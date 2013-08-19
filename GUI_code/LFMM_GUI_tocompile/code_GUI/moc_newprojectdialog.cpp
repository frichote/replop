/****************************************************************************
** Meta object code from reading C++ file 'newprojectdialog.h'
**
** Created: Fri May 24 13:23:02 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "newprojectdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newprojectdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewProjectDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      25,   17,   17,   17, 0x08,
      38,   17,   17,   17, 0x08,
      51,   17,   17,   17, 0x08,
      67,   17,   17,   17, 0x08,
      84,   17,   17,   17, 0x08,
      98,   17,   17,   17, 0x08,
     115,   17,   17,   17, 0x08,
     133,   17,   17,   17, 0x08,
     144,   17,   17,   17, 0x08,
     158,   17,   17,   17, 0x08,
     173,   17,   17,   17, 0x08,
     185,   17,   17,   17, 0x08,
     200,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NewProjectDialog[] = {
    "NewProjectDialog\0\0help()\0browsePath()\0"
    "browseData()\0browseGeoData()\0"
    "browseNameData()\0dataChanged()\0"
    "geoDataChanged()\0nameDataChanged()\0"
    "viewData()\0viewGeoData()\0viewNameData()\0"
    "dataClose()\0geoDataClose()\0nameDataClose()\0"
};

void NewProjectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewProjectDialog *_t = static_cast<NewProjectDialog *>(_o);
        switch (_id) {
        case 0: _t->help(); break;
        case 1: _t->browsePath(); break;
        case 2: _t->browseData(); break;
        case 3: _t->browseGeoData(); break;
        case 4: _t->browseNameData(); break;
        case 5: _t->dataChanged(); break;
        case 6: _t->geoDataChanged(); break;
        case 7: _t->nameDataChanged(); break;
        case 8: _t->viewData(); break;
        case 9: _t->viewGeoData(); break;
        case 10: _t->viewNameData(); break;
        case 11: _t->dataClose(); break;
        case 12: _t->geoDataClose(); break;
        case 13: _t->nameDataClose(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData NewProjectDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NewProjectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewProjectDialog,
      qt_meta_data_NewProjectDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewProjectDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewProjectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewProjectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewProjectDialog))
        return static_cast<void*>(const_cast< NewProjectDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewProjectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
