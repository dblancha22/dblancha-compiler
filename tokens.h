/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ARRAY = 258,
    AUTO = 259,
    BOOLEAN = 260,
    CHAR = 261,
    ELSE = 262,
    FALSE = 263,
    FOR = 264,
    FUNCTION = 265,
    IF = 266,
    INTEGER = 267,
    PRINT = 268,
    RETURN = 269,
    STRING = 270,
    TRUE = 271,
    VOID = 272,
    WHILE = 273,
    AND = 274,
    OR = 275,
    SEMICOLON = 276,
    COLON = 277,
    EQUALS = 278,
    GT = 279,
    GE = 280,
    LT = 281,
    LE = 282,
    EE = 283,
    NE = 284,
    INCREMENT = 285,
    DECREMENT = 286,
    OPEN_PAREN = 287,
    CLOSE_PAREN = 288,
    OPEN_CURLY = 289,
    CLOSE_CURLY = 290,
    OPEN_BRACK = 291,
    CLOSE_BRACK = 292,
    IDENTIFIER = 293,
    CHAR_LITERAL = 294,
    INTEGER_LITERAL = 295,
    BOOLEAN_LITERAL = 296,
    STRING_LITERAL = 297,
    COMMENT = 298,
    REMAINDER = 299,
    EXP = 300,
    PLUS = 301,
    MINUS = 302,
    MULTIPLY = 303,
    DIVIDE = 304,
    NOT = 305,
    QUESTION = 306,
    COMMA = 307,
    TOKEN_ERROR = 308,
    TOKEN_EOF = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */
