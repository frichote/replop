#!/bin/sh

. ../meta.sh

# parameters
dir="io_data_double io_data_float io_data_int io_error io_tools print_bar"

for i in $dir
do
	cd test_$i
	echo "$BLUE ###### file: test_$i ######" 
	sh test_file.sh
	cd ..
done
