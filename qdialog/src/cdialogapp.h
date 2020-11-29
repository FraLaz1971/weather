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
#ifndef __DIALOGAPP_H__
#define __DIALOGAPP_H__

#include <CApplication>
#include <SBoxOptions>
#include <CMenuBox>
#include <iostream>
#include "retcodes.h"

//! debug

#define DEBUG

//! constants

#define VERSION_QDIALOG "qdialog 0.1.1 28 June 2020 \n authors: \n 2009 Evgeniy V. Sergeev <evgeniy.sergeev@gmail.com> \n 2020 Francesco Lazzarotto <fralaz1971@gmail.com>"

enum NCompatability
{
    COMPAT_DEFAULT = 0,
    COMPAT_CDIALOG = 1,
    COMPAT_XDIALOG = 2
};

const int LIMIT_INCLUDES = 20;
const int DEFAULT_TAB_LEN = 8;
const int DEFAULT_ASPECT  = 9;

const int EVENT_UPDATE_FROM_THREAD = QEvent::User + 1;

//! moc-file can't be compiled
#include "defines.h"

//! forward declaration

//! class
class CDialogApp : public CApplication {
Q_OBJECT

public:
    CDialogApp(int &, char **);
    ~CDialogApp();

    virtual int init();
    virtual int run();

protected:
    void    prepeareArguments(const QStringList& aArgs, int aCountIncludes = LIMIT_INCLUDES);
    int     processArguments();

    QString commandLineArgumentAt(int aOffset);
    QString argString(SBoxOptions* apOptions, int aOffset);
    long    argNumeric(int aOffset);
    int     howManyTags(int aPos, int aGroup);
    int     restArgs(int aPos);

    int     readCommonOptions(SBoxOptions* apOptions, int aOffset, int aEndOffset);
    void    readSize(SBoxOptions* apOptions, int& aOffset);

    void    printString(const QString& aString);
    void    printStringQuoted(QString aString, bool aSingleQuoted, bool aIgnoreSpecial, bool aMultiline = false, bool aSeparate = false);
    void    printMaxSize();
    void    printVersion();
    void    printHelp();
    int     getInputFD();
    QFile*  getOutput();

    virtual void    beforeRunBox();
    virtual void    afterRunBox();
//
// options in cdialog look like: <optional options> box <params> <optional params>
//                               ^                  ^
//                               |                  |
//                               +- aPrevOffset     +- aOffset
//
    int     runAbout();
    int     runBox(int aPrevOffset, int& aOffset, bool aYesNo = false, bool aInputBox = false, bool aPasswordBox = false);
    int     runDateTime(int aPrevOffset, int& aOffset, bool aTime = false);
    int     runSelectPath(int aPrevOffset, int& aOffset, bool aDirectory = false);
    int     runPause(int aPrevOffset, int& aOffset);
    int     runInfobox(int aPrevOffset, int& aOffset);
    int     runMenu(int aPrevOffset, int& aOffset, NMenuType aType = MENUTYPE_MENU);
    int     runGauge(int aPrevOffset, int& aOffset);
    int     runForm(int aPrevOffset, int& aOffset, bool aMixedForm =false, bool aPasswordForm =false);
    int     runTextBox(int aPrevOffset, int& aOffset, bool aReadOnly = true, bool aTailBox = false, bool aProgressBox = false);

private:
    static QStringList  mCommandLineArguments;
            
    QFile           mOutput;            // option "--output-fd fd"

    int             mInputFd;
    int             mOutputFd;
    bool            mUseColors;         // use colors by default?
    bool            mUseScrollBar;      // RESERVED
    bool            mVisitItems;        // option "--visit-items"
    bool            mIgnoreUnknown;     // option "--ignore-unknown
    int             mTabLen;            // option "--tab-len n"
    int             mAspectRatio;       // option "--aspect ratio"
    QString         mSeparateBoxes;     // option "--separate-widget string"
    QString         mBackTitle;         // option "--backtitle"
    int             mBoxesCount;        // # of widgets that may have done output

    NCompatability  mCompatability;
};


#endif // __DIALOGAPP_H__

