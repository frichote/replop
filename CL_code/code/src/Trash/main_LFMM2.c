/*
    LFMM, file: main_LFMM.c
    Copyright (C) 2012 Eric Frichot

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../LFMM2/LFMM.h"
#include "../LFMM2/register_lfmm.h"
#include "../LFMM2/print_lfmm.h"
#include "../io/io_tools.h"

int main(int argc, char *argv[])
{

	// Parameters initialization
	int nd = 0;
	int all = 0;
	int K = 0;
	int burn = 1000;
	int Niter = 3000;
	int num_thrd = 1;
	int missing_data = 0;
	char output_file[512] = "";
	char input_file[512];
	char cov_file[512];
        char dev_file[512] = "";
	long long seed = -1;

	// print
	print_head_lfmm();
	print_options(argc, argv);

	// analyse of the command line
	analyse_param_lfmm(argc, argv, &nd, &K, &Niter, &burn,
		      &missing_data, output_file, input_file, cov_file, dev_file,
		      &num_thrd, &seed, &all);

	// run function
	LFMM(input_file, output_file, cov_file, dev_file, nd, K,
		Niter, burn, num_thrd, seed, missing_data, all);

	return 0;
}
