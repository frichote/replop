#ifndef NEWRUNDIALOG_H
#define NEWRUNDIALOG_H

#include <QDialog>


class QCheckBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QRadioButton;
class QComboBox;


class NewRunDialog : public QDialog
{
    Q_OBJECT

public:
	NewRunDialog(QWidget *parent = 0, int D1 = 0);
    ~NewRunDialog();


    QString scOption;
    bool hasGeoData;
    int nD;
    int D;
    QList<QString> varList;
    
    QPushButton* advanced;
    
    QRadioButton *SvdRadioButton;
    QRadioButton *GSRadioButton;
    QRadioButton *VBRadioButton;
    
    QGroupBox *tGroupBox;
    QGroupBox *mGroupBox;
    QLabel *rLabel;
    QLineEdit *rLineEdit;
    QLabel *kLabel;
    QLineEdit *kLineEdit;
    QLabel *toKLabel;
    QLineEdit *toKLineEdit;
    QLabel *dLabel;
    QLineEdit *dLineEdit;
    QLabel *scriptLabel;
    QCheckBox *scriptCheckBox;

    QLabel *nbThreadLabel;
    QLineEdit *nbThreadLineEdit;
    QString psi;
    bool updatePsi;
    QString sigma;
    bool updateSigma;
    
    QString lambda;
    
    QLabel *sLabel;
    QLineEdit *sLineEdit;
    QLabel *bLabel;
    QLineEdit *bLineEdit;
    QLabel *iLabel;
    QLineEdit *iLineEdit;

    QGroupBox* predGroupBox;
    
    QString path;
    QString znoAdm;
    QString zadmCAR;
    QString zadmBYM;
    QString mlAdmCAR;
    QString mlAdmBYM;
    QString mlnoAdm;

protected:
	void accept();
    

private slots:
	void GSToggled(bool checked);
	void scriptStateChanged(int state);
	void advOpt();
	void help();


private:
	bool validate();
	QString mapPath;
};

#endif // NEWRUNDIALOG_H
