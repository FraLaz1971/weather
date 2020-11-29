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

#include <QtCore>

#include "fileutils.h"

#ifdef Q_OS_WIN32
#include <windows.h>
#endif

#include "defines.h"

bool waitForData(int aInputFD, int aDelay)
{
#ifdef Q_OS_WIN32
    ///TODO: mix of win32 handles and os handles. not good
    if( STDIN_FILENO == aInputFD)
        aInputFD = (int)GetStdHandle(STD_INPUT_HANDLE);

    UINT hRet = WaitForSingleObject((HANDLE)aInputFD, aDelay);

    if (hRet == WAIT_OBJECT_0)
        return true;

    return false;
#else
    fd_set rfds;
    struct timeval tv;

    FD_ZERO(&rfds);
    FD_SET(aInputFD, &rfds);

    tv.tv_sec = 0;
    tv.tv_usec = aDelay;

    int vRet = select(1, &rfds, NULL, NULL, &tv);
    if(vRet == -1)
        return false;
    else if(vRet > 0)
        return true;
#endif
    return false; ///TODO: what to return then don't know how to check data avialabilyty
}
