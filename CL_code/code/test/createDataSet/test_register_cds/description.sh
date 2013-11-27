#!/bin/sh
#
# by E. Frichot
#
# file: register_cds, print_cds
#
# functions:
# 	print_help_cds
# 	register_cds
# 	print_summary_cds
#
# command line: ./test_register_cds args
#

. ../../meta.sh

# exec register_cds_cds
# ok
ok_log "./test_register_cds -g input_file.txt" files/test1.log
ok_log "./test_register_cds -h" files/test2.log
ok_log "./test_register_cds -g input_file.txt -m 1 -s 10 -r 0.05" files/test3.log
ok_log "./test_register_cds -g input_file.txt -m 2 -s 10 -r 0.05" files/test4.log
ok_log "./test_register_cds -g input_file.txt -m 3 -s 10 -r 0.05" files/test5.log
ok_log "./test_register_cds -g input_file.txt -o output.txt" files/test6.log

# error
ok_log "./test_register_cds " files/test7.log

ok_log "./test_register_cds -g " files/test8.log

ok_log "./test_register_cds -g input_file.txt -m 0 " files/test9.log
ok_log "./test_register_cds -g input_file.txt -m -1" files/test10.log
ok_log "./test_register_cds -g input_file.txt -m a" files/test11.log
ok_log "./test_register_cds -g input_file.txt -m" files/test12.log

ok_log "./test_register_cds -g input_file.txt -s -1" files/test13.log
ok_log "./test_register_cds -g input_file.txt -s" files/test15.log

ok_log "./test_register_cds -g input_file.txt -r 0 " files/test16.log
ok_log "./test_register_cds -g input_file.txt -r 1 " files/test17.log
ok_log "./test_register_cds -g input_file.txt -r -1" files/test18.log
ok_log "./test_register_cds -g input_file.txt -r a" files/test19.log
ok_log "./test_register_cds -g input_file.txt -r" files/test20.log


