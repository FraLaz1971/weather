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
#ifndef __CTEXTBOX_H__
#define __CTEXTBOX_H__

#include <CMsgBox>
#include <QTextEdit>

/*
       --textbox file height width
              A  text  box  lets  you display the contents of a text file in a
              dialog box.  It is like a simple text file viewer.  The user can
              move  through  the  file by using the cursor, page-up, page-down
              and HOME/END keys available on most keyboards.  If the lines are
              too  long to be displayed in the box, the LEFT/RIGHT keys can be
              used to scroll the text region horizontally.  You may  also  use
              vi-style keys h, j, k, l in place of the cursor keys, and B or N
              in place of the page-up  and  page-down  keys.   Scroll  up/down
              using  vi-style  ’k’  and ’j’, or arrow-keys.  Scroll left/right
              using vi-style ’h’ and ’l’, or arrow-keys.   A  ’0’  resets  the
              left/right  scrolling.   For  more convenience, vi-style forward
              and backward searching functions are also provided.

              On exit, no text is written to dialog’s output.  Only an  "EXIT"
              button  is  provided  for  input,  but an ESC exit status may be
              returned.

       --tailbox file height width
              Display text from a file in a dialog box, as in a "tail -f" com‐
              mand.   Scroll  left/right using vi-style ’h’ and ’l’, or arrow-
              keys.  A ’0’ resets the scrolling.

              On exit, no text is written to dialog’s output.   Only  an  "OK"
              button  is  provided  for  input,  but an ESC exit status may be
              returned.

       --tailboxbg file height width
              Display text from a file in a dialog box as a  background  task,
              as  in  a "tail -f &" command.  Scroll left/right using vi-style
              ’h’ and ’l’, or arrow-keys.  A ’0’ resets the scrolling.

              Dialog treats the background task specially if there  are  other
              widgets  (--and-widget) on the screen concurrently.  Until those
              widgets are closed (e.g., an "OK"), dialog will perform  all  of
              the  tailboxbg widgets in the same process, polling for updates.
              You may use a tab to traverse between the widgets on the screen,
              and  close them individually, e.g., by pressing ENTER.  Once the
              non-tailboxbg widgets are closed, dialog forks a copy of  itself
              into  the  background,  and  prints its process id if the "--no-
              kill" option is given.

              On exit, no text is written to dialog’s output.  Only an  "EXIT"
              button  is  provided  for  input,  but an ESC exit status may be
              returned.

              NOTE: Older versions of dialog forked immediately and  attempted
              to  update  the  screen  individually.   Besides  being  bad for
              performance, it was unworkable.  Some older scripts may not work
              properly with the polled scheme.


       --progressbox text height width

       --progressbox height width
              A progressbox is similar to an tailbox, except that it will exit
              when it reaches the end of the file.  If  three  parameters  are
              given, it displays the text under the title, delineated from the
              scrolling file’s contents.  If only two  parameters  are  given,
              this text is omitted.

*/

class CTextBox : public CMsgBox
{
Q_OBJECT
public:
    CTextBox( QWidget* parent=0 );

public:
    virtual void    setText(const QString& aLabel);
    virtual void    setFileName(const QString& aFileName);
    void            loadFromFile(const QString& aFileName);
    void            setReadOnly(bool aReadOnly);
    bool	    isReadOnly();
    QString         content();

protected:
    QTextEdit       mTextBox;
};


#endif // __CTEXTBOX_H__
