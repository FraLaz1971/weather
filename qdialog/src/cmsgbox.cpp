/****************************************************************************
 **
 ** Copyright (C) 2009 Evgeniy V. Sergeev.  All rights reserved.
 **
 ** This file may be used under the terms of the GNU General Public
 ** License version 2.0 as published by the Free Software Foundation
 ** and appearing in the file LICENSE.GPL included in the packaging of
 ** this file.  Please review the following information to ensure GNU
 ** General Public Licensing requirements will be met:
 ** http://www.trolltech.com/products/qt/opensource.html
 **
 ** If you are unsure which license is appropriate for your use, please
 ** review the following information:
 ** http://www.trolltech.com/    void    finish(int aRetcode);products/qt/licensing.html or contact the
 ** sales department at sales@trolltech.com.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 **
 ** AUTHOR: Evgeniy V. Sergeev <evgeniy.sergeev@gmail.com>
 **
 ****************************************************************************/
#include "cmsgbox.h"
#include "defines.h"
#include "retcodes.h"

CMsgBox::CMsgBox( QWidget *parent ) : 
QDialog( parent, Qt::Dialog | Qt::WindowSystemMenuHint | Qt::MSWindowsFixedSizeDialogHint ),
mMinimumSize(100, 20)
{
    setWindowFlags((windowFlags() | Qt::MSWindowsFixedSizeDialogHint) & ~Qt::WindowMinMaxButtonsHint);

    mLabel.setWordWrap(true);

    mEscButtonIndex = -1;
    mDefaultButtonIndex = -1;
    mEscapePressed = false;

    mFinishing = false;
    mFinishCode = 0;

    mpLayoutMain = new QVBoxLayout();
    mpLayoutButtons = new QHBoxLayout();

    mpLayoutMain->addWidget(&mLabel, 0, Qt::AlignCenter);
    mpLayoutMain->addLayout(mpLayoutButtons, 0);
    mpLayoutButtons->addWidget(&mLeftSpacer, 1, Qt::AlignLeft);
    mpLayoutButtons->addWidget(&mRightSpacer, 1, Qt::AlignRight);
    setLayout(mpLayoutMain);
}

CMsgBox::~CMsgBox()
{
    if(mpLayoutButtons)
        delete mpLayoutButtons;
    if(mpLayoutMain)
        delete mpLayoutMain;
}

void CMsgBox::setText(const QString& aLabel)
{
    mLabel.setText(aLabel);
}

QPushButton* CMsgBox::addButton(const QString& aLabel, int aRet, bool aDefault, bool aEscape)
{
    QPushButton* vNewBtn = new QPushButton(aLabel, this);
    Q_CHECK_PTR(vNewBtn);

    mpLayoutButtons->insertWidget(mpLayoutButtons->count()-1, vNewBtn, 0, Qt::AlignBottom);
    SPushButtonInfo vNewBtnInfo = {vNewBtn, aRet };
    mButtonsList.push_back(vNewBtnInfo);

    if(aDefault)
    {
        vNewBtn->setDefault(true);
        vNewBtn->setFocus();
        vNewBtn->setAutoDefault(true);
        mDefaultButtonIndex = mButtonsList.count() - 1;
    }
    else if(aEscape)
    {
        mEscButtonIndex = mButtonsList.count() - 1;
    }
    connect(vNewBtn, SIGNAL(clicked()), this, SLOT(buttonClicked()));

    return vNewBtn;
}

void CMsgBox::adjustPos()
{
    if(mBoxOptions.begin_set)
    {
        int vPosX = mBoxOptions.begin_x;
        int vPosY = mBoxOptions.begin_y;
    
        if(!mBoxOptions.size_in_pixels)
        {
            vPosX *= fontMetrics().averageCharWidth();
            vPosY *= fontMetrics().lineSpacing();
        }

        move(vPosX, vPosY);
    }

}

void CMsgBox::adjustSize()
{
    QDialog::adjustSize();

    int vHeight = mBoxOptions.height;
    int vWidth  = mBoxOptions.width;

    int vFontHeight = mLabel.fontMetrics().lineSpacing();
    int vFontWidth  = mLabel.fontMetrics().averageCharWidth();

    QRect vScreenRect = QApplication::desktop()->screenGeometry( pos() );

    if((vWidth == -1) || (vHeight == -1))
    {
        vWidth = vScreenRect.width() * 0.85;
        vHeight = vScreenRect.height() * 0.80;
    }
    else
    {
        if(!mBoxOptions.size_in_pixels)
        {
            vHeight *= vFontHeight;
            vWidth  *= vFontWidth;
        }
    }

    mLabel.adjustSize();
    QSize vLabelSize( mLabel.size() );
    QSize vButtonSize( mpLayoutButtons->sizeHint() );


    int vLabelWidth  = vLabelSize.width();
    int vLabelHeight = vLabelSize.height();


    int vSpacingH = style()->pixelMetric(QStyle::PM_LayoutLeftMargin) + style()->pixelMetric(QStyle::PM_LayoutRightMargin);
    int vSpacingV = style()->pixelMetric(QStyle::PM_LayoutTopMargin) + style()->pixelMetric(QStyle::PM_LayoutBottomMargin) + style()->pixelMetric(QStyle::PM_LayoutVerticalSpacing);


    if(vWidth == 0)
    {
        vWidth = vLabelWidth + vSpacingH;
    }

    if ( vWidth > vScreenRect.width() )
        vWidth = vScreenRect.width();

    if ( vWidth < mMinimumSize.width() )
        vWidth = mMinimumSize.width();

    vLabelWidth = vWidth - vSpacingH;
    mLabel.setMinimumWidth(vLabelWidth);

    if(vHeight == 0)
    {
        vLabelHeight = mLabel.heightForWidth(vLabelWidth);

        vHeight = vLabelHeight + vFontHeight + vButtonSize.height() + vSpacingV;
    }

    mLabel.setMinimumHeight(vLabelHeight);
    mLabel.setMinimumWidth(vLabelWidth);
    setMinimumHeight(vHeight);

    if ( vHeight > vScreenRect.height() )
        vHeight = vScreenRect.height();

    if ( vHeight < mMinimumSize.height() )
        vHeight = mMinimumSize.height();

    resize( vWidth, vHeight );

    setMinimumSize( size() );
    //setMaximumSize( size() );
}

void CMsgBox::buttonClicked()
{
    const QObject *vSender = sender();
    for ( int i=0; i<mButtonsList.count(); i++ )
    {
        if ( mButtonsList[i].mpButton == vSender )
        {
            int vRetCode = mButtonsList[i].mRet;
            finish(vRetCode);
            return;
        }
    }
    finish(0);
}

void CMsgBox::keyPressEvent( QKeyEvent *aEvent )
{
    //qWarning("key event %x" , aEvent->key());
    if ( aEvent->key() == Qt::Key_Escape )
    {
        mEscapePressed = true;
        if (( mEscButtonIndex != -1 ) && (mEscButtonIndex < mButtonsList.count()))
        {
            QPushButton* pButton = mButtonsList[mEscButtonIndex].mpButton;
            pButton->animateClick();
            aEvent->accept();
            return;
        }
        else
        {
            finish(IDRET_ESC);
        }
    }
    if ( aEvent->key() == Qt::Key_Return )
    {
        if (( mDefaultButtonIndex != -1 ) && (mDefaultButtonIndex < mButtonsList.count()))
        {
            QPushButton* pButton = mButtonsList[mDefaultButtonIndex].mpButton;
            pButton->animateClick();
            aEvent->accept();
            return;
        }
        finish(IDRET_OK);
    }
#ifndef QT_NO_ACCEL
    if ( !( aEvent->modifiers() & Qt::AltModifier ) && !aEvent->text().isEmpty() )
    {
        for ( int i=0; i<mButtonsList.count(); i++ )
        {
            QPushButton *vBtn = mButtonsList[i].mpButton;
            if ( vBtn->shortcut() == aEvent->text() )
            {
                emit vBtn->animateClick();
                return;
            }
        }
    }
#endif
    QDialog::keyPressEvent( aEvent );
}

void CMsgBox::closeEvent( QCloseEvent *aEvent )
{
    QDialog::closeEvent( aEvent );
    if ( mEscButtonIndex != -1 )
        setResult( mEscButtonIndex );
    mEscapePressed = true;
}

bool CMsgBox::escapePressed() const
{
    return mEscapePressed;
}

// timer

void CMsgBox::setTimeout(int aSecs)
{
    if(aSecs <= 0)
        return;

    QTimer::singleShot(aSecs*1000, this, SLOT(timeoutEvent()));
}

void CMsgBox::timeoutEvent()
{
    mEscapePressed = true;
    reject();
}

void CMsgBox::finishEvent()
{
    done(mFinishCode);
}

void CMsgBox::finish(int aRetCode)
{
    if(!mFinishing)
    {
        if(getBoxOptions()->sleep_secs > 0)
        {
            setEnabled(false);

            mFinishing = true;
            mFinishCode = aRetCode;

            QTimer* vpTimer = new QTimer(this);
            if(vpTimer != NULL)
            {
                Q_CHECK_PTR(vpTimer);
                vpTimer->singleShot(getBoxOptions()->sleep_secs*1000, this, SLOT(finishEvent()));
            }
        }
        else
            done(aRetCode);
    }
}

void CMsgBox::createStandardButtons(bool aHaveCancel, bool aYesNo)
{
    QPushButton* vpExtraButton = NULL;
    QPushButton* vpOkButton = NULL;
    QPushButton* vpCancelButton = NULL;
    QPushButton* vpHelpButton = NULL;

    if( ! mBoxOptions.no_ok )
    {
        vpOkButton = addButton(aYesNo?"&Yes":"Ok", IDRET_OK, true, false);
        Q_CHECK_PTR(vpOkButton);
    }

    if(mBoxOptions.extra_button)
    {
        vpExtraButton = addButton(mBoxOptions.extra_label.isEmpty()?_("&Extra"):mBoxOptions.extra_label, IDRET_EXTRA, false, false);
        Q_CHECK_PTR(vpExtraButton);
    }

    if( aHaveCancel && ! mBoxOptions.no_cancel )
    {
        vpCancelButton = addButton(aYesNo?"&No":"&Cancel", IDRET_CANCEL, false, true);
        Q_CHECK_PTR(vpCancelButton);
    }

    if(mBoxOptions.help_button)
    {
        vpHelpButton = addButton(mBoxOptions.help_label.isEmpty()?_("&Help"):mBoxOptions.help_label, IDRET_HELP, false, false);
        Q_CHECK_PTR(vpHelpButton);
    }

    if(vpOkButton)
    {
        if(!mBoxOptions.yes_label.isEmpty())
            vpOkButton->setText(mBoxOptions.yes_label);
        if (!mBoxOptions.ok_label.isEmpty())
            vpOkButton->setText(mBoxOptions.ok_label);
    }
    if(vpCancelButton)
    {
        if(!mBoxOptions.no_label.isEmpty())
            vpCancelButton->setText(mBoxOptions.no_label);
        if(!mBoxOptions.cancel_label.isEmpty())
            vpCancelButton->setText(mBoxOptions.cancel_label);
    }
}

