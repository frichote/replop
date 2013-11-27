#!/bin/sh
#
# by E. Frichot
#
# file: main_lfmm2geno
#
# functions:
# 	main
#
# command line:
#
# exec main
#

. ../../meta.sh

cmd="../../../bin/lfmm2geno files/N10_M1000.lfmm"
ok_log "$cmd" ref_log.txt
ok_valgrind "$cmd"

