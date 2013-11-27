#k!/bin/sh
#
# by E. Frichot
#
# file: main_crossEntropy
#
# functions:
# 	main
#
# command line:
#
# exec main
#

. ../../meta.sh

ok_cl "../../../bin/createDataSet -g files/N10_M1000.geno -s 1"
ok_cl "../../../bin/sNMF -g files/N10_M1000_I.geno -s 1 -K 4"
cmd="../../../bin/crossEntropy -g files/N10_M1000.geno -K 4"
ok_cl "$cmd"
ok_valgrind "$cmd"


