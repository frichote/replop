/*
    LFMM GUI, file: treeinfo.cpp
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
#include "treeinfo.h"
#include "treewidget.h"

using namespace std;
TreeInfo::TreeInfo(QWidget *parent) : TreeWidget(parent)
{
	setColumnCount(1);
	overviewInfo();
}

TreeInfo::~TreeInfo()
{
}

void TreeInfo::overviewInfo() {

	QString text = tr("Over");
	
	overviewItem = new QTreeWidgetItem(this,
                        QStringList(QString(tr("Overview"))));
	QGridLayout *overviewLayout = new QGridLayout();
	//overviewItem->setItemWidget(overviewLayout);
	QTreeWidgetItem *textItem = new QTreeWidgetItem(overviewItem,
                        QStringList(QString(tr(" Overview text"))));
}
