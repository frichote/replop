// by E. Frichot

// file: criteria

// functions:
// 	least_square

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/sNMF/criteria.h"
#include "../../../src/bituint/io_geno_bituint.h"
#include "../../../src/nnlsm/blockpivot.h"
#include "../../../src/io/io_data_double.h"
#include "../../../src/io/io_data_int.h"

int main (int argc, char *argv[])
{
	// parameters
        char input[512];
        int N, M, K, Mp, nc = 2;
        char input_Q[512];
        char input_F[512];
        char output_LS[512];
        bituint* dat;
        double *Q, *F;
	double alpha, res;
	Memory mem;

	// command line args configuration
        strcpy(input, argv[1]);
        strcpy(input_Q, argv[2]);
        strcpy(input_F, argv[3]);
        N = (int) atoi (argv[4]);
        M = (int) atoi (argv[5]);
        read_data_int(argv[6], 1, 1, &K);
        nc = (int) atoi (argv[7]);
        read_data_double(argv[8], 1, 1, &alpha);
        strcpy(output_LS, argv[9]);

	printf("K %d\n",K);

        // allocate memory
        init_mat_bituint(&dat, N, M * nc, &Mp);
        mem = allocate_memory(M*nc, K);
        Q = (double *) malloc(N * K * sizeof(double));
        F = (double *) malloc(M * nc * K * sizeof(double));

        // read data
        read_geno_bituint(input, N, M, Mp, nc, dat);
        read_data_double(input_Q, N, K, Q);
        read_data_double(input_F, M*nc, K, F);


	// test least_square
	res = least_square(dat, Q, F, N, M, nc, Mp, K, alpha);

	write_data_double(output_LS, 1, 1, &res);

	// free memory
	free_memory(mem);
	free(mem);
	free(dat);
	free(Q);
	free(F);

	return 0;
}
