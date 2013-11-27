#!/bin/sh
#
# by E. Frichot
#
# file: main_geno2lfmm
#
# functions:
# 	main
#
# command line:
#
# exec main
#

. ../../meta.sh

cmd="../../../bin/geno2lfmm files/N10_M1000.geno"
ok_log "$cmd" ref_log.txt
ok_valgrind "$cmd"

