/*
    LFMM GUI, file: advancedialog.cpp
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
#include "advancedialog.h"
#include "title.h"

// TODO 151012
AdvancedOption::AdvancedOption(QWidget *parent)
    : QDialog(parent)
{
	
	setWindowFlags(Qt::WindowCloseButtonHint);
	
    setWindowTitle(tr("Advanced Options"));
				
    pLabel = new QLabel(tr("Change Spatial Interaction Parameter:"));
    pLineEdit = new QLineEdit;
    QDoubleValidator *pV = new QDoubleValidator(this);
    pV->setRange(0.0, 100.0, 2);
    pLineEdit->setValidator(pV);
	
    pUpdateLabel = new QLabel(tr("Update Spatial Interaction Parameter"));
    pUpdateCheckBox = new QCheckBox();	
    
    sigmaLabel = new QLabel(tr("Change Variance:"));
    sigmaLineEdit = new QLineEdit;
    QDoubleValidator *sigmaV = new QDoubleValidator(this);
    sigmaV->setRange(0.0, 100.0, 2);
    sigmaLineEdit->setValidator(sigmaV);
	
    updateLabel = new QLabel(tr("Update Variance"));
    updateCheckBox = new QCheckBox();
	

    dLabel = new QLabel(tr("Parameter of Allele Freq. Model:"));
    dLineEdit = new QLineEdit;
    QDoubleValidator *dV = new QDoubleValidator(this);
    dV->setRange(1.0, 10.0, 2);
    dLineEdit->setValidator(dV);
    
    
    QLabel* titleLabel = new QLabel(tr("Set the geographic scale parameter:")); 
    mRadioButton = new QRadioButton(tr("Mean pairwise distance between individuals"));
    dRadioButton = new QRadioButton(tr("Median pairwise distance between individuals"));
    xRadioButton = new QRadioButton(tr("Max pairwise distance between individuals"));
    uRadioButton = new QRadioButton(tr("User defined: "));
    connect(uRadioButton, SIGNAL(toggled(bool)), this, SLOT(uRadioToggled(bool)));
    
    
    uLineEdit = new QLineEdit;
    QDoubleValidator *uV = new QDoubleValidator(this);
    uV->setBottom(0.01);
    uLineEdit->setValidator(uV);

    QPushButton *okPushButton = new QPushButton(tr("OK"));
    connect(okPushButton, SIGNAL(clicked()), this, SLOT(accept()));

    QPushButton *cancelPushButton = new QPushButton(tr("Cancel"));
    connect(cancelPushButton, SIGNAL(clicked()), this, SLOT(reject()));
   

    QGridLayout *geoLayout = new QGridLayout;
    geoLayout->addWidget(titleLabel,0, 0);
    geoLayout->addWidget(mRadioButton,1,0);
    geoLayout->addWidget(dRadioButton,2,0);
    geoLayout->addWidget(xRadioButton,3,0);
    geoLayout->addWidget(uRadioButton,4,0);
    geoLayout->addWidget(uLineEdit,4,1);
    
    geoGroupBox = new QGroupBox(tr("Geographic Options"));
    geoGroupBox->setLayout(geoLayout);
    
    QGridLayout *inputLayout = new QGridLayout;
    inputLayout->addWidget(pLabel,0,0);
    inputLayout->addWidget(pLineEdit,0,1);
    inputLayout->addWidget(pUpdateLabel,1,0);
    inputLayout->addWidget(pUpdateCheckBox,1,1);
    inputLayout->addWidget(sigmaLabel,2,0);
    inputLayout->addWidget(sigmaLineEdit,2,1);
    inputLayout->addWidget(updateLabel,3,0);
    inputLayout->addWidget(updateCheckBox,3,1);
    inputLayout->addWidget(dLabel,4,0);
    inputLayout->addWidget(dLineEdit,4,1);
    inputLayout->addWidget(geoGroupBox,5,0);
    
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


void AdvancedOption::uRadioToggled(bool checked)
{
	uLineEdit->setEnabled(checked);
}


void AdvancedOption::accept()
{
        if (validate())
        {
                QDialog::accept();
        }
}

AdvancedOption::~AdvancedOption()
{
}

bool AdvancedOption::validate()
{
	
	QString pText = pLineEdit->text();
	int pPos = 0;
	if (!admixture)
	{
		if (pLineEdit->validator()->validate(pText, pPos) != QValidator::Acceptable)
		{
			QMessageBox::warning(this, GUI_TITLE, 
					     tr("Please input a float from 0.0 to 10.0 for spatial interaction parameter (no admixture)."));
			return false;
		}
	}
	else 
	{
		if (!isBYM)
		{
			if (pLineEdit->validator()->validate(pText, pPos) != QValidator::Acceptable || pText.toDouble() >= 1.0)
			{
				QMessageBox::warning(this, GUI_TITLE, 
						     tr("Please input a float from 0.0 to 0.99 for spatial interaction parameter (admixture)."));
				return false;
			}
		}
		
		QString sigmaText = sigmaLineEdit->text();
		int sigmaPos = 0;
		if (sigmaLineEdit->validator()->validate(sigmaText, sigmaPos) != QValidator::Acceptable)
		{
			QMessageBox::warning(this, GUI_TITLE, 
					     tr("Please input a float from 0.0 to 100.0 for the initial variance of CAR."));
			return false;
		}
	}
	
	QString dText = dLineEdit->text();
	int dPos = 0;
	if (dLineEdit->validator()->validate(dText, dPos) != QValidator::Acceptable)
	{
		QMessageBox::warning(this, GUI_TITLE, 
				     tr("Please input a float from 1.0 to 10.0 for parameter of allele freq. model."));
		return false;
	}
	
	
	
	if (hasGeo)
	{
		QString uText = uLineEdit->text();
      	  	int uPos = 0;
       		if (uRadioButton->isChecked() && uLineEdit->validator()->validate(uText, uPos) != QValidator::Acceptable)
       	 	{
                	QMessageBox::warning(this, GUI_TITLE, 
                                     tr("Please input a float greater than 0.01 for the scale parameter"));
                	return false;
        	}
	}
        return true;
}

void AdvancedOption::setState(QString scOption, bool hasGeoData, QString oldPsi, bool oldUpdatePsi, QString oldSigma, bool oldUpdateSigma, bool adm, bool bBYM, QString oldLambda) 
{
	admixture = adm;
	hasGeo = hasGeoData;
	isBYM = bBYM;
	
	pLineEdit->setText(oldPsi);
	pLineEdit->setEnabled(!bBYM);
	pLabel->setEnabled(!bBYM);
	pUpdateLabel->setEnabled(adm && !bBYM);
	pUpdateCheckBox->setEnabled(adm && !bBYM);
	pUpdateCheckBox->setCheckState(oldUpdatePsi ? Qt::Checked : Qt::Unchecked);
	
	sigmaLineEdit->setEnabled(adm);
	sigmaLabel->setEnabled(adm);
	updateLabel->setEnabled(adm);
	updateCheckBox->setEnabled(adm);
	
	sigmaLineEdit->setText(oldSigma);
	updateCheckBox->setCheckState(oldUpdateSigma? Qt::Checked : Qt::Unchecked);
	
	dLineEdit->setText(oldLambda);
	
	geoGroupBox->setEnabled(hasGeoData);
	if (hasGeoData)
	{
		bool bMean = scOption == tr("m");
		bool bMed = scOption == tr("d");
		bool bMax = scOption == tr("x");
		bool bUser = !bMax && !bMed && !bMean;
        	mRadioButton->setChecked(bMean);
		dRadioButton->setChecked(bMed);
		xRadioButton->setChecked(bMax);
		uRadioButton->setChecked(bUser);
		uLineEdit->setEnabled(bUser);
		if (bUser)
		{
        		uLineEdit->setText(scOption);
		}
	}
}
