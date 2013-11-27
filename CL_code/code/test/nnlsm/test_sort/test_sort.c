// by E. Frichot

// file: sort

// functions:
// 	sortCols
// 	sortColsRec

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../src/nnlsm/sort.h"
#include "../../../src/io/io_data_int.h"

// check_ordered_matrix

int check_ordered_matrix(int* X, int* sortIx, int* breaks, int N, int K)
{
        int k, i, equal;

        if (!breaks[0])
                return 1;

        // check if the current column is equal to the previous column
        // if not (!ok), then check that breaks is true
        for (i = 1; i < N; i++) {
                equal = 1;
                for (k=0; k < K; k++) {
                        if (equal) {
                                if (X[k*N+sortIx[i-1]] && !X[k*N+sortIx[i]])
                                        return 1;
                                else if (!X[k*N+sortIx[i-1]] && X[k*N+sortIx[i]])
                                        equal = 0;
                        }
                }
                if (!equal && !breaks)
                        return 1;
        }
        return 0;
}

// test_matrix

void test_matrix(char* test_file, int K, int N)
{
        int* X = (int *) malloc(K * N * sizeof(int));
        int* breaks = (int *) malloc(N * sizeof(int));
        int* sortIx = (int *) malloc(N * sizeof(int));
        int error;
	Memory mem;

        read_data_int(test_file,K,N,X);
	mem = allocate_memory(N, K);
        sortCols(breaks,sortIx,X,K,N, mem);
        error = check_ordered_matrix(X,sortIx,breaks, N, K);

        free(X);
        free(breaks);
        free(sortIx);
	free_memory(mem);
        if (error)
                printf("\\033[1;31m [Error] \\033[0;39m test file: %s\n",test_file);
        else
                printf("\\033[1;32m [OK] \\033[0;39m test file: %s\n",test_file);

}


int main (int argc, char *argv[])
{
	// parameters
        test_matrix("files/test_K1N1_0.txt",1,1);
        test_matrix("files/test_K1N1_1.txt",1,1);
        test_matrix("files/test_K1N10_0.txt",1,10);
        test_matrix("files/test_K1N10_1.txt",1,10);
        test_matrix("files/test_K1N10_rand.txt",1,10);
        test_matrix("files/test_K10N10_0.txt",10,10);
        test_matrix("files/test_K10N10_1.txt",10,10);
        test_matrix("files/test_K10N10_rand.txt",10,10);
        test_matrix("files/test_K10N1_0.txt",10,1);
        test_matrix("files/test_K10N1_1.txt",10,1);
        test_matrix("files/test_K10N1_rand.txt",10,1);
        test_matrix("files/test_K100N10_rand.txt",100,10);
        test_matrix("files/test_K10N100_rand-1.txt",10,100);
        test_matrix("files/test_K10N100_rand-2.txt",10,100);
        test_matrix("files/test_K10N100_rand-3.txt",10,100);
        test_matrix("files/test_K10N100_rand-4.txt",10,100);
        test_matrix("files/test_K10N100_rand-5.txt",10,100);
        test_matrix("files/test_K10N100_rand-6.txt",10,100);
        test_matrix("files/test_K10N100_rand-7.txt",10,100);
        test_matrix("files/test_K10N100_rand-8.txt",10,100);
        test_matrix("files/test_K10N100_rand-9.txt",10,100);
        test_matrix("files/test_K10N100_rand-10.txt",10,100);
        test_matrix("files/plop.txt",5,82);


	// command line args configuration

	// test sortCols

	// test sortColsRec

	return 0;
}
