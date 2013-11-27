// by E. Frichot

// file: V

// functions:
// 	create_m_V
// 	create_inv_cov_V

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/LFMM/V.h"
#include "../../../src/io/io_data_int.h"
#include "../../../src/io/io_data_double.h"
#include "../../../src/io/io_data_float.h"

int main (int argc, char *argv[])
{
        // parameters
        char input_R[512];
        char input_C[512];
        char input_U[512];
        char input_B[512];
        char output_m_V1[512];
        char output_m_V2[512];
        char output_inv_cov_V1[512];
        char output_inv_cov_V2[512];
        int N, M, D, K;
        float *R;
        double *C, *B, *U, *m_V1, *m_V2, *inv_cov_V1, *inv_cov_V2;
	double alpha = 1.3, alpha_R = 2.5;


        // command line args configuration
        strcpy(input_R, argv[1]);
        strcpy(input_U, argv[2]);
        strcpy(input_B, argv[3]);
        strcpy(input_C, argv[4]);
        N = (int) atoi (argv[5]);
        M = (int) atoi (argv[6]);
        read_data_int(argv[7], 1, 1, &D);
        read_data_int(argv[8], 1, 1, &K);
        strcpy(output_m_V1, argv[9]);
        strcpy(output_m_V2, argv[10]);
        strcpy(output_inv_cov_V1, argv[11]);
        strcpy(output_inv_cov_V2, argv[12]);

        // allocate memory
        C = (double *) malloc(N * D * sizeof(double));
        R = (float *) malloc(N * M * sizeof(float));
        U = (double *) malloc(N * K * sizeof(double));
        B = (double *) malloc(M * D * sizeof(double));
        m_V1 = (double *) malloc(K * M * sizeof(double));
        m_V2 = (double *) malloc(K * M * sizeof(double));
        inv_cov_V1 = (double *) malloc(K * K * sizeof(double));
        inv_cov_V2 = (double *) malloc(K * K * sizeof(double));

        // read data
        read_data_double(input_C, N, D, C);
        read_data_double(input_U, K, N, U);
        read_data_double(input_B, D, M, B);
        read_data_float(input_R, N, M, R);

        // test create_m_beta
        create_m_V(U, R, C, B, m_V1, M, N, D, K, 1);
        write_data_double(output_m_V1, K, M, m_V1);
        create_m_V(U, R, C, B, m_V2, M, N, D, K, 2);
        write_data_double(output_m_V2, K, M, m_V2);

        // test create_inv_cov_U
        create_inv_cov_V(inv_cov_V1, alpha, alpha_R, U, K, N, 1);
        write_data_double(output_inv_cov_V1, K, K, inv_cov_V1);
        create_inv_cov_V(inv_cov_V2, alpha, alpha_R, U, K, N, 2);
        write_data_double(output_inv_cov_V2, K, K, inv_cov_V2);

	return 0;
}
