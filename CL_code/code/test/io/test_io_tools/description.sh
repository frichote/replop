#!/bin/sh
#
# by E. Frichot
#
# file: io_tools
#
# functions:
# 	remove_ext
# 	nb_lines
# 	nb_cols_geno
# 	nb_cols_lfmm
# 	fopen_read
# 	fopen_write
#
# command line:
# ./test_io_tools input1 input2 N M
#
# exec remove_ext
# exec nb_lines
# exec nb_cols_geno
# exec nb_cols_lfmm
# exec fopen_read
# exec fopen_write
#

. ../../meta.sh

ok_log './test_io_tools "fake.geno" "fake" 10 10' files/ref1.log

N=10;M=100;
ok_log "./test_io_tools files/N$N\_M$M.geno files/N$N\_M$M.lfmm $N $M" files/ref2.log

N=10;M=1;
ok_log "./test_io_tools files/N$N\_M$M.geno files/N$N\_M$M.lfmm $N $M" files/ref3.log
N=1;M=1000;
ok_log "./test_io_tools files/N$N\_M$M.geno files/N$N\_M$M.lfmm $N $M" files/ref4.log
N=1;M=1;
ok_log "./test_io_tools files/N$N\_M$M.geno files/N$N\_M$M.lfmm $N $M" files/ref5.log

ok_log "./test_io_tools NULL files/factors.txt 6 21" files/ref6.log

ok_log "./test_io_tools NULL files/N100_M1000.env 100 1" files/ref7.log
