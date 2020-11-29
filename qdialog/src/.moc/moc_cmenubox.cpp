/****************************************************************************
** Meta object code from reading C++ file 'cmenubox.h'
**
** Created: Tue Aug 31 01:28:13 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cmenubox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cmenubox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CMenuBox[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   10,    9,    9, 0x09,
      65,   10,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CMenuBox[] = {
    "CMenuBox\0\0apItem,aColumn\0"
    "itemDoubleClicked(QTreeWidgetItem*,int)\0"
    "itemChanged(QTreeWidgetItem*,int)\0"
};

const QMetaObject CMenuBox::staticMetaObject = {
    { &CMsgBox::staticMetaObject, qt_meta_stringdata_CMenuBox,
      qt_meta_data_CMenuBox, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CMenuBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CMenuBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CMenuBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CMenuBox))
        return static_cast<void*>(const_cast< CMenuBox*>(this));
    return CMsgBox::qt_metacast(_clname);
}

int CMenuBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CMsgBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: itemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: itemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
