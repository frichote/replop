/**
 * @file als.h
 *
 * @brief set of functions to compute SNMF with als algorithm
 */


#ifndef ALS_H
#define ALS_H

#include "../nnlsm/blockpivot.h"

/** 
 * @brief Algorithm Alternative Least Square
 *
 * @param X 	genome matrice (of NxM elements)
 * @param Q	output matrix Q (of size NxK)
 * @param F	output matrix F (of size Kx(nc*M))
 * @param N 	number of individuals
 * @param M 	number of loci
 * @param K 	number of clusters
 * @param maxiter	maximum number of iterations
 * @param tol 	relative tolerance
 * @param num_thrd 	number of threads used
 * @param alpha 	sparsity parameter
 */
void ALS(double *X, double *Q, double *F, int N, int M, int K,
	int maxiter, double tol, int num_thrd, double alpha);

#endif // ALS_H
