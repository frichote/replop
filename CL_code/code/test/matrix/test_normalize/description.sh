#!/bin/sh
#
# by E. Frichot
#
# file: normalize
#
# functions:
# 	normalize_cov
# 	normalize_lines
#
# command line:
# ./test_normalize input N M out1 out2 out3 out4
#
# exec normalize_cov
# exec normalize_lines
#

. ../../meta.sh

N=10; M=100;
ok_cl "./test_normalize  files/data_N$N\_M$M.txt $N $M files/out_cov_N$N\_M$M.txt files/out_norm_N$N\_M$M.txt files/out2_cov_N$N\_M$M.txt files/out_mean_N$N\_M$M.txt" 
ok_matrix "cmp files/out_cov_N$N\_M$M.txt files/cov_N$N\_M$M.txt" files/out_cov_N$N\_M$M.txt files/cov_N$N\_M$M.txt
ok_matrix "cmp files/out2_cov_N$N\_M$M.txt files/cov_N$N\_M$M.txt" files/out2_cov_N$N\_M$M.txt files/cov_N$N\_M$M.txt
ok_matrix "cmp files/out_norm_N$N\_M$M.txt files/norm_N$N\_M$M.txt" files/out_norm_N$N\_M$M.txt files/norm_N$N\_M$M.txt
ok_matrix "cmp files/out_mean_N$N\_M$M.txt files/mean_N$N\_M$M.txt" files/out_mean_N$N\_M$M.txt files/mean_N$N\_M$M.txt

N=10; M=1;
ok_cl "./test_normalize  files/data_N$N\_M$M.txt $N $M files/out_cov_N$N\_M$M.txt files/out_norm_N$N\_M$M.txt files/out2_cov_N$N\_M$M.txt files/out_mean_N$N\_M$M.txt" 
ok_matrix "cmp files/out_cov_N$N\_M$M.txt files/cov_N$N\_M$M.txt" files/out_cov_N$N\_M$M.txt files/cov_N$N\_M$M.txt
ok_matrix "cmp files/out2_cov_N$N\_M$M.txt files/cov_N$N\_M$M.txt" files/out2_cov_N$N\_M$M.txt files/cov_N$N\_M$M.txt
ok_matrix "cmp files/out_norm_N$N\_M$M.txt files/norm_N$N\_M$M.txt" files/out_norm_N$N\_M$M.txt files/norm_N$N\_M$M.txt
ok_matrix "cmp files/out_mean_N$N\_M$M.txt files/mean_N$N\_M$M.txt" files/out_mean_N$N\_M$M.txt files/mean_N$N\_M$M.txt

