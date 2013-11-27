#!/bin/sh
#
# by E. Frichot
#
# file: matrix
#
# functions:
# 	dble_sum2
# 	dble_sum
# 	copy_vect
# 	transpose_double
# 	transpose_float
# 	transpose_int
#
# command line:
# ./test_matrix input N M out1 out2 out3 out4 out5 out6
#
# exec dble_sum2
# exec dble_sum
# exec copy_vect
# exec transpose_double
# exec transpose_float
# exec transpose_int

. ../../meta.sh

N=10; M=100;
ok_cl "./test_matrix files/data_N$N\_M$M.txt $N $M files/out_dble_sum2_N$N\_M$M.txt files/out_dble_sum_N$N\_M$M.txt files/out_cpy_N$N\_M$M.txt files/trans_double_N$N\_M$M.txt files/trans_float_N$N\_M$M.txt files/trans_int_N$N\_M$M.txt"
ok_matrix "cmp files/out_dble_sum2_N$N\_M$M.txt files/dble_sum2_N$N\_M$M.txt" files/out_dble_sum2_N$N\_M$M.txt files/dble_sum2_N$N\_M$M.txt
ok_matrix "cmp files/out_dble_sum_N$N\_M$M.txt files/dble_sum_N$N\_M$M.txt" files/out_dble_sum_N$N\_M$M.txt files/dble_sum_N$N\_M$M.txt
ok_matrix "cmp files/out_cpy_N$N\_M$M.txt files/data_N$N\_M$M.txt" files/out_cpy_N$N\_M$M.txt files/data_N$N\_M$M.txt
ok_matrix "cmp files/trans_N$N\_M$M.txt files/trans_double_N$N\_M$M.txt" files/trans_double_N$N\_M$M.txt files/trans_N$N\_M$M.txt
ok_matrix "cmp files/trans_N$N\_M$M.txt files/trans_float_N$N\_M$M.txt" files/trans_float_N$N\_M$M.txt files/trans_N$N\_M$M.txt
ok_matrix "cmp files/trans_N$N\_M$M.txt files/trans_int_N$N\_M$M.txt" files/trans_int_N$N\_M$M.txt files/trans_N$N\_M$M.txt

N=1; M=100;
./test_matrix files/data_N$N\_M$M.txt $N $M files/out_dble_sum2_N$N\_M$M.txt files/out_dble_sum_N$N\_M$M.txt files/out_cpy_N$N\_M$M.txt files/trans_double_N$N\_M$M.txt files/trans_float_N$N\_M$M.txt files/trans_int_N$N\_M$M.txt
ok_matrix "cmp files/out_dble_sum2_N$N\_M$M.txt files/dble_sum2_N$N\_M$M.txt" files/out_dble_sum2_N$N\_M$M.txt files/dble_sum2_N$N\_M$M.txt
ok_matrix "cmp files/out_dble_sum_N$N\_M$M.txt files/dble_sum_N$N\_M$M.txt" files/out_dble_sum_N$N\_M$M.txt files/dble_sum_N$N\_M$M.txt
ok_matrix "cmp files/out_cpy_N$N\_M$M.txt files/data_N$N\_M$M.txt" files/out_cpy_N$N\_M$M.txt files/data_N$N\_M$M.txt
ok_matrix "cmp files/trans_N$N\_M$M.txt files/trans_double_N$N\_M$M.txt" files/trans_double_N$N\_M$M.txt files/trans_N$N\_M$M.txt
ok_matrix "cmp files/trans_N$N\_M$M.txt files/trans_float_N$N\_M$M.txt" files/trans_float_N$N\_M$M.txt files/trans_N$N\_M$M.txt
ok_matrix "cmp files/trans_N$N\_M$M.txt files/trans_int_N$N\_M$M.txt" files/trans_int_N$N\_M$M.txt files/trans_N$N\_M$M.txt

N=1; M=1;
./test_matrix files/data_N$N\_M$M.txt $N $M files/out_dble_sum2_N$N\_M$M.txt files/out_dble_sum_N$N\_M$M.txt files/out_cpy_N$N\_M$M.txt files/trans_double_N$N\_M$M.txt files/trans_float_N$N\_M$M.txt files/trans_int_N$N\_M$M.txt
ok_matrix "cmp files/out_dble_sum2_N$N\_M$M.txt files/dble_sum2_N$N\_M$M.txt" files/out_dble_sum2_N$N\_M$M.txt files/dble_sum2_N$N\_M$M.txt
ok_matrix "cmp files/out_dble_sum_N$N\_M$M.txt files/dble_sum_N$N\_M$M.txt" files/out_dble_sum_N$N\_M$M.txt files/dble_sum_N$N\_M$M.txt
ok_matrix "cmp files/out_cpy_N$N\_M$M.txt files/data_N$N\_M$M.txt" files/out_cpy_N$N\_M$M.txt files/data_N$N\_M$M.txt
ok_matrix "cmp files/trans_N$N\_M$M.txt files/trans_double_N$N\_M$M.txt" files/trans_double_N$N\_M$M.txt files/trans_N$N\_M$M.txt
ok_matrix "cmp files/trans_N$N\_M$M.txt files/trans_float_N$N\_M$M.txt" files/trans_float_N$N\_M$M.txt files/trans_N$N\_M$M.txt
ok_matrix "cmp files/trans_N$N\_M$M.txt files/trans_int_N$N\_M$M.txt" files/trans_int_N$N\_M$M.txt files/trans_N$N\_M$M.txt

N=10; M=1;
./test_matrix files/data_N$N\_M$M.txt $N $M files/out_dble_sum2_N$N\_M$M.txt files/out_dble_sum_N$N\_M$M.txt files/out_cpy_N$N\_M$M.txt files/trans_double_N$N\_M$M.txt files/trans_float_N$N\_M$M.txt files/trans_int_N$N\_M$M.txt
ok_matrix "cmp files/out_dble_sum2_N$N\_M$M.txt files/dble_sum2_N$N\_M$M.txt" files/out_dble_sum2_N$N\_M$M.txt files/dble_sum2_N$N\_M$M.txt
ok_matrix "cmp files/out_dble_sum_N$N\_M$M.txt files/dble_sum_N$N\_M$M.txt" files/out_dble_sum_N$N\_M$M.txt files/dble_sum_N$N\_M$M.txt
ok_matrix "cmp files/out_cpy_N$N\_M$M.txt files/data_N$N\_M$M.txt" files/out_cpy_N$N\_M$M.txt files/data_N$N\_M$M.txt
ok_matrix "cmp files/trans_N$N\_M$M.txt files/trans_double_N$N\_M$M.txt" files/trans_double_N$N\_M$M.txt files/trans_N$N\_M$M.txt
ok_matrix "cmp files/trans_N$N\_M$M.txt files/trans_float_N$N\_M$M.txt" files/trans_float_N$N\_M$M.txt files/trans_N$N\_M$M.txt
ok_matrix "cmp files/trans_N$N\_M$M.txt files/trans_int_N$N\_M$M.txt" files/trans_int_N$N\_M$M.txt files/trans_N$N\_M$M.txt

