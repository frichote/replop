/*
    LFMM GUI, file: zscoretable.cpp
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
#include <cstdio>
#include <iostream>
#include "zscoretable.h"

using namespace std;
ZscoreTable::ZscoreTable(QWidget *parent) : QTableView(parent)
{
	setHeader();
}

ZscoreTable::~ZscoreTable()
{
}

void ZscoreTable::setHeader() {

	model = new QStandardItemModel(1,6,this); //2 Rows and 3 Columns
	QStringList listeHeader;
	listeHeader << "Name" << "Chromosome" << "Position" << "Zscore" << "-log10(p-value)" << "p-value";
	model->setHorizontalHeaderLabels(listeHeader);
	/*
	model->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QString("Chromosome")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QString("Position")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QString("Zscore")));
	model->setHorizontalHeaderItem(4, new QStandardItem(QString("-log10(p-value)")));
	model->setHorizontalHeaderItem(5, new QStandardItem(QString("p-value")));
	*/
 
	setModel(model);
	/*
        this->setColumnCount(6);
        this->verticalHeader()->setVisible(false);

        QTableWidgetItem *col0 = new QTableWidgetItem(tr("Name"));
        QTableWidgetItem *col1 = new QTableWidgetItem(tr("Chromosome"));
        QTableWidgetItem *col2 = new QTableWidgetItem(tr("Position"));
        QTableWidgetItem *col3 = new QTableWidgetItem(tr("Zscore"));
        QTableWidgetItem *col4 = new QTableWidgetItem(tr("-log10(p-value)"));
        QTableWidgetItem *col5 = new QTableWidgetItem(tr("p-value"));

        this->setHorizontalHeaderItem(0,col0);
        this->setHorizontalHeaderItem(1,col1);
        this->setHorizontalHeaderItem(2,col2);
        this->setHorizontalHeaderItem(3,col3);
        this->setHorizontalHeaderItem(4,col4);
        this->setHorizontalHeaderItem(5,col5);
	*/

        for (int i=0;i<6;i++)
                ord[i] = 0;


        QHeaderView *hv = this->horizontalHeader();
        connect(hv,SIGNAL(sectionClicked(int)),this,SLOT(headerPressed(int)));
}

void ZscoreTable::headerPressed(int col)
{
	/*
	int order = this->horizontalHeader()->sortIndicatorOrder();
	this->sortItems(col,Qt::SortOrder(order));
	order = orderChanged(order);
	this->horizontalHeader()->setSortIndicator(col,Qt::SortOrder(order));
        int order = ord[col];//this->horizontalHeader()->sortIndicatorOrder();
        this->sortItems(col,Qt::SortOrder(order));
        order = orderChanged(order);
        ord[col] = order;
	*/

}

int ZscoreTable::orderChanged(int prevOrder = 1)
{
		if (prevOrder == 0) 
		{
			return 1;
		}
		return 0;
}

	/*
QSize ZscoreTable::minimumSizeHint() 
{
	int width = 0;
	QSize size ();
	
	for (int c = 0; c < columnCount(); ++c)
	{
		width += columnWidth(c);
	}
	
	size.setWidth(width);
	return size;

}
QSize ZscoreTable::sizeHint()
{
	return minimumSizeHint();
}
*/
