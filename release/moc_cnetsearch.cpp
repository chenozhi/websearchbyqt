/****************************************************************************
** Meta object code from reading C++ file 'cnetsearch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cnetsearch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cnetsearch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CNetSearch_t {
    QByteArrayData data[10];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CNetSearch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CNetSearch_t qt_meta_stringdata_CNetSearch = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CNetSearch"
QT_MOC_LITERAL(1, 11, 12), // "startParsing"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "stopParsing"
QT_MOC_LITERAL(4, 37, 12), // "startRequest"
QT_MOC_LITERAL(5, 50, 15), // "replyFromRemote"
QT_MOC_LITERAL(6, 66, 14), // "QNetworkReply*"
QT_MOC_LITERAL(7, 81, 5), // "reply"
QT_MOC_LITERAL(8, 87, 13), // "requestCookie"
QT_MOC_LITERAL(9, 101, 7) // "request"

    },
    "CNetSearch\0startParsing\0\0stopParsing\0"
    "startRequest\0replyFromRemote\0"
    "QNetworkReply*\0reply\0requestCookie\0"
    "request"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CNetSearch[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    0,   47,    2, 0x06 /* Public */,
       4,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   49,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       8,    0,   52,    2, 0x02 /* Public */,
       9,    0,   53,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void CNetSearch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CNetSearch *_t = static_cast<CNetSearch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startParsing((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->stopParsing(); break;
        case 2: _t->startRequest(); break;
        case 3: _t->replyFromRemote((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: { int _r = _t->requestCookie();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->request();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CNetSearch::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CNetSearch::startParsing)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CNetSearch::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CNetSearch::stopParsing)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CNetSearch::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CNetSearch::startRequest)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject CNetSearch::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CNetSearch.data,
      qt_meta_data_CNetSearch,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CNetSearch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CNetSearch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CNetSearch.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CNetSearch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CNetSearch::startParsing(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CNetSearch::stopParsing()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CNetSearch::startRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE