#!/bin/sh
#
# by E. Frichot
#
# file: V
#
# functions:
# 	create_m_V
# 	create_inv_cov_V
#
# command line:
# ./test_V input_R input_U input_B input_C N M D K output_m_V1 output_m_V2
# output_inv_cov_V1 output_inv_cov_V2
#
# exec create_m_V
# exec create_inv_cov_V
#

. ../../meta.sh

N=10;M=100;
./test_V files/R.txt files/U.txt files/B.txt files/C.txt $N $M files/D.txt files/K.txt files/out_m_V1.txt files/out_m_V2.txt files/out_inv_cov_V1.txt files/out_inv_cov_V2.txt

ok_matrix "./test_V" files/ref_m_V.txt files/out_m_V1.txt
ok_matrix "./test_V" files/ref_m_V.txt files/out_m_V2.txt
ok_matrix "./test_V" files/ref_inv_cov_V.txt files/out_inv_cov_V1.txt
ok_matrix "./test_V" files/ref_inv_cov_V.txt files/out_inv_cov_V2.txt

