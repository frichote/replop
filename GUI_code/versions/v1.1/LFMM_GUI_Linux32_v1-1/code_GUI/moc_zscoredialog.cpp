/****************************************************************************
** Meta object code from reading C++ file 'zscoredialog.h'
**
** Created: Tue Apr 16 15:13:37 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "zscoredialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zscoredialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ZscoreDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   25,   13,   13, 0x08,
      64,   13,   13,   13, 0x08,
      84,   13,   13,   13, 0x08,
     114,   13,  109,   13, 0x08,
     134,   13,  109,   13, 0x08,
     154,   13,  109,   13, 0x08,
     175,   13,  109,   13, 0x08,
     197,   13,  109,   13, 0x08,
     214,   13,  109,   13, 0x08,
     232,   13,   13,   13, 0x08,
     258,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ZscoreDialog[] = {
    "ZscoreDialog\0\0finished()\0item\0"
    "loadZscoreItem(QTableWidgetItem*)\0"
    "updateZscoreTable()\0updateRunToZscoreTable()\0"
    "bool\0updateZscoreRange()\0updatePvalueRange()\0"
    "updatelPvalueRange()\0updatePositionRange()\0"
    "updateChrRange()\0updateNameRange()\0"
    "exportZscoreTableToText()\0help()\0"
};

const QMetaObject ZscoreDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ZscoreDialog,
      qt_meta_data_ZscoreDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ZscoreDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ZscoreDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ZscoreDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ZscoreDialog))
        return static_cast<void*>(const_cast< ZscoreDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ZscoreDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: finished(); break;
        case 1: loadZscoreItem((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: updateZscoreTable(); break;
        case 3: updateRunToZscoreTable(); break;
        case 4: { bool _r = updateZscoreRange();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = updatePvalueRange();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = updatelPvalueRange();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = updatePositionRange();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = updateChrRange();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { bool _r = updateNameRange();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: exportZscoreTableToText(); break;
        case 11: help(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ZscoreDialog::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
