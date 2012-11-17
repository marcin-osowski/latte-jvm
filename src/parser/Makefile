CC = g++
CCFLAGS = -g
FLEX = flex
BISON = bison
LATEX = latex
DVIPS = dvips

all: testLatte Latte.ps

clean:
	rm -f *.o Latte.dvi Latte.aux Latte.log Latte.ps testLatte

distclean:
	 rm -f *.o Absyn.C Absyn.H Test.C Parser.C Parser.H Lexer.C Skeleton.C Skeleton.H Printer.C Printer.H Latte.l Latte.y Latte.tex Latte.dvi Latte.aux Latte.log Latte.ps testLatte Makefile

testLatte: Absyn.o Lexer.o Parser.o Printer.o Test.o
	@echo "Linking testLatte..."
	${CC} ${CCFLAGS} *.o -o testLatte
        
Absyn.o: Absyn.C Absyn.H
	${CC} ${CCFLAGS} -c Absyn.C

Lexer.C: Latte.l
	${FLEX} -oLexer.C Latte.l

Parser.C: Latte.y
	${BISON} Latte.y -o Parser.C

Lexer.o: Lexer.C Parser.H
	${CC} ${CCFLAGS} -c Lexer.C 

Parser.o: Parser.C Absyn.H
	${CC} ${CCFLAGS} -c Parser.C

Printer.o: Printer.C Printer.H Absyn.H
	${CC} ${CCFLAGS} -c Printer.C

Skeleton.o: Skeleton.C Skeleton.H Absyn.H
	${CC} ${CCFLAGS} -c Skeleton.C

Test.o: Test.C Parser.H Printer.H Absyn.H
	${CC} ${CCFLAGS} -c Test.C

Latte.dvi: Latte.tex
	${LATEX} Latte.tex

Latte.ps: Latte.dvi
	${DVIPS} Latte.dvi -o Latte.ps

