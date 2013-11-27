// by E. Frichot

// file: normalize

// functions:
// 	normalize_cov
// 	normalize_lines

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/matrix/normalize.h"
#include "../../../src/io/io_data_double.h"

int main (int argc, char *argv[])
{
        // parameters
        char input_file[512];
        char output_file1[512];
        char output_file2[512];
        char output_file3[512];
        char output_file4[512];
        int N, M;
        double *data;

        // command line args configuration
        strcpy(input_file, argv[1]);
        N = (int) atoi (argv[2]);
        M = (int) atoi (argv[3]);
        strcpy(output_file1, argv[4]);
        strcpy(output_file2, argv[5]);
        strcpy(output_file3, argv[6]);
        strcpy(output_file4, argv[7]);

	data = (double *) malloc(N * M * sizeof(double));
	read_data_double(input_file, N, M, data);

	// test normalize_cov
	normalize_cov(data, N, M);
	write_data_double(output_file1, N, M, data);

	// test normalize_cov_I
	normalize_cov_I(data, N, M);
	write_data_double(output_file3, N, M, data);

	// test normalize_lines
	normalize_lines(data, N, M);
	write_data_double(output_file2, N, M, data);

	// test normalize_mean_I
	normalize_mean_I(data, N, M);
	write_data_double(output_file4, N, M, data);

	// free memory
	free(data);

	return 0;
}
