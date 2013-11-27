// by E. Frichot

// file: als_F

// functions:
// 	update_F
// 	normalize_F

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/sNMF/als_F.h"
#include "../../../src/nnlsm/blockpivot.h"
#include "../../../src/io/io_data_double.h"
#include "../../../src/io/io_data_int.h"
#include "../../../src/bituint/io_geno_bituint.h"

int main (int argc, char *argv[])
{
	// parameters
	char input[512];
	int N, M, K, Mp, nc = 2;
	char input_Q[512];
	char output_F1[512];
	char output_F2[512];
	char output_F3[512];
	bituint* dat;	
	double *Q, *F;
	Memory mem;

	// command line args configuration
        strcpy(input, argv[1]);
        strcpy(input_Q, argv[2]);
        N = (int) atoi (argv[3]);
        M = (int) atoi (argv[4]);
        read_data_int(argv[5], 1, 1, &K);
        nc = (int) atoi (argv[6]);
        strcpy(output_F1, argv[7]);
        strcpy(output_F2, argv[8]);
        strcpy(output_F3, argv[9]);

	// allocate memory
	init_mat_bituint(&dat, N, M * nc, &Mp);
	mem = allocate_memory(M*nc, K);
	Q = (double *) malloc(N * K * sizeof(double));
	F = (double *) malloc(M * nc * K * sizeof(double));

	// read data
	read_geno_bituint(input, N, M, Mp, nc, dat);		
	read_data_double(input_Q, N, K, Q);		

	// test update_F
	update_F(F, Q, dat, N, M, nc, Mp, K, 1, mem);
	write_data_double(output_F1, M*nc, K, F);
	update_F(F, Q, dat, N, M, nc, Mp, K, 2, mem);
	write_data_double(output_F2, M*nc, K, F);

	// test normalize_F
	normalize_F(F, M, nc, K);
	write_data_double(output_F3, M*nc, K, F);

	// free memory
	free_memory(mem);
	free(mem);
	free(dat);
	free(F);
	free(Q);

	return 0;
}
