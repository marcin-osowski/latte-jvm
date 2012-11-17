#!/bin/bash 

echo CHANGES not included. Exitting.

exit 1

make distclean &> /dev/null

set -e

bnfc -cpp_stl -l -p latte_parser -m Latte.cf

# Add <algorithm> header to Bison input file
sed -i Latte.y -e 's/#include <iostream>/#include <iostream>\n#include <algorithm>/'

# Add annotation that we expect one shift/reduce conflict (dangling else problem)
sed -i Latte.y -e 's/^%%$/%expect 1\n\n%%/'

make clean

make Parser.C

# Change the error message
sed -i Parser.C -e 's/^      yyerror (YY_("syntax error"));$/       fprintf(stderr, "ERROR\\n");yyerror (YY_("syntax error"));/'


make

