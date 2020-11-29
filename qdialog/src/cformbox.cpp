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
 ** http://www.trolltech.com/products/qt/licensing.html or contact the
 ** sales department at sales@trolltech.com.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 **
 ** AUTHOR: Evgeniy V. Sergeev <evgeniy.sergeev@gmail.com>
 **
 ****************************************************************************/
#include "cdialogapp.h"
#include "cformbox.h"

#include "defines.h"


CFormBox::CFormBox( QWidget *parent ) : 
CMsgBox( parent )
{
    mpScrollWidget  = new QWidget(this);
    mpScrollArea    = new QScrollArea(this);

    mpLayoutHelper = new QHBoxLayout();

    mpLayoutMain->insertLayout(1, mpLayoutHelper, 1);
    mpLayoutHelper->addWidget(mpScrollArea, 1);

    mpScrollArea->show();
}

CFormBox::~CFormBox()
{
    if(mpLayoutHelper)
        delete mpLayoutHelper;
}

void autoResizeWidget(QWidget *aWidget)
{
    if(aWidget == NULL)
        return;

    QPoint vMaxPos (aWidget->width(), aWidget->height());

    for(QObjectList::const_iterator vChild = aWidget->children().begin(); vChild < aWidget->children().end(); vChild++ )
    {
        QWidget* vItem = (QWidget*)(*vChild);

        QPoint vPos = vItem->pos();
        QSize vSize = vItem->size();

        vPos.setX( vPos.x() + vSize.width() );
        vPos.setY( vPos.y() + vSize.height() );

        if(vPos.x() > vMaxPos.x() )
            vMaxPos.setX( vPos.x() );

        if(vPos.y() > vMaxPos.y() )
            vMaxPos.setY( vPos.y() );
    }

    aWidget->resize(vMaxPos.x(), vMaxPos.y());

}

void CFormBox::prepeareScroll()
{
    autoResizeWidget(mpScrollWidget);

    mpScrollWidget->show();
    mpScrollArea->setWidget(mpScrollWidget);
}


bool CFormBox::addItem(
        const QString& aLabel, QPoint aPos,
        const QString& aItem, QPoint aItemPos,
        int aItemFieldLength, int aMaxItemLength,
        const QString& aHelp,
        const int aFieldType)
{
    QLineEdit* vpItem = new QLineEdit(this);
    if(vpItem == NULL)
        return false;

    vpItem->setText(aItem);
    vpItem->setParent(mpScrollWidget);

    //TODO: height ????
    int vFontHeight = vpItem->fontMetrics().height() + vpItem->style()->pixelMetric(QStyle::PM_LayoutVerticalSpacing) + vpItem->style()->pixelMetric(QStyle::PM_DefaultFrameWidth) * 2;
    //int vFontWidth  = vpItem->fontMetrics().maxWidth();
    //int vFontWidth  = vpItem->fontMetrics().averageCharWidth();
    int vFontWidth  = vpItem->fontMetrics().charWidth("W", 0);

    aItemPos.setX(aItemPos.x() * vFontWidth);
    aItemPos.setY(aItemPos.y() * vFontHeight);

    vpItem->move(aItemPos);

    QSize vSize = vpItem->size();
    vSize.setWidth(aItemFieldLength*vpItem->fontMetrics().averageCharWidth() * aItemFieldLength);
    //vpItem->resize(vSize);

    if(aMaxItemLength)
        vpItem->setMaxLength(aMaxItemLength);
    vpItem->setToolTip(aHelp);

    if(aFieldType == FIELD_HIDDEN)
    {
        vpItem->setEchoMode(QLineEdit::Password);
    }
    else if(aFieldType == FIELD_READONLY)
    {
        vpItem->setReadOnly(true);
    }
    //else
    {
        mListLineEdits.push_back(vpItem);
    }

    vpItem->show();

    if( !aLabel.isEmpty() )
    {
        QLabel* vpLabel = new QLabel(this);

        //if(aFieldType != FIELD_READONLY)
        {
            mListLabels.push_back(vpItem);
        }

        if(vpItem != NULL)
        {

            vpLabel->setText(aLabel);
            vpLabel->setParent(mpScrollWidget);

            aPos.setX(aPos.x() * vFontWidth);
            aPos.setY(aPos.y() * vFontHeight);

            vpLabel->move(aPos);
            //vpLabel->SetRect(Rect(LabelPos.X, LabelPos.Y - 1, LabelPos.X + wcslen(Label), LabelPos.Y));

            vpItem->setToolTip(aHelp);

            vpLabel->show();
        }
    }

    return true;
}

const QWidgetList* CFormBox::listLabels() const
{
    return &mListLabels;
}

const QWidgetList* CFormBox::listLineEdits() const
{
    return &mListLineEdits;
}
