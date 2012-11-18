#ifndef LATTE_TYPE_CHECK_H
#define LATTE_TYPE_CHECK_H

#include "functions_types.h"
#include <iostream>

/*
 * Class performing type check on given program. Requires functions'
 * signatures to be known before.
 * */

namespace latte_type_check
{
class TypeCheck : public Visitor
{
public:
  TypeCheck(FunTypesEnv const& _funEnv) : funEnv(_funEnv) {}
  void visitPProg(PProg* p);
  void visitTFnDef(TFnDef* p);
  void visitAArg(AArg* p);
  void visitBBlock(BBlock* p);
  void visitSEmpty(SEmpty* p);
  void visitSBStmt(SBStmt* p);
  void visitSDecl(SDecl* p);
  void visitINoInit(INoInit* p);
  void visitIInit(IInit* p);
  void visitSAss(SAss* p);
  void visitSIncr(SIncr* p);
  void visitSDecr(SDecr* p);
  void visitSRet(SRet* p);
  void visitSVRet(SVRet* p);
  void visitSCond(SCond* p);
  void visitSCondElse(SCondElse* p);
  void visitSWhile(SWhile* p);
  void visitSSExp(SSExp* p);
  void visitTInt(TInt* p);
  void visitTStr(TStr* p);
  void visitTBool(TBool* p);
  void visitTVoid(TVoid* p);
  void visitEVar(EVar* p);
  void visitELitInt(ELitInt* p);
  void visitELitTrue(ELitTrue* p);
  void visitELitFalse(ELitFalse* p);
  void visitEApp(EApp* p);
  void visitEString(EString* p);
  void visitENeg(ENeg* p);
  void visitENot(ENot* p);
  void visitEMul(EMul* p);
  void visitEAdd(EAdd* p);
  void visitERel(ERel* p);
  void visitEAnd(EAnd* p);
  void visitEOr(EOr* p);
  void visitOPlus(OPlus* p);
  void visitOMinus(OMinus* p);
  void visitListTopDef(ListTopDef* p);
  void visitListArg(ListArg* p);
  void visitListStmt(ListStmt* p);
  void visitListItem(ListItem* p);
  void visitListExpr(ListExpr* p);
  void visitIdent(Ident x);

  Errors const& getErrors();
private:
  void expectType(LatteType const& t);
  void compareTypes(LatteType const& t1, LatteType const& t2);
private:
  FunTypesEnv funEnv;
  Environment<std::shared_ptr<LatteType>> typeEnv;
  Errors err;
  int lastLineNumber;
  std::shared_ptr<Ident> lastIdent;
  std::shared_ptr<LatteType> declType;
  std::shared_ptr<LatteType> lastType;
  std::shared_ptr<Ident> funcName;
  std::shared_ptr<LatteType> returnType;
  std::shared_ptr<AddOp> lastAddOp;
  std::vector<std::shared_ptr<LatteType>> expectedArgsType;
};
}

#endif
