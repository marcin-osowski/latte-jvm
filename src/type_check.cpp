#include "type_check.h"

#include "exceptions.h"

namespace latte_type_check
{
void TypeCheck::visitPProg(PProg *pprog)
{
  lastLineNumber = pprog->line_number;
  pprog->listtopdef_->accept(this);
}

void TypeCheck::visitTFnDef(TFnDef *tfndef)
{
  {
      auto p = typeEnv.pusher();
      lastLineNumber = tfndef->line_number;
      tfndef->type_->accept(this);
      returnType = lastType;
      visitIdent(tfndef->ident_);
      funcName = lastIdent;
      tfndef->listarg_->accept(this);
      tfndef->block_->accept(this);
  }
}

void TypeCheck::visitAArg(AArg *aarg)
{
  lastLineNumber = aarg->line_number;
  aarg->type_->accept(this);
  visitIdent(aarg->ident_);
  try{
    typeEnv.insert(*lastIdent, lastType);
  }catch(IdentifierRepeatedException ex){
    err.push_back(Error(
          lastLineNumber,
          *funcName,
          "repeated identifier",
          lastIdent->c_str()));
  }
}

void TypeCheck::visitBBlock(BBlock *bblock)
{
  lastLineNumber = bblock->line_number;
  {
      auto pusher = typeEnv.pusher();
      bblock->liststmt_->accept(this);
  }
}

void TypeCheck::visitSEmpty(SEmpty *sempty)
{
  lastLineNumber = sempty->line_number;
}

void TypeCheck::visitSBStmt(SBStmt *sbstmt)
{
  lastLineNumber = sbstmt->line_number;
  {
      auto p = typeEnv.pusher();
      sbstmt->block_->accept(this);
  }
}

void TypeCheck::visitSDecl(SDecl *sdecl)
{
  lastLineNumber = sdecl->line_number;
  sdecl->type_->accept(this);
  declType = lastType;
  sdecl->listitem_->accept(this);
}

#define TYPE_FROM_ENV(type, ident)          \
  do {                                      \
  try{                                      \
    (type) = typeEnv[*(ident)];             \
  }catch(IdentifierNotFoundException ex) {  \
    err.push_back(Error(                    \
        lastLineNumber,                     \
        *funcName,                          \
        "unknown identifier",               \
        (ident)->c_str()));                 \
    (type).reset(new LatteType(ERROR));     \
  }                                         \
  }while (0)                                \

#define TYPE_INTO_ENV(type, ident)          \
  do {                                      \
  try{                                      \
    typeEnv.insert(*(ident), (type));       \
  }catch(IdentifierRepeatedException ex) {  \
    err.push_back(Error(                    \
        lastLineNumber,                     \
        *funcName,                          \
        "repeated identifier",              \
        (ident)->c_str()));                 \
  }                                         \
  }while (0)                                \

void TypeCheck::visitSAss(SAss *sass)
{
  lastLineNumber = sass->line_number;
  visitIdent(sass->ident_);
  std::shared_ptr<LatteType> xType;
  TYPE_FROM_ENV(xType, lastIdent);
  sass->expr_->accept(this);
  expectType(*xType);
}

void TypeCheck::visitSIncr(SIncr *sincr)
{
  lastLineNumber = sincr->line_number;
  visitIdent(sincr->ident_);
  std::shared_ptr<LatteType> xType;
  TYPE_FROM_ENV(xType, lastIdent);
  compareTypes(*xType, INT);
}

void TypeCheck::visitSDecr(SDecr *sdecr)
{
  lastLineNumber = sdecr->line_number;
  visitIdent(sdecr->ident_);
  std::shared_ptr<LatteType> xType;
  TYPE_FROM_ENV(xType, lastIdent);
  compareTypes(*xType, INT);
}

void TypeCheck::visitSRet(SRet *sret)
{
  lastLineNumber = sret->line_number;
  sret->expr_->accept(this);
  expectType(*returnType);
}

void TypeCheck::visitSVRet(SVRet *svret)
{
  lastLineNumber = svret->line_number;
  compareTypes(*returnType, VOID);
}

void TypeCheck::visitSCond(SCond *scond)
{
  lastLineNumber = scond->line_number;
  scond->expr_->accept(this);
  expectType(BOOL);
  {
      auto p = typeEnv.pusher();
      scond->stmt_->accept(this);
  }
}

void TypeCheck::visitSCondElse(SCondElse *scondelse)
{
  lastLineNumber = scondelse->line_number;
  scondelse->expr_->accept(this);
  expectType(BOOL);
  {
      auto p = typeEnv.pusher();
      scondelse->stmt_1->accept(this);
  }
  {
      auto p = typeEnv.pusher();
      scondelse->stmt_2->accept(this);
  }

}

void TypeCheck::visitSWhile(SWhile *swhile)
{
  lastLineNumber = swhile->line_number;
  swhile->expr_->accept(this);
  expectType(BOOL);
  {
      auto p = typeEnv.pusher();
      swhile->stmt_->accept(this);
  }
}

void TypeCheck::visitSSExp(SSExp *ssexp)
{
  lastLineNumber = ssexp->line_number;
  ssexp->expr_->accept(this);
}

void TypeCheck::visitINoInit(INoInit *inoinit)
{
  lastLineNumber = inoinit->line_number;
  visitIdent(inoinit->ident_);
  TYPE_INTO_ENV(declType, &inoinit->ident_);
}

void TypeCheck::visitIInit(IInit *iinit)
{
  visitIdent(iinit->ident_);
  TYPE_INTO_ENV(declType, &iinit->ident_);
  iinit->expr_->accept(this);
  expectType(*declType);
}

void TypeCheck::visitTInt(TInt *tint)
{
  lastLineNumber = tint->line_number;
  lastType.reset(new LatteType(tint));
}

void TypeCheck::visitTStr(TStr *tstr)
{
  lastLineNumber = tstr->line_number;
  lastType.reset(new LatteType(tstr));
}

void TypeCheck::visitTBool(TBool *tbool)
{
  lastLineNumber = tbool->line_number;
  lastType.reset(new LatteType(tbool));
}

void TypeCheck::visitTVoid(TVoid *tvoid)
{
  lastLineNumber = tvoid->line_number;
  lastType.reset(new LatteType(tvoid));
}

void TypeCheck::visitEVar(EVar *evar)
{
  lastLineNumber = evar->line_number;
  visitIdent(evar->ident_);
  TYPE_FROM_ENV(lastType, lastIdent);
}

void TypeCheck::visitELitInt(ELitInt *elitint)
{
  lastLineNumber = elitint->line_number;
  lastType.reset(new LatteType(INT));
}

void TypeCheck::visitELitTrue(ELitTrue *elittrue)
{
  lastLineNumber = elittrue->line_number;
  lastType.reset(new LatteType(BOOL));
}

void TypeCheck::visitELitFalse(ELitFalse *elitfalse)
{
  lastLineNumber = elitfalse->line_number;
  lastType.reset(new LatteType(BOOL));
}

void TypeCheck::visitEApp(EApp *eapp)
{
  lastLineNumber = eapp->line_number;

  visitIdent(eapp->ident_);
  std::shared_ptr<Ident> f = lastIdent;
  try{
    expectedArgsType = funEnv[*f]->getArguments();
    eapp->listexpr_->accept(this);
    lastType.reset(new LatteType(*(funEnv[*f]->getReturnType())));
  }catch(IdentifierNotFoundException ex) {
    err.push_back(Error(
        lastLineNumber,
        *funcName,
        "unknown identifier",
        f->c_str()));
    lastType.reset(new LatteType(ERROR));
  }

}

void TypeCheck::visitEString(EString *estring)
{
  lastLineNumber = estring->line_number;
  lastType.reset(new LatteType(STR));
}

void TypeCheck::visitENeg(ENeg *eneg)
{
  lastLineNumber = eneg->line_number;
  eneg->expr_->accept(this);
  expectType(INT);
}

void TypeCheck::visitENot(ENot *enot)
{
  lastLineNumber = enot->line_number;
  enot->expr_->accept(this);
  expectType(BOOL);
}

void TypeCheck::visitEMul(EMul *emul)
{
  lastLineNumber = emul->line_number;
  emul->expr_1->accept(this);
  expectType(INT);
  emul->expr_2->accept(this);
  expectType(INT);

}

void TypeCheck::visitEAdd(EAdd *eadd)
{
  lastLineNumber = eadd->line_number;
  eadd->expr_1->accept(this);
  std::shared_ptr<LatteType> t1 = lastType;
  eadd->addop_->accept(this);
  std::shared_ptr<AddOp> addOp = lastAddOp;
  eadd->expr_2->accept(this);
  std::shared_ptr<LatteType> t2 = lastType;

  if(dynamic_cast<OPlus*>(addOp.get()) != 0 && *t1 == STR){
    compareTypes(*t1, STR);
    compareTypes(*t2, STR);
  }else{
    compareTypes(*t1, INT);
    compareTypes(*t2, INT);
  }
}

void TypeCheck::visitERel(ERel *erel)
{
  lastLineNumber = erel->line_number;
  erel->expr_1->accept(this);
  std::shared_ptr<LatteType> t1(lastType);
  erel->expr_2->accept(this);

  if(*t1 == BOOL){
    expectType(BOOL);
  } else {
    expectType(INT);
    compareTypes(*t1, INT);
  }
  lastType.reset(new LatteType(BOOL));
}

void TypeCheck::visitEAnd(EAnd *eand)
{
  lastLineNumber = eand->line_number;
  eand->expr_1->accept(this);
  expectType(BOOL);
  eand->expr_2->accept(this);
  expectType(BOOL);

}

void TypeCheck::visitEOr(EOr *eor)
{
  lastLineNumber = eor->line_number;
  eor->expr_1->accept(this);
  expectType(BOOL);
  eor->expr_2->accept(this);
  expectType(BOOL);
}

void TypeCheck::visitOPlus(OPlus *oplus)
{
  lastLineNumber = oplus->line_number;
  lastAddOp.reset(oplus);
}

void TypeCheck::visitOMinus(OMinus *ominus)
{
  lastLineNumber = ominus->line_number;
  lastAddOp.reset(ominus);
}


void TypeCheck::visitListTopDef(ListTopDef* listtopdef)
{
  for (ListTopDef::iterator i = listtopdef->begin() ; i != listtopdef->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void TypeCheck::visitListArg(ListArg* listarg)
{
  for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void TypeCheck::visitListStmt(ListStmt* liststmt)
{
  for (ListStmt::iterator i = liststmt->begin() ; i != liststmt->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void TypeCheck::visitListItem(ListItem* listitem)
{
  for (ListItem::iterator i = listitem->begin() ; i != listitem->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void TypeCheck::visitListExpr(ListExpr* listexpr)
{
  if(listexpr->size() != expectedArgsType.size()){
    err.push_back(Error(lastLineNumber, *funcName, "wrong number of arguments"));
    return;
  }
  std::vector<std::shared_ptr<LatteType>> args(expectedArgsType);
  auto j = args.begin();
  for(auto i : *listexpr) {
    i->accept(this);
    expectType(**j);
    ++j;
  }
}

void TypeCheck::visitIdent(Ident x)
{
    lastIdent.reset(new std::string(x));
}

Errors const& TypeCheck::getErrors()
{
    return err;
}

void TypeCheck::expectType(LatteType const& t)
{
  compareTypes(t, *lastType);
}

void TypeCheck::compareTypes(LatteType const& t1, LatteType const& t2)
{
  if(t1 != t2){
    std::string msg;
    msg += "incompatible types: `";
    msg += t1.toString();
    msg += "' and `";
    msg += t2.toString();
    msg += "'";
    err.push_back(Error(lastLineNumber, *funcName, msg.c_str()));
    lastType.reset(new LatteType(ERROR));
  }
}

}



