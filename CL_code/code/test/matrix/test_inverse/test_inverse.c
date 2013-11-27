// by E. Frichot

// file: inverse

// functions:
// 	fast_inverse
// 	detrm
// 	trans

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/matrix/inverse.h"
#include "../../../src/matrix/data.h"
#include "../../../src/io/io_data_double.h"

int main (int argc, char *argv[])
{
	// parameters
        char input_file[512];
        char output_file1[512];
        char output_file2[512];
        char output_file3[512];
        int N;
        double *data;
        double *inv;
        double *inv2;
	double det;

	// command line args configuration
        strcpy(input_file, argv[1]);
        N = (int) atoi (argv[2]);
        strcpy(output_file1, argv[3]);
        strcpy(output_file2, argv[4]);
        strcpy(output_file3, argv[5]);

	// memory allocation
	data = (double *) malloc(N * N * sizeof(double));
	inv = (double *) malloc(N * N * sizeof(double));
	inv2 = (double *) malloc(N * N * sizeof(double));

	// test fast_inverse
	read_data_double(input_file, N, N, data);
	fast_inverse(data, N, inv);
	write_data_double(output_file1, N, N, inv);

	// test detrm
	det = detrm(data, N);	
	write_data_double(output_file2, 1, 1, &det);
	
	// test cofact
	// cofact(data, N, inv2);
	// write_data_double(output_file3, N, N, inv2);

	// free memory
	free(data);
	free(inv);
	free(inv2);

	return 0;
}
