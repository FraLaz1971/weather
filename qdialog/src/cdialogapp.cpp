/************************F****************************************************
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
 ** updated by Francesco Lazzarotto <fralaz1971@gmail.com>
 * 
 ****************************************************************************/

//TODO: AutoSize and begin_set then dialog starts!

//[+] --
//[+] --file
//[+] --args
//[ ] --create-rc

/* ready widgets

[+]  --calendar     <text> <height> <width> <day> <month> <year>
[+]  --checklist    <text> <height> <width> <list height> <tag1> <item1> <status1>...
[+]  --dselect      <directory> <height> <width>
[+]  --fselect      <filepath> <height> <width>
[+]  --timebox      <text> <height> <width> <hour> <minute> <second>
[+]  --gauge        <text> <height> <width> [<percent>]
[+]  --textbox      <file> <height> <width> <filename>
[+]  --editbox      <file> <height> <width> <filename>
[ ]  --tailbox      <file> <height> <width> <filename>
[ ]  --tailboxbg    <file> <height> <width> <filename>
[+]  --pause        <text> <height> <width> <seconds>
[ ]  --progress     <text> <height> <width> [<maxdots> [[-]<msglen>]]
[ ]  --progressbox  <height> <width>
[ ]  --mixedgauge   <text> <height> <width> <percent> <tag1> <item1>...
[+]  --form         <text> <height> <width> <form height> <label1> <l_y1> <l_x1> <item1> <i_y1> <i_x1> <flen1> <ilen1>...
[+]  --passwordform <text> <height> <width> <form height> <label1> <l_y1> <l_x1> <item1> <i_y1> <i_x1> <flen1> <ilen1>...
[+]  --mixedform    <text> <height> <width> <form height> <label1> <l_y1> <l_x1> <item1> <i_y1> <i_x1> <flen1> <ilen1> <itype>...
[+]  --inputbox     <text> <height> <width> [<init>]
[+]  --inputmenu    <text> <height> <width> <menu height> <tag1> <item1>...
[ ]                 use persistent editor and rename button in inputmenu
[+]  --menu         <text> <height> <width> <menu height> <tag1> <item1>...
[+]  --msgbox       <text> <height> <width>
[+]  --passwordbox  <text> <height> <width> [<init>]
[+]  --radiolist    <text> <height> <width> <list height> <tag1> <item1> <status1>...
[+]  --yesno        <text> <height> <width>
[+]  --infobox     <text> <height> <width> [<timeout>]
[ ]  --2inputsbox  <text> <height> <width> <label1> <init1> <label2> <init2>
[ ]  --3inputsbox  <text> <height> <width> <label1> <init1> <label2> <init2> <label3> <init3>
[ ]  --combobox    <text> <height> <width> <item1> ... <itemN>
[ ]  --rangebox    <text> <height> <width> <min value> <max value> [<default value>]
[ ]  --2rangesbox  <text> <height> <width> <label1> <min1> <max1> <def1> <label2> <min2> <max2> <def2>
[ ]  --3rangesbox  <text> <height> <width> <label1> <min1> <max1> <def1> <label2> <min2> <max2> <def2> <label3> <min3> <max3> <def3>
[ ]  --spinbox     <text> <height> <width> <min> <max> <def> <label>
[ ]  --2spinsbox   <text> <height> <width> <min1> <max1> <def1> <label1> <min2> <max2> <def2> <label2>
[ ]  --3spinsbox   <text> <height> <width> <text> <height> <width> <min1> <max1> <def1> <label1> <min2> <max2> <def2> <label2> <min3> <max3> <def3> <label3>
[ ]  --logbox      <file> <height> <width>
[ ]  --buildlist   <text> <height> <width> <list height> <tag1> <item1> <status1> {<help1>}...
[ ]  --treeview    <text> <height> <width> <list height> <tag1> <item1> <status1> <item_depth1> {<help1>}...
[ ]  --colorsel    <text> <height> <width>
[ ]  --fontsel     <font name> <height> <width>
*/

//! -*- coding: UTF-8 -*-
#define SOURCE_CODING "UTF-8"

#include "config.h"

extern "C" {
    #include <errno.h>
    #include <stdio.h>
    #include <unistd.h>
#if defined(Q_OS_LINUX)
    #include <syslog.h>
#endif
}

#include <QtCore>
//#include <QtNetwork>
//#include <QtXml>
//#include <QtSql>
//#include <QHostInfo>

#include "defines.h"

//#include "main.h"
#include "utils.h"
#include "strutils.h"
#include "cdialogapp.h"
#include "cmsgbox.h"

#include <CMsgBox>
#include <CInputBox>
#include <CMenuBox>
#include <CCalendarBox>
#include <CTimeBox>
#include <CFileBox>
#include <CGaugeBox>
#include <CPauseBox>
#include <CTextBox>
#include <CTailBox>
#include <CFormBox>

#define DEBUG 0

//! extern
extern int boxflag = 0;


//! global variables;

enum NOptions
{
    o_unknown     = 0, // [-]
    o_about          , // [+]
    o_allow_close    , // [ ]
    o_and_widget     , // [-]
    o_aspect         , // [ ]
    o_auto_placement , // [ ]
    o_backtitle      , // [-]
    o_beep           , // [ ]
    o_beep_after     , // [ ]
    o_begin          , // [ ]
    o_calendar       , // [ ]
    o_cancel_label   , // [ ]
    o_checklist      , // [+]
    o_clear          , // [-]
    o_colors         , // [ ]
    o_cr_wrap        , // [+]
    o_create_rc      , // [ ]
    o_default_item   , // [+]
    o_defaultno      , // [ ]
    o_dselect        , // [ ]
    o_exit_label     , // [+]
    o_extra_button   , // [+]
    o_extra_label    , // [+]
    o_fixed_font     , // [ ]
    o_form           , // [ ]
    o_fselect        , // [ ]
    o_fullbutton     , // [ ]
    o_gauge          , // [ ]
    o_help           , // [ ]
    o_help_button    , // [+]
    o_help_label     , // [+]
    o_help_status    , // [ ]
    o_icon           , // [ ]
    o_ignore         , // [ ]
    o_infobox        , // [+]
    o_input_fd       , // [-???]
    o_inputbox       , // [ ]
    o_inputmenu      , // [ ]
    o_insecure       , // [ ]
    o_item_help      , // [+]
    o_keep_colors    , // [ ]
    o_keep_window    , // [ ]
    o_max_input      , // [ ]
    o_menu           , // [+]
    o_menubox        , // [+]
    o_mixedform      , // [ ]
    o_mixedgauge     , // [ ]
    o_msgbox         , // [+]
    o_no_cancel      , // [+]
    o_no_close       , // [ ]
    o_no_collapse    , // [ ]
    o_no_cr_wrap     , // [+]
    o_no_kill        , // [-]
    o_no_label       , // [+]
    o_no_ok          , // [+]
    o_no_shadow      , // [-]
    o_no_tags        , // [ ]
    o_noitem         , // [ ]
    o_ok_label       , // [+]
    o_output_fd      , // [ ]
    o_passwordbox    , // [ ]
    o_passwordform   , // [ ]
    o_pause          , // [ ]
    o_print_maxsize  , // [+]
    o_print_size     , // [ ]
    o_print_version  , // [+]
    o_progressbox    , // [ ]
    o_radiolist      , // [+]
    o_screen_center  , // [ ]
    o_separate_output, // [ ]
    o_separate_widget, // [ ]
    o_separator      , // [ ]
    o_shadow         , // [-]
    o_single_quoted  , // [+]
    o_size_err       , // [ ]
    o_sleep          , // [ ]
    o_smooth         , // [ ]
    o_stderr         , // [+]
    o_stdout         , // [+]
    o_tab_correct    , // [ ]
    o_tab_len        , // [ ]
    o_tailbox        , // [ ]
    o_tailboxbg      , // [ ]
    o_textbox        , // [ ]
    o_textedit       , // [ ]
    o_timebox        , // [ ]
    o_timeout        , // [+]
    o_title          , // [+]
    o_trim           , // [+]
    o_visit_items    , // [ ]
    o_under_mouse    , // [ ]
    o_wmclass        , // [ ]
    o_yes_label      , // [+]
    o_yesno            // [+]
};

/*
 * The bits in 'pass' are used to decide which options are applicable at
 * different stages in the program:
 *      1 flags before widgets
 *      2 widgets
 *      4 non-widget options
 */
struct SOptions
{
    const char *name;
    int code;
    int pass;                   /* 1,2,4 or combination */
    const char *help;           /* NULL to suppress, non-empty to display params */
};

/*
 * The options[] table is organized this way to make it simple to maintain
 * a sorted list of options for the help-message.
 */
/* *INDENT-OFF* */
static const SOptions gOptions[] = {
    { "about",          o_about,                4, "" },
    { "allow-close",    o_allow_close,          1, NULL },
    { "and-widget",     o_and_widget,           4, NULL },
    { "aspect",         o_aspect,               1, "<ratio>" },
    { "auto-placement", o_auto_placement,       1, NULL },
    { "backtitle",      o_backtitle,            1, "<backtitle>" },
    { "beep",           o_beep,                 1, NULL },
    { "beep-after",     o_beep_after,           1, NULL },
    { "begin",          o_begin,                1, "<y> <x>" },
    { "calendar",       o_calendar,             2, "<text> <height> <width> <day> <month> <year>" },
    { "cancel-label",   o_cancel_label,         1, "<str>" },
    { "checklist",      o_checklist,            2, "<text> <height> <width> <list height> <tag1> <item1> <status1>..." },
    { "clear",          o_clear,                1, "" },
    { "colors",         o_colors,               1, "" },
    { "cr-wrap",        o_cr_wrap,              1, "" },
    { "create-rc",      o_create_rc,            1, NULL },
    { "default-item",   o_default_item,         1, "<str>" },
    { "defaultno",      o_defaultno,            1, "" },
    { "dselect",        o_dselect,              2, "<dirpath> <height> <width>" },
    { "editbox",        o_textedit,             2, "<file> <height> <width> <filename>" },
    { "exit-label",     o_exit_label,           1, "<str>" },
    { "extra-button",   o_extra_button,         1, "" },
    { "extra-label",    o_extra_label,          1, "<str>" },
    { "fb",             o_fullbutton,           1, NULL },
    { "fixed-font",     o_fixed_font,           1, NULL },
    { "form",           o_form,                 2, "<text> <height> <width> <form height> <label1> <l_y1> <l_x1> <item1> <i_y1> <i_x1> <flen1> <ilen1>..." },
    { "fselect",        o_fselect,              2, "<filepath> <height> <width>" },
    { "fullbutton",     o_fullbutton,           1, NULL },
    { "gauge",          o_gauge,                2, "<text> <height> <width> [<percent>]" },
    { "guage",          o_gauge,                2, NULL },
    { "help",           o_help,                 4, "" },
    { "help-button",    o_help_button,          1, "" },
    { "help-label",     o_help_label,           1, "<str>" },
    { "help-status",    o_help_status,          1, "" },
    { "icon",           o_icon,                 1, NULL },
    { "ignore",         o_ignore,               1, "" },
    { "infobox",        o_infobox,              2, "<text> <height> <width>" },
    { "input-fd",       o_input_fd,             1, "<fd>" },
    { "inputbox",       o_inputbox,             2, "<text> <height> <width> [<init>]" },
    { "inputmenu",      o_inputmenu,            2, "<text> <height> <width> <menu height> <tag1> <item1>..." },
    { "insecure",       o_insecure,             1, "" },
    { "item-help",      o_item_help,            1, "" },
    { "keep-colors",    o_keep_colors,          1, NULL },
    { "keep-window",    o_keep_window,          1, "" },
    { "max-input",      o_max_input,            1, "<n>" },
    { "menu",           o_menu,                 2, "<text> <height> <width> <menu height> <tag1> <item1>..." },
    { "menubox",        o_menu,                 2, "<text> <height> <width> <menu height> <tag1> <item1>..." },
    { "mixedform",      o_mixedform,            2, "<text> <height> <width> <form height> <label1> <l_y1> <l_x1> <item1> <i_y1> <i_x1> <flen1> <ilen1> <type1> ..." },
    { "mixedgauge",     o_mixedgauge,           2, "<text> <height> <width> <form height> <tag1> <item1> ..." },
    { "msgbox",         o_msgbox,               2, "<text> <height> <width>" },
    { "no-cancel",      o_no_cancel,            1, "" },
    { "no-close",       o_no_close,             1, NULL },
    { "no-collapse",    o_no_collapse,          1, "" },
    { "no-cr-wrap",     o_no_cr_wrap,           1, NULL },
    { "no-kill",        o_no_kill,              1, "" },
    { "no-label",       o_no_label,             1, "<str>" },
    { "no-ok",          o_no_ok,                1, "" },
    { "no-shadow",      o_no_shadow,            1, "" },
    { "no-tags",        o_no_tags,              1, NULL },
    { "noitem",         o_noitem,               1, NULL },
    { "ok-label",       o_ok_label,             1, "<str>" },
    { "output-fd",      o_output_fd,            1, "<fd>" },
    { "passwordbox",    o_passwordbox,          2, "<text> <height> <width> [<init>]" },
    { "passwordform",   o_passwordform,         2, "<text> <height> <width> <form height> <label1> <l_y1> <l_x1> <item1> <i_y1> <i_x1> <flen1> <ilen1>..." },
    { "pause",          o_pause,                2, "<text> <height> <width> <seconds>" },
    { "print-maxsize",  o_print_maxsize,        5, "" },
    { "print-size",     o_print_size,           1, "" },
    { "print-version",  o_print_version,        7, "" },
    { "progress",       o_progressbox,          2, "[text] <height> <width>" },
    { "progressbox",    o_progressbox,          2, "[text] <height> <width>" },
    { "radiolist",      o_radiolist,            2, "<text> <height> <width> <list height> <tag1> <item1> <status1>..." },
    { "screen-center",  o_screen_center,        1, NULL },
    { "separate-output",o_separate_output,      1, "" },
    { "separate-widget",o_separate_widget,      1, "<str>" },
    { "separator",      o_separator,            1, NULL },
    { "shadow",         o_shadow,               1, "" },
    { "single-quoted",  o_single_quoted,        1, "" },
    { "size-err",       o_size_err,             1, "" },
    { "sleep",          o_sleep,                1, "<secs>" },
    { "smooth",         o_smooth,               1, NULL },
    { "stderr",         o_stderr,               1, "" },
    { "stdout",         o_stdout,               1, "" },
    { "tab-correct",    o_tab_correct,          1, "" },
    { "tab-len",        o_tab_len,              1, "<n>" },
    { "tailbox",        o_tailbox,              2, "<file> <height> <width>" },
    { "tailboxbg",      o_tailboxbg,            2, "<file> <height> <width>" },
    { "textbox",        o_textbox,              2, "<file> <height> <width> <filename>" },
    { "timebox",        o_timebox,              2, "<text> <height> <width> <hour> <minute> <second>" },
    { "textedit",       o_textedit,             2, "<file> <height> <width> <filename>" },
    { "timeout",        o_timeout,              1, "<secs>" },
    { "title",          o_title,                1, "<title>" },
    { "trim",           o_trim,                 1, "" },
    { "visit-items",    o_visit_items,          1, "" },
    { "under-mouse",    o_under_mouse,          1, NULL },
    { "version",        o_print_version,        5, "" },
    { "wmclass",        o_wmclass,              1, NULL },
    { "yes-label",      o_yes_label,            1, "<str>" },
    { "yesno",          o_yesno,                2, "<text> <height> <width>" },
    { NULL,             o_unknown,              0, NULL }
};
/* *INDENT-ON* */


//! static globals
QStringList  CDialogApp::mCommandLineArguments;

//! constructor
CDialogApp::CDialogApp(int &aArgc, char **apArgv) :
CApplication(aArgc,apArgv)
{
    mInputFd        = -1;
    mOutputFd       = -1;
    mUseColors      = false;    // use colors by default?
    mUseScrollBar   = false;    // RESERVED
    mVisitItems     = false;    // option "--visit-items"
    mIgnoreUnknown  = true;     // option "--ignore-unknown
    mTabLen         = DEFAULT_TAB_LEN;        // option "--tab-len n"
    mAspectRatio    = DEFAULT_ASPECT;       // option "--aspect ratio"
    mCompatability  = COMPAT_DEFAULT;
    mBoxesCount     = 1;

    QDate d;
    mTabLen = sizeof(d);
}

//! destructor
CDialogApp::~CDialogApp() 
{

}

//! method
int CDialogApp::init() {
    // ----------------------------------------------------------------------------------------------
    int vRetval = 0;

    QStringList vArguments = arguments();

    QFileInfo vProgramInfo(vArguments.at(0));
    QCoreApplication::setApplicationName(vProgramInfo.baseName());
    prepeareArguments(arguments(), LIMIT_INCLUDES);
#if defined(DEBUG) && (DEBUG==1)
    for (int k = 0; k < mCommandLineArguments.count(); k++)
    {
        qWarning() << " arg" << k << ":" << mCommandLineArguments[k];
    }
#endif
    return vRetval;
}

int CDialogApp::getInputFD()
{
    qWarning() << "InputFD = " << mInputFd << "\n";
    return mInputFd;
}

QFile* CDialogApp::getOutput()
{
    if(mOutput.openMode() == QIODevice::NotOpen)
    {
        if((mOutputFd == -1) || (mOutputFd == STDERR_FILENO))
            mOutput.open(stderr, QIODevice::WriteOnly | QIODevice::Text);
        else
            mOutput.open(mOutputFd, QIODevice::WriteOnly | QIODevice::Text);

    }

    return &mOutput;
}

int CDialogApp::run()
{
    int vRetValue = processArguments();

//    std::cout << "b mBoxesCount = " << mBoxesCount << "boxflag = " << boxflag << std::endl;
//      if(boxflag < 1)
//      {
//          runAbout();
//      } else{
//      std::cout << "a mBoxesCount = " << mBoxesCount << "boxflag = " << boxflag << std::endl;
//          exit(0);
//      }
    return vRetValue;
}

void CDialogApp::printMaxSize()
{
    QRect vScreenRect = QApplication::desktop()->screenGeometry();

    vScreenRect.setHeight(vScreenRect.height() / QApplication::desktop()->fontMetrics().height());
    vScreenRect.setWidth(vScreenRect.width() / QApplication::desktop()->fontMetrics().maxWidth());

    QString vResult;
    vResult.sprintf("MaxSize: %d, %d\n", vScreenRect.height(), vScreenRect.width());

    printString(vResult);
}

void CDialogApp::printVersion()
{
    printString(VERSION_QDIALOG);
}

void CDialogApp::printHelp()
{
    printString("  --calendar     <text> <height> <width> <day> <month> <year> \n \
  --checklist    <text> <height> <width> <list height> <tag1> <item1> <status1> ...  \n \
  --dselect      <directory> <height> <width>  \n \
  --fselect      <filepath> <height> <width>  \n \
  --timebox      <text> <height> <width> <hour> <minute> <second>  \n \
  --gauge        <text> <height> <width> [<percent>]  \n \
  --textbox      <file> <height> <width> <filename>  \n \
  --editbox      <file> <height> <width> <filename>  \n \
  --pause        <text> <height> <width> <seconds>  \n \
  --form         <text> <height> <width> <form height> <label1> <l_y1> <l_x1> <item1> <i_y1> <i_x1> <flen1> <ilen1>...   \n \
  --passwordform <text> <height> <width> <form height> <label1> <l_y1> <l_x1> <item1> <i_y1> <i_x1> <flen1> <ilen1>...   \n \
  --mixedform    <text> <height> <width> <form height> <label1> <l_y1> <l_x1> <item1> <i_y1> <i_x1> <flen1> <ilen1> <itype>...   \n \
  --inputbox     <text> <height> <width> [<init>]   \n \
  --inputmenu    <text> <height> <width> <menu height> <tag1> <item1>...   \n \
  --menu         <text> <height> <width> <menu height> <tag1> <item1>...   \n \
  --msgbox       <text> <height> <width>  \n \
  --passwordbox  <text> <height> <width> [<init>]  \n \
  --radiolist    <text> <height> <width> <list height> <tag1> <item1> <status1>...  \n \
  --yesno        <text> <height> <width>  \n \
  --infobox     <text> <height> <width> [<timeout>]  \n \
");
}


void CDialogApp::printString(const QString& aString)
{
    QTextStream vOut(getOutput());
    ///TODO: how to detect unicode console

    vOut << aString;
}

void CDialogApp::printStringQuoted(QString aString, bool aSingleQuoted, bool aIgnoreSpecial, bool aMultiline, bool aSeparate)
{
    QString vOutputString = "";

    QChar vQuote = aSingleQuoted?'\'':'\"';
    if(aIgnoreSpecial)
    {
        aString.replace(QString(vQuote), QString('\\'+vQuote));
        aString.replace("~", "");
    }

    if(!aMultiline)
    {

        if(aSeparate)
        {
            vOutputString += " ";
        }
        
        vOutputString += vQuote;

        vOutputString += aString;
        vOutputString += vQuote;
    }
    else
    {
        vOutputString += aString;
        vOutputString += "\n";
    }

    printString(vOutputString);
}

//! Command line functions

bool isOption(const QString& aStr)
{
    return (aStr.length() >=3) && aStr.startsWith("--") && aStr[2].isLetter();
}

/*
 * Change embedded "\n" substrings to '\n' characters and tabs to single
 * spaces.  If there are no "\n"s, it will strip all extra spaces, for
 * justification.  If it has "\n"'s, it will preserve extra spaces.  If cr_wrap
 * is set, it will preserve '\n's.
 */

QString trimString(const QString& aStr, bool aRemoveTabs, bool aTrim, bool aCrWrap)
{
    //qWarning(aStr);
    QString vRetval = aTrim?aStr.trimmed():aStr;
    
    vRetval.replace("\\r", "");
    vRetval.replace("\\f", "");
    vRetval.replace("\\v", "");

    //vRetval.replace("\n\r", "\n");
    //vRetval.replace("\r\n", "\n");
    //vRetval.replace("\r", "\n");

    if(aCrWrap)
    {
        vRetval.replace("\\n", "\n");
    }
    else
    {
        vRetval.replace("\\n", " ");
    }

    if(aRemoveTabs)
    {
        vRetval.replace("\\t", " ");
    }
    else
    {
        vRetval.replace("\\t", "\t");
    }

    if(aTrim)
    {
        //TODO: remove only multiply whitespaces. this is hard hack.
        while(vRetval.contains("  ")) vRetval.replace("  ", " ");

        vRetval.replace("\n ", "\n");
    }


    return vRetval;
}

int lookupOption(const QString& aName, int aPass)
{
    QString vName = aName;
    if (isOption(vName))
    {
        vName.remove(0,2);

        int n = 0;
        do
        {
            if (((aPass & gOptions[n].pass) != 0) && (vName.compare(gOptions[n].name) == 0))
            {
                return gOptions[n].code;
            }
            n++;
        }
        while(gOptions[n].name != NULL);
    }
    
    return o_unknown;
}

QString CDialogApp::commandLineArgumentAt(int aOffset)
{
    if((aOffset < 0) || (aOffset >= mCommandLineArguments.count()))
        return QString::Null();
    else
        return mCommandLineArguments[aOffset];
}

QString CDialogApp::argString(SBoxOptions* apOptions, int aOffset)
{
    QString vStr = commandLineArgumentAt(aOffset);

    if(apOptions)
    {
        vStr = trimString(vStr, !apOptions->nocollapse, apOptions->trim_whitespace, apOptions->cr_wrap);
    }

    // TODO: check vStr is correct.
    return vStr;
}

long CDialogApp::argNumeric(int aOffset)
{
    QString vStr = commandLineArgumentAt(aOffset);
    if(vStr.isNull() || vStr.isEmpty())
        return 0;

    bool vOk = true;
    long vRetval = vStr.toLong(&vOk);
    // TODO: check ok

    if(vOk)
        return vRetval;
    else
        return 0;
}


void CDialogApp::prepeareArguments(const QStringList& aArgs, int aCountIncludes)
{
    for(int i = ((aCountIncludes == LIMIT_INCLUDES)?1:0); i < aArgs.count(); i++)
    {
        QString vStr = aArgs[i];

        if (vStr.compare("--") == 0)
        {
            i++;
            continue;
        }
        else if(vStr.compare("--input-fd") == 0)
        {           
            i++;
            mInputFd = aArgs[i].toLong();
        }
        else if(vStr.compare("--output-fd") == 0)
        {           
            mOutputFd = aArgs[++i].toLong();
        }
        else if(vStr.compare("--stderr") == 0)
        {           
           mOutputFd = STDERR_FILENO;
        }
        else if(vStr.compare("--stdout") == 0)
        {           
           mOutputFd = STDOUT_FILENO;
        }
        else if (vStr.compare("--args") == 0)
        {
//            qWarning("Showing arguments at %d arg", i);
            for (int k = i; k < aArgs.count(); k++) 
            {
//                qWarning() << " arg" << k << ":" << aArgs[k];
            }
        }
        else if (vStr.compare("--file") == 0)
        {
            if (aCountIncludes <= 1)
            {
//                qWarning() << "Too many --file options";
            }
            else
            {
                i++;
                QString vFileName = aArgs[i];
                if (vFileName.length() > 0)
                {
                    // read from file
#ifdef DEBUG
                    //qWarning() << "read from file" << vFileName;
#endif

                    QStringList vStringsFromFile;

                    QFile vFile(vFileName);
                    QString vBuffer;

                    if (vFile.exists() && vFile.open(QIODevice::ReadOnly | QIODevice::Text))
                    {

                        QTextStream vStream(&vFile);
                        QString vLine = vStream.readLine();
#ifdef DEBUG
                        //qWarning() << "readed: " << vLine;
#endif

                        while(!vLine.isNull())
                        {
                            if(!vLine.isEmpty())
                            {
                                vLine.replace("\t", " ");
                                if(vLine[vLine.count()-1] == '\\')
                                    vLine.remove(vLine.count()-1, 1);
                                else
                                    vLine += " ";
                                vBuffer += vLine + "\n";
                            }

                            vLine = vStream.readLine();
                        }

                        QStringList vStringsFromFile = readArgsFromString(vBuffer);

                        prepeareArguments(vStringsFromFile, aCountIncludes - 1);
                    }
                }
            }
        }
        else
        {
            mCommandLineArguments << vStr;
        }
    }

}


int CDialogApp::processArguments()

{
    int vRetval = IDRET_OK;


    // Begin find boxes.
    
    int vPrevOffset = 0;
    int vOffset = 0;

    while(vOffset < mCommandLineArguments.count())
    {
        QString vOptionString = commandLineArgumentAt(vOffset);

        int vOption = lookupOption(vOptionString, 4);

        switch(vOption)
        {
        case o_print_maxsize:
            printMaxSize();
            mCommandLineArguments.clear();
            break;
        case o_print_version:
            printVersion();
            mCommandLineArguments.clear();
            break;
        case o_help:
            printHelp();
            mCommandLineArguments.clear();
            break;
        }

        vOption = lookupOption(vOptionString, 2);
        switch (vOption)
        {
        case o_about:
            vRetval = runAbout();
            break;
        case o_infobox:
            vRetval = runInfobox(vPrevOffset, vOffset);
            vPrevOffset = vOffset;
            break;
        /* boxes */
        case o_msgbox:
            vRetval = runBox(vPrevOffset, vOffset, false);
            vPrevOffset = vOffset;
            break;
        case o_yesno:
            vRetval = runBox(vPrevOffset, vOffset, true);
            vPrevOffset = vOffset;
            break;
        case o_inputbox:
            vRetval = runBox(vPrevOffset, vOffset, false, true);
            vPrevOffset = vOffset;
            break;
        case o_passwordbox:
            vRetval = runBox(vPrevOffset, vOffset, false, true, true);
            vPrevOffset = vOffset;
            break;
        case o_pause:
            vRetval = runPause(vPrevOffset, vOffset);
            vPrevOffset = vOffset;
            break;
        case o_gauge:
            vRetval = runGauge(vPrevOffset, vOffset);
            vPrevOffset = vOffset;
            break;
        /* text boxes */
        case o_textbox:
            vRetval = runTextBox(vPrevOffset, vOffset);
            vPrevOffset = vOffset;
            break;
        case o_textedit:
            vRetval = runTextBox(vPrevOffset, vOffset, false);
            vPrevOffset = vOffset;
            break;
        case o_tailbox:
            vRetval = runTextBox(vPrevOffset, vOffset, false, true);
            vPrevOffset = vOffset;
            break;
        case o_progressbox:
            vRetval = runTextBox(vPrevOffset, vOffset, false, true, true);
            vPrevOffset = vOffset;
            break;
        /* additional boxes */
        case o_calendar:
            vRetval = runDateTime(vPrevOffset, vOffset, false);
            vPrevOffset = vOffset;
            break;
        case o_timebox:
            vRetval = runDateTime(vPrevOffset, vOffset, true);
            vPrevOffset = vOffset;
            break;
        case o_dselect:
            vRetval = runSelectPath(vPrevOffset, vOffset, true);
            vPrevOffset = vOffset;
            break;
        case o_fselect:
            vRetval = runSelectPath(vPrevOffset, vOffset, false);
            vPrevOffset = vOffset;
            break;
        /* menus */
        case o_menu:
        case o_menubox:
            vRetval = runMenu(vPrevOffset, vOffset);
            vPrevOffset = vOffset;
            break;
        case o_checklist:
            vRetval = runMenu(vPrevOffset, vOffset, MENUTYPE_CHECKLIST);
            vPrevOffset = vOffset;
            break;
        case o_radiolist:
            vRetval = runMenu(vPrevOffset, vOffset, MENUTYPE_RADIOLIST);
            vPrevOffset = vOffset;
            break;
        case o_inputmenu:
            vRetval = runMenu(vPrevOffset, vOffset, MENUTYPE_INPUTMENU);
            vPrevOffset = vOffset;
            break;
        /*form*/
        case o_form:
            vRetval = runForm(vPrevOffset, vOffset);
            vPrevOffset = vOffset;
            break;
        case o_mixedform:
            vRetval = runForm(vPrevOffset, vOffset, true);
            vPrevOffset = vOffset;
            break;
        case o_passwordform:
            vRetval = runForm(vPrevOffset, vOffset, false, true);
            vPrevOffset = vOffset;
            break;

        default:
            vOffset++;
        }

    }
                
//    qWarning() << "exiting main loop proc";
    return vRetval;
}


// "Common" options apply to all widgets more/less.
int CDialogApp::readCommonOptions(SBoxOptions* apOptions, int aOffset, int aEndOffset)
{
    if(apOptions == NULL)
        return aOffset;

    if(aEndOffset == 0)
        aEndOffset = mCommandLineArguments.count();

    bool vDone = false;

    while (aOffset < aEndOffset && !vDone)
    {
        QString vOptionString = commandLineArgumentAt(aOffset);
        int vOption = lookupOption(vOptionString, 5);
        switch (vOption)
        {
            case o_and_widget:
                break;

            /* GLOBAL SCOPE */
            case o_input_fd:
                mInputFd = argNumeric(++aOffset);
                break;
            case o_output_fd:
                mOutputFd = argNumeric(++aOffset);
                break;
            case o_visit_items:
                mVisitItems = true;
                break;
            case o_aspect:
                mAspectRatio = argNumeric(++aOffset);
                break;
            case o_separator:
            case o_separate_widget:
                mSeparateBoxes = argString(apOptions, ++aOffset);
                break;
            case o_shadow:
                //mUseShadow = true;
                break;
            case o_no_shadow:
                //mUseShadow = false;
                break;
            case o_tab_len:
                mTabLen = argNumeric(++aOffset);
                break;

            case o_backtitle:
                mBackTitle = argString(apOptions, ++aOffset);
                break;
            case o_ignore:
                mIgnoreUnknown = true;
                break;

            /* CURRENT BOX SCOPE */
            case o_title:
                apOptions->title = argString(apOptions, ++aOffset);
                break;
            case o_separate_output:
                apOptions->separate_output = true;
                break;
            case o_colors:
                apOptions->colors = true;
                break;
            case o_cr_wrap:
                apOptions->cr_wrap = true;
                break;
            case o_no_collapse:
                apOptions->nocollapse = true;
                break;
            case o_no_kill:
                apOptions->cant_kill = true;
                break;
            case o_no_cancel:
                apOptions->no_cancel = true;
                break;
            case o_no_ok:
                apOptions->no_ok = true;
                break;
            case o_single_quoted:
                apOptions->single_quoted = true;
                break;
            case o_size_err:
                apOptions->size_err = true;
                break;
            case o_no_tags:
                apOptions->notags = true;
                break;
            case o_beep:
                apOptions->beep_signal = true;
                break;
            case o_beep_after:
                apOptions->beep_after_signal = true;
                break;
            case o_defaultno:
                apOptions->defaultno = true;
                break;
            case o_default_item:
                apOptions->default_item = argString(apOptions, ++aOffset);
                break;
            case o_insecure:
                apOptions->insecure = true;
                break;
            case o_item_help:
                apOptions->item_help = true;
                break;
            case o_help_button:
                apOptions->help_button = true;
                break;
            case o_help_status:
                apOptions->help_status = true;
                break;
            case o_extra_button:
                apOptions->extra_button = true;
                break;
            case o_keep_window:
                apOptions->keep_window = true;
                break;
            case o_print_size:
                apOptions->print_size = true;
                break;
            case o_tab_correct:
                apOptions->tab_correct = true;
                break;
            case o_sleep:
                apOptions->sleep_secs = argNumeric(++aOffset);
                break;
            case o_timeout:
                apOptions->timeout_secs = argNumeric(++aOffset);
                break;
            case o_max_input:
                apOptions->max_input = argNumeric(++aOffset);
                break;
            case o_trim:
                apOptions->trim_whitespace = true;
                break;
            case o_begin:
                apOptions->begin_set = true;
                apOptions->begin_y = argNumeric(++aOffset);
                apOptions->begin_x = argNumeric(++aOffset);
                break;
            case o_clear:
                apOptions->clear = true;
                break;
            case o_yes_label:
                apOptions->yes_label = argString(apOptions, ++aOffset);
                break;
            case o_no_label:
                apOptions->no_label = argString(apOptions, ++aOffset);
                break;
            case o_ok_label:
                apOptions->ok_label = argString(apOptions, ++aOffset);
                break;
            case o_cancel_label:
                apOptions->cancel_label = argString(apOptions, ++aOffset);
                break;
            case o_extra_label:
                apOptions->extra_label = argString(apOptions, ++aOffset);
                break;
            case o_exit_label:
                apOptions->exit_label = argString(apOptions, ++aOffset);
                break;
            case o_help_label:
                apOptions->help_label = argString(apOptions, ++aOffset);
                break;
            case o_noitem:
            case o_fullbutton:
                /* ignore */
                break;
                /* options of Xdialog which we ignore */
            case o_icon:
            case o_wmclass:
                (void) argString(NULL, ++aOffset);
            case o_allow_close:
            case o_auto_placement:
            case o_fixed_font:
            case o_keep_colors:
            case o_no_close:
            case o_no_cr_wrap:
            case o_screen_center:
            case o_smooth:
            case o_under_mouse:
                break;
            case o_unknown:
                if (mIgnoreUnknown)
                {
                    break;
                }

            /* FALLTHRU */
             default:                /* no more common options */
                vDone = true;
                break;
             }
             if (!vDone)
                aOffset++;
        }

        // copy params from global scope:

        apOptions->aspect = mAspectRatio;
        
        return aOffset;
}


void CDialogApp::readSize(SBoxOptions* apOptions, int& aOffset)
{
    QString vSizeStr = argString(NULL, ++aOffset);

    bool vOk;

    if(! vSizeStr.contains("x"))
    {
        apOptions->size_in_pixels = false;
        apOptions->height = vSizeStr.toLong(&vOk);
        apOptions->width  = argNumeric(++aOffset);
    }
    else
    {
            apOptions->size_in_pixels = true;

            QStringList vArgs = vSizeStr.split("x");

            apOptions->height = vArgs[0].toLong();
            vSizeStr = vArgs[1];
            if(vSizeStr.contains("+"))
                vSizeStr.replace("+", " +");
            if(vSizeStr.contains("-"))
                vSizeStr.replace("-", " -");
            vArgs = vSizeStr.split(" ");
            int vCountMissing = 3 - vArgs.count();
            if(vCountMissing > 0)
            {
                for(int i = 0; i < vCountMissing; i++)
                {
                    QString vTmp = argString(NULL, aOffset + 1);
    
                    QChar vChar = vTmp[0];
                    if((vChar == '+') || (vChar == '-'))
                    {
                        vTmp.remove(0, 1);
                        if(vTmp.contains("+"))
                        {
                            vTmp.replace("+", " +");
                            i++;
                        }
                        if(vTmp.contains("-"))
                        {
                            vTmp.replace("-", " -");
                            i++;
                        }
                        vSizeStr += " ";
                        vSizeStr += vChar;
                        vSizeStr += vTmp;

                        aOffset ++;
                    }
                    else
                        break;
                }

                vArgs = vSizeStr.split(" ");
            }

            for(int i = 0; i < vArgs.count(); i++)
            {
                QString vStr = vArgs[i];

                switch(i)
                {
                    case 0:
                        apOptions->width = vStr.toLong();
                        break;
                    case 1:
                        apOptions->begin_x = vStr.toLong();
                        break;
                    case 2:
                        apOptions->begin_y = vStr.toLong();
                        break;
                }
            }
    }

//#ifdef DEBUG
//    qWarning() << "BOX GEOMETRY: width = " << apOptions->width << " height = " << apOptions->height << " x = " << apOptions->begin_x << " y = " << apOptions->begin_y << " pixels = " << apOptions->size_in_pixels;
//#endif
}

void CDialogApp::beforeRunBox()
{
    if(mBoxesCount > 0)
    {
        if(!mSeparateBoxes.isEmpty())
        {
            printString(mSeparateBoxes);
        }
        else
        {
            printString("\t");
        }
    }
    mBoxesCount++;
}

void CDialogApp::afterRunBox()
{
    ;
    #if defined(DEBUG) && (DEBUG==1)
    std::cout << "CDialogApp:: box terminated!" << mBoxesCount << std::endl;
    #endif
}

//! In MultiWidget this function is needed to count how many tags a widget (menu, checklist, radiolist) has

int CDialogApp::howManyTags(int aPos, int aGroup)
{
    int vResult = 0;
    int vPos = aPos;
    int vCount = mCommandLineArguments.count();

    while ( vPos < vCount )
    {
        QString vStr = mCommandLineArguments.at(vPos);

        if (isOption(vStr))
            break;

        int vHave = restArgs(vPos);
        if (vHave < aGroup)
        {
            //qWarning() << "Expected" << aGroup << "arguments, found only" << vHave;
            //break;
            return 0;
        }

        vPos += aGroup;
        vResult++;
    }

    return vResult;
}

//! Count arguments, stopping at the end of the argument list, or on any of our "--" tokens.

int CDialogApp::restArgs(int aPos)
{
    int vPos = aPos;
    int vCount = mCommandLineArguments.count();

    while ( vPos < vCount )
    {
        QString vStr = mCommandLineArguments.at(vPos);

        if(vStr.isNull())
            break;

        if(lookupOption(vStr, 7) != o_unknown)
        {
            if(vPos != aPos) // else aPos points to a "--" token */
                break;
        }

        vPos++;
    }

    return vPos - aPos;
}

//! runXXX functions

int CDialogApp::runAbout()
{
    beforeRunBox();

    QMessageBox* vpAbout = new QMessageBox();

    vpAbout->setText(VERSION_QDIALOG);
    vpAbout->addButton(QMessageBox::Ok);
    vpAbout->exec();

    delete vpAbout;

    afterRunBox();

    return IDRET_OK;
}

int CDialogApp::runBox(int aPrevOffset, int& aOffset, bool aYesNo, bool aInputBox, bool aPasswordBox)
{
    beforeRunBox();

    int vRetval = IDRET_OK;

    CMsgBox* vpBox = NULL;
    if(aInputBox)
    {
        vpBox = new CInputBox();
        if(aPasswordBox)
        {
            static_cast<CInputBox*>(vpBox)->setPasswordMode(true);
        }
    }
    else
    {
        vpBox = new CMsgBox();
    }

    Q_CHECK_PTR(vpBox);
    if(vpBox == NULL)
        return IDRET_ERROR;

    SBoxOptions* vpOpts = vpBox->getBoxOptions(); // simplify

    // read options before --name
    readCommonOptions(vpOpts, aPrevOffset, aOffset);

    // read options after --name
    QString vText = argString(vpOpts, ++aOffset);

    readSize(vpOpts, aOffset);

    aOffset++;

    if(aInputBox)
    {
        QString vOptionalInit = argString(vpOpts, aOffset);
        if(!vOptionalInit.isEmpty() && (vOptionalInit.left(2).compare("--") != 0))
        {
            static_cast<CInputBox*>(vpBox)->setEditText(vOptionalInit);
            aOffset++;
        }
    }

    // work with Box

    vpBox->setWindowTitle(vpOpts->title);
    vpBox->setText(vText);

    vpBox->createStandardButtons(aYesNo || aInputBox, aYesNo);
        
    if(aOffset < mCommandLineArguments.count())
    {
        if(lookupOption(commandLineArgumentAt(aOffset), 5) == o_and_widget)
            vpOpts->and_widget = true;
    }

    vpBox->adjustPos();
    vpBox->adjustSize();

    vpBox->setTimeout(vpOpts->timeout_secs);
    vRetval = vpBox->exec();

    if(vpBox->escapePressed())
        vRetval = IDRET_ESC;

    if(aInputBox && (vRetval == IDRET_OK))
    {
        QString vInputText = static_cast<CInputBox*>(vpBox)->getEditText();
        printString(vInputText);
    }

    delete vpBox;

    afterRunBox();

    return vRetval;
}

int CDialogApp::runInfobox(int aPrevOffset, int& aOffset)
{       
    beforeRunBox();

    int vRetval = IDRET_OK;

    CMsgBox* vpBox = new CMsgBox();
    Q_CHECK_PTR(vpBox);
    if(vpBox == NULL)
        return IDRET_ERROR;

    SBoxOptions* vpOpts = vpBox->getBoxOptions(); // simplify

    // read options before --name
    readCommonOptions(vpOpts, aPrevOffset, aOffset);

    // read options after --name
    QString vText = argString(vpOpts, ++aOffset);

    readSize(vpOpts, aOffset);

    if(mCompatability == COMPAT_XDIALOG)
    {
        //optional timeout.
       
    }

    aOffset++;

    // work with Box

    vpBox->setWindowTitle(vpOpts->title);
    vpBox->setText(vText);

    vpBox->createStandardButtons(false, false);

    if(aOffset < mCommandLineArguments.count())
    {
        if(lookupOption(commandLineArgumentAt(aOffset), 5) == o_and_widget)
            vpOpts->and_widget = true;
    }

    vpBox->adjustPos();
    vpBox->adjustSize();

    vpBox->setTimeout(vpOpts->timeout_secs);
    //vpBox->show();
    vRetval = vpBox->exec();

    if(vpBox->escapePressed())
        vRetval = IDRET_ESC;

    delete vpBox;

    afterRunBox();

    return vRetval;
}

#define CHECK_VALID_ARG(a)  if( a.isNull() ) { return IDRET_ERROR; }

int CDialogApp::runMenu(int aPrevOffset, int& aOffset, NMenuType aType)
{
    beforeRunBox();

    int vRetval = IDRET_OK;

    CMenuBox* vpBox = new CMenuBox();
    Q_CHECK_PTR(vpBox);
    if(vpBox == NULL)
        return IDRET_ERROR;


    SBoxOptions* vpOpts = vpBox->getBoxOptions(); // simplify

    // read options before --name
    readCommonOptions(vpOpts, aPrevOffset, aOffset);

    vpBox->setMenuType(aType);

    // read options after --name
    QString vText   = argString(vpOpts, ++aOffset);

    readSize(vpOpts, aOffset);

    long vMenuHeight = argNumeric(++aOffset);

//  dlg->SetMenuItemsPos(0, menuheight);

    aOffset++;

    int vCountItemTags = vpOpts->item_help ? 3 : 2;
    int vDefaultIndex = 0;


    if( aType >= MENUTYPE_RADIOLIST )
        vCountItemTags ++;

    int vTags = howManyTags(aOffset, vCountItemTags);
    for(int vTag = 0; vTag < vTags; vTag++)
    {
        QString vItemTag = commandLineArgumentAt(aOffset++);
        CHECK_VALID_ARG(vItemTag);
	    
        QString vItemName = commandLineArgumentAt(aOffset++);
        CHECK_VALID_ARG(vItemName);

        bool vItemChecked = false;
        if((aType == MENUTYPE_CHECKLIST) || (aType == MENUTYPE_RADIOLIST))
        {
            QString vStringItemChecked = commandLineArgumentAt(aOffset++);
            CHECK_VALID_ARG(vStringItemChecked);
            if(vStringItemChecked.compare("ON", Qt::CaseInsensitive) == 0)
                vItemChecked = true;
            else if(vStringItemChecked.compare("1") == 0)
                vItemChecked = true;
        }
        QString vItemHelp = "";
        if(vpOpts->item_help)
        {
            vItemHelp = commandLineArgumentAt(aOffset++);
            CHECK_VALID_ARG(vItemHelp);
        }

        if(! vpOpts->default_item.isEmpty() )
        {
            if(vItemTag.compare( vpOpts->default_item ) == 0)
            {
                vDefaultIndex = vTag;
            }
        }
                
        if(vItemTag.isNull())
            break;
        else
            vpBox->addMenuItem(vItemTag, vItemName, vItemHelp, vItemChecked);
    }
        
    vpBox->setSelectedItem(vDefaultIndex);

    if(vMenuHeight == 0)
        vMenuHeight = vTags;

    vpBox->setMenuHeight(vMenuHeight);
        

    // work with Box

    vpBox->setWindowTitle(vpOpts->title);
    vpBox->setText(vText);

    vpBox->createStandardButtons(false, true);

    if(aOffset < mCommandLineArguments.count())
    {
        if(lookupOption(commandLineArgumentAt(aOffset), 5) == o_and_widget)
            vpOpts->and_widget = true;
    }

    vpBox->adjustPos();
    vpBox->adjustSize();

    vpBox->setTimeout(vpOpts->timeout_secs);
    vRetval = vpBox->exec();

    if(vpBox->escapePressed())
    {
        vRetval = IDRET_ESC;
    }

    if((vRetval != IDRET_CANCEL) && (vRetval != IDRET_ESC))
    {
        if(aType == MENUTYPE_INPUTMENU)
        {
            QList<QTreeWidgetItem*> vItems = vpBox->getItems();
            for(int i = 0; i<vItems.count(); i++)
            {
                QString vCurrText = vItems.at(i)->text(1);
                QString vOriginalText = vItems.at(i)->data(0, Qt::UserRole+1).toString();
                QString vTag = vItems.at(i)->text(0);

                if(vOriginalText.compare(vCurrText) != 0)
                {
                    QString vOutputStr = "RENAMED ";
                    vOutputStr += vTag;
                    vOutputStr += " ";
                    vOutputStr += vCurrText;
                    vOutputStr += "\n";
                    printString(vOutputStr);
                }
            }

            QString vSelectedTag = vpBox->selectedTag();
            printStringQuoted(vSelectedTag, vpOpts->single_quoted, true);
        }
        else if(aType == MENUTYPE_CHECKLIST)
        {
            QList<QTreeWidgetItem*>* vpCheckedItems = vpBox->getCheckedItems();
            for(int i = 0; i<vpCheckedItems->count(); i++)
            {
                printStringQuoted(vpCheckedItems->at(i)->text(0), vpOpts->single_quoted, true, vpOpts->separate_output, i != 0);
            }
            delete vpCheckedItems;
        }
        else if(aType == MENUTYPE_RADIOLIST)
        {
            printString(vpBox->getFirstCheckedItem() + "\n");
        }
        else //     MENUTYPE_MENU
        {
            QString vSelectedTag = vpBox->selectedTag();
            printStringQuoted(vSelectedTag, vpOpts->single_quoted, true);
        }
    }

    delete vpBox;

    afterRunBox();

    return vRetval;
}

int CDialogApp::runDateTime(int aPrevOffset, int& aOffset, bool aTime /* = false */)
{
    beforeRunBox();

    int vRetval = IDRET_OK;

    CMsgBox* vpBox = NULL;

    if(aTime)
        vpBox = new CTimeBox();
    else
        vpBox = new CCalendarBox();

    Q_CHECK_PTR(vpBox);
    if(vpBox == NULL)
        return IDRET_ERROR;

    SBoxOptions* vpOpts = vpBox->getBoxOptions(); // simplify

    // read options before --name
    readCommonOptions(vpOpts, aPrevOffset, aOffset);

    // read options after --name
    QString vText = argString(vpOpts, ++aOffset);

    readSize(vpOpts, aOffset);

    aOffset++;

    if(aTime)
    {
        static_cast<CTimeBox*>(vpBox)->setTime(QTime::currentTime());
    }


    bool vOk = false;
    QString vOpt1 = argString(vpOpts, aOffset);
    if(!vOpt1.isEmpty())
    {
        aOffset++;
        int vArg1 = vOpt1.toLong(&vOk);
        if(vOk)
        {
                QString vOpt2 = argString(vpOpts, aOffset);
                if(!vOpt2.isEmpty())
                {
                    aOffset++;
                    int vArg2 = vOpt2.toLong(&vOk);
                    if(vOk)
                    {
                        QString vOpt3 = argString(vpOpts, aOffset);
                        if(!vOpt3.isEmpty())
                        {
                            aOffset++;
                            int vArg3 = vOpt3.toLong(&vOk);
                            if(vOk)
                            {
                                if(aTime)
                                {
                                    QTime vTime;
                                    vTime.setHMS(vArg1, vArg2, vArg3, 0);
                                    static_cast<CTimeBox*>(vpBox)->setTime(vTime);
                                }
                                else
                                {
                                    QDate vDate;
                                    vDate.setDate(vArg3, vArg2, vArg1);
                                    static_cast<CCalendarBox*>(vpBox)->setDate(vDate);
                                }
                            }
                        }
                    }
                }
            }
    }

    vpBox->setWindowTitle(vpOpts->title);
    vpBox->setText(vText);

    vpBox->createStandardButtons();

    vpBox->adjustPos();
    vpBox->adjustSize();

    vpBox->setTimeout(vpOpts->timeout_secs);
    vRetval = vpBox->exec();

    if(vpBox->escapePressed())
        vRetval = IDRET_ESC;

    if(vRetval == IDRET_OK)
    {
        if(aTime)
        {
            QTime vTime = static_cast<CTimeBox*>(vpBox)->getTime();
            QString vTimeStr = vTime.toString("hh:mm:ss\n");
            printString(vTimeStr);
        }
        else
        {
            QDate vDate = static_cast<CCalendarBox*>(vpBox)->getDate();
            QString vDateStr = vDate.toString("dd/MM/yyyy\n");
            printString(vDateStr);
        }
    }

    delete vpBox;

    afterRunBox();

    return vRetval;
}

int CDialogApp::runSelectPath(int aPrevOffset, int& aOffset, bool aDirectory)
{
    mBoxesCount++;

    int vRetval = IDRET_OK;

    CFileBox* vpBox = new CFileBox();

    Q_CHECK_PTR(vpBox);
    if(vpBox == NULL)
        return IDRET_ERROR;

    SBoxOptions* vpOpts = vpBox->getBoxOptions(); // simplify

    // read options before --name
    readCommonOptions(vpOpts, aPrevOffset, aOffset);

    // read options after --name
    QString vPath = argString(vpOpts, ++aOffset);

    readSize(vpOpts, aOffset);

    aOffset++;

    vpBox->setWindowTitle(vpOpts->title);

    if(aDirectory)
    {
        vpBox->setFileMode(QFileDialog::DirectoryOnly);
        vpBox->setDirectory(vPath);
    }
    else
    {
        vpBox->setFileMode(QFileDialog::AnyFile);
        vpBox->setDirectory(vPath);
        vpBox->selectFile(vPath);
    }

    vpBox->adjustPos();
    vpBox->adjustSize();

    vpBox->setTimeout(vpOpts->timeout_secs);

    int vResult = vpBox->exec();

    switch(vResult)
    {
        case QDialog::Accepted:
            vRetval = IDRET_OK;
            break;
        case QDialog::Rejected:
            vRetval = IDRET_CANCEL;
            if(vpBox->escapePressed()) vRetval = IDRET_ESC;
            break;
    }



    if(vRetval == IDRET_OK)
    {
        vPath = vpBox->directory().path();
        if(!aDirectory)
        {
            QStringList vFiles = vpBox->selectedFiles();
            for(int i = 0; i < vFiles.count(); i++)
            {
                QString vFilePath = vPath;
                vFilePath += "/";
                vFilePath += vFiles.at(i);
                vFilePath += "\n";
                printString(vFilePath);
            }
        }
        else
        {
            vPath += "\n";
            printString(vPath);
        }
    }

    delete vpBox;

    afterRunBox();

    return vRetval;
}

int CDialogApp::runGauge(int aPrevOffset, int& aOffset)
{
    beforeRunBox();

    int vRetval = IDRET_OK;

    CGaugeBox* vpBox = new CGaugeBox();

    Q_CHECK_PTR(vpBox);
    if(vpBox == NULL)
        return IDRET_ERROR;

    SBoxOptions* vpOpts = vpBox->getBoxOptions(); // simplify

    // read options before --name
    readCommonOptions(vpOpts, aPrevOffset, aOffset);

    // read options after --name
    QString vText = argString(vpOpts, ++aOffset);

    readSize(vpOpts, aOffset);

    aOffset++;

    bool vOk = false;
    QString vOpt1 = argString(vpOpts, aOffset);
    if(!vOpt1.isEmpty())
    {
        aOffset++;
        int vArg1 = vOpt1.toLong(&vOk);
        if(vOk)
        {
            vpBox->setPercent(vArg1);
        }
    }

    vpBox->setWindowTitle(vpOpts->title);
    vpBox->setText(vText);

    vpBox->createStandardButtons(true, false);

    vpBox->adjustPos();
    vpBox->adjustSize();

    vpBox->setTimeout(vpOpts->timeout_secs);

    vRetval = vpBox->exec();

    if(vpBox->escapePressed())
        vRetval = IDRET_ESC;

    if(vRetval == IDRET_OK)
    {
    }

    delete vpBox;

    afterRunBox();

    return vRetval;
}

int CDialogApp::runPause(int aPrevOffset, int& aOffset)
{
    int vRetval = IDRET_OK;

    int vTimeoutSec = argNumeric(aOffset + 4); // read timeout. if timeout == 0 run MsgBox.

    if(vTimeoutSec <= 0)
    {
        vRetval = runBox(aPrevOffset, aOffset);
        aOffset++;
        return vRetval;
    }
    // else timeout > 0

    beforeRunBox();


    CPauseBox* vpBox = new CPauseBox();

    Q_CHECK_PTR(vpBox);
    if(vpBox == NULL)
        return IDRET_ERROR;

    SBoxOptions* vpOpts = vpBox->getBoxOptions(); // simplify

    // read options before --name
    readCommonOptions(vpOpts, aPrevOffset, aOffset);

    // read options after --name
    QString vText = argString(vpOpts, ++aOffset);

    aOffset += 2;

    //
    vpBox->setWindowTitle(vpOpts->title);
    vpBox->setText(vText);

    vpBox->createStandardButtons(true, false);

    vpBox->adjustPos();
    vpBox->adjustSize();

    vpBox->setTimeout(vpOpts->timeout_secs); // this is another timeout. not vTimeoutSec

    vpBox->setPauseSeconds(vTimeoutSec);
    vRetval = vpBox->exec();

    delete vpBox;

    afterRunBox();

    return vRetval;
}

int CDialogApp::runTextBox(int aPrevOffset, int& aOffset, bool aReadOnly /*=true*/, bool aTailBox /*= false*/, bool aProgressBox /*= false*/)
{
    beforeRunBox();

    int vRetval = IDRET_OK;

    CTextBox* vpBox = NULL;
    if(!aTailBox)
        vpBox = new CTextBox();
    else
        vpBox = new CTailBox();

    Q_CHECK_PTR(vpBox);
    if(vpBox == NULL)
        return IDRET_ERROR;

    SBoxOptions* vpOpts = vpBox->getBoxOptions();

    if(aProgressBox)
    {
        bool vOk = false;
        QString vOpt1 = argString(vpOpts, aOffset);
        if(!vOpt1.isEmpty())
        {
            int vArg1 = vOpt1.toLong(&vOk);

            if(!vOk)
            {
                vpBox->setText(vOpt1);
                aOffset++;
            }
        }
    }

    // read options before --name
    readCommonOptions(vpOpts, aPrevOffset, aOffset);

    // read options after --name
    QString vFileName = argString(vpOpts, ++aOffset);

    readSize(vpOpts, aOffset);

    aOffset++;


    vpBox->setWindowTitle(vpOpts->title);
    //vpBox->setText(vText);
    vpBox->setFileName(vFileName);
    if(aProgressBox)
    {
        dynamic_cast<CTailBox*>(vpBox)->setProgressBoxMode();
    }

    vpBox->createStandardButtons();

    vpBox->adjustPos();
    vpBox->adjustSize();

    vpBox->setTimeout(vpOpts->timeout_secs);

    vpBox->setReadOnly(aReadOnly);

    vRetval = vpBox->exec();

    if(vpBox->escapePressed())
        vRetval = IDRET_ESC;

    if(vRetval == IDRET_OK)
    {
        if(!vpBox->isReadOnly())
        {
            printString(vpBox->content());
        }
    }

    delete vpBox;

    afterRunBox();

    return vRetval;
}

int CDialogApp::runForm(int aPrevOffset, int& aOffset, bool aMixedForm /*=false*/, bool aPasswordForm /*=false*/)
{
    beforeRunBox();

    int vRetval = IDRET_OK;

    CFormBox* vpBox = new CFormBox();
    Q_CHECK_PTR(vpBox);
    if(vpBox == NULL)
        return IDRET_ERROR;


    SBoxOptions* vpOpts = vpBox->getBoxOptions(); // simplify

    // read options before --name
    readCommonOptions(vpOpts, aPrevOffset, aOffset);

    // read options after --name
    QString vText   = argString(vpOpts, ++aOffset);

    readSize(vpOpts, aOffset);

    long vFormHeight = argNumeric(++aOffset);

    aOffset++;

    // --form text height width formheight [ label y x item y x flen ilen ] [itemhelp] ...
    int vCountItemTags = ( vpOpts->item_help ? 9 : 8 ) + ( aMixedForm ? 1 : 0 );
    int vDefaultIndex = 0;

    int vMaxY = 0;

    int vTags = howManyTags(aOffset, vCountItemTags);
    for(int vTag = 0; vTag < vTags; vTag++)
    {
        QString vLabel      = commandLineArgumentAt(aOffset++);
        CHECK_VALID_ARG(vLabel);
        int vPosY           = argNumeric(aOffset++);
        int vPosX           = argNumeric(aOffset++);
        QPoint vPos(vPosX, vPosY);
        QString vItem       = commandLineArgumentAt(aOffset++);
        CHECK_VALID_ARG(vItem);
        vPosY               = argNumeric(aOffset++);
        vPosX               = argNumeric(aOffset++);
        QPoint vItemPos(vPosX, vPosY);
        int vItemFieldLength    = argNumeric(aOffset++);
        int vMaxItemLength     = argNumeric(aOffset++);

        int vItemType = FIELD_NORMAL;
        if(aMixedForm)
            vItemType = argNumeric(aOffset++);

        if(aPasswordForm)
        {
            vItemType = FIELD_HIDDEN;
        }

        QString vItemHelp = "";
        if(vpOpts->item_help)
        {
            vItemHelp = commandLineArgumentAt(aOffset++);
            CHECK_VALID_ARG(vItemHelp);
        }

        if(! vpOpts->default_item.isEmpty() )
        {
            if(vItem.compare( vpOpts->default_item ) == 0)
            {
                vDefaultIndex = vTag;
            }
        }

        if(vItem.isNull())
            break;
        else
        {
            vpBox->addItem( vLabel, vPos,
                            vItem, vItemPos,
                            vItemFieldLength, vMaxItemLength,
                            vItemHelp, vItemType);

            if(vPos.y() > vMaxY)
                vMaxY = vPos.y();
            if(vItemPos.y() > vMaxY)
                vMaxY = vItemPos.y();

        }
    }

    // work with Box

/*
        int box_position = SetDlgSize(dlg,
                width, height,
                25, 2,
                2, 6 + max_y);

*/

    vpBox->setWindowTitle(vpOpts->title);
    vpBox->setText(vText);

    vpBox->createStandardButtons(false, true);

    if(aOffset < mCommandLineArguments.count())
    {
        if(lookupOption(commandLineArgumentAt(aOffset), 5) == o_and_widget)
            vpOpts->and_widget = true;
    }

    vpBox->adjustPos();
    vpBox->adjustSize();

    vpBox->prepeareScroll();

    vpBox->setTimeout(vpOpts->timeout_secs);
    vRetval = vpBox->exec();

    if(vpBox->escapePressed())
    {
        vRetval = 255;
    }

    // write result to output

    const QWidgetList* vListLineEdits = vpBox->listLineEdits();
    const QWidgetList* vListLabels    = vpBox->listLabels();

    QWidgetList::const_iterator vEditsItem = vListLineEdits->begin();
    while(vEditsItem < vListLineEdits->end())
    {
        const QLineEdit* vpEdit = (QLineEdit*)*vEditsItem;
        printString(vpEdit->text());
        printString("\n");

        vEditsItem++;
    }



    delete vpBox;

    afterRunBox();

    return vRetval;
}

