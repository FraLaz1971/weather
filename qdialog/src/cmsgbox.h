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
#ifndef __CMSGBOX_H__
#define __CMSGBOX_H__

#include <QtCore>
#include <QtGui>

#include <SBoxOptions>

#include <QDialog>

/*

       --infobox text height width
              An info box is basically a message box.  However, in this  case,
              dialog will exit immediately after displaying the message to the
              user.  The screen is not cleared when dialog exits, so that  the
              message will remain on the screen until the calling shell script
              clears it later.  This is useful when you  want  to  inform  the
              user  that some operations are carrying on that may require some
              time to finish.

              On exit, no text is written to dialog’s output.   Only  an  "OK"
              button  is  provided  for  input,  but an ESC exit status may be
              returned.

*/


class CMsgBox : public QDialog
{
Q_OBJECT
public:
    CMsgBox( QWidget* parent=0 );
    ~CMsgBox();

public:
    virtual void    setText(const QString& aLabel);
    QPushButton*    addButton(const QString& aLabel, int aRet = 0, bool aDefault = false, bool aEscape = false);
    virtual void    adjustSize();
    virtual void    adjustPos();
    bool            escapePressed() const;
    void            setTimeout(int aSecs); // if no user input aSecsonds - exit with escape pressed status.
    void            createStandardButtons(bool aHaveCancel = false, bool aYesNo = false);

public:
    void            setBoxOptions(const SBoxOptions& aBoxOptions) { mBoxOptions = aBoxOptions; }
    SBoxOptions* getBoxOptions() { return &mBoxOptions; }; \
    const SBoxOptions* getBoxOptions() const { return &mBoxOptions; };

protected:
    void            finish(int aRetcode);

//!Events
protected:
    virtual void    keyPressEvent( QKeyEvent *aEvent );
    void            closeEvent( QCloseEvent *aEvent );

protected slots:
    void            buttonClicked();
    void            timeoutEvent();
    void            finishEvent();

protected:
    struct SPushButtonInfo
    {
        QPushButton*    mpButton;
        int             mRet;
    };

    SBoxOptions     mBoxOptions;
    QLabel          mLabel;
    QVBoxLayout*    mpLayoutMain;
    QHBoxLayout*    mpLayoutButtons;
    //QHBoxLayout     mLayoutLabel;
    QWidget         mLeftSpacer, mRightSpacer;
    QList<SPushButtonInfo> mButtonsList;
    QSize           mMinimumSize;
    int             mEscButtonIndex;
    int             mDefaultButtonIndex;
    bool            mEscapePressed;
    bool            mFinishing;
    int             mFinishCode;
};


#endif // __CMSGBOX_H__
