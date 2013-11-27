#!/bin/sh
#
# by E. Frichot
#
# file: error_ce
#
# functions:
# 	error_ce
#
# command line:
#
# exec error_ce
#

. ../../meta.sh


ok_log "./test_error_ce cmd test.txt" files/ref1.log
ok_log "./test_error_ce option \"-g (genotype_file)\" " files/ref2.log
ok_log "./test_error_ce missing test.txt" files/ref3.log
ok_log "./test_error_ce basic test.txt" files/ref4.log
ok_log "./test_error_ce specific \"specific message \!\"" files/ref5.log
ok_log "./test_error_ce autre test.txt" files/ref6.log

