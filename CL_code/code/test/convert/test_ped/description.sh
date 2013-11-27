#!/bin/sh
#
# by E. Frichot
#
# file: ped
#
# functions:
# 	ped2geno
# 	ped2lfmm
# 	fill_line_ped
# 	read_ped
#
# command line:
# ./test_ped input N M output1 output2 output2
#
# exec ped2geno
#
# exec ped2lfmm
#
# exec fill_line_ped
#
# exec read_ped
#

. ../../meta.sh

# A C T G
N=5;M=7;
ok_cl "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.geno files/N$N\_M$M.geno	
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.lfmm files/N$N\_M$M.lfmm	
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out2_N$N\_M$M.lfmm files/N$N\_M$M.lfmm	

# 1 2 3 4
N=5;M=7;
ok_cl "./test_ped files/N$N\_M$M-2.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.geno files/N$N\_M$M.geno	
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.lfmm files/N$N\_M$M.lfmm	
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out2_N$N\_M$M.lfmm files/N$N\_M$M.lfmm	

N=5; M=1;
ok_cl "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.geno files/N$N\_M$M.geno	
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.lfmm files/N$N\_M$M.lfmm	
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out2_N$N\_M$M.lfmm files/N$N\_M$M.lfmm	

N=1; M=7;
ok_cl "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.geno files/N$N\_M$M.geno	
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.lfmm files/N$N\_M$M.lfmm	
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out2_N$N\_M$M.lfmm files/N$N\_M$M.lfmm	

N=1; M=1;
ok_cl "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.geno files/N$N\_M$M.geno	
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.lfmm files/N$N\_M$M.lfmm	
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out2_N$N\_M$M.lfmm files/N$N\_M$M.lfmm	

N=1; M=1;
ok_cl "./test_ped files/N$N\_M$M-9.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.geno files/N$N\_M$M-9.geno	
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.lfmm files/N$N\_M$M-9.lfmm	
log "./test_ped files/N$N\_M$M.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out2_N$N\_M$M.lfmm files/N$N\_M$M-9.lfmm	

# error

N=5; M=7;
# not A, C, T, G, 0, 1, 2, 3, 4
ok_log "./test_ped files/6.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"  files/ref_out_6.log

# error input file
ok_log "./test_ped files/donotexist.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"  files/donotexist.log

# error: number of columns
ok_log "./test_ped files/N5_M7_l1-6.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"  files/ref_l1-6.log
ok_log "./test_ped files/N5_M7_l1-7.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"  files/ref_l1-7.log
ok_log "./test_ped files/N5_M7_l1-8.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"  files/ref_l1-8.log
ok_log "./test_ped files/N5_M7_l3-6.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"  files/ref_l3-6.log
ok_log "./test_ped files/N5_M7_l3-7.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"  files/ref_l3-7.log
ok_log "./test_ped files/N5_M7_l3-8.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"  files/ref_l3-8.log
ok_log "./test_ped files/N5_M7_l5-6.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"  files/ref_l5-6.log
ok_log "./test_ped files/N5_M7_l5-7.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"  files/ref_l5-7.log
ok_log "./test_ped files/N5_M7_l5-8.ped $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"  files/ref_l5-8.log


# Error: number of lines
ok_log "./test_ped files/N5\_M7.ped 4 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm"  files/ref_l4.log
ok_log "./test_ped files/N5\_M7.ped 6 7 files/out2_N5\_M7.lfmm files/out_N5\_M7.geno files/out_N5\_M7.lfmm"  files/ref_l6.log
