/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         latte_parseryyparse
#define yylex           latte_parseryylex
#define yyerror         latte_parseryyerror
#define yylval          latte_parseryylval
#define yychar          latte_parseryychar
#define yydebug         latte_parseryydebug
#define yynerrs         latte_parseryynerrs


/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 2 "Latte.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "Absyn.H"
typedef struct yy_buffer_state *YY_BUFFER_STATE;
int yyparse(void);
int yylex(void);
YY_BUFFER_STATE latte_parseryy_scan_string(const char *str);
void latte_parseryy_delete_buffer(YY_BUFFER_STATE buf);
int latte_parseryy_mylinenumber;
int latte_parserinitialize_lexer(FILE * inp);
int latte_parseryywrap(void)
{
  return 1;
}
void latte_parseryyerror(const char *str)
{
  std::cout << "line " << latte_parseryy_mylinenumber << std::endl ;
  fprintf(stderr,"error: %s\n",str);
}


namespace latte_parser
{
static Program* YY_RESULT_Program_ = 0;
Program* pProgram(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Program_;
  }
}
Program* pProgram(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Program_;
  }
}

static TopDef* YY_RESULT_TopDef_ = 0;
TopDef* pTopDef(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TopDef_;
  }
}
TopDef* pTopDef(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_TopDef_;
  }
}

static ListTopDef* YY_RESULT_ListTopDef_ = 0;
ListTopDef* pListTopDef(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListTopDef_;
  }
}
ListTopDef* pListTopDef(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListTopDef_;
  }
}

static Arg* YY_RESULT_Arg_ = 0;
Arg* pArg(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Arg_;
  }
}
Arg* pArg(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Arg_;
  }
}

static ListArg* YY_RESULT_ListArg_ = 0;
ListArg* pListArg(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListArg_;
  }
}
ListArg* pListArg(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListArg_;
  }
}

static Block* YY_RESULT_Block_ = 0;
Block* pBlock(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Block_;
  }
}
Block* pBlock(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Block_;
  }
}

static ListStmt* YY_RESULT_ListStmt_ = 0;
ListStmt* pListStmt(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStmt_;
  }
}
ListStmt* pListStmt(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStmt_;
  }
}

static Stmt* YY_RESULT_Stmt_ = 0;
Stmt* pStmt(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Stmt_;
  }
}
Stmt* pStmt(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Stmt_;
  }
}

static Item* YY_RESULT_Item_ = 0;
Item* pItem(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Item_;
  }
}
Item* pItem(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Item_;
  }
}

static ListItem* YY_RESULT_ListItem_ = 0;
ListItem* pListItem(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListItem_;
  }
}
ListItem* pListItem(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListItem_;
  }
}

static Type* YY_RESULT_Type_ = 0;
Type* pType(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}
Type* pType(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}

static Expr* YY_RESULT_Expr_ = 0;
Expr* pExpr(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Expr_;
  }
}
Expr* pExpr(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Expr_;
  }
}

static ListExpr* YY_RESULT_ListExpr_ = 0;
ListExpr* pListExpr(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExpr_;
  }
}
ListExpr* pListExpr(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExpr_;
  }
}

static AddOp* YY_RESULT_AddOp_ = 0;
AddOp* pAddOp(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_AddOp_;
  }
}
AddOp* pAddOp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_AddOp_;
  }
}

static MulOp* YY_RESULT_MulOp_ = 0;
MulOp* pMulOp(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_MulOp_;
  }
}
MulOp* pMulOp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_MulOp_;
  }
}

static RelOp* YY_RESULT_RelOp_ = 0;
RelOp* pRelOp(FILE *inp)
{
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_RelOp_;
  }
}
RelOp* pRelOp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  latte_parseryy_mylinenumber = 1;
  latte_parserinitialize_lexer(0);
  buf = latte_parseryy_scan_string(str);
  result = yyparse();
  latte_parseryy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_RelOp_;
  }
}


}


/* Line 268 of yacc.c  */
#line 639 "Parser.C"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _ERROR_ = 258,
     LATTE_PARSER__SYMB_0 = 259,
     LATTE_PARSER__SYMB_1 = 260,
     LATTE_PARSER__SYMB_2 = 261,
     LATTE_PARSER__SYMB_3 = 262,
     LATTE_PARSER__SYMB_4 = 263,
     LATTE_PARSER__SYMB_5 = 264,
     LATTE_PARSER__SYMB_6 = 265,
     LATTE_PARSER__SYMB_7 = 266,
     LATTE_PARSER__SYMB_8 = 267,
     LATTE_PARSER__SYMB_9 = 268,
     LATTE_PARSER__SYMB_10 = 269,
     LATTE_PARSER__SYMB_11 = 270,
     LATTE_PARSER__SYMB_12 = 271,
     LATTE_PARSER__SYMB_13 = 272,
     LATTE_PARSER__SYMB_14 = 273,
     LATTE_PARSER__SYMB_15 = 274,
     LATTE_PARSER__SYMB_16 = 275,
     LATTE_PARSER__SYMB_17 = 276,
     LATTE_PARSER__SYMB_18 = 277,
     LATTE_PARSER__SYMB_19 = 278,
     LATTE_PARSER__SYMB_20 = 279,
     LATTE_PARSER__SYMB_21 = 280,
     LATTE_PARSER__SYMB_22 = 281,
     LATTE_PARSER__SYMB_23 = 282,
     LATTE_PARSER__SYMB_24 = 283,
     LATTE_PARSER__SYMB_25 = 284,
     LATTE_PARSER__SYMB_26 = 285,
     LATTE_PARSER__SYMB_27 = 286,
     LATTE_PARSER__SYMB_28 = 287,
     LATTE_PARSER__SYMB_29 = 288,
     LATTE_PARSER__SYMB_30 = 289,
     LATTE_PARSER__SYMB_31 = 290,
     LATTE_PARSER__SYMB_32 = 291,
     _STRING_ = 292,
     _INTEGER_ = 293,
     _IDENT_ = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 562 "Latte.y"

  int int_;
  char char_;
  double double_;
  char* string_;
  latte_parser::Program* program_;
  latte_parser::TopDef* topdef_;
  latte_parser::ListTopDef* listtopdef_;
  latte_parser::Arg* arg_;
  latte_parser::ListArg* listarg_;
  latte_parser::Block* block_;
  latte_parser::ListStmt* liststmt_;
  latte_parser::Stmt* stmt_;
  latte_parser::Item* item_;
  latte_parser::ListItem* listitem_;
  latte_parser::Type* type_;
  latte_parser::Expr* expr_;
  latte_parser::ListExpr* listexpr_;
  latte_parser::AddOp* addop_;
  latte_parser::MulOp* mulop_;
  latte_parser::RelOp* relop_;




/* Line 293 of yacc.c  */
#line 740 "Parser.C"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 752 "Parser.C"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   132

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  107

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    12,    14,    17,    20,    21,    23,
      27,    31,    32,    35,    37,    39,    43,    48,    52,    56,
      60,    63,    69,    77,    83,    86,    88,    92,    94,    98,
     100,   102,   104,   106,   108,   110,   112,   114,   119,   121,
     125,   128,   131,   133,   137,   139,   143,   145,   149,   151,
     155,   157,   161,   163,   164,   166,   170,   172,   174,   176,
     178,   180,   182,   184,   186,   188,   190
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    43,    -1,    51,    39,     4,    45,     5,
      46,    -1,    42,    -1,    42,    43,    -1,    51,    39,    -1,
      -1,    44,    -1,    44,     6,    45,    -1,     7,    47,     8,
      -1,    -1,    47,    48,    -1,     9,    -1,    46,    -1,    51,
      50,     9,    -1,    39,    10,    58,     9,    -1,    39,    11,
       9,    -1,    39,    12,     9,    -1,    32,    58,     9,    -1,
      32,     9,    -1,    30,     4,    58,     5,    48,    -1,    30,
       4,    58,     5,    48,    28,    48,    -1,    36,     4,    58,
       5,    48,    -1,    58,     9,    -1,    39,    -1,    39,    10,
      58,    -1,    49,    -1,    49,     6,    50,    -1,    31,    -1,
      33,    -1,    27,    -1,    35,    -1,    39,    -1,    38,    -1,
      34,    -1,    29,    -1,    39,     4,    59,     5,    -1,    37,
      -1,     4,    58,     5,    -1,    13,    52,    -1,    14,    52,
      -1,    52,    -1,    54,    61,    53,    -1,    53,    -1,    55,
      60,    54,    -1,    54,    -1,    56,    62,    55,    -1,    55,
      -1,    56,    15,    57,    -1,    56,    -1,    57,    16,    58,
      -1,    57,    -1,    -1,    58,    -1,    58,     6,    59,    -1,
      17,    -1,    13,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,
      26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   652,   652,   654,   656,   657,   659,   661,   662,   663,
     665,   667,   668,   670,   671,   672,   673,   674,   675,   676,
     677,   678,   679,   680,   681,   683,   684,   686,   687,   689,
     690,   691,   692,   694,   695,   696,   697,   698,   699,   700,
     702,   703,   704,   706,   707,   709,   710,   712,   713,   715,
     716,   718,   719,   721,   722,   723,   725,   726,   728,   729,
     730,   732,   733,   734,   735,   736,   737
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ERROR_", "LATTE_PARSER__SYMB_0",
  "LATTE_PARSER__SYMB_1", "LATTE_PARSER__SYMB_2", "LATTE_PARSER__SYMB_3",
  "LATTE_PARSER__SYMB_4", "LATTE_PARSER__SYMB_5", "LATTE_PARSER__SYMB_6",
  "LATTE_PARSER__SYMB_7", "LATTE_PARSER__SYMB_8", "LATTE_PARSER__SYMB_9",
  "LATTE_PARSER__SYMB_10", "LATTE_PARSER__SYMB_11",
  "LATTE_PARSER__SYMB_12", "LATTE_PARSER__SYMB_13",
  "LATTE_PARSER__SYMB_14", "LATTE_PARSER__SYMB_15",
  "LATTE_PARSER__SYMB_16", "LATTE_PARSER__SYMB_17",
  "LATTE_PARSER__SYMB_18", "LATTE_PARSER__SYMB_19",
  "LATTE_PARSER__SYMB_20", "LATTE_PARSER__SYMB_21",
  "LATTE_PARSER__SYMB_22", "LATTE_PARSER__SYMB_23",
  "LATTE_PARSER__SYMB_24", "LATTE_PARSER__SYMB_25",
  "LATTE_PARSER__SYMB_26", "LATTE_PARSER__SYMB_27",
  "LATTE_PARSER__SYMB_28", "LATTE_PARSER__SYMB_29",
  "LATTE_PARSER__SYMB_30", "LATTE_PARSER__SYMB_31",
  "LATTE_PARSER__SYMB_32", "_STRING_", "_INTEGER_", "_IDENT_", "$accept",
  "Program", "TopDef", "ListTopDef", "Arg", "ListArg", "Block", "ListStmt",
  "Stmt", "Item", "ListItem", "Type", "Expr6", "Expr5", "Expr4", "Expr3",
  "Expr2", "Expr1", "Expr", "ListExpr", "AddOp", "MulOp", "RelOp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    43,    43,    44,    45,    45,    45,
      46,    47,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    49,    50,    50,    51,
      51,    51,    51,    52,    52,    52,    52,    52,    52,    52,
      53,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    59,    60,    60,    61,    61,
      61,    62,    62,    62,    62,    62,    62
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     1,     2,     2,     0,     1,     3,
       3,     0,     2,     1,     1,     3,     4,     3,     3,     3,
       2,     5,     7,     5,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       2,     2,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     0,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    31,    29,    30,    32,     0,     4,     2,     0,     1,
       5,     0,     7,     8,     0,     0,     7,     0,     6,     9,
      11,     3,     0,     0,    10,    13,     0,     0,    36,     0,
       0,    35,     0,    38,    34,    33,    14,    12,     0,    42,
      44,    46,    48,    50,    52,     0,    33,     0,    40,    41,
       0,    20,     0,     0,    53,     0,     0,     0,    25,    27,
       0,    58,    59,    60,     0,    57,    56,     0,     0,    61,
      62,    63,    64,    65,    66,     0,     0,    24,    39,     0,
      19,     0,    54,     0,     0,    17,    18,     0,     0,    15,
      43,    45,    49,    47,    51,     0,     0,    53,    37,    16,
      26,    28,    21,    23,    55,     0,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    13,    14,    36,    22,    37,    59,
      60,    38,    39,    40,    41,    42,    43,    44,    45,    83,
      67,    64,    75
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -94
static const yytype_int8 yypact[] =
{
      -9,   -94,   -94,   -94,   -94,     1,    -9,   -94,   -35,   -94,
     -94,     2,    -9,    10,    18,   -11,    -9,    27,   -94,   -94,
     -94,   -94,     6,    86,   -94,   -94,    72,    72,   -94,    45,
      59,   -94,    46,   -94,   -94,    55,   -94,   -94,    15,   -94,
     -94,    28,    12,   106,    35,    47,    54,    64,   -94,   -94,
      86,   -94,    51,    86,    86,    86,    61,    62,    79,    85,
      83,   -94,   -94,   -94,    86,   -94,   -94,    86,    86,   -94,
     -94,   -94,   -94,   -94,   -94,    86,    86,   -94,   -94,    89,
     -94,    90,    96,    98,    95,   -94,   -94,    86,    15,   -94,
     -94,    28,   -94,    12,   -94,    48,    48,    86,   -94,   -94,
     -94,   -94,    77,   -94,   -94,    48,   -94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -94,   101,   -94,    92,    97,   -94,   -93,   -94,
      24,     5,   -18,    49,    50,    41,   -94,    58,   -23,    21,
     -94,   -94,   -94
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      47,     9,   102,   103,    11,     8,    12,    52,    48,    49,
      23,     8,   106,    20,    24,    25,    16,    15,     1,    26,
      27,    15,     2,    17,     3,    65,     4,    79,    18,    66,
      81,    82,    84,     1,    20,    28,    29,     2,    30,     3,
      31,     4,    32,    33,    34,    35,    61,    62,    63,    50,
      53,    76,    23,    94,    58,    20,    77,    25,    54,    54,
      80,    26,    27,    23,   100,    55,    56,    57,    51,    78,
      85,    86,    26,    27,    82,     1,    23,    28,    29,     2,
      30,     3,    31,     4,    32,    33,    34,    35,    28,    87,
      23,    88,    89,    31,    95,    96,    33,    34,    46,    26,
      27,    28,    97,    98,    99,   105,    31,    10,    19,    33,
      34,    46,   101,    90,    21,    28,    93,    91,   104,     0,
      31,    68,     0,    33,    34,    46,    92,    69,    70,    71,
      72,    73,    74
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-94))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      23,     0,    95,    96,    39,     0,     4,    30,    26,    27,
       4,     6,   105,     7,     8,     9,     6,    12,    27,    13,
      14,    16,    31,     5,    33,    13,    35,    50,    39,    17,
      53,    54,    55,    27,     7,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    18,    19,    20,     4,
       4,    16,     4,    76,    39,     7,     9,     9,     4,     4,
       9,    13,    14,     4,    87,    10,    11,    12,     9,     5,
       9,     9,    13,    14,    97,    27,     4,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    29,    10,
       4,     6,     9,    34,     5,     5,    37,    38,    39,    13,
      14,    29,     6,     5,     9,    28,    34,     6,    16,    37,
      38,    39,    88,    64,    17,    29,    75,    67,    97,    -1,
      34,    15,    -1,    37,    38,    39,    68,    21,    22,    23,
      24,    25,    26
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    31,    33,    35,    41,    42,    43,    51,     0,
      43,    39,     4,    44,    45,    51,     6,     5,    39,    45,
       7,    46,    47,     4,     8,     9,    13,    14,    29,    30,
      32,    34,    36,    37,    38,    39,    46,    48,    51,    52,
      53,    54,    55,    56,    57,    58,    39,    58,    52,    52,
       4,     9,    58,     4,     4,    10,    11,    12,    39,    49,
      50,    18,    19,    20,    61,    13,    17,    60,    15,    21,
      22,    23,    24,    25,    26,    62,    16,     9,     5,    58,
       9,    58,    58,    59,    58,     9,     9,    10,     6,     9,
      53,    54,    57,    55,    58,     5,     5,     6,     5,     9,
      58,    50,    48,    48,    59,    28,    48
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 652 "Latte.y"
    {  std::reverse((yyvsp[(1) - (1)].listtopdef_)->begin(),(yyvsp[(1) - (1)].listtopdef_)->end()) ;(yyval.program_) = new latte_parser::PProg((yyvsp[(1) - (1)].listtopdef_)); (yyval.program_)->line_number = latte_parseryy_mylinenumber; latte_parser::YY_RESULT_Program_= (yyval.program_); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 654 "Latte.y"
    {  std::reverse((yyvsp[(4) - (6)].listarg_)->begin(),(yyvsp[(4) - (6)].listarg_)->end()) ;(yyval.topdef_) = new latte_parser::TFnDef((yyvsp[(1) - (6)].type_), (yyvsp[(2) - (6)].string_), (yyvsp[(4) - (6)].listarg_), (yyvsp[(6) - (6)].block_)); (yyval.topdef_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 656 "Latte.y"
    {  (yyval.listtopdef_) = new latte_parser::ListTopDef() ; (yyval.listtopdef_)->push_back((yyvsp[(1) - (1)].topdef_));  }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 657 "Latte.y"
    {  (yyvsp[(2) - (2)].listtopdef_)->push_back((yyvsp[(1) - (2)].topdef_)) ; (yyval.listtopdef_) = (yyvsp[(2) - (2)].listtopdef_) ;  }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 659 "Latte.y"
    {  (yyval.arg_) = new latte_parser::AArg((yyvsp[(1) - (2)].type_), (yyvsp[(2) - (2)].string_)); (yyval.arg_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 661 "Latte.y"
    {  (yyval.listarg_) = new latte_parser::ListArg();  }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 662 "Latte.y"
    {  (yyval.listarg_) = new latte_parser::ListArg() ; (yyval.listarg_)->push_back((yyvsp[(1) - (1)].arg_));  }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 663 "Latte.y"
    {  (yyvsp[(3) - (3)].listarg_)->push_back((yyvsp[(1) - (3)].arg_)) ; (yyval.listarg_) = (yyvsp[(3) - (3)].listarg_) ;  }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 665 "Latte.y"
    {  (yyval.block_) = new latte_parser::BBlock((yyvsp[(2) - (3)].liststmt_)); (yyval.block_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 667 "Latte.y"
    {  (yyval.liststmt_) = new latte_parser::ListStmt();  }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 668 "Latte.y"
    {  (yyvsp[(1) - (2)].liststmt_)->push_back((yyvsp[(2) - (2)].stmt_)) ; (yyval.liststmt_) = (yyvsp[(1) - (2)].liststmt_) ;  }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 670 "Latte.y"
    {  (yyval.stmt_) = new latte_parser::SEmpty(); (yyval.stmt_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 671 "Latte.y"
    {  (yyval.stmt_) = new latte_parser::SBStmt((yyvsp[(1) - (1)].block_)); (yyval.stmt_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 672 "Latte.y"
    {  std::reverse((yyvsp[(2) - (3)].listitem_)->begin(),(yyvsp[(2) - (3)].listitem_)->end()) ;(yyval.stmt_) = new latte_parser::SDecl((yyvsp[(1) - (3)].type_), (yyvsp[(2) - (3)].listitem_)); (yyval.stmt_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 673 "Latte.y"
    {  (yyval.stmt_) = new latte_parser::SAss((yyvsp[(1) - (4)].string_), (yyvsp[(3) - (4)].expr_)); (yyval.stmt_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 674 "Latte.y"
    {  (yyval.stmt_) = new latte_parser::SIncr((yyvsp[(1) - (3)].string_)); (yyval.stmt_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 675 "Latte.y"
    {  (yyval.stmt_) = new latte_parser::SDecr((yyvsp[(1) - (3)].string_)); (yyval.stmt_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 676 "Latte.y"
    {  (yyval.stmt_) = new latte_parser::SRet((yyvsp[(2) - (3)].expr_)); (yyval.stmt_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 677 "Latte.y"
    {  (yyval.stmt_) = new latte_parser::SVRet(); (yyval.stmt_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 678 "Latte.y"
    {  (yyval.stmt_) = new latte_parser::SCond((yyvsp[(3) - (5)].expr_), (yyvsp[(5) - (5)].stmt_)); (yyval.stmt_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 679 "Latte.y"
    {  (yyval.stmt_) = new latte_parser::SCondElse((yyvsp[(3) - (7)].expr_), (yyvsp[(5) - (7)].stmt_), (yyvsp[(7) - (7)].stmt_)); (yyval.stmt_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 680 "Latte.y"
    {  (yyval.stmt_) = new latte_parser::SWhile((yyvsp[(3) - (5)].expr_), (yyvsp[(5) - (5)].stmt_)); (yyval.stmt_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 681 "Latte.y"
    {  (yyval.stmt_) = new latte_parser::SSExp((yyvsp[(1) - (2)].expr_)); (yyval.stmt_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 683 "Latte.y"
    {  (yyval.item_) = new latte_parser::INoInit((yyvsp[(1) - (1)].string_)); (yyval.item_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 684 "Latte.y"
    {  (yyval.item_) = new latte_parser::IInit((yyvsp[(1) - (3)].string_), (yyvsp[(3) - (3)].expr_)); (yyval.item_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 686 "Latte.y"
    {  (yyval.listitem_) = new latte_parser::ListItem() ; (yyval.listitem_)->push_back((yyvsp[(1) - (1)].item_));  }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 687 "Latte.y"
    {  (yyvsp[(3) - (3)].listitem_)->push_back((yyvsp[(1) - (3)].item_)) ; (yyval.listitem_) = (yyvsp[(3) - (3)].listitem_) ;  }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 689 "Latte.y"
    {  (yyval.type_) = new latte_parser::TInt(); (yyval.type_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 690 "Latte.y"
    {  (yyval.type_) = new latte_parser::TStr(); (yyval.type_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 691 "Latte.y"
    {  (yyval.type_) = new latte_parser::TBool(); (yyval.type_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 692 "Latte.y"
    {  (yyval.type_) = new latte_parser::TVoid(); (yyval.type_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 694 "Latte.y"
    {  (yyval.expr_) = new latte_parser::EVar((yyvsp[(1) - (1)].string_)); (yyval.expr_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 695 "Latte.y"
    {  (yyval.expr_) = new latte_parser::ELitInt((yyvsp[(1) - (1)].int_)); (yyval.expr_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 696 "Latte.y"
    {  (yyval.expr_) = new latte_parser::ELitTrue(); (yyval.expr_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 697 "Latte.y"
    {  (yyval.expr_) = new latte_parser::ELitFalse(); (yyval.expr_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 698 "Latte.y"
    {  std::reverse((yyvsp[(3) - (4)].listexpr_)->begin(),(yyvsp[(3) - (4)].listexpr_)->end()) ;(yyval.expr_) = new latte_parser::EApp((yyvsp[(1) - (4)].string_), (yyvsp[(3) - (4)].listexpr_)); (yyval.expr_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 699 "Latte.y"
    {  (yyval.expr_) = new latte_parser::EString((yyvsp[(1) - (1)].string_)); (yyval.expr_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 700 "Latte.y"
    {  (yyval.expr_) = (yyvsp[(2) - (3)].expr_);  }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 702 "Latte.y"
    {  (yyval.expr_) = new latte_parser::ENeg((yyvsp[(2) - (2)].expr_)); (yyval.expr_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 703 "Latte.y"
    {  (yyval.expr_) = new latte_parser::ENot((yyvsp[(2) - (2)].expr_)); (yyval.expr_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 704 "Latte.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 706 "Latte.y"
    {  (yyval.expr_) = new latte_parser::EMul((yyvsp[(1) - (3)].expr_), (yyvsp[(2) - (3)].mulop_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 707 "Latte.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 709 "Latte.y"
    {  (yyval.expr_) = new latte_parser::EAdd((yyvsp[(1) - (3)].expr_), (yyvsp[(2) - (3)].addop_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 710 "Latte.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 712 "Latte.y"
    {  (yyval.expr_) = new latte_parser::ERel((yyvsp[(1) - (3)].expr_), (yyvsp[(2) - (3)].relop_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 713 "Latte.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 715 "Latte.y"
    {  (yyval.expr_) = new latte_parser::EAnd((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 716 "Latte.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 718 "Latte.y"
    {  (yyval.expr_) = new latte_parser::EOr((yyvsp[(1) - (3)].expr_), (yyvsp[(3) - (3)].expr_)); (yyval.expr_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 719 "Latte.y"
    {  (yyval.expr_) = (yyvsp[(1) - (1)].expr_);  }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 721 "Latte.y"
    {  (yyval.listexpr_) = new latte_parser::ListExpr();  }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 722 "Latte.y"
    {  (yyval.listexpr_) = new latte_parser::ListExpr() ; (yyval.listexpr_)->push_back((yyvsp[(1) - (1)].expr_));  }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 723 "Latte.y"
    {  (yyvsp[(3) - (3)].listexpr_)->push_back((yyvsp[(1) - (3)].expr_)) ; (yyval.listexpr_) = (yyvsp[(3) - (3)].listexpr_) ;  }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 725 "Latte.y"
    {  (yyval.addop_) = new latte_parser::OPlus(); (yyval.addop_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 726 "Latte.y"
    {  (yyval.addop_) = new latte_parser::OMinus(); (yyval.addop_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 728 "Latte.y"
    {  (yyval.mulop_) = new latte_parser::OTimes(); (yyval.mulop_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 729 "Latte.y"
    {  (yyval.mulop_) = new latte_parser::ODiv(); (yyval.mulop_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 730 "Latte.y"
    {  (yyval.mulop_) = new latte_parser::OMod(); (yyval.mulop_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 732 "Latte.y"
    {  (yyval.relop_) = new latte_parser::OLTH(); (yyval.relop_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 733 "Latte.y"
    {  (yyval.relop_) = new latte_parser::OLE(); (yyval.relop_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 734 "Latte.y"
    {  (yyval.relop_) = new latte_parser::OGTH(); (yyval.relop_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 735 "Latte.y"
    {  (yyval.relop_) = new latte_parser::OGE(); (yyval.relop_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 736 "Latte.y"
    {  (yyval.relop_) = new latte_parser::OEQU(); (yyval.relop_)->line_number = latte_parseryy_mylinenumber;  }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 737 "Latte.y"
    {  (yyval.relop_) = new latte_parser::ONE(); (yyval.relop_)->line_number = latte_parseryy_mylinenumber;  }
    break;



/* Line 1806 of yacc.c  */
#line 2543 "Parser.C"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
       fprintf(stderr, "ERROR\n");yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



