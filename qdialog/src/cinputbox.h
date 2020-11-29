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
#ifndef __CINPUTBOX_H__
#define __CINPUTBOX_H__

#include <CMsgBox>

/*
       --inputbox text height width [init]
              An input box is useful when  you  want  to  ask  questions  that
              require  the  user  to input a string as the answer.  If init is
              supplied it is used to initialize the input string.  When enter‐
              ing  the  string,  the  backspace, delete and cursor keys can be
              used to correct typing errors.  If the input  string  is  longer
              than  can  fit  in  the  dialog  box,  the  input  field will be
              scrolled.

              On exit, the input string will be printed on dialog’s output.

       --passwordbox text height width [init]
              A  password box is similar to an input box, except that the text
              the user enters is not displayed.  This is useful when prompting
              for  passwords or other sensitive information.  Be aware that if
              anything is passed in "init", it will be visible in the system’s
              process table to casual snoopers.  Also, it is very confusing to
              the user to provide them with a  default  password  they  cannot
              see.   For  these  reasons,  using "init" is highly discouraged.
              See "--insecure" if you do not care about your password.

              On exit, the input string will be printed on dialog’s output.

*/

class CInputBox : public CMsgBox
{
Q_OBJECT
public:
    CInputBox( QWidget* parent=0 );

public:
    void            setPasswordMode(bool aValue = true);
    void            setEditText(const QString& aText);
    QString         getEditText() const;
    virtual void    adjustSize();

protected:
    virtual void    showEvent ( QShowEvent * event );
protected:
    QLineEdit   mLineEdit;
};


#endif // __CINPOUTBOX_H__
