#ifndef LFMMGUI_H
#define LFMMGUI_H

#include <QDesktopServices>
#include <QMainWindow>
#include <QProcess>
#include "project.h"
#include "treeinfo.h"
#include "summarydialog.h"
#include "zscoredialog.h"

class QAction;
class QCloseEvent;
class QMenu;
class QSignalMapper;
class QTableWidget;
class QTextEdit;
class QToolBar;
class QTreeWidgetItem;
class QTableWidgetItem;
class QWorkspace;

class DataWindow;
//class GraphWindow;
class TextWindow;
class TreeWidget;

#define MAX_RECENT_PROJECTS 8

class LFMMGUI : public QMainWindow
{
    Q_OBJECT

public:
    LFMMGUI(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~LFMMGUI();

public:

protected:
	// Close event. If process is running, warning box. Close summaryDialog.
	void closeEvent(QCloseEvent *event); 

private slots:
	// Find the name of the data file and call loadData().
	void openData();
	// Create and show newProjectDialog, close previous project, fill project structure, 
	// 	save project (create .tp), load new project and update menus.
	void newProject();
	// Open QFileDialog. If project already opened, return.
	//		     else close previous project, load project and updateMenus
	void openProject();
	// Save project, clear summaryDialog, clear worspace and updateMenus.
	void removeRun();
	// Save project, clear summaryDialog, clear worspace and updateMenus.
	void closeProject();
	// Write project settings and updateMenus.
	void saveProject();
	// Find the name of the graphical file and call loadGraph().
	//void openGraph();
	// Find the name of the texstual file and call loadText().
	void openText();
	// same as openProject but manage removed recent project and update recent project list
	void openRecentProject();
	// close summaryDialog and call close()
	void quit();
	// modify Voronoi graph (Useless)
	void modify();
	// create and open newRunDialog, set newRunDialog button, set the parameter to previous values
	//	if possible, fill newrun struct and call performMRun().
	void run();
	// warning message, kill running process, change currMRun, and remove RunDir
	void abort();
	void clearInfoWindow();
	void openReference();
	// create and open aboutDialog
	void about();
	// update File Menu, Project Menu, and Window menu
	void updateMenus();
	// ...
	//void updateWindowMenu();
	// call loadGraph with given file
	void loadSummaryRes(QTableWidgetItem *item);
	void loadProjectItem(QTreeWidgetItem *item, int column);
	// remove Run Items and call removeRunDir
	void deleteRunItem(QString item);
	// ...
	void removeRunDir(QString dirName);
	// ... and updateMenus
	void notModifying();
	// summaryOpened false and updateMenus
	void notSummarizing();
	// zscoreOpened false and updateMenus
	void notSummarizingZscore();
	// ...
	void exportTableToText();
	// manage all errors from cle process
	void cleError(QProcess::ProcessError error);
	// exit code, currMRun++, add run to project and launch next run.
	void cleFinished(int exitCode, QProcess::ExitStatus exitStatus);
	// empty
	void cleReadStandardError();
	// ...
	void cleReadStandardOutput();
	// output started
	void cleStarted();
	// ... and updateMenus
	void cleStateChanged(QProcess::ProcessState newState);

public slots:
	void createManhattan();
	void createGreenManhattan();

private:
	bool checkUrl(const QUrl &url);
	// create and link all actions for File, Project, Tools, View, Windows, and Help
	void createActions();
	// for File, Project, Tools, View, Window and Help
	void createMenus();
	// for File, Project, Tools, View, Window and Help
	void createToolBars();
	// ...
	void createStatusBar();
	// Project Dock and Information Dock
	void createDockWindows();

	// ... and add to workspace
	DataWindow *createDataWindow(int EC = 0, int ER = 0);
	// find data window among the windows
	DataWindow *findDataWindow(const QString &fileName);

	// ... and add to workspace
	TextWindow *createTextWindow();
	// find Text window among the windows
	TextWindow *findTextWindow(const QString &fileName);

	// find data windows, create and show + status message
	bool loadData(const QString &fullDataPath, int EC = 0, int ER = 0);
	// read project settings, populate project tree widgets, load data, init summary, set current 
	// 	project and set default rum parameters
	bool loadProject(const QString &projectName);
	// read settings from qt file and fill project struct, and project runs.
	bool readProjectSettings(const QString &projectName);
	// create Tree widget
	bool populateProjectTreeWidget();
	// init summary and link action ...
	
	// find Text windows, create and show + status message
	void loadText(const QString &fileName);
	// ...
	void setCurrentProject(const QString &projectName);
	// ...
	void updateRecentProjectActions();
	// return file name
	QString strippedProjectName(const QString &projectName);
	// write .tp
	bool writeProjectSettings(const QString &projectName);
	// ...
	void closeData(const QString &fileName);
	// ...
	void closeGraph(const QString &fileName);
	// ...
	void closeText(const QString &fileName);
	// fill old.run to default values
	void setDefaultRunParameters();
	// text message, fill old run, create run dir, create command line and cle start
	void performMRun();
	// fill widget tree for new run, save project, add run to summary table and updateMenus.
	void addMRunToProject();

	void performARun();
	void calculateSignificanceProbability();

	void addRunSnps(Run *crun);

	void eigenstratgeno2lfmm(const QString &inFile, 
		const QString &outFile, const int n, const int L );
	void ancestrymap2lfmm(const QString &inFile, 
		const QString &outFile, const int n, const int L );
	void lfmm2lfmm(const QString &inFile, 
		const QString &outFile, const int n, const int L );
	void ped2lfmm(const QString &inFile, 
		const QString &outFile, const int n, const int L );

	void nothing2zscore(const QString &inFile, 
        	const QString &outFile, const int L);
	void lfmmsnp2zscore(const QString &inFile, const QString &snp,
        	const QString &outFile, const int L );
	void snp2zscore(const QString &inFile, const QString &snp,
        	const QString &outFile, const int L );
	void pedsnp2zscore(const QString &inFile, const QString &snp,
        	const QString &outFile, const int L );
	QWorkspace *workspace;
	QWidget *centralZone;
	QSignalMapper *windowMapper;
	QTabWidget *tabMain;

	TreeWidget *projectTreeWidget;
	SummaryDialog *summaryDialog;
	ZscoreDialog *zscoreDialog;
	//QLabel *manhattanDialog;
	QTreeWidgetItem *projectRunsItem;
	QTreeWidgetItem *projectItem;
	QTreeWidgetItem *projectSummarizeItem;
	QTreeWidgetItem *runNameItem;

	QTextEdit *infoTextEdit;
	TreeInfo *infoTextIntro;
	QWorkspace *workspaceData;

	// File
	QAction *openDataAct;
	QAction *newProjectAct;
	QAction *openProjectAct;
	QAction *closeProjectAct;
	//QAction *saveProjectAct;
	QAction *openTextualResultsAct;
	QAction *recentProjectSeparatorAct;
	QAction *recentProjectActs[MAX_RECENT_PROJECTS];
	QAction *quitAct;

	// Project
	QAction *runAct;
	QAction *abortAct;
	QAction *removeRunAct;

	// View
	QAction *clearAct;

	// Window
	QAction *closeAct;
	QAction *closeAllAct;
	QAction *tileAct;
	QAction *cascadeAct;
	QAction *arrangeAct;
	QAction *nextAct;
	QAction *previousAct;
	QAction *windowSeparatorAct;

	// Help
	QAction *referenceAct;
	QAction *aboutAct;

	QMenu *fileMenu;
	QMenu *projectMenu;
	QMenu *toolsMenu;
	QMenu *viewMenu;
	QMenu *windowMenu;
	QMenu *helpMenu;

	QToolBar *fileToolBar;
	QToolBar *projectToolBar;
	QToolBar *toolsToolBar;
	QToolBar *viewToolBar;
	QToolBar *helpToolBar;

	Project project;
	bool projectOpened;
	bool projectModified;
	QString currentProject;

	bool mainRun;
	int currARun;
	int currMRun;
	int currDRun;
	int totDRun;
	int totMRun;
	int currK;

	Run oldRun;
	Run newRun;

	QString trName;  // Textual Results
	QString lhName;  // Log-Likelihood History

	// Command-Line Engine (TESS MCMC and TESS EM)
	QProcess *cle;
	QProcess::ProcessState cleState;

	QProcess *cle2;
	QProcess::ProcessState cleState2;

	//QDesktopServices *test;
	//bool creationData;
	//bool creationRes;
};

#endif // LFMMGUI_H
