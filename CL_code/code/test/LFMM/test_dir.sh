#!/bin/sh

. ../meta.sh

# parameters
dir="beta error_lfmm register_lfmm U V data_lfmm lfmm"

for i in $dir
do
	cd test_$i
	echo "$BLUE ###### file: test_$i ######" 
	sh test_file.sh
	cd ..
done
