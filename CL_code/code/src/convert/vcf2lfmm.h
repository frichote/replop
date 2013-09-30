/**
 * @file vcf2lfmm.h
 *
 * @brief functions to convert a file from vcf to lfmm format.
 */

#ifndef VCF2LFMM_H
#define VCF2LFMM_H

#include <stdint.h>

void vcf2lfmm (char *input_file, char* output_file, int *N, int *M, char* snp_bp_file, 
	char* removed_bp_file);

#endif // VCF2LFMM_H
