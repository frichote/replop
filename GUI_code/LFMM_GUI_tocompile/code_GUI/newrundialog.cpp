/*
    LFMM GUI, file: newrundialog.cpp
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
#include "newrundialog.h"
#include "title.h"
#include "advancedialog.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

	NewRunDialog::NewRunDialog(QWidget *parent, int D1)
: QDialog(parent)
{

	D = D1;
	//hasGeoData = hasGeo;	

	setWindowFlags(Qt::WindowCloseButtonHint);
	setWindowTitle(tr("New Run(s)"));

	//SvdRadioButton = new QRadioButton(tr("Singular Value Decomposition"));
	//SvdRadioButton->setEnabled(false);

	GSRadioButton = new QRadioButton(tr("Gibbs Sampler"));
	connect(GSRadioButton, SIGNAL(toggled(bool)), this, SLOT(GSToggled(bool)));
	//VBRadioButton = new QRadioButton(tr("Variational Bayes"));
	//VBRadioButton->setEnabled(false);

        QToolButton *methodHelp = new QToolButton;
        methodHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        methodHelp->setText(tr("method"));
        methodHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        methodHelp->setAutoRaise(true);
        methodHelp->setStatusTip(tr("Help"));
        connect(methodHelp, SIGNAL(clicked()), this, SLOT(help()));

	QHBoxLayout *typeLayout = new QHBoxLayout;
	//typeLayout->addWidget(SvdRadioButton);
	typeLayout->addWidget(GSRadioButton);
	//typeLayout->addWidget(VBRadioButton);
	typeLayout->addWidget(methodHelp);
	tGroupBox = new QGroupBox(tr("Algorithm"));
	tGroupBox->setLayout(typeLayout);

	scriptLabel = new QLabel(tr("Set Multiple Ks"));
	scriptCheckBox = new QCheckBox();
	connect(scriptCheckBox, SIGNAL(stateChanged(int)), this, SLOT(scriptStateChanged(int)));

        QToolButton *scriptHelp = new QToolButton;
        scriptHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        scriptHelp->setText(tr("script"));
        scriptHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        scriptHelp->setAutoRaise(true);
        scriptHelp->setStatusTip(tr("Help"));
        connect(scriptHelp, SIGNAL(clicked()), this, SLOT(help()));

	rLabel = new QLabel(tr("Number of Runs (per K):"));
	rLineEdit = new QLineEdit;
	QIntValidator *rV = new QIntValidator(this);
	rV->setBottom(1);
	rLineEdit->setValidator(rV);

        QToolButton *rHelp = new QToolButton;
        rHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        rHelp->setText(tr("r"));
        rHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        rHelp->setAutoRaise(true);
        rHelp->setStatusTip(tr("Help"));
        connect(rHelp, SIGNAL(clicked()), this, SLOT(help()));

	kLabel = new QLabel(tr("Number of Latent Factors:"));
	kLineEdit = new QLineEdit;
	QIntValidator *kV = new QIntValidator(this);
	kV->setRange(1, 216);
	kLineEdit->setValidator(kV);

	toKLabel = new QLabel(tr("to:"));
	toKLineEdit = new QLineEdit;
	QIntValidator *toKV = new QIntValidator(this);
	toKV->setRange(1, 216);
	toKLineEdit->setValidator(toKV);

	advanced = new QPushButton(tr("Advanced Options"));
	advanced->setEnabled(false);
	connect(advanced, SIGNAL(clicked()), this, SLOT(advOpt()));

        QToolButton *kHelp = new QToolButton;
        kHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        kHelp->setText(tr("k"));
        kHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        kHelp->setAutoRaise(true);
        kHelp->setStatusTip(tr("Help"));
        connect(kHelp, SIGNAL(clicked()), this, SLOT(help()));

        dLabel = new QLabel(tr("Chosen Environmental variables (separated by commas):"));
        dLineEdit = new QLineEdit;
        QToolButton *dHelp = new QToolButton;
        dHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        dHelp->setText(tr("d"));
        dHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        dHelp->setAutoRaise(true);
        dHelp->setStatusTip(tr("Help"));
        connect(dHelp, SIGNAL(clicked()), this, SLOT(help()));

	sLabel = new QLabel(tr("Total number of Sweeps:"));
	sLineEdit = new QLineEdit;
	QIntValidator *sV = new QIntValidator(this);
	sV->setBottom(1);
	sLineEdit->setValidator(sV);

        QToolButton *sHelp = new QToolButton;
        sHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        sHelp->setText(tr("s"));
        sHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        sHelp->setAutoRaise(true);
        sHelp->setStatusTip(tr("Help"));
        connect(sHelp, SIGNAL(clicked()), this, SLOT(help()));

	bLabel = new QLabel(tr("Burn In Number of Sweeps:"));
	bLineEdit = new QLineEdit;
	QIntValidator *bV = new QIntValidator(this);
	bV->setBottom(0);
	bLineEdit->setValidator(bV);

        QToolButton *bHelp = new QToolButton;
        bHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        bHelp->setText(tr("b"));
        bHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        bHelp->setAutoRaise(true);
        bHelp->setStatusTip(tr("Help"));
        connect(bHelp, SIGNAL(clicked()), this, SLOT(help()));

	nbThreadLabel = new QLabel(tr("Number of Processes used:"));
	nbThreadLineEdit = new QLineEdit("1");
	QIntValidator *nbThread = new QIntValidator(this);
	nbThread->setRange(1, 100); // TODO
	nbThreadLineEdit->setValidator(nbThread);
#ifdef Q_WS_WIN
	nbTreadLineEdit->setEnabled(false);
#endif


        QToolButton *threadHelp = new QToolButton;
        threadHelp->setIcon(QIcon(tr(":/images/helpreference.png")));
        threadHelp->setText(tr("thread"));
        threadHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
        threadHelp->setAutoRaise(true);
        threadHelp->setStatusTip(tr("Help"));
        connect(threadHelp, SIGNAL(clicked()), this, SLOT(help()));

	QGridLayout *inputLayout = new QGridLayout;
	inputLayout->addWidget(tGroupBox, 3, 0, 1, 3); 			//OK
	inputLayout->addWidget(scriptLabel,4,0);
	inputLayout->addWidget(scriptCheckBox,4,1);
	inputLayout->addWidget(scriptHelp,4,4);
	inputLayout->addWidget(rLabel, 5, 0, 1, 1);
	inputLayout->addWidget(rLineEdit, 5, 1, 1, 3);
	inputLayout->addWidget(rHelp,5,4);
	inputLayout->addWidget(kLabel, 6, 0,1,1);
	inputLayout->addWidget(kLineEdit, 6, 1,1,1);
	inputLayout->addWidget(toKLabel, 6, 2, 1,1,Qt::AlignRight);
	inputLayout->addWidget(toKLineEdit, 6, 3, 1,1);
	inputLayout->addWidget(advanced,9,3);
	inputLayout->addWidget(kHelp,6,4);
	inputLayout->addWidget(dLabel, 7, 0, 1, 1);
	inputLayout->addWidget(dLineEdit, 7, 1, 1, 3);
	inputLayout->addWidget(dHelp,7,4);
	inputLayout->addWidget(sLabel, 14, 0);
	inputLayout->addWidget(sLineEdit, 14, 1, 1, 3);
	inputLayout->addWidget(sHelp,14,4);
	inputLayout->addWidget(bLabel, 15, 0);
	inputLayout->addWidget(bLineEdit, 15, 1, 1, 3);
	inputLayout->addWidget(bHelp,15,4);
	inputLayout->addWidget(nbThreadLabel, 17, 0,1,1);
	inputLayout->addWidget(nbThreadLineEdit, 17, 1,1,1);
	inputLayout->addWidget(threadHelp,17,4);

	QPushButton *okPushButton = new QPushButton(tr("OK"));
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
	mainLayout->addLayout(inputLayout);
	mainLayout->addStretch();
	mainLayout->addSpacing(5);
	mainLayout->addLayout(buttonLayout);

	setLayout(mainLayout);
}

NewRunDialog::~NewRunDialog()
{
}

void NewRunDialog::help()
{
        QToolButton *bt = qobject_cast<QToolButton *>(QObject::sender());
        if (bt->text() == tr("method")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr("The method for estimating parameters is the Gibbs Sampling algorithm. Please, check the reference manual and refer to our papers for more information."));
        } else if (bt->text() == tr("script")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr("If you check this box, you can run the algorithm for several values of K, the number of latent factors, sequentially.\n\nOne run file directory will be created for each run."));
        } else if (bt->text() == tr("r")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr("You can run several runs with the same parameter sets for each value of K, the number of latent factors, sequentially.\n\nOne run file directory will be created for each run."));
        } else if (bt->text() == tr("k")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr("Specify the number latent factors.\n\nThis number is the number of principal components (or latent factors) that should be required for the neutral structure of the data. Several values should be tested. Underestimating the value of K will make the model too liberal. Overestimating the value of K will make the model too conservative. In our paper, we used the number of significant principal components in the Tracy-Widom test of SmartPCA. This heuristic is a bit too conservative. We advise you to carefully choose the value of K and, if possible, to compare your results at several values of K."));
        } else if (bt->text() == tr("d")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr("You can run LFMM for several different environmental variables.\n\nOne run file directory will be created for each variable. For example, specify the list of number of environmental variables, separated by commas. For example, \"1,2,5\"."));
        } else if (bt->text() == tr("s")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr("Specify the number of iterations in the Gibbs Sampling algorithm following a burnin period.\n\nThe number of iterations in the Gibbs Sampling algorithm should be large. One way to test if it is large enough is to check if the results are similar for several runs at the same value of K."));
        } else if (bt->text() == tr("b")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr("Specify the number of burnin iterations in the Gibbs Sampling algorithm."));
        } else if (bt->text() == tr("thread")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr("Specify the number of processes that you will use when you run the algorithm in parrallel.\n\nBe careful, this number has to be lower or equal to the number of physical processes available on your computer. By default, this number is set to 1."));
        } else if (bt->text() == tr("script")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr(""));
        } else if (bt->text() == tr("script")) {
                        QMessageBox::information(this, GUI_TITLE,
                                     tr(""));
	}
}


void NewRunDialog::accept()
{
	if (validate())
	{
		QDialog::accept();
	}
}

void NewRunDialog::scriptStateChanged(int state)
{
	bool checked = state == Qt::Checked;
	toKLabel->setEnabled(checked);
	toKLineEdit->setEnabled(checked);
}

void NewRunDialog::GSToggled(bool checked)
{
	sLabel->setEnabled(checked);
	sLineEdit->setEnabled(checked);
	bLabel->setEnabled(checked);
	bLineEdit->setEnabled(checked);
}

void NewRunDialog::advOpt()
{
	//AdvancedOption *advancedoption = new AdvancedOption;
	printf("Advanced options: no implemented yet !!!\n");
	/*
	   bool admixture = admRadioButton->isChecked();
	   bool bBYM = admRadioButton->isChecked() && bymRadioButton->isChecked();
	   advancedoption->setState(scOption,hasGeoData,psi,updatePsi,sigma,updateSigma,admixture,bBYM,lambda);       //restore the previous user choice
	   advancedoption->exec();

	   psi = advancedoption->pLineEdit->text();
	   updatePsi = advancedoption->pUpdateCheckBox->checkState() == Qt::Checked;
	   sigma = advancedoption->sigmaLineEdit->text();
	   updateSigma = advancedoption->updateCheckBox->checkState() == Qt::Checked;
	   lambda = advancedoption->dLineEdit->text();


	   if (hasGeoData)
	   {
	   if (advancedoption->mRadioButton->isChecked())
	   {
	   scOption = "m";
	   }
	   if (advancedoption->dRadioButton->isChecked())
	   {
	   scOption = "d";
	   }
	   if (advancedoption->xRadioButton->isChecked())
	   {
	   scOption = "x";
	   }
	   if (advancedoption->uRadioButton->isChecked())
	   {
	   scOption = advancedoption->uLineEdit->text();;
	   }
	   }
	   delete advancedoption;
	 */
}

bool NewRunDialog::validate()
{
	QString rText = rLineEdit->text();
	int rPos = 0;
	if (rLineEdit->validator()->validate(rText, rPos) != QValidator::Acceptable)
	{
		QMessageBox::warning(this, GUI_TITLE, tr("Invalid Number of Runs"));
		return false;
	}

	QString kText = kLineEdit->text();
	int kPos = 0;
	if (kLineEdit->validator()->validate(kText, kPos) != QValidator::Acceptable)
	{
		QMessageBox::warning(this, GUI_TITLE, 
				tr("Please input an integer upper or equal than 1 for the number of latent factors.\n\nThis number is the number of principal components (or latent factors) that should be required for the neutral structure of the data. Several values should be tested. Underestimating the value of K will make the model too liberal. Overestimating the value of K will make the model too conservative. In our paper, we used the number of significant principal components in the Tracy-Widom test of SmartPCA. This heuristic is a bit too conservative. We advise you to carefully choose the value of K and, if possible, to compare your results at several values of K."));
		return false;
	}

	/*
        QString dText = dLineEdit->text();
        int dPos = 0;
        if (kLineEdit->validator()->validate(kText, kPos) != QValidator::Acceptable)
        {
                QMessageBox::warning(this, GUI_TITLE,
                                tr("Please input an integer from 1 to 216 for number of clusters."));
                return false;
        }
	*/



	if (scriptCheckBox->checkState() == Qt::Checked)
	{
		QString toKText = toKLineEdit->text();
		int toKPos = 0;
		if (toKLineEdit->validator()->validate(toKText, toKPos) != QValidator::Acceptable)
		{
			QMessageBox::warning(this, GUI_TITLE, 
					tr("Please input an integer upper or equal than 1 for the number of latent factors.\n\nThis number is the number of principal components (or latent factors) that should be required for the neutral structure of the data. Several values should be tested. Underestimating the value of K will make the model too liberal. Overestimating the value of K will make the model too conservative. In our paper, we used the number of significant principal components in the Tracy-Widom test of SmartPCA. This heuristic is a bit too conservative. We advise you to carefully choose the value of K and, if possible, to compare your results at several values of K."));
			return false;
		}

		if (toKText.toInt() < kText.toInt())
		{
			QMessageBox::warning(this, GUI_TITLE, 
					tr("The upper number of clusters must be greater or equal than the lower number of clusters."));
			return false;
		}
	}

	QString nbThreadText = nbThreadLineEdit->text();
	int nbThreadPos = 0;
	if (nbThreadLineEdit->validator()->validate(nbThreadText, nbThreadPos) != QValidator::Acceptable)
	{
		QMessageBox::warning(this, GUI_TITLE, 
				tr("Please input an integer upper or equal to 1 for the number of processus used."));
		return false;
	}

	if (GSRadioButton->isChecked()) { // == Qt::Checked) {
		QString sText = sLineEdit->text();
		int sPos = 0;
		if (sLineEdit->validator()->validate(sText, sPos) != QValidator::Acceptable)
		{
			QMessageBox::warning(this, GUI_TITLE, 
					tr("Invalid Total Number of Sweeps"));
			return false;
		}


		QString bText = bLineEdit->text();
		int bPos = 0;
		if (bLineEdit->validator()->validate(bText, bPos) != QValidator::Acceptable)
		{
			QMessageBox::warning(this, GUI_TITLE, 
					tr("Invalid Burn In Number of Sweeps"));
			return false;
		}


		if (!(sLineEdit->text().toInt() > bLineEdit->text().toInt()))
		{
			QMessageBox::warning(this, GUI_TITLE, 
					tr("Total number of sweeps must be larger than burn in number of sweeps."));
			return false;
		}  
	}

	if(dLineEdit->text().isEmpty()) {
               QMessageBox::warning(this, GUI_TITLE,
                      tr("Invalid number for environmental variable."));
               return false;
	}

	QRegExp regExp("[\\t\\s]+|[\\s\\t]*[,;][\\s\\t]*");
 	QStringList oneRowList = dLineEdit->text().split(regExp, QString::SkipEmptyParts);

	if (oneRowList.size() == 0) {
               QMessageBox::warning(this, GUI_TITLE,
                      tr("Invalid number for environmental variable."));
               return false;
	}


	varList.clear();
	nD = 0;
	for(int i=0; i<oneRowList.size();i++) {
		int nb = oneRowList[i].toInt();
		//int intD = D.toInt();
		//printf("%s\n",qPrintable(D));
			
		if ( nb<=0 || nb>D) {
               		QMessageBox::warning(this, GUI_TITLE,
                      		tr("One of the number for the environmental variable is not correct.\n\nThis number should be between 1 and the number of environmental variables."));
               		return false;
		}
		nD++;
		varList.append(oneRowList[i]);
	}

	return true;
}
