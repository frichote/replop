#!/bin/sh

. ../meta.sh

# parameters
dir="ancestrymap geno geno2lfmm lfmm2geno ped register_convert" 

for i in $dir
do
	cd test_$i
	echo "$BLUE ###### file: test_$i ######" 
	sh test_file.sh
	cd ..
done
