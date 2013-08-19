#ifndef ZSCORETABLE_H
#define ZSCORETABLE_H

// #include <QDialog>
#include <QTableWidget>
#include <QtGui>

class QSize;
class QTableWidgetItem;

class ZscoreTable : public QTableView
{
	Q_OBJECT
	public:
		ZscoreTable(QWidget *parent = 0);
		~ZscoreTable();
		
	/*
		QSize minimumSizeHint();
		QSize sizeHint();
	*/
		
		void setHeader();
		QStandardItemModel *model;
		
	protected:
		void accept();
		int orderChanged(int prevOrder);
		int ord[6];
		
	private slots:
		void headerPressed(int col);
};

#endif
