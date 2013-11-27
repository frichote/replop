// by E. Frichot

// file: register_cds, print_cds

// functions:
// 	print_help_cds
// 	register_cds
// 	print_summary_cds

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/createDataSet/register_cds.h"
#include "../../../src/createDataSet/print_cds.h"

int main (int argc, char *argv[])
{
	// parameters
	int K;
	long long s = 1;
	int m = 2;
	double e = 0.05;
	char input[512];
	char output[512] = "";


	// test register_cds
	// test print_help_cds
	analyse_param_cds(argc, argv, &m, &s, &e, input, output);

	// test print_summary_cds
	print_summary_cds (10, 100, m, s, e, input, output);

	return 0;
}
