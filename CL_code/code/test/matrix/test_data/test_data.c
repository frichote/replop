// by E. Frichot

// file: data

// functions:
// 	zeros
// 	check_mat
// 	update_m
// 	create_I

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/matrix/data.h"
#include "../../../src/matrix/rand.h"
#include "../../../src/io/io_data_double.h"
#include "../../../src/io/io_data_float.h"
#include "../../../src/io/io_data_int.h"

int main (int argc, char *argv[])
{
        // parameters
        char input_file[512];
        char input_file2[512];
        char output_file1[512];
        char output_file2[512];
        int N, M, j;
        double *data;
        float *fata;
	int *I, *col;

        // command line args configuration
        strcpy(input_file, argv[1]);
        strcpy(input_file2, argv[2]);
        N = (int) atoi (argv[3]);
        M = (int) atoi (argv[4]);
        strcpy(output_file1, argv[5]);
        strcpy(output_file2, argv[6]);

	// memory allocation
	data = (double *) malloc (N * M * sizeof(double));
	fata = (float *) malloc (N * M * sizeof(float));
	I = (int *) malloc (N * M * sizeof(int));
	col = (int *) malloc (M * sizeof(int));
	
	// test zeros
	zeros(data, N * M);
	print_data_double(data, N, M);

	// test check_mat
	if (check_mat(data, N, rand_int(M), M))
		return 1;

	j = rand_int(M);
	data[(N-1)*M+j] /= 0;
	if (!check_mat(data, N, j, M))
		return 1; 

	// test update_m
	read_data_double(input_file, N, M, data);
	update_m(data, N*M, 2);
	write_data_double(output_file1, N, M, data);

	// test create_I
	read_data_float(input_file2, N, M, fata);
	create_I(fata, I, N, M);
	write_data_int(output_file2, N, M, I);
	
	// free memory
	free(data);
	free(fata);
	free(I);
	free(col);

	return 0;
}
