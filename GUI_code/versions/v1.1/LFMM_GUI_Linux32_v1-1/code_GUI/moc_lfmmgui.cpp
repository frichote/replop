/****************************************************************************
** Meta object code from reading C++ file 'lfmmgui.h'
**
** Created: Tue Apr 16 15:13:41 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "lfmmgui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lfmmgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LFMMGUI[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
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
     217,  205,    8,    8, 0x08,
     260,  255,    8,    8, 0x08,
     291,  283,    8,    8, 0x08,
     313,    8,    8,    8, 0x08,
     328,    8,    8,    8, 0x08,
     345,    8,    8,    8, 0x08,
     368,    8,    8,    8, 0x08,
     394,  388,    8,    8, 0x08,
     447,  427,    8,    8, 0x08,
     485,    8,    8,    8, 0x08,
     508,    8,    8,    8, 0x08,
     532,    8,    8,    8, 0x08,
     554,  545,    8,    8, 0x08,
     594,    8,    8,    8, 0x0a,
     612,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LFMMGUI[] = {
    "LFMMGUI\0\0openData()\0newProject()\0"
    "openProject()\0removeRun()\0closeProject()\0"
    "saveProject()\0openText()\0openRecentProject()\0"
    "quit()\0modify()\0run()\0abort()\0"
    "clearInfoWindow()\0openReference()\0"
    "about()\0updateMenus()\0item,column\0"
    "loadProjectItem(QTreeWidgetItem*,int)\0"
    "item\0deleteRunItem(QString)\0dirName\0"
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

const QMetaObject LFMMGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_LFMMGUI,
      qt_meta_data_LFMMGUI, 0 }
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
        switch (_id) {
        case 0: openData(); break;
        case 1: newProject(); break;
        case 2: openProject(); break;
        case 3: removeRun(); break;
        case 4: closeProject(); break;
        case 5: saveProject(); break;
        case 6: openText(); break;
        case 7: openRecentProject(); break;
        case 8: quit(); break;
        case 9: modify(); break;
        case 10: run(); break;
        case 11: abort(); break;
        case 12: clearInfoWindow(); break;
        case 13: openReference(); break;
        case 14: about(); break;
        case 15: updateMenus(); break;
        case 16: loadProjectItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: deleteRunItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: removeRunDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: notModifying(); break;
        case 20: notSummarizing(); break;
        case 21: notSummarizingZscore(); break;
        case 22: exportTableToText(); break;
        case 23: cleError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 24: cleFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 25: cleReadStandardError(); break;
        case 26: cleReadStandardOutput(); break;
        case 27: cleStarted(); break;
        case 28: cleStateChanged((*reinterpret_cast< QProcess::ProcessState(*)>(_a[1]))); break;
        case 29: createManhattan(); break;
        case 30: createGreenManhattan(); break;
        default: ;
        }
        _id -= 31;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
