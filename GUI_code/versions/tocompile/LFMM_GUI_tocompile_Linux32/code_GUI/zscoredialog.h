#ifndef ZSCOREDIALOG_H
#define ZSCOREDIALOG_H

#include <QDialog>
#include <QtGui>

#include "zscoretable.h"
#include "project.h"
#include "snp.h"

class ZscoreTable;
class QCloseEvent;
class QComboBox;
class QPushButton;
class QCheckBox;
class QLineEdit;
class QLabel;
class QListWidget;
class QGroupBox;

class ZscoreDialog : public QDialog

{
	Q_OBJECT

public:
	ZscoreDialog(QWidget *parent = 0);
	~ZscoreDialog();

signals:
	void finished();
	
public:
	ZscoreTable *zscoreTable;
	QPushButton *toTextPushButton;
	QPushButton *toPlotPushButton;
	QPushButton *toGreenPlotPushButton;
	QLineEdit *popfileLineEdit;
	QString commonPath;
	Project *project;
	QLabel *numberLabel;

	QComboBox *runComboBox;
	
	
	void createZscoreTableToPlot();
	void createZscoreTableToPlotGreen();
	void clear();
	bool initZscore();
	void addRunToZscoreTable(bool update);

private slots:
	void loadZscoreItem(QTableWidgetItem *item);
	void updateZscoreTable();
	void updateRunToZscoreTable();

	bool updateZscoreRange();
	bool updatePvalueRange();
	bool updatelPvalueRange();
	bool updatePositionRange();
	bool updateChrRange();
	bool updateNameRange();	
	void exportZscoreTableToText();
	void help();

private:
	QCheckBox *nameSearchCheckBox;
	QLineEdit * nameSearchLineEdit;

	QCheckBox *zscoreCheckBox;
	QLineEdit * minZscoreLineEdit;
	QLineEdit * maxZscoreLineEdit;

	QCheckBox *pvalueCheckBox;
	QLineEdit * minPvalueLineEdit;
	QLineEdit * maxPvalueLineEdit;
	
	QCheckBox *lpvalueCheckBox;
	QLineEdit * minlPvalueLineEdit;
	QLineEdit * maxlPvalueLineEdit;
	
	QCheckBox *positionCheckBox;
	QLineEdit * minPositionLineEdit;
	QLineEdit * maxPositionLineEdit;

	QComboBox *chrComboBox;
	
	int curIndex;
	QList<Snp > snps;

	int curNbSnps;
	void updateOKSnps();

	void keyPressEvent(QKeyEvent *e);

	//void setEnabledZscore(bool enable);
};

#endif
