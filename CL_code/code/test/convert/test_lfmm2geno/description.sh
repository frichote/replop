#!/bin/sh
#
# by E. Frichot
#
# file: lfmm2geno
#
# functions:
#       lfmm2geno
#
# ./test_lfmm2geno input_file N M output_file
#
# exec lfmm2geno

# correct

. ../../meta.sh

N=10;M=100;
ok "./test_lfmm2geno files/N$N\_M$M.lfmm $N $M files/out_N$N\_M$M.geno" files/N$N\_M$M.geno files/out_N$N\_M$M.geno

N=10;M=1;
ok "./test_lfmm2geno files/N$N\_M$M.lfmm $N $M files/out_N$N\_M$M.geno" files/N$N\_M$M.geno files/out_N$N\_M$M.geno

N=1;M=1000;
ok "./test_lfmm2geno files/N$N\_M$M.lfmm $N $M files/out_N$N\_M$M.geno" files/N$N\_M$M.geno files/out_N$N\_M$M.geno

N=1;M=1;
ok "./test_lfmm2geno files/N$N\_M$M.lfmm $N $M files/out_N$N\_M$M.geno" files/N$N\_M$M.geno files/out_N$N\_M$M.geno


