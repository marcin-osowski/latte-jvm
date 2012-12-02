#!/bin/bash

set -e

make

rm -f `find lattests | grep '\.j$'`
rm -f `find lattests | grep '\.class$'`


echo ">>GOOD<<"
echo
for i in lattests/good/core???.lat; do
    echo $i
    CLASS=$(echo $i | sed -e 's/\.lat//' | sed -e 's%/%.%g')
    OUTPUT=$(echo $i | sed -e 's/\.lat$/.output/')
    INPUT=$(echo $i | sed -e 's/\.lat$/.input/')
    TMP=$(mktemp)
    ./latc $i
    if [ -e $INPUT ]; then
         java $CLASS > $TMP < $INPUT
    else
         java $CLASS > $TMP
    fi
    diff -u $OUTPUT $TMP
    echo Output OK.
    rm -f $TMP
done


echo
echo ">>BAD<<"
echo
for i in lattests/bad/bad???.lat lattests/mybad/bad???.lat; do
    echo $i
    if ./latc $i > /dev/null; then
      false
    fi
done


echo
echo "All tests OK"
