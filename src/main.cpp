#include <stdio.h>
#include <iostream>
#include "parser/Parser.H"
#include "parser/Printer.H"
#include "parser/Absyn.H"
#include "functions_types.h"
#include "type_check.h"
#include "return_check.h"

int main(int argc, char ** argv)
{
    FILE *input;
    if (argc > 1) {
        input = fopen(argv[1], "r");
        if (!input) {
            fprintf(stderr, "Error opening input file.\n");
            exit(1);
        }
    }else {
        input = stdin;
    }
    latte_parser::Program *parse_tree = latte_parser::pProgram(input);
    if (!parse_tree) {
        return 1;
    }
    {
        /* Functions load */
        latte_type_check::FunTypesLoader functions_types;
        parse_tree->accept(&functions_types);
        if(! functions_types.getErrors().empty()){
            std::cerr << "ERROR\n";
            std::cout << functions_types.getErrors().toString();
            return 1;
        }

        /* Type check */
        latte_type_check::TypeCheck type_check(functions_types.getResultEnv());
        parse_tree->accept(&type_check);
        if(! type_check.getErrors().empty()){
            std::cerr << "ERROR\n";
            std::cout << type_check.getErrors().toString();
            return 1;
        }

        /* Return check */
        latte_type_check::ReturnCheck return_check(functions_types.getResultEnv());
        parse_tree->accept(&return_check);
        if(! return_check.getErrors().empty()){
            std::cerr << "ERROR\n";
            std::cout << return_check.getErrors().toString();
            return 1;
        }

        std::cerr << "OK\n";

    }

    return 0;
}

