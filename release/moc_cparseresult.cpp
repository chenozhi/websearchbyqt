/****************************************************************************
** Meta object code from reading C++ file 'cparseresult.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cparseresult.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cparseresult.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CParseResult_t {
    QByteArrayData data[11];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CParseResult_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CParseResult_t qt_meta_stringdata_CParseResult = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CParseResult"
QT_MOC_LITERAL(1, 13, 17), // "parsePageFinished"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 19), // "parseThreadFinished"
QT_MOC_LITERAL(4, 52, 15), // "enterIntoThread"
QT_MOC_LITERAL(5, 68, 9), // "parseDone"
QT_MOC_LITERAL(6, 78, 5), // "total"
QT_MOC_LITERAL(7, 84, 11), // "doParseWork"
QT_MOC_LITERAL(8, 96, 2), // "ba"
QT_MOC_LITERAL(9, 99, 13), // "doThreadParse"
QT_MOC_LITERAL(10, 113, 11) // "doGetReuslt"

    },
    "CParseResult\0parsePageFinished\0\0"
    "parseThreadFinished\0enterIntoThread\0"
    "parseDone\0total\0doParseWork\0ba\0"
    "doThreadParse\0doGetReuslt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CParseResult[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,
       5,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   57,    2, 0x0a /* Public */,
       9,    1,   60,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void,

       0        // eod
};

void CParseResult::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CParseResult *_t = static_cast<CParseResult *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->parsePageFinished(); break;
        case 1: _t->parseThreadFinished(); break;
        case 2: _t->enterIntoThread((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->parseDone((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->doParseWork((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->doThreadParse((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->doGetReuslt(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CParseResult::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CParseResult::parsePageFinished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CParseResult::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CParseResult::parseThreadFinished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CParseResult::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CParseResult::enterIntoThread)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CParseResult::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CParseResult::parseDone)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject CParseResult::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CParseResult.data,
      qt_meta_data_CParseResult,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CParseResult::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CParseResult::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CParseResult.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CParseResult::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CParseResult::parsePageFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CParseResult::parseThreadFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CParseResult::enterIntoThread(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CParseResult::parseDone(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
