#!/bin/sh

. ../meta.sh

# parameters
dir="main_ancestrymap2geno main_ancestrymap2lfmm main_createDataSet main_crossEntropy main_geno2lfmm main_lfmm2geno main_LFMM main_ped2geno main_ped2lfmm main_sNMF main_vcf2geno main_vcf2lfmm main_pca"

cd ../../
echo "$PURPLE ## make for gprof $NORMAL"
make clean; make LDFLAGS="-pg -g -O3 -Wall -Wextra" > /dev/null 2>&1
cd test/main_gprof


#for i in $dir
#do
#	cd test_$i
#	echo "$BLUE ###### file: test_$i ######" 
#	sh test_file.sh
#	cd ..
#done

#cd ../../
#echo "$PURPLE ## make $NORMAL "
#make clean; make
#cd test/main_gprof

