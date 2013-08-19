#!/bin/sh

cd code
make clean
make
if [ ! -e "LFMM" ]; then
        echo "\nERROR: an error occured during the compilation of LFMM command-line program."
	cd ..
	exit 1
fi
cd ..

# Error a ne pas oublier.
cp code_GUI/LFMM_GUI ./ 2> tmp.txt
cp code_GUI/LFMM_GUI.app/Contents/MacOS/LFMM_GUI ./ 2> tmp.txt
rm tmp.txt
if [ ! -e "LFMM_GUI" ]; then
        echo "\nERROR: an error occured during the creation of LFMM GUI program."
	exit 1
fi
chmod +x LFMM_GUI
echo "\nSUCCESS: LFMM GUI program was created without error."
exit 0

