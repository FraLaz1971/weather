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
#include "ctextbox.h"
#include "defines.h"


CTextBox::CTextBox( QWidget *parent ) : 
CMsgBox( parent )
{
    mLabel.hide();

    QHBoxLayout* vpLayoutTextBox = new QHBoxLayout();
    mpLayoutMain->insertLayout(1, vpLayoutTextBox, 1);
    vpLayoutTextBox->addWidget(&mTextBox, 1);    
    mTextBox.setReadOnly(true);
    mTextBox.setWordWrapMode(QTextOption::NoWrap);

    mMinimumSize.setWidth(500);
    mMinimumSize.setHeight(250);
}

void CTextBox::setText(const QString& aLabel)
{
    if(!aLabel.isEmpty())
    {
        mLabel.show();
    }
    else
    {
        mLabel.hide();
    }
    CMsgBox::setText(aLabel);
}

void CTextBox::loadFromFile(const QString& aFileName)
{
    QFile vFile(aFileName);
    if(vFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        try
        {
            QTextStream vStream(&vFile);


            //mTextBox.setText(vStream.readAll());
            mTextBox.clear();
            while(!vStream.atEnd())
            {
                QString vString = vStream.readLine();
                if(!vString.isEmpty() || !vStream.atEnd())
                    mTextBox.append(vString);
            }

        }
        catch(...)
        {
        }
        vFile.close();
    }
}

void CTextBox::setFileName(const QString& aFileName)
{
    loadFromFile(aFileName);
}

void CTextBox::setReadOnly(bool aReadOnly)
{
    mTextBox.setReadOnly(aReadOnly);
}

bool CTextBox::isReadOnly()
{
    return mTextBox.isReadOnly();
}

QString CTextBox::content()
{
    return mTextBox.toPlainText();
}
