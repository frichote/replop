#!/bin/sh
#
# by E. Frichot
#
# file: criteria
#
# functions:
# 	least_square
#
# command line:
# ./test_criteria input input_Q input_F N M file_K nc file_alpha output_LS
#
# exec least_square
#

. ../../meta.sh

ok_cl "./test_criteria files/R.txt files/Q.txt files/F.txt 10 100 files/K.txt 3 files/alpha.txt files/out_LS.txt"
ok_matrix "./test_criteria" files/out_LS.txt files/ref_LS.txt
