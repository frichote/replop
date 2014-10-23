/*
    LFMM GUI, file: datawindow.cpp
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
#include "datawindow.h"
#include "title.h"


// not interesting ... 

DataWindow::DataWindow(QWidget *parent, int EC, int ER)
    : QTableWidget(parent)
{
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowIcon(QIcon(":/images/filedata.png"));
	extraCol=EC;
	extraRow=ER;
}

DataWindow::~DataWindow()
{
}

bool DataWindow::loadFile(const QString &fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) 
	{
		QMessageBox::warning(this, GUI_TITLE,
			tr("Cannot load data file %1!").arg(fileName));
		return false;
	}

	QTextStream in(&file);
	QString oneRow;
	QRegExp reWC("\\w");  // Word Character
	QRegExp regExp("\\s+|\\t+");  // Space(s) or Tab(s)
	QStringList oneRowList;
	QList<QStringList> data;
	int numOfRow = 0;
	int numOfCol = 0;
	QApplication::setOverrideCursor(Qt::WaitCursor);
	while (!(oneRow = in.readLine()).isNull())
	{
		if (oneRow.contains(reWC))
		{
			oneRowList = oneRow.split(regExp, QString::SkipEmptyParts);
			numOfRow++;
			if (oneRowList.size() > numOfCol)
			{
				numOfCol = oneRowList.size();
			}
			data.push_back(oneRowList);
		}
	}
	hide();
	setRowCount(numOfRow);
	setColumnCount(numOfCol);
	
	for (int i = 0; i < numOfRow; i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			QTableWidgetItem *newItem = new QTableWidgetItem(data[i][j]);
			newItem->setFlags(newItem->flags() & ~Qt::ItemIsEditable);
			newItem->setTextAlignment(Qt::AlignCenter);
			
			if (i < extraRow || j < extraCol)
			{
				newItem->setBackground(QBrush(Qt::lightGray));
			}
			
			setItem(i, j, newItem);
		}
	}
	show();
	QApplication::restoreOverrideCursor();

	setWindowTitle(fileName);
	setCurrentFile(fileName);

	return true;
}

void DataWindow::setCurrentFile(const QString &fileName)
{
	file = QFileInfo(fileName).canonicalFilePath();
}

