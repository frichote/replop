#!/bin/sh
#
# by E. Frichot
#
# file: print_lfmm
#
# functions:
# 	print_licence_lfmm
# 	print_head_licence_lfmm
# 	print_head_lfmm
# 	print_help_lfmm
# 	print_options_lfmm
#
# command line:
# ./test_print_lfmm args
#
# exec print_licence_lfmm
#
# exec print_head_licence_lfmm
#
# exec print_head_lfmm
#
# exec print_help_lfmm
#
# exec print_options_lfmm
#

. ../../meta.sh

ok_log "./test_print_lfmm" files/ref1.log
ok_log "./test_print_lfmm prout1 " files/ref2.log
ok_log "./test_print_lfmm prout1 prout2" files/ref3.log
