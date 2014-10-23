#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QTreeWidget>

class TreeWidget : public QTreeWidget
{
    Q_OBJECT

public:
    TreeWidget(QWidget *parent = 0);
    ~TreeWidget();

signals:
	void runItemDeleted(QString item);

protected:
	void keyPressEvent(QKeyEvent *event);
};

#endif // TREEWIDGET_H
