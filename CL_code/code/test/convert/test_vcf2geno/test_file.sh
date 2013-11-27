#!/bin/sh

. ../../meta.sh

echo "$LBLUE # Test files creation"
echo "$LBLUE # Make $NORMAL"
make clean; make #&> /dev/null
echo "$LBLUE # Tests $NORMAL"
sh description.sh
echo ""
