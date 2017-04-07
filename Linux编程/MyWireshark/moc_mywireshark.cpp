/****************************************************************************
** Meta object code from reading C++ file 'mywireshark.h'
**
** Created: Mon Dec 19 19:22:23 2016
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mywireshark.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywireshark.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mywireshark[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      26,   12,   12,   12, 0x08,
      45,   12,   12,   12, 0x08,
      64,   12,   12,   12, 0x08,
      82,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_mywireshark[] = {
    "mywireshark\0\0onTimerOut()\0on_apply_clicked()\0"
    "on_clear_clicked()\0on_stop_clicked()\0"
    "on_start_clicked()\0"
};

const QMetaObject mywireshark::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mywireshark,
      qt_meta_data_mywireshark, 0 }
};

const QMetaObject *mywireshark::metaObject() const
{
    return &staticMetaObject;
}

void *mywireshark::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mywireshark))
        return static_cast<void*>(const_cast< mywireshark*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int mywireshark::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onTimerOut(); break;
        case 1: on_apply_clicked(); break;
        case 2: on_clear_clicked(); break;
        case 3: on_stop_clicked(); break;
        case 4: on_start_clicked(); break;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
