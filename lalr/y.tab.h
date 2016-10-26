/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER_TYPE = 258,
     NUMBER_TYPE = 259,
     BOOLEAN_TYPE = 260,
     TEXT_TYPE = 261,
     CAST = 262,
     LPAREN = 263,
     COMMA = 264,
     ID = 265,
     RPAREN = 266,
     OR = 267,
     AND = 268,
     NOTEQ = 269,
     EQ = 270,
     GR = 271,
     LE = 272,
     GREQ = 273,
     LEEQ = 274,
     PLUS_OP = 275,
     MINUS_OP = 276,
     TIMES_OP = 277,
     DIV_OP = 278,
     FALSE = 279,
     TRUE = 280,
     NUMBER = 281,
     TEXT = 282,
     INTEGER = 283,
     DOT = 284,
     ACTION = 285,
     END = 286,
     RETURNS = 287,
     COLON = 288,
     CLASS = 289,
     IS = 290,
     REPEAT = 291,
     WHILE = 292,
     UNTIL = 293,
     IF = 294,
     ELSEIF = 295,
     ELSE = 296,
     USE = 297,
     CHECK = 298,
     DETECT = 299,
     ALWAYS = 300,
     TIMES = 301,
     BAD_COMMENT = 302,
     ERROR = 303,
     END_OF_FILE = 304
   };
#endif
/* Tokens.  */
#define INTEGER_TYPE 258
#define NUMBER_TYPE 259
#define BOOLEAN_TYPE 260
#define TEXT_TYPE 261
#define CAST 262
#define LPAREN 263
#define COMMA 264
#define ID 265
#define RPAREN 266
#define OR 267
#define AND 268
#define NOTEQ 269
#define EQ 270
#define GR 271
#define LE 272
#define GREQ 273
#define LEEQ 274
#define PLUS_OP 275
#define MINUS_OP 276
#define TIMES_OP 277
#define DIV_OP 278
#define FALSE 279
#define TRUE 280
#define NUMBER 281
#define TEXT 282
#define INTEGER 283
#define DOT 284
#define ACTION 285
#define END 286
#define RETURNS 287
#define COLON 288
#define CLASS 289
#define IS 290
#define REPEAT 291
#define WHILE 292
#define UNTIL 293
#define IF 294
#define ELSEIF 295
#define ELSE 296
#define USE 297
#define CHECK 298
#define DETECT 299
#define ALWAYS 300
#define TIMES 301
#define BAD_COMMENT 302
#define ERROR 303
#define END_OF_FILE 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

