/**
 * @file calc_cov.h
 *
 * @brief function to calculate covariance matrix
 */


#ifndef CALC_COV_H
#define CALC_COV_H

/**
 * calculate the covariance matrix  
 *
 * @param data		data matrix (of size NxM)
 * @param N		number of individuals
 * @param M		number of loci
 * @param cov		output covariance matrix
 */
void calc_cov(double *data, int N, int M, double *cov);

#endif // CALC_COV_H
