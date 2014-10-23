/**
 * @file als_F.h
 *
 * @brief set of functions to compute F matrix from als algorithm
 */


#ifndef ALS_F_H
#define ALS_F_H

#include "../nnlsm/blockpivot.h"

/** 
 * @brief Update F
 *
 * @param F 	ancestral frequencies (of size KxM)
 * @param Q 	admixture coefficients (of size NxK)
 * @param X 	genome matrice (of size NxM)
 * @param N 	number of individuals
 * @param M 	number of loci
 * @param K 	number of clusters
 * @param num_thrd 	number of threads used
 * @param mem	previously allocated memory
 */
void update_F(double *F, double *Q, double *X, int N, int M, 
	int K, int num_thrd, Memory mem);

/** 
 * @brief Update F with nnlsm method
 *
 * @param F 	ancestral frequencies (of size KxM)
 * @param Q 	admixture coefficients (of size NxK)
 * @param X 	genome matrice (of size NxM)
 * @param N 	number of individuals
 * @param M 	number of loci
 * @param K 	number of clusters
 * @param num_thrd 	number of threads used
 * @param mem	previously allocated memory
 */
double update_nnlsm_F(double *F, double *Q, double *X, int N, int M, 
	int K, int num_thrd, Memory mem);

/** @brief normalize F 
 * 
 * @param F 	ancestral frequencies (of size KxM)
 * @param M 	number of loci
 * @param nc	number of different values in X
 * @param K	number of clusters
 */
void normalize_F(double *F, int M, int nc, int K);

#endif // ALS_F_H
