#!/bin/sh

. ../meta.sh

# parameters
dir="als_F als_Q criteria error_nmf register_snmf print_snmf"

for i in $dir
do
	cd test_$i
	echo "$BLUE ###### file: test_$i ######" 
	sh test_file.sh
	cd ..
done
