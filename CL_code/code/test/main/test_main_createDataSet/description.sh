#!/bin/sh
#
# by E. Frichot
#
# file: main_createDataSet
#
# functions:
# 	main
#
# command line:
#
# exec main
#

. ../../meta.sh

cmd="../../../bin/createDataSet -g files/N10_M1000.geno -s 1"
ok_log "$cmd" ref_log.txt
ok_valgrind "$cmd"

