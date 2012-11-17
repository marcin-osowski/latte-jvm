#include "return_check.h"
#include "exceptions.h"

namespace latte_type_check
{
void ReturnCheck::visitPProg(PProg *pprog)
{
  pprog->listtopdef_->accept(this);
}

void ReturnCheck::visitTFnDef(TFnDef *tfndef)
{
  auto retType = funEnv[tfndef->ident_]->getReturnType();
  if(*retType != VOID){
    reachable = true;
    tfndef->block_->accept(this);
    if(reachable){
      err.push_back(Error(
            tfndef->line_number,
            tfndef->ident_,
            "control reaches end of non-void function"
          ));
    }
  }
}

void ReturnCheck::visitBBlock(BBlock *bblock)
{
  bblock->liststmt_->accept(this);
}

void ReturnCheck::visitSEmpty(SEmpty *sempty __attribute__((__unused__)))
{
}

void ReturnCheck::visitSBStmt(SBStmt *sbstmt)
{
  sbstmt->block_->accept(this);
}

void ReturnCheck::visitSDecl(SDecl *sdecl __attribute__((__unused__)))
{
}

void ReturnCheck::visitSAss(SAss *sass __attribute__((__unused__)))
{
}

void ReturnCheck::visitSIncr(SIncr *sincr __attribute__((__unused__)))
{
}

void ReturnCheck::visitSDecr(SDecr *sdecr __attribute__((__unused__)))
{
}

void ReturnCheck::visitSRet(SRet *sret __attribute__((__unused__)))
{
  reachable = false;
}

void ReturnCheck::visitSVRet(SVRet *svret __attribute__((__unused__)))
{
  reachable = false;
}

void ReturnCheck::visitSCond(SCond *scond)
{
  if(dynamic_cast<ELitTrue*>(scond->expr_))
    scond->stmt_->accept(this);
}

void ReturnCheck::visitSCondElse(SCondElse *scondelse)
{
  bool const reachableCopy = reachable;

  reachable = true;
  scondelse->stmt_1->accept(this);
  bool const stmt1_stops = !reachable;

  reachable = true;
  scondelse->stmt_2->accept(this);
  bool const stmt2_stops = !reachable;

  reachable = reachableCopy;

  if(dynamic_cast<ELitTrue*>(scondelse->expr_) && stmt1_stops)
    reachable = false;
  if(dynamic_cast<ELitFalse*>(scondelse->expr_) && stmt2_stops)
    reachable = false;
  if(stmt1_stops && stmt2_stops)
    reachable = false;
}

void ReturnCheck::visitSWhile(SWhile *swhile)
{
  if(dynamic_cast<ELitTrue*>(swhile->expr_))
    reachable = false;
}

void ReturnCheck::visitSSExp(SSExp *ssexp __attribute__((__unused__)))
{
}

void ReturnCheck::visitListTopDef(ListTopDef* listtopdef)
{
  for (ListTopDef::iterator i = listtopdef->begin() ; i != listtopdef->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void ReturnCheck::visitListStmt(ListStmt* liststmt)
{
  for (ListStmt::iterator i = liststmt->begin() ; i != liststmt->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void ReturnCheck::visitIdent(Ident x)
{
  funName.reset(new std::string(x));
}

Errors const& ReturnCheck::getErrors()
{
    return err;
}

}

