/**
 * @file geno2lfmm.h
 *
 * @brief functions to convert a file from geno to lfmm format.
 */

#ifndef GENO2LFMM_H
#define GENO2LFMM_H

#include <stdint.h>

/**
 * convert a file from geno to lfmm format and count the number of lines (M)
 * and the number of columns (N) (in geno format)
 *
 * @param input_file   input file name
 * @param output_file   output file name
 * @param N     	the number of columns (in geno format)
 * @param M     	the number of lines (in geno format)
 */
void geno2lfmm (char *input_file, char* output_file, int *N, int *M);

#endif // GENO2LFMM_H
