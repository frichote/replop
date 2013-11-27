#!/bin/sh
#
# by E. Frichot
#
# file: cholesky
#
# functions:
# 	cholesky
#
# command line:
# ./test_cholesky input_file N output_file
#
# exec cholesky
#

. ../../meta.sh

N=10
./test_cholesky files/file_N$N.txt $N files/out_N$N.txt
ok_matrix "./test_cholesky files/file_N$N.txt $N files/out_N$N.txt" files/out_N$N.txt files/chol_file_N$N.txt

N=1
./test_cholesky files/file_N$N.txt $N files/out_N$N.txt
ok_matrix "./test_cholesky files/file_N$N.txt $N files/out_N$N.txt" files/out_N$N.txt files/chol_file_N$N.txt
