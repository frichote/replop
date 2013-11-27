// by E. Frichot

// file: cholesky

// functions:
// 	cholesky

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/matrix/cholesky.h"
#include "../../../src/io/io_data_double.h"

int main (int argc, char *argv[])
{
	// parameters
        char input_file[512];
        char output_file1[512];
        int N;
	double *data;
	double *chol;

        // command line args configuration
        strcpy(input_file, argv[1]);
        N = (int) atoi (argv[2]);
        strcpy(output_file1, argv[3]);


	// command line args configuration
	data = (double *) malloc (N * N * sizeof(double));
	chol = (double *) malloc (N * N * sizeof(double));	
	read_data_double(input_file, N, N, data); 
	cholesky(data, N, chol);
	write_data_double(output_file1, N, N, chol); 

	// test cholesky

	free(data);
	free(chol);

	return 0;
}
