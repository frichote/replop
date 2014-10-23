/**
 * @file generative.h
 *
 * @brief function to generate data from the generative model
 */

#ifndef GENERATIVE_H
#define GENERATIVE_H

/**
 * generate data from the generative LFMM model
 *
 * @param data	the data matrix (of size NxM)
 * @param beta	the beta matrix (of size KxM)
 * @param U	the U matrix (of size DxN)
 * @param V	the V matrix (of size DxM)
 * @param C	the covariable matrix (of size NxK)
 * @param N	the number of individuals
 * @param M	the number of loci
 * @param K	the number of latent factors
 * @param D	the number of covariables
 */
void generate_data(float *data, double *beta, double *U, double *V,
		   double *C, int N, int M, int K, int D);

#endif // GENERATIVE_H
