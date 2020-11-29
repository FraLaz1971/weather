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
#ifdef Q_OS_LINUX
    #include <syslog.h>
#endif
}

#include <QtCore>
#include <QEvent>
//#include <QtNetwork>
#include <QtXml>
//#include <QtSql>
//#include <QHostInfo>

#include "defines.h"

//#include "main.h"
#include "cdialogapp.h"
#include "utils.h"

//! global variables
static QMutex gSettingsMutex(QMutex::Recursive);
QSettings *gpSettings = 0;

//! function
QString toSQLString(const QVariant &aValue) {
    QString vString = aValue.toString();
    vString.replace(qLatin1("'"),qLatin1("''"));
    vString.replace(qLatin1("\\"),qLatin1("\\\\"));
    return qLatin1("'%1'").arg(vString);
}

//! function
QVariant aSettings(const QString &aKey, const QVariant &aDefaultValue) {
    QMutexLocker vMutexLocker(&gSettingsMutex);

    if(gpSettings && gpSettings->status() == QSettings::NoError) {
        return gpSettings->value(aKey, aDefaultValue);
    }
    return aDefaultValue;
}

//! function
bool aSettingsContains(const QString &aKey) {
    QMutexLocker vMutexLocker(&gSettingsMutex);

    if(gpSettings && gpSettings->status() == QSettings::NoError) {
        return gpSettings->contains(aKey);
    }
    return false;
}

//! function
QSettings *aSettings() {
    if(gpSettings && gpSettings->status() == QSettings::NoError) {
        return gpSettings;
    }
    return 0;
}

//! function
QStringList aSettingsKeyList(const QString &aGroupName) {
    QMutexLocker vMutexLocker(&gSettingsMutex);

    QStringList vKeyList;
    if(gpSettings && gpSettings->status() == QSettings::NoError) {
        gpSettings->beginGroup(aGroupName);
        vKeyList = gpSettings->childKeys();
        gpSettings->endGroup();
    }
    return vKeyList;
}

//! function
QString aGetArgument(const QStringList &aArguments, const QString &aShortKey, const QString &aLongKey) {
    //
    QString vArgumentValue = QString::null;

    QStringListIterator vI(aArguments);
    while(vI.hasNext()) {
        QString vArgumentTmp = vI.next();

        if(vArgumentTmp == aShortKey || (!aLongKey.isEmpty() && vArgumentTmp.startsWith(aLongKey))) {
            vArgumentValue = QString::null;

            if(vArgumentTmp == aShortKey) {
                if(vI.hasNext()) {
                    vArgumentValue = vI.next();
                    if(vArgumentValue.isEmpty() || (vArgumentValue.startsWith(QLatin1Char('-')) && vArgumentValue != qLatin1("-"))) {
                        vArgumentValue = QString::null;
                    }
                }
            }
            else if(!aLongKey.isEmpty()) {
                vArgumentValue = vArgumentTmp.mid(aLongKey.length());
                if(!vArgumentValue.isNull() && vArgumentValue.isEmpty()) {
                    vArgumentValue = QString::null;
                }
            }

            if(!vArgumentValue.isEmpty()) {
                break;
            }

            continue;
        }
    }
    return vArgumentValue;
}

//!
QString qEventTypeName(QEvent::Type aType) {
    switch(aType) {
    case QEvent::None:
        return QString::fromLatin1("QEvent::None");
    case QEvent::AccessibilityDescription:
        return QString::fromLatin1("QEvent::AccessibilityDescription");
    case QEvent::AccessibilityHelp:
        return QString::fromLatin1("QEvent::AccessibilityHelp");
    case QEvent::AccessibilityPrepare:
        return QString::fromLatin1("QEvent::AccessibilityPrepare");
    case QEvent::ActionAdded:
        return QString::fromLatin1("QEvent::ActionAdded");
    case QEvent::ActionChanged:
        return QString::fromLatin1("QEvent::ActionChanged");
    case QEvent::ActionRemoved:
        return QString::fromLatin1("QEvent::ActionRemoved");
    case QEvent::ActivationChange:
        return QString::fromLatin1("QEvent::ActivationChange");
#if QT_VERSION >= 0x040300
    case QEvent::ApplicationActivate:
        return QString::fromLatin1("QEvent::ApplicationActivate");
    case QEvent::ApplicationDeactivate:
        return QString::fromLatin1("QEvent::ApplicationDeactivate");
#endif //  QT_VERSION >= 0x040200
    case QEvent::ApplicationFontChange:
        return QString::fromLatin1("QEvent::ApplicationFontChange");
    case QEvent::ApplicationLayoutDirectionChange:
        return QString::fromLatin1("QEvent::ApplicationLayoutDirectionChange");
    case QEvent::ApplicationPaletteChange:
        return QString::fromLatin1("QEvent::ApplicationPaletteChange");
    case QEvent::ApplicationWindowIconChange:
        return QString::fromLatin1("QEvent::ApplicationWindowIconChange");
    case QEvent::ChildAdded:
        return QString::fromLatin1("QEvent::ChildAdded");
    case QEvent::ChildPolished:
        return QString::fromLatin1("QEvent::ChildPolished");
    case QEvent::ChildRemoved:
        return QString::fromLatin1("QEvent::ChildRemoved");
    case QEvent::Clipboard:
        return QString::fromLatin1("QEvent::Clipboard");
    case QEvent::Close:
        return QString::fromLatin1("QEvent::Close");
#if QT_VERSION >= 0x040300
    case QEvent::ContentsRectChange:
        return QString::fromLatin1("QEvent::ContentsRectChange");
#endif // QT_VERSION >= 0x040300
    case QEvent::ContextMenu:
        return QString::fromLatin1("QEvent::ContextMenu");
    case QEvent::DeferredDelete:
        return QString::fromLatin1("QEvent::DeferredDelete");
    case QEvent::DragEnter:
        return QString::fromLatin1("QEvent::DragEnter");
    case QEvent::DragLeave:
        return QString::fromLatin1("QEvent::DragLeave");
    case QEvent::DragMove:
        return QString::fromLatin1("QEvent::DragMove");
    case QEvent::Drop:
        return QString::fromLatin1("QEvent::Drop");
    case QEvent::EnabledChange:
        return QString::fromLatin1("QEvent::EnabledChange");
    case QEvent::Enter:
        return QString::fromLatin1("QEvent::Enter");
    case QEvent::EnterWhatsThisMode:
        return QString::fromLatin1("QEvent::EnterWhatsThisMode");
    case QEvent::FileOpen:
        return QString::fromLatin1("QEvent::FileOpen");
    case QEvent::FocusIn:
        return QString::fromLatin1("QEvent::FocusIn");
    case QEvent::FocusOut:
        return QString::fromLatin1("QEvent::FocusOut");
    case QEvent::FontChange:
        return QString::fromLatin1("QEvent::FontChange");
    case QEvent::GraphicsSceneContextMenu:
        return QString::fromLatin1("QEvent::GraphicsSceneContextMenu");
    case QEvent::GraphicsSceneDragEnter:
        return QString::fromLatin1("QEvent::GraphicsSceneDragEnter");
    case QEvent::GraphicsSceneDragLeave:
        return QString::fromLatin1("QEvent::GraphicsSceneDragLeave");
    case QEvent::GraphicsSceneDragMove:
        return QString::fromLatin1("QEvent::GraphicsSceneDragMove");
    case QEvent::GraphicsSceneDrop:
        return QString::fromLatin1("QEvent::GraphicsSceneDrop");
    case QEvent::GraphicsSceneHelp:
        return QString::fromLatin1("QEvent::GraphicsSceneHelp");
    case QEvent::GraphicsSceneHoverEnter:
        return QString::fromLatin1("QEvent::GraphicsSceneHoverEnter");
    case QEvent::GraphicsSceneHoverLeave:
        return QString::fromLatin1("QEvent::GraphicsSceneHoverLeave");
    case QEvent::GraphicsSceneHoverMove:
        return QString::fromLatin1("QEvent::GraphicsSceneHoverMove");
    case QEvent::GraphicsSceneMouseDoubleClick:
        return QString::fromLatin1("QEvent::GraphicsSceneMouseDoubleClick");
    case QEvent::GraphicsSceneMouseMove:
        return QString::fromLatin1("QEvent::GraphicsSceneMouseMove");
    case QEvent::GraphicsSceneMousePress:
        return QString::fromLatin1("QEvent::GraphicsSceneMousePress");
    case QEvent::GraphicsSceneMouseRelease:
        return QString::fromLatin1("QEvent::GraphicsSceneMouseRelease");
    case QEvent::GraphicsSceneWheel:
        return QString::fromLatin1("QEvent::GraphicsSceneWheel");
    case QEvent::Hide:
        return QString::fromLatin1("QEvent::Hide");
    case QEvent::HideToParent:
        return QString::fromLatin1("QEvent::HideToParent");
    case QEvent::HoverEnter:
        return QString::fromLatin1("QEvent::HoverEnter");
    case QEvent::HoverLeave:
        return QString::fromLatin1("QEvent::HoverLeave");
    case QEvent::HoverMove:
        return QString::fromLatin1("QEvent::HoverMove");
    case QEvent::IconDrag:
        return QString::fromLatin1("QEvent::IconDrag");
    case QEvent::IconTextChange:
        return QString::fromLatin1("QEvent::IconTextChange");
    case QEvent::InputMethod:
        return QString::fromLatin1("QEvent::InputMethod");
    case QEvent::KeyPress:
        return QString::fromLatin1("QEvent::KeyPress");
    case QEvent::KeyRelease:
        return QString::fromLatin1("QEvent::KeyRelease");
    case QEvent::LanguageChange:
        return QString::fromLatin1("QEvent::LanguageChange");
    case QEvent::LayoutDirectionChange:
        return QString::fromLatin1("QEvent::LayoutDirectionChange");
    case QEvent::LayoutRequest:
        return QString::fromLatin1("QEvent::LayoutRequest");
    case QEvent::Leave:
        return QString::fromLatin1("QEvent::Leave");
    case QEvent::LeaveWhatsThisMode:
        return QString::fromLatin1("QEvent::LeaveWhatsThisMode");
    case QEvent::LocaleChange:
        return QString::fromLatin1("QEvent::LocaleChange");
#if QT_VERSION >= 0x040300
    case QEvent::NonClientAreaMouseButtonDblClick:
        return QString::fromLatin1("QEvent::NonClientAreaMouseButtonDblClick");
    case QEvent::NonClientAreaMouseButtonPress:
        return QString::fromLatin1("QEvent::NonClientAreaMouseButtonPress");
    case QEvent::NonClientAreaMouseButtonRelease:
        return QString::fromLatin1("QEvent::NonClientAreaMouseButtonRelease");
    case QEvent::NonClientAreaMouseMove:
        return QString::fromLatin1("QEvent::NonClientAreaMouseMove");
    case QEvent::MacSizeChange:
        return QString::fromLatin1("QEvent::MacSizeChange");
#endif // QT_VERSION >= 0x040300
    case QEvent::MenubarUpdated:
        return QString::fromLatin1("QEvent::MenubarUpdated");
    case QEvent::MetaCall:
        return QString::fromLatin1("QEvent::MetaCall");
    case QEvent::ModifiedChange:
        return QString::fromLatin1("QEvent::ModifiedChange");
    case QEvent::MouseButtonDblClick:
        return QString::fromLatin1("QEvent::MouseButtonDblClick");
    case QEvent::MouseButtonPress:
        return QString::fromLatin1("QEvent::MouseButtonPress");
    case QEvent::MouseButtonRelease:
        return QString::fromLatin1("QEvent::MouseButtonRelease");
    case QEvent::MouseMove:
        return QString::fromLatin1("QEvent::MouseMove");
    case QEvent::MouseTrackingChange:
        return QString::fromLatin1("QEvent::MouseTrackingChange");
    case QEvent::Move:
        return QString::fromLatin1("QEvent::Move");
    case QEvent::Paint:
        return QString::fromLatin1("QEvent::Paint");
    case QEvent::PaletteChange:
        return QString::fromLatin1("QEvent::PaletteChange");
    case QEvent::ParentAboutToChange:
        return QString::fromLatin1("QEvent::ParentAboutToChange");
    case QEvent::ParentChange:
        return QString::fromLatin1("QEvent::ParentChange");
    case QEvent::Polish:
        return QString::fromLatin1("QEvent::Polish");
    case QEvent::PolishRequest:
        return QString::fromLatin1("QEvent::PolishRequest");
    case QEvent::QueryWhatsThis:
        return QString::fromLatin1("QEvent::QueryWhatsThis");
    case QEvent::Resize:
        return QString::fromLatin1("QEvent::Resize");
    case QEvent::Shortcut:
        return QString::fromLatin1("QEvent::Shortcut");
    case QEvent::ShortcutOverride:
        return QString::fromLatin1("QEvent::ShortcutOverride");
    case QEvent::Show:
        return QString::fromLatin1("QEvent::Show");
    case QEvent::ShowToParent:
        return QString::fromLatin1("QEvent::ShowToParent");
    case QEvent::SockAct:
        return QString::fromLatin1("QEvent::SockAct");
    case QEvent::StatusTip:
        return QString::fromLatin1("QEvent::StatusTip");
    case QEvent::StyleChange:
        return QString::fromLatin1("QEvent::StyleChange");
    case QEvent::TabletMove:
        return QString::fromLatin1("QEvent::TabletMove");
    case QEvent::TabletPress:
        return QString::fromLatin1("QEvent::TabletPress");
    case QEvent::TabletRelease:
        return QString::fromLatin1("QEvent::TabletRelease");
    case QEvent::TabletEnterProximity:
        return QString::fromLatin1("QEvent::TabletEnterProximity");
    case QEvent::TabletLeaveProximity:
        return QString::fromLatin1("QEvent::TabletLeaveProximity");
    case QEvent::Timer:
        return QString::fromLatin1("QEvent::Timer");
    case QEvent::ToolBarChange:
        return QString::fromLatin1("QEvent::ToolBarChange");
    case QEvent::ToolTip:
        return QString::fromLatin1("QEvent::ToolTip");
    case QEvent::UpdateLater:
        return QString::fromLatin1("QEvent::UpdateLater");
    case QEvent::UpdateRequest:
        return QString::fromLatin1("QEvent::UpdateRequest");
    case QEvent::WhatsThis:
        return QString::fromLatin1("QEvent::WhatsThis");
    case QEvent::WhatsThisClicked:
        return QString::fromLatin1("QEvent::WhatsThisClicked");
    case QEvent::Wheel:
        return QString::fromLatin1("QEvent::Wheel");
    case QEvent::WinEventAct:
        return QString::fromLatin1("QEvent::WinEventAct");
    case QEvent::WindowActivate:
        return QString::fromLatin1("QEvent::WindowActivate");
    case QEvent::WindowBlocked:
        return QString::fromLatin1("QEvent::WindowBlocked");
    case QEvent::WindowDeactivate:
        return QString::fromLatin1("QEvent::WindowDeactivate");
    case QEvent::WindowIconChange:
        return QString::fromLatin1("QEvent::WindowIconChange");
    case QEvent::WindowStateChange:
        return QString::fromLatin1("QEvent::WindowStateChange");
    case QEvent::WindowTitleChange:
        return QString::fromLatin1("QEvent::WindowTitleChange");
    case QEvent::WindowUnblocked:
        return QString::fromLatin1("QEvent::WindowUnblocked");
    case QEvent::ZOrderChange:
        return QString::fromLatin1("QEvent::ZOrderChange");
    case QEvent::KeyboardLayoutChange:
        return QString::fromLatin1("QEvent::KeyboardLayoutChange");
    case QEvent::DynamicPropertyChange:
        return QString::fromLatin1("QEvent::DynamicPropertyChange");
    default:
        break;
    }
    return QString::null;
}
