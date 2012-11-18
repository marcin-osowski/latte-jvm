#ifndef LATTE_FUNCTIONS_TYPES_H
#define LATTE_FUNCTIONS_TYPES_H

#include <string>
#include <vector>
#include <memory>
#include "parser/Absyn.H"
#include "parser/Printer.H"
#include "environment.h"
#include "error.h"
#include "type.h"

/*
 * Class that loads function signatures before actual type check
 * can take place.
 * */

namespace latte_type_check
{
using namespace latte_parser;
class FunType;
class FunTypesLoader;

typedef Environment<std::shared_ptr<FunType>> FunTypesEnv;

class FunType
{
public:
  FunType(std::shared_ptr<LatteType>& _returnType): returnType(_returnType->clone()){}
  
  void addArgType(std::shared_ptr<LatteType>& _argType){
    arguments.push_back(std::shared_ptr<LatteType>(_argType->clone()));
  }

  std::vector<std::shared_ptr<LatteType>> const& getArguments(){
    return arguments;
  }

  std::shared_ptr<LatteType> const& getReturnType(){
    return returnType;
  }

  std::string toString(){
    std::string result = returnType->toString();
    result.append("(");
    size_t i = 0;
    for(auto t : arguments){
        i++;
        result.append(t->toString());
        if(i < arguments.size())
            result.append(", ");
    }
    result.append(")");
    return result;
  }


private:
  std::shared_ptr<LatteType> returnType;
  std::vector<std::shared_ptr<LatteType>> arguments;
  
};

using namespace latte_parser;
class FunTypesLoader : public Visitor
{
public:
  FunTypesLoader();
  ~FunTypesLoader();
  void visitPProg(PProg* p);
  void visitTFnDef(TFnDef* p);
  void visitAArg(AArg* p);
  void visitTInt(TInt* p);
  void visitTStr(TStr* p);
  void visitTBool(TBool* p);
  void visitTVoid(TVoid* p);
  void visitListTopDef(ListTopDef* p);
  void visitListArg(ListArg* p);
  void visitIdent(Ident x);

  const FunTypesEnv& getResultEnv();
  const Errors& getErrors();
private:
  FunTypesEnv env;
  std::shared_ptr<LatteType> lastType;
  std::shared_ptr<std::string> lastIdent;
  std::shared_ptr<FunType> lastFunType;

  Errors err;

};
}

#endif
