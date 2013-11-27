#!/bin/sh

. ../../meta.sh

echo "$LBLUE # Test files creation"
Rscript generator.R
rm files/out_* 2> /dev/null 
echo "$LBLUE # Make $NORMAL"
make clean; make #2> /dev/null
echo "$LBLUE # Tests $NORMAL"
sh description.sh
echo ""
