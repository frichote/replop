#!/bin/sh
#
# by E. Frichot
#
# file: error_cds
#
# functions:
# 	print_error_cds
#
# command line:
#
# exec print_error_cds
#

. ../../meta.sh

ok_log "./test_error_cds cmd test.txt" files/ref1.log 
ok_log "./test_error_cds option \"-g (genotype_file)\" " files/ref2.log
ok_log "./test_error_cds missing test.txt" files/ref3.log
ok_log "./test_error_cds basic test.txt" files/ref4.log
ok_log "./test_error_cds specific \"specific message \!\"" files/ref5.log
ok_log "./test_error_cds autre test.txt" files/ref6.log

