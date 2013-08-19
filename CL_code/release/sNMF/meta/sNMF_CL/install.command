#!/bin/sh

VERT="\\033[1;32m" NORMAL="\\033[0;39m" 
ROUGE="\\033[1;31m" JAUNE="\\033[1;33m"

cd code

make clean
make

if [ ! -e "sNMF" ]; then
	echo "$ROUGE" "\n ERROR: an error occured during the compilation of sNMF command-line program." "$NORMAL"
	cd ../../
	exit 1
elif [ ! -e "crossEntropy" ]; then
  	echo "$ROUGE" "\n ERROR: an error occured during the compilation of crossEntropy command-line program." "$NORMAL"
        cd ../../
        exit 1
elif [ ! -e "createDataSet" ]; then
  	echo "$ROUGE" "\n ERROR: an error occured during the compilation of createDataSet command-line program." "$NORMAL"
        cd ../../
        exit 1
else
	mv sNMF crossEntropy createDataSet ../bin/
fi
cd ..

echo "$VERT" "\n SUCCESS: sNMF command-line program was compiled without error." "$NORMAL"
exit 0

