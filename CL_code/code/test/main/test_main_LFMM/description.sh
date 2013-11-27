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

cmd="../../../bin/LFMM -g files/N10_M100.lfmm -v files/N10_M100.env -m -s 1 -a -K 4"
ok_cl "$cmd"
ok_valgrind "$cmd"

cmd="../../../bin/LFMM -g files/N10_M100.lfmm -v files/N10_M100.env -m -s 1 -K 4"
ok_cl "$cmd" 
ok_valgrind "$cmd"

