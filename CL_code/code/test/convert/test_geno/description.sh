#!/bin/sh
#
# by E. Frichot
#
# file: geno
#
# functions:
# 	fill_line_geno
# 	write_geno
# 	read_geno
#
# ./test_geno input_file N M output_file
#
# exec fill_line_geno
# exec write_geno
# exec read_geno
. ../../meta.sh

# correct
N=10;M=100;
ok "./test_geno files/N$N\_M$M.geno $N $M files/out_N$N\_M$M.geno" files/N$N\_M$M.geno files/out_N$N\_M$M.geno 

N=10;M=1;
ok "./test_geno files/N$N\_M$M.geno $N $M files/out_N$N\_M$M.geno" files/N$N\_M$M.geno files/out_N$N\_M$M.geno 

N=1;M=1000;
ok "./test_geno files/N$N\_M$M.geno $N $M files/out_N$N\_M$M.geno" files/N$N\_M$M.geno files/out_N$N\_M$M.geno 

N=1;M=1;
ok "./test_geno files/N$N\_M$M.geno $N $M files/out_N$N\_M$M.geno" files/N$N\_M$M.geno files/out_N$N\_M$M.geno 

# not a 0,1,2 or 9
ok_log "./test_geno files/6.geno 1 1 files/out_6.geno" files/ref_out_6.log

# Error: input file do not exist
ok_log "./test_geno donotexist.txt 1 1 output.geno" files/ref_donotexist.log

# Error: number of columns
ok_log "./test_geno files/N10_M100_l1-9.geno 10 100 output.geno" files/ref_l1-9.log
ok_log "./test_geno files/N10_M100_l1-11.geno 10 100 output.geno" files/ref_l1-11.log
ok_log "./test_geno files/N10_M100_l50-9.geno 10 100 output.geno" files/ref_l50-9.log
ok_log "./test_geno files/N10_M100_l50-11.geno 10 100 output.geno" files/ref_l50-11.log
ok_log "./test_geno files/N10_M100_l100-9.geno 10 100 output.geno" files/ref_l100-9.log
ok_log "./test_geno files/N10_M100_l100-11.geno 10 100 output.geno" files/ref_l100-11.log

# Error: number of lines
ok_log "./test_geno files/N10_M100.geno 10 99 output.geno" files/ref_l99.log
ok_log "./test_geno files/N10_M100.geno 10 101 output.geno" files/ref_l101.log
