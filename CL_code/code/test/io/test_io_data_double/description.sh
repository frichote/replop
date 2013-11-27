#!/bin/sh
#
# by E. Frichot
#
# file: io_data_double
#
# functions:
# 	read_data_double
# 	write_data_double
# 	print_data_double
#
# command line:
# ./test_io_data_double input N M output
#
# exec read_data_double
# exec write_data_double
# exec print_data_double
#

. ../../meta.sh

N=10;M=100;
./test_io_data_double files/N$N\_M$M.txt $N $M files/out_N$N\_M$M.txt > files/out_print_N$N\_M$M.txt
ok_matrix "./test_io_data_double files/N$N\_M$M.txt $N $M files/out_N$N\_M$M.txt" files/N$N\_M$M.txt files/out_N$N\_M$M.txt
ok_matrix "./test_io_data_double files/N$N\_M$M.txt $N $M files/out_N$N\_M$M.txt" files/N$N\_M$M.txt files/out_print_N$N\_M$M.txt

N=10;M=1;
./test_io_data_double files/N$N\_M$M.txt $N $M files/out_N$N\_M$M.txt > files/out_print_N$N\_M$M.txt
ok_matrix "./test_io_data_double files/N$N\_M$M.txt $N $M files/out_N$N\_M$M.txt" files/N$N\_M$M.txt files/out_N$N\_M$M.txt
ok_matrix "./test_io_data_double files/N$N\_M$M.txt $N $M files/out_N$N\_M$M.txt" files/N$N\_M$M.txt files/out_print_N$N\_M$M.txt

N=1;M=1000;
./test_io_data_double files/N$N\_M$M.txt $N $M files/out_N$N\_M$M.txt > files/out_print_N$N\_M$M.txt
ok_matrix "./test_io_data_double files/N$N\_M$M.txt $N $M files/out_N$N\_M$M.txt" files/N$N\_M$M.txt files/out_N$N\_M$M.txt
ok_matrix "./test_io_data_double files/N$N\_M$M.txt $N $M files/out_N$N\_M$M.txt" files/N$N\_M$M.txt files/out_print_N$N\_M$M.txt

N=1;M=1;
./test_io_data_double files/N$N\_M$M.txt $N $M files/out_N$N\_M$M.txt > files/out_print_N$N\_M$M.txt
ok_matrix "./test_io_data_double files/N$N\_M$M.txt $N $M files/out_N$N\_M$M.txt" files/N$N\_M$M.txt files/out_N$N\_M$M.txt
ok_matrix "./test_io_data_double files/N$N\_M$M.txt $N $M files/out_N$N\_M$M.txt" files/N$N\_M$M.txt files/out_print_N$N\_M$M.txt

./test_io_data_double files/factors.txt 6 21 files/out_factors.txt > files/out_print_factors.txt
ok_matrix "./test_io_data_double files/factors.txt" files/factors.txt files/out_factors.txt
ok_matrix "./test_io_data_double files/factors.txt" files/factors.txt files/out_print_factors.txt

# Error: input file do not exist
ok_log "./test_io_data_double donotexist.txt 1 1 output.geno" files/ref_donotexist.log

# Error: number of lines
ok_log "./test_io_data_double files/N10_M100.txt 9 100 output.txt" files/ref_l9.log
ok_log "./test_io_data_double files/N10_M100.txt 11 100 output.txt" files/ref_l11.log

# Error: number of lines
ok_log "./test_io_data_double files/N10_M100_l1-99.txt 10 100 output.txt" files/ref_l1-99.log
ok_log "./test_io_data_double files/N10_M100_l1-101.txt 10 100 output.txt" files/ref_l1-101.log
ok_log "./test_io_data_double files/N10_M100_l5-99.txt 10 100 output.txt" files/ref_l5-99.log
ok_log "./test_io_data_double files/N10_M100_l5-101.txt 10 100 output.txt" files/ref_l5-101.log
ok_log "./test_io_data_double files/N10_M100_l10-99.txt 10 100 output.txt" files/ref_l10-99.log
ok_log "./test_io_data_double files/N10_M100_l10-101.txt 10 100 output.txt" files/ref_l10-101.log


