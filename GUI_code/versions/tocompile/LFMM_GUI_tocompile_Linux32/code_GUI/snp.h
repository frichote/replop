#ifndef SNP_H
#define SNP_H

#include <QString>
#include <QDateTime>

class Snp
{
public:
	QString name;
	QString position;
	QString chromosome;
	QString zscore;
	QString pvalue;
	QString lpvalue;
		
	bool nOK;
	bool pOK;
	bool cOK;
	bool zOK;
	bool pvOK;
	bool lpvOK;

	bool OK;
	
};

#endif // SNP_H
