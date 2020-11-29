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
#include "cfilebox.h"

#include "defines.h"

CFileBox::CFileBox( QWidget* parent, const QString & caption,
                    const QString & directory,
                    const QString & filter):
QFileDialog( parent, caption, directory, filter )
{
    mEscapePressed = false;
}

void CFileBox::adjustPos()
{
    if(mBoxOptions.begin_set)
    {
        int vPosX = mBoxOptions.begin_x;
        int vPosY = mBoxOptions.begin_y;

        if(!mBoxOptions.size_in_pixels)
        {
            vPosX *= fontMetrics().maxWidth();
            vPosY *= fontMetrics().height();
        }

        move(vPosX, vPosY);
    }
}

void CFileBox::adjustSize()
{
    int vHeight = mBoxOptions.height;
    int vWidth  = mBoxOptions.width;

    QRect vScreenRect = QApplication::desktop()->screenGeometry( pos() );

    if(vWidth == 0)
    {
        vWidth = width(); // default width;
    }
    else if(vWidth == -1)
    {
        vWidth = vScreenRect.width();
    }
    else
    {
        vWidth  *= fontMetrics().maxWidth();
    }

    if(vHeight == 0)
    {
        vHeight = height(); // default
    }
    else if(vHeight == -1)
    {
        vHeight = vScreenRect.height() - 150;
    }
    else
    {
        vHeight *= fontMetrics().height();
    }

    if ( vWidth > vScreenRect.width() )
        vWidth = vScreenRect.width();

    resize( vWidth, vHeight );

    setMinimumSize( size() );

}

void CFileBox::keyPressEvent( QKeyEvent *aEvent )
{
    //qWarning("key event %x" , aEvent->key());
    if ( aEvent->key() == Qt::Key_Escape )
    {
        mEscapePressed = true;
    }

    QFileDialog::keyPressEvent( aEvent );
}

bool CFileBox::escapePressed() const
{
    return mEscapePressed;
}

void CFileBox::setTimeout(int aSecs)
{
    if(aSecs <= 0)
        return;

    QTimer::singleShot(aSecs*1000, this, SLOT(timeoutEvent()));
}

void CFileBox::timeoutEvent()
{
    mEscapePressed = true;
    reject();
}

