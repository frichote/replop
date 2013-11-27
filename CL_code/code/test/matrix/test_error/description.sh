#!/bin/sh
#
# by E. Frichot
#
# file: error
#
# functions:
# 	print_error_global
#
# command line:
# ./test_print_error_global
#
# exec print_error_global
#

. ../../meta.sh

./test_error open test.txt 10 > files/out_open.txt
log "./test_error open test.txt 10 > files/out_open.txt" files/out_open.txt files/ref_open.txt
./test_error read test.txt 10 > files/out_read.txt
log "./test_error read test.txt 10 > files/out_read.txt" files/out_read.txt files/ref_read.txt
./test_error interne test.txt 10 > files/out_interne.txt
log "./test_error interne test.txt 10 > files/out_interne.txt" files/out_interne.txt files/ref_interne.txt
./test_error constant test.txt 10 > files/out_constant.txt
log "./test_error constant test.txt 10 > files/out_constant.txt" files/out_constant.txt files/ref_constant.txt
./test_error nan test.txt 10 > files/out_nan.txt
log "./test_error nan test.txt 10 > files/out_nan.txt" files/out_nan.txt files/ref_nan.txt
./test_error autre test.txt 10 > files/out_autre.txt
log "./test_error autre test.txt 10 > files/out_autre.txt" files/out_autre.txt files/ref_autre.txt

