/**
 * @file thread_beta.h
 *
 * @brief multithreaded part of the functions calculate 
 *	  beta parameters (possibly multithreaded) 
 */

#ifndef THREAD_BETA_H
#define THREAD_BETA_H

/**
 * compute a slice of conditional mean for beta
 *
 * @param G	a specific structure for multi-threading
 */
void slice_mbeta_beta(void *G);

/**
 * compute a slice of new values for beta
 *
 * @param G	a specific structure for multi-threading for lfmm
 */
void slice_rand_beta(void *G);

#endif // THREAD_BETA_H
