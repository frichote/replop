/*
    LFMM GUI, file: lfmmgui.cpp
    Copyright (C) 2012 Eric Frichot

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <QtAlgorithms>
#include <QtCore>
#include <QtGui>
#include <QUrl>
#include <QSize>
#include <QDesktopServices>
#include <set>
#include <cmath>
#include <algorithm>
#include <QDateTime>
#include <sstream>

#include "lfmmgui.h"
#include "aboutdialog.h"
#include "datawindow.h"
#include "newprojectdialog.h"
#include "newrundialog.h"
#include "textwindow.h"
#include "title.h"
#include "snp.h"
#include "treewidget.h"

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	1

#define KMAX	216  



struct SPATIAL_INFO 
{
	int num;
	double xMin;
	double xMax;
	double xMu;
	double xSigma;
	double yMin;
	double yMax;
	double yMu;
	double ySigma;
};

struct SCOORD
{
	double x;
	double y;
};

	LFMMGUI::LFMMGUI(QWidget *parent, Qt::WFlags flags)
: QMainWindow(parent, flags)
{

//	creationData = false;
//	creationRes = false;
	projectOpened = false;
	projectModified = false;

	workspace = new QWorkspace; //TODO
	centralZone = new QWidget;
	setCentralWidget(centralZone);

	// create Window, menu, actions...
	createActions();
	createMenus();
	createToolBars();
	createStatusBar();
	createDockWindows();

	connect(summaryDialog->summaryTable, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), 
			this, SLOT(loadSummaryRes(QTableWidgetItem *)));

	// Double click on project Tree
	connect(projectTreeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)), 
			this, SLOT(loadProjectItem(QTreeWidgetItem *, int)));

	// title
	setWindowTitle(GUI_TITLE);

	// connect command line actions
	cle = new QProcess(this);
	cle->setReadChannelMode(QProcess::MergedChannels);
	connect(cle, SIGNAL(error(QProcess::ProcessError)), 
			this, SLOT(cleError(QProcess::ProcessError)));
	connect(cle, SIGNAL(finished(int, QProcess::ExitStatus)), 
			this, SLOT(cleFinished(int, QProcess::ExitStatus)));
	connect(cle, SIGNAL(readyReadStandardError()), 
			this, SLOT(cleReadStandardError()));
	connect(cle, SIGNAL(readyReadStandardOutput()), 
			this, SLOT(cleReadStandardOutput()));
	connect(cle, SIGNAL(started()), this, SLOT(cleStarted()));
	connect(cle, SIGNAL(stateChanged(QProcess::ProcessState)), 
			this, SLOT(cleStateChanged(QProcess::ProcessState)));
	cleState = QProcess::NotRunning;

	cle2 = new QProcess(this);
	cle2->setReadChannelMode(QProcess::MergedChannels);
	//connect(cle2, SIGNAL(error(QProcess::ProcessError)), 
	//		this, SLOT(cleError(QProcess::ProcessError)));
	connect(cle2, SIGNAL(readyReadStandardError()), 
			this, SLOT(cleReadStandardError()));
	connect(cle2, SIGNAL(readyReadStandardOutput()), 
			this, SLOT(cleReadStandardOutput()));
	// connect(cle2, SIGNAL(started()), this, SLOT(cle2Started()));
	
	updateMenus();
}

LFMMGUI::~LFMMGUI()
{
	// delete summary panel
	if (summaryDialog)
	{
		delete summaryDialog;
	}

	// delete zscore panel
	if (zscoreDialog)
	{
		delete zscoreDialog;
	}
}

// TEST
bool checkUrl(const QUrl &url) {
	if (!url.isValid()) {
		//qDebug(QString("Invalid URL: %1").arg(url.toString()));
		return false;
	}
	return true;
}



void LFMMGUI::closeEvent(QCloseEvent *event)
{
	if (cleState != QProcess::NotRunning)
	{
		int response = QMessageBox::question(this, GUI_TITLE, 
				tr("Project is running. Do you really want to quit?"), 
				QMessageBox::Yes, 
				QMessageBox::No | QMessageBox::Default);
		if (response == QMessageBox::Yes)
		{
			summaryDialog->clear();
			zscoreDialog->clear();
			event->accept();
		}
		else
		{
			event->ignore();
		}

		summaryDialog->clear();
		zscoreDialog->clear();

		return;
	}

	summaryDialog->clear();
	zscoreDialog->clear();
	event->accept();
}

void LFMMGUI::openData()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Data"));
	loadData(fileName);
}

void LFMMGUI::newProject()
{
	QDateTime date;
	NewProjectDialog *newProjectDialog = new NewProjectDialog(this);

	if (newProjectDialog->exec() == QFileDialog::Accepted)
	{

		closeProject();  // Close previously opened project, if any.

		project.date = date.currentDateTime().toString();
		project.name = newProjectDialog->nameLineEdit->text();
		project.path = newProjectDialog->pathLineEdit->text();
		QFileInfo dataInfo(newProjectDialog->dataLineEdit->text());
		//project.data = dataInfo.fileName();
		project.data_prev = dataInfo.fileName();

		//project.hasGeoData = !newProjectDialog->geoDataLineEdit->text().isEmpty();
		QFileInfo geoDataInfo(newProjectDialog->geoDataLineEdit->text());
		project.geoData = geoDataInfo.fileName();

		project.hasNameData = !newProjectDialog->nameDataLineEdit->text().isEmpty();
		if (project.hasNameData) {
			QFileInfo nameDataInfo(newProjectDialog->nameDataLineEdit->text());
			project.nameData = nameDataInfo.fileName();
		}

		project.N = newProjectDialog->nLineEdit->text();
		project.L = newProjectDialog->lLineEdit->text();
		project.D = newProjectDialog->dLineEdit->text();

		project.i = 0;

		QString newData = project.path + "/" + project.name +"_data.lfmm";

		if (project.data_prev.endsWith(tr(".ped")))
		{
			ped2lfmm(newProjectDialog->dataLineEdit->text(),
				newData, project.N.toInt(), project.L.toInt()); 
		} else if (project.data_prev.endsWith(tr(".ancestrymap")))
		{
			ancestrymap2lfmm(newProjectDialog->dataLineEdit->text(),
				newData, project.N.toInt(), project.L.toInt()); 
		} else if (project.data_prev.endsWith(tr(".eigenstratgeno")) 
			|| project.data_prev.endsWith(tr(".geno")) )
		{
			eigenstratgeno2lfmm(newProjectDialog->dataLineEdit->text(),
				newData, project.N.toInt(), project.L.toInt()); 
		} else if (project.data_prev.endsWith(tr(".lfmm")))
		{
			lfmm2lfmm(newProjectDialog->dataLineEdit->text(),
				newData, project.N.toInt(), project.L.toInt()); 
		}

		project.data = project.name + "_data.lfmm";

		QFile newDataFile(newData);
		if (!newDataFile.exists()) {
	                QMessageBox::critical(this, GUI_TITLE,
                        tr("An error happened during the creation of the genotype data file.\n\n"
                        "Please, check the reference manual or the General informations panel and your genotype data file and retry to create this project."));

			clearInfoWindow();
			projectOpened = true;
			closeProject();
		} else {
		projectModified = true;
		currentProject = project.path + "/" + project.name + ".tp";
		saveProject();   // Save the newly created project.
		clearInfoWindow();
		if (!loadProject(currentProject))  // Load the new project.
		{
			projectOpened = true;
			closeProject();
		}
		}
		updateMenus();
	}
	delete newProjectDialog;
	summaryDialog->project = &project;
	zscoreDialog->project = &project;
}

void LFMMGUI::ped2lfmm(const QString &inFile, 
        const QString &outFile, const int n, const int L )
{

        static QList< int > res;
        QList< char > ref;
        res.clear();
        ref.clear();

        for (int l = 0; l < L; l++)
		ref.append('0');

        QFile file(inFile);
        if (!file.open(QFile::ReadOnly | QFile::Text)) 
        {
                QMessageBox::warning(this, GUI_TITLE,
                        tr("Cannot verify data file %1!").arg(inFile));
        }
        QTextStream in(&file);
        QRegExp reWC("\\w");  // Word Character
        QRegExp regExp("\\s+|\\t+");  // Space(s) or Tab(s)
        QString oneRow;
        QStringList oneRowList;
        QApplication::setOverrideCursor(Qt::WaitCursor);
        while (!(oneRow = in.readLine()).isNull())
        {
                oneRowList = oneRow.split(regExp, QString::SkipEmptyParts);
		
                for (int i = 0; i<L; i++)
                {
			int tmp = 0;
			
			if (!QString(ref[i]).compare("0")) {
				if (!oneRowList[6+i*2].compare("0") 
					&& !oneRowList[6+i*2 + 1].compare("0"))
					tmp = 9;
				else if (oneRowList[6+i*2].compare("0") 
					&& !oneRowList[6+i*2 + 1].compare("0")) {
					ref[i] = oneRowList[6+i*2].at(0).toLatin1();
					tmp = 9;
				} else if (!oneRowList[6+i*2].compare("0") 
					&& !oneRowList[6+i*2 + 1].compare("0")) {
					ref[i] = oneRowList[6+i*2+1].at(0).toLatin1();
					tmp = 1;
				} else {
					ref[i] = oneRowList[6+i*2].at(0).toLatin1();
					tmp = 1;
					if(!oneRowList[6+i*2 + 1].compare(oneRowList[6+i*2]))
						tmp ++;
				}
			} else {
				if (!oneRowList[6+i*2].compare("0") 
					|| !oneRowList[6+i*2 + 1].compare("0"))
					tmp = 9;
				else {	
					if (!QString(ref[i]).compare(oneRowList[6+i*2]))
						tmp ++;
					if (!QString(ref[i]).compare(oneRowList[6+i*2+1]))
						tmp ++;
				}
			}
   	       		res.append(tmp);
		}
        }
        QApplication::restoreOverrideCursor();
        file.close();

        QFile saveFile(outFile);
        if (!saveFile.open(QFile::WriteOnly | QFile::Text))
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Cannot open file %1!")
                                .arg(outFile));
                return;
        }

        QTextStream out(&saveFile);

        for (int i = 0; i < n; i++)
        {
                for (int l = 0; l < L-1; l++)
                {
                        out << res[i*L+l] << ' ';
                }
                out << res[i*L+L-1] << endl;
        }
        saveFile.close();
}


void LFMMGUI::lfmm2lfmm(const QString &inFile, 
        const QString &outFile, const int n, const int L )
{

        static QList< int > res;
        res.clear();

        QFile file(inFile);
        if (!file.open(QFile::ReadOnly | QFile::Text)) 
        {
                QMessageBox::warning(this, GUI_TITLE,
                        tr("Cannot verify data file %1!").arg(inFile));
        }
        QTextStream in(&file);
        QRegExp reWC("\\w");  // Word Character
        QRegExp regExp("\\s+|\\t+");  // Space(s) or Tab(s)
        QString oneRow;
        QStringList oneRowList;
        QApplication::setOverrideCursor(Qt::WaitCursor);
        while (!(oneRow = in.readLine()).isNull())
        {
                oneRowList = oneRow.split(regExp, QString::SkipEmptyParts);
		
                for (int i = 0; i<oneRowList.size(); i++)
                {
   	       		res.append(oneRowList[i].toInt());
		}
        }
        QApplication::restoreOverrideCursor();
        file.close();

        QFile saveFile(outFile);
        if (!saveFile.open(QFile::WriteOnly | QFile::Text))
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Cannot open file %1!")
                                .arg(outFile));
                return;
        }

        QTextStream out(&saveFile);

        for (int i = 0; i < n; i++)
        {
                for (int l = 0; l < L-1; l++)
                {
                        out << res[i*L+l] << ' ';
                }
                out << res[i*L+L-1] << endl;
        }
        saveFile.close();
}

void LFMMGUI::ancestrymap2lfmm(const QString &inFile, 
        const QString &outFile, const int n, const int L )
{

        static QList< int > res;
        res.clear();

        QFile file(inFile);
        if (!file.open(QFile::ReadOnly | QFile::Text)) 
        {
                QMessageBox::warning(this, GUI_TITLE,
                        tr("Cannot verify data file %1!").arg(inFile));
        }
        QTextStream in(&file);
        QRegExp reWC("\\w");  // Word Character
        QRegExp regExp("\\s+|\\t+");  // Space(s) or Tab(s)
        QString oneRow;
        QStringList oneRowList;
        QApplication::setOverrideCursor(Qt::WaitCursor);
        while (!(oneRow = in.readLine()).isNull())
        {
                oneRowList = oneRow.split(regExp, QString::SkipEmptyParts);
   	       	res.append(oneRowList[2].toInt());
        }
        QApplication::restoreOverrideCursor();
        file.close();

        QFile saveFile(outFile);
        if (!saveFile.open(QFile::WriteOnly | QFile::Text))
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Cannot open file %1!")
                                .arg(outFile));
                return;
        }

        QTextStream out(&saveFile);

        for (int i = 0; i < n; i++)
        {
                for (int l = 0; l < L-1; l++)
                {
                        out << res[l*n+i] << ' ';
                }
                out << res[(L-1)*n+i] << endl;
        }
        saveFile.close();
}
void LFMMGUI::eigenstratgeno2lfmm(const QString &inFile, 
        const QString &outFile, const int n, const int L )
{

        static QList< int > res;
        res.clear();

        QFile file(inFile);
        if (!file.open(QFile::ReadOnly | QFile::Text)) 
        {
                QMessageBox::warning(this, GUI_TITLE,
                        tr("Cannot verify data file %1!").arg(inFile));
        }
        QTextStream in(&file);
        QRegExp reWC("\\w");  // Word Character
        QRegExp regExp("");  // Space(s) or Tab(s)
        QString oneRow;
        QStringList oneRowList;
        QApplication::setOverrideCursor(Qt::WaitCursor);
        while (!(oneRow = in.readLine()).isNull())
        {
                        //oneRowList = oneRow.split(regExp, QString::SkipEmptyParts);
                        for (int i = 0; i<oneRow.size(); i++)
                        {
                                res.append(oneRow[i].digitValue());
                }
        }
        QApplication::restoreOverrideCursor();
        file.close();

        QFile saveFile(outFile);
        if (!saveFile.open(QFile::WriteOnly | QFile::Text))
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Cannot open file %1!")
                                .arg(outFile));
                return;
        }

        QTextStream out(&saveFile);

        for (int i = 0; i < n; i++)
        {
                for (int l = 0; l < L-1; l++)
                {
                        out << res[l*n+i] << ' ';
                }
                out << res[(L-1)*n+i] << endl;
        }
        saveFile.close();
}

void LFMMGUI::openProject()
{
	QString projectName = QFileDialog::getOpenFileName(
			this,
			tr("Open %1 Project").arg(GUI_TITLE),
			QDir::currentPath(),
			tr("%1 Projects (*.tp);;All Files (*.*)").arg(GUI_TITLE)
			);
	if (!projectName.isEmpty())
	{
		if (projectOpened && projectName == currentProject)
		{
			return;
		}
		else
		{
			closeProject();  // Close previously opened project, if any.
			if (!loadProject(projectName))
			{
				projectOpened = true;
				closeProject();
				QMessageBox::warning(this, GUI_TITLE, tr("Cannot open project!"));
			}
		}
		updateMenus();
	}
}

void LFMMGUI::removeRun()
{
	QString runName = QFileDialog::getExistingDirectory(
			this,
			tr("Remove %1 Run").arg(GUI_TITLE),
			project.path
			);
	if (!runName.isEmpty())
	{
        	if (runName.endsWith('/') || runName.endsWith('\\'))
       	 	{
                	runName = runName.left(runName.length() - 1);
	       	}
	        QRegExp rx(tr("%1/(%2_RUN_\\d*)").arg(project.path).arg(QFileInfo(project.path + "/" + project.name).baseName()));
				
		if (rx.indexIn(runName) != -1) {
		runName = rx.cap(1);
		if (projectOpened)
		{
			deleteRunItem(runName);
			QString projectName = currentProject; 
			closeProject();
			if (!loadProject(projectName))
			{
				projectOpened = true;
				closeProject();
				QMessageBox::warning(this, GUI_TITLE, tr("Cannot open project!"));
			}
			updateMenus();
			
			return;
		}
		} else {
			QMessageBox::warning(this, GUI_TITLE, 
				tr("You cannot suppress run with path:\n\n"
				   "%1\n\nIt is not the directory of a run of this project. " 
				   "Please select the directory of a run of this project.").arg(runName));
		}
	}
}


void LFMMGUI::closeProject()
{
	if (projectOpened)
	{
		saveProject();
		summaryDialog->clear();
		zscoreDialog->clear();

		projectTreeWidget->clear();
		workspaceData->closeAllWindows();
		workspace->closeAllWindows();
		clearInfoWindow();
		project.runs.clear();
		setDefaultRunParameters();
		projectOpened = false;
		updateMenus();
		summaryDialog->project = NULL;
		zscoreDialog->project = NULL;
		tabMain->setCurrentIndex(0);
	}
}

void LFMMGUI::saveProject()
{
	if (projectModified)
	{
		writeProjectSettings(currentProject);
		projectModified = false;
		updateMenus();
	}
}

void LFMMGUI::openText()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Textual Results"));
	loadText(fileName);
}

void LFMMGUI::openRecentProject()
{
	QAction *action = qobject_cast<QAction *>(sender());
	if (action)
	{
		if (projectOpened && action->data().toString() == currentProject)
		{
			return;
		}
		else
		{
			closeProject();  // Close previously opened project, if any.
			if (!QFile::exists(action->data().toString()) || 
					!loadProject(action->data().toString()))
			{
				projectOpened = true;
				closeProject();
				QMessageBox::warning(this, GUI_TITLE, 
						tr("Cannot open this recent project!\n"
							"It will be removed from the recent project list."));
				QSettings settings(tr("SuperSoft"), GUI_TITLE);
				QStringList projects = 
					settings.value(tr("recentProjectList")).toStringList();
				projects.removeAll(action->data().toString());
				while (projects.size() > MAX_RECENT_PROJECTS)
				{
					projects.removeLast();
				}
				settings.setValue(tr("recentProjectList"), projects);
				updateRecentProjectActions();
			}
		}
		updateMenus();
	}
}

void LFMMGUI::quit()
{
	summaryDialog->clear();
	zscoreDialog->clear();
	summaryDialog->close();
	zscoreDialog->close();
	close();
}

void LFMMGUI::modify()
{

}

void LFMMGUI::run()
{
	NewRunDialog *newRunDialog = new NewRunDialog(0,project.D.toInt());
	//bool bSvd = oldRun.T == tr("Singular Value Decomposition");
	//newRunDialog->SvdRadioButton->setChecked(bSvd);		
	bool bGS = oldRun.T == tr("Gibbs Sampler");
	//bool bVB = oldRun.T == tr("Variational Bayes");
	newRunDialog->GSRadioButton->setChecked(bGS);	
	//newRunDialog->VBRadioButton->setChecked(bVB);	
	newRunDialog->sLabel->setEnabled(bGS);	
	newRunDialog->sLineEdit->setEnabled(bGS);	
	newRunDialog->bLabel->setEnabled(bGS);
	newRunDialog->bLineEdit->setEnabled(bGS);	
	newRunDialog->rLineEdit->setText(oldRun.N);

	newRunDialog->scriptCheckBox->setCheckState(oldRun.script ? Qt::Checked : Qt::Unchecked);
	bool scriptChecked = newRunDialog->scriptCheckBox->checkState() == Qt::Checked;
	newRunDialog->kLineEdit->setText(oldRun.baseK);
	newRunDialog->toKLabel->setEnabled(scriptChecked);
	newRunDialog->toKLineEdit->setEnabled(scriptChecked);
	newRunDialog->toKLineEdit->setText(oldRun.toK);

	newRunDialog->nbThreadLineEdit->setText(oldRun.nbThread);

	newRunDialog->sLineEdit->setText(oldRun.S);
	newRunDialog->bLineEdit->setText(oldRun.B);
	newRunDialog->dLineEdit->setText(oldRun.V);

	

	if (newRunDialog->exec() == QDialog::Accepted)
	{

		clearInfoWindow();

		if (newRunDialog->GSRadioButton->isChecked())
		{
			newRun.T = tr("Gibbs Sampler");
		}
		/*
		if (newRunDialog->VBRadioButton->isChecked())
		{
			newRun.T = tr("Variational Bayes");
		}
		if (newRunDialog->SvdRadioButton->isChecked())
		{
			newRun.T = tr("Singular Value Decomposition");
		}*/

		QDateTime date;
		newRun.date = date.currentDateTime().toString();	
		newRun.script = newRunDialog->scriptCheckBox->checkState() == Qt::Checked;
		newRun.N = newRunDialog->rLineEdit->text();
		newRun.baseK = newRunDialog->kLineEdit->text();


		currMRun = 0;
		newRun.K = newRun.baseK;

		if (newRun.script)
		{
			newRun.toK = newRunDialog->toKLineEdit->text();
			totMRun = (newRun.toK.toInt() - newRun.baseK.toInt() + 1)*newRun.N.toInt();
		}
		else
		{
			totMRun = newRun.N.toInt();
		}

		currDRun = 0;
		newRun.nD = newRunDialog->nD;
			newRun.var = newRunDialog->varList;
		totDRun = newRun.nD;

		newRun.nbThread = newRunDialog->nbThreadLineEdit->text();

		newRun.S = newRunDialog->sLineEdit->text();
		newRun.B = newRunDialog->bLineEdit->text();
		newRun.V = newRunDialog->dLineEdit->text();

		performMRun();
	}

	delete newRunDialog;

}

void LFMMGUI::abort()
{
	int response = QMessageBox::question(this, GUI_TITLE, 
			tr("Do you really want to abort the run(s)?\n\n"
				"Please note that if you choose to abort runs,\n" 
				"all results for the current run will be deleted\n"
				"and all the rest runs (if any) will be aborted."), 
			QMessageBox::Yes, QMessageBox::No);
	if (response == QMessageBox::Yes)  //  && cleState != QProcess::NotRunning
	{
		// Abort the current run by killing the running process.
		cle->kill();

		// Abort the rest runs, if any.
		// 		currMRun = newRun.N.toInt();
		currMRun = totMRun;

		// Delete all result files.
		removeRunDir(project.path + "/" + newRun.name);
	}
}

/*
   void LFMMGUI::summarize()
   {
   int size = project.runs.size();
   if (size <= 0)
   {
   QMessageBox::warning(this,GUI_TITLE,tr("Nothing to summarize!"));
   return;
   }
   updateSummaryTable();
   summaryDialog->show();
   summaryOpened = true;
   updateMenus();
   }
 */

void LFMMGUI::exportTableToText()
{
	QString saveFileName = QFileDialog::getSaveFileName(this, tr("Save Table"), summaryDialog->commonPath);
	if (saveFileName.isEmpty())
	{
		QMessageBox::warning(this, GUI_TITLE, 
				tr("Cannot open/create file ! Check your rights"));
	//			.arg(summaryDialog->popfileLineEdit->text()));
		return;
	}
	QFile saveFile(saveFileName);
	if (!saveFile.open(QFile::WriteOnly | QFile::Text)) 
	{
		QMessageBox::warning(this, GUI_TITLE, 
				tr("Cannot open file!"));
		//		.arg(summaryDialog->popfileLineEdit->text()));
		return;
	}

	QTextStream out(&saveFile);

	out << "Labels" << '\t' << "Kmax" << '\t' << "DIC" << '\t' << "Trend_Degree" << '\t' <<"Model" << endl;

	int nRow = summaryDialog->summaryTable->rowCount();
	//We export columns number 0,1,2,6,7
	for (int i=0; i < nRow; i++)
	{
		out << summaryDialog->summaryTable->item(i,0)->text() << '\t';
		out << summaryDialog->summaryTable->item(i,1)->text() << '\t';
		out << summaryDialog->summaryTable->item(i,2)->text() << '\t';
		out << summaryDialog->summaryTable->item(i,6)->text() << '\t';
		out << summaryDialog->summaryTable->item(i,7)->text() << endl;
	}
	saveFile.close();
	QMessageBox::information(this, GUI_TITLE, tr(" Success! "));
	return;
}

void LFMMGUI::clearInfoWindow()
{
	infoTextEdit->clear();
	QFont courierFont("Courier", 9, QFont::Normal);
	infoTextEdit->setCurrentFont(courierFont);
}

void LFMMGUI::openReference()
{
#ifdef Q_WS_MAC
	QString referenceFilePath = tr("file://") +  QCoreApplication::applicationDirPath() + 
#endif
#ifdef Q_WS_WIN
	QString referenceFilePath = QCoreApplication::applicationDirPath() + 
#endif
#ifdef Q_WS_X11
	QString referenceFilePath = QCoreApplication::applicationDirPath() + 
#endif
		tr("/documentation/manual.pdf");
	//if (!QFile::exists(referenceFilePath))
	//{
	//	QMessageBox::warning(this, GUI_TITLE, tr("Reference manual is missing!"));
	//	return;
	//}
	QUrl url(referenceFilePath);
	QDesktopServices::openUrl(url);
}

void LFMMGUI::about()
{
	AboutDialog *aboutDialog = new AboutDialog;
	aboutDialog->exec();
	delete aboutDialog;
}

void LFMMGUI::updateMenus()
{
	// TODO

	// File Menu
	newProjectAct->setEnabled(cleState == QProcess::NotRunning);// && !modifying);
	openProjectAct->setEnabled(cleState == QProcess::NotRunning);// && !modifying);
	closeProjectAct->setEnabled(projectOpened && cleState == QProcess::NotRunning);

	//	&& !modifying);
	/*
	saveProjectAct->setEnabled(projectOpened && projectModified && 
			cleState == QProcess::NotRunning);// && !modifying);
	*/
	quitAct->setEnabled(cleState == QProcess::NotRunning);// && !modifying);

	// Project Menu
	runAct->setEnabled(projectOpened && cleState == QProcess::NotRunning);// && !modifying);
	abortAct->setEnabled(projectOpened && cleState != QProcess::NotRunning);
	removeRunAct->setEnabled(projectOpened && cleState == QProcess::NotRunning && project.runs.size() != 0);// && !modifying);
	//bool hasRun = project.runs.size() > 0;

	// Window Menu
	bool hasChild = workspace->activeWindow() != 0;
	closeAct->setEnabled(hasChild);
	closeAllAct->setEnabled(hasChild);
	tileAct->setEnabled(hasChild);
	cascadeAct->setEnabled(hasChild);
	arrangeAct->setEnabled(hasChild);
	nextAct->setEnabled(hasChild);
	previousAct->setEnabled(hasChild);
	windowSeparatorAct->setVisible(hasChild);
	summaryDialog->project = &project;
	zscoreDialog->project = &project;
}

/*
void LFMMGUI::updateWindowMenu()
{
	windowMenu->clear();
	windowMenu->addAction(closeAct);
	windowMenu->addAction(closeAllAct);
	windowMenu->addSeparator();
	windowMenu->addAction(tileAct);
	windowMenu->addAction(cascadeAct);
	windowMenu->addAction(arrangeAct);
	windowMenu->addSeparator();
	windowMenu->addAction(nextAct);
	windowMenu->addAction(previousAct);
	windowMenu->addAction(windowSeparatorAct);

	QList<QWidget *> windows = workspace->windowList();
	windowSeparatorAct->setVisible(!windows.isEmpty());

	for (int i = 0; i < windows.size(); i++) 
	{
		QWidget *child = windows.at(i);
		DataWindow *dataChild = qobject_cast<DataWindow *>(child);
		//GraphWindow * graphChild = qobject_cast<GraphWindow *>(child);
		TextWindow * textChild = qobject_cast<TextWindow *>(child);

		QString fileName;
		if (dataChild)
		{
			fileName = dataChild->currentFile();
		}
		/*
		if (graphChild)
		{
			fileName = graphChild->currentFile();
		}
		*
		if (textChild)
		{
			fileName = textChild->currentFile();
		}

		QString text;
		if (i < 9) 
		{
			text = tr("&%1 %2").arg(i + 1).arg(fileName);
		} 
		else 
		{
			text = tr("%1 %2").arg(i + 1).arg(fileName);
		}
		QAction *action  = windowMenu->addAction(text);
		action->setCheckable(true);
		action ->setChecked(child == workspace->activeWindow());
		connect(action, SIGNAL(triggered()), windowMapper, SLOT(map()));
		windowMapper->setMapping(action, child);
	}
}
*/
void LFMMGUI::loadSummaryRes(QTableWidgetItem *item)
{
	if (!item->text().compare(tr("zscore.res")))
	{
		QTableWidgetItem *name = summaryDialog->summaryTable->item(item->row(),0);
		QRegExp rx("^.*_RUN_(\\d*)");
		rx.indexIn(name->text());
		int nIndex = rx.cap(1).toInt() - 1;
		zscoreDialog->runComboBox->setCurrentIndex(nIndex);
		tabMain->setCurrentIndex(1);
	}
}

void LFMMGUI::loadProjectItem(QTreeWidgetItem *item, int column)
{
	if (item->text(column).startsWith(tr("Data lfmm")))
	{
		loadData(project.path + "/" + project.data, 0, 0);
	}

	if (item->text(column).startsWith(tr("Data:")))
	{
		loadData(project.path + "/" + project.data_prev, 0, 0);
	}
/*
	if (item->text(column).endsWith(".png"))
	{
		int nIndex = item->text(column).indexOf(QString(": ")) + 2;
		//loadGraph(project.path + "/" + item->text(column).mid(nIndex));
	}
*/
	if (item->text(column).startsWith(tr("Env:")))
	{
		loadData(project.path + "/" + project.geoData, 0, 0);
	}

	if (item->text(column).startsWith(tr("SNP name")))
	{
		loadData(project.path + "/" + project.nameData, 0, 0);
	}

	if (item->text(column).startsWith(tr("Zscore Table")))
	{
		QTreeWidgetItem *parent = item->parent();
		QRegExp rx("^.*_RUN_(\\d*)");
		rx.indexIn(parent->text(column));
		int nIndex = rx.cap(1).toInt() - 1;
		//Snp snp = project.runs[nIndex].snps.at(0);
		//printf("nam %s\n",qPrintable(snp.name));
		// initZscore
		//zscoreDialog->initZscore();
		//close zscore previous...
		//zscoreDialog->initZscore();
		// go to Zscore panel
		zscoreDialog->runComboBox->setCurrentIndex(nIndex);
		tabMain->setCurrentIndex(1);

		//loadData(project.path + "/" + parent->text(column) +"/" + "zscore.txt");
	}
	if (item->text(column).startsWith(tr("Deviance")))
	{
		tabMain->setCurrentIndex(2);
	}

	if (item->text(column).startsWith(tr("DIC")))
	{
		tabMain->setCurrentIndex(2);
	}

	if (!item->text(column).startsWith(tr("SNP name")) &&
			!item->text(column).startsWith(tr("Zscore Table")) &&
			!item->text(column).startsWith(tr("Data")) && 
			item->text(column).endsWith(".txt") && 
			!item->text(column).startsWith(tr("Env")))
	{
		int nIndex = item->text(column).indexOf(QString(": ")) + 2;
		loadText(project.path + "/" + item->text(column).mid(nIndex));
	}
}

void LFMMGUI::deleteRunItem(QString item)
{
	int Kremoved = 0;
	for (int i = 0; i < project.runs.size(); i++)
	{
		if (project.runs.at(i).name == item)
		{
			Kremoved = project.runs.at(i).K.toInt();
			project.runs.removeAt(i);
			project.i--;//=project.runs.size();
			//summaryDialog->removeRunFromSummaryTable(i,Kremoved);
			projectModified = true;
			saveProject();
			updateMenus();
			break;
		}
	}

	removeRunDir(project.path + "/" + item);
}

void LFMMGUI::removeRunDir(QString dirName)
{
	QDir runDir(dirName);
	if (runDir.exists())
	{
		runDir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
		QStringList fileList = runDir.entryList();
		for (int i = 0; i < fileList.size(); i++)
		{
			runDir.remove(fileList[i]);
		}
		runDir.rmdir(dirName);
	}
}

void LFMMGUI::notSummarizing()
{
	//summaryOpened = false;
	updateMenus();	
}

void LFMMGUI::notSummarizingZscore()
{
	//zscoreOpened = false;
	updateMenus();	
}
void LFMMGUI::notModifying()
{
	//modifying = false;
	updateMenus();
}

void LFMMGUI::cleError(QProcess::ProcessError error)
{
	switch(error) 
	{
		case QProcess::FailedToStart:
			infoTextEdit->append(tr("Error: Failed to start %1 (%2).\n")
					.arg(CMD_TITLE)
					.arg(newRun.T));
			break;

		case QProcess::Crashed:
			infoTextEdit->append(tr("Error: %1 (%2) aborted or crashed.\n")
					.arg(CMD_TITLE)
					.arg(newRun.T));
			break;

		case QProcess::Timedout:
			infoTextEdit->append(tr("Error: Waiting for %1 (%2) timed out.\n")
					.arg(CMD_TITLE)
					.arg(newRun.T));
			break;

		case QProcess::WriteError:
			infoTextEdit->append(
					tr("Error: An error occurred when attempting to write to %1 (%2).\n")
					.arg(CMD_TITLE)
					.arg(newRun.T));
			break;

		case QProcess::ReadError:
			infoTextEdit->append(
					tr("Error: An error occurred when attempting to read from %1 (%2).\n")
					.arg(CMD_TITLE)
					.arg(newRun.T));
			break;

		default:
			infoTextEdit->append(tr("Error: An unknown error occurred.\n"));
	}
}

void LFMMGUI::cleFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
	infoTextEdit->append(tr("%1 (%2) Exit Code: %3, %4 (%5) Exit Status: %6.\n")
			.arg(CMD_TITLE)
			.arg(newRun.T)
			.arg(exitCode)
			.arg(CMD_TITLE)
			.arg(newRun.T)
			.arg(exitStatus));

	if (mainRun) // && !creationData && !creationRes)
	{
		currMRun++;

		QString zscoreName2 = project.path + "/" + newRun.name 
					+ "/zscore.txt_" + newRun.var[currDRun];
		QString devName = project.path + "/" + newRun.name + "/DIC.txt";
		
		if (exitCode == EXIT_SUCCESS && // && 
			   QFile::exists(zscoreName2) && 
			   QFile::exists(devName)) 
		{
			//creationRes = true;
			QString cmdLine;
			QString fullNameRes = project.path + "/" + newRun.name + "/" + "zscore.res";
			QString zscoreName = project.path + "/" + newRun.name + "/" + newRun.ZS 
				+ "_" + newRun.var[currDRun];
			QString fullNameData = project.path + "/" + project.nameData;

			if (!project.nameData.isEmpty()) {
			if (QFile::exists(fullNameData)) {
			if (fullNameData.endsWith(tr(".pedsnp")) || fullNameData.endsWith(tr(".map")))
			{
				pedsnp2zscore(zscoreName,fullNameData,fullNameRes,project.L.toInt()); 
			} else if (fullNameData.endsWith(tr(".snp")))
			{
				snp2zscore(zscoreName,fullNameData,fullNameRes,project.L.toInt()); 
			} else if (fullNameData.endsWith(tr(".lfmmsnp")))
			{
				lfmmsnp2zscore(zscoreName,fullNameData,fullNameRes,project.L.toInt()); 
			}
			}
			} else 
			{
				nothing2zscore(zscoreName,fullNameRes,project.L.toInt()); 
			}

		newRun.ZS = "zscore.res";

                QString path = project.path + "/" + newRun.name + "/" + "DIC.txt";
                QFile file(path);
                if(file.exists() && file.open(QIODevice::ReadOnly)) {
                        QTextStream in(&file);
                        QString line = in.readLine();
                        line = in.readLine();
                        QStringList fields = line.split(" ");
			newRun.Deviance = fields[0];
			newRun.DIC = fields[1];
		}

		QFile newDataFile(fullNameData);
                if (!newDataFile.exists()) {
                        QMessageBox::critical(this, GUI_TITLE,
                        tr("An error happened during the creation of the zscore file.\n\n"
                        "Please, check the reference manual or the General informations panel and your genotype data file and retry to launch this run."));

                } else {
			addMRunToProject();
		}
		}

		if (currMRun < totMRun)
		{
			performMRun();
		}
		if (currMRun == totMRun && currDRun +1< totDRun)
		{
			currMRun = 0;
			currDRun++;
			performMRun();

		}
	} 
}

void LFMMGUI::pedsnp2zscore(const QString &inFile, const QString &snp,
        const QString &outFile, const int L )
{
        QFile file(inFile);
        if (!file.open(QFile::ReadOnly | QFile::Text)) 
        {
                QMessageBox::warning(this, GUI_TITLE,
                        tr("Cannot verify data file %1!").arg(inFile));
        }
        QTextStream in(&file);

        QFile file2(snp);
        if (!file2.open(QFile::ReadOnly | QFile::Text)) 
        {
                QMessageBox::warning(this, GUI_TITLE,
                        tr("Cannot verify data file %1!").arg(snp));
        }
        QTextStream in2(&file2);

        QFile saveFile(outFile);
        if (!saveFile.open(QFile::WriteOnly | QFile::Text))
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Cannot open file %1!")
                                .arg(outFile));
                return;
        }
        QTextStream out(&saveFile);

        QRegExp reWC("\\w");  // Word Character
        QRegExp regExp("\\s+|\\t+");  // Space(s) or Tab(s)
        QString oneRow;
        QStringList oneRowList;
        QString oneRow2;
        QStringList oneRowList2;
        QApplication::setOverrideCursor(Qt::WaitCursor);
        while (!(oneRow = in.readLine()).isNull())
        {
        	oneRow2 = in2.readLine();
                oneRowList2 = oneRow2.split(regExp, QString::SkipEmptyParts);
                oneRowList = oneRow.split(regExp, QString::SkipEmptyParts);
		out << oneRowList2[1] << " " << oneRowList2[0] << " " << oneRowList2[3] << " "
		<< oneRowList[0] << " " << oneRowList[1] << " " << oneRowList[2] << endl;
        }
        QApplication::restoreOverrideCursor();
        file.close();
        file2.close();

        saveFile.close();
}

void LFMMGUI::snp2zscore(const QString &inFile, const QString &snp,
        const QString &outFile, const int L )
{
        QFile file(inFile);
        if (!file.open(QFile::ReadOnly | QFile::Text)) 
        {
                QMessageBox::warning(this, GUI_TITLE,
                        tr("Cannot verify data file %1!").arg(inFile));
        }
        QTextStream in(&file);

        QFile file2(snp);
        if (!file2.open(QFile::ReadOnly | QFile::Text)) 
        {
                QMessageBox::warning(this, GUI_TITLE,
                        tr("Cannot verify data file %1!").arg(snp));
        }
        QTextStream in2(&file2);

        QFile saveFile(outFile);
        if (!saveFile.open(QFile::WriteOnly | QFile::Text))
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Cannot open file %1!")
                                .arg(outFile));
                return;
        }
        QTextStream out(&saveFile);

        QRegExp reWC("\\w");  // Word Character
        QRegExp regExp("\\s+|\\t+");  // Space(s) or Tab(s)
        QString oneRow;
        QStringList oneRowList;
        QString oneRow2;
        QStringList oneRowList2;
        QApplication::setOverrideCursor(Qt::WaitCursor);
        while (!(oneRow = in.readLine()).isNull())
        {
        	oneRow2 = in2.readLine();
                oneRowList2 = oneRow2.split(regExp, QString::SkipEmptyParts);
                oneRowList = oneRow.split(regExp, QString::SkipEmptyParts);
		out << oneRowList2[0] << " " << oneRowList2[1] << " " << oneRowList2[3] << " "
		<< oneRowList[0] << " " << oneRowList[1] << " " << oneRowList[2] << endl;
        }
        QApplication::restoreOverrideCursor();
        file.close();
        file2.close();

        saveFile.close();
}


void LFMMGUI::lfmmsnp2zscore(const QString &inFile, const QString &snp,
        const QString &outFile, const int L )
{
        QFile file(inFile);
        if (!file.open(QFile::ReadOnly | QFile::Text)) 
        {
                QMessageBox::warning(this, GUI_TITLE,
                        tr("Cannot verify data file %1!").arg(inFile));
        }
        QTextStream in(&file);

        QFile file2(snp);
        if (!file2.open(QFile::ReadOnly | QFile::Text)) 
        {
                QMessageBox::warning(this, GUI_TITLE,
                        tr("Cannot verify data file %1!").arg(snp));
        }
        QTextStream in2(&file2);

        QFile saveFile(outFile);
        if (!saveFile.open(QFile::WriteOnly | QFile::Text))
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Cannot open file %1!")
                                .arg(outFile));
                return;
        }
        QTextStream out(&saveFile);

        QRegExp reWC("\\w");  // Word Character
        QRegExp regExp("\\s+|\\t+");  // Space(s) or Tab(s)
        QString oneRow;
        QStringList oneRowList;
        QString oneRow2;
        QStringList oneRowList2;
        QApplication::setOverrideCursor(Qt::WaitCursor);
        while (!(oneRow = in.readLine()).isNull())
        {
        	oneRow2 = in2.readLine();
                oneRowList2 = oneRow2.split(regExp, QString::SkipEmptyParts);
                oneRowList = oneRow.split(regExp, QString::SkipEmptyParts);
		out << oneRowList2[0] << " " << oneRowList2[1] << " " << oneRowList2[2] << " "
		<< oneRowList[0] << " " << oneRowList[1] << " " << oneRowList[2] << endl;
        }
        QApplication::restoreOverrideCursor();
        file.close();
        file2.close();

        saveFile.close();
}

void LFMMGUI::nothing2zscore(const QString &inFile, 
        const QString &outFile, const int L )
{
	int i = 0;
        static QList< int > res;
        res.clear();

        QFile file(inFile);
        if (!file.open(QFile::ReadOnly | QFile::Text)) 
        {
                QMessageBox::warning(this, GUI_TITLE,
                        tr("Cannot verify data file %1!").arg(inFile));
        }
        QTextStream in(&file);

        QFile saveFile(outFile);
        if (!saveFile.open(QFile::WriteOnly | QFile::Text))
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Cannot open file %1!")
                                .arg(outFile));
                return;
        }
        QTextStream out(&saveFile);

        QRegExp reWC("\\w");  // Word Character
        QRegExp regExp("\\s+|\\t+");  // Space(s) or Tab(s)
        QString oneRow;
        QStringList oneRowList;
        QApplication::setOverrideCursor(Qt::WaitCursor);
        while (!(oneRow = in.readLine()).isNull())
        {
		i++;
                oneRowList = oneRow.split(regExp, QString::SkipEmptyParts);
                out << "SNP_" << i << " 0 " << i << " " << oneRowList[0] 
		<< " " << oneRowList[1] << " " << oneRowList[2] << endl;
        }
        QApplication::restoreOverrideCursor();
        file.close();

        saveFile.close();
}

void LFMMGUI::cleReadStandardError()
{
}

void LFMMGUI::cleReadStandardOutput()
{
	infoTextEdit->append(QString(cle->readAll()));
}

void LFMMGUI::cleStarted()
{
	infoTextEdit->append(tr("%1 (%2) started and is running. Please wait...\n")
			.arg(CMD_TITLE)
			.arg(newRun.T));
}

void LFMMGUI::cleStateChanged(QProcess::ProcessState newState)
{
	cleState = newState;
	updateMenus();
}

void LFMMGUI::createActions()
{
	// File
	openDataAct = new QAction(QIcon(":/images/filedata.png"), 
			tr("Open &Data"), this);
	openDataAct->setShortcut(tr("Ctrl+D"));
	openDataAct->setStatusTip(tr("Open %1 data").arg(GUI_TITLE));
	connect(openDataAct, SIGNAL(triggered()), this, SLOT(openData()));

	newProjectAct = new QAction(QIcon(":/images/filenew.png"), 
			tr("&New Project"), this);
	newProjectAct->setShortcut(tr("Ctrl+N"));
	newProjectAct->setStatusTip(tr("Create a new %1 project").arg(GUI_TITLE));
	connect(newProjectAct, SIGNAL(triggered()), this, SLOT(newProject()));

	openProjectAct = new QAction(QIcon(":/images/fileopen.png"), 
			tr("&Open Project"), this);
	openProjectAct->setShortcut(tr("Ctrl+O"));
	openProjectAct->setStatusTip(tr("Open an existing %1 project").arg(GUI_TITLE));
	connect(openProjectAct, SIGNAL(triggered()), this, SLOT(openProject()));

	removeRunAct = new QAction(QIcon(":/images/removerun.png"), 
			tr("&Remove Run"), this);
	removeRunAct->setShortcut(tr("Ctrl+U"));
	removeRunAct->setStatusTip(tr("Remove a run form %1 project").arg(GUI_TITLE));
	connect(removeRunAct, SIGNAL(triggered()), this, SLOT(removeRun()));

	closeProjectAct = new QAction(QIcon(":/images/fileclose.png"), 
			tr("&Close Project"), this);
	closeProjectAct->setStatusTip(tr("Close the opened %1 project").arg(GUI_TITLE));
	connect(closeProjectAct, SIGNAL(triggered()), this, SLOT(closeProject()));

	/*
	saveProjectAct = new QAction(QIcon(":/images/filesave.png"), 
			tr("&Save Project"), this);
	saveProjectAct->setShortcut(tr("Ctrl+S"));
	saveProjectAct->setStatusTip(tr("Save the current %1 project").arg(GUI_TITLE));
	connect(saveProjectAct, SIGNAL(triggered()), this, SLOT(saveProject()));
	*/

	recentProjectSeparatorAct = new QAction(this);
	recentProjectSeparatorAct->setSeparator(true);

	for (int i = 0; i < MAX_RECENT_PROJECTS; i++) 
	{
		recentProjectActs[i] = new QAction(this);
		recentProjectActs[i]->setVisible(false);
		connect(recentProjectActs[i], SIGNAL(triggered()), 
				this, SLOT(openRecentProject()));
	}

	runAct = new QAction(QIcon(":/images/projectrun.png"), 
			tr("&Create Run"), this);
	runAct->setShortcut(tr("Ctrl+R"));
	runAct->setStatusTip(tr("Run %1 project").arg(GUI_TITLE));
	connect(runAct, SIGNAL(triggered()), this, SLOT(run()));

	abortAct = new QAction(QIcon(":/images/projectabort.png"), 
			tr("&Abort Run"), this);
	abortAct->setStatusTip(tr("Abort running %1 project").arg(GUI_TITLE));
	connect(abortAct, SIGNAL(triggered()), this, SLOT(abort()));

	// Windows
	closeAct = new QAction(tr("Cl&ose"), this);
	closeAct->setShortcut(tr("Ctrl+F4"));
	closeAct->setStatusTip(tr("Close the active window"));
	connect(closeAct, SIGNAL(triggered()), workspace, SLOT(closeActiveWindow()));

	closeAllAct = new QAction(tr("Close &All"), this);
	closeAllAct->setStatusTip(tr("Close all the windows"));
	connect(closeAllAct, SIGNAL(triggered()), workspace, SLOT(closeAllWindows()));

	tileAct = new QAction(tr("&Tile"), this);
	tileAct->setStatusTip(tr("Tile the windows"));
	connect(tileAct, SIGNAL(triggered()), workspace, SLOT(tile()));

	cascadeAct = new QAction(tr("&Cascade"), this);
	cascadeAct->setStatusTip(tr("Cascade the windows"));
	connect(cascadeAct, SIGNAL(triggered()), workspace, SLOT(cascade()));

	arrangeAct = new QAction(tr("Arrange &Icons"), this);
	arrangeAct->setStatusTip(tr("Arrange the icons"));
	connect(arrangeAct, SIGNAL(triggered()), workspace, SLOT(arrangeIcons()));

	nextAct = new QAction(tr("Ne&xt"), this);
	nextAct->setShortcut(tr("Ctrl+F6"));
	nextAct->setStatusTip(tr("Move the focus to the next window"));
	connect(nextAct, SIGNAL(triggered()), workspace, SLOT(activateNextWindow()));

	previousAct = new QAction(tr("Pre&vious"), this);
	previousAct->setShortcut(tr("Ctrl+Shift+F6"));
	previousAct->setStatusTip(tr("Move the focus to the previous window"));
	connect(previousAct, SIGNAL(triggered()), 
			workspace, SLOT(activatePreviousWindow()));

	windowSeparatorAct = new QAction(this);
	windowSeparatorAct->setSeparator(true);

	// Help
	referenceAct = new QAction(QIcon(":/images/helpreference.png"), 
			tr("&Reference Manual"), this);
	referenceAct->setStatusTip(tr("Open the reference manual"));
	connect(referenceAct, SIGNAL(triggered()), this, SLOT(openReference()));
	aboutAct = new QAction(QIcon(":/images/helpabout.png"), tr("&About..."), this);
	aboutAct->setStatusTip(tr("Show the About box of %1").arg(GUI_TITLE));
	connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

	quitAct = new QAction(QIcon(":/images/filequit.png"), tr("&Quit"), this);
	quitAct->setShortcut(tr("Ctrl+Q"));
	quitAct->setStatusTip(tr("Quit %1").arg(GUI_TITLE));
	connect(quitAct, SIGNAL(triggered()), this, SLOT(quit()));

}

void LFMMGUI::createMenus()
{

	// File
	fileMenu = menuBar()->addMenu(tr("&Project"));
	fileMenu->addAction(openDataAct);
	fileMenu->addSeparator();
	fileMenu->addAction(newProjectAct);
	fileMenu->addAction(openProjectAct);
	fileMenu->addAction(closeProjectAct);
	fileMenu->addAction(recentProjectSeparatorAct);
	for (int i = 0; i < MAX_RECENT_PROJECTS; i++)
	{
		fileMenu->addAction(recentProjectActs[i]);
	}
	fileMenu->addSeparator();
	fileMenu->addAction(quitAct);
	updateRecentProjectActions();

	// Project
	projectMenu = menuBar()->addMenu(tr("&Run"));
	projectMenu->addAction(runAct);
	projectMenu->addAction(abortAct);
	projectMenu->addAction(removeRunAct);

	// Window
	//windowMenu = menuBar()->addMenu(tr("&Window"));
	//connect(windowMenu, SIGNAL(aboutToShow()), this, SLOT(updateWindowMenu()));

	//menuBar()->addSeparator();

	// Help
	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(referenceAct);
	helpMenu->addSeparator();
	helpMenu->addAction(aboutAct);
}

void LFMMGUI::createToolBars()
{
	int w = 40;
	int h = 40;
	// File
	fileToolBar = addToolBar(tr("File"));
	fileToolBar->setIconSize(QSize(w,h));
	fileToolBar->addAction(openDataAct);
	fileToolBar->addSeparator();
	fileToolBar->addAction(newProjectAct);
	fileToolBar->addAction(openProjectAct);
	fileToolBar->addAction(closeProjectAct);
	//fileToolBar->addAction(saveProjectAct);
	//fileToolBar->addSeparator();
	//fileToolBar->addAction(openGraphicalResultsAct);
	//fileToolBar->addAction(openTextualResultsAct);


	// Project
	projectToolBar = addToolBar(tr("Project"));
	projectToolBar->setIconSize(QSize(w,h));
	projectToolBar->addAction(runAct);
	projectToolBar->addAction(abortAct);
	projectToolBar->addAction(removeRunAct);

	// Help
	helpToolBar = addToolBar(tr("Help"));
	helpToolBar->setIconSize(QSize(w,h));
	helpToolBar->addAction(referenceAct);
	//helpToolBar->addSeparator();
	helpToolBar->addAction(aboutAct);
	helpToolBar->addAction(quitAct);
}

void LFMMGUI::createStatusBar()
{
	statusBar()->showMessage(tr("Ready"));
}

void LFMMGUI::createDockWindows()
{

	QFont courierFont("Courier", 9, QFont::Normal);


	QTabWidget *tabTree = new QTabWidget(centralZone);
	projectTreeWidget = new TreeWidget(tabTree);
	projectTreeWidget->setColumnCount(1);
	projectTreeWidget->setItemHidden(projectTreeWidget->headerItem(), true);
	//projectTreeWidget->setMinimumWidth(320);

	connect(projectTreeWidget, SIGNAL(runItemDeleted(QString)), 
			this, SLOT(deleteRunItem(QString)));
	tabTree->insertTab(1,projectTreeWidget,"Project Tree");

	tabMain = new QTabWidget(centralZone);

	//infoTextIntro = new TreeInfo(tabMain);
	//infoTextIntro->setColumnCount(1);
	//infoTextIntro->setItemHidden(infoTextIntro->headerItem(), true);
	/*
	infoTextIntro->setReadOnly(true);
	infoTextIntro->setCurrentFont(courierFont);
	infoTextIntro->setHtml("	<h4>LFM software </h4>"
			"<b>LFMM: A program for testing association between loci and environmental gradients using latent factor mixed models </b>  <br></p>"
			"Adaptation to local environments often occurs through natural selection acting on large number of alleles, each having a weak phenotypic effect. One way to detect those alleles is by identifying genetic polymorphisms that exhibit high correlation with some environmental gradient or with the variables used as proxies for ecological pressures. The LFM computer program includes an integrated framework based on population genetics, ecological modeling and statistical techniques for screening genomes for signatures of local adaptation. It implements fast algorithms using latent factor mixed models based on a variant of Bayesian principal component analysis in which residual population structure is introduced via unobserved factors." 
			"<br><br>"
			"</a>");
	*/
	//tabMain->insertTab(1,infoTextIntro,"General Informations");

	workspaceData = new QWorkspace; //TODO
	tabMain->insertTab(1,workspaceData,"Display Data");

	zscoreDialog = new ZscoreDialog(this);
	zscoreDialog->commonPath = project.path;
	tabMain->insertTab(2,zscoreDialog,"Z score");

	/*
	manhattanDialog = new QLabel(this);
	//manhattanDialog->commonPath = project.path;
	manhattanDialog->setPixmap(QPixmap("scripts/tmp.pdf", 0, Qt::AutoColor));
	tabMain->insertTab(4,manhattanDialog,"Manhattan Plot");
	*/

	summaryDialog = new SummaryDialog(this);
	summaryDialog->commonPath = project.path;
	//summaryDialog->setEnabled(false);
	tabMain->insertTab(3,summaryDialog,"Summary");

	infoTextEdit = new QTextEdit(centralZone);
	infoTextEdit->setReadOnly(true);
	infoTextEdit->setCurrentFont(courierFont);
	infoTextEdit->setLineWrapMode(QTextEdit::NoWrap);

	QHBoxLayout *hbox = new QHBoxLayout(centralZone);

	QSplitter *splitter1 = new QSplitter(Qt::Horizontal, centralZone);
	splitter1->addWidget(tabTree);
	splitter1->addWidget(tabMain);

	QSplitter *splitter2 = new QSplitter(Qt::Vertical, centralZone);
	splitter2->addWidget(splitter1);
	splitter2->addWidget(infoTextEdit);

	hbox->addWidget(splitter2);
	centralZone->setLayout(hbox);

}

DataWindow *LFMMGUI::createDataWindow(int EC, int ER)
{
	DataWindow *window = new DataWindow(0,EC,ER);
	workspaceData->addWindow(window);
	tabMain->setCurrentIndex(0);
	return window;
}

DataWindow *LFMMGUI::findDataWindow(const QString &fileName)
{
	QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

	foreach (QWidget *window, workspaceData->windowList()) 
	{
		DataWindow *dataWindow = qobject_cast<DataWindow *>(window);
		if (dataWindow && dataWindow->currentFile() == canonicalFilePath)
		{
			return dataWindow;
		}
	}

	return 0;
}

TextWindow *LFMMGUI::createTextWindow()
{
	TextWindow *window = new TextWindow;
	workspaceData->addWindow(window);
	tabMain->setCurrentIndex(0);
	return window;
}

TextWindow *LFMMGUI::findTextWindow(const QString &fileName)
{
	QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

	foreach (QWidget *window, workspaceData->windowList()) 
	{
		TextWindow *textWindow = qobject_cast<TextWindow *>(window);
		if (textWindow && textWindow->currentFile() == canonicalFilePath)
		{
			return textWindow;
		}
	}

	return 0;
}

bool LFMMGUI::loadData(const QString &fullDataPath, int EC, int ER)
{
	if (!fullDataPath.isEmpty())
	{
		DataWindow *existingWindow = findDataWindow(fullDataPath);
		if (existingWindow) 
		{
			workspaceData->closeAllWindows();
		}

		tabMain->setCurrentIndex(0);
		DataWindow *window = createDataWindow(EC,ER);
		if (window->loadFile(fullDataPath))
		{
			window->showMaximized();
			statusBar()->showMessage(tr("%1 Loaded").arg(fullDataPath), 2000);
			return true;
		}
	}

	return false;
}

bool LFMMGUI::loadProject(const QString &projectName)
{
	if (!projectName.isEmpty())
	{
		if (!readProjectSettings(projectName))
		{
			return false;
		}
		if (!populateProjectTreeWidget())
		{
			return false;
		}
		if (!loadData(project.path + "/" + project.data,0,0))
		{
			return false;
		}

		projectOpened = true;

		setCurrentProject(projectName);

		setDefaultRunParameters();

		zscoreDialog->project = &(project);
		summaryDialog->project = &(project);
		if (!zscoreDialog->initZscore())
		{
			return false;
		}
		if (!summaryDialog->initSummary())
		{
			return false;
		}
		return true;
	}

	return false;
}

bool LFMMGUI::readProjectSettings(const QString &projectName)
{
	if (!projectName.isEmpty())
	{
		QFileInfo projectInfo(projectName);
		project.name = projectInfo.fileName();
		project.path = projectInfo.absolutePath();

		QSettings projectSettings(projectName, QSettings::IniFormat);

		QString projectSignature = 
			projectSettings.value(tr("projectSignature")).toString();
		if (projectSignature != tr("%1 Project").arg(GUI_TITLE))
		{
			// Invalid Project
			return false;
		}

		// Project Information
		projectSettings.beginGroup(tr("projectInfo"));
		project.date = projectSettings.value(tr("date")).toString();
		project.data = projectSettings.value(tr("data")).toString();
		project.data_prev = projectSettings.value(tr("dataPrev")).toString();
		//project.hasGeoData = projectSettings.value(tr("hasGeo"), false).toBool();  // For Backward Compatibility
		project.geoData = projectSettings.value(tr("geoData")).toString();
		project.hasNameData = projectSettings.value(tr("hasName"), false).toBool();  // For Backward Compatibility
		project.nameData = projectSettings.value(tr("nameData")).toString();
		projectSettings.endGroup();

		// Data Information
		projectSettings.beginGroup(tr("dataInfo"));
		project.N = projectSettings.value(tr("N")).toString();
		project.L = projectSettings.value(tr("L")).toString();
		project.D = projectSettings.value(tr("D")).toString();
		project.M = projectSettings.value(tr("M")).toString();
		projectSettings.endGroup();

		// Run Information
		projectSettings.beginGroup(tr("runInfo"));
		project.i = projectSettings.value(tr("i")).toInt();
		projectSettings.endGroup();

		// Project Runs
		project.runs.clear();
		int size = projectSettings.beginReadArray(tr("runs"));
		for (int i = 0; i < size; i++) 
		{
			projectSettings.setArrayIndex(i);
			Run run;
			run.name = projectSettings.value(tr("name")).toString();
			run.date = projectSettings.value(tr("date")).toString();
			run.T    = projectSettings.value(tr("T"), tr("Gibbs Sampler")).toString();  // For Backward Compatibility
			run.K    = projectSettings.value(tr("K")).toString();
			run.D    = projectSettings.value(tr("D")).toString();
			run.toK    = projectSettings.value(tr("toK")).toString();
			run.P    = projectSettings.value(tr("P")).toString();
			run.S    = projectSettings.value(tr("S")).toString();
			run.B    = projectSettings.value(tr("B")).toString();
			//run.LH   = projectSettings.value(tr("LH")).toString();
			run.ZS   = projectSettings.value(tr("ZS")).toString();
			run.Deviance   = projectSettings.value(tr("Deviance")).toString();
			run.DIC   = projectSettings.value(tr("DIC")).toString();
			run.nbThread   = projectSettings.value(tr("nbThread")).toString();
			project.runs.append(run);
			//addRunSnps(&run); 
		}
		projectSettings.endArray();

		return true;
	}
	return false;
}

bool LFMMGUI::populateProjectTreeWidget()
{
	projectTreeWidget->clear();

	projectItem = new QTreeWidgetItem(projectTreeWidget, 
			QStringList(QFileInfo(project.path + "/" + project.name).baseName()));

	// Project Information
	QTreeWidgetItem *projectInfoItem = new QTreeWidgetItem(projectItem, 
			QStringList(QString(tr("Project Information"))));
	new QTreeWidgetItem(projectInfoItem, 
			QStringList(QString(tr("Name:\t%1")).arg(project.name)));
	new QTreeWidgetItem(projectInfoItem, 
			QStringList(QString(tr("Date:\t%1")).arg(project.date)));
	new QTreeWidgetItem(projectInfoItem, 
			QStringList(QString(tr("Path:\t%1")).arg(project.path)));
	new QTreeWidgetItem(projectInfoItem, 
			QStringList(QString(tr("Data lfmm:\t%1")).arg(project.data)));
	new QTreeWidgetItem(projectInfoItem, 
			QStringList(QString(tr("Data:\t%1")).arg(project.data_prev)));

	//if (project.hasGeoData)
	//{
		new QTreeWidgetItem(projectInfoItem, 
				QStringList(QString(tr("Env:\t%1")).arg(project.geoData)));
	//}

	if (project.hasNameData)
	{
		new QTreeWidgetItem(projectInfoItem, QStringList(QString(tr("SNP name: %1")).arg(project.nameData)));
	}

	// Data Information
	QTreeWidgetItem *dataInfoItem = new QTreeWidgetItem(projectItem, 
			QStringList(QString(tr("Data Information"))));
	new QTreeWidgetItem(dataInfoItem, 
			QStringList(QString(tr("Individuals:\t\t%1")).arg(project.N)));
	new QTreeWidgetItem(dataInfoItem, 
			QStringList(QString(tr("Loci:\t\t%1")).arg(project.L)));
	new QTreeWidgetItem(dataInfoItem, 
			QStringList(QString(tr("Variables:\t\t%1")).arg(project.D)));
	/*
	new QTreeWidgetItem(dataInfoItem, 
			QStringList(QString(tr("Missing Value:\t%1")).arg(project.M)));
	*/

	int i;

	// Project Runs
	projectRunsItem = new QTreeWidgetItem(projectItem, 
			QStringList(QString(tr("Project Runs"))));
	for (i = 0; i < project.runs.size(); i++)
	{
		QTreeWidgetItem *runNameItem = new QTreeWidgetItem(projectRunsItem, 
				QStringList(project.runs[i].name));

		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("Date:\t\t %1"))
					.arg(project.runs[i].date)));

		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("Algorithm:\t\t %1"))
					.arg(project.runs[i].T)));

		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("Latent Factors:\t %1"))
					.arg(project.runs[i].K)));

		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("Environmental variable:\t %1"))
					.arg(project.runs[i].D)));

		// TODO print the number of thread
		/*
		   new QTreeWidgetItem(runNameItem, 
		   QStringList(QString(tr("DIC: %1"))
		   .arg(project.runs[i].DIC)));

		   if (!newRun.q || project.runs[i].admMod != "BYM")
		   {
		   new QTreeWidgetItem(runNameItem, 
		   QStringList(QString(tr("Spatial Interaction Parameter (init. value): %1"))
		   .arg(project.runs[i].P)));
		   }
		 */

		if (project.runs[i].T == tr("Gibbs Sampler")) // && project.runs[i].q)
		{
			new QTreeWidgetItem(runNameItem, 
					QStringList(QString(tr("Effective Sweeps:\t %1"))
						.arg(project.runs[i].S)));
			new QTreeWidgetItem(runNameItem, 
					QStringList(QString(tr("Burning Sweeps:\t %1"))
						.arg(project.runs[i].B)));
		}
		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("Processes:\t\t %1"))
					.arg(project.runs[i].nbThread)));

		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("Zscore Table:\t%1"))
					.arg(project.runs[i].ZS)));
		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("Deviance:\t\t%1"))
					.arg(project.runs[i].Deviance)));
		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("DIC:\t\t%1"))
					.arg(project.runs[i].DIC)));
	}

	projectTreeWidget->expandItem(projectItem);
	projectTreeWidget->expandItem(projectRunsItem);

	return true;
}

void LFMMGUI::loadText(const QString &fileName)
{
	if (!fileName.isEmpty())
	{
		TextWindow *existingWindow = findTextWindow(fileName);
		if (existingWindow) 
		{
			workspaceData->setActiveWindow(existingWindow);
			tabMain->setCurrentIndex(0);
			return;
		}

		TextWindow *window = createTextWindow();
		if (window->loadFile(fileName))
		{
			window->showMaximized();
			statusBar()->showMessage(tr("%1 Loaded").arg(fileName), 2000);
		}
		else
		{
			window->close();
		}
	}
}

void LFMMGUI::setCurrentProject(const QString &projectName)
{
	// TO CHECK
	currentProject = projectName;

	QSettings settings(tr("SuperSoft"), GUI_TITLE);
	QStringList projects = settings.value(tr("recentProjectList")).toStringList();
	projects.removeAll(projectName);
	projects.prepend(projectName);
	while (projects.size() > MAX_RECENT_PROJECTS)
	{
		projects.removeLast();
	}
	settings.setValue(tr("recentProjectList"), projects);
	updateRecentProjectActions();
}

void LFMMGUI::updateRecentProjectActions()
{
	QSettings settings(tr("SuperSoft"), GUI_TITLE);
	QStringList projects = settings.value(tr("recentProjectList")).toStringList();

	int numRecentProjects = qMin(projects.size(), MAX_RECENT_PROJECTS);

	for (int i = 0; i < numRecentProjects; i++) 
	{
		QString text = tr("Recent Project &%1: %2")
			.arg(i + 1).arg(strippedProjectName(projects[i]));
		recentProjectActs[i]->setText(text);
		recentProjectActs[i]->setData(projects[i]);
		recentProjectActs[i]->setVisible(true);
	}
	for (int j = numRecentProjects; j < MAX_RECENT_PROJECTS; j++)
	{
		recentProjectActs[j]->setVisible(false);
	}

	recentProjectSeparatorAct->setVisible(numRecentProjects > 0);
}

QString LFMMGUI::strippedProjectName(const QString &projectName)
{
	return QFileInfo(projectName).fileName();
}

bool LFMMGUI::writeProjectSettings(const QString &projectName)
{
	if (!projectName.isEmpty())
	{
		QSettings projectSettings(projectName, QSettings::IniFormat);

		// Project Signature
		QString projectSignature = tr("%1 Project").arg(GUI_TITLE);
		projectSettings.setValue(tr("projectSignature"), projectSignature);

		// Project Information
		projectSettings.beginGroup(tr("projectInfo"));
		projectSettings.setValue(tr("date"), project.date);
		projectSettings.setValue(tr("data"), project.data);
		projectSettings.setValue(tr("dataPrev"), project.data_prev);
		//projectSettings.setValue(tr("hasGeo"),project.hasGeoData);	//hasGeo: geographic distances loaded ?
		projectSettings.setValue(tr("geoData"),project.geoData);
		projectSettings.setValue(tr("hasName"),project.hasNameData);	//hasName: geographic distances loaded ?
		projectSettings.setValue(tr("nameData"),project.nameData);
		projectSettings.endGroup();

		// Data Information
		projectSettings.beginGroup(tr("dataInfo"));
		projectSettings.setValue(tr("N"), project.N);
		projectSettings.setValue(tr("L"), project.L);
		projectSettings.setValue(tr("D"), project.D);
		projectSettings.setValue(tr("M"), project.M);

		projectSettings.endGroup();

		// Run Information
		projectSettings.beginGroup(tr("runInfo"));
		projectSettings.setValue(tr("i"), project.i);
		projectSettings.endGroup();

		// Project Runs
		projectSettings.beginWriteArray(tr("runs"));
		for (int i = 0; i < project.runs.size(); i++) 
		{
			//currentrun = project.path + "/" + project.runs.at(i).name + "/" + "zscore.tr";
			projectSettings.setArrayIndex(i);
			projectSettings.setValue(tr("name"), project.runs.at(i).name);
			projectSettings.setValue(tr("date"), project.runs.at(i).date);
			projectSettings.setValue(tr("T"),    project.runs.at(i).T);
			projectSettings.setValue(tr("K"),    project.runs.at(i).K);
			projectSettings.setValue(tr("D"),    project.runs.at(i).D);
			projectSettings.setValue(tr("nbThread"),    project.runs.at(i).nbThread);
			projectSettings.setValue(tr("P"),    project.runs.at(i).P);
			projectSettings.setValue(tr("S"),    project.runs.at(i).S);
			projectSettings.setValue(tr("B"),    project.runs.at(i).B);
			//projectSettings.setValue(tr("LH"),   project.runs.at(i).LH);
			projectSettings.setValue(tr("ZS"),   project.runs.at(i).ZS);
			projectSettings.setValue(tr("Deviance"),   project.runs.at(i).Deviance);
			projectSettings.setValue(tr("DIC"),   project.runs.at(i).DIC);
		}
		projectSettings.endArray();

		return true;
	}

	return false;
}

void LFMMGUI::closeData(const QString &fileName)
{
	foreach (QWidget *window, workspaceData->windowList()) 
	{
		DataWindow *dataWindow = qobject_cast<DataWindow *>(window);
		if (dataWindow && dataWindow->currentFile() == fileName)
		{
			dataWindow->close();
		}
	}
}

/*
void LFMMGUI::closeGraph(const QString &fileName)
{
	foreach (QWidget *window, workspace->windowList()) 
	{
		GraphWindow *graphWindow = qobject_cast<GraphWindow *>(window);
		if (graphWindow && graphWindow->currentFile() == fileName)
		{
			graphWindow->close();
		}
	}
}
*/

void LFMMGUI::closeText(const QString &fileName)
{
	foreach (QWidget *window, workspaceData->windowList()) 
	{
		TextWindow *textWindow = qobject_cast<TextWindow *>(window);
		if (textWindow && textWindow->currentFile() == fileName)
		{
			textWindow->close();
		}
	}
}

void LFMMGUI::setDefaultRunParameters()
{
	oldRun.T = tr("Gibbs Sampler");
	oldRun.N = "1";
	oldRun.baseK = "";
	oldRun.toK = "";
	oldRun.nbThread = "1";
	oldRun.P = "0.6";
	oldRun.S = "10000";
	oldRun.B = "1000";
	oldRun.V = "1";
	oldRun.script = false;
}

void LFMMGUI::performMRun()
{
	mainRun = true;

	// TODO
	/*
	if (totMRun == 1)
	{
		infoTextEdit->append(QString(tr("Run %1:\n")).arg(newRun.T));
	}

	if (totMRun > 1)
	{
		if (currMRun > 0)
		{
			infoTextEdit->append("\n\n");
		}
		infoTextEdit->append(QString(tr("Run %1 of %2 Runs %3:\n"))
				.arg(currMRun + 1)
				.arg(totMRun)
				.arg(newRun.T));
	}
	*/

	if (newRun.script)
	{
		newRun.K = QString::number((newRun.baseK.toInt() + currMRun / newRun.N.toInt()));
	}

	project.i++;
	newRun.D = newRun.var[currDRun];
	newRun.name = QFileInfo(project.name).baseName() + tr("_RUN_") 
		+ QString("%1").arg(project.i, 6, 10, QChar('0'));
	newRun.ZS = tr("zscore.txt"); //TODO

	oldRun.T = newRun.T;
	oldRun.N = newRun.N;
	oldRun.K = newRun.K;
	oldRun.baseK = newRun.K;
	oldRun.toK = newRun.toK;
	oldRun.nbThread = newRun.nbThread;
	oldRun.script = newRun.script;
	oldRun.P = newRun.P;
	oldRun.S = newRun.S;
	oldRun.B = newRun.B;
	oldRun.V = newRun.V;

	QString fullRunPath = project.path + "/" + newRun.name;
	QDir runDir;
	runDir.mkdir(fullRunPath);

	QString dataName = project.path + "/" + project.data;
	QString envName = project.path + "/" + project.geoData;
	QString zscoreName = project.path + "/" + newRun.name + "/" + newRun.ZS;
	QString devName = project.path + "/" + newRun.name + "/DIC.txt";

	QString cmdLine;
#ifdef Q_WS_WIN

	if (newRun.T == tr("Gibbs Sampler"))
	{
		cmdLine = 

			tr("code\\LFMM.exe -n %1 -L %2 -K %3 -i %4 -b %5 -g \"%7\" -v \"%8\" -o \"%9\" -p %10 -C \"%11\" -D %12 -d %13 -m") 
			.arg(project.N)
			.arg(project.L)
			.arg(newRun.K)
			.arg(newRun.S)
			.arg(newRun.B)
			.arg(dataName)
			.arg(envName)
			.arg(zscoreName)
			.arg(newRun.nbThread)
			.arg(devName)
			.arg(project.D)
			.arg(newRun.D);
	}

#endif
#ifdef Q_WS_X11

	if (newRun.T == tr("Gibbs Sampler"))
	{
		cmdLine = 
			tr("./code/LFMM -n %1 -L %2 -K %3 -i %4 -b %5 -g \"%7\" -v \"%8\" -o \"%9\" -p %10 -C \"%11\" -D \"%12\" -d %13 -m") 
			.arg(project.N)
			.arg(project.L)
			.arg(newRun.K)
			.arg(newRun.S)
			.arg(newRun.B)
			.arg(dataName)
			.arg(envName)
			.arg(zscoreName)
			.arg(newRun.nbThread)
			.arg(devName)
			.arg(project.D)
			.arg(newRun.D);
	}

#endif

#ifdef Q_WS_MAC
	   QString applPath = QCoreApplication::applicationDirPath();
	   if (applPath.contains(QChar(' ')))
	   {
	   	applPath = "\"" + applPath + "\""; 
	   }
	   if (newRun.T == tr("Gibbs Sampler"))
	   {
	   cmdLine = 
	   applPath + tr("/code/LFMM -n %1 -L %2 -K %3 -i %4 -b %5 -g \"%7\" -v \"%8\" -o \"%9\" -p %10 -C \"%11\" -D \"%12\" -d %13 -m") 
			.arg(project.N)
			.arg(project.L)
			.arg(newRun.K)
			.arg(newRun.S)
			.arg(newRun.B)
			.arg(dataName)
			.arg(envName)
			.arg(zscoreName)
			.arg(newRun.nbThread)
			.arg(devName)
			.arg(project.D)
			.arg(newRun.D);
	   }
#endif
	

/*
#ifndef Q_WS_MAC
	this->setEnabled(false);
#endif
*/
	cle->start(cmdLine);
/*
#ifndef Q_WS_MAC
	this->setEnabled(true);
#endif
*/

}


void LFMMGUI::addMRunToProject()
{



	project.runs.append(newRun);

	if (projectRunsItem)
	{
		runNameItem = new QTreeWidgetItem(projectRunsItem, 
				QStringList(newRun.name));

		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("Date:\t %1"))
					.arg(newRun.date)));
		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("Algorithm:\t %1"))
					.arg(newRun.T)));

		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("Latent Factors:\t %1"))
					.arg(newRun.K)));

		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("Environmental variable:\t %1"))
					.arg(newRun.D)));

		if (newRun.T == tr("Gibbs Sampler")) // && project.runs[i].q)
		{
			new QTreeWidgetItem(runNameItem, 
					QStringList(QString(tr("Total Sweeps:\t %1"))
						.arg(newRun.S)));
			new QTreeWidgetItem(runNameItem, 
					QStringList(QString(tr("Burning Sweeps:\t %1"))
						.arg(newRun.B)));
		}
		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("Processes:\t\t %1"))
					.arg(newRun.nbThread)));

		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("Zscore Table:\t%1"))
					.arg(newRun.ZS)));
		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("Deviance:\t\t%1"))
					.arg(newRun.Deviance)));
		new QTreeWidgetItem(runNameItem, 
				QStringList(QString(tr("DIC:\t\t%1"))
					.arg(newRun.DIC)));

	}

	projectModified = true;
	saveProject();

	tabMain->setCurrentIndex(1);
	zscoreDialog->addRunToZscoreTable(true);
	summaryDialog->addRunToSummaryTable();

	updateMenus();
}

void LFMMGUI::addRunSnps(Run *crun) {
	// add result SNP table in run
	// TO CHANGE
	QString path = project.path + "/" + crun->name + "/" + "zscore.res";
	//QString path = project.path + "/" + "zscore.res";
	QFile file(path);
	if(file.open(QIODevice::ReadOnly)) {
		//QMessageBox::information(0, "error", file.errorString());

		QTextStream in(&file);

		crun->i = 0;
		for (int i=0; i<project.L.toInt(); i++) {
			(crun->i)++;
			QString line = in.readLine();
			QStringList fields = line.split(" ");
			Snp snp;
			//int in = crun->i;
			snp.name = fields[0];
			snp.chromosome = fields[1];
			snp.position = fields[2];
			snp.zscore = fields[3];
			snp.pvalue = fields[4];
			snp.lpvalue = fields[5];
			//crun->snps.append(snp);
			/*
			printf("%s\n",qPrintable(snp.name));
			printf("%s\n",qPrintable(snp.chromosome));
			printf("%s\n",qPrintable(snp.position));
			printf("%s\n",qPrintable(snp.zscore));
			printf("%s\n",qPrintable(snp.pvalue));
			printf("%s\n",qPrintable(snp.mlog10pvalue));
			*/
		}
	}
 //       printf("name %s\n",qPrintable(crun->snps[0].name));

}

void LFMMGUI::createManhattan()
{
	zscoreDialog->createZscoreTableToPlot();

	QString table= "\"" + project.path + "/manhattan_table.txt\"";
	QString toHighlight= "\"" + project.path + "/toHighlight_table.txt\"";
	QString plot= "\"" + project.path + "/manhattan_plot.pdf\"";
	QString plot2= project.path + "/manhattan_plot.pdf";
	QString cmdLine;


#ifdef Q_WS_WIN
	cmdLine = "R-2.14.1\\bin\\Rscript scripts/manhattan.R " + table + " " + toHighlight + " " + plot; 
#endif

#ifdef Q_WS_X11
	cmdLine = "Rscript scripts/manhattan.R " + table + " " + toHighlight + " " + plot; 
#endif

#ifdef Q_WS_MAC
	   QString applPath = "";//QCoreApplication::applicationDirPath();
	   if (applPath.contains(QChar(' ')))
	   {
	   	applPath = "\"" + applPath + "\""; 
	   }
	   cmdLine = applPath + "Rscript scripts/manhattan.R " + table + " " + toHighlight + " " + plot; 
#endif
/*
#ifndef Q_WS_MAC
	this->setEnabled(false);
#endif
*/
	infoTextEdit->append(tr("%1, the creation of the manhattan plot started and is running. Please wait...\n")
		.arg(CMD_TITLE));
	cle2->start(cmdLine);
	cle2->waitForFinished();
	infoTextEdit->append(tr("%1, the creation of the manhattan plot ended without error.\n")
		.arg(CMD_TITLE));
/*
#ifndef Q_WS_MAC
	this->setEnabled(true);
#endif
*/	
        QFile newDataFile(plot2);
        if (!newDataFile.exists()) {
                        QMessageBox::critical(this, GUI_TITLE,
                        tr("An error happened during the creation of the pdf file.\n\n"
                        "Please, check the reference manual or the General informations panel and try again."));
        } else {

#ifdef Q_WS_MAC
	QString referenceFilePath = tr("file://") +  project.path + 
#endif
#ifdef Q_WS_WIN
	QString referenceFilePath = project.path + 
#endif
#ifdef Q_WS_X11
	QString referenceFilePath = project.path + 
#endif
		tr("/manhattan_plot.pdf");

//	referenceFilePath.replace(" ","\%20");

		//QUrl url(referenceFilePath);
        	QDesktopServices::openUrl(QUrl::fromLocalFile(referenceFilePath));
	}

}

void LFMMGUI::createGreenManhattan()
{
	zscoreDialog->createZscoreTableToPlotGreen();

	QString table= "\"" + project.path + "/manhattan_table.txt\"";
	QString toHighlight= "\"" + project.path + "/toHighlight_table.txt\"";
	QString plot= "\"" + project.path + "/manhattan_plot.pdf\"";
	QString plot2 = project.path + "/manhattan_plot.pdf";
	QString cmdLine;

#ifdef Q_WS_WIN
        cmdLine = "R-2.14.1\\bin\\Rscript scripts/manhattan.R " + table + " " + toHighlight + " " + plot;
#endif

#ifdef Q_WS_X11
        cmdLine = "Rscript scripts/manhattan.R " + table + " " + toHighlight + " " + plot;
#endif

#ifdef Q_WS_MAC
           QString applPath = "";//QCoreApplication::applicationDirPath();
           if (applPath.contains(QChar(' ')))
           {
                applPath = "\"" + applPath + "\"";
           }
           cmdLine = applPath + "Rscript scripts/manhattan.R " + table + " " + toHighlight + " " + plot; 
#endif


/*
#ifndef Q_WS_MAC
	this->setEnabled(false);
#endif
*/
	infoTextEdit->append(tr("%1, the creation of the manhattan plot started and is running. Please wait...\n")
		.arg(CMD_TITLE));
	cle2->start(cmdLine);
	cle2->waitForFinished();
	infoTextEdit->append(tr("%1, the creation of the manhattan plot ended without error.\n")
		.arg(CMD_TITLE));
/*
#ifndef Q_WS_MAC
	this->setEnabled(true);
#endif
*/	
        QFile newDataFile(plot2);
        if (!newDataFile.exists()) {
                        QMessageBox::critical(this, GUI_TITLE,
                        tr("An error happened during the creation of the pdf file.\n\n"
                        "Please, check the reference manual or the General informations panel and try again."));
        } else {
#ifdef Q_WS_MAC
	QString referenceFilePath = tr("file://") +  project.path + 
#endif
#ifdef Q_WS_WIN
	QString referenceFilePath = project.path + 
#endif
#ifdef Q_WS_X11
	QString referenceFilePath = project.path + 
#endif
		tr("/manhattan_plot.pdf");
//	referenceFilePath.replace(" ","\%20");
//		printf("%s\n",qPrintable(referenceFilePath));
		//QUrl url(referenceFilePath);
        	//QUrl url(plot);
        	QDesktopServices::openUrl(QUrl::fromLocalFile(referenceFilePath));
        	//QDesktopServices::openUrl(url);
	}

}
