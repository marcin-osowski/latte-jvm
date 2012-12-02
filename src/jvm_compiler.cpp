#include "jvm_compiler.h"
#include "exceptions.h"
#include <cassert>
#include <sstream>
#include <algorithm>

namespace latte_compile
{
void JVMCompiler::visitPProg(PProg *pprog)
{
    emit(";");
    emit("; Compiled with latc: latte to JVM compiler");
    emit("; (C) 2012 Osowski Marcin");
    emit(";");
    emit("");

    emit(".class public " + class_name);
    emit(".super java/lang/Object");
    emit("");

    emit("; a Scanner for stdin input operations");
    emit(".field public static scanner Ljava/util/Scanner;");
    emit("");

    emit("; class initializer");
    emit(".method static public <clinit>()V");
    emitInstr("new java/util/Scanner");
    emitInstr("dup");
    emitInstr("getstatic java/lang/System/in Ljava/io/InputStream;");
    emitInstr("invokenonvirtual java/util/Scanner/<init>"
                                    "(Ljava/io/InputStream;)V");
    emitInstr("putstatic " + class_name + "/scanner Ljava/util/Scanner;");
    emitInstr("return");
    emit(".limit stack 3");
    emit(".limit locals 0");
    emit(".end method");
    emit("");

    emit("; standard initializer");
    emit(".method public <init>()V");
    emitInstr("aload_0");
    emitInstr("invokenonvirtual java/lang/Object/<init>()V");
    emitInstr("return");
    emit(".end method");
    emit("");

    emit("; Compiled methods");
    pprog->listtopdef_->accept(this);
}

void JVMCompiler::visitTFnDef(TFnDef *tfndef)
{
    {
        auto p = localsEnv.pusher();
        emit("");
        if(tfndef->ident_ == std::string("main")){
            emit(".method public static main([Ljava/lang/String;)V");
            locals_count = 1;
            inside_main = true;
        }else{
            emit(".method public static " + tfndef->ident_ +
                                                tfndef->funType->toJVMType());
            locals_count = 0;
            inside_main = false;
        }
        current_stack = 0;
        max_stack = 0;
        labels_count = 0;

        tfndef->listarg_->accept(this);
        tfndef->block_->accept(this);

        if(*(tfndef->funType->getReturnType()) == VOID){
            emitInstr("return");
        }else{
            emitInstr("nop");
        }

        emit(".limit stack ", max_stack);
        emit(".limit locals ", locals_count); 
        emit(".end method");
    }
}

void JVMCompiler::visitAArg(AArg *aarg)
{
    localsEnv.insert(aarg->ident_, newLocal());
}

void JVMCompiler::visitBBlock(BBlock *bblock)
{
    {
        auto p = localsEnv.pusher();
        bblock->liststmt_->accept(this);
    }
    assert(current_stack == 0);
}

void JVMCompiler::visitSEmpty(SEmpty *sempty __attribute__((__unused__)))
{
    //  :)
    emitInstr("nop");
    assert(current_stack == 0);
}

void JVMCompiler::visitSBStmt(SBStmt *sbstmt)
{
    {
        auto p = localsEnv.pusher();
        sbstmt->block_->accept(this);
    }
    assert(current_stack == 0);
}

void JVMCompiler::visitSDecl(SDecl *sdecl)
{
    declType.reset(new LatteType(sdecl->type_));
    sdecl->listitem_->accept(this);
    declType.reset();
    assert(current_stack == 0);
}

void JVMCompiler::visitSAss(SAss *sass)
{
    if(*(sass->expr_->type) == STR){
        /* String */
        sass->expr_->accept(this);
        stackDecrease(); emitAStore(localsEnv[sass->ident_]);
    }else{
        pushAsValue(sass->expr_);
        stackDecrease(); emitIStore(localsEnv[sass->ident_]);
    }
    assert(current_stack == 0);
}

void JVMCompiler::visitSIncr(SIncr *sincr)
{
    emitIInc(localsEnv[sincr->ident_], 1);
    assert(current_stack == 0);
}

void JVMCompiler::visitSDecr(SDecr *sdecr)
{
    emitIInc(localsEnv[sdecr->ident_], -1);
    assert(current_stack == 0);
}

void JVMCompiler::visitSRet(SRet *sret)
{
    if(*(sret->expr_->type) == STR){
        /* String */
        sret->expr_->accept(this);
        stackDecrease(); emitInstr("areturn");
    }else{
        pushAsValue(sret->expr_);
        if(inside_main){
            stackDecrease();
            emitInstr("invokestatic java/lang/System/exit(I)V");
            emitInstr("return");
        }else{
            stackDecrease(); emitInstr("ireturn");
        }
    }
    assert(current_stack == 0);
}

void JVMCompiler::visitSVRet(SVRet *svret __attribute__((__unused__)))
{
    emitInstr("return");
    assert(current_stack == 0);
}

void JVMCompiler::visitSCond(SCond *scond)
{
    uint16_t const ifTrue = newLabel();
    uint16_t const end = newLabel();

    ifTrueLabel = ifTrue;
    ifFalseLabel = end;
    scond->expr_->accept(this);
    assert(current_stack == 0);

    emitLabel(ifTrue);
    scond->stmt_->accept(this);

    emitLabel(end);
}

void JVMCompiler::visitSCondElse(SCondElse *scondelse)
{
    uint16_t const ifTrue = newLabel();
    uint16_t const ifFalse = newLabel();
    uint16_t const end = newLabel();

    ifTrueLabel = ifTrue;
    ifFalseLabel = ifFalse;
    scondelse->expr_->accept(this);
    assert(current_stack == 0);

    emitLabel(ifTrue);
    scondelse->stmt_1->accept(this);
    emitGoto(end);

    emitLabel(ifFalse);
    scondelse->stmt_2->accept(this);

    emitLabel(end);

}

void JVMCompiler::visitSWhile(SWhile *swhile)
{
    uint16_t const loop = newLabel();
    uint16_t const enter_loop = newLabel();
    uint16_t const end = newLabel();

    emitLabel(loop);
    ifTrueLabel = enter_loop;
    ifFalseLabel = end;
    swhile->expr_->accept(this);
    assert(current_stack == 0);

    emitLabel(enter_loop);
    swhile->stmt_->accept(this);
    emitGoto(loop);

    emitLabel(end);
}

void JVMCompiler::visitSSExp(SSExp *ssexp)
{
    ssexp->expr_->accept(this);
    if(*(ssexp->expr_->type) != LatteType(VOID)){
        stackDecrease(); emitInstr("pop");
    }
    assert(current_stack == 0);
}

void JVMCompiler::visitINoInit(INoInit *inoinit)
{
    uint16_t const local = newLocal();
    localsEnv.insert(inoinit->ident_, local);
    if(*declType == STR){
        stackIncrease(); emitPushString("");
        stackDecrease(); emitAStore(local);
    }else{
        stackIncrease(); emitPushInt(0);
        stackDecrease(); emitIStore(local);
    }
}

void JVMCompiler::visitIInit(IInit *iinit)
{
    uint16_t const local = newLocal();
    if(*declType == STR){
        iinit->expr_->accept(this);
        localsEnv.insert(iinit->ident_, local);
        stackDecrease(); emitAStore(local);
    }else{
        pushAsValue(iinit->expr_);
        localsEnv.insert(iinit->ident_, local);
        stackDecrease(); emitIStore(local);
    }
}

void JVMCompiler::visitEVar(EVar *evar)
{
    if(*(evar->type) == BOOL){
        /* Boolean */
        stackIncrease(); emitILoad(localsEnv[evar->ident_]);
        stackDecrease(); emitConditional("ifne", ifTrueLabel, ifFalseLabel);
    }else{
        if(*(evar->type) == STR){
            /* String */
            stackIncrease(); emitALoad(localsEnv[evar->ident_]);
        }else{
            /* Integer */
            assert(*(evar->type) == INT);
            stackIncrease(); emitILoad(localsEnv[evar->ident_]);
        }
    }
}

void JVMCompiler::visitELitInt(ELitInt *elitint)
{
    stackIncrease(); emitPushInt(elitint->integer_);
}

void JVMCompiler::visitELitTrue(ELitTrue *elittrue __attribute__((__unused__)))
{
    emitGoto(ifTrueLabel);
}

void JVMCompiler::visitELitFalse(
            ELitFalse *elitfalse __attribute__((__unused__)))
{
    emitGoto(ifFalseLabel);
}

void JVMCompiler::visitEApp(EApp *eapp)
{
    if(eapp->ident_ == "printInt"){
        stackIncrease();
        emitInstr("getstatic java/lang/System/out Ljava/io/PrintStream;");
        (*(eapp->listexpr_))[0]->accept(this);
        stackDecrease(); stackDecrease();
        emitInstr("invokevirtual java/io/PrintStream/println(I)V");

    }else if(eapp->ident_ == "printString"){
        stackIncrease();
        emitInstr("getstatic java/lang/System/out Ljava/io/PrintStream;");
        (*(eapp->listexpr_))[0]->accept(this);
        stackDecrease(); stackDecrease();
        emitInstr(
            "invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");

    }else if(eapp->ident_ == "error"){
        stackIncrease();
        emitInstr(
            "invokestatic java/lang/Runtime/getRuntime()Ljava/lang/Runtime;");
        stackIncrease();
        emitPushInt(1);
        stackDecrease(); stackDecrease();
        emitInstr("invokevirtual java/lang/Runtime/halt(I)V");

    }else if(eapp->ident_ == "readInt"){
        emitPushLineFromStdin();
        emitInstr(
            "invokestatic java/lang/Integer.parseInt(Ljava/lang/String;)I");

    }else if(eapp->ident_ == "readString"){
        emitPushLineFromStdin();

    }else {
        uint16_t const ifTrue = ifTrueLabel;
        uint16_t const ifFalse = ifFalseLabel;

        for(auto i=eapp->listexpr_->begin(); i!=eapp->listexpr_->end(); ++i) {
            pushAsValue(*i);
        }
        for(auto i=eapp->listexpr_->begin(); i!=eapp->listexpr_->end(); ++i) {
            stackDecrease();
        }
        if(*(eapp->type) != LatteType(VOID))
            stackIncrease();
        emitInstr("invokestatic " + class_name + "/" +
                     eapp->ident_ + funTypes[eapp->ident_]->toJVMType());

        if(*(eapp->type) == BOOL){
            stackDecrease(); emitConditional("ifne", ifTrue, ifFalse);
        }
    }
}

void JVMCompiler::visitEString(EString *estring)
{
    stackIncrease(); emitPushString(estring->string_);
}

void JVMCompiler::visitENeg(ENeg *eneg)
{
    eneg->expr_->accept(this);
    emitInstr("ineg");
}

void JVMCompiler::visitENot(ENot *enot)
{
    std::swap(ifTrueLabel, ifFalseLabel);
    enot->expr_->accept(this);
}

void JVMCompiler::visitEMul(EMul *emul)
{
    emul->expr_1->accept(this);
    emul->expr_2->accept(this);
    emul->mulop_->accept(this);
}

void JVMCompiler::visitEAdd(EAdd *eadd)
{
    if(dynamic_cast<OPlus*>(eadd->addop_) != 0
            && (*(eadd->expr_1->type) == STR)){
        /* String concatenation */
        eadd->expr_1->accept(this);
        eadd->expr_2->accept(this);
        stackDecrease();
        emitInstr("invokevirtual java/lang/String/concat"
                        "(Ljava/lang/String;)Ljava/lang/String;");
    }else{
        /* Integer operation */
        assert(*(eadd->expr_1->type) == INT);
        eadd->expr_1->accept(this);
        eadd->expr_2->accept(this);
        eadd->addop_->accept(this);
    }
}

void JVMCompiler::visitERel(ERel *erel)
{
    uint16_t const ifTrue = ifTrueLabel;
    uint16_t const ifFalse = ifFalseLabel;

    pushAsValue(erel->expr_1);
    pushAsValue(erel->expr_2);

    ifTrueLabel = ifTrue;
    ifFalseLabel = ifFalse;
    erel->relop_->accept(this);
}

void JVMCompiler::visitEAnd(EAnd *eand)
{
    uint16_t const ifTrue = ifTrueLabel;
    uint16_t const ifFalse = ifFalseLabel;
    uint16_t const furtherCheck = newLabel();

    ifTrueLabel = furtherCheck;
    ifFalseLabel = ifFalse;
    eand->expr_1->accept(this);

    emitLabel(furtherCheck);
    ifTrueLabel = ifTrue;
    ifFalseLabel = ifFalse;
    eand->expr_2->accept(this);
}

void JVMCompiler::visitEOr(EOr *eor)
{
    uint16_t const ifTrue = ifTrueLabel;
    uint16_t const ifFalse = ifFalseLabel;
    uint16_t const furtherCheck = newLabel();

    ifTrueLabel = ifTrue;
    ifFalseLabel = furtherCheck;
    eor->expr_1->accept(this);

    emitLabel(furtherCheck);
    ifTrueLabel = ifTrue;
    ifFalseLabel = ifFalse;
    eor->expr_2->accept(this);
}

void JVMCompiler::visitOPlus(OPlus *oplus __attribute__((__unused__)))
{
    stackDecrease(); emitInstr("iadd");
}

void JVMCompiler::visitOMinus(OMinus *ominus __attribute__((__unused__)))
{
    stackDecrease(); emitInstr("isub");
}

void JVMCompiler::visitOTimes(OTimes *p __attribute__((__unused__)))
{
    stackDecrease(); emitInstr("imul");
}

void JVMCompiler::visitODiv(ODiv *p __attribute__((__unused__)))
{
    stackDecrease(); emitInstr("idiv");
}

void JVMCompiler::visitOMod(OMod *p __attribute__((__unused__)))
{
    stackDecrease(); emitInstr("irem");
}

void JVMCompiler::visitOLTH(OLTH *p __attribute__((__unused__)))
{
    stackDecrease(); stackDecrease();
    emitConditional("if_icmplt", ifTrueLabel, ifFalseLabel);
}

void JVMCompiler::visitOLE(OLE *p __attribute__((__unused__)))
{
    stackDecrease(); stackDecrease();
    emitConditional("if_icmple", ifTrueLabel, ifFalseLabel);
}

void JVMCompiler::visitOGTH(OGTH *p __attribute__((__unused__)))
{
    stackDecrease(); stackDecrease();
    emitConditional("if_icmpgt", ifTrueLabel, ifFalseLabel);
}

void JVMCompiler::visitOGE(OGE *p __attribute__((__unused__)))
{
    stackDecrease(); stackDecrease();
    emitConditional("if_icmpge", ifTrueLabel, ifFalseLabel);
}

void JVMCompiler::visitOEQU(OEQU *p __attribute__((__unused__)))
{
    stackDecrease(); stackDecrease();
    emitConditional("if_icmpeq", ifTrueLabel, ifFalseLabel);
}

void JVMCompiler::visitONE(ONE *p __attribute__((__unused__)))
{
    stackDecrease(); stackDecrease();
    emitConditional("if_icmpne", ifTrueLabel, ifFalseLabel);
}


void JVMCompiler::visitListTopDef(ListTopDef* listtopdef)
{
  for (auto i=listtopdef->begin() ; i!=listtopdef->end() ; ++i) {
    (*i)->accept(this);
  }
}

void JVMCompiler::visitListArg(ListArg* listarg)
{
  for (auto i=listarg->begin(); i!=listarg->end(); ++i) {
    (*i)->accept(this);
  }
}

void JVMCompiler::visitListStmt(ListStmt* liststmt)
{
  for (auto i = liststmt->begin(); i!=liststmt->end(); ++i) {
    (*i)->accept(this);
  }
}

void JVMCompiler::visitListItem(ListItem* listitem)
{
  for (auto i=listitem->begin(); i!=listitem->end(); ++i) {
    (*i)->accept(this);
  }
}

void JVMCompiler::pushAsValue(Expr* e)
{
    if(*(e->type) == BOOL){
        /* Boolean */
        uint16_t const ifTrue = newLabel();
        uint16_t const ifFalse = newLabel();
        uint16_t const endLabel = newLabel();
        ifTrueLabel = ifTrue;
        ifFalseLabel = ifFalse;
        e->accept(this);
        
        stackIncrease();
        emitLabel(ifTrue);
        emitPushInt(1);
        emitGoto(endLabel);

        emitLabel(ifFalse);
        emitPushInt(0);
        emitLabel(endLabel);
    }else{
        e->accept(this);
    }
}

void JVMCompiler::stackIncrease()
{
    current_stack++;
    max_stack = std::max(max_stack, current_stack);
}

void JVMCompiler::stackDecrease()
{
    current_stack--;
    assert(current_stack < 65535);
}

void JVMCompiler::emit(std::string const& line)
{
    (*output) << line << "\n";
}

void JVMCompiler::emit(std::string const& line, int const num)
{
    (*output) << line << num << "\n";
}

void JVMCompiler::emitInstr(std::string const& line)
{
    (*output) << "\t" << line << "\n";
}

void JVMCompiler::emitInstr(std::string const& line, int const num)
{
    (*output) << "\t" << line << num << "\n";
}

void JVMCompiler::emitAStore(uint16_t var)
{
    if(var < 4){
        emitInstr("astore_", var);
    }else{
        emitInstr("astore ", var);
    }
}

void JVMCompiler::emitIStore(uint16_t var)
{
    if(var < 4){
        emitInstr("istore_", var);
    }else{
        emitInstr("istore ", var);
    }
}

void JVMCompiler::emitALoad(uint16_t var)
{
    if(var < 4){
        emitInstr("aload_", var);
    }else{
        emitInstr("aload ", var);
    }
}

void JVMCompiler::emitILoad(uint16_t var)
{
    if(var < 4){
        emitInstr("iload_", var);
    }else{
        emitInstr("iload ", var);
    }
}

void JVMCompiler::emitGoto(uint32_t label)
{
    emitInstr("goto " + printLabel(label));
}

void JVMCompiler::emitConditional(
            std::string const& instr,
            uint32_t lab1,
            uint32_t lab2)
{
    std::stringstream s;
    s << instr << " " << printLabel(lab1);
    emitInstr(s.str());
    emitGoto(lab2);
}

void JVMCompiler::emitIInc(uint16_t var, int delta)
{
    std::stringstream s;
    s << "iinc " << var << " " << delta << "\n";
    emitInstr(s.str());
}

void JVMCompiler::emitPushInt(int const num)
{
    if(num <= 5 && num >= -1)
        emitInstr("iconst_", num);
    else if(num <= 127 && num >= -128)
        emitInstr("bipush ", num);
    else if(num <= 32767 && num >= -32768)
        emitInstr("sipush ", num);
    else
        emitInstr("ldc ", num);
}

void JVMCompiler::emitPushString(std::string const& str)
{
    std::stringstream instr;
    instr << "ldc \"";
    instr << std::oct;
    for(char c : str){
        if(isalnum(c))
            instr << c;
        else
            instr << '\\' << (int) c;
    }
    instr << "\"";
    emitInstr(instr.str());
}

void JVMCompiler::emitPushLineFromStdin()
{
    stackIncrease();
    emitInstr("getstatic " + class_name + "/scanner Ljava/util/Scanner;");
    emitInstr("invokevirtual java/util/Scanner/nextLine()Ljava/lang/String;");
}

std::string JVMCompiler::printLabel(uint32_t label)
{
    std::stringstream s;
    s << "l" << label;
    return s.str();
}

void JVMCompiler::emitLabel(uint32_t label)
{
    std::stringstream s;
    s << "l" << label << ":";
    emit(s.str());
}

uint16_t JVMCompiler::newLocal()
{
    uint16_t retval = locals_count;
    locals_count++;
    return retval;
}

uint32_t JVMCompiler::newLabel()
{
    uint32_t retval = labels_count;
    labels_count++;
    return retval;
}

};

