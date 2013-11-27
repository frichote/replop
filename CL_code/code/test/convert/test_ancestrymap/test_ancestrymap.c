// by E. Frichot

// file: ancestrymap.c

// functions: 	ancestrymap2geno
//		ancestrymap2lfmm
//		read_ancestrymap
//		nb_ind_ancestrymap
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/convert/ancestrymap.h"

int main (int argc, char *argv[])
{

	char input_file[512];
	char output_file1[512];
	char output_file2[512];
	char output_file3[512];
	int N, M;
	int test_N, test_M;
	int test_n, test_m;
	int *data;

	// command line arguments configuration
	strcpy(input_file, argv[1]);
	N = (int) atoi (argv[2]);
	M = (int) atoi (argv[3]);
	strcpy(output_file1, argv[4]);
	strcpy(output_file2, argv[5]);
	strcpy(output_file3, argv[6]);

	// test read_ancestrymap
	data = (int *) malloc (N * M * sizeof(int));
	read_ancestrymap(input_file, N, M, data);	
	write_data_int(output_file1, N, M, data);
	
	// test nb_ind_ancestrymap
	test_N = nb_ind_ancestrymap(input_file);
	if (test_N != N) {
                printf("Test ERROR: incorrect N detected, %d instead of %d!\n", test_N, N);
		return 1;
	}

	// test ancestrymap2geno
	ancestrymap2geno(input_file, output_file2, &test_N, &test_M);
	if (N != test_N || M != test_M) {
                printf("Test ERROR: incorrect N or M detected, %d (%d) instead of %d (%d) !\n", 
		test_N, test_M, N, M);
		return 1;
	}

	// test ancestrymap2lfmm
	ancestrymap2lfmm(input_file, output_file3, &test_n, &test_m);
	if (N != test_n || M != test_m) {
                printf("Test ERROR: incorrect N or M detected, %d (%d) instead of %d (%d) !\n", 
		test_n, test_m, N, M);
		return 1;
	}

	free(data);

	return 0;
}
