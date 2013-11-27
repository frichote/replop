#!/bin/sh
#
# by E. Frichot
#
# file: rand
#
# functions:
# 	zscore2pvalue
# ./test_rand input N
#
# command line:
#
# exec zscore2pvalue
#

. ../../meta.sh

./test_rand files/ref_zscore.txt 3001 > files/out_mlpvalue.txt 

ok_matrix "./test_rand files/ref_zscore.txt 3001 > files/out_mlpvalue.txt" files/out_mlpvalue.txt files/ref_mlpvalue.txt
