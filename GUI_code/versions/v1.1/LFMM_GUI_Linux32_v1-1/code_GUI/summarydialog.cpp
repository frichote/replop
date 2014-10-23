/*
    LFMM GUI, file: summarydialog.cpp
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
#include "summarydialog.h"
#include "title.h"
#include "project.h"

using namespace std;

SummaryDialog::SummaryDialog(QWidget *parent) 
	: QDialog(parent)
{
	setWindowTitle(tr("Summarize Project Runs"));
	
	/*
	QLabel *lowerLabel = new QLabel(tr("Lower Range: "));
	lowerComboBox = new QComboBox;
	
	QLabel *upperLabel = new QLabel(tr("Upper Range: "));
	upperComboBox = new QComboBox;
	
	QLabel *avgDICLabel = new QLabel(tr("Avg. DIC =   "));
	avgDICTextEdit = new QLabel;
	*/	

	/*
	QVBoxLayout *lowerLayout = new QVBoxLayout;
	lowerLayout->addWidget(lowerLabel);
	lowerLayout->addWidget(lowerComboBox,Qt::AlignLeft);
	
	QVBoxLayout *upperLayout = new QVBoxLayout;
	upperLayout->addWidget(upperLabel);
	upperLayout->addWidget(upperComboBox,Qt::AlignLeft);

	QLabel *percentageLabel = new QLabel(tr("Filter lowest DIC runs:"));
	percentageComboBox = new QComboBox();
	
	for (int i = 1; i <= 5; i++)
	{
		percentageComboBox->addItem(QString("%1 %").arg(i*10, 3, 10, QChar('0')));
	}
	
	QVBoxLayout *percentageLayout = new QVBoxLayout;
	percentageLayout->addWidget(percentageLabel);
	percentageLayout->addWidget(percentageComboBox);
		
	
	QHBoxLayout *avgDICLayout = new QHBoxLayout;
	avgDICLayout->addWidget(avgDICLabel);
	avgDICLayout->addWidget(avgDICTextEdit);
	*/

	toTextPushButton = new QPushButton(tr("Export Table to Text File"));
	
	QGridLayout *rangeLayout = new QGridLayout;

	/*
	rangeLayout->addLayout(lowerLayout,0,0,1,1);
	rangeLayout->addLayout(upperLayout,0,1,1,1);
	rangeLayout->addLayout(percentageLayout,0,2,1,1);
	rangeLayout->addLayout(avgDICLayout,1,0,1,1);
	*/
	rangeLayout->addWidget(toTextPushButton,6,0,1,2);
	
	summaryTable = new SummaryTable(this);
	summaryTable->resizeColumnsToContents();
	summaryTable->setMinimumSize(summaryTable->minimumSizeHint());
	QGridLayout *tableLayout = new QGridLayout;
	tableLayout->addWidget(summaryTable,0,0,10,5);
	
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(summaryTable);
	mainLayout->addLayout(rangeLayout);
	//mainLayout->addStretch();

	QHBoxLayout *mainLayout2 = new QHBoxLayout;
	mainLayout2->addLayout(mainLayout);
	mainLayout2->addStretch();

	setLayout(mainLayout2);
}

SummaryDialog::~SummaryDialog()
{
	if (summaryTable) 
	{
		delete summaryTable;
	}
}

void SummaryDialog::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Escape)
	{
		close();
	}
}

void SummaryDialog::closeEvent(QCloseEvent *event)
{
	event->accept();
	emit finished();
}

void SummaryDialog::closeClicked()
{
	close();
}

void SummaryDialog::clear()
{
        summaryTable->clearContents();

        project = NULL;
	updateSummaryTable();

	//lowerComboBox->disconnect();
	//lowerComboBox->clear();
	//upperComboBox->disconnect();
	//upperComboBox->clear();
	//percentageComboBox->disconnect();
}

bool SummaryDialog::summaryRangeUpdated()
{
	/*
        summaryLowerRange = lowerComboBox->currentIndex();
        summaryUpperRange = upperComboBox->currentIndex();


        if (summaryLowerRange < 0 || summaryUpperRange < 0 )
        {
                return false;
        }

        if (summaryUpperRange < summaryLowerRange)
        {
                QMessageBox::warning(this,GUI_TITLE,tr("The upper range must be greater than the lower range!"));
                return false;
        }

        percentageComboBox->setCurrentIndex(9);
	*/
        updateSummaryTable();
        return true;
}

bool SummaryDialog::initSummary()
{

        int size = project->runs.size(); // number of runs
        // should not happen
        if (size < 0)
        {
                return false;
        }

        // there are runs
        if (size > 0)
        {
		/*
                int numDigits = int(log10(double(size)) + 1);
                //set<int> setKmax;
                // for each run
                for (int i = 0; i < size; i++)
                {
                        QString currentItem = project->runs[i].name;
                        int toCut = currentItem.lastIndexOf('_') + 1;
                        currentItem.remove(0,toCut);
                        // add data
                        lowerComboBox->addItem(QString("%1").arg(currentItem.toInt(), numDigits, 10, QChar('0')));
                        upperComboBox->addItem(QString("%1").arg(currentItem.toInt(), numDigits, 10, QChar('0')));

                        // suggest K
                  //      setKmax.insert(project->runs[i].K.toInt());
                }
		*/
		/*
                set<int>::iterator KmaxIterator;
                for( KmaxIterator = setKmax.begin(); KmaxIterator != setKmax.end(); KmaxIterator++ ) {
                        KmaxComboBox->addItem(QString("%1").arg(*KmaxIterator));//, numDigits, 10, QChar('0')));
                }
		*/

                // init
                //KmaxComboBox->setCurrentIndex(0);
                //lowerComboBox->setCurrentIndex(0);
                //upperComboBox->setCurrentIndex((size - 1));
        }

        else
        // no run
        {
                // init
                //KmaxComboBox->setCurrentIndex(0);
                //lowerComboBox->setCurrentIndex(0);
                //upperComboBox->setCurrentIndex(0);
        }

        // get the ranges to display
        //summaryLowerRange = lowerComboBox->currentIndex();
        //summaryUpperRange = upperComboBox->currentIndex();

        //percentageComboBox->setCurrentIndex(9);
        if (size > 0)
        {
        	updateSummaryTable();
        }

        // actions to connect

        // update table if the ranges is are changed
        //connect(lowerComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(summaryRangeUpdated()));
        //connect(upperComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(summaryRangeUpdated()));
        // if 
        connect(summaryTable, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(loadSummaryItem(QTableWidgetItem *)));

        //connect(percentageComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(filterCandidateRuns(int)));

        // export text
        connect(toTextPushButton, SIGNAL(clicked()),this,SLOT(exportTableToText()));
        return true;
}

void SummaryDialog::loadSummaryItem(QTableWidgetItem *item)
{
        if (item->text().endsWith(".png"))
        {
        //      loadGraph(project->path + "/" + item->text());
        }
}

/*
void SummaryDialog::filterCandidateRuns(int percentageIndex)
{
        if (percentageIndex < 0)
        {
                return;
        }
        //int Kmax = KmaxComboBox->currentText().toInt();
        //int Kmax = 0;
        //int KmaxIndex = KmaxComboBox->currentIndex();
        updateSummaryTable();
        //QString percentage = percentageComboBox->itemText(percentageIndex);
        //percentage.chop(1);

        //int nbCandidates = candidateListWidget->count();
        int nbCandidates = summaryTable->rowCount();

        if (nbCandidates == 0)
        {
                return;
        }
        if (percentage.toInt() == 100)
        {
                return;
        }

        int size = project->runs.size();
        QStringList candidateList;
        double avgDIC = 0.0;

        for (int i = 0; i < nbCandidates; i++)
        {
                for (int j = 0; j < size; j ++)
                {
                        //if (project->runs[j].name == candidateListWidget->item(i)->text())
                        if (project->runs[j].name == summaryTable->item(i,0)->text())
                        {
                                candidateList << QString("%1").arg(j);
                                //avgDIC += project->runs[i].DIC.toDouble();
                                break;
                        }
                }
        }

        QList < QTableWidgetItem*> runsToReject;
        for (int i = 0; i < nbCandidates; i ++)
        {
                int runIndex = candidateList[i].toInt();
                /*
                   if (project->runs[runIndex].DIC.toDouble() >= maxDIC)
                   {    
                //runsToReject << candidateListWidget->item(i);
                runsToReject << summaryTable->item(i,0);
                avgDIC -= project->runs[runIndex].DIC.toDouble();
                }
        }

        if (runsToReject.size() < nbCandidates)
        {
                avgDIC /= (nbCandidates - runsToReject.size());
        }
        else
        {
                avgDIC = -1.0;
        }


        for (int i = 0; i < runsToReject.size(); i ++)
        {
                summaryTable->removeRow(summaryTable->row(runsToReject.at(i)));

        }

        //Update average DIC
        avgDICTextEdit->setText(QString(tr("%1").arg(avgDIC)));
}
*/

void SummaryDialog::updateSummaryTable()
{
        // TODO
	if (project) {
        int nbRun = project->runs.size();//(summaryUpperRange-summaryLowerRange)+1;
        summaryTable->setRowCount(nbRun);
        //populate the summary table and compute average DIC
        //double avgDIC = 0.0;

        int DICmaxDigits = 0;
        //int KmaxDigits = 0;
        //First pass to determine number of digits for proper sort
                /*
        for (int j = 0; j <= (summaryUpperRange-summaryLowerRange); j++)
        {
                   int i = j + summaryLowerRange;
                   QString currDIC = project->runs[i].DIC;

                   int toCut = currDIC.indexOf('.');
                   currDIC = currDIC.left(toCut);       //only keep digits before decimals
                   QString currK = project->runs[i].K;
                   if (currDIC.size() > DICmaxDigits)
                   {
                   DICmaxDigits = currDIC.size();
                   }
                   if (currK.size() > KmaxDigits)
                   {
                   KmaxDigits = currK.size();
                   }
        }
                 */


        for (int j = 0; j < nbRun; j++)
        {
                int i = j;

                //run names
                QTableWidgetItem *name = new QTableWidgetItem(tr("%1").arg(project->runs[i].name));
                name->setFlags(Qt::ItemIsEnabled);
                summaryTable->setItem(j,0,name);

                QTableWidgetItem *D = new QTableWidgetItem(tr("%1").arg(project->runs[i].D));
                D->setFlags(Qt::ItemIsEnabled);
                summaryTable->setItem(j,1,D);

                QTableWidgetItem *K = new QTableWidgetItem(tr("%1").arg(project->runs[i].K));
                K->setFlags(Qt::ItemIsEnabled);
                summaryTable->setItem(j,2,K);

                QTableWidgetItem *DIC = new QTableWidgetItem(tr("%1").arg(project->runs[i].DIC));
                DIC->setFlags(Qt::ItemIsEnabled);
                summaryTable->setItem(j,3,DIC);

                QTableWidgetItem *Deviance = new QTableWidgetItem(tr("%1").arg(project->runs[i].Deviance));
                Deviance->setFlags(Qt::ItemIsEnabled);
                summaryTable->setItem(j,4,Deviance);

                //run max num of clusters
                //QTableWidgetItem *maxK = new QTableWidgetItem(tr("%1").arg(project->runs[i].K,KmaxDigits,QChar('0')));
                //maxK->setFlags(Qt::ItemIsEnabled);
                //summaryTable->setItem(j,1,maxK);

                //run DIC
                /*
                   QTableWidgetItem *dic = new QTableWidgetItem(tr("%1").arg(project->runs[i].DIC, DICmaxDigits, QChar('0')));
                   dic->setFlags(Qt::ItemIsEnabled);
                   summaryTable->setItem(j,2,dic);
                 */

                QTableWidgetItem *zscore = new QTableWidgetItem(tr("%1").arg(project->runs[i].ZS));
                zscore->setFlags(Qt::ItemIsEnabled);
                summaryTable->setItem(j,5,zscore);
        }

        //Display average DIC
	/*
        avgDIC /= (double)(summaryUpperRange-summaryLowerRange +1);
        avgDICTextEdit->setText(QString(tr("%1").arg(avgDIC)));
	*/
        summaryTable->resizeColumnToContents(0);
        summaryTable->resizeColumnToContents(1);
        summaryTable->resizeColumnToContents(2);
        summaryTable->resizeColumnToContents(3);
        summaryTable->resizeColumnToContents(4);
        summaryTable->resizeColumnToContents(5);
	}
}

void SummaryDialog::removeRunFromSummaryTable(int runLabel, int Kremoved)
{
        int size = project->runs.size(); //one run has just been removed...

        //upperComboBox->removeItem(runLabel);
        //lowerComboBox->removeItem(runLabel);

        //QString removedK = QString("%1").arg(Kremoved);//, numDigits, 10, QChar('0'));

	/*
        bool removeKfromComboBox = true;
        for (int i = 0; i < size; i ++)
        {
                if (removedK.toInt() == project->runs[i].K.toInt())
                {
                        //another run with same value of Kmax: we do nothing
                        removeKfromComboBox = false;
                        break;
                }
        }

        if (removeKfromComboBox)
        {
                int removeIndex = KmaxComboBox->findText(removedK);
                KmaxComboBox->removeItem(removeIndex);
        }
	*/

        if (size > 0)
        {
                //percentageComboBox->setCurrentIndex(9);
                updateSummaryTable();
        } else {
                clear();
        }
}

void SummaryDialog::addRunToSummaryTable()
{
        int size = project->runs.size();
        int numDigits = int(log10(double(size)) + 1);


        QString currentItem = project->runs[size-1].name;
        int toCut = currentItem.lastIndexOf('_') + 1;
        currentItem.remove(0,toCut);

	/*
        upperComboBox->addItem(QString("%1").arg(currentItem.toInt(), numDigits, 10, QChar('0')));
        lowerComboBox->addItem(QString("%1").arg(currentItem.toInt(), numDigits, 10, QChar('0')));
	*/


        //If we were on the last run, increment
	/*
        if (upperComboBox->currentIndex() == upperComboBox->count()-2)
        {
                upperComboBox->setCurrentIndex(upperComboBox->count()-1);
        }
	*/
        //int currentK = project->runs[size-1].K.toInt();
        //      int numDigitsK = int(log10(double(currentK)) + 1);

        //QString currK = QString("%1").arg(currentK);//, numDigitsK, 10, QChar('0'));


        //Insert the value of Kmax to the comboBox to the correct place if it's not already in it. The comboBox is initially sorted.
        //If it's empty, add it, else look for it and add it if not already in
	/*
        if (KmaxComboBox->count() == 0)
        {
                KmaxComboBox->addItem(currK);
        }


        else if (KmaxComboBox->findText(currK) == -1)
        {
                //Item is not in the comboBox
                int nbUniqueKmax = KmaxComboBox->count();
                bool found = false;
                for (int k = 0; k < nbUniqueKmax; k++)
                {
                        int Kmax = KmaxComboBox->itemText(k).toInt();
                        if (currK.toInt() < Kmax)
                        {
                                KmaxComboBox->insertItem(k,currK);
                                found = true;
                                break;
                        }
                }
                if (!found)
                {
                        KmaxComboBox->addItem(currK);
                }
        }
	*/
        //percentageComboBox->setCurrentIndex(9);
        updateSummaryTable();
}

void SummaryDialog::exportTableToText()
{
        QString saveFileName = QFileDialog::getSaveFileName(this, tr("Save Summary Table"), commonPath);
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
                                tr("Cannot open/create file!. Check your rights !"));
                return;
        }

        QTextStream out(&saveFile);

        out << "Run Label" << '\t' << "D" << '\t' << "K" << '\t' << "DIC" << '\t' <<"Deviance"<< endl;

        int nRow = summaryTable->rowCount();
        //We export columns number 0,1,2,6,7
        for (int i=0; i < nRow; i++)
        {
                out << summaryTable->item(i,0)->text() << '\t';
                out << summaryTable->item(i,1)->text() << '\t';
                out << summaryTable->item(i,2)->text() << '\t';
                out << summaryTable->item(i,3)->text() << '\t';
                out << summaryTable->item(i,4)->text() << endl;
        }
        saveFile.close();
        QMessageBox::information(this, GUI_TITLE, tr(" Success! "));
        return;
}

