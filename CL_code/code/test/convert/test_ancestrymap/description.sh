#!/bin/sh
#
# by E. Frichot
#
# file: ancestrymap
#
# functions:
#       nb_ind_ancestrymap
#	read_ancestrymap
#	ancestrymap2geno
#	ancestrymap2lfmm
#
# ./test_ancestrymap input N M output1 output2 output3
#
# exec lfmm2geno

# correct

. ../../meta.sh

N=10;M=100;
ok_cl "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"
log "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.geno files/N$N\_M$M.geno
log "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.lfmm files/N$N\_M$M.lfmm
log "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out2_N$N\_M$M.lfmm files/N$N\_M$M.lfmm

N=10;M=1;
ok_cl "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"
log "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.geno files/N$N\_M$M.geno
log "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.lfmm files/N$N\_M$M.lfmm
log "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out2_N$N\_M$M.lfmm files/N$N\_M$M.lfmm

N=1;M=1000;
ok_cl "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"
log "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.geno files/N$N\_M$M.geno
log "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.lfmm files/N$N\_M$M.lfmm
log "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out2_N$N\_M$M.lfmm files/N$N\_M$M.lfmm

N=1;M=1;
ok_cl "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm"
log "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.geno files/N$N\_M$M.geno
log "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out_N$N\_M$M.lfmm files/N$N\_M$M.lfmm
log "./test_ancestrymap files/N$N\_M$M.ancestrymap $N $M files/out2_N$N\_M$M.lfmm files/out_N$N\_M$M.geno files/out_N$N\_M$M.lfmm" files/out2_N$N\_M$M.lfmm files/N$N\_M$M.lfmm

# not a 0,1,2 or 9
ok_log "./test_ancestrymap files/6.ancestrymap 1 1 files/out2_6.lfmm files/out_6.geno files/out_6.lfmm" files/ref_6.log

# Error: input file do not exist
ok_log "./test_ancestrymap files/donotexist.ancestrymap 1 1 files/out2.lfmm files/out.geno files/out.lfmm" files/ref_donotexist.log

# Error: number of columns
ok_log "./test_ancestrymap files/N10_M100_l1-9.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm" files/ref_l1-9.log
ok_log "./test_ancestrymap files/N10_M100_l1-11.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm" files/ref_l1-11.log
ok_log "./test_ancestrymap files/N10_M100_l50-9.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm" files/ref_l50-9.log
ok_log "./test_ancestrymap files/N10_M100_l50-11.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm" files/ref_l50-11.log
ok_log "./test_ancestrymap files/N10_M100_l100-9.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm" files/ref_l100-9.log
ok_log "./test_ancestrymap files/N10_M100_l100-11.ancestrymap 10 100 files/out2.lfmm files/out.geno files/out.lfmm" files/ref_l100-11.log

# Error: number of lines
ok_log "./test_ancestrymap files/N10_M100.ancestrymap 10 99 files/out2.lfmm files/out.geno files/out.lfmm" files/ref_l99.log
ok_log "./test_ancestrymap files/N10_M100.ancestrymap 10 101 files/out2.lfmm files/out.geno files/out.lfmm" files/ref_l101.log

