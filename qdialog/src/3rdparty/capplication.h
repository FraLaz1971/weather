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
 ** AUTHOR: Sergey A. Sukiyazov <sukiyazov@mail.ru>
 **
 ****************************************************************************/
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <QtCore>
#include <QtGui>
#include <QtXml>

//! moc-file can't be compiled
#include "defines.h"

//! forward declaration

//! class
class CApplication : public QApplication {
Q_OBJECT

public:
    CApplication(int &, char **);
    ~CApplication();

    virtual int init();

public Q_SLOTS:
    void unixSignalHandler(int aSigNo);

private:
    //static void messageHandler(QtMsgType aType, const char *apMessage);

    static QString      mProcessIdFileName;
    static QString      mLogFileName;
};

//! function
#ifndef LC_return
#if HAVE_LOCALE
#include <locale.h>

// This macro check locale to be set (LC_CTYPE category only) before executing
// QTextCodec related function or method. Otherwise (if locale is not set) return
// value of methods like QTextCodec::fromLocal8Bit(...) and QString::toLocal8Bit()
// equivalent execution QTextCodec::fromLatin1(...) and QString::toLatin1() accordingly.
// If we determine that locale is not set, we try set locale category LC_CTYPE before
// QTextCodec related function or method will be executed.
#define LC_return(x) \
    register char *vpLocale = ::setlocale(LC_CTYPE,0); \
    if(::qstrncmp(vpLocale,"C",1)==0 || ::qstrncmp(vpLocale,"POSIX",5)==0) { \
        ::setlocale(LC_CTYPE,""); \
    } \
    return (x);
#else
#define LC_return(x) \
    return (x);
#endif // HAVE_LOCALE
#endif // !ifndef LC_return

inline QString    __S2U(const char *apStr)   { LC_return(QString::fromLocal8Bit(apStr));        }
inline QByteArray __U2S(const QString &aStr) { LC_return(aStr.toLocal8Bit());                   }
inline QChar      __C2U(const char aCh)      { LC_return(QString::fromLocal8Bit(&aCh,1).at(0)); }
inline QChar      __C2U(const char *apCh)    { LC_return(QString::fromLocal8Bit(apCh).at(0));   }
inline char       __U2C(const QChar &aCh)    { LC_return(QString(aCh).toLocal8Bit().at(0));     }


#ifndef SOURCE_CODING_FUNCTION
#define SOURCE_CODING_FUNCTION
//#warning "!!! function QString _(const char *) defined in application.h

#ifndef SOURCE_CODING
#define SOURCE_CODING "UTF-8"
#endif

//! function
inline QString _(const char *apStr) {
    QTextCodec *vpCodec = 0;
#ifdef SOURCE_CODING
    vpCodec = QTextCodec::codecForName(SOURCE_CODING);
#else
#ifdef __APPLICATION_H__
    CApplication::setupLocale();
#endif // __APPLICATION_H__
    vpCodec = QTextCodec::codecForLocale();
#endif
    if(!vpCodec) vpCodec = QTextCodec::codecForMib(4); // 4 -> ISO-8859-1, 106 - UTF-8
    if(vpCodec) return vpCodec->toUnicode(apStr);
    return QString(apStr);
}
#endif // SOURCE_CODING_FUNCTION

#endif // __APPLICATION_H__
