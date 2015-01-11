#!/bin/sh

# command line:
# sh create_LEA_release.sh version_number

##################
#   parameters   #
##################

# name of the program
prog="LEA" 
# name of the directory to create 
dir="LEA_v$1"
# list of the src directory to copy from replop/CL_code/code/src/
src_list="io matrix LFMM bituint convert createDataSet crossEntropy nnlsm sNMF pca tracyWidom stats"
# list of the executable to add
main_list="LFMM createDataSet crossEntropy sNMF ancestrymap2geno ancestrymap2lfmm geno2lfmm lfmm2geno pca ped2geno ped2lfmm vcf2geno tracyWidom"

# color definition
VERT="\\033[1;32m" NORMAL="\\033[0;39m" ROUGE="\\033[1;31m" JAUNE="\\033[1;33m"

#############################
# creation of the directory #
#############################

echo "$VERT" "Creation of the directory $dir for $prog." "$NORMAL"
if [ -d $dir ]; then
	echo "$ROUGE" "A directory called $dir already exists !"
	echo "$ROUGE" "Creation Aborted." "$NORMAL"
	exit 1
else
	cp -r meta/$prog $dir
fi

echo "$VERT" "Entering $dir"
cd $dir

#############################
#  add of the src files     #
#############################
echo "\tAdd src files"

# copy files
for i in $src_list; do 
	echo "\t\tCopy of $i in $dir"
	cp -r ../../../code/src/$i/ src/ 
done

# Replace C function with specific R Function
echo "$VERT" "\tReplace C function with specific R Function"
files=`egrep -rl 'fflush|printf|malloc|calloc|realloc|free|exit\(1\)|warning|printf|RCODE' src/*/*.c` 
for f in $files; do
	echo "$NORMAL" "$f"
	sed -i '18 i\#include <R.h>' $f
	# malloc
	sed -i 's/calloc\(.*\),\s*sizeof(\(.*\)));/Calloc\1 * sizeof(\2), \2);/g' $f
	sed -i 's/malloc\(.*\)\s*sizeof(\(.*\)));/Calloc\1 sizeof(\2), \2);/g' $f
	sed -i 's/#define RCODE 0/#define RCODE 1/g' $f
	sed -i 's/realloc\(.*\),\s*sizeof(\(.*\)));/Realloc\1 * sizeof(\2), \2);/g' $f
	sed -i 's/free(/Free(/g' $f
	sed -i 's/\([^fn]\)printf/\1Rprintf/g' $f
	sed -i 's/exit(1)/error(NULL)/g' $f
	sed -i 's/fflush(stdout)//g' $f
done

# remove lapack, already present in R
files=`egrep -rl 'lapack' src/*/*.c` 
for f in $files; do
	echo $f
	sed -i 's/^.*lapack.*$//g' $f
	sed -i '19 i\#include <R_ext/Lapack.h>' $f
	sed -i 's/integer/int/g' $f
	sed -i 's/doublereal/double/g' $f
done

##############################
# WARNING: UPDATE the README #
##############################

echo "$JAUNE" "\tWARNING: Do not FORGET to update the README files !!!"

# documentation
# echo "$VERT" "\tCompilation of the documentation" "$NORMAL"

# end
echo "$VERT" "Leaving $dir" "$NORMAL"
cd ..


###########################
# creation of the archive #
###########################

echo "$VERT" "creation of the archive" "$NORMAL"
time R CMD build $dir


# Advise about how to check the package
echo "$VERT" "To check the package, use:\nR CMD check --as-cran <package.tar.gz>\nR CMD BiocCheck <package.tar.gz>\n" 


