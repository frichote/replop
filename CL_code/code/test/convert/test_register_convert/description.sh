#!/bin/sh
#
# by E. Frichot
#
# file: register_convert
#
# functions:
# 	analyse_param_convert
#
# command line:
#
# exec analyse_param_convert
#

. ../../meta.sh

ok_log "./test_register_convert" files/ref1.log
ok_log "./test_register_convert input.log" files/ref2.log
ok_log "./test_register_convert input.log output.log" files/ref3.log
ok_log "./test_register_convert input.log output.log tmp.log" files/ref4.log
