/*
    LFMM GUI, file: textwindow.cpp
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
#include "textwindow.h"
#include "title.h"

TextWindow::TextWindow(QWidget *parent)
    : QTextEdit(parent)
{
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowIcon(QIcon(":/images/filetext.png"));

	setReadOnly(true);
	QFont courierFont("Courier", 10, QFont::Bold);
	setCurrentFont(courierFont);
	setLineWrapMode(QTextEdit::NoWrap);
}

TextWindow::~TextWindow()
{
}

bool TextWindow::loadFile(const QString &fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text)) 
	{
		QMessageBox::warning(this, GUI_TITLE,
			tr("Cannot load text file %1!").arg(fileName));
		return false;
	}

	QTextStream in(&file);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	setPlainText(in.readAll());
	QApplication::restoreOverrideCursor();

	setWindowTitle(fileName);
	setCurrentFile(fileName);

	return true;
}

void TextWindow::setCurrentFile(const QString &fileName)
{
	file = QFileInfo(fileName).canonicalFilePath();
}
