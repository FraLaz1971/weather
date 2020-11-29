/****************************************************************************
 **
 ** Copyright (C) 206-2007 Sergey A. Sukiyazov.  All rights reserved.
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
 ** AUTHOR: Sergey A. Sukiyazov <sukiyazov_sa@mail.ru>
 **
 ****************************************************************************/
//! -*- coding: UTF-8 -*-
#define SOURCE_CODING "UTF-8"

#include "config.h"

extern "C" {
    #include <locale.h>
    #include <signal.h>
    #include <unistd.h>
    #include <errno.h>
    #include <stdio.h>
#if defined(Q_OS_LINUX)
    #include <syslog.h>
#endif
}

#include <QtCore>
//#include <QtNetwork>
#include <QtXml>
//#include <QtSql>
//#include <QHostInfo>

#include "defines.h"

#include "main.h"
#include <CApplication>
#include "utils.h"


#if defined (Q_OS_LINUX)
extern "C" {
    #include <X11/Xlib.h>
    #include <langinfo.h>
}
#endif

//! global variables;


//! static globals
QString      CApplication::mProcessIdFileName = QString::null;
QString      CApplication::mLogFileName = QString::null;

//! constructor
CApplication::CApplication(int &aArgc, char **apArgv) :
QApplication(aArgc,apArgv) {
#if HAVE_LOCALE
    // ----------------------------------------------------------------------------------------------
    // Устанавливаем локализацию
    ::setlocale(LC_ALL,"");
    ::setlocale(LC_NUMERIC,"POSIX");

    char *vpLang = ::getenv("LANG");
    if(vpLang != 0 && vpLang[0] != '\0') {
        QLocale vLocale(qLatin1(vpLang));
        QLocale::setDefault(vLocale);
    }

    //char *vpLcCtype = ::setlocale(LC_MESSAGES,NULL);
    //if(vpLcCtype!=0 && vpLcCtype[0] != '\0') {
    //    QLocale vLocale(vpLcCtype);
    //    QLocale::setDefault(vLocale);
    //}

    QTextCodec *vpC = 0;

// В Win32 платформе не определена фукция nl_langinfo.
// в win32 для определения языка локали корректно работает 
// QTextCodec::codecForLocale() которая базируется на WinAPI.

#if defined (Q_OS_LINUX)
    char *vpNlCodeset = ::nl_langinfo(CODESET);
    if(vpNlCodeset!=0 && vpNlCodeset[0] != '\0') {
        vpC = QTextCodec::codecForName(vpNlCodeset);
        if(vpC) QTextCodec::setCodecForLocale(vpC);
    }
#elif defined(Q_OS_WIN32)
    const char *vpNlCodeset = "UTF-8";
    vpC = QTextCodec::codecForName(vpNlCodeset);
    if(vpC) QTextCodec::setCodecForLocale(vpC);
#endif

    if(!vpC) {
        vpC = QTextCodec::codecForLocale();
    }

    if(vpC) {
        QTextCodec::setCodecForCStrings(vpC);
        QTextCodec::setCodecForTr(vpC);
    }
#endif // #if HAVE_LOCALE

    // ---------------------------------------------------------------------------------------------
    // Инициализация обработчиков сигналов
#if defined (Q_OS_UNIX)
    watchUnixSignal(SIGINT, true);  // Прерывание с клавиатуры
    watchUnixSignal(SIGILL, true);  // Несуществующая инструкция
    watchUnixSignal(SIGFPE, true);  // Ошибка операций с плавающей запятой
    watchUnixSignal(SIGUSR1,true);  // Первый сигнал, определяемый пользователем
    watchUnixSignal(SIGUSR2,true);  // Второй сигнал, определяемый пользователем
    watchUnixSignal(SIGPIPE,true);  // Оборванный канал: запись в канал, из которого не читают
    watchUnixSignal(SIGALRM,true);  // Сигнал таймера от функции alarm(2)
    watchUnixSignal(SIGQUIT,true);  // Выход с клавиатуры
    watchUnixSignal(SIGTERM,true);  // Сигнал завершения
    watchUnixSignal(SIGABRT,true);  // Сигнал прерывания, посланный функцией abort(3)
    watchUnixSignal(SIGSEGV,true);  // Обращение к запретной области памяти
#endif
    connect(this, SIGNAL(unixSignal(int)),this,SLOT(unixSignalHandler(int)));

    // ----------------------------------------------------------------------------------------------
    //::qInstallMsgHandler(messageHandler);
}

//! destructor
CApplication::~CApplication() {
}

//! method
int CApplication::init() {
    // ----------------------------------------------------------------------------------------------
    QStringList vArguments = arguments();

    // Устанавливаем имя приложения
    QFileInfo vProgramInfo(vArguments.at(0));
    QCoreApplication::setApplicationName(vProgramInfo.baseName());

    int vRetval = 0;

    return vRetval;
}

//! method
void CApplication::unixSignalHandler(int aSigNo) {
    switch(aSigNo) {
        // Завершение выполнения диспетчера

        case SIGABRT:
        case SIGFPE:
        case SIGSEGV:
#if defined(Q_OS_UNIX)
        case SIGQUIT:
        case SIGPIPE:
        case SIGALRM:
#endif
        case SIGILL: {
            exit(aSigNo + 100);
            break;
        }
        case SIGTERM:
        case SIGINT: {
            exit(0);
            break;
        }
#if defined(Q_OS_UNIX)
        // Обновление конфигурации
        case SIGUSR1: {
            break;
        }
#endif
    }
}

#if 0
//! method
void CApplication::messageHandler(QtMsgType aType, const char *apMessage) {
    int vPriority = LOG_INFO;
    QString vMessagePrefix = QString::null;

    switch (aType) {
        case QtDebugMsg: {
            vPriority = LOG_DEBUG;
            vMessagePrefix = tr("Debug:");
            break;
        }
        case QtWarningMsg: {
            vPriority = LOG_INFO;
            vMessagePrefix = tr("Warning:");
            break;
        }
        case QtCriticalMsg: {
            vPriority = LOG_CRIT;
            vMessagePrefix = tr("Critical:");
            break;
        }
        case QtFatalMsg: {
            vPriority = LOG_ERR;
            vMessagePrefix = tr("Fatal:");
            break;
        }
        default: {
            vPriority = LOG_INFO;
            vMessagePrefix = tr("Info:");
        }
    }

    QString vMessage = qLocal8Bit(apMessage);

    QTextStream vStdErr(::stderr);
    vStdErr << qLatin1("! ") << vMessagePrefix + vMessage << qLatin1("\n");
    //::syslog(vPriority,"pid#%d/%s",::getpid(),vMessage.toLocal8Bit().data());
}
#endif
