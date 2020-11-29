/****************************************************************************
** $Id: defines.h,v 1.4 2007/03/09 10:20:48 sukiyazov_sa Exp $
**
** Definition of const char * to QString (and backward) convertion helper
** functions and macros
**
** Created : 950419
**
** Copyright (C) 206-2007 Sergey A. Sukiyazov.  All rights reserved.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** Contact sukiyazov@mail.ru if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <locale.h>

#ifndef SOURCE_CODING
#define SOURCE_CODING "UTF-8"
#endif

// This macro check locale to be set (LC_CTYPE category only) before executing
// QTextCodec related function or method. Otherwise (if locale is not set) return
// value of methods like QTextCodec::fromLocal8Bit(...) and QString::toLocal8Bit()
// equivalent execution QTextCodec::fromLatin1(...) and QString::toLatin1() accordingly.
// If we determine that locale is not set, we try set locale category LC_CTYPE before
// QTextCodec related function or method will be executed.
#ifndef LC_return
#define LC_return(x) \
    register char *vpLocale = ::setlocale(LC_CTYPE,0); \
    if(::qstrncmp(vpLocale,"C",1)==0 || ::qstrncmp(vpLocale,"POSIX",5)==0) { \
        ::setlocale(LC_CTYPE,""); \
    } \
    return (x);
#endif // !ifndef LC_return

// This macro check locale to be set (LC_CTYPE category only) before executing
// QTextCodec::codecForLocale() and return found codec. Otherwise (if locale is not set)
// QTextCodec::codecForLocale() returns pointer to codec equivalent "ISO-8819-1" charset.
// If we determine that locale is not set, we try set locale category LC_CTYPE before
// QTextCodec::codecForLocale() will be executed.
#define LC_setLocaleCodec(x) \
    register char *vpLocale = ::setlocale(LC_CTYPE,0); \
    if(::qstrncmp(vpLocale,"C",1)==0 || ::qstrncmp(vpLocale,"POSIX",5)==0) { \
        ::setlocale(LC_CTYPE,""); \
    } \
    (x) = QTextCodec::codecForLocale();

// This macro check for source code encoding to be set. С/С++ have not internal tools for
// determine source code encoding we need define special macro at begining of source file.
// We use for determination source code encoding two macros:
//    SOURCE_CODING_UTF8 - say that source in UTF-8 encoding
//    SOURCE_CODING - if SOURCE_CODING_UTF8 is not set, contains name of source code encoding
// This macro returns pointer to codec which be used for translation (char *) constants to correct
// QString values, independent of locale which pogram be run.
#if SOURCE_CODING_UTF8
#define LC_setSourceCodec(x) \
    (x) = QTextCodec::codecForMib(106);
#else // SOURCE_CODING_UTF8
#ifdef SOURCE_CODING
#define LC_setSourceCodec(x) \
    (x) = QTextCodec::codecForName(SOURCE_CODING);
#else // SOURCE_CODING
#define LC_setSourceCodec(x) \
    register char *vpLocale = ::setlocale(LC_CTYPE,0); \
    if(::qstrncmp(vpLocale,"C",1)==0 || ::qstrncmp(vpLocale,"POSIX",5)==0) { \
        ::setlocale(LC_CTYPE,""); \
    } \
    (x) = QTextCodec::codecForLocale();
#endif // SOURCE_CODING
#endif // SOURCE_CODING_UTF8

//! function
// Like LC_return(x) macro, but only check for locale is set (LC_CTYPE category only) and try
// set it.  
inline void checkLcCtype() {
    // Check for locale is not set.
    register char *vpLocale = ::setlocale(LC_CTYPE,0);
    if(qstrncmp(vpLocale,"C",1)==0 || qstrncmp(vpLocale,"POSIX",5)==0) {
        ::setlocale(LC_CTYPE,"");
    }
}

//! function
// Equivalent LC_setLocaleCodec(x)
inline QTextCodec *defaultLocaleCodec() {
    checkLcCtype();
    return QTextCodec::codecForLocale();
}

//! function
// Equivalent LC_setSourceCodec(x)
inline QTextCodec *defaultSourceCodec() {
#if SOURCE_CODING_UTF8
    return QTextCodec::codecForMib(106); // 4 -> ISO-8859-1, 106 - UTF-8
#else // SOURCE_CODING_UTF8
#ifdef SOURCE_CODING
    return QTextCodec::codecForName(SOURCE_CODING);
#else // SOURCE_CODING
    return defaultLocaleCodec();
#endif // SOURCE_CODING
#endif // SOURCE_CODING_UTF8
}

#ifndef SOURCE_CODING_FUNCTION
#define SOURCE_CODING_FUNCTION

// #ifndef BUILD_PLUGIN
// #warning "!!! function QString _(const char *) defined in defines.h
// #endif

//! function
// This function must be used for initialization QString values from char * values.
// This function used translation based on SOURCE_CODING_* macros.
// Sample:
//      QString vQStr = _("C-like sting value (probably in native language)");
inline QString _(const char *apStr) {
    QTextCodec *vpCodec;

    LC_setSourceCodec(vpCodec);
    if(vpCodec) return vpCodec->toUnicode(apStr);
    return QString::fromLatin1(apStr);
}
#endif // SOURCE_CODING_FUNCTION

//! function
// Equivalent QString _(const char *a);
inline QString $(const char *apString) {
#if SOURCE_CODING_UTF8
    return QString::fromUtf8(apString);
#else // SOURCE_CODING_UTF8
    QTextCodec *vpCodec;

    LC_setSourceCodec(vpCodec);
    if(vpCodec) return vpCodec->toUnicode(apString);
    return QString::fromLatin1(apString);
#endif // SOURCE_CODING_UTF8
}

//! function
inline QByteArray $(const QString &aString) {
#if SOURCE_CODING_UTF8
    return aString.toUtf8();
#else // SOURCE_CODING_UTF8
    QTextCodec *vpCodec;

    LC_setSourceCodec(vpCodec);
    if(vpCodec) return vpCodec->fromUnicode(aString);
    return aString.toLatin1();
#endif // SOURCE_CODING_UTF8
}

inline QString qLatin1(const char *aCStr)          { return QString::fromLatin1(aCStr);               }
inline QString qLatin1(const QByteArray &aBArr)    { return QString::fromLatin1(aBArr);               }
inline QByteArray qLatin1(const QString &aStr)     { return aStr.toLatin1();                          }
inline QChar qLatin1(char aCh)                     { return QString::fromLatin1(&aCh,1).at(0);        }
inline char qLatin1(const QChar &aCh)              { return QString(aCh).toLatin1().at(0);            }

inline QString qLocal8Bit(const char *aCStr)       { LC_return(QString::fromLocal8Bit(aCStr));        }
inline QString qLocal8Bit(const QByteArray &aBArr) { LC_return(QString::fromLocal8Bit(aBArr));        }
inline QByteArray qLocal8Bit(const QString &aStr)  { LC_return(aStr.toLocal8Bit());                   }
inline QChar qLocal8Bit(char aCh)                  { LC_return(QString::fromLocal8Bit(&aCh,1).at(0)); }
inline char qLocal8Bit(const QChar &aCh)           { LC_return(QString(aCh).toLocal8Bit().at(0));     }

inline QString qUtf8(const char *aCStr)            { return QString::fromUtf8(aCStr);                 }
inline QString qUtf8(const QByteArray &aBArr)      { return QString::fromUtf8(aBArr);                 }
inline QByteArray qUtf8(const QString &aStr)       { return aStr.toUtf8();                            }

//! function
inline QString $S(const char *apEncoding, const char *apString) {
    QTextCodec *vpCodec = 0;

    if(apEncoding && *apEncoding != '\0') vpCodec = QTextCodec::codecForName(apEncoding);
    if(!vpCodec) {
        LC_setLocaleCodec(vpCodec);
    }

    if(vpCodec) return vpCodec->toUnicode(apString);
    return QString::fromLatin1(apString);
}

//! function
inline QString $S(const char *apString) {
#if SOURCE_CODING_UTF8
    return QString::fromUtf8(apString);
#else // SOURCE_CODING_UTF8
    QTextCodec *vpCodec;

    LC_setSourceCodec(vpCodec);
    if(vpCodec) return vpCodec->toUnicode(apString);
    return QString::fromLatin1(apString);
#endif // SOURCE_CODING_UTF8
}

//! function
inline QByteArray $S(const char *apEncoding, const QString &aString) {
    QTextCodec *vpCodec = 0;

    if(apEncoding && *apEncoding != '\0') vpCodec = QTextCodec::codecForName(apEncoding);
    if(!vpCodec) {
        LC_setLocaleCodec(vpCodec);
    }

    if(vpCodec) return vpCodec->fromUnicode(aString);
    return aString.toLatin1();
}

//! function
inline QByteArray $S(const QString &aString) {
#if SOURCE_CODING_UTF8
    return aString.toUtf8();
#else // SOURCE_CODING_UTF8
    QTextCodec *vpCodec;

    LC_setSourceCodec(vpCodec);
    if(vpCodec) return vpCodec->fromUnicode(aString);
    return aString.toLatin1();
#endif // SOURCE_CODING_UTF8
}

//! function
inline QChar $C(const char *apEncoding, const char *apString) {
    QTextCodec *vpCodec = 0;

    if(apEncoding && *apEncoding != '\0') vpCodec = QTextCodec::codecForName(apEncoding);
    if(!vpCodec) {
        LC_setLocaleCodec(vpCodec);
    }

    if(vpCodec) return vpCodec->toUnicode(apString,6).at(0);
    return QString::fromLatin1(apString,6).at(0);
}

//! function
inline QChar $C(const char *apString) {
#if SOURCE_CODING_UTF8
    return QString::fromUtf8(apString,6).at(0);
#else // SOURCE_CODING_UTF8
    QTextCodec *vpCodec;

    LC_setSourceCodec(vpCodec);
    if(vpCodec) return vpCodec->toUnicode(apString,6).at(0);
    return QString::fromLatin1(apString,6).at(0);
#endif // SOURCE_CODING_UTF8
}

//! function
inline QByteArray $C(const char *apEncoding, const QChar &aChar) {
    QTextCodec *vpCodec = 0;

    if(apEncoding && *apEncoding != '\0') vpCodec = QTextCodec::codecForName(apEncoding);
    if(!vpCodec) {
        LC_setLocaleCodec(vpCodec);
    }

    if(vpCodec) return vpCodec->fromUnicode(&aChar,1);
    return QString(aChar).toLatin1();
}

//! function
inline QByteArray $C(const QChar &aChar) {
#if SOURCE_CODING_UTF8
    return QString(aChar).toUtf8();
#else // SOURCE_CODING_UTF8
    QTextCodec *vpCodec;

    LC_setSourceCodec(vpCodec);
    if(vpCodec) return vpCodec->fromUnicode(&aChar,1);
    return QString(aChar).toLatin1();
#endif // SOURCE_CODING_UTF8
}

//! function
inline QString tr(const char *apSourceText, const char *apComment = 0, int aN = -1)  {
#if QT_VERSION >= 0x040200
    return QObject::tr(apSourceText,apComment,aN);
#else
    return QObject::tr(apSourceText,apComment);
#endif
}

/*
//! function
inline void qWarning(const QString &aMessage) {
    qWarning(qPrintable(aMessage));
}

//! function
inline void qDebug(const QString &aMessage) {
    qDebug(qPrintable(aMessage));
}

//! function
inline void qFatal(const QString &aMessage) {
    qFatal(qPrintable(aMessage));
}

//! function
inline void qCritical(const QString &aMessage) {
    qCritical(qPrintable(aMessage));
}
*/

// macro for onaming members
#ifdef METHOD1
#undef METHOD1
#endif
#ifdef SLOT1
#undef SLOT1
#endif
#ifdef SIGNAL1
#undef SIGNAL1
#endif

#define METHOD1(a)        "0"a
#define SLOT1(a)          "1"a
#define SIGNAL1(a)        "2"a

#endif // __DEFINES_H__
