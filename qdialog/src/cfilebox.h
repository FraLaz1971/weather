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
#ifndef __CFILEBOX_H__
#define __CFILEBOX_H__

#include <QFileDialog>
#include "sboxoptions.h"

/*
       --fselect filepath height width
              The  file-selection dialog displays a text-entry window in which
              you can type a filename (or directory), and above that two  win
              dows with directory names and filenames.

              Here  filepath  can  be  a  filepath  in which case the file and
              directory windows will display the contents of the path and  the
              text-entry window will contain the preselected filename.

              Use  tab  or arrow keys to move between the windows.  Within the
              directory or filename windows, use the  up/down  arrow  keys  to
              scroll  the  current  selection.   Use the space-bar to copy the
              current selection into the text-entry window.

              Typing any printable characters switches focus to the text-entry
              window,  entering that character as well as scrolling the direc
              tory and filename windows to the closest match.

              Use a carriage return or the "OK" button to accept  the  current
              value in the text-entry window and exit.

              On  exit,  the  contents of the text-entry window are written to
              dialog output.
*/

class CFileBox : public QFileDialog
{
Q_OBJECT
public:
    CFileBox( QWidget* parent = 0, const QString & caption = QString(),
                    const QString & directory = QString(),
                    const QString & filter = QString());
public:
    void    adjustSize();
    void    adjustPos();
    bool    escapePressed() const;
    void    setTimeout(int aSecs); // if no user input aSecsonds - exit with escape pressed status.

public:
    void                setBoxOptions(const SBoxOptions& aBoxOptions) { mBoxOptions = aBoxOptions; }
    SBoxOptions*        getBoxOptions() { return &mBoxOptions; }; \
    const SBoxOptions*  getBoxOptions() const { return &mBoxOptions; };

//!Events
protected:
    virtual void    keyPressEvent( QKeyEvent *aEvent );

protected slots:
    void    timeoutEvent();

protected:
    bool    mEscapePressed;

protected:
    SBoxOptions     mBoxOptions;
};


#endif // _CFILEBOX_H__
