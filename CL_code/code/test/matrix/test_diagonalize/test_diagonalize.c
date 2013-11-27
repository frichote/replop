// by E. Frichot

// file: diagonalize

// functions:
// 	diagonalize

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/matrix/diagonalize.h"
#include "../../../src/io/io_data_double.h"

int main (int argc, char *argv[])
{
	// parameters
        char input_file[512];
        char output_file1[512];
        char output_file2[512];
	int N;
	int K;
	double *data, *val, *vect;

	// command line args configuration
        strcpy(input_file, argv[1]);
        N = (int) atoi (argv[2]);
        K = (int) atoi (argv[3]);
        strcpy(output_file1, argv[4]);
        strcpy(output_file2, argv[5]);

	// allocate memory
	data = (double *) malloc(N * N * sizeof(double));
	val = (double *) malloc(K * sizeof(double));
	vect = (double *) malloc(N * K * sizeof(double));

	read_data_double(input_file, N, N, data);

	// test diagonalize
	diagonalize(data, N, K, val, vect);

	write_data_double(output_file1, K, 1, val);
	write_data_double(output_file2, N, K, vect);

	return 0;
}
