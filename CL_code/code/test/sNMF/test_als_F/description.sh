#!/bin/sh
#
# by E. Frichot
#
# file: als_F
#
# functions:
# 	update_F
# 	normalize_F
#
# command line:
# ./test_als_F input input_Q N M K.txt 3 output_F1 output_F2 normalize_F
#
# exec update_F
#
# exec normalize_F
#

. ../../meta.sh

ok_cl "./test_als_F files/R.txt files/Q.txt 10 100 files/K.txt 3 files/out_F1.txt files/out_F2.txt files/out_normalize_F.txt"
ok_matrix "./test_als_F" files/out_F1.txt files/ref_Fp.txt
ok_matrix "./test_als_F" files/out_F2.txt files/ref_Fp.txt
ok_matrix "./test_als_F" files/out_normalize_F.txt files/ref_normalize_Fp.txt
