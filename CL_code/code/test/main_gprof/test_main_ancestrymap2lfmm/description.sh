#!/bin/sh
#
# by E. Frichot
#
# file: main_ancestrymap2lfmm
#
# functions:
# 	main
#
# command line:
#
# exec main
#

. ../../meta.sh

cmd="../../../bin/ancestrymap2lfmm files/N100_M10000.ancestrymap"
ok_main "$cmd" files/ref_main.txt ../../../bin/ancestrymap2lfmm

