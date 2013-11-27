// by E. Frichot

// file: U

// functions:
// 	create_m_U
// 	create_inv_cov_U

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/LFMM/U.h"
#include "../../../src/io/io_data_int.h"
#include "../../../src/io/io_data_double.h"
#include "../../../src/io/io_data_float.h"

int main (int argc, char *argv[])
{
        // parameters
        char input_R[512];
        char input_C[512];
        char input_B[512];
        char input_V[512];
        char output_m_U1[512];
        char output_m_U2[512];
        char output_inv_cov_U1[512];
        char output_inv_cov_U2[512];
        int N, M, D, K;
        float *R;
        double *C, *B, *V, *m_U1, *m_U2, *inv_cov_U1, *inv_cov_U2;
	double alpha = 1.3;
	double alpha_R = 2.5;

        // command line args configuration
        strcpy(input_R, argv[1]);
        strcpy(input_B, argv[2]);
        strcpy(input_V, argv[3]);
        strcpy(input_C, argv[4]);
        N = (int) atoi (argv[5]);
        M = (int) atoi (argv[6]);
        read_data_int(argv[7], 1, 1, &D);
        read_data_int(argv[8], 1, 1, &K);
        strcpy(output_m_U1, argv[9]);
        strcpy(output_m_U2, argv[10]);
        strcpy(output_inv_cov_U1, argv[11]);
        strcpy(output_inv_cov_U2, argv[12]);

        // allocate memory
        C = (double *) malloc(N * D * sizeof(double));
        R = (float *) malloc(N * M * sizeof(float));
        B = (double *) malloc(M * D * sizeof(double));
        V = (double *) malloc(M * K * sizeof(double));
        m_U1 = (double *) malloc(N * K * sizeof(double));
        m_U2 = (double *) malloc(N * K * sizeof(double));
        inv_cov_U1 = (double *) malloc(K * K * sizeof(double));
        inv_cov_U2 = (double *) malloc(K * K * sizeof(double));

        // read data
        read_data_double(input_C, N, D, C);
        read_data_double(input_B, D, M, B);
        read_data_double(input_V, K, M, V);
        read_data_float(input_R, N, M, R);

        // test create_m_U
        create_m_U(V, R, C, B, m_U1, M, N, D, K, 1);
        write_data_double(output_m_U1, N, K, m_U1);
        create_m_U(V, R, C, B, m_U2, M, N, D, K, 2);
        write_data_double(output_m_U2, N, K, m_U2);

        // test create_inv_cov_U
        create_inv_cov_U(inv_cov_U1, alpha, alpha_R, V, K, M, 1);
        write_data_double(output_inv_cov_U1, K, K, inv_cov_U1);
        create_inv_cov_U(inv_cov_U2, alpha, alpha_R, V, K, M, 2);
        write_data_double(output_inv_cov_U2, K, K, inv_cov_U2);

	return 0;
}
