#!/bin/sh

# color definition
VERT="\\033[1;32m" NORMAL="\\033[0;39m" ROUGE="\\033[1;31m" JAUNE="\\033[1;33m"

cd code

make clean
make



if [ ! -e "LFMM" ]; then
	echo "$ROUGE" "\n ERROR: an error occured during the compilation of LFMM command-line program." "$NORMAL"
	cd ../../
	exit 1
else
	mv LFMM ../bin/
fi
cd ..

echo "$VERT" "\n SUCCESS: LFMM command-line program was compiled without error." "$NORMAL"
exit 0

