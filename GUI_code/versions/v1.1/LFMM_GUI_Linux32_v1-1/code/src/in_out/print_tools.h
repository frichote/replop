/**
 * @file print_tools.h
 *
 * @brief set of global printing functions
 */

#ifndef PRINT_TOOLS_H
#define PRINT_TOOLS_H

/**
 * initialize progress bar
 *
 * @param i	progress integer	
 * @param j	progress integer
 */
void init_bar(int *i, int *j);

/**
 * print progress bar
 *
 * @param i	progress integer	
 * @param j	progress integer
 * @param Niter	total number of iterations of the algorithm 
 */
void print_bar(int *i, int *j, int Niter);

#endif // PRINT_TOOLSH
