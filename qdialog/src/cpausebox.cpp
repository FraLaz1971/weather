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
#include "cpausebox.h"

#include "defines.h"

#include <QTimer>

CPauseBox::CPauseBox( QWidget *parent ) :
CGaugeBox( parent )
{
    mTimer.setInterval(1000); // 1 sec
    mProgressBar.setFormat("%v sec");
}

void CPauseBox::setPauseSeconds(const int aValue)
{
    mTimer.stop();

    mProgressBar.setMinimum(0);
    mProgressBar.setMaximum(aValue);
    mProgressBar.setValue(aValue);

    connect(&mTimer, SIGNAL(timeout()), this, SLOT(updateGauge()));
    mTimer.start();
}

void CPauseBox::updateGauge()
{
    if(mProgressBar.value() == 0)
    {
        done(IDRET_OK);
    }
    else
    {
        mProgressBar.setValue(mProgressBar.value() - 1);
    }
}
