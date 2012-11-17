#ifndef LATTE_PARSER_SKELETON_HEADER
#define LATTE_PARSER_SKELETON_HEADER
/* You might want to change the above name. */

#include "Absyn.H"

namespace latte_parser
{
class Skeleton : public Visitor
{
public:
  void visitProgram(Program* p);
  void visitTopDef(TopDef* p);
  void visitArg(Arg* p);
  void visitBlock(Block* p);
  void visitStmt(Stmt* p);
  void visitItem(Item* p);
  void visitType(Type* p);
  void visitExpr(Expr* p);
  void visitAddOp(AddOp* p);
  void visitMulOp(MulOp* p);
  void visitRelOp(RelOp* p);
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
  void visitOTimes(OTimes* p);
  void visitODiv(ODiv* p);
  void visitOMod(OMod* p);
  void visitOLTH(OLTH* p);
  void visitOLE(OLE* p);
  void visitOGTH(OGTH* p);
  void visitOGE(OGE* p);
  void visitOEQU(OEQU* p);
  void visitONE(ONE* p);
  void visitListTopDef(ListTopDef* p);
  void visitListArg(ListArg* p);
  void visitListStmt(ListStmt* p);
  void visitListItem(ListItem* p);
  void visitListExpr(ListExpr* p);

  void visitInteger(Integer x);
  void visitChar(Char x);
  void visitDouble(Double x);
  void visitString(String x);
  void visitIdent(Ident x);

};
}

#endif
