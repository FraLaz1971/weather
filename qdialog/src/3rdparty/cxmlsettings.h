#ifndef __QXMLSETTINGS_H__
#define __QXMLSETTINGS_H__

#include <QtCore>
#include <QtXml>
#include "cxmlbase.h"

bool readXmlFile(QIODevice &aDevice, QSettings::SettingsMap &aMap);
bool writeXmlFile(QIODevice &aDevice, const QSettings::SettingsMap &aMap);

#endif // __QXMLSETTINGS_H__
