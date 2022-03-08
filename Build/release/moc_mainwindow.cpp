/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MAT500Project2/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 6), // "BBForm"
QT_MOC_LITERAL(2, 18, 9), // "PointPair"
QT_MOC_LITERAL(3, 28, 0), // ""
QT_MOC_LITERAL(4, 29, 1), // "t"
QT_MOC_LITERAL(5, 31, 3), // "NLI"
QT_MOC_LITERAL(6, 35, 19), // "MidpointSubdivision"
QT_MOC_LITERAL(7, 55, 20), // "PrintPascalsTriangle"
QT_MOC_LITERAL(8, 76, 21), // "CreatePascalsTriangle"
QT_MOC_LITERAL(9, 98, 8), // "MakePlot"
QT_MOC_LITERAL(10, 107, 11), // "onPointDrag"
QT_MOC_LITERAL(11, 119, 12), // "QMouseEvent*"
QT_MOC_LITERAL(12, 132, 5), // "event"
QT_MOC_LITERAL(13, 138, 8), // "AddPoint"
QT_MOC_LITERAL(14, 147, 22), // "ClearShellPointVectors"
QT_MOC_LITERAL(15, 170, 13), // "AddShellCurve"
QT_MOC_LITERAL(16, 184, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(17, 217, 5), // "value"
QT_MOC_LITERAL(18, 223, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(19, 254, 4), // "arg1"
QT_MOC_LITERAL(20, 259, 19), // "on_checkBox_toggled"
QT_MOC_LITERAL(21, 279, 7) // "checked"

    },
    "MainWindow\0BBForm\0PointPair\0\0t\0NLI\0"
    "MidpointSubdivision\0PrintPascalsTriangle\0"
    "CreatePascalsTriangle\0MakePlot\0"
    "onPointDrag\0QMouseEvent*\0event\0AddPoint\0"
    "ClearShellPointVectors\0AddShellCurve\0"
    "on_horizontalSlider_valueChanged\0value\0"
    "on_comboBox_currentTextChanged\0arg1\0"
    "on_checkBox_toggled\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    3, 0x08 /* Private */,
       5,    1,   82,    3, 0x08 /* Private */,
       6,    0,   85,    3, 0x08 /* Private */,
       7,    0,   86,    3, 0x08 /* Private */,
       8,    0,   87,    3, 0x08 /* Private */,
       9,    0,   88,    3, 0x08 /* Private */,
      10,    1,   89,    3, 0x08 /* Private */,
      13,    1,   92,    3, 0x08 /* Private */,
      14,    0,   95,    3, 0x08 /* Private */,
      15,    0,   96,    3, 0x08 /* Private */,
      16,    1,   97,    3, 0x08 /* Private */,
      18,    1,  100,    3, 0x08 /* Private */,
      20,    1,  103,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2, QMetaType::Double,    4,
    0x80000000 | 2, QMetaType::Double,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::Bool,   21,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { PointPair _r = _t->BBForm((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< PointPair*>(_a[0]) = std::move(_r); }  break;
        case 1: { PointPair _r = _t->NLI((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< PointPair*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->MidpointSubdivision(); break;
        case 3: _t->PrintPascalsTriangle(); break;
        case 4: _t->CreatePascalsTriangle(); break;
        case 5: _t->MakePlot(); break;
        case 6: _t->onPointDrag((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: _t->AddPoint((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 8: _t->ClearShellPointVectors(); break;
        case 9: _t->AddShellCurve(); break;
        case 10: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
