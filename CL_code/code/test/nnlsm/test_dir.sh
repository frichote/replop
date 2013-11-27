#!/bin/sh

. ../meta.sh

# parameters
#dir="blockpivot sort solvenormaleqcomb"
dir="sort"

for i in $dir
do
	cd test_$i
	echo "$BLUE ###### file: test_$i ######" 
	sh test_file.sh
	cd ..
done
