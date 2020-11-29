/**/
#include <QtCore>
#include <QtXml>
#include "cxmlsettings.h"

bool readXmlFile(QIODevice &aDevice, QSettings::SettingsMap &aMap);
bool writeXmlFile(QIODevice &aDevice, const QSettings::SettingsMap &aMap);
/*
*
*/
static bool readXmlFileElement(const QString &aPath, const QDomElement &aElement, QSettings::SettingsMap &map) {
    bool vRetval = true;
    QDomNodeList vTmpList0 = aElement.childNodes();
    for(int i=0; i < vTmpList0.count(); i++) {
        QDomNode vTmpNode = vTmpList0.at(i);

        if((vTmpNode.isCDATASection() || vTmpNode.isText()) && vTmpNode.childNodes().count()==0) {
            QVariant vValue;

            if(nodeToVariant(vTmpNode,vValue)) {
                map.insert(aPath,vValue);
                return vRetval;
            }
        }

        if(vTmpNode.isElement()) {
            QDomElement vTmpElement = vTmpNode.toElement();
            QString vPath = vTmpElement.tagName();

            if(!aPath.isEmpty()) {
              //qDebug() << "aPath:" << aPath << " : " << "vPath:" << vPath;
              if (vPath.startsWith(__S2U("item"))) {
                if (aPath.section('/', -1).compare(__S2U("array"))==0) {
                  vPath = vPath.replace(__S2U("item"),__S2U(""));
                }
              }
              vPath = __S2U("%1/%2").arg(aPath).arg(vPath);
            } 
            vRetval = readXmlFileElement(vPath,vTmpElement,map);
        }
    }
    return vRetval;
}

/*
*
*/
bool readXmlFile(QIODevice &aDevice, QSettings::SettingsMap &aMap) {
    QString vErrorMsg;
    QDomDocument vDocument;
    int vErrorLine = 0, vErrorColumn = 0;

    if(!vDocument.setContent(&aDevice,&vErrorMsg,&vErrorLine,&vErrorColumn)) {
      qDebug("Cant read config: %s at line %d column %d", __U2S(vErrorMsg).toLocal8Bit().data(),vErrorLine,vErrorColumn);
      return false;
    }

    QDomElement vRoot = vDocument.documentElement();
    if(vRoot.tagName() != __S2U("config")) return false;

    return readXmlFileElement(QString::null,vRoot,aMap);
//    bool vRetval = readXmlFileElement(QString::null,vRoot,map);
//    return vRetval;
}

/*
*
*/
bool writeXmlFile(QIODevice &aDevice, const QSettings::SettingsMap &aMap) {
    QDomDocument vDocument;
    qWarning("\n\nwriteXmlFile\n\n");
    QTextCodec *vpCodecForLocale = QTextCodec::codecForLocale();
    if(!vpCodecForLocale) {
        vpCodecForLocale = QTextCodec::codecForMib(106); // UTF-8
    }

    QString vInstructData = __S2U("version=\"1.0\" encoding=\"%1\"").arg(__S2U(vpCodecForLocale->name()));
    QDomProcessingInstruction vInstruct = vDocument.createProcessingInstruction(__S2U("xml"),vInstructData);
    vDocument.appendChild(vInstruct);

    QDomElement vRoot = vDocument.createElement(__S2U("config"));
    vDocument.appendChild(vRoot);

    QMap<QString,QVariant>::const_iterator vIter = aMap.begin();
    for (; vIter != aMap.end(); ++vIter) {
        QString vKey = vIter.key();
        QVariant vValue = vIter.value();

        // Ключ пустой 
        if(vKey.isEmpty()) continue;

        QStringList vPath = vKey.split(QLatin1Char('/'));
        //QString vLastKey = vPath.takeLast();

        // Находим елемент соответсвующий пути ключа
        QStringListIterator i(vPath);
        QDomElement vElement = vRoot;
        while (i.hasNext()) {
            QString vTagName = i.next();

            if (vTagName[0].isDigit())  // это элемент массива
                vTagName.prepend(__S2U("item"));

            QDomElement vTmp = vElement.firstChildElement(vTagName);

            if(vTmp.isNull()) {
                vTmp = vDocument.createElement(vTagName);
                vElement.appendChild(vTmp);
            }

            vElement = vTmp;
            vElement.removeAttribute(__S2U("type"));

            QDomNodeList vTmpList = vElement.childNodes();
            for(int i=0; i < vTmpList.count(); i++) {
                if(vTmpList.item(i).nodeType() != QDomNode::ElementNode) {
                    vElement.removeChild(vTmpList.item(i));
                }
            }
        }


        vElement.removeAttribute(__S2U("type"));

        QDomNodeList vTmpList = vElement.childNodes();
        for(int i=0; i < vTmpList.count(); i++) {
            if(vTmpList.item(i).nodeType() != QDomNode::ElementNode) {
                vElement.removeChild(vTmpList.item(i));
            }
        }
        variantToNode(vValue, vElement);
    }
 
    QByteArray vRawXml = vpCodecForLocale->fromUnicode(vDocument.toString(4));
    if(aDevice.write(vRawXml)==vRawXml.size()) {
         return true;
    }
    return false;
}
