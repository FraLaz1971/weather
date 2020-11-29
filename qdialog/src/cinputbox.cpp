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
#include "cinputbox.h"
#include "defines.h"


CInputBox::CInputBox( QWidget *parent ) : 
CMsgBox( parent )
{
    mpLayoutMain->insertWidget(1, &mLineEdit, 1, Qt::AlignTop);
}

void CInputBox::setEditText(const QString& aText)
{
    mLineEdit.setText(aText);
}

QString CInputBox::getEditText() const
{
    return mLineEdit.text();
}

void CInputBox::setPasswordMode(bool aValue)
{
    mLineEdit.setEchoMode(aValue?QLineEdit::Password:QLineEdit::Normal);
}

void CInputBox::adjustSize()
{
    CMsgBox::adjustSize();

    QSize vSize = size();
    
    mLineEdit.adjustSize();
    int vHeight = mLineEdit.height();

    vSize.setHeight( vSize.height() + vHeight );

    resize( vSize );

    setMinimumSize( size() );

}

void CInputBox::showEvent ( QShowEvent * event )
{
    CMsgBox::showEvent( event );

    mLineEdit.setFocus();
}

