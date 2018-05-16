/****************************************************************************
** Meta object code from reading C++ file 'ui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ui_t {
    QByteArrayData data[9];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ui_t qt_meta_stringdata_ui = {
    {
QT_MOC_LITERAL(0, 0, 2), // "ui"
QT_MOC_LITERAL(1, 3, 9), // "load_data"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 3), // "seg"
QT_MOC_LITERAL(4, 18, 15), // "slider_changed1"
QT_MOC_LITERAL(5, 34, 5), // "value"
QT_MOC_LITERAL(6, 40, 15), // "slider_changed2"
QT_MOC_LITERAL(7, 56, 15), // "slider_changed3"
QT_MOC_LITERAL(8, 72, 15) // "slider_changed4"

    },
    "ui\0load_data\0\0seg\0slider_changed1\0"
    "value\0slider_changed2\0slider_changed3\0"
    "slider_changed4"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    1,   46,    2, 0x0a /* Public */,
       6,    1,   49,    2, 0x0a /* Public */,
       7,    1,   52,    2, 0x0a /* Public */,
       8,    1,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void ui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ui *_t = static_cast<ui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->load_data(); break;
        case 1: _t->seg(); break;
        case 2: _t->slider_changed1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slider_changed2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->slider_changed3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slider_changed4((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ui::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ui.data,
      qt_meta_data_ui,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ui::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ui.stringdata0))
        return static_cast<void*>(const_cast< ui*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
