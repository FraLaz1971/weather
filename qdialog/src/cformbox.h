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
#ifndef __CFORMBOX_H__
#define __CFORMBOX_H__

#include <QtCore>
#include <QtGui>

#include <SBoxOptions>

#include <CMsgBox>

/*
       --form text height width formheight [ label y x item y x flen ilen ] ...
              The form dialog displays a form consisting of labels and fields,
              which are positioned on a scrollable window by coordinates given
              in the script.  The field length flen and input-length ilen tell
              how  long the field can be.  The former defines the length shown
              for a selected field, while the latter defines  the  permissible
              length of the data entered in the field.

              -  If  flen  is zero, the corresponding field cannot be altered.
                 and the contents of the field determine the displayed-length.

              -  If  flen  is  negative,  the  corresponding  field  cannot be
                 altered, and the negated value of flen is used  as  the  dis‐
                 played-length.

              -  If ilen is zero, it is set to flen.

              Use  up/down  arrows  (or  control/N, control/P) to move between
              fields.  Use tab to move between windows.

              On exit, the contents of the form-fields are written to dialog’s
              output,  each  field  separated  by a newline.  The text used to
              fill non-editable fields (flen is zero or negative) is not writ‐
              ten out.

       --passwordform text height width formheight [ label y x item y  x  flen ilen ] ...
              This is identical to --form except  that  all  text  fields  are
              treated as password widgets rather than inputbox widgets.

       --mixedform text height width formheight [ label y x mitem y x flen ilen itype ] ...
              The mixedform dialog displays a form consisting  of  labels  and
              fields,  much  like  the  --form dialog.  It differs by adding a
              field-type parameter to each fields description.  Each  bit  in
              the type denotes an attribute of the field:

              1    hidden, e.g., a password field.

              2    readonly, e.g., a label.
*/

const int FIELD_NORMAL      = 0;
const int FIELD_HIDDEN      = 1;
const int FIELD_READONLY    = 2;

class CFormBox : public CMsgBox
{
Q_OBJECT
public:
    CFormBox( QWidget* parent=0 );
    ~CFormBox();

public:
    bool addItem(   const QString& aLabel, QPoint aPos,
                    const QString& aItem, QPoint aItemPos,
                    int aItemFieldLength, int aMaxItemLength,
                    const QString& aHelp,
                    const int aFieldType);
    void prepeareScroll();
    const QWidgetList*  listLabels() const;
    const QWidgetList*  listLineEdits() const;

//    virtual void    adjustSize();
protected:
    QWidget*        mpScrollWidget;
    QScrollArea*    mpScrollArea;
    QWidgetList     mListLabels;
    QWidgetList     mListLineEdits;
    QHBoxLayout*    mpLayoutHelper;
};

#endif // __CFORMBOX_H__
