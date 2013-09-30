/**
 * @file vcf2geno.h
 *
 * @brief functions to convert a file from vcf to lfmm format.
 */

#ifndef VCF2GENO_H
#define VCF2GENO_H

#include <stdint.h>

void vcf2geno (char *input_file, char* output_file, int *N, int *M, char* snp_bp_file, 
	char* removed_bp_file);

#endif // VCF2GENO_H
