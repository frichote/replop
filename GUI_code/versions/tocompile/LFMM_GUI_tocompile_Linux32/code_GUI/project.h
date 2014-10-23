#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QList>
#include "run.h"
#include <QDateTime>

class Project
{
public:
	// Project Information
	QString date;
	QString name;
	QString path;
	QString data;
	QString data_prev;
	QString geoData;
	QString nameData;

	/*
	QString v;	// Voronoi Diagram
	QString n;	// Neighborhood Diagram
	QString c;	// Voronoi & Neighborhood Configuration
	QString znoAdm;	// Allele Frequency & Membership Configuration (no adm)
	QString zadmCAR;	// Allele Frequency & Membership Configuration (adm CAR)
	QString zadmBYM;	// Allele Frequency & Membership Configuration (adm BYM)
        QString mlAdmCAR;     //Min DIC run informations (admixture case, CAR)
	QString mlAdmBYM;     //Min DIC run informations (admixture case, BYM)
	QString mlnoAdm;     //Min DIC run informations (no admixture case)
	*/	
		
	
	//bool hasGeoData;	//geographic data file included ?
	bool hasNameData;	//geographic data file included ?
	//bool specialFormat;	//data stored in one line per individual?
	//bool isRecessiveAllele; //is there a row containing recessive alleles?
	
	// Data Information
	QString N;  // Number of Individuals
	QString D;  // Number of covariables
	//QString A;  // Ploidy
	QString L;  // Number of Loci
	QString M;  // Missing Data Value
	
	// Data Format
	//QString R;  // Number of Extra Rows
	//QString C;  // Number of Extra Columns

	// Run Information
	int i;		// Next Run Index
	QList< Run > runs;
};

#endif // PROJECT_H
