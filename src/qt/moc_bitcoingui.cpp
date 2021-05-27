/****************************************************************************
** Meta object code from reading C++ file 'bitcoingui.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "qt/bitcoingui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bitcoingui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BitcoinGUI_t {
    QByteArrayData data[62];
    char stringdata0[833];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BitcoinGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BitcoinGUI_t qt_meta_stringdata_BitcoinGUI = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BitcoinGUI"
QT_MOC_LITERAL(1, 11, 11), // "receivedURI"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "uri"
QT_MOC_LITERAL(4, 28, 12), // "consoleShown"
QT_MOC_LITERAL(5, 41, 11), // "RPCConsole*"
QT_MOC_LITERAL(6, 53, 7), // "console"
QT_MOC_LITERAL(7, 61, 17), // "setNumConnections"
QT_MOC_LITERAL(8, 79, 5), // "count"
QT_MOC_LITERAL(9, 85, 16), // "setNetworkActive"
QT_MOC_LITERAL(10, 102, 13), // "networkActive"
QT_MOC_LITERAL(11, 116, 12), // "setNumBlocks"
QT_MOC_LITERAL(12, 129, 9), // "blockDate"
QT_MOC_LITERAL(13, 139, 21), // "nVerificationProgress"
QT_MOC_LITERAL(14, 161, 7), // "headers"
QT_MOC_LITERAL(15, 169, 7), // "message"
QT_MOC_LITERAL(16, 177, 5), // "title"
QT_MOC_LITERAL(17, 183, 5), // "style"
QT_MOC_LITERAL(18, 189, 5), // "bool*"
QT_MOC_LITERAL(19, 195, 3), // "ret"
QT_MOC_LITERAL(20, 199, 16), // "setCurrentWallet"
QT_MOC_LITERAL(21, 216, 12), // "WalletModel*"
QT_MOC_LITERAL(22, 229, 12), // "wallet_model"
QT_MOC_LITERAL(23, 242, 31), // "setCurrentWalletBySelectorIndex"
QT_MOC_LITERAL(24, 274, 5), // "index"
QT_MOC_LITERAL(25, 280, 18), // "updateWalletStatus"
QT_MOC_LITERAL(26, 299, 20), // "handlePaymentRequest"
QT_MOC_LITERAL(27, 320, 18), // "SendCoinsRecipient"
QT_MOC_LITERAL(28, 339, 9), // "recipient"
QT_MOC_LITERAL(29, 349, 19), // "incomingTransaction"
QT_MOC_LITERAL(30, 369, 4), // "date"
QT_MOC_LITERAL(31, 374, 4), // "unit"
QT_MOC_LITERAL(32, 379, 7), // "CAmount"
QT_MOC_LITERAL(33, 387, 6), // "amount"
QT_MOC_LITERAL(34, 394, 4), // "type"
QT_MOC_LITERAL(35, 399, 7), // "address"
QT_MOC_LITERAL(36, 407, 5), // "label"
QT_MOC_LITERAL(37, 413, 10), // "walletName"
QT_MOC_LITERAL(38, 424, 16), // "gotoOverviewPage"
QT_MOC_LITERAL(39, 441, 15), // "gotoHistoryPage"
QT_MOC_LITERAL(40, 457, 20), // "gotoReceiveCoinsPage"
QT_MOC_LITERAL(41, 478, 17), // "gotoSendCoinsPage"
QT_MOC_LITERAL(42, 496, 4), // "addr"
QT_MOC_LITERAL(43, 501, 18), // "gotoSignMessageTab"
QT_MOC_LITERAL(44, 520, 20), // "gotoVerifyMessageTab"
QT_MOC_LITERAL(45, 541, 11), // "openClicked"
QT_MOC_LITERAL(46, 553, 14), // "optionsClicked"
QT_MOC_LITERAL(47, 568, 12), // "aboutClicked"
QT_MOC_LITERAL(48, 581, 15), // "showDebugWindow"
QT_MOC_LITERAL(49, 597, 30), // "showDebugWindowActivateConsole"
QT_MOC_LITERAL(50, 628, 22), // "showHelpMessageClicked"
QT_MOC_LITERAL(51, 651, 17), // "trayIconActivated"
QT_MOC_LITERAL(52, 669, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(53, 703, 6), // "reason"
QT_MOC_LITERAL(54, 710, 21), // "showNormalIfMinimized"
QT_MOC_LITERAL(55, 732, 13), // "fToggleHidden"
QT_MOC_LITERAL(56, 746, 12), // "toggleHidden"
QT_MOC_LITERAL(57, 759, 14), // "detectShutdown"
QT_MOC_LITERAL(58, 774, 12), // "showProgress"
QT_MOC_LITERAL(59, 787, 9), // "nProgress"
QT_MOC_LITERAL(60, 797, 18), // "setTrayIconVisible"
QT_MOC_LITERAL(61, 816, 16) // "showModalOverlay"

    },
    "BitcoinGUI\0receivedURI\0\0uri\0consoleShown\0"
    "RPCConsole*\0console\0setNumConnections\0"
    "count\0setNetworkActive\0networkActive\0"
    "setNumBlocks\0blockDate\0nVerificationProgress\0"
    "headers\0message\0title\0style\0bool*\0ret\0"
    "setCurrentWallet\0WalletModel*\0"
    "wallet_model\0setCurrentWalletBySelectorIndex\0"
    "index\0updateWalletStatus\0handlePaymentRequest\0"
    "SendCoinsRecipient\0recipient\0"
    "incomingTransaction\0date\0unit\0CAmount\0"
    "amount\0type\0address\0label\0walletName\0"
    "gotoOverviewPage\0gotoHistoryPage\0"
    "gotoReceiveCoinsPage\0gotoSendCoinsPage\0"
    "addr\0gotoSignMessageTab\0gotoVerifyMessageTab\0"
    "openClicked\0optionsClicked\0aboutClicked\0"
    "showDebugWindow\0showDebugWindowActivateConsole\0"
    "showHelpMessageClicked\0trayIconActivated\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0showNormalIfMinimized\0fToggleHidden\0"
    "toggleHidden\0detectShutdown\0showProgress\0"
    "nProgress\0setTrayIconVisible\0"
    "showModalOverlay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BitcoinGUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  189,    2, 0x06 /* Public */,
       4,    1,  192,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,  195,    2, 0x0a /* Public */,
       9,    1,  198,    2, 0x0a /* Public */,
      11,    4,  201,    2, 0x0a /* Public */,
      15,    4,  210,    2, 0x0a /* Public */,
      15,    3,  219,    2, 0x2a /* Public | MethodCloned */,
      20,    1,  226,    2, 0x0a /* Public */,
      23,    1,  229,    2, 0x0a /* Public */,
      25,    0,  232,    2, 0x0a /* Public */,
      26,    1,  233,    2, 0x0a /* Public */,
      29,    7,  236,    2, 0x0a /* Public */,
      38,    0,  251,    2, 0x0a /* Public */,
      39,    0,  252,    2, 0x0a /* Public */,
      40,    0,  253,    2, 0x0a /* Public */,
      41,    1,  254,    2, 0x0a /* Public */,
      41,    0,  257,    2, 0x2a /* Public | MethodCloned */,
      43,    1,  258,    2, 0x0a /* Public */,
      43,    0,  261,    2, 0x2a /* Public | MethodCloned */,
      44,    1,  262,    2, 0x0a /* Public */,
      44,    0,  265,    2, 0x2a /* Public | MethodCloned */,
      45,    0,  266,    2, 0x0a /* Public */,
      46,    0,  267,    2, 0x0a /* Public */,
      47,    0,  268,    2, 0x0a /* Public */,
      48,    0,  269,    2, 0x0a /* Public */,
      49,    0,  270,    2, 0x0a /* Public */,
      50,    0,  271,    2, 0x0a /* Public */,
      51,    1,  272,    2, 0x0a /* Public */,
      54,    0,  275,    2, 0x0a /* Public */,
      54,    1,  276,    2, 0x0a /* Public */,
      56,    0,  279,    2, 0x0a /* Public */,
      57,    0,  280,    2, 0x0a /* Public */,
      58,    2,  281,    2, 0x0a /* Public */,
      60,    1,  286,    2, 0x0a /* Public */,
      61,    0,  289,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::QDateTime, QMetaType::Double, QMetaType::Bool,    8,   12,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::UInt, 0x80000000 | 18,   16,   15,   17,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::UInt,   16,   15,   17,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 27,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, 0x80000000 | 32, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   30,   31,   33,   34,   35,   36,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 52,   53,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   55,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   16,   59,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void BitcoinGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BitcoinGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivedURI((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->consoleShown((*reinterpret_cast< RPCConsole*(*)>(_a[1]))); break;
        case 2: _t->setNumConnections((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setNetworkActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setNumBlocks((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 5: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< bool*(*)>(_a[4]))); break;
        case 6: _t->message((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 7: _t->setCurrentWallet((*reinterpret_cast< WalletModel*(*)>(_a[1]))); break;
        case 8: _t->setCurrentWalletBySelectorIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->updateWalletStatus(); break;
        case 10: { bool _r = _t->handlePaymentRequest((*reinterpret_cast< const SendCoinsRecipient(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->incomingTransaction((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const CAmount(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6])),(*reinterpret_cast< const QString(*)>(_a[7]))); break;
        case 12: _t->gotoOverviewPage(); break;
        case 13: _t->gotoHistoryPage(); break;
        case 14: _t->gotoReceiveCoinsPage(); break;
        case 15: _t->gotoSendCoinsPage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->gotoSendCoinsPage(); break;
        case 17: _t->gotoSignMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->gotoSignMessageTab(); break;
        case 19: _t->gotoVerifyMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->gotoVerifyMessageTab(); break;
        case 21: _t->openClicked(); break;
        case 22: _t->optionsClicked(); break;
        case 23: _t->aboutClicked(); break;
        case 24: _t->showDebugWindow(); break;
        case 25: _t->showDebugWindowActivateConsole(); break;
        case 26: _t->showHelpMessageClicked(); break;
        case 27: _t->trayIconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 28: _t->showNormalIfMinimized(); break;
        case 29: _t->showNormalIfMinimized((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->toggleHidden(); break;
        case 31: _t->detectShutdown(); break;
        case 32: _t->showProgress((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 33: _t->setTrayIconVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->showModalOverlay(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BitcoinGUI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BitcoinGUI::receivedURI)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BitcoinGUI::*)(RPCConsole * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BitcoinGUI::consoleShown)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BitcoinGUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_BitcoinGUI.data,
    qt_meta_data_BitcoinGUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BitcoinGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BitcoinGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BitcoinGUI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int BitcoinGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void BitcoinGUI::receivedURI(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BitcoinGUI::consoleShown(RPCConsole * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_UnitDisplayStatusBarControl_t {
    QByteArrayData data[7];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UnitDisplayStatusBarControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UnitDisplayStatusBarControl_t qt_meta_stringdata_UnitDisplayStatusBarControl = {
    {
QT_MOC_LITERAL(0, 0, 27), // "UnitDisplayStatusBarControl"
QT_MOC_LITERAL(1, 28, 17), // "updateDisplayUnit"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 8), // "newUnits"
QT_MOC_LITERAL(4, 56, 15), // "onMenuSelection"
QT_MOC_LITERAL(5, 72, 8), // "QAction*"
QT_MOC_LITERAL(6, 81, 6) // "action"

    },
    "UnitDisplayStatusBarControl\0"
    "updateDisplayUnit\0\0newUnits\0onMenuSelection\0"
    "QAction*\0action"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UnitDisplayStatusBarControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void UnitDisplayStatusBarControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UnitDisplayStatusBarControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateDisplayUnit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onMenuSelection((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UnitDisplayStatusBarControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_meta_stringdata_UnitDisplayStatusBarControl.data,
    qt_meta_data_UnitDisplayStatusBarControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UnitDisplayStatusBarControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UnitDisplayStatusBarControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UnitDisplayStatusBarControl.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int UnitDisplayStatusBarControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
