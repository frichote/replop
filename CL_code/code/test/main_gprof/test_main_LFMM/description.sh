#!/bin/sh
#
# by E. Frichot
#
# file: main_LFMM
#
# functions:
# 	main
#
# command line:
#
# exec main
#

. ../../meta.sh

cmd="../../../bin/LFMM -g files/N100_M1000.lfmm -v files/N100_M1000.env -m -s 1 -a -K 4"
ok_main "$cmd" files/ref_main.txt ../../../bin/LFMM

