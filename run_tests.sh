#!/bin/bash

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
    ./latc $i
done
