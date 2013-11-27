#!/bin/sh
#
# by E. Frichot
#
# file: U
#
# functions:
# 	create_m_U
# 	create_inv_cov_U
#
# command line:
# ./test_U input_R input_B input_V input_C N M D K output_m_U1 output_m_U2
# output_inv_cov_U1 output_inv_cov_U2
#
# exec create_m_U
# exec create_inv_cov_U
#

. ../../meta.sh

N=10;M=100;
./test_U files/R.txt files/B.txt files/V.txt files/C.txt $N $M files/D.txt files/K.txt files/out_m_U1.txt files/out_m_U2.txt files/out_inv_cov_U1.txt files/out_inv_cov_U2.txt

ok_matrix "./test_U" files/ref_m_U.txt files/out_m_U1.txt
ok_matrix "./test_U" files/ref_m_U.txt files/out_m_U2.txt
ok_matrix "./test_U" files/ref_inv_cov_U.txt files/out_inv_cov_U1.txt
ok_matrix "./test_U" files/ref_inv_cov_U.txt files/out_inv_cov_U2.txt

