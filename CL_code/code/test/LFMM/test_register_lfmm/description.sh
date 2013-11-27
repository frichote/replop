#!/bin/sh
#
# by E. Frichot
#
# file: register_lfmm
#
# functions:
# 	print_summary_lfmm
# 	analyse_param_lfmm
#
# command line:
#
# exec print_summary_lfmm
#
# exec analyse_param_lfmm
#

. ../../meta.sh

# ok
ok_log "./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10" files/ref1.log
ok_log "./test_register_lfmm -h" files/ref2.log
ok_log "./test_register_lfmm -l" files/ref2a.log
ok_log "./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -o output -m  -p 1 -i 1000 -b 100 -d 1 -C dic.txt -s 2" files/ref2b.log
ok_log "./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -o output -m  -p 1 -i 1000 -b 100 -a -C dic.txt -s 2" files/ref2c.log

# error
ok_log "./test_register_lfmm -" files/ref3.log
ok_log "./test_register_lfmm -g " files/ref4.log
ok_log "./test_register_lfmm -g input_file.txt" files/ref5.log
ok_log "./test_register_lfmm -g input_file.txt -v" files/ref6.log
ok_log "./test_register_lfmm -g input_file.txt -v cov_file.txt" files/ref7.log
ok_log "./test_register_lfmm -g input_file.txt -v cov_file.txt -K" files/ref8.log
ok_log "./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -o" files/ref9.log
ok_log "./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -p" files/ref10.log
ok_log "./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -p 0" files/ref11.log
ok_log "./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -i" files/ref12.log
ok_log "./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -b" files/ref13.log
ok_log "./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -b 1000" files/ref14.log
ok_log "./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -d 1 -C dic.txt" files/ref15.log
ok_log "./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -C dic.txt" files/ref16.log

ok_log "./test_register_lfmm -g input_file.txt -L -v cov_file.txt -K 3" files/ref17.log
ok_log "./test_register_lfmm -g input_file.txt -L 1000 -v cov_file.txt -K 3" files/ref18.log
ok_log "./test_register_lfmm -g input_file.txt -n -v cov_file.txt -K 3" files/ref19.log
ok_log "./test_register_lfmm -g input_file.txt -n 1000 -v cov_file.txt -K 3" files/ref20.log
ok_log "./test_register_lfmm -g input_file.txt -D -v cov_file.txt -K 3" files/ref21.log
ok_log "./test_register_lfmm -g input_file.txt -D 10 -v cov_file.txt -K 3" files/ref22.log

ok_log "./test_register_lfmm -g input_file.txt -v cov_file.txt -K 10 -d 1 -a" files/ref23.log
