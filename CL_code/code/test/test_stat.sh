#!/bin/sh

. ./meta.sh

# parameters
dir="bituint convert createDataSet crossEntropy io LFMM main matrix nnlsm pca sNMF"

for d in $dir
do
	cd $d
	nb_ok=`grep -c "OK" test_$d.res`
	nb_fail=`grep -c "FAILED" test_$d.res`
	tot=`expr $nb_ok + $nb_fail`
	perc_ok=`expr $nb_ok \* 100`
	perc_ok=`expr $perc_ok / $tot 2> /dev/null`
	perc_fail=`expr 100 - $perc_ok 2> /dev/null`
	echo "\t $BLUE $d: \t $NORMAL OK $VERT $perc_ok% ($nb_ok) \t $NORMAL FAILED $ROUGE $perc_fail% ($nb_fail) $NORMAL"
	cd ..
done

