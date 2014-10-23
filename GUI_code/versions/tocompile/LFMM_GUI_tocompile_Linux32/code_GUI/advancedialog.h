#ifndef ADVANCEDIALOG_H
#define ADVANCEDIALOG_H

#include <QDialog>



class QLabel;
class QLineEdit;
class QRadioButton;
class QGroupBox;
class QCheckBox;

class AdvancedOption : public QDialog
{
    Q_OBJECT

public:
     AdvancedOption(QWidget *parent = 0);
    ~AdvancedOption();
    void setState(QString,bool,QString,bool,QString,bool,bool,bool,QString);

    bool admixture;
    bool isBYM;
    bool hasGeo;
    
    QLabel *pLabel;
    QLineEdit *pLineEdit;
    QLabel *pUpdateLabel;
    QCheckBox *pUpdateCheckBox;
    QLabel *sigmaLabel;
    QLineEdit *sigmaLineEdit;
    QLabel *updateLabel;
    QCheckBox *updateCheckBox;
    
    QLabel *dLabel;
    QLineEdit *dLineEdit;
    
    QRadioButton *mRadioButton;
    QRadioButton *dRadioButton;
    QRadioButton *xRadioButton;
    QRadioButton *uRadioButton;
    
    QLineEdit *uLineEdit;
    
    QGroupBox *geoGroupBox;

protected:
 	void accept();
    
private slots:
    	void uRadioToggled(bool checked);
    

private:
 	bool validate();
        
};

#endif //ADVANCEDIALOG_H
