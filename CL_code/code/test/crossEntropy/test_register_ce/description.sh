#!/bin/sh
#
# by E. Frichot
#
# file: register_ce
#
# functions:
# 	print_help_ce
# 	register_ce
# 	print_summary_ce
#
# command line:
#
# exec print_help_ce
# exec register_ce
# exec print_summary_ce
#

. ../../meta.sh
# OK
ok_log "./test_register_ce -x input_file.txt -K 3" files/test1.log
ok_log "./test_register_ce -h" files/test2.log
ok_log "./test_register_ce -x input_file.txt -K 3 -m 1 -q Q_file.txt -g G_file.txt -i I_file.txt" files/test3.log


# Error
ok_log "./test_register_ce " files/test4.log
ok_log "./test_register_ce -x " files/test5.log
ok_log "./test_register_ce -x input_file " files/test6.log

ok_log "./test_register_ce -x input_file -K 0" files/test7.log
ok_log "./test_register_ce -x input_file -K a" files/test8.log
ok_log "./test_register_ce -x input_file -K " files/test9.log

ok_log "./test_register_ce -x input_file -K 2 -m " files/test10.log
ok_log "./test_register_ce -x input_file -K 2 -m 0" files/test11.log
ok_log "./test_register_ce -x input_file -K 2 -m -1" files/test12.log
ok_log "./test_register_ce -x input_file -K 2 -m a" files/test13.log

ok_log "./test_register_ce -x input_file -K 2 -q " files/test14.log
ok_log "./test_register_ce -x input_file -K 2 -g " files/test15.log
ok_log "./test_register_ce -x input_file -K 2 -i " files/test16.log
