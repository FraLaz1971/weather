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
#ifndef __CTAILBOX_H__
#define __CTAILBOX_H__

#include <CTextBox>

class CTailBox : public CTextBox
{
Q_OBJECT
public:
    CTailBox( QWidget* parent=0 );
    ~CTailBox();

public:
    virtual void    setFileName(const QString& aFileName);
    void    assignFile(const QString& aFileName);
    void    closeFile();
    void    setProgressBoxMode(bool aMode = true);
    void    setProgressBoxText(const QString& aLabel);

protected slots:
    void    updateFileData();

protected:
    QTimer  		mTimer;
    QFile*  		mpFile;
    QTextStream* 	mpStream;
    bool            mProgressBoxMode;
};


#endif // __CTAILBOX_H__
