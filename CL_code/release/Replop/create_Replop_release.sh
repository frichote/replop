#!/bin/sh

# parameters
prog="Replop"
dir="Replop_v$1"
src_list="io lapack matrix LFMM bituint createDataSet crossEntropy nnlsm sNMF pca spfa thread"
main_list="LFMM createDataSet crossEntropy sNMF"

# color definition
VERT="\\033[1;32m" NORMAL="\\033[0;39m" ROUGE="\\033[1;31m" JAUNE="\\033[1;33m"
# creation of the directory
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

# add src files
echo "\tAdd src files"

for i in $src_list; do 
	echo "\t\tCopy of $i in $dir"
	cp -r ../../../code/src/$i/ src/ 
done

for i in $main_list; do 
	echo "\t\tCopy of $i in $dir"
	cp ../../../code/src/$i.c src/R_$i.c 
	sed -i s/"int main"/"#include \"R_$i.h\" \n\nint main_$i"/g src/R_$i.c
done

# README
echo "$JAUNE" "\tWARNING: Do not FORGET to update the README files !!!"

# documentation
echo "$VERT" "\tCompilation of the documentation" "$NORMAL"
#cd  ../../../documentation/$prog/obj/
#rm note.pdf
#pdflatex -interaction=batchmode note.tex
#bibtex note.aux
#pdflatex -interaction=batchmode note.tex
#cp note.pdf ../note_$prog.pdf 
#cp ../note_$prog.pdf ../../../release/$prog/$dir/documentation/
#cd  ../../../release/$prog/$dir/

# example
#echo "$VERT" "\tAdd examples files" "$NORMAL"
#cp -r ../../../examples/$prog/* examples/

echo "$VERT" "Leaving $dir" "$NORMAL"
cd ..

# creation of the archive
#echo "$VERT" "creation of the archive" "$NORMAL"

#if [ -f $dir.tar.gz ]; then
#        echo "$ROUGE" "An archive called $dir.tar.gz already exists !"
#        echo "$ROUGE" "Creation Aborted." "$NORMAL"
#	rm -rf $dir
#        exit 1
#else
#	tar -czf $dir.tar.gz $dir/
#	rm -rf $dir
#fi
echo "$VERT" "Succesful creation of $prog release v$1" "$NORMAL"

