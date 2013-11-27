#!/bin/sh
#
# by E. Frichot
#
# file: main_sNMF
#
# functions:
# 	main
#
# command line:
#
# exec main
#

. ../../meta.sh

cmd="../../../bin/sNMF -g files/N10_M1000.geno -c -K 5"
ok_main "$cmd" files/ref_main.txt ../../../bin/sNMF

