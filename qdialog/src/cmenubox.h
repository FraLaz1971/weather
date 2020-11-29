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
#ifndef __CMENUBOX_H__
#define __CMENUBOX_H__

#include <QtCore>
#include <QtGui>

#include <SBoxOptions>

#include <CMsgBox>
#include <QTreeWidget>

/*
       --menu text height width menu-height [ tag item ] ...
              As  its  name  suggests,  a menu box is a dialog box that can be
              used to present a list of choices in the form of a menu for  the
              user to choose.  Choices are displayed in the order given.  Each
              menu entry consists of a tag string and an item string.  The tag
              gives  the entry a name to distinguish it from the other entries
              in the menu.  The item is a short description of the option that
              the  entry  represents.   The  user  can  move  between the menu
              entries by pressing the cursor keys, the first letter of the tag
              as  a  hot-key,  or  the  number keys 1-9. There are menu-height
              entries displayed in the menu at one time, but the menu will  be
              scrolled if there are more entries than that.

              On exit the tag of the chosen menu entry will be printed on dial
              og’s output.  If the "--help-button" option is given, the  cor
              responding  help  text  will  be printed if the user selects the
              help button.

       --radiolist text height width list-height  [ tag item status ] ...
              A  radiolist  box is similar to a menu box.  The only difference
              is that you can indicate which entry is currently  selected,  by
              setting its status to on.

              On  exit,  the  name of the selected item is written to dialog’s
              output.

       --checklist text height width list-height [ tag item status ] ...
              A checklist box is similar to a menu  box;  there  are  multiple
              entries  presented  in  the form of a menu.  Instead of choosing
              one entry among the entries, each entry can be turned on or  off
              by  the  user.  The initial on/off state of each entry is speci
              fied by status.

              On exit, a list of the tag strings of  those  entries  that  are
              turned  on  will be printed on dialog’s output.  If the "--sepa
              rate-output" option is not given, the strings will be quoted  to
              make it simple for scripts to separate them.  See the "--single-
              quoted" option, which modifies the quoting behavior.

*/

enum NMenuType
{
    MENUTYPE_MENU = 0,
    MENUTYPE_INPUTMENU = 1,
    MENUTYPE_RADIOLIST = 2,
    MENUTYPE_CHECKLIST = 3
};

class CMenuBox : public CMsgBox
{
Q_OBJECT
public:
    CMenuBox( QWidget* parent=0 );

public:
    virtual void    adjustSize();
    void            setMenuType(NMenuType aMenuType);
    void            setMenuHeight(int aHeight);
    void            addMenuItem(const QString& aItemTag, const QString& aItemName, const QString& aItemHelp, bool aItemChecked);
    void            setSelectedItem(int aDefaultIndex);
    QString         selectedTag() const;
    QList<QTreeWidgetItem*> getItems() const; // for inputmenu
    QList<QTreeWidgetItem*>* getCheckedItems() const; // for checklist
    QString getFirstCheckedItem() const; // for radiolist

protected slots:
    void            itemDoubleClicked ( QTreeWidgetItem * apItem, int aColumn );
    void            itemChanged ( QTreeWidgetItem * apItem, int aColumn );

protected:
    void            setColumnCount(int aCount = 1);
    void            resizeEvent( QResizeEvent * );
    QTreeWidget     mMenuItems;
    NMenuType       mMenuType;
    int             mColumnCount;
};



#endif // __CMENUBOX_H__
