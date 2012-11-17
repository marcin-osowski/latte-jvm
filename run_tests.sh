#!/bin/bash

set -e

make

echo ">>GOOD<<"
echo
for i in lattests/good/core0*.lat; do
    echo $i
    ./latc $i
done


echo
echo ">>BAD<<"
echo
for i in lattests/bad/bad0*.lat; do
    echo $i
    if ./latc $i > /dev/null; then
      false
    fi
done


echo
echo "All tests OK"
