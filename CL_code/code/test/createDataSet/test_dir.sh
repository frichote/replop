#!/bin/sh

. ../meta.sh

# parameters
dir="error_cds register_cds"

for i in $dir
do
	cd test_$i
	echo "$BLUE ###### file: test_$i ######" 
	sh test_file.sh
	cd ..
done
