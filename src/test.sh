#!/bin/bash -xe

make
./latc foo.lat
jasmin foo.j
#java LatteProgram
cat foo.j
