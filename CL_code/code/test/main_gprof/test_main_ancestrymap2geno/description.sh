#!/bin/sh
#
# by E. Frichot
#
# file: main_ancestrymap2geno
#
# functions:
# 	main
#
# command line:
#
# exec main
#

. ../../meta.sh

cmd="../../../bin/ancestrymap2geno files/N100_M10000.ancestrymap"
ok_main "$cmd" files/ref_main.txt ../../../bin/ancestrymap2geno

