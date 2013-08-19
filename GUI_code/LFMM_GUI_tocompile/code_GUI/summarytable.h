#ifndef SUMMARYTABLE_H
#define SUMMARYTABLE_H

// #include <QDialog>
#include <QTableWidget>

class QSize;
class QTableWidgetItem;

class SummaryTable : public QTableWidget
{
	Q_OBJECT
	public:
		SummaryTable(QWidget *parent = 0);
		~SummaryTable();
		
		QSize minimumSizeHint();
		QSize sizeHint();
		
		
	protected:
		void accept();
		int orderChanged(int prevOrder);
		int ord[6];
		
	private slots:
		void headerPressed(int col);
};

#endif
