#!/bin/sh
#
# by E. Frichot
#
# file: print_snmf
#
# functions:
# 	print_licence_snmf
# 	print_head_licence_snmf
# 	print_head_snmf
#
# command line:
#
# exec print_licence_snmf
#
# exec print_head_licence_snmf
#
# exec print_head_snmf
#

. ../../meta.sh

ok_log "./test_print_snmf" files/ref1.log
ok_log "./test_print_snmf prout1 " files/ref2.log
ok_log "./test_print_snmf prout1 prout2" files/ref3.log

