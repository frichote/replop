// by E. Frichot

// file: register_ce

// functions:
// 	register_ce
// 	print_ce

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/crossEntropy/register_ce.h"
#include "../../../src/crossEntropy/print_ce.h"

int main (int argc, char *argv[])
{
	// parameters
        int m = 2, K;
        char input[512];
        char input_I[512] = "";
        char input_Q[512] = "";
        char input_F[512] = "";


        // test register_ce
        // test print_help_ce
        analyse_param_ce(argc, argv, &m, &K, input, input_Q, input_F, input_I);

        // test print_summary_ce
        print_summary_ce (10, 100, K, m, input, input_Q, input_F, input_I);

	return 0;
}
