#!/bin/sh
#
# by E. Frichot
#
# file: error_nmf
#
# functions:
# 	print_error_nmf
#
# command line:
#
# exec print_error_nmf
#

. ../../meta.sh

ok_log "./test_error_nmf cmd test.txt 0"  files/ref1.log
ok_log "./test_error_nmf option '-g (...)' 0"  files/ref2.log
ok_log "./test_error_nmf missing test.txt 0"  files/ref3.log
ok_log "./test_error_nmf basic test.txt 0"  files/ref4.log
ok_log "./test_error_nmf specific 'Specific message \!' 0"  files/ref5.log
ok_log "./test_error_nmf autre test.txt 0"  files/ref6.log

