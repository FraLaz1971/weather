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
#ifndef __CGAUGEBOX_H__
#define __CGAUGEBOX_H__

#include <CMsgBox>
#include <QProgressBar>
#include <QThread>

class CGaugeBoxThread;

class CGaugeBox : public CMsgBox
{
Q_OBJECT
public:
    CGaugeBox( QWidget* parent=0 );
    ~CGaugeBox();

public:
    void            setPercent(const int aValue);
    int             getPercent() const;
    void            startInputThread(int aInputFD = -1);
    virtual void    adjustSize();

protected slots:
    void            newPercent(int aPercent);
    void            newText(const QString& aText);

protected:
    QProgressBar    mProgressBar;
    bool            mWantToStop;
    bool            mRunning;
    CGaugeBoxThread* mpInputThread;
};

class CGaugeBoxThread : public QThread
{
Q_OBJECT
public:
    CGaugeBoxThread( CGaugeBox* apGauge, int aInputFD);
    void        wantToStop();
    bool        isWantToStop();

protected:
    virtual void    run();

signals:
    void        percentChanged(int aPercent);
    void        textChanged(const QString& aText);

protected:
    QMutex          mWantStopMutex;
    bool            mWantStop;
    CGaugeBox*      mpGauge;
    unsigned long   mInputFD;
};


#endif // __CGAUGEBOX_H__
