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
#include "../LFMM/LFMM.h"
#include "../LFMM/register_lfmm.h"
#include "../LFMM/print_lfmm.h"
#include "../io/io_tools.h"
#include "../matrix/matrix.h"

int main(int argc, char *argv[])
{

	// Parameters initialization
	int nd = 0;
	int all = 0;
	int K = 0;
	int n, L, D;
	int burn = 100;
	int Niter = 1000;
	int num_thrd = 1;
	int missing_data = 0;
	char output_file[512] = "";
	char input_file[512];
	char cov_file[512];
        char dev_file[512] = "";
	long long seed = -1;
	double dev, dic;
	double noise_epsilon = 1e-3;
	double b_epsilon = 1000;
	int init = 1; 

	// print
	print_head_lfmm();
	print_options(argc, argv);

	// analyse of the command line
	analyse_param_lfmm(argc, argv, &nd, &K, &Niter, &burn,
		      &missing_data, output_file, input_file, cov_file,
		      &num_thrd, &seed, &all);

	// run function
	LFMM(input_file, output_file, cov_file, &n, &L, &D, nd, K,
		Niter, burn, num_thrd, &seed, missing_data, all, &dic, &dev,
		noise_epsilon, b_epsilon, init);

	return 0;
}
