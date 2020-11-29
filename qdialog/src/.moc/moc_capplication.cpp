/****************************************************************************
** Meta object code from reading C++ file 'capplication.h'
**
** Created: Tue Aug 31 01:27:45 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../3rdparty/capplication.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'capplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CApplication[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   14,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CApplication[] = {
    "CApplication\0\0aSigNo\0unixSignalHandler(int)\0"
};

const QMetaObject CApplication::staticMetaObject = {
    { &QApplication::staticMetaObject, qt_meta_stringdata_CApplication,
      qt_meta_data_CApplication, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CApplication::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CApplication))
        return static_cast<void*>(const_cast< CApplication*>(this));
    return QApplication::qt_metacast(_clname);
}

int CApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: unixSignalHandler((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
