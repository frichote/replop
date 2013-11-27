#!/bin/sh
#
# by E. Frichot
#
# file: beta
#
# functions:
# 	create_m_beta
# 	create_CCt
# 	create_inv_cov_beta
#
# command line:
# ./test_beta input_R input_U input_V input_C input_alpha_beta N M D K output_m_beta1 output_m_beta2 
# output_CCt output_inv_cov_beta
#
# exec create_m_beta
# exec create_CCt
# exec create_inv_cov_beta
#

. ../../meta.sh

N=10;M=100;
./test_beta files/R.txt files/U.txt files/V.txt files/C.txt files/alpha_beta.txt $N $M files/D.txt files/K.txt files/out_m_beta1.txt files/out_m_beta2.txt files/out_CCt.txt files/out_inv_cov_beta.txt

ok_matrix "./test_beta m_beta p 1" files/ref_m_beta.txt files/out_m_beta1.txt
ok_matrix "./test_beta m_beta p 2" files/ref_m_beta.txt files/out_m_beta2.txt
ok_matrix "./test_beta CCt" files/ref_CCt.txt files/out_CCt.txt
ok_matrix "./test_beta inv_cov_beta" files/ref_inv_cov_beta.txt files/out_inv_cov_beta.txt
