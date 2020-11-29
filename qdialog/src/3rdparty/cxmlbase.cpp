#include <QtCore>
#include <QtXml>
#include "cxmlbase.h"

bool nodeToVariant(const QDomNode &aNode,QVariant &aValue) {
    bool vRetval = false;
    QString vType, vValue;

    aValue = QVariant();
    if(!vRetval && aNode.isCDATASection()) {
        vValue = aNode.toCDATASection().data();
        vRetval = true;
    }

    if(!vRetval && aNode.isText()) {
        vValue = aNode.toText().data();
        vRetval = true;
    }

    if(!vRetval && aNode.isElement()) {
        vValue = aNode.toElement().text();
        vRetval = true;
    }
    
    if(!vRetval) return vRetval;
    if(vValue.isEmpty()) return false; 

    const QDomNode vParent = aNode.parentNode();
    if(vParent.isElement()) {
        vType = vParent.toElement().attribute(__S2U("type"));
    }

    if(vType == QLatin1String("bytearray")) {
        aValue = QVariant(vValue.toLatin1());
    }
    else if(vType == QLatin1String("variant")) {
        QByteArray vArray(vValue.toLatin1());
        QDataStream vStream(&vArray, QIODevice::ReadOnly);
        vStream >> aValue;
    }
    else if(vType == QLatin1String("rect")) {
        QStringList vArgs = vValue.split(QLatin1Char(' '));
        if(vArgs.size() == 4) {
            aValue = QVariant(QRect(vArgs[0].toInt(), vArgs[1].toInt(), vArgs[2].toInt(), vArgs[3].toInt()));
        }
        else {
            vRetval = false;
        }
    }
    else if(vType == QLatin1String("size")) {
        QStringList vArgs = vValue.split(QLatin1Char(' '));
        if(vArgs.size() == 2) {
            aValue = QVariant(QSize(vArgs[0].toInt(), vArgs[1].toInt()));
        }
        else {
            vRetval = false;
        }
    }
    else if(vType == QLatin1String("point")) {
        QStringList vArgs = vValue.split(QLatin1Char(' '));
        if(vArgs.size() == 2) {
            aValue = QVariant(QPoint(vArgs[0].toInt(), vArgs[1].toInt()));
        }
        else {
            vRetval = false;
        }
    }
    else if(vType == QLatin1String("integer")) {
        aValue = vValue.toInt(&vRetval);
    }
    else if(vType == QLatin1String("bool")) {
        aValue = QVariant(vValue).toBool();
    }
    else if(vType == QLatin1String("double")) {
        aValue =  vValue.toDouble(&vRetval);
    }
    else if(vType == __S2U("invalid")) {
        vRetval = false;
    }
    else {
        aValue = vValue;
    }
    return vRetval;
}

/*
*
*/
bool variantToNode(const QVariant &aValue, QDomElement &aElement) {
    QDomDocument vDocument = aElement.ownerDocument();
    QString vValue, vType;
    QDomNode vValueNode;

    switch (aValue.type()) {
        case QVariant::Invalid: {
            vType  = QLatin1String("invalid");
            vValue = QString::null;
            break;
        }
        case QVariant::ByteArray: {
            QByteArray a = aValue.toByteArray();
            vType  = QLatin1String("bytearray");
            vValue = QString::fromLatin1(a.constData(), a.size());
            break;
        }
        case QVariant::String: {
            vType  = QString::null;
            vValue = aValue.toString();
            break;
        }
        case QVariant::LongLong:
        case QVariant::ULongLong:
        case QVariant::Int:
        case QVariant::UInt: {
            vType  = QLatin1String("integer");
            vValue = aValue.toString();
            break;
        }
        case QVariant::Bool: {
            vType  = QLatin1String("bool");
            vValue = aValue.toString();
            break;
        }
        case QVariant::Double: {
            vType  = QLatin1String("double");
            vValue = aValue.toString();
            break;
        }
        case QVariant::Rect: {
            QRect vRect = qvariant_cast<QRect>(aValue);
            vType   = QLatin1String("rect");
            vValue  = QString::number(vRect.x());
            vValue += QLatin1Char(' ');
            vValue += QString::number(vRect.y());
            vValue += QLatin1Char(' ');
            vValue += QString::number(vRect.width());
            vValue += QLatin1Char(' ');
            vValue += QString::number(vRect.height());
            break;
        }
        case QVariant::Size: {
            QSize vSize = qvariant_cast<QSize>(aValue);
            vType   = QLatin1String("size");
            vValue  = QString::number(vSize.width());
            vValue += QLatin1Char(' ');
            vValue += QString::number(vSize.height());
            break;
        }
        case QVariant::Point: {
            QPoint vPoint = qvariant_cast<QPoint>(aValue);
            vType   = QLatin1String("point");
            vValue  = QString::number(vPoint.x());
            vValue += QLatin1Char(' ');
            vValue += QString::number(vPoint.y());
            break;
        }
        default: {
            QByteArray vArray;
            {
                QDataStream vStream(&vArray, QIODevice::WriteOnly);
                vStream << aValue;
            }

            vType   = QLatin1String("variant");
            vValue += QString::fromLatin1(vArray.constData(), vArray.size());
            break;
        }
    }

    if(!vType.isEmpty()) {
        QDomAttr vTypeAttr = vDocument.createAttribute(__S2U("type"));

        vTypeAttr.setValue(vType);
        aElement.setAttributeNode(vTypeAttr);
    }

    // проверяем возможность добаления текста
    bool vTextOk = false;

    if(!vValue.contains(QLatin1Char('>')) && !vValue.contains(QLatin1Char('<'))) {
        QDomDocument vDocumentTest;
        if(vDocumentTest.setContent(__S2U("<T>%1</T>").arg(vValue))) {
            vTextOk = true;
        }
    }

    if(vTextOk) {
        vValueNode = vDocument.createTextNode(vValue);
    }
    else {
        vValueNode = vDocument.createCDATASection(vValue);
    }

    aElement.appendChild(vValueNode);
    return true;
}
