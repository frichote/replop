#!/bin/sh
#
# by E. Frichot
#
# file: main_ped2geno
#
# functions:
# 	main
#
# command line:
#
# exec main
#

. ../../meta.sh

cmd="../../../bin/ped2geno files/N5_M7.ped"
ok_log "$cmd" ref_log.txt
ok_valgrind "$cmd"
