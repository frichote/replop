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

cmd="../../../bin/createDataSet -g files/N100_M10000.geno"
ok_main "$cmd" files/ref_main.txt ../../../bin/createDataSet

