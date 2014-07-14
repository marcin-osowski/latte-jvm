Latte JVM compiler
==================

An implementation of Latte (a Java subset) compiler with JVM output.
To build the compiler please run `make` in this directory.
The compiler can then be run via `./latc`.

Directories:
   * lattests/    - tests
   * src/         - compiler source files
   * src/parser/  - parser source files
   * lib/         - a JVM assembler, Jasmin

Programming language: C++11

Tools: BNFC, flex, bison, make, g++, Jasmin

Libraries: Boost


&copy; 2012 Osowski Marcin, MRJP @ MIMUW
