/*
    LFMM GUI, file: summarytable.cpp
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
#include "summarytable.h"

using namespace std;
SummaryTable::SummaryTable(QWidget *parent) : QTableWidget(parent)
{
	this->setColumnCount(6);
	this->verticalHeader()->setVisible(false);

	QTableWidgetItem *col0 = new QTableWidgetItem(tr("Run Label"));
	QTableWidgetItem *col1 = new QTableWidgetItem(tr("D"));
	QTableWidgetItem *col2 = new QTableWidgetItem(tr("K"));
	QTableWidgetItem *col3 = new QTableWidgetItem(tr("DIC"));
	QTableWidgetItem *col4 = new QTableWidgetItem(tr("Deviance"));
	QTableWidgetItem *col5 = new QTableWidgetItem(tr("Zscore"));
	
	this->setHorizontalHeaderItem(0,col0);
	this->setHorizontalHeaderItem(1,col1);
	this->setHorizontalHeaderItem(2,col2);
	this->setHorizontalHeaderItem(3,col3);
	this->setHorizontalHeaderItem(4,col4);
	this->setHorizontalHeaderItem(5,col5);
	
	for (int i=0;i<6;i++)
		ord[i] = 0;

	QHeaderView *hv = this->horizontalHeader();
	connect(hv,SIGNAL(sectionClicked(int)),this,SLOT(headerPressed(int)));
}

SummaryTable::~SummaryTable()
{
}

void SummaryTable::headerPressed(int col)
{
	/*
	int order = this->horizontalHeader()->sortIndicatorOrder();
	this->sortItems(col,Qt::SortOrder(order));
	order = orderChanged(order);
	this->horizontalHeader()->setSortIndicator(col,Qt::SortOrder(order));
	*/
	int order = ord[col];//this->horizontalHeader()->sortIndicatorOrder();
	this->sortItems(col,Qt::SortOrder(order));
	order = orderChanged(order);
	ord[col] = order;
	//this->horizontalHeader()->setSortIndicator(col,Qt::SortOrder(order));
}

int SummaryTable::orderChanged(int prevOrder)
{
		if (prevOrder == 0) 
		{
			return 1;
		}
		return 0;
}

QSize SummaryTable::minimumSizeHint() 
{
	QSize size (QTableWidget::sizeHint());
	int width = 0;
	
	for (int c = 0; c < columnCount(); ++c)
	{
		width += columnWidth(c);
	}
	
	size.setWidth(width);
	
	return size;
}

QSize SummaryTable::sizeHint()
{
	return minimumSizeHint();
}
