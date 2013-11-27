#!/bin/sh
#
# by E. Frichot
#
# file: inverse
#
# functions:
# 	fast_inverse
# 	detrm
# 	trans
#
# command line:
# ./test_inverse input N output1 output2 output3
#
# exec fast_inverse
#
# exec detrm
#
# exec trans
#

. ../../meta.sh

N=10;
./test_inverse data_N$N.txt $N out_inv1_N$N.txt out_det_N$N.txt out_inv2_N$N.txt
ok_matrix "cmp inv_N$N.txt out_inv1_N$N.txt" inv_N$N.txt out_inv1_N$N.txt 
# ok_matrix "cmp inv_N$N.txt out_inv2_N$N.txt" inv_N$N.txt out_inv2_N$N.txt 
ok_matrix "cmp det_N$N.txt out_det_N$N.txt" det_N$N.txt out_det_N$N.txt 

N=1;
./test_inverse data_N$N.txt $N out_inv1_N$N.txt out_det_N$N.txt out_inv2_N$N.txt
ok_matrix "cmp inv_N$N.txt out_inv1_N$N.txt" inv_N$N.txt out_inv1_N$N.txt 
# ok_matrix "cmp inv_N$N.txt out_inv2_N$N.txt" inv_N$N.txt out_inv2_N$N.txt 
ok_matrix "cmp det_N$N.txt out_det_N$N.txt" det_N$N.txt out_det_N$N.txt 
