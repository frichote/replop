/****************************************************************************
** Meta object code from reading C++ file 'newprojectdialog.h'
**
** Created: Tue Apr 16 15:13:34 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "newprojectdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newprojectdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewProjectDialog[] = {

 // content:
       5,       // revision
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

const QMetaObject NewProjectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewProjectDialog,
      qt_meta_data_NewProjectDialog, 0 }
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
        switch (_id) {
        case 0: help(); break;
        case 1: browsePath(); break;
        case 2: browseData(); break;
        case 3: browseGeoData(); break;
        case 4: browseNameData(); break;
        case 5: dataChanged(); break;
        case 6: geoDataChanged(); break;
        case 7: nameDataChanged(); break;
        case 8: viewData(); break;
        case 9: viewGeoData(); break;
        case 10: viewNameData(); break;
        case 11: dataClose(); break;
        case 12: geoDataClose(); break;
        case 13: nameDataClose(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
