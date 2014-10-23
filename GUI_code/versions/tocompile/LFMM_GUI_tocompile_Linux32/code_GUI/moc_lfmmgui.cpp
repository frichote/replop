/****************************************************************************
** Meta object code from reading C++ file 'lfmmgui.h'
**
** Created: Fri May 24 13:23:08 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "lfmmgui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lfmmgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LFMMGUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      20,    8,    8,    8, 0x08,
      33,    8,    8,    8, 0x08,
      47,    8,    8,    8, 0x08,
      59,    8,    8,    8, 0x08,
      74,    8,    8,    8, 0x08,
      88,    8,    8,    8, 0x08,
      99,    8,    8,    8, 0x08,
     119,    8,    8,    8, 0x08,
     126,    8,    8,    8, 0x08,
     135,    8,    8,    8, 0x08,
     141,    8,    8,    8, 0x08,
     149,    8,    8,    8, 0x08,
     167,    8,    8,    8, 0x08,
     183,    8,    8,    8, 0x08,
     191,    8,    8,    8, 0x08,
     210,  205,    8,    8, 0x08,
     256,  244,    8,    8, 0x08,
     294,  205,    8,    8, 0x08,
     325,  317,    8,    8, 0x08,
     347,    8,    8,    8, 0x08,
     362,    8,    8,    8, 0x08,
     379,    8,    8,    8, 0x08,
     402,    8,    8,    8, 0x08,
     428,  422,    8,    8, 0x08,
     481,  461,    8,    8, 0x08,
     519,    8,    8,    8, 0x08,
     542,    8,    8,    8, 0x08,
     566,    8,    8,    8, 0x08,
     588,  579,    8,    8, 0x08,
     628,    8,    8,    8, 0x0a,
     646,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LFMMGUI[] = {
    "LFMMGUI\0\0openData()\0newProject()\0"
    "openProject()\0removeRun()\0closeProject()\0"
    "saveProject()\0openText()\0openRecentProject()\0"
    "quit()\0modify()\0run()\0abort()\0"
    "clearInfoWindow()\0openReference()\0"
    "about()\0updateMenus()\0item\0"
    "loadSummaryRes(QTableWidgetItem*)\0"
    "item,column\0loadProjectItem(QTreeWidgetItem*,int)\0"
    "deleteRunItem(QString)\0dirName\0"
    "removeRunDir(QString)\0notModifying()\0"
    "notSummarizing()\0notSummarizingZscore()\0"
    "exportTableToText()\0error\0"
    "cleError(QProcess::ProcessError)\0"
    "exitCode,exitStatus\0"
    "cleFinished(int,QProcess::ExitStatus)\0"
    "cleReadStandardError()\0cleReadStandardOutput()\0"
    "cleStarted()\0newState\0"
    "cleStateChanged(QProcess::ProcessState)\0"
    "createManhattan()\0createGreenManhattan()\0"
};

void LFMMGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LFMMGUI *_t = static_cast<LFMMGUI *>(_o);
        switch (_id) {
        case 0: _t->openData(); break;
        case 1: _t->newProject(); break;
        case 2: _t->openProject(); break;
        case 3: _t->removeRun(); break;
        case 4: _t->closeProject(); break;
        case 5: _t->saveProject(); break;
        case 6: _t->openText(); break;
        case 7: _t->openRecentProject(); break;
        case 8: _t->quit(); break;
        case 9: _t->modify(); break;
        case 10: _t->run(); break;
        case 11: _t->abort(); break;
        case 12: _t->clearInfoWindow(); break;
        case 13: _t->openReference(); break;
        case 14: _t->about(); break;
        case 15: _t->updateMenus(); break;
        case 16: _t->loadSummaryRes((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 17: _t->loadProjectItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->deleteRunItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->removeRunDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->notModifying(); break;
        case 21: _t->notSummarizing(); break;
        case 22: _t->notSummarizingZscore(); break;
        case 23: _t->exportTableToText(); break;
        case 24: _t->cleError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 25: _t->cleFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 26: _t->cleReadStandardError(); break;
        case 27: _t->cleReadStandardOutput(); break;
        case 28: _t->cleStarted(); break;
        case 29: _t->cleStateChanged((*reinterpret_cast< QProcess::ProcessState(*)>(_a[1]))); break;
        case 30: _t->createManhattan(); break;
        case 31: _t->createGreenManhattan(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LFMMGUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LFMMGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_LFMMGUI,
      qt_meta_data_LFMMGUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LFMMGUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LFMMGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LFMMGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LFMMGUI))
        return static_cast<void*>(const_cast< LFMMGUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int LFMMGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
