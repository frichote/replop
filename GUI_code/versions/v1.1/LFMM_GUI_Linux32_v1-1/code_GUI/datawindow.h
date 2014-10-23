#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include <QTableWidget>

class DataWindow : public QTableWidget
{
    Q_OBJECT

public:
    DataWindow(QWidget *parent = 0, int EC = 0, int ER = 0);
    ~DataWindow();

	QString currentFile()
	{
		return file;
	}

	bool loadFile(const QString &fileName);

private:
	void setCurrentFile(const QString &fileName);
	QString file;
	int extraCol;
	int extraRow;
};

#endif // DATAWINDOW_H
