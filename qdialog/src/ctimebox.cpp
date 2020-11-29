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
#include "ctimebox.h"

#include "defines.h"


CTimeBox::CTimeBox( QWidget *parent ) :
CMsgBox( parent )
{
    mpLayoutMain->insertWidget(1, &mTimeEdit, 1, Qt::AlignTop);
    mTimeEdit.setDisplayFormat ("hh:mm:ss" );
}

void CTimeBox::adjustSize()
{
    CMsgBox::adjustSize();

    QSize vSize = size();
    
    mTimeEdit.adjustSize();
    int vHeight = mTimeEdit.height();
    int vWidth  = mTimeEdit.width();

    vSize.setHeight( vSize.height() + vHeight );
    vSize.setWidth( vSize.width() + vWidth );

    resize( vSize );

    setMinimumSize( size() );

}

void CTimeBox::setTime(const QTime& aTime)
{
    mTimeEdit.setTime(aTime);
}

QTime CTimeBox::getTime() const
{
    return mTimeEdit.time();
}
