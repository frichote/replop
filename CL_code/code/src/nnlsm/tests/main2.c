/*
    NMF, file: main.c
    Copyright (C) 2013 François Mathieu, Eric Frichot

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
#include <stdio.h>
#include <string.h>
#include "in_out/src/read.h"
#include "nnlsm/src/sort.h"

// test_matrix

void test_matrix(char* test_file, int K, int N)
{
        int* X = (int *) malloc(K * N * sizeof(int));
        int* breaks = (int *) malloc(N * sizeof(int));
        int* sortIx = (int *) malloc(N * sizeof(int));
	int error;

	read_data_int2(test_file,K,N,X);
	sortCols(breaks,sortIx,X,K,N);
	error = check_ordered_matrix(X,sortIx,breaks, N, K);

	if (error) {
		printf("[Error] for test file: %s\n",test_file);
		printf("X:\n");
		print_matrix(X,K,N);
		printf("breaks\n");
		print_matrix(breaks,1,N);
		printf("Ordered X\n");
		print_ordered_matrix(X,sortIx,K,N);
		printf("\n");
	} else {
		printf("[OK] test file: %s\n",test_file);
	}

	free(X);
	free(breaks);
	free(sortIx);
}

int main (int argc, char *argv[]) {

	test_matrix("test_K1N1_0.txt",1,1);
	test_matrix("test_K1N1_1.txt",1,1);
	test_matrix("test_K1N10_0.txt",1,10);
	test_matrix("test_K1N10_1.txt",1,10);
	test_matrix("test_K1N10_rand.txt",1,10);
	test_matrix("test_K10N10_0.txt",10,10);
	test_matrix("test_K10N10_1.txt",10,10);
	test_matrix("test_K10N10_rand.txt",10,10);
	test_matrix("test_K10N1_0.txt",10,1);
	test_matrix("test_K10N1_1.txt",10,1);
	test_matrix("test_K10N1_rand.txt",10,1);
	test_matrix("test_K100N10_rand.txt",100,10);
	test_matrix("test_K10N100_rand-1.txt",10,100);
	test_matrix("test_K10N100_rand-2.txt",10,100);
	test_matrix("test_K10N100_rand-3.txt",10,100);
	test_matrix("test_K10N100_rand-4.txt",10,100);
	test_matrix("test_K10N100_rand-5.txt",10,100);
	test_matrix("test_K10N100_rand-6.txt",10,100);
	test_matrix("test_K10N100_rand-7.txt",10,100);
	test_matrix("test_K10N100_rand-8.txt",10,100);
	test_matrix("test_K10N100_rand-9.txt",10,100);
	test_matrix("test_K10N100_rand-10.txt",10,100);

        return 0;
}
