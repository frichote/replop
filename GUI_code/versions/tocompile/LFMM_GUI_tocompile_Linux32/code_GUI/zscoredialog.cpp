/*
    LFMM GUI, file: zscoredialog.cpp
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


//#include <QtCore>
#include <QtGui>
#include <set>
#include <iostream>
#include "zscoredialog.h"
#include "title.h"
#include "snp.h"
#include "project.h"

using namespace std;

	ZscoreDialog::ZscoreDialog(QWidget *parent) 
: QDialog(parent)
{
	setWindowTitle(tr("Summarize Zscore of Runs"));

	curIndex=-1;

	QLabel *runLabel = new QLabel(tr("Select a run: "));
	runComboBox = new QComboBox;
        QToolButton *runHelp = new QToolButton;
        runHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        runHelp->setText(tr("run"));
        runHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        runHelp->setAutoRaise(true);
        runHelp->setStatusTip(tr("Help"));
	connect(runHelp, SIGNAL(clicked()), this, SLOT(help()));


	QHBoxLayout *runLayout = new QHBoxLayout;
	runLayout->addWidget(runLabel);
	runLayout->addWidget(runComboBox);
	runLayout->addWidget(runHelp);

	QGridLayout *parameterLayout = new QGridLayout;

	numberLabel = new QLabel(tr("The current number of snps displayed is 0."));
        QToolButton *numberHelp = new QToolButton;
        numberHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        numberHelp->setText(tr("number"));
        numberHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        numberHelp->setAutoRaise(true);
        numberHelp->setStatusTip(tr("Help"));
	connect(numberHelp, SIGNAL(clicked()), this, SLOT(help()));


	QLabel *chrLabel = new QLabel(tr("Search only in Chromosome:"));
	chrComboBox = new QComboBox;
        QToolButton *chrHelp = new QToolButton;
        chrHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        chrHelp->setText(tr("chr"));
        chrHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        chrHelp->setAutoRaise(true);
        chrHelp->setStatusTip(tr("Help"));
	connect(chrHelp, SIGNAL(clicked()), this, SLOT(help()));


	nameSearchCheckBox = new QCheckBox(tr("Search for specific names (separated by commas)"));
	nameSearchLineEdit = new QLineEdit;
        QToolButton *nameSearchHelp = new QToolButton;
        nameSearchHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        nameSearchHelp->setText(tr("nameSearch"));
        nameSearchHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        nameSearchHelp->setAutoRaise(true);
        nameSearchHelp->setStatusTip(tr("Help"));
	connect(nameSearchHelp, SIGNAL(clicked()), this, SLOT(help()));

	positionCheckBox = new QCheckBox(tr("Search for positions:"));
	minPositionLineEdit = new QLineEdit;
	QDoubleValidator *kV = new QDoubleValidator(this);
	minPositionLineEdit->setValidator(kV);
	QLabel *fromLabel = new QLabel(tr(" from"));
	QLabel *toLabel = new QLabel(tr("to"));
	maxPositionLineEdit = new QLineEdit;
	maxPositionLineEdit->setValidator(kV);
        QToolButton *positionHelp = new QToolButton;
        positionHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        positionHelp->setText(tr("position"));
        positionHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        positionHelp->setAutoRaise(true);
        positionHelp->setStatusTip(tr("Help"));
	connect(positionHelp, SIGNAL(clicked()), this, SLOT(help()));

	zscoreCheckBox = new QCheckBox(tr("Search for zscores:"));
	minZscoreLineEdit = new QLineEdit;
	minZscoreLineEdit->setValidator(kV);
	QLabel *fromLabel2 = new QLabel(tr(" from"));
	QLabel *toLabel2 = new QLabel(tr("to"));
	maxZscoreLineEdit = new QLineEdit;
	maxZscoreLineEdit->setValidator(kV);
        QToolButton *zscoreHelp = new QToolButton;
        zscoreHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        zscoreHelp->setText(tr("zscore"));
        zscoreHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        zscoreHelp->setAutoRaise(true);
        zscoreHelp->setStatusTip(tr("Help"));
	connect(zscoreHelp, SIGNAL(clicked()), this, SLOT(help()));

	pvalueCheckBox = new QCheckBox(tr("Search for p-values:"));
	minPvalueLineEdit = new QLineEdit;
	minPvalueLineEdit->setValidator(kV);
	QLabel *fromLabel3 = new QLabel(tr(" from"));
	QLabel *toLabel3 = new QLabel(tr("to"));
	maxPvalueLineEdit = new QLineEdit;
	maxPvalueLineEdit->setValidator(kV);
        QToolButton *pvalueHelp = new QToolButton;
        pvalueHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        pvalueHelp->setText(tr("pvalue"));
        pvalueHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        pvalueHelp->setAutoRaise(true);
        pvalueHelp->setStatusTip(tr("Help"));
	connect(pvalueHelp, SIGNAL(clicked()), this, SLOT(help()));

	lpvalueCheckBox = new QCheckBox(tr("Search for -log10(p-values):"));
	minlPvalueLineEdit = new QLineEdit;
	minlPvalueLineEdit->setValidator(kV);
	QLabel *fromLabel4 = new QLabel(tr(" from"));
	QLabel *toLabel4 = new QLabel(tr("to"));
	maxlPvalueLineEdit = new QLineEdit;
	maxlPvalueLineEdit->setValidator(kV);
        QToolButton *lpvalueHelp = new QToolButton;
        lpvalueHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        lpvalueHelp->setText(tr("lpvalue"));
        lpvalueHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        lpvalueHelp->setAutoRaise(true);
        lpvalueHelp->setStatusTip(tr("Help"));
	connect(lpvalueHelp, SIGNAL(clicked()), this, SLOT(help()));

	QHBoxLayout *toTextLayout = new QHBoxLayout;
	toTextPushButton = new QPushButton(tr("Export Displayed Table to Text File"));
        QToolButton *toTextHelp = new QToolButton;
        toTextHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        toTextHelp->setText(tr("toText"));
        toTextHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toTextHelp->setAutoRaise(true);
        toTextHelp->setStatusTip(tr("Help"));
	connect(toTextHelp, SIGNAL(clicked()), this, SLOT(help()));
	toTextLayout->addStretch();
	toTextLayout->addWidget(toTextPushButton);
	toTextLayout->addStretch();
	toTextLayout->addWidget(toTextHelp);

	//QHBoxLayout *toPlotLayout = new QHBoxLayout;
	toPlotPushButton = new QPushButton(tr("Create Manhattan Plot assciated with current Table"));
        QToolButton *toPlotHelp = new QToolButton;
        toPlotHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        toPlotHelp->setText(tr("toPlot"));
        toPlotHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toPlotHelp->setAutoRaise(true);
        toPlotHelp->setStatusTip(tr("Help"));
	connect(toPlotHelp, SIGNAL(clicked()), this, SLOT(help()));
	//toPlotLayout->addStretch();
	//toPlotLayout->addWidget(toPlotPushButton);
	//toPlotLayout->addStretch();

	//QHBoxLayout *toGreenPlotLayout = new QHBoxLayout;
	toGreenPlotPushButton = new QPushButton(tr("Create Manhattan Plot with all snps and in green snps in the table"));
        QToolButton *toGreenPlotHelp = new QToolButton;
        toGreenPlotHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        toGreenPlotHelp->setText(tr("toGreenPlot"));
        toGreenPlotHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toGreenPlotHelp->setAutoRaise(true);
        toGreenPlotHelp->setStatusTip(tr("Help"));
	connect(toGreenPlotHelp, SIGNAL(clicked()), this, SLOT(help()));
	//toGreenPlotLayout->addStretch();
	//toGreenPlotLayout->addWidget(toGreenPlotPushButton);
	//toGreenPlotLayout->addStretch();

	parameterLayout->addWidget(numberLabel,0,0,1,5);
	parameterLayout->addWidget(numberHelp,0,5,1,1);
	parameterLayout->addWidget(chrLabel,1,0,1,3);
	parameterLayout->addWidget(chrComboBox,1,3,1,2);
	parameterLayout->addWidget(chrHelp,1,5,1,1);
	parameterLayout->addWidget(nameSearchCheckBox,2,0,1,5);
	parameterLayout->addWidget(nameSearchLineEdit,3,0,1,5);
	parameterLayout->addWidget(nameSearchHelp,3,5,1,1);
	// 
	parameterLayout->addWidget(positionCheckBox,4,0,1,1);
	parameterLayout->addWidget(fromLabel,4,1,1,1);
	parameterLayout->addWidget(minPositionLineEdit,4,2,1,1);
	parameterLayout->addWidget(toLabel,4,3,1,1);
	parameterLayout->addWidget(maxPositionLineEdit,4,4,1,1);
	parameterLayout->addWidget(positionHelp,4,5,1,1);
	//
	parameterLayout->addWidget(zscoreCheckBox,5,0,1,1);
	parameterLayout->addWidget(fromLabel2,5,1,1,1);
	parameterLayout->addWidget(minZscoreLineEdit,5,2,1,1);
	parameterLayout->addWidget(toLabel2,5,3,1,1);
	parameterLayout->addWidget(maxZscoreLineEdit,5,4,1,1);
	parameterLayout->addWidget(zscoreHelp,5,5,1,1);
	//
	parameterLayout->addWidget(pvalueCheckBox,6,0,1,1);
	parameterLayout->addWidget(fromLabel3,6,1,1,1);
	parameterLayout->addWidget(minPvalueLineEdit,6,2,1,1);
	parameterLayout->addWidget(toLabel3,6,3,1,1);
	parameterLayout->addWidget(maxPvalueLineEdit,6,4,1,1);
	parameterLayout->addWidget(pvalueHelp,6,5,1,1);
	//
	parameterLayout->addWidget(lpvalueCheckBox,7,0,1,1);
	parameterLayout->addWidget(fromLabel4,7,1,1,1);
	parameterLayout->addWidget(minlPvalueLineEdit,7,2,1,1);
	parameterLayout->addWidget(toLabel4,7,3,1,1);
	parameterLayout->addWidget(maxlPvalueLineEdit,7,4,1,1);
	parameterLayout->addWidget(lpvalueHelp,7,5,1,1);

	QGroupBox *tGroupBox = new QGroupBox(tr("Project Run"));
	tGroupBox->setLayout(runLayout);

	QGroupBox *tGroupBox2 = new QGroupBox(tr("Parameter Table"));
	tGroupBox2->setLayout(parameterLayout);

	QGroupBox *tGroupBox3 = new QGroupBox(tr("Export Table"));
	tGroupBox3->setLayout(toTextLayout);

	QGroupBox *tGroupBox4 = new QGroupBox(tr("Manhattan Plot"));
	QGridLayout *gb4Layout = new QGridLayout;
	gb4Layout->addWidget(toPlotPushButton,0,0);
	gb4Layout->addWidget(toPlotHelp,0,1);
	gb4Layout->addWidget(toGreenPlotPushButton,1,0);
	gb4Layout->addWidget(toGreenPlotHelp,1,1);
	tGroupBox4->setLayout(gb4Layout);

	zscoreTable = new ZscoreTable(this);
	zscoreTable->resizeColumnsToContents();
	QGridLayout *tableLayout = new QGridLayout;
	tableLayout->addWidget(zscoreTable,0,0);

	QVBoxLayout *submainLayout = new QVBoxLayout;
	submainLayout->addWidget(tGroupBox);
	submainLayout->addWidget(tGroupBox2);
	submainLayout->addWidget(tGroupBox3);
	submainLayout->addWidget(tGroupBox4);
	submainLayout->addStretch();

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(submainLayout);
	mainLayout->addLayout(tableLayout);
	setLayout(mainLayout);
}

ZscoreDialog::~ZscoreDialog()
{
	if (zscoreTable) 
	{
		delete zscoreTable;
	}
}

void ZscoreDialog::clear()
{
        // update table if the ranges is are changed
        disconnect(runComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(updateRunToZscoreTable()));

        //connect(chrCheckBox,SIGNAL(stateChanged(int)),this,SLOT(updateChrRange()));
        disconnect(chrComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(updateChrRange()));
        disconnect(zscoreCheckBox,SIGNAL(stateChanged(int)),this,SLOT(updateZscoreRange()));
        disconnect(minZscoreLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updateZscoreRange()));
        disconnect(maxZscoreLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updateZscoreRange()));
        disconnect(pvalueCheckBox,SIGNAL(stateChanged(int)),this,SLOT(updatePvalueRange()));
        disconnect(minPvalueLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updatePvalueRange()));
        disconnect(maxPvalueLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updatePvalueRange()));
        disconnect(lpvalueCheckBox,SIGNAL(stateChanged(int)),this,SLOT(updatelPvalueRange()));
        disconnect(minlPvalueLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updatelPvalueRange()));
        disconnect(maxlPvalueLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updatelPvalueRange()));
        disconnect(positionCheckBox,SIGNAL(stateChanged(int)),this,SLOT(updatePositionRange()));
        disconnect(minPositionLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updatePositionRange()));
        disconnect(maxPositionLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updatePositionRange()));
        disconnect(nameSearchCheckBox,SIGNAL(stateChanged(int)),this,SLOT(updateNameRange()));
        disconnect(nameSearchLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updateNameRange()));

        // export text
        disconnect(toTextPushButton, SIGNAL(clicked()),this,SLOT(exportZscoreTableToText()));
	disconnect(toPlotPushButton, SIGNAL(clicked()), this->parent()->parent()->parent()->parent()->parent()->parent(), SLOT(createManhattan()));
	disconnect(toGreenPlotPushButton, SIGNAL(clicked()), this->parent()->parent()->parent()->parent()->parent()->parent(), SLOT(createGreenManhattan()));


	curIndex = -1;
	curNbSnps = 0;
	
	//nameSearchCheckBox->setEnabled(false);
	nameSearchLineEdit->clear();

        //zscoreCheckBox->setEnabled(false);
        minZscoreLineEdit->clear();
        maxZscoreLineEdit->clear();

        //pvalueCheckBox->setEnabled(false);
        minPvalueLineEdit->clear();
        maxPvalueLineEdit->clear();

        //lpvalueCheckBox->setEnabled(false);
        minlPvalueLineEdit->clear();
        maxlPvalueLineEdit->clear();

        //positionCheckBox->setEnabled(false);
        minPositionLineEdit->clear();
        maxPositionLineEdit->clear();

	chrComboBox->clear();
	curNbSnps = 0;

	runComboBox->clear();
	//zscoreTable->clearContents();
	zscoreTable->model->clear();

	project = NULL;
	snps.clear();
	updateOKSnps();
	updateZscoreTable();
	//updateZscoreTable();
}

bool ZscoreDialog::updateZscoreRange() {

	if (project) {
	int size = project->runs.size(); // number of runs
	if (size > 0) {
	if (zscoreCheckBox->checkState() == Qt::Checked) {
		if (!minZscoreLineEdit->text().isEmpty() && !maxZscoreLineEdit->text().isEmpty()) {
			if (minZscoreLineEdit->text().toDouble() > maxZscoreLineEdit->text().toDouble())
			{
				QMessageBox::warning(this,GUI_TITLE,tr("Zscore: The upper range "
							"must be greater than the lower range!"));
				return false;
			}

			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].zOK = snps[j].zscore.toDouble() >= minZscoreLineEdit->text().toDouble()
					&& snps[j].zscore.toDouble() <= maxZscoreLineEdit->text().toDouble();
			}
		} else if (!minZscoreLineEdit->text().isEmpty()) {
			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].zOK = snps[j].zscore.toDouble() >= minZscoreLineEdit->text().toDouble();
			}
		} else if (!maxZscoreLineEdit->text().isEmpty()) {
			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].zOK = snps[j].zscore.toDouble() <= maxZscoreLineEdit->text().toDouble();
			}
		} else {
			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].zOK = true;
			}
		}
	} else {
		for (int j = 0; j < project->L.toInt(); j++)
		{       
			snps[j].zOK = true; 
		}       
	}
	

	updateOKSnps();
	updateZscoreTable();
	}
	}

	return true;
}

bool ZscoreDialog::updatePvalueRange() {

	if (project) {
	int size = project->runs.size(); // number of runs
	if (size > 0) {
	if (pvalueCheckBox->checkState() == Qt::Checked) {
		if (!minPvalueLineEdit->text().isEmpty() && !maxPvalueLineEdit->text().isEmpty()) {
			if (minPvalueLineEdit->text().toDouble() > maxPvalueLineEdit->text().toDouble())
			{
				QMessageBox::warning(this,GUI_TITLE,tr("Zscore: The upper range "
							"must be greater than the lower range!"));
				return false;
			}

			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].pvOK = snps[j].pvalue.toDouble() >= minPvalueLineEdit->text().toDouble()
					&& snps[j].pvalue.toDouble() <= maxPvalueLineEdit->text().toDouble();
			}
		} else if (!minPvalueLineEdit->text().isEmpty()) {
			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].pvOK = snps[j].pvalue.toDouble() >= minPvalueLineEdit->text().toDouble();
			}
		} else if (!maxPvalueLineEdit->text().isEmpty()) {
			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].pvOK = snps[j].pvalue.toDouble() <= maxPvalueLineEdit->text().toDouble();
			}
		} else {
			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].pvOK = true;
			}
		}
	} else {
		for (int j = 0; j < project->L.toInt(); j++)
		{       
			snps[j].pvOK = true; 
		}       
	}

	updateOKSnps();
	updateZscoreTable();
	}	
	}
	
	return true;
}

bool ZscoreDialog::updateNameRange() {

	if (project) {
	int size = project->runs.size(); // number of runs
	if (size > 0) {
	if (nameSearchCheckBox->checkState() == Qt::Checked && !nameSearchLineEdit->text().isEmpty()) {
	        QRegExp regExp("[\\t\\s]+|[\\s\\t]*[,;][\\s\\t]*");  // Space(s) or Tab(s)
		QStringList oneRowList = nameSearchLineEdit->text().split(regExp, QString::SkipEmptyParts);

		for (int j = 0; j < project->L.toInt(); j++) {
			snps[j].nOK = oneRowList.contains(snps[j].name,Qt::CaseInsensitive);
		}
	} else {
		for (int j = 0; j < project->L.toInt(); j++)
		{       
			snps[j].nOK = true; 
		}       
	}

	updateOKSnps();
	updateZscoreTable();
	}
	}

	return true;
}

bool ZscoreDialog::updateChrRange() {

	if (project) {
	int size = project->runs.size(); // number of runs
	if (size > 0) {
	if (!chrComboBox->currentText().isEmpty() && !chrComboBox->currentText().startsWith(tr("ALL"))) {
		for (int j = 0; j < project->L.toInt(); j++) {
			snps[j].cOK = QString::compare(chrComboBox->currentText(),snps[j].chromosome,Qt::CaseSensitive) == 0;
		}
	} else {
		for (int j = 0; j < project->L.toInt(); j++)
		{       
			snps[j].cOK = true; 
		}       
	}

	updateOKSnps();
	updateZscoreTable();
	}
	}

	return true;
}

bool ZscoreDialog::updatelPvalueRange() {

	if (project) {
	int size = project->runs.size(); // number of runs
	if (size > 0) {
	if (lpvalueCheckBox->checkState() == Qt::Checked) {
		if (!minlPvalueLineEdit->text().isEmpty() && !maxlPvalueLineEdit->text().isEmpty()) {
			if (minlPvalueLineEdit->text().toDouble() > maxlPvalueLineEdit->text().toDouble())
			{
				QMessageBox::warning(this,GUI_TITLE,tr("Zscore: The upper range "
							"must be greater than the lower range!"));
				return false;
			}

			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].lpvOK = snps[j].lpvalue.toDouble() >= minlPvalueLineEdit->text().toDouble()
					&& snps[j].lpvalue.toDouble() <= maxlPvalueLineEdit->text().toDouble();
			}
		} else if (!minlPvalueLineEdit->text().isEmpty()) {
			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].lpvOK = snps[j].lpvalue.toDouble() >= minlPvalueLineEdit->text().toDouble();
			}
		} else if (!maxlPvalueLineEdit->text().isEmpty()) {
			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].lpvOK = snps[j].lpvalue.toDouble() <= maxlPvalueLineEdit->text().toDouble();
			}
		} else {
			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].lpvOK = true;
			}
		}
	} else {
		for (int j = 0; j < project->L.toInt(); j++)
		{       
			snps[j].lpvOK = true; 
		}       
	}

	updateOKSnps();
	updateZscoreTable();
	}
	}

	return true;
}

bool ZscoreDialog::updatePositionRange() {

	if (project) {
	int size = project->runs.size(); // number of runs
	if (size > 0) {
	if (positionCheckBox->checkState() == Qt::Checked) {
		if (!minPositionLineEdit->text().isEmpty() && !maxPositionLineEdit->text().isEmpty()) {
			if (minPositionLineEdit->text().toDouble() > maxPositionLineEdit->text().toDouble())
			{
				QMessageBox::warning(this,GUI_TITLE,tr("Zscore: The upper range "
							"must be greater than the lower range!"));
				return false;
			}

			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].pOK = snps[j].position.toDouble() >= minPositionLineEdit->text().toDouble()
					&& snps[j].position.toDouble() <= maxPositionLineEdit->text().toDouble();
			}
		} else if (!minPositionLineEdit->text().isEmpty()) {
			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].pOK = snps[j].position.toDouble() >= minPositionLineEdit->text().toDouble();
			}
		} else if (!maxPositionLineEdit->text().isEmpty()) {
			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].pOK = snps[j].position.toDouble() <= maxPositionLineEdit->text().toDouble();
			}
		} else {
			for (int j = 0; j < project->L.toInt(); j++)
			{
				snps[j].pOK = true;
			}
		}
	} else {
		for (int j = 0; j < project->L.toInt(); j++)
		{       
			snps[j].pOK = true; 
		}       
	}

	updateOKSnps();
	updateZscoreTable();
	}
	}

	return true;
}

void ZscoreDialog::updateOKSnps() {

	if (project) {
	int size = project->runs.size(); // number of runs
	if (size > 0) {
        curNbSnps = 0;
	if (project) {
        for (int j = 0; j < project->L.toInt(); j++)
        {       
		snps[j].OK = snps[j].nOK && snps[j].pOK && snps[j].cOK && snps[j].zOK 
				&& snps[j].pvOK && snps[j].lpvOK;
                if (snps[j].OK) {
			curNbSnps++;
                }
        }
	}
	numberLabel->setText(tr("The current number of snps displayed is %1.").arg(curNbSnps));
	}
	}
}

bool ZscoreDialog::initZscore()
{

	if (project) {
	int size = project->runs.size(); // number of runs
	// should not happen

	if (size < 0)
	{
		return false;
	}
	// there are runs
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			QString currentItem = project->runs[i].name;
			runComboBox->addItem(QString("%1").arg(currentItem));
		}

	}
	runComboBox->setCurrentIndex(0);


        curNbSnps = 0;
	//percentageComboBox->setCurrentIndex(9);
	if (size > 0)
	{
		curNbSnps = project->L.toInt();
		/*
		zscoreTable->setRowCount(curNbSnps);
		for (int i = 0; i < curNbSnps; i++) {

			QTableWidgetItem *name = new QTableWidgetItem(tr("%1").arg("plop"));
			name->setFlags(Qt::ItemIsEnabled);
			zscoreTable->setItem(i,0,name);

			QTableWidgetItem *chr = new QTableWidgetItem(tr("%1").arg("plop"));
			chr->setFlags(Qt::ItemIsEnabled);
			zscoreTable->setItem(i,1,chr);

			QTableWidgetItem *pos = new QTableWidgetItem(tr("%1").arg("plop"));
			pos->setFlags(Qt::ItemIsEnabled);
			zscoreTable->setItem(i,2,pos);

			QTableWidgetItem *z = new QTableWidgetItem(tr("%1").arg("plop"));
			z->setFlags(Qt::ItemIsEnabled);
			zscoreTable->setItem(i,3,z);

			QTableWidgetItem *lp = new QTableWidgetItem(tr("%1").arg("plop"));
			lp->setFlags(Qt::ItemIsEnabled);
			zscoreTable->setItem(i,4,lp);

			QTableWidgetItem *p = new QTableWidgetItem(tr("%1").arg("plop"));
			p->setFlags(Qt::ItemIsEnabled);
			zscoreTable->setItem(i,5,p);
		}
		zscoreTable->resizeColumnToContents(0);
		zscoreTable->resizeColumnToContents(1);
		zscoreTable->resizeColumnToContents(2);
		zscoreTable->resizeColumnToContents(3);
		zscoreTable->resizeColumnToContents(4);
		zscoreTable->resizeColumnToContents(5);
		*/

		updateRunToZscoreTable();
	}

	// actions to connect

	// update table if the ranges is are changed
	connect(runComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(updateRunToZscoreTable()));

	//connect(chrCheckBox,SIGNAL(stateChanged(int)),this,SLOT(updateChrRange()));
	connect(chrComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(updateChrRange()));
	connect(zscoreCheckBox,SIGNAL(stateChanged(int)),this,SLOT(updateZscoreRange()));
	connect(minZscoreLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updateZscoreRange()));
	connect(maxZscoreLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updateZscoreRange()));
	connect(pvalueCheckBox,SIGNAL(stateChanged(int)),this,SLOT(updatePvalueRange()));
	connect(minPvalueLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updatePvalueRange()));
	connect(maxPvalueLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updatePvalueRange()));
	connect(lpvalueCheckBox,SIGNAL(stateChanged(int)),this,SLOT(updatelPvalueRange()));
	connect(minlPvalueLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updatelPvalueRange()));
	connect(maxlPvalueLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updatelPvalueRange()));
	connect(positionCheckBox,SIGNAL(stateChanged(int)),this,SLOT(updatePositionRange()));
	connect(minPositionLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updatePositionRange()));
	connect(maxPositionLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updatePositionRange()));
	connect(nameSearchCheckBox,SIGNAL(stateChanged(int)),this,SLOT(updateNameRange()));
	connect(nameSearchLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updateNameRange()));

	// export text
	connect(toTextPushButton, SIGNAL(clicked()),this,SLOT(exportZscoreTableToText()));
	connect(toPlotPushButton, SIGNAL(clicked()), this->parent()->parent()->parent()->parent()->parent()->parent(), SLOT(createManhattan()));
	connect(toGreenPlotPushButton, SIGNAL(clicked()), this->parent()->parent()->parent()->parent()->parent()->parent(), SLOT(createGreenManhattan()));

	return true;
	}
	return false;

}

void ZscoreDialog::loadZscoreItem(QTableWidgetItem *item)
{
	if (item->text().endsWith(".png"))
	{
		//      loadGraph(project->path + "/" + item->text());
	}
}

void ZscoreDialog::updateZscoreTable()
{

	// TODO
	if (curIndex >= 0) {
		
	int nbSnp = project->L.toInt();
	Run run= project->runs[curIndex];
	//	zscoreTable->setRowCount(curNbSnps);


	if (chrComboBox->findText(QString("ALL")) == -1) {
		chrComboBox->addItem(QString("ALL"));
	}
	int i=0;
//	zscoreTable->clearContents();
	for (int j = 0; j < nbSnp; j++)
	{
		if (snps[j].OK) {

			zscoreTable->showRow(j);
			/*	
			QTableWidgetItem *name = zscoreTable->item(i,0);
			name->setText(tr("%1").arg(snps[j].name));
			*/
			if (chrComboBox->findText(snps[j].chromosome,Qt::MatchCaseSensitive) == -1) {
				chrComboBox->addItem(QString("%1").arg(snps[j].chromosome));
			}
			/*
			QTableWidgetItem *chr = zscoreTable->item(i,1);
			chr->setText(tr("%1").arg(snps[j].chromosome));

			QTableWidgetItem *pos = zscoreTable->item(i,2);
			pos->setText(tr("%1").arg(snps[j].position));

			QTableWidgetItem *z = zscoreTable->item(i,3);
			z->setText(tr("%1").arg(snps[j].zscore));

			QTableWidgetItem *lp = zscoreTable->item(i,4);
			lp->setText(tr("%1").arg(snps[j].lpvalue));

			QTableWidgetItem *p = zscoreTable->item(i,5);
			p->setText(tr("%1").arg(snps[j].pvalue));
			*/
			i++;
		} else {
			zscoreTable->hideRow(j);
		}
	}
	/*
	for (int j = i; j < nbSnp; j++)
	{
		QTableWidgetItem *name = zscoreTable->item(j,0);
		name->setText(tr(""));

		QTableWidgetItem *chr = zscoreTable->item(j,1);
		chr->setText(tr(""));

		QTableWidgetItem *pos = zscoreTable->item(j,2);
		pos->setText(tr(""));

		QTableWidgetItem *z = zscoreTable->item(j,3);
		z->setText(tr(""));

		QTableWidgetItem *lp = zscoreTable->item(j,4);
		lp->setText(tr(""));

		QTableWidgetItem *p = zscoreTable->item(j,5);
		p->setText(tr(""));

	}
	*/
	//Display average DIC
	zscoreTable->resizeColumnToContents(0);
	zscoreTable->resizeColumnToContents(1);
	zscoreTable->resizeColumnToContents(2);
	zscoreTable->resizeColumnToContents(3);
	zscoreTable->resizeColumnToContents(4);
	zscoreTable->resizeColumnToContents(5);

	}
}

void ZscoreDialog::addRunToZscoreTable(bool update)
{
        QString currentItem = project->runs[project->runs.size()-1].name;
	//QRegExp rx("^.*_RUN_(\\d*)");

        runComboBox->addItem(QString("%1").arg(currentItem));
	
        //rx.indexIn(currentItem);
        //int nIndex = rx.cap(1).toInt() - 1;
	if (update || curIndex == -1) {
        for (int i = 0; i < project->runs.size(); i++)
        {
                if (project->runs.at(i).name == currentItem)
                {
			runComboBox->setCurrentIndex(i);
		}
	}
	
	}
	updateRunToZscoreTable();
}

void ZscoreDialog::updateRunToZscoreTable() {

	
	if (project) {
	int size = project->runs.size(); // number of runs
	if (size > 0) {
	//QRegExp rx("^.*_RUN_(\\d*)");
	//rx.indexIn(runComboBox->currentText());
	int nIndex = -1;
	curIndex = -1;
	/*
	if (rx.indexIn(runComboBox->currentText()) != -1) {
		nIndex = rx.cap(1).toInt() - 1;
	}
	*/
        for (int i = 0; i < project->runs.size(); i++)
        {
                if (project->runs.at(i).name == runComboBox->currentText())
                {
			nIndex=i;
		}
	}
	if (nIndex != -1 &&(curIndex = -1 || (curIndex != nIndex))) {
		snps.clear();
		curIndex = nIndex;
		curNbSnps = project->L.toInt();
		zscoreTable->model->setRowCount(curNbSnps);
		Run *run = &(project->runs[nIndex]);
		QString path = project->path + "/" + run->name + "/" + "zscore.res";
		//QString path = project.path + "/" + "zscore.res";
		QFile file(path);
		if(file.exists() && file.open(QIODevice::ReadOnly)) {
			//QMessageBox::information(0, "error", file.errorString());

			QTextStream in(&file);

			run->i = 0;
			for (int i=0; i<project->L.toInt(); i++) {
				(run->i)++;
				QString line = in.readLine();
				QStringList fields = line.split(" ");
				Snp snp;
				QStandardItem *name = new QStandardItem(QString(fields[0]));
				zscoreTable->model->setItem(i,0,name);
				QStandardItem *chr = new QStandardItem(QString(fields[1]));
				zscoreTable->model->setItem(i,1,chr);
				QStandardItem *pos = new QStandardItem(QString(fields[2]));
				zscoreTable->model->setItem(i,2,pos);
				QStandardItem *z = new QStandardItem(QString(fields[3]));
				zscoreTable->model->setItem(i,3,z);
				QStandardItem *lp = new QStandardItem(QString(fields[4]));
				zscoreTable->model->setItem(i,4,lp);
				QStandardItem *p = new QStandardItem(QString(fields[5]));
				zscoreTable->model->setItem(i,5,p);

				snp.name = fields[0];
				snp.chromosome = fields[1];
				snp.position = fields[2];
				snp.zscore = fields[3];
				snp.lpvalue = fields[4];
				snp.pvalue = fields[5];

				snp.nOK = true;
				snp.cOK = true;
				snp.pOK = true;
				snp.zOK = true;
				snp.pvOK = true;
				snp.lpvOK = true;
				snp.OK = true;
				snps.append(snp);
			}
	updateZscoreRange();
	updatePvalueRange();
	updatelPvalueRange();
	updatePositionRange();
	updateChrRange();
	updateNameRange();
	// TODO

	updateZscoreTable();
		} else {
 			QMessageBox::critical(this, GUI_TITLE,
                        	tr("An error happened during the reading of the zscore file.\n\n"
                        	"Please, check the reference manual or the General informations panel and try again."));
			snps.clear();
			for (int i=0; i<project->L.toInt(); i++) {
				Snp snp;
				snp.nOK = true;
				snp.cOK = true;
				snp.pOK = true;
				snp.zOK = true;
				snp.pvOK = true;
				snp.lpvOK = true;
				snp.OK = false;
				snps.append(snp);
			}
			
			//zscoreTable->clearContents();
        		curNbSnps = 0;
			numberLabel->setText(tr("The current number of snps displayed is %1.").arg(curNbSnps));
			updateZscoreTable();
		}
	}
	}
	}
}

void ZscoreDialog::createZscoreTableToPlot()
{
	
	QString saveFileName = project->path + "/manhattan_table.txt";
        QFile saveFile(saveFileName);
        if (!saveFile.open(QFile::WriteOnly | QFile::Text))
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Cannot open file %1!")
                                .arg(popfileLineEdit->text()));
                return;
        }

        QTextStream out(&saveFile);

        out << "Name" << '\t' << "Chr" << '\t' << "Position" << '\t' << "Zscore" << '\t' <<"-log10(p-value)" << " p-value" << endl;

        //int nRow = zscoreTable->rowCount();
        //We export columns number 0,1,2,6,7
        for (int i=0; i < project->L.toInt(); i++)
        {
		if (snps[i].OK) {
	                out << snps[i].name << '\t';
        	        out << snps[i].chromosome << '\t';
                	out << snps[i].position << '\t';
	                out << snps[i].zscore << '\t';
        	        out << snps[i].lpvalue << '\t';
                	out << snps[i].pvalue << endl;
		}
		
	/*
                out << zscoreTable->item(i,0)->text() << '\t';
                out << zscoreTable->item(i,1)->text() << '\t';
                out << zscoreTable->item(i,2)->text() << '\t';
                out << zscoreTable->item(i,3)->text() << '\t';
                out << zscoreTable->item(i,4)->text() << '\t';
                out << zscoreTable->item(i,5)->text() << endl;
	*/
        }
        saveFile.close();

	saveFileName = project->path + "/toHighlight_table.txt";
        QFile saveFile2(saveFileName);
        if (!saveFile2.open(QFile::WriteOnly | QFile::Text))
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Cannot open file %1!")
                                .arg(popfileLineEdit->text()));
                return;
        }

        QTextStream out2(&saveFile2);

        out2 << "Name" << '\t' << "Chr" << '\t' << "Position" << '\t' << "Zscore" << '\t' <<"-log10(p-value)" << " p-value" << endl;

}

void ZscoreDialog::exportZscoreTableToText()
{
        QString saveFileName = QFileDialog::getSaveFileName(this, tr("Save Zscore Table"), commonPath);
        if (saveFileName.isEmpty())
        {
        //        QMessageBox::warning(this, GUI_TITLE,
        //                        tr("Cannot open/create file ! Check your rights"));
                return;
        }
        QFile saveFile(saveFileName);
        if (!saveFile.open(QFile::WriteOnly | QFile::Text))
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Cannot open/create file %1!. Check your rights !")
                                .arg(popfileLineEdit->text()));
                return;
        }

        QTextStream out(&saveFile);

        out << "Name" << '\t' << "Chr" << '\t' << "Position" << '\t' << "Zscore" << '\t' <<"-log10(p-value)" << " p-value" << endl;

        //int nRow = zscoreTable->rowCount();
        //We export columns number 0,1,2,6,7
	for (int j = 0; j < project->L.toInt(); j++)
	{
		if (snps[j].OK) {
	                out << qPrintable(snps[j].name) << '\t';
        	        out << qPrintable(snps[j].chromosome) << '\t';
                	out << qPrintable(snps[j].position) << '\t';
	                out << qPrintable(snps[j].zscore) << '\t';
        	        out << qPrintable(snps[j].lpvalue) << '\t';
                	out << qPrintable(snps[j].pvalue) << endl;
		}
		/*
                out << zscoreTable->item(i,0)->text() << '\t';
                out << zscoreTable->item(i,1)->text() << '\t';
                out << zscoreTable->item(i,2)->text() << '\t';
                out << zscoreTable->item(i,3)->text() << '\t';
                out << zscoreTable->item(i,4)->text() << '\t';
                out << zscoreTable->item(i,5)->text() << endl;
		*/
        }
        saveFile.close();
        QMessageBox::information(this, GUI_TITLE, tr(" Success! "));
        return;
}

void ZscoreDialog::keyPressEvent(QKeyEvent *e) {
    	if(e->key() != Qt::Key_Escape)
        QDialog::keyPressEvent(e);
}

void ZscoreDialog::createZscoreTableToPlotGreen()
{
	
	QString saveFileName = project->path + "/toHighlight_table.txt";
        QFile saveFile(saveFileName);
        if (!saveFile.open(QFile::WriteOnly | QFile::Text))
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Cannot open file %1!")
                                .arg(popfileLineEdit->text()));
                return;
        }

        QTextStream out(&saveFile);

        out << "Name" << '\t' << "Chr" << '\t' << "Position" << '\t' << "Zscore" << '\t' <<"-log10(p-value)" << " p-value" << endl;

        //int nRow = zscoreTable->rowCount();
        //We export columns number 0,1,2,6,7
	for (int j = 0; j < project->L.toInt(); j++)
	{
		if (snps[j].OK) {
	                out << qPrintable(snps[j].name) << '\t';
        	        out << qPrintable(snps[j].chromosome) << '\t';
                	out << qPrintable(snps[j].position) << '\t';
	                out << qPrintable(snps[j].zscore) << '\t';
        	        out << qPrintable(snps[j].lpvalue) << '\t';
                	out << qPrintable(snps[j].pvalue) << endl;
		}
        }
        saveFile.close();

	saveFileName = project->path + "/manhattan_table.txt";
        QFile saveFile2(saveFileName);
        if (!saveFile2.open(QFile::WriteOnly | QFile::Text))
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Cannot open file %1!")
                                .arg(popfileLineEdit->text()));
                return;
        }

        QTextStream out2(&saveFile2);

        out2 << "Name" << '\t' << "Chr" << '\t' << "Position" << '\t' << "Zscore" << '\t' <<"-log10(p-value)" << " p-value" << endl;

        //nRow = zscoreTable->rowCount();
        //We export columns number 0,1,2,6,7
	int nbSnp = project->runs[curIndex].i;
	if (!chrComboBox->currentText().isEmpty() && !chrComboBox->currentText().startsWith(tr("ALL"))) {
		for (int j = 0; j < nbSnp; j++) {
			if(QString::compare(chrComboBox->currentText(),
					snps[j].chromosome,Qt::CaseSensitive) == 0) {
	                		out2 << qPrintable(snps[j].name) << '\t';
        	        		out2 << qPrintable(snps[j].chromosome) << '\t';
                			out2 << qPrintable(snps[j].position) << '\t';
               	 			out2 << qPrintable(snps[j].zscore) << '\t';
                			out2 << qPrintable(snps[j].lpvalue) << '\t';
                			out2 << qPrintable(snps[j].pvalue) << endl;
                	}
		}
        } else {
		for (int j = 0; j < nbSnp; j++) {
	                	out2 << qPrintable(snps[j].name) << '\t';
        	        	out2 << qPrintable(snps[j].chromosome) << '\t';
                		out2 << qPrintable(snps[j].position) << '\t';
                		out2 << qPrintable(snps[j].zscore) << '\t';
	                	out2 << qPrintable(snps[j].lpvalue) << '\t';
        	        	out2 << qPrintable(snps[j].pvalue) << endl;
        	}
	}
        saveFile2.close();
}

void ZscoreDialog::help()
{
        QToolButton *bt = qobject_cast<QToolButton *>(QObject::sender());
        if (bt->text() == tr("run")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr("Specify the run that you want to analyse.\n\nYou can select a run in the list. It will be loaded in the table and you will be able to analyse it."));
        } else if (bt->text() == tr("number")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr("This is the current number of snps displayed in the table."));
        } else if (bt->text() == tr("chr")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr("You can select a specific chromosome or display all snps by selecting ALL.\n\nIn the case you did not provide snp information, all snps will be in chromosome 0."));
        } else if (bt->text() == tr("nameSearch")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr("You can search for snps with specific names.\n\nFor example, specify the list of snps that you are searching for, separated by commas. For example, \"SNP_1, SNP_2, SNP_9\"."));
        } else if (bt->text() == tr("position")) {
                        QMessageBox::information(this, GUI_TITLE,
				     tr("You can search for snps in a specific range of positions.\n\nIt can help you to search for or count snps in a specific range of positions (in a specific snp, for example). If you did not provide snp information,  the snp position is by default the number of the snp in it's order of appearance.\nIf you specify the lower (or upper) bound, your search will display the snps with position above (or below) that bound."));
        } else if (bt->text() == tr("zscore")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr("You can search for snps in a specific range of zscores.\n\nIf you specify the lower (or upper) bound, your search will display the snps with zscore above (or below) that bound."));
        } else if (bt->text() == tr("pvalue")) {
                        QMessageBox::information(this, GUI_TITLE,
					tr("You can search for snps in a specific range of pvalues.\n\nIf you specify the lower (or upper) bound, your search will display the snps with pvalue above (or below) that bound."));
        } else if (bt->text() == tr("lpvalue")) {
                        QMessageBox::information(this, GUI_TITLE,
					tr("You can search for snps in a specific range of -log_10(pvalues).\n\nIf you specify the lower (or upper) bound, your search will display the snps with -log_10(pvalue) above (or below) that bound."));
        } else if (bt->text() == tr("toText")) {
                        QMessageBox::information(this, GUI_TITLE,
					tr("You can export the current table of snps with their information in text format."));
        } else if (bt->text() == tr("toPlot")) {
                        QMessageBox::information(this, GUI_TITLE,
				tr("You can create a pdf of the manhattan plot of the snps currently in the table.\n\nA manhattan plot displays the -log_10(palue) as a function of the position of each snp.\nIf you did not provide snps information, the snps will be displayed in the order they appear in the genotype data file. In this case, you cannot look for manhattan patterns. But it can be useful."));
        } else if (bt->text() == tr("toGreenPlot")) {
                        QMessageBox::information(this, GUI_TITLE,
				tr("You can create a pdf of the manhattan plot with all snps in black and with the snps from the table in green.\n\nThis can help you visualize specific snps.\nA manhattan plot displays the -log_10(palue) as a function of the position of each snp.\nIf you did not provide snps information, the snps will be displayed in the order they appear in the genotype data file. In this case, you cannot look for manhattan patterns. But it can be useful."));
	}
}
