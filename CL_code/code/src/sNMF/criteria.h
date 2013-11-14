/**
 * @file criteria.h
 *
 * @brief set of functions to compute least square criterion for sNMF
 */


#ifndef CRITERIA_H
#define CRITERIA_H

#include "../bituint/bituint.h"

/** 
 * calculate least square criteria with regularization
 *
 * @param X	data matrix
 * @param Q	Q matrix (of size NxK)
 * @param F	F matrix (of size M*ncxK)
 * @param N	number of individuals
 * @param M	number of SNPs
 * @param nc	number of alleles
 * @param Mp	number of columns of X
 * @param K	number of ancestral populations
 * @param alpha regularization parameter
 */
double least_square(bituint *X, double *Q, double *F, int N, int M, int nc, 
	int Mp, int K, double alpha); 

#endif // CRITERIA_H
