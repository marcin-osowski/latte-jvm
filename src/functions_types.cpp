#include "functions_types.h"
#include "exceptions.h"

namespace latte_type_check
{

FunTypesLoader::FunTypesLoader()
{
}

FunTypesLoader::~FunTypesLoader()
{
}

void FunTypesLoader::visitPProg(PProg *pprog)
{
  {
    /* Pre-loaded functions:
     *   void printInt(int)
     *   void printString(string)
     *   void error()
     *   int readInt()
     *   string readString()
     */
    std::shared_ptr<LatteType> tVoid(new LatteType(VOID));
    std::shared_ptr<LatteType> tInt(new LatteType(INT));
    std::shared_ptr<LatteType> tStr(new LatteType(STR));

    {
      /* printInt() */
      std::shared_ptr<FunType> printInt(new FunType(tVoid));
      printInt->addArgType(tInt);
      env.insert("printInt", printInt);
    }
    {
      /* printString() */
      std::shared_ptr<FunType> printString(new FunType(tVoid));
      printString->addArgType(tStr);
      env.insert("printString", printString);
    }
    {
      /* error() */
      std::shared_ptr<FunType> error(new FunType(tVoid));
      env.insert("error", error);
    }
    {
      /* readInt() */
      std::shared_ptr<FunType> readInt(new FunType(tInt));
      env.insert("readInt", readInt);
    }
    {
      /* readString() */
      std::shared_ptr<FunType> readString(new FunType(tStr));
      env.insert("readString", readString);
    }


  }
  pprog->listtopdef_->accept(this);
  try{
    std::shared_ptr<FunType> main = env[std::string("main")];
    if(*(main->getReturnType()) != LatteType(INT)){
      err.push_back(Error(
          0,
          std::string("main"),
          "function must return int"
       ));
    }
    if(! main->getArguments().empty()){
      err.push_back(Error(
          0,
          std::string("main"),
          "function must not have arguments"
       ));
    }
  }catch(IdentifierNotFoundException ex){
    err.push_back(Error(
        0,
        std::string("<global>"),
        "no function main() defined"
     ));

  }
}

void FunTypesLoader::visitTFnDef(TFnDef *tfndef)
{
  tfndef->type_->accept(this);
  visitIdent(tfndef->ident_);
  lastFunType.reset(new FunType(lastType));
  tfndef->listarg_->accept(this);
  try{
      env.insert(*lastIdent, lastFunType);
      tfndef->funType = lastFunType;
  }catch(IdentifierRepeatedException ex){
      err.push_back(Error(tfndef->line_number, *lastIdent, "conflicing function name"));
  }
}

void FunTypesLoader::visitAArg(AArg *aarg)
{
  aarg->type_->accept(this);
  if(*lastType == LatteType(VOID)){
      err.push_back(Error(
                aarg->line_number,
                *lastIdent,
                "type not allowed for a function parameter",
                "void"
            ));
  } else{
      lastFunType->addArgType(lastType);
  }
}

void FunTypesLoader::visitTInt(TInt *tint)
{
  lastType.reset(new LatteType(tint));
}

void FunTypesLoader::visitTStr(TStr *tstr)
{
  lastType.reset(new LatteType(tstr));
}

void FunTypesLoader::visitTBool(TBool *tbool)
{
  lastType.reset(new LatteType(tbool));
}

void FunTypesLoader::visitTVoid(TVoid *tvoid)
{
  lastType.reset(new LatteType(tvoid));
}

void FunTypesLoader::visitListTopDef(ListTopDef* listtopdef)
{
  for (ListTopDef::iterator i = listtopdef->begin() ; i != listtopdef->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void FunTypesLoader::visitListArg(ListArg* listarg)
{
  for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void FunTypesLoader::visitIdent(Ident x)
{
    lastIdent.reset(new std::string(x));
}


const Environment<std::shared_ptr<FunType>>& FunTypesLoader::getResultEnv()
{
    return env;
}

const Errors& FunTypesLoader::getErrors()
{
    return err;
}


}
