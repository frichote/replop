// by E. Frichot

// file: register_snmf

// functions:
// 	analyze_param_snmf

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/sNMF/register_snmf.h"
#include "../../../src/sNMF/print_snmf.h"

int main (int argc, char *argv[])
{
	// parameters
	int m = 2, K, iter = 1000, num_thrd = 1;
	double alpha = 100, tol = 0.0001, e = 0.0;
	long long s = 1;
	char input[512];
	char output_Q[512];
	char output_F[512];
	int N = 10, M = 100;

	// command line args configuration
	
	// test analyze_param_snmf
	analyse_param_snmf(argc, argv, &m, &s, &K, &alpha, &tol, &e,
		&iter, input, &num_thrd, output_Q, output_F);

	// test print_help_snmf
	print_summary_snmf(N, M, m, s, K, alpha, tol, iter, 
		input, num_thrd, e, output_Q, output_F);	

	return 0;
}
