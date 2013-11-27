// by E. Frichot

// file: geno2lfmm

// functions:
// 	geno2lfmm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/convert/geno2lfmm.h"

int main (int argc, char *argv[])
{
	// parameters
        char input_file[512];
        char output_file1[512];
        int N, M;
        int test_N, test_M;

	// command line args configuration
        strcpy(input_file, argv[1]);
        N = (int) atoi (argv[2]);
        M = (int) atoi (argv[3]);
        strcpy(output_file1, argv[4]);

	// test geno2lfmm
	geno2lfmm(input_file, output_file1, &test_N, &test_M);
	if (N != test_N) {
		printf("Test ERROR: incorrect N detected, %d instead of %d!\n", test_N, N);
		return 1;

	}
 	if (M != test_M)	{
		printf("Test ERROR: incorrect M detected, %d instead of %d!\n", test_M, M);
		return 1;
	}

	return 0;
}
