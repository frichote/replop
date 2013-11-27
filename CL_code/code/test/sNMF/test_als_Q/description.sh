#!/bin/sh
#
# by E. Frichot
#
# file: als_Q
#
# functions:
# 	normalize_Q
# 	F_tF_alpha
# 	F_tX
#
# command line:
# ./test_als_Q input input_F N M K.txt alpha.txt 3 out_temp1_1 out_temp1_2 out_temp3_1 out_temp3_2
#
# exec F_tF_alpha
# exec F_tX
#

. ../../meta.sh

ok_cl "./test_als_Q files/R.txt files/F.txt 10 100 files/K.txt files/alpha.txt 3 files/out_temp1_1.txt files/out_temp1_2.txt files/out_temp3_1.txt files/out_temp3_2.txt"
ok_matrix "./test_als_Q" files/out_temp1_1.txt files/ref_temp1.txt
ok_matrix "./test_als_Q" files/out_temp1_2.txt files/ref_temp1.txt
ok_matrix "./test_als_Q" files/out_temp3_1.txt files/ref_temp3.txt
ok_matrix "./test_als_Q" files/out_temp3_2.txt files/ref_temp3.txt
