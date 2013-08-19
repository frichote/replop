#!/bin/sh

cd code

make clean
make

cd bin 
if [ ! -e "sNMF" ]; then
	echo "\n ERROR: an error occured during the compilation of sNMF command-line program."
	cd ../../
	exit 1
elif [ ! -e "LFMM" ]; then
  	echo "\n ERROR: an error occured during the compilation of LFMM command-line program."
        cd ../../
        exit 1
elif [ ! -e "crossEntropy" ]; then
  	echo "\n ERROR: an error occured during the compilation of crossEntropy command-line program."
        cd ../../
        exit 1
elif [ ! -e "createDataSet" ]; then
  	echo "\n ERROR: an error occured during the compilation of createDataSet command-line program."
        cd ../../
        exit 1
fi
cd ../..

echo "\n SUCCESS: All command-line programs were compiled without error."
exit 0

