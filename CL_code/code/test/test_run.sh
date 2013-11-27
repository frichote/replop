#!/bin/sh

. ./meta.sh

# parameters
dir="bituint convert createDataSet crossEntropy io LFMM main matrix nnlsm pca sNMF"

for d in $dir
do
	cd $d
#	echo "$PURPLE ###########################
#    directory: $d 
# ###########################
#$NORMAL "
	sh test_dir.sh > test_$d.res 2>&1
	cd ..
done

