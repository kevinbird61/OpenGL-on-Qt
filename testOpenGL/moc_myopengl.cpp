/****************************************************************************
** Meta object code from reading C++ file 'myopengl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myopengl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myopengl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyOpenGL_t {
    QByteArrayData data[14];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyOpenGL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyOpenGL_t qt_meta_stringdata_MyOpenGL = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyOpenGL"
QT_MOC_LITERAL(1, 9, 12), // "changeShader"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "string"
QT_MOC_LITERAL(4, 30, 16), // "changeViewShader"
QT_MOC_LITERAL(5, 47, 5), // "value"
QT_MOC_LITERAL(6, 53, 15), // "changeLightXPos"
QT_MOC_LITERAL(7, 69, 15), // "changeLightYPos"
QT_MOC_LITERAL(8, 85, 15), // "changeLightZPos"
QT_MOC_LITERAL(9, 101, 12), // "changePicSrc"
QT_MOC_LITERAL(10, 114, 12), // "changePicObj"
QT_MOC_LITERAL(11, 127, 12), // "changeXModel"
QT_MOC_LITERAL(12, 140, 11), // "changeSigma"
QT_MOC_LITERAL(13, 152, 5) // "sigma"

    },
    "MyOpenGL\0changeShader\0\0string\0"
    "changeViewShader\0value\0changeLightXPos\0"
    "changeLightYPos\0changeLightZPos\0"
    "changePicSrc\0changePicObj\0changeXModel\0"
    "changeSigma\0sigma"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyOpenGL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       6,    1,   65,    2, 0x0a /* Public */,
       7,    1,   68,    2, 0x0a /* Public */,
       8,    1,   71,    2, 0x0a /* Public */,
       9,    1,   74,    2, 0x0a /* Public */,
      10,    1,   77,    2, 0x0a /* Public */,
      11,    1,   80,    2, 0x0a /* Public */,
      12,    1,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double,   13,

       0        // eod
};

void MyOpenGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyOpenGL *_t = static_cast<MyOpenGL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeShader((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->changeViewShader((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeLightXPos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changeLightYPos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeLightZPos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->changePicSrc((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->changePicObj((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->changeXModel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->changeSigma((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MyOpenGL::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_MyOpenGL.data,
      qt_meta_data_MyOpenGL,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyOpenGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyOpenGL::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyOpenGL.stringdata0))
        return static_cast<void*>(const_cast< MyOpenGL*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int MyOpenGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
