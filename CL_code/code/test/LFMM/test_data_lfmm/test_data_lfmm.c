// by E. Frichot

// file: data_lfmm

// functions:
// 	zscore_calc
// 	update_sum
// 	update_sum2
// 	update_mean
// 	modify_C
// 	write_DIC
// 	write_zscore_double
// 	var_data
// 	inputation_lfmm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/LFMM/data_lfmm.h"
#include "../../../src/io/io_data_double.h"
#include "../../../src/io/io_data_float.h"
#include "../../../src/io/io_data_int.h"

int main (int argc, char *argv[])
{
        // parameters
	char input_sum[512];
	char input_sum2[512];
	char input_mean[512];
	char input_beta[512];
	char output_zscore1[512];
	char output_zscore2[512];
	char output_DIC[512];
	char output_R[512];
	char output_sum[512];
	char output_sum2[512];
	char output_mean[512];
        char input_R[512];
        char input_C[512];
        char input_U[512];
        char input_V[512];
        char input_I[512];
	double *zscore, *sum, *sum2, *beta, *mean, *C, *U, *V, *CC; 
	float *R;
	int D = 3, cur = 10, *I;
	double deviance = 2.1, var1 = 0, var2 = 0;
	double thrd_m1 = 10.0, thrd_m2 = 10.0;
	int N = 10, M = 100, K = 2; 

        // command line args configuration
        strcpy(input_sum, argv[1]);
        strcpy(input_sum2, argv[2]);
        strcpy(input_mean, argv[3]);
        strcpy(input_beta, argv[4]);
        strcpy(input_R, argv[5]);
        strcpy(input_C, argv[6]);
        strcpy(input_U, argv[7]);
        strcpy(input_V, argv[8]);
        strcpy(input_I, argv[9]);
	N = (int) atoi(argv[10]);
	D = (int) atoi(argv[11]);
        strcpy(output_DIC, argv[12]);
        strcpy(output_zscore1, argv[13]);
        strcpy(output_zscore2, argv[14]);
        strcpy(output_R, argv[15]);
        strcpy(output_sum, argv[16]);
        strcpy(output_sum2, argv[17]);
        strcpy(output_mean, argv[18]);

        // allocate memory
	zscore = (double *) malloc(M * D * sizeof(double));
        sum = (double *) malloc(M * D * sizeof(double));
        sum2 = (double *) malloc(M * D * sizeof(double));
        beta = (double *) malloc(M * D * sizeof(double));
        mean = (double *) malloc(M * D * sizeof(double));
        C = (double *) malloc(N * (D-1) * sizeof(double));
        CC = (double *) malloc(N * D * sizeof(double));
        U = (double *) malloc(N * K * sizeof(double));
        V = (double *) malloc(M * K * sizeof(double));
	R = (float *) malloc(N * M * sizeof(float));
	I = (int *) malloc(N * M * sizeof(int));

        // read data
        read_data_double(input_sum, D, M, sum);
        read_data_double(input_sum2, D, M, sum2);
        read_data_double(input_mean, D, M, mean);
        read_data_double(input_beta, D, M, beta);
        read_data_double(input_V, K, M, V);
        read_data_double(input_U, K, N, U);
        read_data_float(input_R, N, M, R);
        read_data_double(input_C, N, D-1, C);
        read_data_int(input_I, N, M, I);

	// test zscore_calc
	// test write_zscore_double
	zscore_calc(zscore, sum, sum2, M, cur, D);
	write_zscore_double(output_zscore1, M, zscore, D-1, 1, 0);
	zscore_calc(zscore, sum, sum2, M, cur, D);
	write_zscore_double(output_zscore2, M, zscore, D, 0, 0);

	// test update_sum
	update_sum(beta, sum, D * M);
	write_data_double(output_sum, D, M, sum); 

	// test update_sum2
	update_sum2(beta, sum2, D * M);
	write_data_double(output_sum2, D, M, sum2); 

	// test update_mean
	update_mean(beta, mean, D * M, cur); 
	write_data_double(output_mean, D, M, mean);

	// test modify_C
	modify_C(C, N, D-1, CC, 0, 1);

	// test var_data
	var1 = var_data(R, U, V, CC, beta, N, M, K, D, &thrd_m1, 1);
	printf("%g %g\n", var1, thrd_m1);
	var2 = var_data(R, U, V, CC, beta, N, M, K, D, &thrd_m2, 2);
	printf("%g %g\n", var2, thrd_m2);

	// test update_deviance 
	// test write_DIC
	update_deviance(&deviance, cur, var1, thrd_m1); 
	write_DIC(output_DIC, deviance, 1.0);

	// test inputation_lfmm
	inputation_lfmm(R, U, V, CC, beta, I, N, M, K, D);
	write_data_float(output_R, N, M, R);

	// free memory
	free(zscore);
	free(sum);
	free(sum2);
	free(beta);
	free(mean);
	free(C);
	free(CC);
	free(U);
	free(V);
	free(R);
	free(I);

	return 0;
}
