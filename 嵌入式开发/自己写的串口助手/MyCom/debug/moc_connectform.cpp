/****************************************************************************
** Meta object code from reading C++ file 'connectform.h'
**
** Created: Sat May 20 10:20:26 2017
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../connectform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConnectForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   12,   12,   12, 0x08,
      59,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConnectForm[] = {
    "ConnectForm\0\0sendConnectReady(int)\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
};

const QMetaObject ConnectForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ConnectForm,
      qt_meta_data_ConnectForm, 0 }
};

const QMetaObject *ConnectForm::metaObject() const
{
    return &staticMetaObject;
}

void *ConnectForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectForm))
        return static_cast<void*>(const_cast< ConnectForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int ConnectForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendConnectReady((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: on_pushButton_clicked(); break;
        case 2: on_pushButton_2_clicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ConnectForm::sendConnectReady(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
