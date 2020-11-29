//! -*- coding: UTF-8 -*-
#define SOURCE_CODING "UTF-8"

#include "config.h"

#include <QtCore>

#include "defines.h"

#include "strutils.h"


QString getWordAt(const QString& aString, int aIndex)
{
    QString vResult;

    vResult = aString.right(aString.count()-aIndex);
    for(int i = 0; i < vResult.count() - 1; i++)
    {
        QChar c = vResult.at(i);
        if(c.isSpace())
        {
            vResult = vResult.left(i);
            break;
        }
    }

    return vResult.trimmed();
}

QString getQuotedStringAt(const QString& aString, int aIndex, QChar aDelimiter)
{
    QString vResult;

    if(aString[aIndex] == aDelimiter)
    {
        vResult = aString.right(aString.count()-aIndex-1);
        int vEnd = vResult.indexOf(aDelimiter);
        if(vEnd == 0)
            vResult = "";
        else
            vResult = vResult.left(vEnd);
    }

    return vResult;
}

//! function
QStringList readArgsFromString(const QString& aString)
{
    QStringList vResult;

    for(int i = 0; i < aString.count()-1; i++)
    {
        QChar vCurrent = aString.at(i);

        if(!vCurrent.isSpace())
        {
            if(vCurrent == '\"')
            {
                QString vTemp = getQuotedStringAt(aString, i, '\"');
                vResult.append(vTemp);
                i += vTemp.count() + 1;
            }
            else if(vCurrent == '\'')
            {
                QString vTemp = getQuotedStringAt(aString, i, '\'');
                vResult.append(vTemp);
                i += vTemp.count() + 1;
            }
            else
            {
                QString vTemp = getWordAt(aString, i);
                vResult.append(vTemp);
                i += vTemp.count();
            }
        }
    }

    return vResult;
}
