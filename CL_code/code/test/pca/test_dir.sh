#!/bin/sh

. ../meta.sh

# parameters
dir=""

for i in $dir
do
	cd test_$i
	echo "$BLUE ###### file: test_$i ######\n" 
	sh test_file.sh
	cd ..
done
