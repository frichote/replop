/**
 * @file criteria.h
 *
 * @brief set of functions to compute SNMF with als algorithm
 */


#ifndef CRITERIA_H
#define CRITERIA_H

#include "../bituint/bituint.h"

double least_square(bituint *X, double *Q, double *F, int N, int M, int nc, 
	int Mp, int K, double alpha); 

#endif // CRITERIA_H
