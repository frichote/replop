// by E. Frichot

// file: matrix

// functions:
// 	dble_sum2
// 	dble_sum
// 	copy_vect
// 	transpose_double
// 	transpose_float
// 	transpose_int

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/matrix/matrix.h"
#include "../../../src/io/io_data_double.h"
#include "../../../src/io/io_data_float.h"
#include "../../../src/io/io_data_int.h"

int main (int argc, char *argv[])
{
	// parameters
        char input_file[512];
        char output_file1[512];
        char output_file2[512];
        char output_file3[512];
        char output_file4[512];
        char output_file5[512];
        char output_file6[512];
        int N, M;
        double *data;
        double *cpy;
        float *fata;
        int *iata;
	double *res2;
	double res;

	// command line args configuration
        strcpy(input_file, argv[1]);
        N = (int) atoi (argv[2]);
        M = (int) atoi (argv[3]);
        strcpy(output_file1, argv[4]);
        strcpy(output_file2, argv[5]);
        strcpy(output_file3, argv[6]);
        strcpy(output_file4, argv[7]);
        strcpy(output_file5, argv[8]);
        strcpy(output_file6, argv[9]);

	// memory allocation
        data = (double *) malloc (N * M * sizeof(double));
        res2 = (double *) malloc (N * sizeof(double));
        cpy = (double *) malloc (N * M * sizeof(double));
        fata = (float *) malloc (N * M * sizeof(float));
        iata = (int *) malloc (N * M * sizeof(int));

	read_data_double(input_file, N, M, data);
	read_data_float(input_file, N, M, fata);
	read_data_int(input_file, N, M, iata);

	// test dble_sum2
	dble_sum2(data, N, M, res2, 0.01);	
	write_data_double(output_file1, N, 1, res2);	

	// test dble_sum
	res = dble_sum(data, N * M);
	write_data_double(output_file2, 1, 1, &res);

	// test copy_vect
	copy_vect(data, cpy, N * M);
	write_data_double(output_file3, N, M, cpy);

	// test transpose_double
	transpose_double(data, M, N);
	write_data_double(output_file4, M, N, data);

	// test transpose_float
	transpose_float(fata, M, N);
	write_data_float(output_file5, M, N, fata);

	// test transpose_int
	transpose_int(iata, M, N);
	write_data_int(output_file6, M, N, iata);

	// free memory
	free (data);
	free (fata);
	free (iata);
	free(cpy);
	free(res2);

	return 0;
}
