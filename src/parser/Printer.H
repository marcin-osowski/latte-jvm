#ifndef LATTE_PARSER_PRINTER_HEADER
#define LATTE_PARSER_PRINTER_HEADER

#include "Absyn.H"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

namespace latte_parser
{
/* Certain applications may improve performance by changing the buffer size */
#define LATTE_PARSER_BUFFER_INITIAL 2000
/* You may wish to change _L_PAREN or _R_PAREN */
#define LATTE_PARSER__L_PAREN '('
#define LATTE_PARSER__R_PAREN ')'

class PrintAbsyn : public Visitor
{
 protected:
  int _n_, _i_;
  /* The following are simple heuristics for rendering terminals */
  /* You may wish to change them */
  void render(Char c);
  void render(String s);
  void indent(void);
  void backup(void);
 public:
  PrintAbsyn(void);
  ~PrintAbsyn(void);
  char* print(Visitable* v);

  void visitProgram(Program *p); /* abstract class */
  void visitPProg(PProg *p);
  void visitTopDef(TopDef *p); /* abstract class */
  void visitTFnDef(TFnDef *p);
  void visitListTopDef(ListTopDef* p);
  void visitArg(Arg *p); /* abstract class */
  void visitAArg(AArg *p);
  void visitListArg(ListArg* p);
  void visitBlock(Block *p); /* abstract class */
  void visitBBlock(BBlock *p);
  void visitListStmt(ListStmt* p);
  void visitStmt(Stmt *p); /* abstract class */
  void visitSEmpty(SEmpty *p);
  void visitSBStmt(SBStmt *p);
  void visitSDecl(SDecl *p);
  void visitSAss(SAss *p);
  void visitSIncr(SIncr *p);
  void visitSDecr(SDecr *p);
  void visitSRet(SRet *p);
  void visitSVRet(SVRet *p);
  void visitSCond(SCond *p);
  void visitSCondElse(SCondElse *p);
  void visitSWhile(SWhile *p);
  void visitSSExp(SSExp *p);
  void visitItem(Item *p); /* abstract class */
  void visitINoInit(INoInit *p);
  void visitIInit(IInit *p);
  void visitListItem(ListItem* p);
  void visitType(Type *p); /* abstract class */
  void visitTInt(TInt *p);
  void visitTStr(TStr *p);
  void visitTBool(TBool *p);
  void visitTVoid(TVoid *p);
  void visitExpr(Expr *p); /* abstract class */
  void visitEVar(EVar *p);
  void visitELitInt(ELitInt *p);
  void visitELitTrue(ELitTrue *p);
  void visitELitFalse(ELitFalse *p);
  void visitEApp(EApp *p);
  void visitEString(EString *p);
  void visitENeg(ENeg *p);
  void visitENot(ENot *p);
  void visitEMul(EMul *p);
  void visitEAdd(EAdd *p);
  void visitERel(ERel *p);
  void visitEAnd(EAnd *p);
  void visitEOr(EOr *p);
  void visitListExpr(ListExpr* p);
  void visitAddOp(AddOp *p); /* abstract class */
  void visitOPlus(OPlus *p);
  void visitOMinus(OMinus *p);
  void visitMulOp(MulOp *p); /* abstract class */
  void visitOTimes(OTimes *p);
  void visitODiv(ODiv *p);
  void visitOMod(OMod *p);
  void visitRelOp(RelOp *p); /* abstract class */
  void visitOLTH(OLTH *p);
  void visitOLE(OLE *p);
  void visitOGTH(OGTH *p);
  void visitOGE(OGE *p);
  void visitOEQU(OEQU *p);
  void visitONE(ONE *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = LATTE_PARSER_BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};



class ShowAbsyn : public Visitor
{
 public:
  ShowAbsyn(void);
  ~ShowAbsyn(void);
  char* show(Visitable* v);

  void visitProgram(Program *p); /* abstract class */
  void visitPProg(PProg *p);
  void visitTopDef(TopDef *p); /* abstract class */
  void visitTFnDef(TFnDef *p);
  void visitListTopDef(ListTopDef* p);
  void visitArg(Arg *p); /* abstract class */
  void visitAArg(AArg *p);
  void visitListArg(ListArg* p);
  void visitBlock(Block *p); /* abstract class */
  void visitBBlock(BBlock *p);
  void visitListStmt(ListStmt* p);
  void visitStmt(Stmt *p); /* abstract class */
  void visitSEmpty(SEmpty *p);
  void visitSBStmt(SBStmt *p);
  void visitSDecl(SDecl *p);
  void visitSAss(SAss *p);
  void visitSIncr(SIncr *p);
  void visitSDecr(SDecr *p);
  void visitSRet(SRet *p);
  void visitSVRet(SVRet *p);
  void visitSCond(SCond *p);
  void visitSCondElse(SCondElse *p);
  void visitSWhile(SWhile *p);
  void visitSSExp(SSExp *p);
  void visitItem(Item *p); /* abstract class */
  void visitINoInit(INoInit *p);
  void visitIInit(IInit *p);
  void visitListItem(ListItem* p);
  void visitType(Type *p); /* abstract class */
  void visitTInt(TInt *p);
  void visitTStr(TStr *p);
  void visitTBool(TBool *p);
  void visitTVoid(TVoid *p);
  void visitExpr(Expr *p); /* abstract class */
  void visitEVar(EVar *p);
  void visitELitInt(ELitInt *p);
  void visitELitTrue(ELitTrue *p);
  void visitELitFalse(ELitFalse *p);
  void visitEApp(EApp *p);
  void visitEString(EString *p);
  void visitENeg(ENeg *p);
  void visitENot(ENot *p);
  void visitEMul(EMul *p);
  void visitEAdd(EAdd *p);
  void visitERel(ERel *p);
  void visitEAnd(EAnd *p);
  void visitEOr(EOr *p);
  void visitListExpr(ListExpr* p);
  void visitAddOp(AddOp *p); /* abstract class */
  void visitOPlus(OPlus *p);
  void visitOMinus(OMinus *p);
  void visitMulOp(MulOp *p); /* abstract class */
  void visitOTimes(OTimes *p);
  void visitODiv(ODiv *p);
  void visitOMod(OMod *p);
  void visitRelOp(RelOp *p); /* abstract class */
  void visitOLTH(OLTH *p);
  void visitOLE(OLE *p);
  void visitOGTH(OGTH *p);
  void visitOGE(OGE *p);
  void visitOEQU(OEQU *p);
  void visitONE(ONE *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = LATTE_PARSER_BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};


}

#endif

