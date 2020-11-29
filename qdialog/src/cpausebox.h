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
#ifndef __CPAUSEBOX_H__
#define __CPAUSEBOX_H__

#include <CGaugeBox>

/*

       --pause text height width seconds
              A pause box displays a meter along the bottom of the  box.   The
              meter  indicates  how  many  seconds remain until the end of the
              pause.  The pause exits when timeout is reached (status  OK)  or
              the user presses the Exit button (status CANCEL).

*/

class CPauseBox : public CGaugeBox
{
Q_OBJECT
public:
    CPauseBox( QWidget* parent=0 );

public:
    void setPauseSeconds(const int aValue);

protected slots:
    void    updateGauge();

protected:
    QTimer  mTimer;
};

#endif // __CPAUSEBOX_H__
