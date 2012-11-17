#ifndef LATTE_RETURN_CHECK_H
#define LATTE_RETURN_CHECK_H

#include "functions_types.h"
#include <iostream>

namespace latte_type_check
{
class ReturnCheck : public Visitor
{
public:
  ReturnCheck(FunTypesEnv const& _funEnv) : funEnv(_funEnv) {}
  void visitPProg(PProg* p);
  void visitTFnDef(TFnDef* p);
  void visitBBlock(BBlock* p);
  void visitSEmpty(SEmpty* p);
  void visitSBStmt(SBStmt* p);
  void visitSDecl(SDecl* p);
  void visitSAss(SAss* p);
  void visitSIncr(SIncr* p);
  void visitSDecr(SDecr* p);
  void visitSRet(SRet* p);
  void visitSVRet(SVRet* p);
  void visitSCond(SCond* p);
  void visitSCondElse(SCondElse* p);
  void visitSWhile(SWhile* p);
  void visitSSExp(SSExp* p);
  void visitListTopDef(ListTopDef* p);
  void visitListStmt(ListStmt* p);
  void visitIdent(Ident x);

  Errors const& getErrors();
private:
  FunTypesEnv funEnv;
  Environment<std::shared_ptr<LatteType>> typeEnv;
  Errors err;
  std::shared_ptr<Ident> funName;
  bool reachable;
};
}

#endif
