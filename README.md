Latte JVM compiler
==================

An implementation of Latte compiler with JVM output

Programming language: C++11

Tools: BNFC, flex, bison, make, g++, jasmin

Libraries: Boost

Aby zbudowac kompilator nalezy wykonac polecenie `make' w glownym
katalogu projektu. Kompilator uruchamia sie poprzez skrypt ./latc

Struktura katalogow:
    lattests/    - testy z treści zadania
    src/         - pliki zrodlowe kompilatora
    src/parser/  - pliki zrodlowe parsera
    lib/         - assembler JVM Jasmin

(C) 2012 Osowski Marcin
MRJP @ MIMUW
