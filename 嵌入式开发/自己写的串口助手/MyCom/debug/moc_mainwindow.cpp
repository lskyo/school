/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon May 22 18:09:41 2017
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      39,   11,   11,   11, 0x08,
      65,   11,   11,   11, 0x08,
      91,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     143,   11,   11,   11, 0x08,
     175,  169,   11,   11, 0x08,
     214,  169,   11,   11, 0x08,
     253,  169,   11,   11, 0x08,
     292,  169,   11,   11, 0x08,
     329,   11,   11,   11, 0x08,
     355,   11,   11,   11, 0x08,
     379,  169,   11,   11, 0x08,
     418,   11,   11,   11, 0x08,
     444,   11,   11,   11, 0x08,
     470,   11,   11,   11, 0x08,
     482,   11,   11,   11, 0x08,
     508,   11,   11,   11, 0x08,
     522,   11,   11,   11, 0x08,
     542,   11,   11,   11, 0x08,
     558,   11,   11,   11, 0x08,
     601,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_pushButton_10_clicked()\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_4_clicked()\0index\0"
    "on_comboBox_5_currentIndexChanged(int)\0"
    "on_comboBox_4_currentIndexChanged(int)\0"
    "on_comboBox_3_currentIndexChanged(int)\0"
    "on_comboBox_currentIndexChanged(int)\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_comboBox_2_currentIndexChanged(int)\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_2_clicked()\0readMyCom()\0"
    "readPendingDatagrams(int)\0readMessage()\0"
    "readClientMessage()\0getConnection()\0"
    "displayError(QAbstractSocket::SocketError)\0"
    "displayError2(QAbstractSocket::SocketError)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_10_clicked(); break;
        case 1: on_pushButton_9_clicked(); break;
        case 2: on_pushButton_8_clicked(); break;
        case 3: on_pushButton_7_clicked(); break;
        case 4: on_pushButton_6_clicked(); break;
        case 5: on_pushButton_4_clicked(); break;
        case 6: on_comboBox_5_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_comboBox_4_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_comboBox_3_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: on_pushButton_3_clicked(); break;
        case 11: on_pushButton_clicked(); break;
        case 12: on_comboBox_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: on_pushButton_5_clicked(); break;
        case 14: on_pushButton_2_clicked(); break;
        case 15: readMyCom(); break;
        case 16: readPendingDatagrams((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: readMessage(); break;
        case 18: readClientMessage(); break;
        case 19: getConnection(); break;
        case 20: displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 21: displayError2((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
