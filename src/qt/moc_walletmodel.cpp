/****************************************************************************
** Meta object code from reading C++ file 'walletmodel.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "qt/walletmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'walletmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WalletModel_t {
    QByteArrayData data[32];
    char stringdata0[408];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WalletModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WalletModel_t qt_meta_stringdata_WalletModel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "WalletModel"
QT_MOC_LITERAL(1, 12, 14), // "balanceChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 26), // "interfaces::WalletBalances"
QT_MOC_LITERAL(4, 55, 8), // "balances"
QT_MOC_LITERAL(5, 64, 23), // "encryptionStatusChanged"
QT_MOC_LITERAL(6, 88, 13), // "requireUnlock"
QT_MOC_LITERAL(7, 102, 7), // "message"
QT_MOC_LITERAL(8, 110, 5), // "title"
QT_MOC_LITERAL(9, 116, 5), // "style"
QT_MOC_LITERAL(10, 122, 9), // "coinsSent"
QT_MOC_LITERAL(11, 132, 12), // "WalletModel*"
QT_MOC_LITERAL(12, 145, 6), // "wallet"
QT_MOC_LITERAL(13, 152, 18), // "SendCoinsRecipient"
QT_MOC_LITERAL(14, 171, 9), // "recipient"
QT_MOC_LITERAL(15, 181, 11), // "transaction"
QT_MOC_LITERAL(16, 193, 12), // "showProgress"
QT_MOC_LITERAL(17, 206, 9), // "nProgress"
QT_MOC_LITERAL(18, 216, 22), // "notifyWatchonlyChanged"
QT_MOC_LITERAL(19, 239, 14), // "fHaveWatchonly"
QT_MOC_LITERAL(20, 254, 6), // "unload"
QT_MOC_LITERAL(21, 261, 22), // "canGetAddressesChanged"
QT_MOC_LITERAL(22, 284, 12), // "updateStatus"
QT_MOC_LITERAL(23, 297, 17), // "updateTransaction"
QT_MOC_LITERAL(24, 315, 17), // "updateAddressBook"
QT_MOC_LITERAL(25, 333, 7), // "address"
QT_MOC_LITERAL(26, 341, 5), // "label"
QT_MOC_LITERAL(27, 347, 6), // "isMine"
QT_MOC_LITERAL(28, 354, 7), // "purpose"
QT_MOC_LITERAL(29, 362, 6), // "status"
QT_MOC_LITERAL(30, 369, 19), // "updateWatchOnlyFlag"
QT_MOC_LITERAL(31, 389, 18) // "pollBalanceChanged"

    },
    "WalletModel\0balanceChanged\0\0"
    "interfaces::WalletBalances\0balances\0"
    "encryptionStatusChanged\0requireUnlock\0"
    "message\0title\0style\0coinsSent\0"
    "WalletModel*\0wallet\0SendCoinsRecipient\0"
    "recipient\0transaction\0showProgress\0"
    "nProgress\0notifyWatchonlyChanged\0"
    "fHaveWatchonly\0unload\0canGetAddressesChanged\0"
    "updateStatus\0updateTransaction\0"
    "updateAddressBook\0address\0label\0isMine\0"
    "purpose\0status\0updateWatchOnlyFlag\0"
    "pollBalanceChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WalletModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    0,   88,    2, 0x06 /* Public */,
       7,    3,   89,    2, 0x06 /* Public */,
      10,    3,   96,    2, 0x06 /* Public */,
      16,    2,  103,    2, 0x06 /* Public */,
      18,    1,  108,    2, 0x06 /* Public */,
      20,    0,  111,    2, 0x06 /* Public */,
      21,    0,  112,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    0,  113,    2, 0x0a /* Public */,
      23,    0,  114,    2, 0x0a /* Public */,
      24,    5,  115,    2, 0x0a /* Public */,
      30,    1,  126,    2, 0x0a /* Public */,
      31,    0,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::UInt,    8,    7,    9,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 13, QMetaType::QByteArray,   12,   14,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    8,   17,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::Int,   25,   26,   27,   28,   29,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,

       0        // eod
};

void WalletModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WalletModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->balanceChanged((*reinterpret_cast< const interfaces::WalletBalances(*)>(_a[1]))); break;
        case 1: _t->encryptionStatusChanged(); break;
        case 2: _t->requireUnlock(); break;
        case 3: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 4: _t->coinsSent((*reinterpret_cast< WalletModel*(*)>(_a[1])),(*reinterpret_cast< SendCoinsRecipient(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 5: _t->showProgress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->notifyWatchonlyChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->unload(); break;
        case 8: _t->canGetAddressesChanged(); break;
        case 9: _t->updateStatus(); break;
        case 10: _t->updateTransaction(); break;
        case 11: _t->updateAddressBook((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 12: _t->updateWatchOnlyFlag((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->pollBalanceChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
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
            using _t = void (WalletModel::*)(const interfaces::WalletBalances & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletModel::balanceChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WalletModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletModel::encryptionStatusChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WalletModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletModel::requireUnlock)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WalletModel::*)(const QString & , const QString & , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletModel::message)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WalletModel::*)(WalletModel * , SendCoinsRecipient , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletModel::coinsSent)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (WalletModel::*)(const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletModel::showProgress)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (WalletModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletModel::notifyWatchonlyChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (WalletModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletModel::unload)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (WalletModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletModel::canGetAddressesChanged)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WalletModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_WalletModel.data,
    qt_meta_data_WalletModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WalletModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WalletModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WalletModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WalletModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void WalletModel::balanceChanged(const interfaces::WalletBalances & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WalletModel::encryptionStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WalletModel::requireUnlock()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WalletModel::message(const QString & _t1, const QString & _t2, unsigned int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WalletModel::coinsSent(WalletModel * _t1, SendCoinsRecipient _t2, QByteArray _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void WalletModel::showProgress(const QString & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void WalletModel::notifyWatchonlyChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void WalletModel::unload()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void WalletModel::canGetAddressesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
