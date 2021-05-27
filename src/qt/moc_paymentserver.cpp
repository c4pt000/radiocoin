/****************************************************************************
** Meta object code from reading C++ file 'paymentserver.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "qt/paymentserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paymentserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PaymentServer_t {
    QByteArrayData data[23];
    char stringdata0[303];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PaymentServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PaymentServer_t qt_meta_stringdata_PaymentServer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PaymentServer"
QT_MOC_LITERAL(1, 14, 22), // "receivedPaymentRequest"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 18), // "SendCoinsRecipient"
QT_MOC_LITERAL(4, 57, 7), // "message"
QT_MOC_LITERAL(5, 65, 5), // "title"
QT_MOC_LITERAL(6, 71, 5), // "style"
QT_MOC_LITERAL(7, 77, 18), // "receivedPaymentACK"
QT_MOC_LITERAL(8, 96, 13), // "paymentACKMsg"
QT_MOC_LITERAL(9, 110, 7), // "uiReady"
QT_MOC_LITERAL(10, 118, 15), // "handleURIOrFile"
QT_MOC_LITERAL(11, 134, 1), // "s"
QT_MOC_LITERAL(12, 136, 15), // "fetchPaymentACK"
QT_MOC_LITERAL(13, 152, 12), // "WalletModel*"
QT_MOC_LITERAL(14, 165, 11), // "walletModel"
QT_MOC_LITERAL(15, 177, 9), // "recipient"
QT_MOC_LITERAL(16, 187, 11), // "transaction"
QT_MOC_LITERAL(17, 199, 19), // "handleURIConnection"
QT_MOC_LITERAL(18, 219, 18), // "netRequestFinished"
QT_MOC_LITERAL(19, 238, 14), // "QNetworkReply*"
QT_MOC_LITERAL(20, 253, 15), // "reportSslErrors"
QT_MOC_LITERAL(21, 269, 16), // "QList<QSslError>"
QT_MOC_LITERAL(22, 286, 16) // "handlePaymentACK"

    },
    "PaymentServer\0receivedPaymentRequest\0"
    "\0SendCoinsRecipient\0message\0title\0"
    "style\0receivedPaymentACK\0paymentACKMsg\0"
    "uiReady\0handleURIOrFile\0s\0fetchPaymentACK\0"
    "WalletModel*\0walletModel\0recipient\0"
    "transaction\0handleURIConnection\0"
    "netRequestFinished\0QNetworkReply*\0"
    "reportSslErrors\0QList<QSslError>\0"
    "handlePaymentACK"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PaymentServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    3,   67,    2, 0x06 /* Public */,
       7,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   77,    2, 0x0a /* Public */,
      10,    1,   78,    2, 0x0a /* Public */,
      12,    3,   81,    2, 0x0a /* Public */,
      17,    0,   88,    2, 0x08 /* Private */,
      18,    1,   89,    2, 0x08 /* Private */,
      20,    2,   92,    2, 0x08 /* Private */,
      22,    1,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::UInt,    5,    4,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 3, QMetaType::QByteArray,   14,   15,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 21,    2,    2,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void PaymentServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PaymentServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivedPaymentRequest((*reinterpret_cast< SendCoinsRecipient(*)>(_a[1]))); break;
        case 1: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 2: _t->receivedPaymentACK((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->uiReady(); break;
        case 4: _t->handleURIOrFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->fetchPaymentACK((*reinterpret_cast< WalletModel*(*)>(_a[1])),(*reinterpret_cast< const SendCoinsRecipient(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 6: _t->handleURIConnection(); break;
        case 7: _t->netRequestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 8: _t->reportSslErrors((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        case 9: _t->handlePaymentACK((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WalletModel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PaymentServer::*)(SendCoinsRecipient );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PaymentServer::receivedPaymentRequest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PaymentServer::*)(const QString & , const QString & , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PaymentServer::message)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PaymentServer::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PaymentServer::receivedPaymentACK)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PaymentServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PaymentServer.data,
    qt_meta_data_PaymentServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PaymentServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PaymentServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PaymentServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PaymentServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void PaymentServer::receivedPaymentRequest(SendCoinsRecipient _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PaymentServer::message(const QString & _t1, const QString & _t2, unsigned int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PaymentServer::receivedPaymentACK(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
