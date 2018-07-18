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
    QByteArrayData data[14];
    char stringdata0[165];
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
QT_MOC_LITERAL(3, 25, 18), // "startParsingThread"
QT_MOC_LITERAL(4, 44, 11), // "stopParsing"
QT_MOC_LITERAL(5, 56, 12), // "startRequest"
QT_MOC_LITERAL(6, 69, 15), // "replyFromRemote"
QT_MOC_LITERAL(7, 85, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 100, 5), // "reply"
QT_MOC_LITERAL(9, 106, 18), // "replyFromThreadAsk"
QT_MOC_LITERAL(10, 125, 7), // "request"
QT_MOC_LITERAL(11, 133, 13), // "requestThread"
QT_MOC_LITERAL(12, 147, 3), // "url"
QT_MOC_LITERAL(13, 151, 13) // "requestCookie"

    },
    "CNetSearch\0startParsing\0\0startParsingThread\0"
    "stopParsing\0startRequest\0replyFromRemote\0"
    "QNetworkReply*\0reply\0replyFromThreadAsk\0"
    "request\0requestThread\0url\0requestCookie"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CNetSearch[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    0,   65,    2, 0x06 /* Public */,
       5,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   67,    2, 0x0a /* Public */,
       9,    1,   70,    2, 0x0a /* Public */,
      10,    0,   73,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      13,    0,   77,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

 // methods: parameters
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
        case 1: _t->startParsingThread((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->stopParsing(); break;
        case 3: _t->startRequest(); break;
        case 4: _t->replyFromRemote((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->replyFromThreadAsk((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->request(); break;
        case 7: _t->requestThread((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: { int _r = _t->requestCookie();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 5:
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
            typedef void (CNetSearch::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CNetSearch::startParsingThread)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CNetSearch::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CNetSearch::stopParsing)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CNetSearch::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CNetSearch::startRequest)) {
                *result = 3;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
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
void CNetSearch::startParsingThread(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CNetSearch::stopParsing()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void CNetSearch::startRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
