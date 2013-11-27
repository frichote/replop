#!/bin/sh

. ../meta.sh

# parameters
dir="cholesky data error inverse matrix normalize"

for i in $dir
do
	cd test_$i
	echo "$BLUE ###### file: test_$i ######" 
	sh test_file.sh
	cd ..
done
