/**
 * @file geno2lfmm.h
 *
 * @brief functions to convert a file from geno to lfmm format.
 */

#ifndef GENO2LFMM_H
#define GENO2LFMM_H

#include <stdint.h>

void geno2lfmm (char *input_file, char* output_file, int *N, int *M);

#endif // GENO2LFMM_H
