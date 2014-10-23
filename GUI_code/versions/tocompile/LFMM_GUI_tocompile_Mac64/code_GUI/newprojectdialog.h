#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>
#include <QList>
#include <QProcess>

class QCheckBox;
class QLineEdit;
class QPushButton;

class NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    NewProjectDialog(QWidget *parent = 0);
    ~NewProjectDialog();

public:
	QLineEdit *nameLineEdit;
	QLineEdit *pathLineEdit;
	QLineEdit *dataLineEdit;
	QLineEdit *geoDataLineEdit;
	QLineEdit *nameDataLineEdit;
	QDialog *geoDataDialog;
	QDialog *dataDialog;
	QDialog *nameDataDialog;

	QLineEdit *nLineEdit;
	//QLineEdit *dLineEdit;
	//QLineEdit *aLineEdit;
	QLineEdit *lLineEdit;
	QLineEdit *dLineEdit;
	QLineEdit *mLineEdit;
	//QCheckBox *specialCheckBox;
	//QCheckBox *recessiveCheckBox;
	
	//QLineEdit *rLineEdit;
	//QLineEdit *cLineEdit;

public slots:
	void help();

protected:
	void accept();

private slots:
	void browsePath();
	void browseData();
	void browseGeoData();
	void browseNameData();
	void dataChanged();
	void geoDataChanged();
	void nameDataChanged();
	void viewData();
	void viewGeoData();
	void viewNameData();
	void dataClose();	
	void geoDataClose();	
	void nameDataClose();	

private:
	bool validate();
	const QList< int > &dataFormat(const QString &data);

	QPushButton *viewDataPushButton;
	QPushButton *viewGeoDataPushButton;
	QPushButton *viewNameDataPushButton;
	QString projectPath;
	/*
	void changeProjectDataFormat();
	void eigenstratgeno2lfmm(const QString inFile, 
		const QString outFile, const int n, const int L );
	*/

};

#endif // NEWPROJECTDIALOG_H
