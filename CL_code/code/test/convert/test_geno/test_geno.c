// by E. Frichot

// file: geno

// functions:
// 	fill_line_geno
// 	write_geno
// 	read_geno

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/convert/geno.h"

int main (int argc, char *argv[])
{
	// parameters
        char input_file[512];
        char output_file1[512];
        int N, M;
        int test_N, test_M;
        int *data;

	// command line args configuration
        strcpy(input_file, argv[1]);
        N = (int) atoi (argv[2]);
        M = (int) atoi (argv[3]);
        strcpy(output_file1, argv[4]);

	data = (int *)malloc(N * M * sizeof(int));

	// test read_geno
	// test fill_line_geno
	read_geno(input_file, data, N, M);

	// test write_geno
	write_geno(output_file1, N, M, data);

	// free memory
	free(data);

	return 0;
}
