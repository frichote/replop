// by E. Frichot

// file: register_lfmm

// functions:
// 	print_summary_lfmm
// 	analyse_param_lfmm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/LFMM/register_lfmm.h"
#include "../../../src/LFMM/print_lfmm.h"

int main (int argc, char *argv[])
{
	// parameters
	int d = 0, K, m, num_thrd = 1;
	char output[512] = "";
	char input[512];
	char cov_file[512];
	char dev_file[512] = "";
	long long s = 1;
	int N = 10, M = 100, D = 2, Niter = 1000, burn = 200, all = 0;

	// command line args configuration
	// test analyse_param_lfmm
	analyse_param_lfmm(argc, argv, &d, &K, &Niter, &burn, &m, output, input,
		cov_file, dev_file, &num_thrd, &s, &all); 

	// test print_summary_lfmm
	print_summary_lfmm(N, M, K, D, d, Niter, burn, m, output, input,
		cov_file, dev_file, num_thrd, s, all);


	return 0;
}
