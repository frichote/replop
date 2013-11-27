#!/bin/sh

. ../meta.sh

# parameters
dir="io_geno_bituint"

for i in $dir
do
	cd test_$i
	echo "$BLUE ###### file: test_$i ######" 
	sh test_file.sh
	cd ..
done
