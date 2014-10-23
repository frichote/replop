/**
 * @file als_Q.h
 *
 * @brief set of functions to compute update Q in als algorithm
 */


#ifndef ALS_Q_H
#define ALS_Q_H

#include "../nnlsm/blockpivot.h"

/** @brief Update Q
 *
 * @param Q 	admixture coefficients (of size NxK)
 * @param F 	ancestral frequencies (of size KxM)
 * @param X 	genome matrice (of size NxM)
 * @param N 	number of individuals
 * @param M 	number of loci
 * @param K	number of clusters
 * @param alpha parameter of the algorithm
 * @param mem 	allocated memory
 */
void update_Q(double *Q, double *F, double *X, int N, int M, 
			int K, double alpha, Memory mem);

/** @brief Update Q with non-negative least square method 
 *
 * @param Q 	admixture coefficients (of size NxK)
 * @param F 	ancestral frequencies (of size KxM)
 * @param X 	genome matrice (of size NxMc)
 * @param N 	number of individuals
 * @param M 	number of loci
 * @param K	number of clusters
 * @param alpha parameter of the algorithm
 * @param mem 	allocated memory
 * @param num_thrd number of CPU used
 */
double update_nnlsm_Q(double *Q, double *F, double *X, int N, int M,
	int K, double alpha, Memory mem, int num_thrd);

/** @brief normalize Q
 * 
 * @param Q 	ancestral frequencies (of size NxK)
 * @param N 	number of individuals
 * @param K	number of clusters
 */
void normalize_Q(double *Q, int N, int K);

/** 
 * compute t(F) * F + alpha
 *
 * @param temp1 output matrix (of size KxK)
 * @param F	input F matrix (of size McxK)
 * @param K	number of clusters
 * @param M 	number of loci
 * @param N 	number of individuals
 * @param num_thrd	number of CPU used 
 * @param alpha regularization parameter of the algorithm
 */
void F_tF_alpha(double *temp1, double *F, int K, int M, int N,
        int num_thrd, double alpha);

/** 
 * compute t(F) * t(X)
 *
 * @param temp3 output matrix (of size KxN)
 * @param X 	genotype matrice (of size NxMc)
 * @param F	input F matrix (of size McxK)
 * @param K	number of clusters
 * @param M 	number of loci
 * @param N 	number of individuals
 * @param num_thrd	number of CPU used 
 */
void tF_tX(double *temp3, double *X, double *F, int K, int M,
        int N, int num_thrd);


#endif // ALS_Q_H
