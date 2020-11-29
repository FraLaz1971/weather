/****************************************************************************
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
 **
 ****************************************************************************/
#include "cdialogapp.h"
#include "cgaugebox.h"
#include "fileutils.h"
#include <unistd.h>
#include <QtTest/QTest>
#ifdef Q_OS_WIN32
#include <windows.h>
#endif

#include "defines.h"

const int TIME_DELTA    = 50;

CGaugeBox::CGaugeBox( QWidget *parent ) :
CMsgBox( parent )
{
    mpLayoutMain->insertWidget(1, &mProgressBar, 1, Qt::AlignTop);
    mMinimumSize.setWidth(150);

    startInputThread();
}

CGaugeBox::~CGaugeBox()
{
    if(mpInputThread->isRunning())
    {
        mpInputThread->wantToStop();
        mpInputThread->quit();
        mpInputThread->wait();
    }
}

void CGaugeBox::adjustSize()
{
    mProgressBar.adjustSize();

    CMsgBox::adjustSize();

    QSize vGaugeSize( mProgressBar.size() );

    QSize vSize( size() );

    vSize.setHeight( vSize.height() + vGaugeSize.height() + style()->pixelMetric(QStyle::PM_LayoutVerticalSpacing));

    resize( vSize );

    setMinimumSize( size() );
}

void CGaugeBox::setPercent(const int aValue)
{
    mProgressBar.setValue(aValue);
    //mProgressBar.update();
}

int CGaugeBox::getPercent() const
{
    return mProgressBar.value();
}

void CGaugeBox::startInputThread(int aInputFD)
{
    if(aInputFD == -1)
    {
        aInputFD = STDIN_FILENO;
    }

    mpInputThread = new CGaugeBoxThread(this, aInputFD);

    mpInputThread->start();
}


void CGaugeBox::newPercent(int aPercent)
{
    setPercent(aPercent);
}

void CGaugeBox::newText(const QString& aText)
{
    setText(aText);    
}

// CGaugeBoxThread
CGaugeBoxThread::CGaugeBoxThread( CGaugeBox* apGauge, int aInputFD):
        mpGauge(apGauge),
        mInputFD(aInputFD)
{
    mWantStop = false;

    connect(this, SIGNAL(textChanged(QString)), apGauge, SLOT(newText(QString)));
    connect(this, SIGNAL(percentChanged(int)),  apGauge, SLOT(newPercent(int)));
    connect(this, SIGNAL(finished()), apGauge, SLOT(close()));
}

bool CGaugeBoxThread::isWantToStop()
{
    bool vResult = false;

    try
    {
//        mWantStopMutex.lock();
        vResult = mWantStop;
    }
    catch(...)
    {
//        mWantStopMutex.unlock();
    }

    return vResult;
}

void CGaugeBoxThread::wantToStop()
{
    try
    {
//        mWantStopMutex.lock();
        mWantStop = true;
    }
    catch(...)
    {
//        mWantStopMutex.unlock();
    }
}

void CGaugeBoxThread::run()
{
    //QTest::qSleep(40*1000);

    bool vDataAvail = false;
    do
    {
        vDataAvail = waitForData(mInputFD, TIME_DELTA);
        if(isWantToStop())
            return;
    }
    while(!vDataAvail);

    if(vDataAvail)
    {
        QFile* vpFile = new QFile();
        if(vpFile != NULL)
        {
            if(vpFile->open(mInputFD, QIODevice::ReadOnly))
            {
                do
                {
                    QString vStr = vpFile->readLine();

                    if(vStr.isEmpty())
                        break;

                    bool vOk = false;
                    int vPercent = vStr.trimmed().toLong(&vOk);
                    if(vOk)
                    {
                        emit percentChanged(vPercent);
                    }
                    else if (vStr.trimmed().compare("XXX") == 0) // MARKER
                    {
                        /*
                        * Historically, next line should be percentage, but one of the
                        * worse-written clones of 'dialog' assumes the number is missing.
                        * (Gresham's Law applied to software).
                        */

                        QString vStr = vpFile->readLine();

                        if(vStr.isEmpty())
                            break;

                        vPercent = vStr.trimmed().toLong(&vOk);
                        if(vOk)
                        {
                            emit percentChanged(vPercent);
                        }
                        vStr = "";
                    }
                    else
                    {
                        vStr = vpFile->readLine();

                        if(vStr.isEmpty())
                            break;
                    }

                    /* Rest is message text */

                    bool vReadMessageFinished = false;
                    QString vMessageText;
                    //vMessageText.clear();
                    while(true)
                    {
                        vMessageText.append(vStr);
                        vStr = vpFile->readLine();

                        if(vStr.isEmpty())
                            break;

                        if (vStr.trimmed().compare("XXX") == 0) // MARKER
                        {
                            vReadMessageFinished = true;
                            break;
                        }
                    }

                    if(!vReadMessageFinished)
                    {
                        // this mean end of file  reached or thread stopping
                        break;
                    }


                    emit textChanged(vMessageText);

                }
                while(!isWantToStop());//!vpFile->atEnd());

                vpFile->close();
            }

            delete vpFile;
            vpFile = NULL;
        }

    }
}

