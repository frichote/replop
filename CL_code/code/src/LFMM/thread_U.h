/**
 * @file thread_U.h
 *
 * @brief multithreaded part of the functions to compute 
 *	  new values for U from the conditional distribution 
 *	  (possibly multithreaded) 
 */

#ifndef THREAD_U_H
#define THREAD_U_H

/**
 * compute a slice of conditional mean for U
 *
 * @param G     a specific structure for multi-threading
 */
void slice_mU_U(void *G);

/**
 * compute a slice of new values for U
 *
 * @param G     a specific structure for multi-threading
 */
void slice_rand_U(void *G);

/**
 * compute a slice of conditional covariance for U
 *
 * @param G     a specific structure for multi-threading
 */
void slice_inv_cov_U(void *G);

#endif // THREAD_U_H
