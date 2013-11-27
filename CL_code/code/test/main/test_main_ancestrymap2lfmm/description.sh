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

cmd="../../../bin/ancestrymap2lfmm files/N10_M1000.ancestrymap"
ok_log "$cmd" ref_log.txt
ok_valgrind "$cmd"


