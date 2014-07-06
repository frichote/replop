/**
 * @addtogroup als_k1
 * @ingroup sNMF
 * @{
 *
 * @brief set of functions to compute SNMF for k=1
 */


#ifndef ALS_K1_H
#define ALS_K1_H

#include "../bituint/bituint.h"

/** 
 * @brief compute NMF for K=1
 *
 * @param X 	genome matrice (of NxM elements)
 * @param Q	output matrix Q (of size NxK)
 * @param F	output matrix F (of size Kx(nc*M))
 * @param N 	number of individuals
 * @param M 	number of loci
 * @param nc	number of different values in X
 * @param Mp 	number of columns of X
 */
void ALS_k1(bituint *X, double *Q, double *F, int N, int M, int nc, int Mp);

#endif // ALS_K1_H

/** @} */