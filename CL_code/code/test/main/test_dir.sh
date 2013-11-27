#!/bin/sh

. ../meta.sh

# parameters
dir="main_ancestrymap2geno main_ancestrymap2lfmm main_createDataSet main_crossEntropy main_geno2lfmm main_lfmm2geno main_LFMM main_ped2geno main_ped2lfmm main_sNMF main_vcf2geno main_pca"

for i in $dir
do
	cd test_$i
	echo "$BLUE ###### file: test_$i ######" 
	sh test_file.sh
	cd ..
done
