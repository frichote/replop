#ifndef SUMMARYDIALOG_H
#define SUMMARYDIALOG_H

#include <QDialog>

#include "summarytable.h"
#include "project.h"

class SummaryTable;
class QCloseEvent;
class QComboBox;
class QPushButton;
class QCheckBox;
class QLineEdit;
class QLabel;
class QListWidget;
class QGroupBox;

class SummaryDialog : public QDialog
{
	Q_OBJECT

public:
	SummaryDialog(QWidget *parent = 0);
	~SummaryDialog();

signals:
	void finished();
	
public:
	SummaryTable *summaryTable;
	//QComboBox *lowerComboBox;
	//QComboBox *upperComboBox;
	QPushButton *toTextPushButton;
	//QComboBox *percentageComboBox; 
	//QLabel *avgDICTextEdit;
	//QLineEdit *popfileLineEdit;
	QString commonPath;
	Project *project;
	
	void clear();
	bool initSummary();
	void removeRunFromSummaryTable(int runLabel, int Kremoved);
	void addRunToSummaryTable();

protected:
	void closeEvent(QCloseEvent *event);
	void keyPressEvent(QKeyEvent *event);

private slots:
	void closeClicked();
	bool summaryRangeUpdated();
	void loadSummaryItem(QTableWidgetItem *item);
	//void filterCandidateRuns(int percentageIndex);
	void exportTableToText();
	void updateSummaryTable();
	
private:
  	int summaryLowerRange;
        int summaryUpperRange;
	
	

};

#endif
