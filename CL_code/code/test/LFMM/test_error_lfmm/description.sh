#!/bin/sh
#
# by E. Frichot
#
# file: error_lfmm
#
# functions:
# 	print_error_lfmm
#
# command line:
# ./test_error_lfmm msg file n
#
# exec print_error_lfmm
#

. ../../meta.sh

ok_log "./test_error_lfmm cmd test.txt 0"  files/ref1.log
ok_log "./test_error_lfmm option '-g (...)' 0"  files/ref2.log
ok_log "./test_error_lfmm missing test.txt 0"  files/ref3.log
ok_log "./test_error_lfmm basic test.txt 0"  files/ref4.log
ok_log "./test_error_lfmm specific 'Specific message \!' 0"  files/ref5.log
ok_log "./test_error_lfmm autre test.txt 0"  files/ref6.log
