/****************************************************************************
** Meta object code from reading C++ file 'newrundialog.h'
**
** Created: Tue Apr 16 15:13:34 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "newrundialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newrundialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewRunDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   14,   13,   13, 0x08,
      44,   38,   13,   13, 0x08,
      68,   13,   13,   13, 0x08,
      77,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NewRunDialog[] = {
    "NewRunDialog\0\0checked\0GSToggled(bool)\0"
    "state\0scriptStateChanged(int)\0advOpt()\0"
    "help()\0"
};

const QMetaObject NewRunDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewRunDialog,
      qt_meta_data_NewRunDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewRunDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewRunDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewRunDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewRunDialog))
        return static_cast<void*>(const_cast< NewRunDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewRunDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: GSToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: scriptStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: advOpt(); break;
        case 3: help(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
