#ifndef RUN_H
#define RUN_H

#include <QString>
#include <QList>
#include <QDateTime>
#include "snp.h"

class Run
{
public:
	QString name;
	QString date;

	//bool q;		 // Perform admixture ?
	//bool fmod;    	 // Perform F-model ?
	//bool updateParameters; //Update spatial and admixture parameters (admixture case)
	//bool updatePsiParameter; //Update psi ? (admixture case)
	bool script;      // Scripted runs? (Multiple runs with multiple Ks) 
	//bool multiThread;      // Scripted runs? (Multiple runs with multiple Ks) 
	//bool hasPrediction;	//has prediction been computed?
	
	QString T;	// Type of Run: with or without adm
	//QString admMod; // Admixture model: CAR or BYM
	QString N;	// Number of Runs
	QString K;	// Current Maximal Number of Clusters
	QString D;
	QString baseK;	// Min. Maximal number of clusters.
	QString toK;    // Maximal Number of Clusters upper range for multiple runs with multiple values of K
	QString nbThread;    // Maximal Number of Clusters upper range for multiple runs with multiple values of K
	QString P;	// TODO // Interaction Parameter of HMRF
	//QString trendDegree; //Degree of trend for admixture
        	 
	//QString D;	// Parameter of Dirichlet Allele Frequency Model (MCMC Only)
        //QString sigma;  //Parameter of admixture model
	//QString scOpt;  // Option for the scale parameter
	QString S;	// Total Number of Sweeps of MCMC (MCMC Only)
	QString B;	// Burn In Number of Sweeps of MCMC (MCMC Only)
	//bool C;		// Continuing Previous Run?
	QString V;
	//bool NJ;	// Init from Neighbor Joining Tree ?
	//QString map;	// Name of file containing map for prediction

	// SNP Information
	int i;		// Next SNP Index
	//QList< Snp > snps;
	//Snp snp;
	
        int nD;          // Next Run Index
        QList< QString > var;

	
	
	// Results
	QString Deviance;
	QString DIC;
	/*
	QString L;	// Average Log-Likelihood
	QString AL;	// Average Log-Likelihood (File Name)
	//QString DIC;	// Decision Information Criterion
	//QString fDIC;	// Decision Information Criterion (File Name)
	QString IM;	// Initial Membership of Individuals
	QString HC;	// Hard Clustering
	QString AP; 	// Soft Clustering (Assignment Probabilities)
	QString Predict;// Map of predictions
	QString BH;	// Beta History
	*/
	//QString TR;	// Textual Results
	//QString LH; 	// Log-Likelihood History
	QString ZS; 	// Log-Likelihood History
	
};

#endif // RUN_H
