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
#include "cmenubox.h"

#include "defines.h"


CMenuBox::CMenuBox( QWidget *parent ) : 
CMsgBox( parent )
{
    mpLayoutMain->insertWidget(1, &mMenuItems, 0);
    //mMenuItems.setViewMode(QListView::ListMode);
    mColumnCount = 1;
	mMenuType = MENUTYPE_MENU;

    mMenuItems.setSelectionMode( QAbstractItemView::SingleSelection );
}

void CMenuBox::setMenuType(NMenuType aMenuType)
{
    mMenuType = aMenuType;
    if( mBoxOptions.notags )
    {
        setColumnCount(1);
        mMenuItems.headerItem()->setText(0,"Name");
    }
    else
    {
        setColumnCount(2);
        mMenuItems.headerItem()->setText(0,"Tag");
        mMenuItems.headerItem()->setText(1,"Name");
    }

    mMenuItems.headerItem()->setHidden(true);
    mMenuItems.setRootIsDecorated(false);

    connect(&mMenuItems, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(itemDoubleClicked(QTreeWidgetItem*, int)));
    connect(&mMenuItems, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(itemChanged(QTreeWidgetItem*, int)));

}

void CMenuBox::setMenuHeight(int aHeight)
{
    mMenuItems.setGeometry(0, 0, 100, 10);
}


void CMenuBox::adjustSize()
{
    CMsgBox::adjustSize();

}


void CMenuBox::resizeEvent( QResizeEvent * aEvent )
{
    CMsgBox::resizeEvent( aEvent );
}

void CMenuBox::setColumnCount(int aCount)
{
    if((aCount >= 1) & (aCount <= 2))
    {
        mMenuItems.setColumnCount(aCount);
        if(aCount == 1)
        {
            ///TODO: why this line don't want to work
            mMenuItems.setColumnWidth(0, mMenuItems.width());
        }
        mColumnCount = aCount;
    }
}

void CMenuBox::addMenuItem(const QString& aItemTag, const QString& aItemName, const QString& aItemHelp, bool aItemChecked)
{

#if 0
    qWarning() << "add menu item " << aItemTag << aItemName << aItemHelp << aItemChecked << mColumnCount;
#endif

    QTreeWidgetItem* vpItem = new QTreeWidgetItem(&mMenuItems);

    vpItem->setData(0, Qt::UserRole, aItemTag);
    vpItem->setData(0, Qt::UserRole+1, aItemName);
    vpItem->setToolTip(0, aItemHelp);
//    vpItem->setStatusTip(0, aItemHelp);

    if(mColumnCount == 1)
    {
        vpItem->setText(0, aItemName);
    }
    else
    {
        vpItem->setText(0, aItemTag);
        vpItem->setText(1, aItemName);

        vpItem->setToolTip(1, aItemHelp);
//        vpItem->setStatusTip(1, aItemHelp);
    }

    if(mMenuType >= MENUTYPE_RADIOLIST)
	{
    	vpItem->setCheckState(0, aItemChecked?Qt::Checked:Qt::Unchecked);
	}

    if(mMenuType == MENUTYPE_INPUTMENU)
    {
        vpItem->setFlags(vpItem->flags() | Qt::ItemIsEditable);
    }
}

void CMenuBox::setSelectedItem(int aDefaultIndex)
{
    if(mMenuItems.topLevelItemCount() > 0)
    {
        if((aDefaultIndex < 0) || (aDefaultIndex >= mMenuItems.topLevelItemCount()))
            aDefaultIndex = 0;

        mMenuItems.setCurrentItem(mMenuItems.topLevelItem(aDefaultIndex));
    }
}

QString CMenuBox::selectedTag() const
{
    QTreeWidgetItem* vpItem = mMenuItems.currentItem();
    if(vpItem)
    {
        return vpItem->data(0, Qt::UserRole).toString();
    }
    else
    {
        return QString::Null();
    }
}

void CMenuBox::itemDoubleClicked ( QTreeWidgetItem * apItem, int aColumn )
{
    if((mMenuType == MENUTYPE_CHECKLIST) || (mMenuType == MENUTYPE_RADIOLIST))
    {
        apItem->setCheckState(0, Qt::Checked);
    }

    if(mMenuType != MENUTYPE_INPUTMENU)
    {
        if(apItem != NULL)
            finish(IDRET_OK);
    }
}

QList<QTreeWidgetItem*> CMenuBox::getItems() const
{
    return mMenuItems.findItems(QString("*"), Qt::MatchWrap | Qt::MatchWildcard);
}


QList<QTreeWidgetItem*>* CMenuBox::getCheckedItems() const
{
    QList<QTreeWidgetItem*>* vpResult = new QList<QTreeWidgetItem*>;
    if(vpResult == NULL)
        return NULL;

    for(int i = 0; i < mMenuItems.topLevelItemCount(); i++)
    {
        QTreeWidgetItem* vpItem = mMenuItems.topLevelItem(i);
        if(vpItem->checkState(0) == Qt::Checked)
            vpResult->append(vpItem);
    }

    return vpResult;
}

QString CMenuBox::getFirstCheckedItem() const
{
    for(int i = 0; i < mMenuItems.topLevelItemCount(); i++)
    {
        QTreeWidgetItem* vpItem = mMenuItems.topLevelItem(i);
        if(vpItem->checkState(0) == Qt::Checked)
            return vpItem->text(0);
    }

    return QString::Null();
}


void CMenuBox::itemChanged ( QTreeWidgetItem * apItem, int aColumn ) 
{
    if(mMenuType == MENUTYPE_RADIOLIST)
    {
        if((apItem->checkState(0) == Qt::Checked) && (aColumn == 0))
        {
            QList<QTreeWidgetItem*> vItems = mMenuItems.findItems(QString("*"), Qt::MatchWrap | Qt::MatchWildcard);
            
            for(int i = 0; i < vItems.count(); i++)
            {
                QTreeWidgetItem* vpItem = vItems.at(i);
                if(vpItem != apItem)
                    vpItem->setCheckState(0, Qt::Unchecked);
            }
        }
    }
}
