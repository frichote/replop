#!/bin/sh
#
# by E. Frichot
#
# file: data
#
# functions:
# 	zeros
# 	check_mat
# 	update_m
# 	create_I
# 	clean_data
#
# command line:
# ./test_data input1 input2 N M output1 output2
#
# exec zeros
# exec check_mat
# exec update_m
# exec create_I
# exec clean_data
#

. ../../meta.sh

./test_data files/data_N10_M10.txt files/create_I_N10_M10.txt 10 10 files/out_update_N10_M10.txt files/out_I_N10_M10.txt > files/out_zeros.txt


log "./test_data files/data_N10_M10.txt files/create_I_N10_M10.txt 10 10 files/update_N10_M10.txt files/I_N10_M10.txt" files/out_zeros.txt files/ref_zeros.txt

ok_matrix "./test_data files/data_N10_M10.txt files/create_I_N10_M10.txt 10 10 files/update_N10_M10.txt files/I_N10_M10.txt" files/out_update_N10_M10.txt files/update_N10_M10.txt

ok_matrix "./test_data files/data_N10_M10.txt files/create_I_N10_M10.txt 10 10 files/update_N10_M10.txt files/I_N10_M10.txt" files/out_I_N10_M10.txt files/I_N10_M10.txt
