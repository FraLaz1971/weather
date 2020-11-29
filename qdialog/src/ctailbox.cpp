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
#include "ctailbox.h"
#include "defines.h"


/*

       --tailbox file height width
              Display text from a file in a dialog box, as in a "tail -f" com‐
              mand.  Scroll left/right using vi-style 'h' and 'l',  or  arrow-
              keys.  A '0' resets the scrolling.

              On  exit,  no  text is written to dialog's output.  Only an "OK"
              button is provided for input, but an  ESC  exit  status  may  be
              returned.


       --tailboxbg file height width
              Display  text  from a file in a dialog box as a background task,
              as in a "tail -f &" command.  Scroll left/right  using  vi-style
              'h' and 'l', or arrow-keys.  A '0' resets the scrolling.

              Dialog  treats  the background task specially if there are other
              widgets (--and-widget) on the screen concurrently.  Until  those
              widgets  are  closed (e.g., an "OK"), dialog will perform all of
              the tailboxbg widgets in the same process, polling for  updates.
              You may use a tab to traverse between the widgets on the screen,
              and close them individually, e.g., by pressing ENTER.  Once  the
              non-tailboxbg  widgets are closed, dialog forks a copy of itself
              into the background, and prints its process  id  if  the  "--no-
              kill" option is given.

              On  exit, no text is written to dialog's output.  Only an "EXIT"
              button is provided for input, but an  ESC  exit  status  may  be
              returned.

              NOTE:  Older versions of dialog forked immediately and attempted
              to update the screen individually.  Besides being bad  for  per‐
              formance,  it  was  unworkable.  Some older scripts may not work
              properly with the polled scheme.

  */

CTailBox::CTailBox( QWidget *parent ) : 
CTextBox( parent )
{
    mProgressBoxMode = false;

    mTimer.setInterval(1000); // 1 sec
    connect(&mTimer, SIGNAL(timeout()), this, SLOT(updateFileData()));
    mTimer.start();

    mpStream = NULL;
    mpFile = NULL;
}

CTailBox::~CTailBox()
{
    closeFile();
}

void CTailBox::setFileName(const QString& aFileName)
{
    assignFile(aFileName);
    setReadOnly(true);
}

void CTailBox::assignFile(const QString& aFileName)
{
    mTextBox.setText("");

    mpFile = new QFile(aFileName);
    if(mpFile && mpFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        mpStream = new QTextStream(mpFile);
        if(mpStream == NULL)
            closeFile();
    }
    else
    {
        closeFile();
    }
}

void CTailBox::closeFile()
{
    if(mpFile != NULL)
    {
        delete mpFile;
        mpFile = NULL;
    }
    if(mpStream != NULL)
    {
        delete mpStream;
        mpStream = NULL;
    }
}

void CTailBox::updateFileData()
{
    if(mpStream != NULL)
    {
        while(!mpStream->atEnd())
        {
            QString vString = mpStream->readLine();
            if(!vString.isEmpty() || !mpStream->atEnd())
            {

                mTextBox.append(vString);
            }
        }
    }

    mTextBox.setReadOnly(true);
}

void CTailBox::setProgressBoxMode(bool aMode)
{
    if(aMode)
        mLabel.show();
    else
        mLabel.hide();
 }

void CTailBox::setProgressBoxText(const QString& aLabel)
{
    mLabel.setText(aLabel);
}

