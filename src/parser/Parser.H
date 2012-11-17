#ifndef LATTE_PARSER_PARSER_HEADER_FILE
#define LATTE_PARSER_PARSER_HEADER_FILE

#include<vector>
#include<string>

namespace latte_parser
{
class Program;
class TopDef;
class ListTopDef;
class Arg;
class ListArg;
class Block;
class ListStmt;
class Stmt;
class Item;
class ListItem;
class Type;
class Expr;
class ListExpr;
class AddOp;
class MulOp;
class RelOp;

typedef union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Program* program_;
  TopDef* topdef_;
  ListTopDef* listtopdef_;
  Arg* arg_;
  ListArg* listarg_;
  Block* block_;
  ListStmt* liststmt_;
  Stmt* stmt_;
  Item* item_;
  ListItem* listitem_;
  Type* type_;
  Expr* expr_;
  ListExpr* listexpr_;
  AddOp* addop_;
  MulOp* mulop_;
  RelOp* relop_;
} YYSTYPE;

Program* pProgram(FILE *inp);
Program* pProgram(const char *str);

}

#define LATTE_PARSER__ERROR_ 258
#define LATTE_PARSER__SYMB_0 259
#define LATTE_PARSER__SYMB_1 260
#define LATTE_PARSER__SYMB_2 261
#define LATTE_PARSER__SYMB_3 262
#define LATTE_PARSER__SYMB_4 263
#define LATTE_PARSER__SYMB_5 264
#define LATTE_PARSER__SYMB_6 265
#define LATTE_PARSER__SYMB_7 266
#define LATTE_PARSER__SYMB_8 267
#define LATTE_PARSER__SYMB_9 268
#define LATTE_PARSER__SYMB_10 269
#define LATTE_PARSER__SYMB_11 270
#define LATTE_PARSER__SYMB_12 271
#define LATTE_PARSER__SYMB_13 272
#define LATTE_PARSER__SYMB_14 273
#define LATTE_PARSER__SYMB_15 274
#define LATTE_PARSER__SYMB_16 275
#define LATTE_PARSER__SYMB_17 276
#define LATTE_PARSER__SYMB_18 277
#define LATTE_PARSER__SYMB_19 278
#define LATTE_PARSER__SYMB_20 279
#define LATTE_PARSER__SYMB_21 280
#define LATTE_PARSER__SYMB_22 281
#define LATTE_PARSER__SYMB_23 282
#define LATTE_PARSER__SYMB_24 283
#define LATTE_PARSER__SYMB_25 284
#define LATTE_PARSER__SYMB_26 285
#define LATTE_PARSER__SYMB_27 286
#define LATTE_PARSER__SYMB_28 287
#define LATTE_PARSER__SYMB_29 288
#define LATTE_PARSER__SYMB_30 289
#define LATTE_PARSER__SYMB_31 290
#define LATTE_PARSER__SYMB_32 291
#define LATTE_PARSER__STRING_ 292
#define LATTE_PARSER__INTEGER_ 293
#define LATTE_PARSER__IDENT_ 294

extern latte_parser::YYSTYPE latte_parseryylval;

#endif
