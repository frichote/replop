/**
 * @file thread_V.h
 *
 * @brief multithreaded part of the functions to compute 
 *	  new values for V from the conditional distribution 
 *        (possibly multithreaded) 
 */

#ifndef THREAD_V_H
#define THREAD_V_H

/**
 * compute a slice of conditional mean for V
 *
 * @param G     a specific structure for multi-threading
 */
void slice_mV_V(void *G);

/**
 * compute a slice of new values for V
 *
 * @param G     a specific structure for multi-threading
 */
void slice_rand_V(void *G);

/**
 * compute a slice of conditional covariance for V
 *
 * @param G     a specific structure for multi-threading
 */
void slice_inv_cov_V(void *G);

#endif // THREAD_LIKE_H
