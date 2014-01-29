// by E. Frichot

// file: beta

// functions:
// 	create_m_beta
// 	create_CCt
// 	create_inv_cov_beta

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/LFMM/beta.h"
#include "../../../src/io/io_data_int.h"
#include "../../../src/io/io_data_double.h"
#include "../../../src/io/io_data_float.h"

int main (int argc, char *argv[])
{
	// parameters
        char input_R[512];
        char input_C[512];
        char input_U[512];
        char input_V[512];
        char input_alpha_beta[512];
        char output_m_beta1[512];
        char output_m_beta2[512];
        char output_CCt[512];
        char output_inv_cov_beta[512];
        int N, M, D, K;
        float *R;
	double *C, *U, *V, *m_beta1, *m_beta2, *CCt, *inv_cov_beta, *alpha_beta;


	// command line args configuration
        strcpy(input_R, argv[1]);
        strcpy(input_U, argv[2]);
        strcpy(input_V, argv[3]);
        strcpy(input_C, argv[4]);
        strcpy(input_alpha_beta, argv[5]);
        N = (int) atoi (argv[6]);
        M = (int) atoi (argv[7]);
	read_data_int(argv[8], 1, 1, &D);
	read_data_int(argv[9], 1, 1, &K);
        strcpy(output_m_beta1, argv[10]);
        strcpy(output_m_beta2, argv[11]);
        strcpy(output_CCt, argv[12]);
        strcpy(output_inv_cov_beta, argv[13]);

	// allocate memory
	C = (double *) malloc(N * D * sizeof(double));
	R = (float *) malloc(N * M * sizeof(float));
	U = (double *) malloc(N * K * sizeof(double));
	V = (double *) malloc(M * K * sizeof(double));
	m_beta1 = (double *) malloc(M * D * sizeof(double));
	m_beta2 = (double *) malloc(M * D * sizeof(double));
	CCt = (double *) malloc(D * D * sizeof(double));
	inv_cov_beta = (double *) malloc(D * D * sizeof(double));
	alpha_beta = (double *) malloc(D * sizeof(double));

	// read data
	read_data_double(input_C, N, D, C);
	read_data_double(input_U, K, N, U);
	read_data_double(input_V, K, M, V);
	read_data_float(input_R, N, M, R);
	read_data_double(input_alpha_beta, D, 1, alpha_beta);

	// test create_m_beta
	create_m_beta(C, R, U, V, m_beta1, M, N, D, K, 1);
	write_data_double(output_m_beta1, D, M, m_beta1);
	create_m_beta(C, R, U, V, m_beta2, M, N, D, K, 2);
	write_data_double(output_m_beta2, D, M, m_beta2);

	// test create_CCt
	create_CCt(CCt, C, D, N);
	write_data_double(output_CCt, D, D, CCt);

	// test create_inv_cov_beta
	create_inv_cov_beta(inv_cov_beta, alpha_beta, 2.5, D, CCt);
	write_data_double(output_inv_cov_beta, D, D, inv_cov_beta);

	return 0;
}
