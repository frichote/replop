/*
    LFMM GUI, file: treewidget.cpp
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
#include "treewidget.h"

TreeWidget::TreeWidget(QWidget *parent)
    : QTreeWidget(parent)
{
}

TreeWidget::~TreeWidget()
{
}

void TreeWidget::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Delete && currentItem()->text(0).contains(tr("_RUN_")))
	{
		QTreeWidgetItem *itemToBeDeleted = currentItem();
		QString item = itemToBeDeleted->text(0);
		QTreeWidgetItem *parent = itemToBeDeleted->parent();  // Item of Project Runs
		delete parent->takeChild(parent->indexOfChild(itemToBeDeleted));
		emit runItemDeleted(item);
	}
	else
	{
		QTreeWidget::keyPressEvent(event);
	}
}
