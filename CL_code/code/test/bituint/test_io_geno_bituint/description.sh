#!/bin/sh
#
# by E. Frichot
#
# file: io_geno_bituint.h
#
# functions:
# 	write_geno_bituint
# 	read_geno_bituint
#	print_geno_bituint
#
# ./test_io_geno_bituint input_file N M nc output_file1 
#
. ../../meta.sh

# correct
N=10;M=100;nc=2;
ok_and_log "./test_io_geno_bituint files/N$N\_M$M\_nc$nc.geno $N $M $nc files/out_N$N\_M$M\_nc$nc.geno" files/N$N\_M$M\_nc$nc.geno files/out_N$N\_M$M\_nc$nc.geno 

N=10;M=100;nc=3;
ok_and_log "./test_io_geno_bituint files/N$N\_M$M\_nc$nc.geno $N $M $nc files/out_N$N\_M$M\_nc$nc.geno" files/N$N\_M$M\_nc$nc.geno files/out_N$N\_M$M\_nc$nc.geno 

N=10;M=100;nc=4;
ok_and_log "./test_io_geno_bituint files/N$N\_M$M\_nc$nc.geno $N $M $nc files/out_N$N\_M$M\_nc$nc.geno" files/N$N\_M$M\_nc$nc.geno files/out_N$N\_M$M\_nc$nc.geno 

N=10;M=1;nc=3;
ok_and_log "./test_io_geno_bituint files/N$N\_M$M\_nc$nc.geno $N $M $nc files/out_N$N\_M$M\_nc$nc.geno" files/N$N\_M$M\_nc$nc.geno files/out_N$N\_M$M\_nc$nc.geno 

N=1;M=1000;nc=3;
ok_and_log "./test_io_geno_bituint files/N$N\_M$M\_nc$nc.geno $N $M $nc files/out_N$N\_M$M\_nc$nc.geno" files/N$N\_M$M\_nc$nc.geno files/out_N$N\_M$M\_nc$nc.geno 

N=1;M=1;nc=3;
ok_and_log "./test_io_geno_bituint files/N$N\_M$M\_nc$nc.geno $N $M $nc files/out_N$N\_M$M\_nc$nc.geno" files/N$N\_M$M\_nc$nc.geno files/N$N\_M$M\_nc$nc.geno 

# not a 0,1,2 or 9
ok_log "./test_io_geno_bituint files/6.geno 1 1 2 files/out_6.geno" files/ref_out_6.log

# Error: input file do not exist
ok_log "./test_io_geno_bituint donotexist.txt 1 1 3 output.geno" files/ref_donotexist.log

# Error: number of columns
ok_log "./test_io_geno_bituint files/N10_M100_l1-9.geno 10 100 3 output.geno" files/ref_l1-9.log
ok_log "./test_io_geno_bituint files/N10_M100_l1-11.geno 10 100 3 output.geno" files/ref_l1-11.log
ok_log "./test_io_geno_bituint files/N10_M100_l50-9.geno 10 100 3 output.geno" files/ref_l50-9.log
ok_log "./test_io_geno_bituint files/N10_M100_l50-11.geno 10 100 3 output.geno" files/ref_l50-11.log
ok_log "./test_io_geno_bituint files/N10_M100_l100-9.geno 10 100 3 output.geno" files/ref_l100-9.log
ok_log "./test_io_geno_bituint files/N10_M100_l100-11.geno 10 100 3 output.geno" files/ref_l100-11.log

# Error: number of lines
ok_log "./test_io_geno_bituint files/N10_M100_nc3.geno 10 99 3 output.geno" files/ref_l99.log
ok_log "./test_io_geno_bituint files/N10_M100_nc3.geno 10 101 3 output.geno" files/ref_l101.log
