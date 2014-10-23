/**
 * @file random_projection.h
 *
 * @brief functions for random projection
 */

#ifndef RANDOM_PROJECTION_H
#define RANDOM_PROJECTION_H

/**
 * create a random projection matrix from N(0,1) 
 * 
 * @param X	rp matrix (of size MxMp)
 * @param M     the number of lines
 * @param Mp    the number of columns
 */
void create_rp(double *X, int M, int Mp);

/**
 * create a sparse random projection matrix -1,0,1 1/6,2/3,1/6 
 * 
 * @param X	rp matrix (of size MxMp)
 * @param M     the number of lines
 * @param Mp    the number of columns
 */
void create_srp(double *X, int M, int Mp);

/**
 * create a very sparse random projection matrix 
 * -1,0,1 1/2sqrt(D),1-1/sqrt(D),1/2sqrt(D) 
 * 
 * @param X	rp matrix (of size MxMp)
 * @param M     the number of lines
 * @param Mp    the number of columns
 */
void create_vsrp(double *X, int M, int Mp);

/**
 * project X on Xp through P, Xp = X P
 *
 * @param X	matrix to project (of size NxM)
 * @param P	projection matrix (of size MxMp)
 * @param Xp	projected matrix (of size NxMp)
 * @param N	number of lines
 * @param M	number of columns of X
 * @param Mp	number of columns of Xp
 */
void project(double *X, double *P, double *Xp, int N, int M, int Mp);

#endif // RANDOM_PROJECTION_H
