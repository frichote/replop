// by E. Frichot

// file: io_tools

// functions:
// 	remove_ext
// 	nb_lines
// 	nb_cols_geno
// 	nb_cols_lfmm
// 	fopen_read
// 	fopen_write

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/io/io_tools.h"

int main (int argc, char *argv[])
{
	// parameters
	char input1[512];
	char input2[512];
	int M, N, test_N, test_M;
	char *tmp_file1, *tmp_file2;
	FILE* file1;

	// command line args configuration
	strcpy(input1, argv[1]);
	strcpy(input2, argv[2]);
	N = (int) atoi (argv[3]);
	M = (int) atoi (argv[4]);

	// test remove_ext
	tmp_file1 = remove_ext(input1, '.', '/');
	printf("%s\n",tmp_file1);

	tmp_file2 = remove_ext(input2, '.', '/');
	printf("%s\n",tmp_file2);

	// test fopen_read
	if (strcmp(input1,"NULL")) {
		file1 = fopen_read(input1);
		fclose(file1);

		// test nb_cols_geno
		test_N = nb_cols_geno(input1);
		if (N != test_N)        {
			printf("Test cols_geno ERROR: incorrect N detected, %d instead of %d!\n", test_N, N);
			return 1;
		}

		test_M = nb_lines(input1, N);
		if (M != test_M) {
			printf("Test lines eERROR: incorrect M detected, %d instead of %d!\n", test_M, M);
			return 1;

		}
	}

	test_M = nb_cols_lfmm(input2);
	if (M != test_M)        {
		printf("Test cols_lfmm ERROR: incorrect M detected, %d instead of %d!\n", test_M, M);
		return 1;
	}

	test_N = nb_lines(input2, M);
	if (N != test_N) {
		printf("Test lines EeRROR: incorrect N detected, %d instead of %d!\n", test_N, N);
		return 1;

	}

	free(tmp_file1);
	free(tmp_file2);
	return 0;
}
