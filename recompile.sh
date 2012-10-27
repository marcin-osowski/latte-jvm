#!/bin/bash 

make distclean &> /dev/null

set -e

bnfc -cpp_stl -l -p bnfc -m Latte.cf

# Add <algorithm> header to Bison input file
sed -i Latte.y -e 's/#include <iostream>/#include <iostream>\n#include <algorithm>/'

# Add annotation that we expect one shift/reduce conflict (dangling else problem)
sed -i Latte.y -e 's/^%%$/%expect 1\n\n%%/'


make clean
make

