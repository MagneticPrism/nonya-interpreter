/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    COLON = 258,                   /* COLON  */
    EXCL_MARK = 259,               /* EXCL_MARK  */
    ARROW_FUN = 260,               /* ARROW_FUN  */
    COLON_COLON = 261,             /* COLON_COLON  */
    COMMA = 262,                   /* COMMA  */
    SINGLE_QUOTES = 263,           /* SINGLE_QUOTES  */
    SEMI_COLON = 264,              /* SEMI_COLON  */
    EQUALS = 265,                  /* EQUALS  */
    BRACKET_OPEN = 266,            /* BRACKET_OPEN  */
    BRACKET_CLOSE = 267,           /* BRACKET_CLOSE  */
    CURLY_BRACE_OPEN = 268,        /* CURLY_BRACE_OPEN  */
    CURLY_BRACE_CLOSE = 269,       /* CURLY_BRACE_CLOSE  */
    BIG_BRACKET_OPEN = 270,        /* BIG_BRACKET_OPEN  */
    BIG_BRACKET_CLOSE = 271,       /* BIG_BRACKET_CLOSE  */
    CHARACTER_VALUE = 272,         /* CHARACTER_VALUE  */
    INTEGER_VALUE = 273,           /* INTEGER_VALUE  */
    FLOAT_VALUE = 274,             /* FLOAT_VALUE  */
    STRING_VALUE = 275,            /* STRING_VALUE  */
    INT = 276,                     /* INT  */
    FLOAT = 277,                   /* FLOAT  */
    STRING = 278,                  /* STRING  */
    DATA_TYPE = 279,               /* DATA_TYPE  */
    IDENTIFIER = 280,              /* IDENTIFIER  */
    ARRAY_IDENTIFIER = 281,        /* ARRAY_IDENTIFIER  */
    STRUCT = 282,                  /* STRUCT  */
    NAMESPACE = 283,               /* NAMESPACE  */
    IF = 284,                      /* IF  */
    ELSE = 285,                    /* ELSE  */
    ELSEIF = 286,                  /* ELSEIF  */
    RETURN = 287,                  /* RETURN  */
    IS = 288,                      /* IS  */
    NOT = 289,                     /* NOT  */
    PRINT = 290,                   /* PRINT  */
    EXECUTE = 291                  /* EXECUTE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define COLON 258
#define EXCL_MARK 259
#define ARROW_FUN 260
#define COLON_COLON 261
#define COMMA 262
#define SINGLE_QUOTES 263
#define SEMI_COLON 264
#define EQUALS 265
#define BRACKET_OPEN 266
#define BRACKET_CLOSE 267
#define CURLY_BRACE_OPEN 268
#define CURLY_BRACE_CLOSE 269
#define BIG_BRACKET_OPEN 270
#define BIG_BRACKET_CLOSE 271
#define CHARACTER_VALUE 272
#define INTEGER_VALUE 273
#define FLOAT_VALUE 274
#define STRING_VALUE 275
#define INT 276
#define FLOAT 277
#define STRING 278
#define DATA_TYPE 279
#define IDENTIFIER 280
#define ARRAY_IDENTIFIER 281
#define STRUCT 282
#define NAMESPACE 283
#define IF 284
#define ELSE 285
#define ELSEIF 286
#define RETURN 287
#define IS 288
#define NOT 289
#define PRINT 290
#define EXECUTE 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "syntax2.y"

  int intVal;
  char* dataType;
  char* strVal;
  float floatVal;
  char charVal;

#line 146 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
