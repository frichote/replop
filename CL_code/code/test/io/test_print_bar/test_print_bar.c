// by E. Frichot

// file: print_bar

// functions:
// 	init_bar
// 	print_bar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../../../src/io/print_bar.h"

int main (int argc, char *argv[])
{
	// parameters
	int Niter, i, j, n;

	// command line args configuration
	Niter = (int) atoi(argv[1]);

	// test init_bar
	init_bar(&i,&j);

	// test print_bar
	for (n = 0; n < Niter; n++) {
		usleep(1000);	
		print_bar(&i, &j, Niter);
	}

	final_bar();

	return 0;
}
