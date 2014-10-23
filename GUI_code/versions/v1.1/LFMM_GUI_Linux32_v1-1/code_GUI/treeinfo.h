#ifndef TREEINFO_H
#define TREEINFO_H

// #include <QDialog>
#include <QTableWidget>
#include "treewidget.h"

class QSize;

class TreeInfo : public TreeWidget
{
	Q_OBJECT
	public:
		TreeInfo(QWidget *parent = 0);
		~TreeInfo();
		
	protected:
		
	private:
		void overviewInfo();
		QTreeWidgetItem *overviewItem;
};

#endif
