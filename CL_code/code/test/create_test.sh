#!/bin/sh

# parameters
dir=$1
file=$2
functions=$3

file_dir="$dir/test_$file"

# test directory
mkdir $file_dir
cd $file_dir

#cp test_file.sh
cp ../../test_file.sh .

# files directory
mkdir files

# R generator
touch generator.R
for f in $functions
do
	echo "# generate $f\n" >> generator.R
done

# description
touch description.sh
echo "#!/bin/sh
#
# by E. Frichot
#" >> description.sh
echo "# file: $file
#
# functions:" >> description.sh
for f in $functions
do
	echo "# \t$f" >> description.sh
done

echo "#
# command line:
#" >> description.sh

for f in $functions
do
	echo "# exec $f
#" >> description.sh
done
echo "
. ../../meta.sh

" >> description.sh

# main 
main="test_$file"
touch $main.c
echo "// by E. Frichot\n" >> $main.c
echo "// file: $file\n" >> $main.c
echo "// functions:" >> $main.c
for f in $functions
do
	echo "// \t$f" >> $main.c
done
echo "\n#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include \"../../../src/$dir/$file.h\"

int main (int argc, char *argv[])
{
	// parameters

	// command line args configuration
" >> $main.c

for f in $functions
do
	echo "\t// test $f\n" >> $main.c
done
echo "\treturn 0;
}" >> $main.c

# makefile
touch Makefile
echo "## OPTIONS ####
CFLAGS = -lm -lpthread -Wall -Wextra
LDFLAGS = -g -O3 -Wall -Wextra

CC = colorgcc
## CC = gcc

# src obj
SRC = $main.c
OBJ = \$(patsubst %.c,%.o,\$(SRC))

EXEC = $main
all: \$(SRC) \$(EXEC)

\$%.o: \$%.c
\t\$(CC) \$(LDFLAGS) -c \$< -o \$@

$main : \$(OBJ)
\t\$(CC) \$(OBJ) -o \$@ ../../../obj/bituint/*.o ../../../obj/convert/*.o ../../../obj/createDataSet/*.o ../../../obj/crossEntropy/*.o ../../../obj/io/*.o ../../../obj/lapack/*.o ../../../obj/LFMM/*.o ../../../obj/matrix/*.o ../../../obj/nnlsm/*.o ../../../obj/sNMF/*.o \$(CFLAGS) \$(LDFLAGS)

clean:
	rm -f *.o $main
" > Makefile

