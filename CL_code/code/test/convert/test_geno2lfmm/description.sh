#!/bin/sh
#
# by E. Frichot
#
# file: geno2lfmm
#
# functions:
# 	geno2lfmm
#
# ./test_geno2lfmm input_file N M output_file
#
# exec geno2lfmm

. ../../meta.sh


# correct
N=10;M=100;
ok "./test_geno2lfmm files/N$N\_M$M.geno $N $M files/out_N$N\_M$M.lfmm" files/N$N\_M$M.lfmm files/out_N$N\_M$M.lfmm

N=10;M=1;
ok "./test_geno2lfmm files/N$N\_M$M.geno $N $M files/out_N$N\_M$M.lfmm" files/N$N\_M$M.lfmm files/out_N$N\_M$M.lfmm 

N=1;M=1000;
ok "./test_geno2lfmm files/N$N\_M$M.geno $N $M files/out_N$N\_M$M.lfmm" files/N$N\_M$M.lfmm files/out_N$N\_M$M.lfmm 

N=1;M=1;
ok "./test_geno2lfmm files/N$N\_M$M.geno $N $M files/out_N$N\_M$M.lfmm" files/N$N\_M$M.lfmm files/out_N$N\_M$M.lfmm 
