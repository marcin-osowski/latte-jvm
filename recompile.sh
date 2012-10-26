#!/bin/bash 

make distclean &> /dev/null

set -e

bnfc -cpp_stl -l -p bnfc -m Latte.cf

make clean
make

