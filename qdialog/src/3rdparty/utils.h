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
#ifndef __UTILS_H__
#define __UTILS_H__

#include <QtCore>
#include <QtGui>

QString toSQLString(const QVariant &aValue);

//! functions
QVariant aSettings(const QString &aKey, const QVariant &aDefaultValue = QVariant());
bool aSettingsContains(const QString &aKey);
QSettings *aSettings();
QStringList aSettingsKeyList(const QString &aGroupName);

//! function
inline QVariant aSettings(const char *apKey, const QVariant &aDefaultValue = QVariant()) {
    return aSettings(qLocal8Bit(apKey), aDefaultValue);
}

//! function
inline bool aSettingsContains(const char *apKey) {
    return aSettingsContains(qLocal8Bit(apKey));
}

//! function
inline QStringList aSettingsKeyList(const char *apGroupName) {
    return aSettingsKeyList(qLocal8Bit(apGroupName));
}

QString aGetArgument(const QStringList &aArguments, const QString &aShortKey, const QString &aLongKey = QString::null);
QString qEventTypeName(QEvent::Type aType);

#endif // __UTILS_H__
