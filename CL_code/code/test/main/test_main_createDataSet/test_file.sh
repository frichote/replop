#!/bin/sh

. ../../meta.sh

echo "$LBLUE # Test files creation"
rm files/* 2> /dev/null 
Rscript generator.R
echo "$LBLUE # Tests $NORMAL"
sh description.sh
echo ""
