#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include <QTableWidget>
#include <QtGui>

class DataWindow : public QTableView
{
    Q_OBJECT

public:
    	DataWindow(QWidget *parent = 0, int EC = 0, int ER = 0);
    	~DataWindow();

	QString currentFile()
	{
		return file;
	}

	QStandardItemModel *model;


	bool loadFile(const QString &fileName);

private:
	void setCurrentFile(const QString &fileName);
	QString file;
	int extraCol;
	int extraRow;
};

#endif // DATAWINDOW_H
