/*
    LFMM GUI, file: newprojectdialog.cpp
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


#include <QtCore>
#include <QtGui>
#include "newprojectdialog.h"
#include "datawindow.h"
#include "title.h"

NewProjectDialog::NewProjectDialog(QWidget *parent)
    : QDialog(parent)
{
	setWindowTitle(tr("New Project"));

	// Name
	QLabel *nameLabel = new QLabel(tr("Project Name:"));
	nameLineEdit = new QLineEdit;
	QToolButton *nameHelp = new QToolButton;
	nameHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
	nameHelp->setText(tr("name"));
	nameHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
	nameHelp->setAutoRaise(true);
	nameHelp->setStatusTip(tr("Help"));
	connect(nameHelp, SIGNAL(clicked()), this, SLOT(help()));

	// Path
	QLabel *pathLabel = new QLabel(tr("Project Path:"));
	pathLineEdit = new QLineEdit;
	QToolButton *pathHelp = new QToolButton;
	pathHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
	pathHelp->setText(tr("path"));
	pathHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
	pathHelp->setAutoRaise(true);
	pathHelp->setStatusTip(tr("Help"));
	connect(pathHelp, SIGNAL(clicked()), this, SLOT(help()));

	QPushButton *browsePathPushButton = new QPushButton(tr("Browse..."));
	browsePathPushButton->setAutoDefault(false);
	connect(browsePathPushButton, SIGNAL(clicked()), this, SLOT(browsePath()));

	// Data format

	// Data
	QLabel *dataLabel = new QLabel(tr("Genotype Data File:"));
	dataLineEdit = new QLineEdit;
	connect(dataLineEdit, SIGNAL(textChanged(const QString &)), 
		this, SLOT(dataChanged()));
	QToolButton *dataHelp = new QToolButton;
	dataHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
	dataHelp->setText(tr("data"));
	dataHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
	dataHelp->setAutoRaise(true);
	dataHelp->setStatusTip(tr("Help"));
	connect(dataHelp, SIGNAL(clicked()), this, SLOT(help()));

	QPushButton *browseDataPushButton = new QPushButton(tr("Browse..."));
	browseDataPushButton->setAutoDefault(false);
	connect(browseDataPushButton, SIGNAL(clicked()), this, SLOT(browseData()));

	// Env
	QLabel *geoDataLabel = new QLabel(tr("Environmental File:"));
	geoDataLineEdit = new QLineEdit;
	connect(geoDataLineEdit, SIGNAL(textChanged(const QString &)), 
		this, SLOT(geoDataChanged()));
	QToolButton *geoDataHelp = new QToolButton;
	geoDataHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
	geoDataHelp->setText(tr("geodata"));
	geoDataHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
	geoDataHelp->setAutoRaise(true);
	geoDataHelp->setStatusTip(tr("Help"));
	connect(geoDataHelp, SIGNAL(clicked()), this, SLOT(help()));
	
	QPushButton *browseGeoDataPushButton = new QPushButton(tr("Browse..."));
	browseGeoDataPushButton->setAutoDefault(false);
	connect(browseGeoDataPushButton, SIGNAL(clicked()), this, SLOT(browseGeoData()));
	
	// snp
	QLabel *nameDataLabel = new QLabel(tr("Snp File (optional):"));
	nameDataLineEdit = new QLineEdit;
	connect(nameDataLineEdit, SIGNAL(textChanged(const QString &)), 
		this, SLOT(nameDataChanged()));
	QToolButton *nameDataHelp = new QToolButton;
	nameDataHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
	nameDataHelp->setText(tr("namedata"));
	nameDataHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
	nameDataHelp->setAutoRaise(true);
	nameDataHelp->setStatusTip(tr("Help"));
	connect(nameDataHelp, SIGNAL(clicked()), this, SLOT(help()));


	QPushButton *browseNameDataPushButton = new QPushButton(tr("Browse..."));
	browseNameDataPushButton->setAutoDefault(false);
	connect(browseNameDataPushButton, SIGNAL(clicked()), this, SLOT(browseNameData()));
	
	QGridLayout *projectInfoLayout = new QGridLayout;
	projectInfoLayout->addWidget(nameLabel, 0, 0);
	projectInfoLayout->addWidget(nameLineEdit, 0, 1);
	projectInfoLayout->addWidget(nameHelp, 0, 3);
	projectInfoLayout->addWidget(pathLabel, 1, 0);
	projectInfoLayout->addWidget(pathLineEdit, 1, 1);
	projectInfoLayout->addWidget(browsePathPushButton, 1, 2);
	projectInfoLayout->addWidget(pathHelp, 1, 3);
	projectInfoLayout->addWidget(dataLabel, 2, 0);
	projectInfoLayout->addWidget(dataLineEdit, 2, 1);
	projectInfoLayout->addWidget(browseDataPushButton, 2, 2);
	projectInfoLayout->addWidget(dataHelp, 2, 3);
	projectInfoLayout->addWidget(geoDataLabel, 3, 0);
	projectInfoLayout->addWidget(geoDataLineEdit, 3, 1);
	projectInfoLayout->addWidget(browseGeoDataPushButton, 3, 2);
	projectInfoLayout->addWidget(geoDataHelp, 3, 3);
	projectInfoLayout->addWidget(nameDataLabel, 4, 0);
	projectInfoLayout->addWidget(nameDataLineEdit, 4, 1);
	projectInfoLayout->addWidget(browseNameDataPushButton, 4, 2);
	projectInfoLayout->addWidget(nameDataHelp, 4, 3);

	QFrame *dataInfoFrame = new QFrame;
	dataInfoFrame->setFrameStyle(QFrame::HLine | QFrame::Sunken);

	viewDataPushButton = new QPushButton(tr("View Data..."));
	viewDataPushButton->setAutoDefault(false);
	viewDataPushButton->setEnabled(false);
	connect(viewDataPushButton, SIGNAL(clicked()), this, SLOT(viewData()));
	
	viewGeoDataPushButton = new QPushButton(tr("View Environmental Data..."));
	viewGeoDataPushButton->setAutoDefault(false);
	viewGeoDataPushButton->setEnabled(false);
	connect(viewGeoDataPushButton, SIGNAL(clicked()), this, SLOT(viewGeoData()));
	
	viewNameDataPushButton = new QPushButton(tr("View SNPs Data..."));
	viewNameDataPushButton->setAutoDefault(false);
	viewNameDataPushButton->setEnabled(false);
	connect(viewNameDataPushButton, SIGNAL(clicked()), this, SLOT(viewNameData()));
	

	QLabel *nLabel = new QLabel(tr("Number of Individuals:"));
	nLineEdit = new QLineEdit;
	QIntValidator *nV = new QIntValidator(this);
	nV->setBottom(1);
	nLineEdit->setValidator(nV);
	QToolButton *nLabelHelp = new QToolButton;
	nLabelHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
	nLabelHelp->setText(tr("nLabel"));
	nLabelHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
	nLabelHelp->setAutoRaise(true);
	nLabelHelp->setStatusTip(tr("Help"));
	connect(nLabelHelp, SIGNAL(clicked()), this, SLOT(help()));

	QLabel *lLabel = new QLabel(tr("Number of Loci:"));
	lLineEdit = new QLineEdit;
	QIntValidator *lV = new QIntValidator(this);
	lV->setBottom(1);
	lLineEdit->setValidator(lV);
	QToolButton *lLabelHelp = new QToolButton;
	lLabelHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
	lLabelHelp->setText(tr("lLabel"));
	lLabelHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
	lLabelHelp->setAutoRaise(true);
	lLabelHelp->setStatusTip(tr("Help"));
	connect(lLabelHelp, SIGNAL(clicked()), this, SLOT(help()));

        QLabel *dLabel = new QLabel(tr("Number of environmental variables:"));
        dLineEdit = new QLineEdit;
        QIntValidator *dV = new QIntValidator(this);
        dV->setBottom(1);
        dLineEdit->setValidator(dV);
        QToolButton *dLabelHelp = new QToolButton;
        dLabelHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        dLabelHelp->setText(tr("dLabel"));
        dLabelHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        dLabelHelp->setAutoRaise(true);
        dLabelHelp->setStatusTip(tr("Help"));
        connect(dLabelHelp, SIGNAL(clicked()), this, SLOT(help()));

	/*
	QLabel *mLabel = new QLabel(tr("Missing Data Value:"));
	mLineEdit = new QLineEdit;
	mLineEdit->setText(tr("-9"));
	QIntValidator *mV = new QIntValidator(this);
	mV->setTop(-1);
	mLineEdit->setValidator(mV);
	mLineEdit->setEnabled(false);
	QToolButton *mLabelHelp = new QToolButton;
	mLabelHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
	mLabelHelp->setText(tr("mLabel"));
	mLabelHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
	mLabelHelp->setAutoRaise(true);
	mLabelHelp->setStatusTip(tr("Help"));
	connect(mLabelHelp, SIGNAL(clicked()), this, SLOT(help()));
	*/

	QGridLayout *dataInfoLayout = new QGridLayout;
	dataInfoLayout->addWidget(viewDataPushButton, 0, 0);
	dataInfoLayout->addWidget(viewGeoDataPushButton, 0, 1);
	dataInfoLayout->addWidget(viewNameDataPushButton, 0, 2);
	dataInfoLayout->addWidget(nLabel, 1, 0);
	dataInfoLayout->addWidget(nLineEdit, 1, 1);
	dataInfoLayout->addWidget(nLabelHelp, 1, 4);
	dataInfoLayout->addWidget(lLabel, 4, 0);
	dataInfoLayout->addWidget(lLineEdit, 4, 1);
	dataInfoLayout->addWidget(lLabelHelp, 4, 4);
	dataInfoLayout->addWidget(dLabel, 5, 0);
	dataInfoLayout->addWidget(dLineEdit, 5, 1);
	dataInfoLayout->addWidget(dLabelHelp, 5, 4);
	/*
	dataInfoLayout->addWidget(mLabel, 5, 0);
	dataInfoLayout->addWidget(mLineEdit, 5, 1);
	dataInfoLayout->addWidget(mLabelHelp, 5, 4);
	*/

	QPushButton *okPushButton = new QPushButton(tr("OK"));
	okPushButton->setDefault(true);
	connect(okPushButton, SIGNAL(clicked()), this, SLOT(accept()));

	QPushButton *cancelPushButton = new QPushButton(tr("Cancel"));
	connect(cancelPushButton, SIGNAL(clicked()), this, SLOT(reject()));

	QHBoxLayout *buttonLayout = new QHBoxLayout;
	buttonLayout->addStretch();
	buttonLayout->addWidget(okPushButton);
	buttonLayout->addStretch();
	buttonLayout->addWidget(cancelPushButton);
	buttonLayout->addStretch();

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(projectInfoLayout);
	mainLayout->addWidget(dataInfoFrame);
	mainLayout->addLayout(dataInfoLayout);
	mainLayout->addStretch();
	mainLayout->addSpacing(5);
	mainLayout->addLayout(buttonLayout);

	setLayout(mainLayout);

}

NewProjectDialog::~NewProjectDialog()
{
}


void NewProjectDialog::accept()
{
	if (validate())
	{
		QDialog::accept();
	}
}

void NewProjectDialog::help()
{
	QToolButton *bt = qobject_cast<QToolButton *>(QObject::sender());
	if (bt->text() == tr("name")) {
	                QMessageBox::information(this, GUI_TITLE,
                                     tr("The project name is necessary to save your results to a unique file location.\n\nLater, you will be able to find and open your project from the file project_name.tp. We also recommend that users store different projects using separate directories for clear organization of information, although LFMM does not require this."));
	} else if (bt->text() == tr("path")) {
	                QMessageBox::information(this, GUI_TITLE,
                                     tr("The path of the project is the directory where all files from the project will be created.\n\nNote that LFMM requests its user to put his/her data in the same directory of the project file itself. We also recommend that users store different projects using separate directories for clear organization of information, although LFM does not require this."));
	} else if (bt->text() == tr("data")) {
	                QMessageBox::information(this, GUI_TITLE,
                                     tr("The genotype data file contains the genotype data.\n\nThis file is mandatory. The authorized data extensions are lfmm, ped, eigenstratgeno, and ancestrymap. You can display the file you provided by clicking on the \"View Data...\" button. For more specific information, please check the reference manual or the General information panel."));
	} else if (bt->text() == tr("geodata")) {
	                QMessageBox::information(this, GUI_TITLE,
                                     tr("The environmental data file contains the environmental variables.\n\nThis file is mandatory. The authorized data extension is env. You can display the file you provided by clicking on the \"View Environmental Data...\" button. For more specific information, please check the reference manual or the General information panel."));
	} else if (bt->text() == tr("namedata")) {
	                QMessageBox::information(this, GUI_TITLE,
                                     tr("The snp data file contains optional information on SNP locations, names, etc.\n\nIt is optional. The authorized data formats are lfmmsnp, pedsnp, map ,and snp. You can display the file you provided by clicking on the \"View SNPs Data...\" button. For more specific information, please check the reference manual or the General information panel."));
	} else if (bt->text() == tr("nLabel")) {
	                QMessageBox::information(this, GUI_TITLE,
                                     tr("Specify the number of individuals.\n\nIf you are not clear about this value, you can always click the \"View Data...\" and \"View Environmental Data...\" buttons to check the data first."));
	} else if (bt->text() == tr("Number of Dummy Individuals:")) {
	                QMessageBox::information(this, GUI_TITLE,
                                     tr("Specify the project name."));
	} else if(bt->text() == tr("Ploidy:")) {
	                QMessageBox::information(this, GUI_TITLE,
                                     tr("Specify the project name."));
	} else if (bt->text() == tr("lLabel")) {
	                QMessageBox::information(this, GUI_TITLE,
                                     tr("Specify the number of SNPs.\n\nIf you are not clear about this information, you can always click the \"View Data...\" and \"View SNPs Data...\" buttons to check the data first."));
	} else if (bt->text() == tr("dLabel")) {
	                QMessageBox::information(this, GUI_TITLE,
                                     tr("Specify the number of environmental variables.\n\nIf you are not clear about this information, you can always click the \"View Environmental Data...\" buttons to check the data first."));
	} else if (bt->text() == tr("mLabel")) {
	                QMessageBox::information(this, GUI_TITLE,
                                     tr("Specify the project name."));
	} else if (bt->text() == tr("Number of Extra Rows:")) {
	                QMessageBox::information(this, GUI_TITLE,
                                     tr("Specify the project name."));
	} else if (bt->text() == tr("Number of Extra Columns:")) {
	                QMessageBox::information(this, GUI_TITLE,
                                     tr("Specify the project name."));
	} 

}

/*
void NewProjectDialog::changeProjectDataFormat() {

        QString cmdLine;
        QString newData = pathLineEdit->text() + "/" + "data.lfmm";
        if (dataLineEdit->text().endsWith(tr(".ped")))
        {
                cmdLine =
           tr("perl scripts/ped2lfmm.pl %1 %2 %3 %4")
           .arg(dataLineEdit->text())
           .arg(newData)
           .arg(lLineEdit->text())
           .arg(nLineEdit->text());
        } else if (dataLineEdit->text().endsWith(tr(".ancestrymap")))
        {
                cmdLine =
           tr("perl ./scripts/ancestrymap2lfmm.pl %1 %2 %3 %4")
           .arg(dataLineEdit->text())
           .arg(newData)
           .arg(lLineEdit->text())
           .arg(nLineEdit->text());
        } else if (dataLineEdit->text().endsWith(tr(".eigenstratgeno")) || dataLineEdit->text().endsWith(tr(".geno")))
        {
                cmdLine =
           tr("perl ./scripts/eigenstrat2lfmm.pl %1 %2 %3 %4")
           .arg(dataLineEdit->text())
           .arg(newData)
           .arg(lLineEdit->text())
           .arg(nLineEdit->text());
        } else if (dataLineEdit->text().endsWith(tr(".lfmm")))
        {
                cmdLine =
           tr("echo \"Nothing to do !!!\"");
        }
          //      cmdLine =
          // tr("echo coucou");
	this->setEnabled(false);
	this->setEnabled(true);

}

void NewProjectDialog::eigenstratgeno2lfmm(const QString &inFile, 
	const QString &outFile, const int n, const int L )
{

	static QList< int > res;
	format.clear();

	QFile file(inFile);
	if (!file.open(QFile::ReadOnly | QFile::Text)) 
	{
		QMessageBox::warning(this, GUI_TITLE,
			tr("Cannot verify data file %1!").arg(data));
		return format;
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
				res.append(oneRow[i].toInteger());
		}
	}
	QApplication::restoreOverrideCursor();
	file.close();

        QFile saveFile(outFile);
        if (!saveFile.open(QFile::WriteOnly | QFile::Text))
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Cannot open file %1!")
                                .arg(popfileLineEdit->text()));
                return;
        }

        QTextStream out(&saveFile);

	for (int i = 0; i < n; i++)
	{
		for (int l = 0; l < L-1; l++)
		{
			out << res[l*n+i] << ' ';
		}
		out << res[(L-1)*n+i] << endl;
	}
        saveFile.close();


}
*/
void NewProjectDialog::browsePath()
{
	QString path = QFileDialog::getExistingDirectory(this, 
		tr("Choose Project Path"), projectPath);
	if (path.endsWith('/') || path.endsWith('\\'))
	{
		path = path.left(path.length() - 1);
	}
	if (!path.isEmpty())
	{
		pathLineEdit->setText(path);
		projectPath = path;
	}
}

void NewProjectDialog::browseData()
{
	QString data = QFileDialog::getOpenFileName(this, 
		tr("Choose Project Data File"), projectPath);
	if (!data.isEmpty())
	{
		/*
		if (data.endsWith(".ped")) {
			printf("coucou\n");
		}*/
		dataLineEdit->setText(data);
		projectPath = QFileInfo(data).absolutePath();
	}
}

void NewProjectDialog::browseGeoData()
{
	QString data = QFileDialog::getOpenFileName(this, 
			tr("Choose Geographic Distances File"), projectPath);
	if (!data.isEmpty())
	{
		geoDataLineEdit->setText(data);
	}
}

void NewProjectDialog::browseNameData()
{
	QString data = QFileDialog::getOpenFileName(this, 
			tr("Choose SNP name File"), projectPath);
	if (!data.isEmpty())
	{
		nameDataLineEdit->setText(data);
	}
}

void NewProjectDialog::geoDataChanged()
{
	viewGeoDataPushButton->setEnabled(!geoDataLineEdit->text().isEmpty());
}

void NewProjectDialog::nameDataChanged()
{
	viewNameDataPushButton->setEnabled(!nameDataLineEdit->text().isEmpty());
}

void NewProjectDialog::dataChanged()
{
	viewDataPushButton->setEnabled(!dataLineEdit->text().isEmpty());
}

void NewProjectDialog::viewGeoData()
{
	if (!QFile::exists(geoDataLineEdit->text()))
	{
		QMessageBox::warning(this, GUI_TITLE, 
				     tr("The specified geographic distances file does not exist."));
		return;
	}

	geoDataDialog = new QDialog(this,Qt::WindowTitleHint);
	geoDataDialog->setAttribute(Qt::WA_DeleteOnClose);
	geoDataDialog->setWindowTitle(tr("Geographic Distances File"));
	DataWindow *dataWidget = new DataWindow;
	QGridLayout *mainLayout = new QGridLayout;
	QPushButton *OK = new QPushButton(tr("OK"));
	mainLayout->addWidget(dataWidget,0,0,1,3);
	mainLayout->addWidget(OK,1,1,1,1);
	geoDataDialog->setLayout(mainLayout);
	geoDataDialog->resize(500, 320);
	connect(OK, SIGNAL(clicked()), this, SLOT(geoDataClose()));
	if (dataWidget->loadFile(geoDataLineEdit->text()))
	{
		geoDataDialog->exec();	
	}
	else
	{
		geoDataDialog->close();
	}
}

void NewProjectDialog::geoDataClose()
{
	geoDataDialog->close();
}

void NewProjectDialog::viewNameData()
{
	if (!QFile::exists(nameDataLineEdit->text()))
	{
		QMessageBox::warning(this, GUI_TITLE, 
				     tr("The specified SNP name file does not exist."));
		return;
	}

	nameDataDialog = new QDialog(this,Qt::WindowTitleHint);
	nameDataDialog->setAttribute(Qt::WA_DeleteOnClose);
	nameDataDialog->setWindowTitle(tr("SNP name File"));
	DataWindow *dataWidget = new DataWindow;
	QGridLayout *mainLayout = new QGridLayout;
	QPushButton *OK = new QPushButton(tr("OK"));
	mainLayout->addWidget(dataWidget,0,0,1,3);
	mainLayout->addWidget(OK,1,1,1,1);
	nameDataDialog->setLayout(mainLayout);
	nameDataDialog->resize(500, 320);
	connect(OK, SIGNAL(clicked()), this, SLOT(nameDataClose()));
	if (dataWidget->loadFile(nameDataLineEdit->text()))
	{
		nameDataDialog->exec();	
	}
	else
	{
		nameDataDialog->close();
	}
}

void NewProjectDialog::nameDataClose()
{
	nameDataDialog->close();
}

void NewProjectDialog::viewData()
{
	if (!QFile::exists(dataLineEdit->text()))
	{
		QMessageBox::warning(this, GUI_TITLE, 
			tr("The specified genotype data file does not exist."));
		return;
	}

	dataDialog = new QDialog(this,Qt::WindowTitleHint);
	dataDialog->setAttribute(Qt::WA_DeleteOnClose);
	dataDialog->setWindowTitle(tr("Project Data"));
	DataWindow *dataWidget = new DataWindow;
	QGridLayout *mainLayout = new QGridLayout;
	QPushButton *OK = new QPushButton(tr("OK"));
	mainLayout->addWidget(dataWidget,0,0,1,3);
	mainLayout->addWidget(OK,1,1,1,1);
	dataDialog->setLayout(mainLayout);
	dataDialog->resize(500, 320);
	connect(OK, SIGNAL(clicked()), this, SLOT(dataClose()));
	if (dataWidget->loadFile(dataLineEdit->text()))
	{
		dataDialog->exec();	
	}
	else
	{
		dataDialog->close();
	}
}

void NewProjectDialog::dataClose()
{
	dataDialog->close();
}

bool NewProjectDialog::validate()
{

	// Empty project Name
	if (nameLineEdit->text().isEmpty())
	{
		QMessageBox::warning(this, GUI_TITLE, tr("Project name cannot be empty."));
		return false;
	}

	// Empty or non-existent path Dir
	QDir path(pathLineEdit->text());
	if (pathLineEdit->text().isEmpty() || !path.exists())
	{
		QMessageBox::warning(this, GUI_TITLE, 
			tr("The specified project path does not exist."));
		return false;
	}

	// Project name already exists
	if (QFile::exists(pathLineEdit->text() + "/" + nameLineEdit->text() + ".tp"))
	{
		QMessageBox::warning(this, GUI_TITLE, 
			tr("A project with same name already exists.\n"
			"Please change the name of your project."));
		return false;
	}

	// Empty or non-existent GeoDataLine
	if (geoDataLineEdit->text().isEmpty() && !QFile::exists(geoDataLineEdit->text()))
	{
		QMessageBox::warning(this, GUI_TITLE, 
				     tr("The specified environmental data file is not correct.\n\nIf you provided it, check that the file exists."));
		return false;
	}
	
	// Empty or non-existent SNP File
	if (!nameDataLineEdit->text().isEmpty() && !QFile::exists(nameDataLineEdit->text()))
	{
		QMessageBox::warning(this, GUI_TITLE, 
				     tr("The specified SNP data file does not exist.\n\nIf you provided it, check that the file exists."));
		return false;
	}
	
	// Project Data empty or non-existent
	if (dataLineEdit->text().isEmpty() || !QFile::exists(dataLineEdit->text()))
	{
		QMessageBox::warning(this, GUI_TITLE, 
			tr("The specified genotype data file is not correct.\n\nIf you provided it, check that the file exists."));
		return false;
	}

	// Data in the project Directory
	QFileInfo dataInfo(dataLineEdit->text());
	if (path != dataInfo.absoluteDir())
	{
		QMessageBox::warning(this, GUI_TITLE, 
			tr("Please put data files in the project directory."));
		return false;
	}

	// invalidate number of individuals
	QString nText = nLineEdit->text();
	int nPos = 0;
	if (nLineEdit->validator()->validate(nText, nPos) != QValidator::Acceptable)
	{
		QMessageBox::warning(this, GUI_TITLE, tr("Invalid Number of Individuals."));
		return false;
	}

	// invalidate number of snps
	QString lText = lLineEdit->text();
	int lPos = 0;
	if (lLineEdit->validator()->validate(lText, lPos) != QValidator::Acceptable)
	{
		QMessageBox::warning(this, GUI_TITLE, tr("Invalid Number of Loci."));
		return false;
	}

	// invalidate number of env variable
	QString dText = dLineEdit->text();
	int dPos = 0;
	if (dLineEdit->validator()->validate(dText, dPos) != QValidator::Acceptable)
	{
		QMessageBox::warning(this, GUI_TITLE, tr("Invalid Number of Environmental variables."));
		return false;
	}

	// missing data
	/*
	QString mText = mLineEdit->text();
	int mPos = 0;
	if (mLineEdit->validator()->validate(mText, mPos) != QValidator::Acceptable)
	{
		QMessageBox::warning(this, GUI_TITLE, 
			tr("Please use a negative integer to represent missing data."));
		return false;
	}
	*/

	/***************************
	 *       DATA FILE         *
	 ***************************/

	/* 	check that data, ind, snp, files have a known extension format */
	//	&& !dataLineEdit->text().endsWith(".packedancestrymapgen")
	//	&& !dataLineEdit->text().endsWith(".packedancestrymapgen")
	//	&& !dataLineEdit->text().endsWith(".bed")
	if (	   !dataLineEdit->text().endsWith(".ancestrymap") 
		&& !dataLineEdit->text().endsWith(".eigenstratgeno")
		&& !dataLineEdit->text().endsWith(".geno")
		&& !dataLineEdit->text().endsWith(".ped")
		&& !dataLineEdit->text().endsWith(".lfmm")) {
		QMessageBox::warning(this, GUI_TITLE, 
			tr("The genotype data file format is unknown.\n\nThe authorized data format are lfmm, ped, eigenstratgeno, and ancestrymap. You can display the file you provided by clicking on \"View Data...\" button. For more specific informations, please check the reference manual or the General informations panel."));
		return false;
	}

	/* extract n,L and the number of lines and columns of data file*/

	int lNameRows = lLineEdit->text().toInt();
	int nNameRows = nLineEdit->text().toInt();
	QList <int> formatName = dataFormat(dataLineEdit->text());
	int eNameCols = formatName[0];
	int eNameRows = formatName.size();

	// check ancestrymapgen file
	if (dataLineEdit->text().endsWith(".ancestrymap")) {
		if (eNameCols != 3) {
			QMessageBox::warning(this, GUI_TITLE, QString(tr(
						     "You have chosen the ancestrymap format for thedata file,\n"
						     "but I detected that there are actually %1 columns instead of 3. You can display the file you provided by clicking on \"View Data...\" button.\n\n"
						     "Please check whether you have correctly input:\n"
						     "Genotype Data File\n"
						     )).arg(eNameCols));
			return false;
		}
		if (eNameRows != lNameRows*nNameRows) {
			QMessageBox::warning(this, GUI_TITLE, QString(tr(
						     "You have chosen the ancestrymap format for the data file,\n"
						     "but I detected that there are actually %1 lines instead of %2, the product of the number of individuals by the number of loci. You can display the file you provided by clicking on \"View Data...\" button.\n\n"
						     "Please check whether you have correctly input:\n"
						     "Number of Individuals\n"
						     "Number of Loci\n"
						     "Genotype Data File\n"
						     )).arg(eNameRows).arg(lNameRows*nNameRows));
			return false;
		}
			

	//} else if (dataLineEdit->text().endsWith(".eigenstratgeno")) {
	// check eigenstratgeno
		// fucking stupid particular case...
	//} else if (dataLineEdit->text().endsWith(".packedancestrymapgen")) {
	//} else if (dataLineEdit->text().endsWith(".packedancestrymapgen")) {
	} else if (dataLineEdit->text().endsWith(".ped")) {
		if (eNameCols != 2*lNameRows+6) {
			QMessageBox::warning(this, GUI_TITLE, QString(tr(
						     "You have chosen the ped  format for the data file,\n"
						     "but I detected that there are actually %1 columns instead of %2. You can display the file you provided by clicking on \"View Data...\" button.\n\n"
						     "Please check whether you have correctly input:\n"
						     "Number of Loci\n"
						     "Genotype Data File\n"
						     )).arg(eNameCols).arg(2*lNameRows+6));
			return false;
		}
		if (eNameRows != nNameRows) {
			QMessageBox::warning(this, GUI_TITLE, QString(tr(
						     "You have chosen the ped format for the data file,\n"
						     "but I detected that there are actually %1 lines instead of %2, the number of individuals. You can display the file you provided by clicking on \"View Data...\" button.\n\n"
						     "Please check whether you have correctly input:\n"
						     "Number of Individuals\n"
						     "Genotype Data File\n"
						     )).arg(eNameRows).arg(nNameRows));
			return false;
		}
			

	} else if (dataLineEdit->text().endsWith(".lfmm")) {
		if (eNameCols != lNameRows) {
			QMessageBox::warning(this, GUI_TITLE, QString(tr(
						     "You have chosen the lfmm format for the data file,\n"
						     "but I detected that there are actually %1 columns instead of %2, the number of loci. You can display the file you provided by clicking on \"View Data...\" button.\n\n"
						     "Please check whether you have correctly input:\n"
						     "Number of Loci\n"
						     "Genotype Data File.\n"
						     )).arg(eNameCols).arg(lNameRows));
			return false;
		}
		if (eNameRows != nNameRows) {
			QMessageBox::warning(this, GUI_TITLE, QString(tr(
						     "You have chosen the lfmm format for the data file,\n"
						     "but I detected that there are actually %1 lines instead of %2, the number of individuals. You can display the file you provided by clicking on \"View Data...\" button.\n\n"
						     "Please check whether you have correctly input:\n"
						     "Number of Individuals\n"
						     "Genotype Data File\n"
						     )).arg(eNameRows).arg(nNameRows));
			return false;
		}
	} else if (dataLineEdit->text().endsWith(".eigenstratgeno") 
		|| dataLineEdit->text().endsWith(".geno")) {
		if (eNameRows != lNameRows) {
			QMessageBox::warning(this, GUI_TITLE, QString(tr(
						     "You have chosen the eigenstratgeno format for the data file,\n"
						     "but I detected that there are actually %1 lines instead of %2, the number of individuals. You can display the file you provided by clicking on \"View Data...\" button.\n\n"
						     "Please check whether you have correctly input:\n"
						     "Number of Individuals\n"
						     "Genotype Data File\n"
						     )).arg(eNameRows).arg(lNameRows));
			return false;
		}
	} else {
		QMessageBox::warning(this, GUI_TITLE, 
			tr("The data file format is unknown.\n\nThe authorized data format are lfmm, ped, eigenstratgeno, and ancestrymap. You can display the file you provided by clicking on \"View Data...\" button. For more specific informations, please check the reference manual or the General informations panel."));
		return false;
	}

	/***************************
	 *	INDIVIDUAL FILE    *
	 ***************************/

	//	&& !geoDataLineEdit->text().endsWith(".bedind")
	if (	!geoDataLineEdit->text().endsWith(".env")) {
		//&& !geoDataLineEdit->text().endsWith(".ind")
		//&& !geoDataLineEdit->text().endsWith(".lfmmind")) {
		QMessageBox::warning(this, GUI_TITLE, 
			tr("The environmental data file format is unknown.\n\nThe authorized data format is env. You can display the file you provided by clicking on \"View Environmental Data...\" button. For more specific informations, please check the reference manual or the General informations panel."));
		return false;
	}

	/* extract n and the number of lines and columns of individual file*/

	int dNameRows = dLineEdit->text().toInt();
	int sNameRows = nLineEdit->text().toInt();
	formatName = dataFormat(geoDataLineEdit->text());
	eNameRows = formatName.size();
	eNameCols = formatName[0];

	// TODO: check that all lines -> same size

	/* check that ind file has a correct number of lines */

	if ((geoDataLineEdit->text().endsWith(".env"))
	    && sNameRows != eNameRows) {
		QMessageBox::warning(this, GUI_TITLE, QString(tr(
						     "According to your input, there should be totally %1 rows in the individual data file,\n"
						     "but I detected that there are actually %2 rows. You can display the file you provided by clicking on \"View Environmental Data...\" button.\n\n"
						     "Please check whether you have correctly input:\n"
						     "Number of Individuals\n"
						     "Environmental Data File\n"
						     )).arg(sNameRows).arg(eNameRows));
		return false;

	}
	
	// lfmmind - number of columns
	if ((geoDataLineEdit->text().endsWith(".env"))
		// TODO
	    && (dNameRows != eNameCols)) {
		QMessageBox::warning(this, GUI_TITLE, QString(tr(
						     "According to your input, there should be %1 columns in the individual data file (with the covariable proxy),\n"
						     "but I detected that there are actually %2 columns. You can display the file you provided by clicking on \"View Environmental Data...\" button.\n\n"
						     "Please check whether you have correctly input:\n"
						     "Environmental Data File\n"
						     )).arg(dNameRows).arg(eNameCols));
		return false;

	}

	/***************************
	 *        SNP FILE         *
	 ***************************/

	//	&& !nameDataLineEdit->text().endsWith(".bedsnp")
	if (	!nameDataLineEdit->text().isEmpty() 
		&& !nameDataLineEdit->text().endsWith(".pedsnp")
		&& !nameDataLineEdit->text().endsWith(".map")
		&& !nameDataLineEdit->text().endsWith(".snp")
		&& !nameDataLineEdit->text().endsWith(".lfmmsnp")) {
		QMessageBox::warning(this, GUI_TITLE, 
			tr("The snp file format is unknown.\n\nThe authorized data formats are lfmmsnp, pedsnp, map, and snp. You can display the file you provided by clicking on \"View SNPs Data...\" button. For more specific informations, please check the reference manual or the General informations panel."));
		return false;
	}

	/* extract L and the number of lines and columns of snp file*/

	if (	!nameDataLineEdit->text().isEmpty()) {
	sNameRows = lLineEdit->text().toInt();
	formatName = dataFormat(nameDataLineEdit->text());
	eNameRows = formatName.size();
	eNameCols = formatName[0];

	/* check that snp file has a correct number of lines */

	// snp, pedsnp, lfmmsnp - number of snps
	if ((nameDataLineEdit->text().endsWith(".snp") || nameDataLineEdit->text().endsWith(".pedsnp")
	   || nameDataLineEdit->text().endsWith(".map") || nameDataLineEdit->text().endsWith(".lfmmsnp")) 
	    && sNameRows != eNameRows) {
		QMessageBox::warning(this, GUI_TITLE, QString(tr(
						     "According to your input, there should be totally %1 rows in the snp data file,\n"
						     "but I detected that there are actually %2 rows. You can display the file you provided by clicking on \"View SNPs Data...\" button.\n\n"
						     "Please check whether you have correctly input:\n"
						     "Number of Loci\n"
						     "SNPs data File\n"
						     )).arg(sNameRows).arg(eNameRows));
		return false;

	}

	/* for each snp format, check the number of columns */

	// check snp and pedsnp 
	if ((nameDataLineEdit->text().endsWith(".snp") || nameDataLineEdit->text().endsWith(".pedsnp")
	|| nameDataLineEdit->text().endsWith(".map")) && (4 > eNameCols || 6 < eNameCols)) {
		QMessageBox::warning(this, GUI_TITLE, QString(tr(
						     "According to snp/pedsnp/map format, there should be 6 columns (last 2 optional) in the snp data file,\n"
						     "but I detected that there are actually %1 columns. You can display the file you provided by clicking on \"View SNPs Data...\" button.\n\n"
						     "Please check whether you have correctly input:\n"
						     "SNPs data File\n"
						     )).arg(eNameCols));
		return false;

	}
	// check lfmmsnp 
	else if ((nameDataLineEdit->text().endsWith(".lfmmsnp")) 
	    && (3 != eNameCols)) {
		QMessageBox::warning(this, GUI_TITLE, QString(tr(
						     "According to lfmmsnp format, there should be 2 columns in the snp data file,\n"
						     "but I detected that there are actually %1 columns. You can display the file you provided by clicking on \"View SNPs Data...\" button.\n\n"
						     "Please check whether you have correctly input:\n"
						     "SNPs Data File\n"
						     )).arg(eNameCols));
		return false;

	}
	}


	// TO MODIFY with Bool
	//changeProjectDataFormat();
	return true;
}

const QList< int > &NewProjectDialog::dataFormat(const QString &data)
{
	static QList< int > format;
	format.clear();

	QFile file(data);
	if (!file.open(QFile::ReadOnly | QFile::Text)) 
	{
		QMessageBox::warning(this, GUI_TITLE,
			tr("Cannot verify data file %1!").arg(data));
		return format;
	}
	QTextStream in(&file);
	QRegExp reWC("\\w");  // Word Character
	QRegExp regExp("\\s+|\\t+");  // Space(s) or Tab(s)
	QString oneRow;
	QStringList oneRowList;
	QApplication::setOverrideCursor(Qt::WaitCursor);
	while (!(oneRow = in.readLine()).isNull())
	{
		if (oneRow.contains(reWC))
		{
			oneRowList = oneRow.split(regExp, QString::SkipEmptyParts);
			format.append(oneRowList.size());
		}
	}
	QApplication::restoreOverrideCursor();
	file.close();

	return format;
}
