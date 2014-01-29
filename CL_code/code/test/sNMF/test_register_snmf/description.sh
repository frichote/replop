#!/bin/sh
#
# by E. Frichot
#
# file: register_snmf
#
# functions:
# 	analyze_param_snmf
#
# command line:
# ./test_register_snmf argv
#
# exec analyze_param_snmf
#

. ../../meta.sh

ok_log "./test_register_snmf -x input_file.txt -K 10"  files/ref1.log
ok_log "./test_register_snmf -h"  files/ref2.log
ok_log "./test_register_snmf -l"  files/ref3.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -a 100 -c 0.01 -e 0.1 -i 100 -s 2 -m 2 -p 2 -q output.Q -g output.G -I " files/ref4.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -a 100 -c 0.01 -e 0.1 -i 100 -s 2 -m 2 -p 2 -q output.Q -Q inputQ -I 1000" files/ref4a.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -a 100 -c -e 0.1 -i 100 -s 2 -m 2 -p 2 -q output.Q -g output.G -Q input.Q" files/ref4b.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -m 1"  files/ref5.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -m 2"  files/ref6.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -m 3"  files/ref7.log

# error
ok_log "./test_register_snmf -"  files/ref8.log
ok_log "./test_register_snmf -x"  files/ref9.log
ok_log "./test_register_snmf -x input_file.txt"  files/ref10.log
ok_log "./test_register_snmf -x input_file.txt -K"  files/ref11.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -a "  files/ref12.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -a -1"  files/ref13.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -c -1"  files/ref14.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -c 0"  files/ref15.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -c "  files/ref16.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -c 1"  files/ref17.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -e "  files/ref18.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -e 0"  files/ref19.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -e -1"  files/ref20.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -i 0"  files/ref21.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -i "  files/ref22.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -i -1"  files/ref23.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -s"  files/ref24.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -s -1"  files/ref25.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -m"  files/ref26.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -m 0"  files/ref27.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -p"  files/ref28.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -p 0"  files/ref29.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -q "  files/ref30.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -g "  files/ref31.log
ok_log "./test_register_snmf -x input_file.txt -K 10 -Q "  files/ref32.log
