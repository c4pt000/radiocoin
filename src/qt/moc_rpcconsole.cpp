/****************************************************************************
** Meta object code from reading C++ file 'rpcconsole.h'
**
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "qt/rpcconsole.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rpcconsole.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RPCConsole_t {
    QByteArrayData data[65];
    char stringdata0[874];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RPCConsole_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RPCConsole_t qt_meta_stringdata_RPCConsole = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RPCConsole"
QT_MOC_LITERAL(1, 11, 10), // "cmdRequest"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "command"
QT_MOC_LITERAL(4, 31, 18), // "const WalletModel*"
QT_MOC_LITERAL(5, 50, 12), // "wallet_model"
QT_MOC_LITERAL(6, 63, 25), // "on_lineEdit_returnPressed"
QT_MOC_LITERAL(7, 89, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(8, 117, 5), // "index"
QT_MOC_LITERAL(9, 123, 33), // "on_openDebugLogfileButton_cli..."
QT_MOC_LITERAL(10, 157, 29), // "on_sldGraphRange_valueChanged"
QT_MOC_LITERAL(11, 187, 5), // "value"
QT_MOC_LITERAL(12, 193, 18), // "updateTrafficStats"
QT_MOC_LITERAL(13, 212, 12), // "totalBytesIn"
QT_MOC_LITERAL(14, 225, 13), // "totalBytesOut"
QT_MOC_LITERAL(15, 239, 11), // "resizeEvent"
QT_MOC_LITERAL(16, 251, 13), // "QResizeEvent*"
QT_MOC_LITERAL(17, 265, 5), // "event"
QT_MOC_LITERAL(18, 271, 9), // "showEvent"
QT_MOC_LITERAL(19, 281, 11), // "QShowEvent*"
QT_MOC_LITERAL(20, 293, 9), // "hideEvent"
QT_MOC_LITERAL(21, 303, 11), // "QHideEvent*"
QT_MOC_LITERAL(22, 315, 25), // "showPeersTableContextMenu"
QT_MOC_LITERAL(23, 341, 5), // "point"
QT_MOC_LITERAL(24, 347, 23), // "showBanTableContextMenu"
QT_MOC_LITERAL(25, 371, 28), // "showOrHideBanTableIfRequired"
QT_MOC_LITERAL(26, 400, 17), // "clearSelectedNode"
QT_MOC_LITERAL(27, 418, 5), // "clear"
QT_MOC_LITERAL(28, 424, 12), // "clearHistory"
QT_MOC_LITERAL(29, 437, 10), // "fontBigger"
QT_MOC_LITERAL(30, 448, 11), // "fontSmaller"
QT_MOC_LITERAL(31, 460, 11), // "setFontSize"
QT_MOC_LITERAL(32, 472, 7), // "newSize"
QT_MOC_LITERAL(33, 480, 7), // "message"
QT_MOC_LITERAL(34, 488, 8), // "category"
QT_MOC_LITERAL(35, 497, 3), // "msg"
QT_MOC_LITERAL(36, 501, 4), // "html"
QT_MOC_LITERAL(37, 506, 17), // "setNumConnections"
QT_MOC_LITERAL(38, 524, 5), // "count"
QT_MOC_LITERAL(39, 530, 16), // "setNetworkActive"
QT_MOC_LITERAL(40, 547, 13), // "networkActive"
QT_MOC_LITERAL(41, 561, 12), // "setNumBlocks"
QT_MOC_LITERAL(42, 574, 9), // "blockDate"
QT_MOC_LITERAL(43, 584, 21), // "nVerificationProgress"
QT_MOC_LITERAL(44, 606, 7), // "headers"
QT_MOC_LITERAL(45, 614, 14), // "setMempoolSize"
QT_MOC_LITERAL(46, 629, 11), // "numberOfTxs"
QT_MOC_LITERAL(47, 641, 6), // "size_t"
QT_MOC_LITERAL(48, 648, 8), // "dynUsage"
QT_MOC_LITERAL(49, 657, 13), // "browseHistory"
QT_MOC_LITERAL(50, 671, 6), // "offset"
QT_MOC_LITERAL(51, 678, 11), // "scrollToEnd"
QT_MOC_LITERAL(52, 690, 12), // "peerSelected"
QT_MOC_LITERAL(53, 703, 14), // "QItemSelection"
QT_MOC_LITERAL(54, 718, 8), // "selected"
QT_MOC_LITERAL(55, 727, 10), // "deselected"
QT_MOC_LITERAL(56, 738, 23), // "peerLayoutAboutToChange"
QT_MOC_LITERAL(57, 762, 17), // "peerLayoutChanged"
QT_MOC_LITERAL(58, 780, 22), // "disconnectSelectedNode"
QT_MOC_LITERAL(59, 803, 15), // "banSelectedNode"
QT_MOC_LITERAL(60, 819, 7), // "bantime"
QT_MOC_LITERAL(61, 827, 17), // "unbanSelectedNode"
QT_MOC_LITERAL(62, 845, 11), // "setTabFocus"
QT_MOC_LITERAL(63, 857, 8), // "TabTypes"
QT_MOC_LITERAL(64, 866, 7) // "tabType"

    },
    "RPCConsole\0cmdRequest\0\0command\0"
    "const WalletModel*\0wallet_model\0"
    "on_lineEdit_returnPressed\0"
    "on_tabWidget_currentChanged\0index\0"
    "on_openDebugLogfileButton_clicked\0"
    "on_sldGraphRange_valueChanged\0value\0"
    "updateTrafficStats\0totalBytesIn\0"
    "totalBytesOut\0resizeEvent\0QResizeEvent*\0"
    "event\0showEvent\0QShowEvent*\0hideEvent\0"
    "QHideEvent*\0showPeersTableContextMenu\0"
    "point\0showBanTableContextMenu\0"
    "showOrHideBanTableIfRequired\0"
    "clearSelectedNode\0clear\0clearHistory\0"
    "fontBigger\0fontSmaller\0setFontSize\0"
    "newSize\0message\0category\0msg\0html\0"
    "setNumConnections\0count\0setNetworkActive\0"
    "networkActive\0setNumBlocks\0blockDate\0"
    "nVerificationProgress\0headers\0"
    "setMempoolSize\0numberOfTxs\0size_t\0"
    "dynUsage\0browseHistory\0offset\0scrollToEnd\0"
    "peerSelected\0QItemSelection\0selected\0"
    "deselected\0peerLayoutAboutToChange\0"
    "peerLayoutChanged\0disconnectSelectedNode\0"
    "banSelectedNode\0bantime\0unbanSelectedNode\0"
    "setTabFocus\0TabTypes\0tabType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RPCConsole[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  179,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  184,    2, 0x08 /* Private */,
       7,    1,  185,    2, 0x08 /* Private */,
       9,    0,  188,    2, 0x08 /* Private */,
      10,    1,  189,    2, 0x08 /* Private */,
      12,    2,  192,    2, 0x08 /* Private */,
      15,    1,  197,    2, 0x08 /* Private */,
      18,    1,  200,    2, 0x08 /* Private */,
      20,    1,  203,    2, 0x08 /* Private */,
      22,    1,  206,    2, 0x08 /* Private */,
      24,    1,  209,    2, 0x08 /* Private */,
      25,    0,  212,    2, 0x08 /* Private */,
      26,    0,  213,    2, 0x08 /* Private */,
      27,    1,  214,    2, 0x0a /* Public */,
      27,    0,  217,    2, 0x2a /* Public | MethodCloned */,
      29,    0,  218,    2, 0x0a /* Public */,
      30,    0,  219,    2, 0x0a /* Public */,
      31,    1,  220,    2, 0x0a /* Public */,
      33,    2,  223,    2, 0x0a /* Public */,
      33,    3,  228,    2, 0x0a /* Public */,
      37,    1,  235,    2, 0x0a /* Public */,
      39,    1,  238,    2, 0x0a /* Public */,
      41,    4,  241,    2, 0x0a /* Public */,
      45,    2,  250,    2, 0x0a /* Public */,
      49,    1,  255,    2, 0x0a /* Public */,
      51,    0,  258,    2, 0x0a /* Public */,
      52,    2,  259,    2, 0x0a /* Public */,
      56,    0,  264,    2, 0x0a /* Public */,
      57,    0,  265,    2, 0x0a /* Public */,
      58,    0,  266,    2, 0x0a /* Public */,
      59,    1,  267,    2, 0x0a /* Public */,
      61,    0,  270,    2, 0x0a /* Public */,
      62,    1,  271,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::ULongLong,   13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 19,   17,
    QMetaType::Void, 0x80000000 | 21,   17,
    QMetaType::Void, QMetaType::QPoint,   23,
    QMetaType::Void, QMetaType::QPoint,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   34,   35,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,   34,   33,   36,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void, QMetaType::Bool,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::QDateTime, QMetaType::Double, QMetaType::Bool,   38,   42,   43,   44,
    QMetaType::Void, QMetaType::Long, 0x80000000 | 47,   46,   48,
    QMetaType::Void, QMetaType::Int,   50,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 53, 0x80000000 | 53,   54,   55,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   60,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 63,   64,

       0        // eod
};

void RPCConsole::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RPCConsole *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cmdRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const WalletModel*(*)>(_a[2]))); break;
        case 1: _t->on_lineEdit_returnPressed(); break;
        case 2: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_openDebugLogfileButton_clicked(); break;
        case 4: _t->on_sldGraphRange_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateTrafficStats((*reinterpret_cast< quint64(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2]))); break;
        case 6: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 7: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 8: _t->hideEvent((*reinterpret_cast< QHideEvent*(*)>(_a[1]))); break;
        case 9: _t->showPeersTableContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 10: _t->showBanTableContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 11: _t->showOrHideBanTableIfRequired(); break;
        case 12: _t->clearSelectedNode(); break;
        case 13: _t->clear((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->clear(); break;
        case 15: _t->fontBigger(); break;
        case 16: _t->fontSmaller(); break;
        case 17: _t->setFontSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->message((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 19: _t->message((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 20: _t->setNumConnections((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->setNetworkActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->setNumBlocks((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 23: _t->setMempoolSize((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2]))); break;
        case 24: _t->browseHistory((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->scrollToEnd(); break;
        case 26: _t->peerSelected((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 27: _t->peerLayoutAboutToChange(); break;
        case 28: _t->peerLayoutChanged(); break;
        case 29: _t->disconnectSelectedNode(); break;
        case 30: _t->banSelectedNode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->unbanSelectedNode(); break;
        case 32: _t->setTabFocus((*reinterpret_cast< TabTypes(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RPCConsole::*)(const QString & , const WalletModel * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RPCConsole::cmdRequest)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RPCConsole::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_RPCConsole.data,
    qt_meta_data_RPCConsole,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RPCConsole::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RPCConsole::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RPCConsole.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RPCConsole::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    }
    return _id;
}

// SIGNAL 0
void RPCConsole::cmdRequest(const QString & _t1, const WalletModel * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
