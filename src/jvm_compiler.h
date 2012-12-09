#ifndef LATTE_JVM_COMPILE_H
#define LATTE_JVM_COMPILE_H

#include <string>
#include <list>
#include "parser/Absyn.H"
#include "functions_types.h"

/*
 * Class that compiles type-checked Latte parse tree
 * into Jasmin JVM assembly.
 * */

namespace latte_compile
{
using namespace latte_parser;
using namespace latte_type_check;
class JVMCompiler : public Visitor
{
public:
  JVMCompiler(std::string const& _class_name,
              std::shared_ptr<std::ostream> _output,
              FunTypesEnv const& _funTypes)
                    : class_name(_class_name), output(_output), funTypes(_funTypes){ }
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
  void visitOTimes(OTimes *p);
  void visitODiv(ODiv *p);
  void visitOMod(OMod *p);
  void visitOLTH(OLTH *p);
  void visitOLE(OLE *p);
  void visitOGTH(OGTH *p);
  void visitOGE(OGE *p);
  void visitOEQU(OEQU *p);
  void visitONE(ONE *p);
  void visitListTopDef(ListTopDef* p);
  void visitListArg(ListArg* p);
  void visitListStmt(ListStmt* p);
  void visitListItem(ListItem* p);

private:
  void pushAsValue(Expr* e);
  void stackIncrease();
  void stackDecrease();
  void emit(std::string const& line);
  void emit(std::string const& line, int const num);
  void emitInstr(std::string const& instr);
  void emitInstr(std::string const& instr, int const num);
  void emitAStore(uint16_t var);
  void emitIStore(uint16_t var);
  void emitALoad(uint16_t var);
  void emitILoad(uint16_t var);
  void emitGoto(uint32_t label);
  void emitConditional(std::string const& instr, uint32_t lab1, uint32_t lab2);
  void emitIInc(uint16_t var, int delta);
  void emitPushInt(int const num);
  void emitPushString(std::string const& str);
  void emitPushLineFromStdin();
  std::string printLabel(uint32_t label);
  void emitLabel(uint32_t label);
  uint16_t newLocal();
  uint32_t newLabel();
private:
  std::string class_name;
  std::shared_ptr<std::ostream> output;
  FunTypesEnv funTypes;
  uint32_t labels_count;
  uint16_t current_stack;
  uint16_t max_stack;
  uint16_t locals_count;
  Environment<uint16_t> localsEnv;
  uint32_t ifTrueLabel;
  uint32_t ifFalseLabel;
  std::shared_ptr<LatteType> declType;
};
}

#endif
