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
#include "ccalendarbox.h"

#include "defines.h"


CCalendarBox::CCalendarBox( QWidget *parent ) :
CMsgBox( parent )
{
    mpLayoutMain->insertWidget(1, &mCalendar, 1, Qt::AlignTop);
}

void CCalendarBox::adjustSize()
{
    CMsgBox::adjustSize();

    QSize vSize = size();
    
    mCalendar.adjustSize();
    int vHeight = mCalendar.height();
    int vWidth  = mCalendar.width();

    vSize.setWidth( qMax( vSize.width(), vWidth ) );
    vSize.setHeight( vSize.height() + vHeight );

    vSize.setHeight( vSize.height() );
    vSize.setWidth( vSize.width() );

    mLabel.setMinimumWidth( vSize.width() );

    resize( vSize );

    setMinimumSize( size() );

}

void CCalendarBox::setDate(const QDate& aDate)
{
    mCalendar.setSelectedDate(aDate);
}

QDate CCalendarBox::getDate() const
{
    return mCalendar.selectedDate();
}
