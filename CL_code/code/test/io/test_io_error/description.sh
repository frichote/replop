#!/bin/sh
#
# by E. Frichot
#
# file: io_error
#
# functions:
# 	test_column
# 	test_line
#
# command line:
# ./test_io_error i1 i2 N token
#
# exec test_column
# exec test_line
#

. ../../meta.sh

ok_log "./test_io_error 9 10 10 0" files/ref1.log
ok_log "./test_io_error 11 10 10 0" files/ref2.log
ok_log "./test_io_error 10 9 10" files/ref3.log
ok_log "./test_io_error 10 11 10 0" files/ref4.log
ok_log "./test_io_error 10 10 10 0" files/ref5.log
ok_log "./test_io_error 10 10 10 a" files/ref6.log
