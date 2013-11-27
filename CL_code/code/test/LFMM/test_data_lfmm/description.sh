#!/bin/sh
#
# by E. Frichot
#
# file: data_lfmm
#
# functions:
# 	zscore_calc
# 	update_sum
# 	update_sum2
# 	update_mean
# 	modify_C
# 	write_DIC
# 	write_zscore_double
# 	var_data
# 	inputation_lfmm
#
# command line:
# ./test_data_lfmm input_sum input_sum2 input_beta input_R input_C input_U input_V input_I N D DIC zscore output_R output_sum output_sum2 output_mean
#
# exec zscore_calc
# exec update_sum
# exec update_sum2
# exec update_mean
# exec modify_C
# exec write_DIC
# exec write_zscore_double
# exec var_data
# exec inputation_lfmm
#

. ../../meta.sh

ok_cl "./test_data_lfmm files/sum.txt files/sum2.txt files/mean.txt files/B.txt files/R.txt files/C.txt files/U.txt files/V.txt files/I.txt 10 3 files/DIC.txt files/out_zscore1.txt files/out_zscore2.txt files/out_R.txt files/out_sum.txt files/out_sum2.txt files/out_mean.txt > files/out_dev_dic.txt"

ok_matrix "./test_data_lfmm" files/out_sum.txt files/ref_sum.txt
ok_matrix "./test_data_lfmm" files/out_sum2.txt files/ref_sum2.txt
ok_matrix "./test_data_lfmm" files/out_R.txt files/ref_R.txt
ok_matrix "./test_data_lfmm" files/out_mean.txt files/ref_mean.txt
ok_matrix "./test_data_lfmm" files/out_zscore1.txt_all_1.res files/ref_zscore1-1.txt
ok_matrix "./test_data_lfmm" files/out_zscore1.txt_all_2.res files/ref_zscore1-2.txt
ok_matrix "./test_data_lfmm" files/out_zscore2.txt_1.res files/ref_zscore1-1.txt
ok_matrix "./test_data_lfmm" files/out_dev_dic.txt files/DIC.txt
