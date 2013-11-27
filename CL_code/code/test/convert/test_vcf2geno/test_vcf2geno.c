// by E. Frichot

// file: vcf2geno

// functions:
// 	vcf2geno

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/convert/vcf2geno.h"

int main (int argc, char *argv[])
{
	// parameters
	char input[512];
	char output[512];
	int N, M, removed;
	int test_N, test_M, test_removed;
	char snp_file[512];
	char removed_file[512];

	// command line args configuration
        strcpy(input, argv[1]);
        N = (int) atoi (argv[2]);
        M = (int) atoi (argv[3]);
        removed = (int) atoi (argv[4]);
        strcpy(output, argv[5]);
        strcpy(snp_file, argv[6]);
        strcpy(removed_file, argv[7]);

	// test vcf2geno
	vcf2geno(input, output, &test_N, &test_M, snp_file, 
		removed_file, &test_removed);	

	if (test_N != N) {
		printf("Test Error: N false %d instead of %d!\n",test_N, N);
		exit(1);
	} 

	if (test_M != M) {
		printf("Test Error: M false %d instead of %d!\n",test_M, M);
		exit(1);
	} 

	if (test_removed != removed) {
		printf("Test Error: 'removed' false %d instead of %d!\n",test_removed, removed);
		exit(1);
	} 

	return 0;
}
