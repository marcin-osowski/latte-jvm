/*** BNFC-Generated Pretty Printer and Abstract Syntax Viewer ***/

#include <string>
#include "Printer.H"

namespace latte_parser
{
//You may wish to change render
void PrintAbsyn::render(Char c)
{
  if (c == '{')
  {
     bufAppend('\n');
     indent();
     bufAppend(c);
     _n_ = _n_ + 2;
     bufAppend('\n');
     indent();
  }
  else if (c == '(' || c == '[')
     bufAppend(c);
  else if (c == ')' || c == ']')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == '}')
  {
     _n_ = _n_ - 2;
     backup();
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == ',')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == ';')
  {
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == 0) return;
  else
  {
     bufAppend(c);
     bufAppend(' ');
  }
}
void PrintAbsyn::render(String s_)
{
  const char *s = s_.c_str() ;
  if(strlen(s) > 0)
  {
    bufAppend(s);
    bufAppend(' ');
  }
}
void PrintAbsyn::indent()
{
  int n = _n_;
  while (n > 0)
  {
    bufAppend(' ');
    n--;
  }
}
void PrintAbsyn::backup()
{
  if (buf_[cur_ - 1] == ' ')
  {
    buf_[cur_ - 1] = 0;
    cur_--;
  }
}
PrintAbsyn::PrintAbsyn(void)
{
  _i_ = 0; _n_ = 0;
  buf_ = 0;
  bufReset();
}

PrintAbsyn::~PrintAbsyn(void)
{
}

char* PrintAbsyn::print(Visitable *v)
{
  _i_ = 0; _n_ = 0;
  bufReset();
  v->accept(this);
  return buf_;
}
void PrintAbsyn::visitProgram(Program*p) {} //abstract class

void PrintAbsyn::visitPProg(PProg* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  if(p->listtopdef_) {_i_ = 0; p->listtopdef_->accept(this);}
  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTopDef(TopDef*p) {} //abstract class

void PrintAbsyn::visitTFnDef(TFnDef* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  _i_ = 0; p->type_->accept(this);
  visitIdent(p->ident_);
  render('(');
  if(p->listarg_) {_i_ = 0; p->listarg_->accept(this);}  render(')');
  _i_ = 0; p->block_->accept(this);

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListTopDef(ListTopDef *listtopdef)
{
  for (ListTopDef::const_iterator i = listtopdef->begin() ; i != listtopdef->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listtopdef->end() - 1) render("");
  }
}

void PrintAbsyn::visitArg(Arg*p) {} //abstract class

void PrintAbsyn::visitAArg(AArg* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  _i_ = 0; p->type_->accept(this);
  visitIdent(p->ident_);

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListArg(ListArg *listarg)
{
  for (ListArg::const_iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listarg->end() - 1) render(',');
  }
}

void PrintAbsyn::visitBlock(Block*p) {} //abstract class

void PrintAbsyn::visitBBlock(BBlock* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render('{');
  if(p->liststmt_) {_i_ = 0; p->liststmt_->accept(this);}  render('}');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListStmt(ListStmt *liststmt)
{
  for (ListStmt::const_iterator i = liststmt->begin() ; i != liststmt->end() ; ++i)
  {
    (*i)->accept(this);
    render("");
  }
}

void PrintAbsyn::visitStmt(Stmt*p) {} //abstract class

void PrintAbsyn::visitSEmpty(SEmpty* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render(';');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSBStmt(SBStmt* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  _i_ = 0; p->block_->accept(this);

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSDecl(SDecl* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  _i_ = 0; p->type_->accept(this);
  if(p->listitem_) {_i_ = 0; p->listitem_->accept(this);}  render(';');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSAss(SAss* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  visitIdent(p->ident_);
  render('=');
  _i_ = 0; p->expr_->accept(this);
  render(';');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSIncr(SIncr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  visitIdent(p->ident_);
  render("++");
  render(';');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSDecr(SDecr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  visitIdent(p->ident_);
  render("--");
  render(';');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSRet(SRet* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render("return");
  _i_ = 0; p->expr_->accept(this);
  render(';');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSVRet(SVRet* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render("return");
  render(';');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSCond(SCond* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render("if");
  render('(');
  _i_ = 0; p->expr_->accept(this);
  render(')');
  _i_ = 0; p->stmt_->accept(this);

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSCondElse(SCondElse* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render("if");
  render('(');
  _i_ = 0; p->expr_->accept(this);
  render(')');
  _i_ = 0; p->stmt_1->accept(this);
  render("else");
  _i_ = 0; p->stmt_2->accept(this);

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSWhile(SWhile* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render("while");
  render('(');
  _i_ = 0; p->expr_->accept(this);
  render(')');
  _i_ = 0; p->stmt_->accept(this);

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSSExp(SSExp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  _i_ = 0; p->expr_->accept(this);
  render(';');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitItem(Item*p) {} //abstract class

void PrintAbsyn::visitINoInit(INoInit* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitIInit(IInit* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  visitIdent(p->ident_);
  render('=');
  _i_ = 0; p->expr_->accept(this);

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListItem(ListItem *listitem)
{
  for (ListItem::const_iterator i = listitem->begin() ; i != listitem->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listitem->end() - 1) render(',');
  }
}

void PrintAbsyn::visitType(Type*p) {} //abstract class

void PrintAbsyn::visitTInt(TInt* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render("int");

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTStr(TStr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render("string");

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTBool(TBool* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render("boolean");

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitTVoid(TVoid* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render("void");

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitExpr(Expr*p) {} //abstract class

void PrintAbsyn::visitEVar(EVar* p)
{
  int oldi = _i_;
  if (oldi > 6) render(LATTE_PARSER__L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 6) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELitInt(ELitInt* p)
{
  int oldi = _i_;
  if (oldi > 6) render(LATTE_PARSER__L_PAREN);

  visitInteger(p->integer_);

  if (oldi > 6) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELitTrue(ELitTrue* p)
{
  int oldi = _i_;
  if (oldi > 6) render(LATTE_PARSER__L_PAREN);

  render("true");

  if (oldi > 6) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELitFalse(ELitFalse* p)
{
  int oldi = _i_;
  if (oldi > 6) render(LATTE_PARSER__L_PAREN);

  render("false");

  if (oldi > 6) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEApp(EApp* p)
{
  int oldi = _i_;
  if (oldi > 6) render(LATTE_PARSER__L_PAREN);

  visitIdent(p->ident_);
  render('(');
  if(p->listexpr_) {_i_ = 0; p->listexpr_->accept(this);}  render(')');

  if (oldi > 6) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEString(EString* p)
{
  int oldi = _i_;
  if (oldi > 6) render(LATTE_PARSER__L_PAREN);

  visitString(p->string_);

  if (oldi > 6) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitENeg(ENeg* p)
{
  int oldi = _i_;
  if (oldi > 5) render(LATTE_PARSER__L_PAREN);

  render('-');
  _i_ = 6; p->expr_->accept(this);

  if (oldi > 5) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitENot(ENot* p)
{
  int oldi = _i_;
  if (oldi > 5) render(LATTE_PARSER__L_PAREN);

  render('!');
  _i_ = 6; p->expr_->accept(this);

  if (oldi > 5) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEMul(EMul* p)
{
  int oldi = _i_;
  if (oldi > 4) render(LATTE_PARSER__L_PAREN);

  _i_ = 4; p->expr_1->accept(this);
  _i_ = 0; p->mulop_->accept(this);
  _i_ = 5; p->expr_2->accept(this);

  if (oldi > 4) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAdd(EAdd* p)
{
  int oldi = _i_;
  if (oldi > 3) render(LATTE_PARSER__L_PAREN);

  _i_ = 3; p->expr_1->accept(this);
  _i_ = 0; p->addop_->accept(this);
  _i_ = 4; p->expr_2->accept(this);

  if (oldi > 3) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitERel(ERel* p)
{
  int oldi = _i_;
  if (oldi > 2) render(LATTE_PARSER__L_PAREN);

  _i_ = 2; p->expr_1->accept(this);
  _i_ = 0; p->relop_->accept(this);
  _i_ = 3; p->expr_2->accept(this);

  if (oldi > 2) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAnd(EAnd* p)
{
  int oldi = _i_;
  if (oldi > 1) render(LATTE_PARSER__L_PAREN);

  _i_ = 2; p->expr_1->accept(this);
  render("&&");
  _i_ = 1; p->expr_2->accept(this);

  if (oldi > 1) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEOr(EOr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  _i_ = 1; p->expr_1->accept(this);
  render("||");
  _i_ = 0; p->expr_2->accept(this);

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListExpr(ListExpr *listexpr)
{
  for (ListExpr::const_iterator i = listexpr->begin() ; i != listexpr->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listexpr->end() - 1) render(',');
  }
}

void PrintAbsyn::visitAddOp(AddOp*p) {} //abstract class

void PrintAbsyn::visitOPlus(OPlus* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render('+');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOMinus(OMinus* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render('-');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitMulOp(MulOp*p) {} //abstract class

void PrintAbsyn::visitOTimes(OTimes* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render('*');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitODiv(ODiv* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render('/');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOMod(OMod* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render('%');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRelOp(RelOp*p) {} //abstract class

void PrintAbsyn::visitOLTH(OLTH* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render('<');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOLE(OLE* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render("<=");

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOGTH(OGTH* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render('>');

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOGE(OGE* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render(">=");

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOEQU(OEQU* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render("==");

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitONE(ONE* p)
{
  int oldi = _i_;
  if (oldi > 0) render(LATTE_PARSER__L_PAREN);

  render("!=");

  if (oldi > 0) render(LATTE_PARSER__R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void PrintAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void PrintAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void PrintAbsyn::visitString(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void PrintAbsyn::visitIdent(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}

ShowAbsyn::ShowAbsyn(void)
{
  buf_ = 0;
  bufReset();
}

ShowAbsyn::~ShowAbsyn(void)
{
}

char* ShowAbsyn::show(Visitable *v)
{
  bufReset();
  v->accept(this);
  return buf_;
}
void ShowAbsyn::visitProgram(Program* p) {} //abstract class

void ShowAbsyn::visitPProg(PProg* p)
{
  bufAppend('(');
  bufAppend("PProg");
  bufAppend(' ');
  bufAppend('[');
  if (p->listtopdef_)  p->listtopdef_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitTopDef(TopDef* p) {} //abstract class

void ShowAbsyn::visitTFnDef(TFnDef* p)
{
  bufAppend('(');
  bufAppend("TFnDef");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->listarg_)  p->listarg_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->block_)  p->block_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListTopDef(ListTopDef *listtopdef)
{
  for (ListTopDef::const_iterator i = listtopdef->begin() ; i != listtopdef->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listtopdef->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitArg(Arg* p) {} //abstract class

void ShowAbsyn::visitAArg(AArg* p)
{
  bufAppend('(');
  bufAppend("AArg");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitListArg(ListArg *listarg)
{
  for (ListArg::const_iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listarg->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitBlock(Block* p) {} //abstract class

void ShowAbsyn::visitBBlock(BBlock* p)
{
  bufAppend('(');
  bufAppend("BBlock");
  bufAppend(' ');
  bufAppend('[');
  if (p->liststmt_)  p->liststmt_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitListStmt(ListStmt *liststmt)
{
  for (ListStmt::const_iterator i = liststmt->begin() ; i != liststmt->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != liststmt->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitStmt(Stmt* p) {} //abstract class

void ShowAbsyn::visitSEmpty(SEmpty* p)
{
  bufAppend("SEmpty");
}
void ShowAbsyn::visitSBStmt(SBStmt* p)
{
  bufAppend('(');
  bufAppend("SBStmt");
  bufAppend(' ');
  bufAppend('[');
  if (p->block_)  p->block_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitSDecl(SDecl* p)
{
  bufAppend('(');
  bufAppend("SDecl");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listitem_)  p->listitem_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSAss(SAss* p)
{
  bufAppend('(');
  bufAppend("SAss");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSIncr(SIncr* p)
{
  bufAppend('(');
  bufAppend("SIncr");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSDecr(SDecr* p)
{
  bufAppend('(');
  bufAppend("SDecr");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSRet(SRet* p)
{
  bufAppend('(');
  bufAppend("SRet");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSVRet(SVRet* p)
{
  bufAppend("SVRet");
}
void ShowAbsyn::visitSCond(SCond* p)
{
  bufAppend('(');
  bufAppend("SCond");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->stmt_)  p->stmt_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitSCondElse(SCondElse* p)
{
  bufAppend('(');
  bufAppend("SCondElse");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  p->stmt_1->accept(this);
  bufAppend(' ');
  p->stmt_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitSWhile(SWhile* p)
{
  bufAppend('(');
  bufAppend("SWhile");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->stmt_)  p->stmt_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitSSExp(SSExp* p)
{
  bufAppend('(');
  bufAppend("SSExp");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitItem(Item* p) {} //abstract class

void ShowAbsyn::visitINoInit(INoInit* p)
{
  bufAppend('(');
  bufAppend("INoInit");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitIInit(IInit* p)
{
  bufAppend('(');
  bufAppend("IInit");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListItem(ListItem *listitem)
{
  for (ListItem::const_iterator i = listitem->begin() ; i != listitem->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listitem->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitType(Type* p) {} //abstract class

void ShowAbsyn::visitTInt(TInt* p)
{
  bufAppend("TInt");
}
void ShowAbsyn::visitTStr(TStr* p)
{
  bufAppend("TStr");
}
void ShowAbsyn::visitTBool(TBool* p)
{
  bufAppend("TBool");
}
void ShowAbsyn::visitTVoid(TVoid* p)
{
  bufAppend("TVoid");
}
void ShowAbsyn::visitExpr(Expr* p) {} //abstract class

void ShowAbsyn::visitEVar(EVar* p)
{
  bufAppend('(');
  bufAppend("EVar");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitELitInt(ELitInt* p)
{
  bufAppend('(');
  bufAppend("ELitInt");
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(')');
}
void ShowAbsyn::visitELitTrue(ELitTrue* p)
{
  bufAppend("ELitTrue");
}
void ShowAbsyn::visitELitFalse(ELitFalse* p)
{
  bufAppend("ELitFalse");
}
void ShowAbsyn::visitEApp(EApp* p)
{
  bufAppend('(');
  bufAppend("EApp");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->listexpr_)  p->listexpr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEString(EString* p)
{
  bufAppend('(');
  bufAppend("EString");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
void ShowAbsyn::visitENeg(ENeg* p)
{
  bufAppend('(');
  bufAppend("ENeg");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitENot(ENot* p)
{
  bufAppend('(');
  bufAppend("ENot");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEMul(EMul* p)
{
  bufAppend('(');
  bufAppend("EMul");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  bufAppend('[');
  if (p->mulop_)  p->mulop_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEAdd(EAdd* p)
{
  bufAppend('(');
  bufAppend("EAdd");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  bufAppend('[');
  if (p->addop_)  p->addop_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitERel(ERel* p)
{
  bufAppend('(');
  bufAppend("ERel");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  bufAppend('[');
  if (p->relop_)  p->relop_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEAnd(EAnd* p)
{
  bufAppend('(');
  bufAppend("EAnd");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEOr(EOr* p)
{
  bufAppend('(');
  bufAppend("EOr");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitListExpr(ListExpr *listexpr)
{
  for (ListExpr::const_iterator i = listexpr->begin() ; i != listexpr->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listexpr->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitAddOp(AddOp* p) {} //abstract class

void ShowAbsyn::visitOPlus(OPlus* p)
{
  bufAppend("OPlus");
}
void ShowAbsyn::visitOMinus(OMinus* p)
{
  bufAppend("OMinus");
}
void ShowAbsyn::visitMulOp(MulOp* p) {} //abstract class

void ShowAbsyn::visitOTimes(OTimes* p)
{
  bufAppend("OTimes");
}
void ShowAbsyn::visitODiv(ODiv* p)
{
  bufAppend("ODiv");
}
void ShowAbsyn::visitOMod(OMod* p)
{
  bufAppend("OMod");
}
void ShowAbsyn::visitRelOp(RelOp* p) {} //abstract class

void ShowAbsyn::visitOLTH(OLTH* p)
{
  bufAppend("OLTH");
}
void ShowAbsyn::visitOLE(OLE* p)
{
  bufAppend("OLE");
}
void ShowAbsyn::visitOGTH(OGTH* p)
{
  bufAppend("OGTH");
}
void ShowAbsyn::visitOGE(OGE* p)
{
  bufAppend("OGE");
}
void ShowAbsyn::visitOEQU(OEQU* p)
{
  bufAppend("OEQU");
}
void ShowAbsyn::visitONE(ONE* p)
{
  bufAppend("ONE");
}
void ShowAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void ShowAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void ShowAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void ShowAbsyn::visitString(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void ShowAbsyn::visitIdent(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}

}
