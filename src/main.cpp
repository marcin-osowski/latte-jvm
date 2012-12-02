#include <stdio.h>
#include <memory>
#include <fstream>
#include <iostream>
#include "parser/Parser.H"
#include "parser/Printer.H"
#include "parser/Absyn.H"
#include "functions_types.h"
#include "type_check.h"
#include "return_check.h"
#include "jvm_compiler.h"

int main(const int argc, const char ** argv)
{
    FILE *input;
    if (argc != 2) {
        std::cerr << "ERROR\n";
        std::cout << "Please specify exactly one file to compile.\n";
        exit(1);
    }

    std::string out_filename = argv[1];
    std::string class_name = argv[1];
    auto pos = out_filename.rfind(".lat");
    if((pos != std::string::npos) && (pos == out_filename.size() - 4)){
        out_filename.replace(pos, 4, ".j");
        class_name.replace(pos, 4, "");
    }else{
        std::cerr << "ERROR\n";
        std::cout << "Filename must end with `.lat'.\n";
        exit(1);
    }

    input = fopen(argv[1], "r");
    if (!input) {
        std::cerr << "ERROR\n";
        std::cout << "Error opening input file.\n";
        exit(1);
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

        std::shared_ptr<std::ostream> output(
                new std::ofstream(out_filename, std::ios_base::out | std::ios_base::trunc));

        /* Compilation starts here */
        latte_compile::JVMCompiler jvm_compiler(class_name, output, functions_types.getResultEnv());
        parse_tree->accept(&jvm_compiler);

        std::cout << "Generated " << out_filename << "\n";
    }

    return 0;
}

