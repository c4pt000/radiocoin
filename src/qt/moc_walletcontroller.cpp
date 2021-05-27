/****************************************************************************
** Meta object code from reading C++ file 'walletcontroller.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "qt/walletcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'walletcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WalletController_t {
    QByteArrayData data[11];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WalletController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WalletController_t qt_meta_stringdata_WalletController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "WalletController"
QT_MOC_LITERAL(1, 17, 11), // "walletAdded"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "WalletModel*"
QT_MOC_LITERAL(4, 43, 12), // "wallet_model"
QT_MOC_LITERAL(5, 56, 13), // "walletRemoved"
QT_MOC_LITERAL(6, 70, 9), // "coinsSent"
QT_MOC_LITERAL(7, 80, 18), // "SendCoinsRecipient"
QT_MOC_LITERAL(8, 99, 9), // "recipient"
QT_MOC_LITERAL(9, 109, 11), // "transaction"
QT_MOC_LITERAL(10, 121, 9) // "addWallet"

    },
    "WalletController\0walletAdded\0\0"
    "WalletModel*\0wallet_model\0walletRemoved\0"
    "coinsSent\0SendCoinsRecipient\0recipient\0"
    "transaction\0addWallet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WalletController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,
       6,    3,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 7, QMetaType::QByteArray,    4,    8,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void WalletController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WalletController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->walletAdded((*reinterpret_cast< WalletModel*(*)>(_a[1]))); break;
        case 1: _t->walletRemoved((*reinterpret_cast< WalletModel*(*)>(_a[1]))); break;
        case 2: _t->coinsSent((*reinterpret_cast< WalletModel*(*)>(_a[1])),(*reinterpret_cast< SendCoinsRecipient(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 3: _t->addWallet((*reinterpret_cast< WalletModel*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WalletModel* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WalletModel* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WalletModel* >(); break;
            }
            break;
        case 3:
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
            using _t = void (WalletController::*)(WalletModel * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletController::walletAdded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WalletController::*)(WalletModel * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletController::walletRemoved)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WalletController::*)(WalletModel * , SendCoinsRecipient , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WalletController::coinsSent)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WalletController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_WalletController.data,
    qt_meta_data_WalletController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WalletController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WalletController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WalletController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WalletController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void WalletController::walletAdded(WalletModel * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WalletController::walletRemoved(WalletModel * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WalletController::coinsSent(WalletModel * _t1, SendCoinsRecipient _t2, QByteArray _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_OpenWalletActivity_t {
    QByteArrayData data[11];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenWalletActivity_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenWalletActivity_t qt_meta_stringdata_OpenWalletActivity = {
    {
QT_MOC_LITERAL(0, 0, 18), // "OpenWalletActivity"
QT_MOC_LITERAL(1, 19, 7), // "message"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 17), // "QMessageBox::Icon"
QT_MOC_LITERAL(4, 46, 4), // "icon"
QT_MOC_LITERAL(5, 51, 4), // "text"
QT_MOC_LITERAL(6, 56, 8), // "finished"
QT_MOC_LITERAL(7, 65, 6), // "opened"
QT_MOC_LITERAL(8, 72, 12), // "WalletModel*"
QT_MOC_LITERAL(9, 85, 12), // "wallet_model"
QT_MOC_LITERAL(10, 98, 4) // "open"

    },
    "OpenWalletActivity\0message\0\0"
    "QMessageBox::Icon\0icon\0text\0finished\0"
    "opened\0WalletModel*\0wallet_model\0open"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenWalletActivity[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       6,    0,   39,    2, 0x06 /* Public */,
       7,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void OpenWalletActivity::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OpenWalletActivity *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->message((*reinterpret_cast< QMessageBox::Icon(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->finished(); break;
        case 2: _t->opened((*reinterpret_cast< WalletModel*(*)>(_a[1]))); break;
        case 3: _t->open(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
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
            using _t = void (OpenWalletActivity::*)(QMessageBox::Icon , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenWalletActivity::message)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OpenWalletActivity::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenWalletActivity::finished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (OpenWalletActivity::*)(WalletModel * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OpenWalletActivity::opened)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OpenWalletActivity::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_OpenWalletActivity.data,
    qt_meta_data_OpenWalletActivity,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OpenWalletActivity::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenWalletActivity::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OpenWalletActivity.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OpenWalletActivity::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void OpenWalletActivity::message(QMessageBox::Icon _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OpenWalletActivity::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void OpenWalletActivity::opened(WalletModel * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
