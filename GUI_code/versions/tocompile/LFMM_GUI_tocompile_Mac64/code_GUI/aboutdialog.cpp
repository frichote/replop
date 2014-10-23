/*
    LFMM GUI, file: aboutdialog.cpp
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


#include <QtGui>
#include "aboutdialog.h"
#include "title.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
{
	setWindowTitle(tr("About %1").arg(GUI_TITLE));

	QLabel *aboutLabel = new QLabel(tr("<b>%1</b> is a user friendly shell for "
		"<b>%2</b>, which is a MCMC algorithm for inference of associations "
		"between loci and environmental gradients.").arg(GUI_TITLE).arg(CMD_TITLE));
	aboutLabel->setWordWrap(true);
	
	QLabel *emailLabel = new QLabel(tr("Contact Authors: "));
	QLabel *emailUrl = new QLabel(tr("<a href=\"mailto:eric.frichot@imag.fr\">eric.frichot@imag.fr</a>"));
	QLabel *emailUrl2 = new QLabel(tr("<a href=\"mailto:olivier.francois@imag.fr\">olivier.francois@imag.fr</a>"));
	emailUrl->setOpenExternalLinks(true);
	emailUrl2->setOpenExternalLinks(true);
	QLabel *wwwLabel = new QLabel(tr("Download Latest Version: "));
	QLabel *wwwUrl = new QLabel(tr("<a href=\"http://www-timc.imag.fr/Olivier.Francois/lfmm.html\">http://www-timc.imag.fr/Olivier.Francois/lfmm.html</a>"));
	wwwUrl->setOpenExternalLinks(true);
	QGridLayout *urlLayout = new QGridLayout;
	urlLayout->addWidget(emailLabel, 0, 0);
	urlLayout->addWidget(emailUrl, 0, 1);
	urlLayout->addWidget(emailUrl2, 1, 1);
	urlLayout->addWidget(wwwLabel, 2, 0);
	urlLayout->addWidget(wwwUrl, 2, 1);

	QLabel *disclaimerLabel = new QLabel(tr(
    "LFMM GUI Copyright (C) 2012 Eric Frichot\n"
    "\n"
    "This program is free software: you can redistribute it and/or modify\n"
    "it under the terms of the GNU General Public License as published by\n"
    "the Free Software Foundation, either version 3 of the License, or\n"
    "(at your option) any later version.\n"
    "\n"
    "This program is distributed in the hope that it will be useful,\n"
    "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
    "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
    "GNU General Public License for more details.\n"
    "\n"
    "You should have received a copy of the GNU General Public License\n"
    "along with this program.  If not, see <http://www.gnu.org/licenses/>.\n"));
	disclaimerLabel->setWordWrap(true);

	QPushButton *okPushButton = new QPushButton(tr("OK"));
	connect(okPushButton, SIGNAL(clicked()), this, SLOT(accept()));
	QHBoxLayout *okLayout = new QHBoxLayout;
	okLayout->addStretch();
	okLayout->addWidget(okPushButton);
	okLayout->addStretch();

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(aboutLabel);
	mainLayout->addLayout(urlLayout);
	mainLayout->addWidget(disclaimerLabel);
	mainLayout->addStretch();
	mainLayout->addSpacing(5);
	mainLayout->addLayout(okLayout);

	setLayout(mainLayout);
}

AboutDialog::~AboutDialog()
{
}

