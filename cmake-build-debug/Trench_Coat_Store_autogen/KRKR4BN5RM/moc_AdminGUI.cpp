/****************************************************************************
** Meta object code from reading C++ file 'AdminGUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../UI/AdminGUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AdminGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdminGUI_t {
    QByteArrayData data[19];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminGUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminGUI_t qt_meta_stringdata_AdminGUI = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AdminGUI"
QT_MOC_LITERAL(1, 9, 17), // "CoatsUpdateSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "addCoatSignal"
QT_MOC_LITERAL(4, 42, 11), // "std::string"
QT_MOC_LITERAL(5, 54, 4), // "size"
QT_MOC_LITERAL(6, 59, 6), // "colour"
QT_MOC_LITERAL(7, 66, 5), // "price"
QT_MOC_LITERAL(8, 72, 8), // "quantity"
QT_MOC_LITERAL(9, 81, 5), // "photo"
QT_MOC_LITERAL(10, 87, 16), // "removeCoatSignal"
QT_MOC_LITERAL(11, 104, 2), // "id"
QT_MOC_LITERAL(12, 107, 16), // "updateCoatSignal"
QT_MOC_LITERAL(13, 124, 20), // "addCoatButtonHandler"
QT_MOC_LITERAL(14, 145, 23), // "removeCoatButtonHandler"
QT_MOC_LITERAL(15, 169, 23), // "updateCoatButtonHandler"
QT_MOC_LITERAL(16, 193, 7), // "addCoat"
QT_MOC_LITERAL(17, 201, 10), // "removeCoat"
QT_MOC_LITERAL(18, 212, 10) // "updateCoat"

    },
    "AdminGUI\0CoatsUpdateSignal\0\0addCoatSignal\0"
    "std::string\0size\0colour\0price\0quantity\0"
    "photo\0removeCoatSignal\0id\0updateCoatSignal\0"
    "addCoatButtonHandler\0removeCoatButtonHandler\0"
    "updateCoatButtonHandler\0addCoat\0"
    "removeCoat\0updateCoat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminGUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    5,   65,    2, 0x06 /* Public */,
      10,    1,   76,    2, 0x06 /* Public */,
      12,    6,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   92,    2, 0x0a /* Public */,
      14,    0,   93,    2, 0x0a /* Public */,
      15,    0,   94,    2, 0x0a /* Public */,
      16,    5,   95,    2, 0x0a /* Public */,
      17,    1,  106,    2, 0x0a /* Public */,
      18,    6,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Double, QMetaType::Int, 0x80000000 | 4,    5,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Double, QMetaType::Int, 0x80000000 | 4,   11,    5,    6,    7,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Double, QMetaType::Int, 0x80000000 | 4,    5,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Double, QMetaType::Int, 0x80000000 | 4,   11,    5,    6,    7,    8,    9,

       0        // eod
};

void AdminGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminGUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CoatsUpdateSignal(); break;
        case 1: _t->addCoatSignal((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< std::string(*)>(_a[5]))); break;
        case 2: _t->removeCoatSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updateCoatSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< std::string(*)>(_a[6]))); break;
        case 4: _t->addCoatButtonHandler(); break;
        case 5: _t->removeCoatButtonHandler(); break;
        case 6: _t->updateCoatButtonHandler(); break;
        case 7: _t->addCoat((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< std::string(*)>(_a[5]))); break;
        case 8: _t->removeCoat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->updateCoat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< std::string(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AdminGUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminGUI::CoatsUpdateSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AdminGUI::*)(std::string , std::string , double , int , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminGUI::addCoatSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AdminGUI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminGUI::removeCoatSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AdminGUI::*)(int , std::string , std::string , double , int , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AdminGUI::updateCoatSignal)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AdminGUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AdminGUI.data,
    qt_meta_data_AdminGUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AdminGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminGUI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AdminGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void AdminGUI::CoatsUpdateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AdminGUI::addCoatSignal(std::string _t1, std::string _t2, double _t3, int _t4, std::string _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AdminGUI::removeCoatSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AdminGUI::updateCoatSignal(int _t1, std::string _t2, std::string _t3, double _t4, int _t5, std::string _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
