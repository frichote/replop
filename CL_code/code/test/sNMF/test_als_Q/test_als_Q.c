// by E. Frichot

// file: als_Q

// functions:
// 	normalize_Q
// 	F_tF_alpha
// 	F_tX

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/sNMF/als_Q.h"
#include "../../../src/io/io_data_double.h"
#include "../../../src/io/io_data_int.h"
#include "../../../src/bituint/io_geno_bituint.h"

int main (int argc, char *argv[])
{
        // parameters
        char input[512];
        int N, M, K, Mp, nc = 2;
        char input_F[512];
        char output_temp1_1[512];
        char output_temp1_2[512];
        char output_temp3_1[512];
        char output_temp3_2[512];
        bituint* dat;
        double *F, *temp1, *temp3;
        Memory mem;
	double alpha;

        // command line args configuration
        strcpy(input, argv[1]);
        strcpy(input_F, argv[2]);
        N = (int) atoi (argv[3]);
        M = (int) atoi (argv[4]);
        read_data_int(argv[5], 1, 1, &K);
        read_data_double(argv[6], 1, 1, &alpha);
        nc = (int) atoi (argv[7]);
        strcpy(output_temp1_1, argv[8]);
        strcpy(output_temp1_2, argv[9]);
        strcpy(output_temp3_1, argv[10]);
        strcpy(output_temp3_2, argv[11]);

        // allocate memory
        init_mat_bituint(&dat, N, M * nc, &Mp);
        mem = allocate_memory(M*nc, K);
        F = (double *) malloc(M * nc * K * sizeof(double));
        temp1 = (double *) malloc(K * K * sizeof(double));
        temp3 = (double *) malloc(K * N * sizeof(double));

	// read data
        read_geno_bituint(input, N, M, Mp, nc, dat);
        read_data_double(input_F, M*nc, K, F);


	// test F_tF_alpha
	F_tF_alpha(temp1, F, nc, K, M, Mp, N, 1, alpha);
	write_data_double(output_temp1_1, K, K, temp1);
	F_tF_alpha(temp1, F, nc, K, M, Mp, N, 2, alpha);
	write_data_double(output_temp1_2, K, K, temp1);

	// test F_tX
	tF_tX(temp3, dat, F, nc, K, M, Mp, N, 1);
	write_data_double(output_temp3_1, K, N, temp3);
	tF_tX(temp3, dat, F, nc, K, M, Mp, N, 2);
	write_data_double(output_temp3_2, K, N, temp3);



	// free memory
	free_memory(mem);
	free(mem);
	free(F);
	free(dat);
	free(temp1);
	free(temp3);

	return 0;
}
