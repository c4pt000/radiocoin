/****************************************************************************
** Meta object code from reading C++ file 'walletview.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "qt/walletview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'walletview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WalletView_t {
    QByteArrayData data[40];
    char stringdata0[543];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WalletView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WalletView_t qt_meta_stringdata_WalletView = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WalletView"
QT_MOC_LITERAL(1, 11, 21), // "showNormalIfMinimized"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "message"
QT_MOC_LITERAL(4, 42, 5), // "title"
QT_MOC_LITERAL(5, 48, 5), // "style"
QT_MOC_LITERAL(6, 54, 23), // "encryptionStatusChanged"
QT_MOC_LITERAL(7, 78, 22), // "hdEnabledStatusChanged"
QT_MOC_LITERAL(8, 101, 19), // "incomingTransaction"
QT_MOC_LITERAL(9, 121, 4), // "date"
QT_MOC_LITERAL(10, 126, 4), // "unit"
QT_MOC_LITERAL(11, 131, 7), // "CAmount"
QT_MOC_LITERAL(12, 139, 6), // "amount"
QT_MOC_LITERAL(13, 146, 4), // "type"
QT_MOC_LITERAL(14, 151, 7), // "address"
QT_MOC_LITERAL(15, 159, 5), // "label"
QT_MOC_LITERAL(16, 165, 10), // "walletName"
QT_MOC_LITERAL(17, 176, 23), // "outOfSyncWarningClicked"
QT_MOC_LITERAL(18, 200, 16), // "gotoOverviewPage"
QT_MOC_LITERAL(19, 217, 15), // "gotoHistoryPage"
QT_MOC_LITERAL(20, 233, 20), // "gotoReceiveCoinsPage"
QT_MOC_LITERAL(21, 254, 17), // "gotoSendCoinsPage"
QT_MOC_LITERAL(22, 272, 4), // "addr"
QT_MOC_LITERAL(23, 277, 18), // "gotoSignMessageTab"
QT_MOC_LITERAL(24, 296, 20), // "gotoVerifyMessageTab"
QT_MOC_LITERAL(25, 317, 21), // "processNewTransaction"
QT_MOC_LITERAL(26, 339, 11), // "QModelIndex"
QT_MOC_LITERAL(27, 351, 6), // "parent"
QT_MOC_LITERAL(28, 358, 5), // "start"
QT_MOC_LITERAL(29, 364, 13), // "encryptWallet"
QT_MOC_LITERAL(30, 378, 6), // "status"
QT_MOC_LITERAL(31, 385, 12), // "backupWallet"
QT_MOC_LITERAL(32, 398, 16), // "changePassphrase"
QT_MOC_LITERAL(33, 415, 12), // "unlockWallet"
QT_MOC_LITERAL(34, 428, 20), // "usedSendingAddresses"
QT_MOC_LITERAL(35, 449, 22), // "usedReceivingAddresses"
QT_MOC_LITERAL(36, 472, 22), // "updateEncryptionStatus"
QT_MOC_LITERAL(37, 495, 12), // "showProgress"
QT_MOC_LITERAL(38, 508, 9), // "nProgress"
QT_MOC_LITERAL(39, 518, 24) // "requestedSyncWarningInfo"

    },
    "WalletView\0showNormalIfMinimized\0\0"
    "message\0title\0style\0encryptionStatusChanged\0"
    "hdEnabledStatusChanged\0incomingTransaction\0"
    "date\0unit\0CAmount\0amount\0type\0address\0"
    "label\0walletName\0outOfSyncWarningClicked\0"
    "gotoOverviewPage\0gotoHistoryPage\0"
    "gotoReceiveCoinsPage\0gotoSendCoinsPage\0"
    "addr\0gotoSignMessageTab\0gotoVerifyMessageTab\0"
    "processNewTransaction\0QModelIndex\0"
    "parent\0start\0encryptWallet\0status\0"
    "backupWallet\0changePassphrase\0"
    "unlockWallet\0usedSendingAddresses\0"
    "usedReceivingAddresses\0updateEncryptionStatus\0"
    "showProgress\0nProgress\0requestedSyncWarningInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WalletView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  139,    2, 0x06 /* Public */,
       3,    3,  140,    2, 0x06 /* Public */,
       6,    0,  147,    2, 0x06 /* Public */,
       7,    0,  148,    2, 0x06 /* Public */,
       8,    7,  149,    2, 0x06 /* Public */,
      17,    0,  164,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  165,    2, 0x0a /* Public */,
      19,    0,  166,    2, 0x0a /* Public */,
      20,    0,  167,    2, 0x0a /* Public */,
      21,    1,  168,    2, 0x0a /* Public */,
      21,    0,  171,    2, 0x2a /* Public | MethodCloned */,
      23,    1,  172,    2, 0x0a /* Public */,
      23,    0,  175,    2, 0x2a /* Public | MethodCloned */,
      24,    1,  176,    2, 0x0a /* Public */,
      24,    0,  179,    2, 0x2a /* Public | MethodCloned */,
      25,    3,  180,    2, 0x0a /* Public */,
      29,    1,  187,    2, 0x0a /* Public */,
      31,    0,  190,    2, 0x0a /* Public */,
      32,    0,  191,    2, 0x0a /* Public */,
      33,    0,  192,    2, 0x0a /* Public */,
      34,    0,  193,    2, 0x0a /* Public */,
      35,    0,  194,    2, 0x0a /* Public */,
      36,    0,  195,    2, 0x0a /* Public */,
      37,    2,  196,    2, 0x0a /* Public */,
      39,    0,  201,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::UInt,    4,    3,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, 0x80000000 | 11, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   12,   13,   14,   15,   16,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 26, QMetaType::Int, QMetaType::Int,   27,   28,    2,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    4,   38,
    QMetaType::Void,

       0        // eod
};

void WalletView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WalletView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showNormalIfMinimized(); break;
        case 1: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 2: _t->encryptionStatusChanged(); break;
        case 3: _t->hdEnabledStatusChanged(); break;
        case 4: _t->incomingTransaction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const CAmount(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7]))); break;
        case 5: _t->outOfSyncWarningClicked(); break;
        case 6: _t->gotoOverviewPage(); break;
        case 7: _t->gotoHistoryPage(); break;
        case 8: _t->gotoReceiveCoinsPage(); break;
        case 9: _t->gotoSendCoinsPage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->gotoSendCoinsPage(); break;
        case 11: _t->gotoSignMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->gotoSignMessageTab(); break;
        case 13: _t->gotoVerifyMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->gotoVerifyMessageTab(); break;
        case 15: _t->processNewTransaction((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 16: _t->encryptWallet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->backupWallet(); break;
        case 18: _t->changePassphrase(); break;
        case 19: _t->unlockWallet(); break;
        case 20: _t->usedSendingAddresses(); break;
        case 21: _t->usedReceivingAddresses(); break;
        case 22: _t->updateEncryptionStatus(); break;
        case 23: _t->showProgress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 24: _t->requestedSyncWarningInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WalletView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletView::showNormalIfMinimized)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WalletView::*)(const QString & , const QString & , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletView::message)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WalletView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletView::encryptionStatusChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WalletView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletView::hdEnabledStatusChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WalletView::*)(const QString & , int , const CAmount & , const QString & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletView::incomingTransaction)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (WalletView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletView::outOfSyncWarningClicked)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WalletView::staticMetaObject = { {
    QMetaObject::SuperData::link<QStackedWidget::staticMetaObject>(),
    qt_meta_stringdata_WalletView.data,
    qt_meta_data_WalletView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WalletView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WalletView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WalletView.stringdata0))
        return static_cast<void*>(this);
    return QStackedWidget::qt_metacast(_clname);
}

int WalletView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void WalletView::showNormalIfMinimized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WalletView::message(const QString & _t1, const QString & _t2, unsigned int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WalletView::encryptionStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WalletView::hdEnabledStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void WalletView::incomingTransaction(const QString & _t1, int _t2, const CAmount & _t3, const QString & _t4, const QString & _t5, const QString & _t6, const QString & _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void WalletView::outOfSyncWarningClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
