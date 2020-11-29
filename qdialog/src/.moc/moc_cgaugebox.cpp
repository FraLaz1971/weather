/****************************************************************************
** Meta object code from reading C++ file 'cgaugebox.h'
**
** Created: Tue Aug 31 01:27:56 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cgaugebox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cgaugebox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CGaugeBox[] = {

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
      20,   11,   10,   10, 0x09,
      42,   36,   10,   10, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CGaugeBox[] = {
    "CGaugeBox\0\0aPercent\0newPercent(int)\0"
    "aText\0newText(QString)\0"
};

const QMetaObject CGaugeBox::staticMetaObject = {
    { &CMsgBox::staticMetaObject, qt_meta_stringdata_CGaugeBox,
      qt_meta_data_CGaugeBox, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CGaugeBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CGaugeBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CGaugeBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CGaugeBox))
        return static_cast<void*>(const_cast< CGaugeBox*>(this));
    return CMsgBox::qt_metacast(_clname);
}

int CGaugeBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CMsgBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newPercent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: newText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_CGaugeBoxThread[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   17,   16,   16, 0x05,
      52,   46,   16,   16, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_CGaugeBoxThread[] = {
    "CGaugeBoxThread\0\0aPercent\0percentChanged(int)\0"
    "aText\0textChanged(QString)\0"
};

const QMetaObject CGaugeBoxThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_CGaugeBoxThread,
      qt_meta_data_CGaugeBoxThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CGaugeBoxThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CGaugeBoxThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CGaugeBoxThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CGaugeBoxThread))
        return static_cast<void*>(const_cast< CGaugeBoxThread*>(this));
    return QThread::qt_metacast(_clname);
}

int CGaugeBoxThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: percentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CGaugeBoxThread::percentChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CGaugeBoxThread::textChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
