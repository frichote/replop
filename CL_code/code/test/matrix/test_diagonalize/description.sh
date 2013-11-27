#!/bin/sh
#
# by E. Frichot
#
# file: diagonalize
#
# functions:
# 	diagonalize
#
# command line:
#
# exec diagonalize
#

. ../../meta.sh

ok_cl "./test_diagonalize files/N10_K10.txt 10 10 files/out_val_N10_K10.txt files/out_vect_N10_K10.txt"
ok_matrix ".test_normalize val_N10_K10.txt" files/out_val_N10_K10.txt files/val_N10_K10.txt
ok_matrix ".test_normalize vect_N10_K10.txt" files/out_vect_N10_K10.txt files/vect_N10_K10.txt

ok_cl "./test_diagonalize files/N10_K2.txt 10 2 files/out_val_N10_K2.txt files/out_vect_N10_K2.txt"
ok_matrix ".test_normalize val_N10_K2.txt" files/out_val_N10_K2.txt files/val_N10_K2.txt
ok_matrix ".test_normalize vect_N10_K2.txt" files/out_vect_N10_K2.txt files/vect_N10_K2.txt
