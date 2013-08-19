/**
 * @file als_Q.h
 *
 * @brief set of functions to compute update Q in als algorithm
 */


#ifndef ALS_Q_H
#define ALS_Q_H

#include "../bituint/bituint.h"
#include "../nnlsm/blockpivot.h"

/** @brief Update Q
 *
 * @param Q 	admixture coefficients (of size NxK)
 * @param F 	ancestral frequencies (of size KxM)
 * @param X 	genome matrice (of size NxM)
 * @param N 	number of individuals
 * @param M 	number of loci
 * @param nc	number of different values in X
 * @param Mp 	number of columns of X
 * @param K	number of clusters
 * @param alpha parameter of the algorithm
 */
void update_Q(double *Q, double *F, bituint *X, int N, int M, int nc, int Mp, 
			int K, double alpha, Memory mem);

/** @brief Update Q with non-negative least square method 
 *
 * @param Q 	admixture coefficients (of size NxK)
 * @param F 	ancestral frequencies (of size KxM)
 * @param X 	genome matrice (of size NxM)
 * @param N 	number of individuals
 * @param M 	number of loci
 * @param nc	number of different values in X
 * @param Mp 	number of columns of X
 * @param K	number of clusters
 * @param alpha parameter of the algorithm
 */
double update_nnlsm_Q(double *Q, double *F, bituint *X, int N, int M, int nc,
	int Mp,	int K, double alpha, Memory mem, int num_thrd);

/** @brief normalize Q
 * 
 * @param Q 	ancestral frequencies (of size NxK)
 * @param N 	number of individuals
 * @param K	number of clusters
 */
void normalize_Q(double *Q, int N, int K);

/** @brief mean relative difference between Q_prec and Q
 *
 * @param Q_prec	matrix of size n
 * @param Q	matrix of size n
 * @param n	size of Q
 */
double diff_rel(double *Q_prec, double *Q, int n);

#endif // ALS_Q_H
