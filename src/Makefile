HEADERS=environment.h  error.h  exceptions.h  functions_types.h  type_check.h  type.h return_check.h jvm_compiler.h
OTHER_OBJS=parser/Absyn.o parser/Lexer.o parser/Parser.o parser/Printer.o
OBJS=main.o functions_types.o type_check.o return_check.o jvm_compiler.o
OUT=latc

CPP=g++
OPT=-g -Wall -Wextra -std=c++11 -lstdc++ #-Werror

all: $(OUT)

$(OTHER_OBJS): parser/%.o: parser/%.C
	make -C parser

$(OBJS): %.o: %.cpp $(HEADERS)
	$(CPP) $(OPT) -c $< -o $@

$(OUT): $(OBJS) $(OTHER_OBJS)
	$(CPP) $(OPT) $(OBJS) $(OTHER_OBJS) -o $(OUT)

rebuild: clean all

clean:
	rm -f $(OUT)
	rm -f *.o
	rm -f *.j
	rm -f *.class
	rm -f *~
	make -C parser clean
