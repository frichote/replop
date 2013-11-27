#!/bin/sh
#
# by E. Frichot
#
# file: print_bar
#
# functions:
# 	init_bar
# 	print_bar
#
# command line:
#
# exec init_bar
#
# exec print_bar
#

. ../../meta.sh

ok_log "./test_print_bar 1" files/ref.log
ok_log "./test_print_bar 10" files/ref.log
ok_log "./test_print_bar 74" files/ref.log
ok_log "./test_print_bar 75" files/ref.log
ok_log "./test_print_bar 76" files/ref.log
ok_log "./test_print_bar 1000" files/ref.log
