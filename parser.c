/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.bison" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include "expr.h"
    #include "stmt.h"
    #include "decl.h"
    extern char *yytext;
    extern int yylex();
    extern int yyerror(char *str);
    
    struct decl* root;

#line 79 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "tokens.h".  */
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

union YYSTYPE
{
#line 70 "parser.bison" /* yacc.c:355  */

      struct decl* decl;
      struct stmt* stmt;
      struct expr* expr;
      char* str;
      struct type* type;
      struct param_list* param_list;

#line 183 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 200 "parser.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    95,    98,    99,   100,   101,   104,   106,
     109,   110,   113,   114,   115,   116,   117,   118,   122,   123,
     124,   125,   126,   127,   128,   131,   132,   133,   134,   135,
     136,   137,   140,   141,   144,   145,   148,   149,   150,   151,
     152,   153,   155,   158,   161,   162,   165,   167,   168,   169,
     172,   173,   174,   177,   178,   179,   180,   181,   184,   185,
     188,   189,   192,   193,   196,   197,   198,   201,   202,   205,
     206,   209,   210,   211,   212,   213,   214,   215,   218,   219,
     220,   223,   224,   225,   226,   229,   230,   233,   234,   235,
     238,   239,   240,   243,   244,   245,   246,   249,   252,   253,
     256,   259,   260,   263,   264,   267,   268,   271,   272,   275,
     276,   277,   278,   279,   280
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ARRAY", "AUTO", "BOOLEAN", "CHAR",
  "ELSE", "FALSE", "FOR", "FUNCTION", "IF", "INTEGER", "PRINT", "RETURN",
  "STRING", "TRUE", "VOID", "WHILE", "AND", "OR", "SEMICOLON", "COLON",
  "EQUALS", "GT", "GE", "LT", "LE", "EE", "NE", "INCREMENT", "DECREMENT",
  "OPEN_PAREN", "CLOSE_PAREN", "OPEN_CURLY", "CLOSE_CURLY", "OPEN_BRACK",
  "CLOSE_BRACK", "IDENTIFIER", "CHAR_LITERAL", "INTEGER_LITERAL",
  "BOOLEAN_LITERAL", "STRING_LITERAL", "COMMENT", "REMAINDER", "EXP",
  "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "NOT", "QUESTION", "COMMA",
  "TOKEN_ERROR", "TOKEN_EOF", "$accept", "program", "decl_list",
  "decl_var", "decl_func", "type_var", "type_var_arr", "type_func",
  "param_epsilon", "param_list", "type_param", "stmt_0", "if_stmt",
  "if_loop", "else_stmt", "closed_if", "stmt", "stmts_epsilon",
  "bunch_o_stmts", "expr_1_epsilon", "expr_1", "expr_2", "expr_3",
  "expr_4", "expr_5", "expr_6", "expr_7", "expr_8", "expr_9", "expr_10",
  "array_start", "brack_list", "func_call", "func_args", "func_args_e",
  "expr_epsilon", "expr_list", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -172

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-172)))

#define YYTABLE_NINF -24

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -32,     1,    40,  -172,   -32,   -32,   107,  -172,  -172,  -172,
      14,    30,    35,    64,    90,    76,    83,    88,    85,    27,
      65,    65,    65,    90,    65,    65,    65,     8,  -172,    51,
      51,    51,   134,    16,  -172,  -172,  -172,  -172,    51,    51,
      81,    -4,   101,   139,    26,   -16,    78,  -172,    73,  -172,
    -172,  -172,  -172,   -24,  -172,  -172,  -172,    65,  -172,  -172,
    -172,  -172,    94,   100,    97,    82,   109,    99,  -172,  -172,
    -172,  -172,  -172,  -172,    51,    51,  -172,  -172,  -172,   134,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,  -172,  -172,  -172,   123,
     114,  -172,     4,  -172,  -172,    51,  -172,    51,    96,  -172,
     124,   132,   135,   101,  -172,   138,   139,    26,    26,    26,
      26,    26,    26,   -16,   -16,    78,    78,    78,  -172,   121,
    -172,   129,   146,    51,    51,     4,    48,  -172,     4,  -172,
    -172,  -172,  -172,   144,  -172,   159,  -172,   145,    51,  -172,
     148,    51,   149,  -172,  -172,  -172,  -172,  -172,  -172,   131,
      51,    51,     4,   160,  -172,   165,  -172,   152,   -13,   147,
    -172,  -172,  -172,   134,  -172,  -172,  -172,   151,   153,   168,
     157,  -172,   185,  -172,  -172,  -172,  -172,   121,  -172,    51,
    -172,     4,  -172,   172,  -172,  -172,    51,   161,     4,  -172,
    -172
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     6,     7,     0,     1,     4,     5,
       0,    16,    13,    15,     0,    12,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       0,     0,     0,   113,   111,   109,   110,   112,     0,     0,
       0,    66,    68,    70,    77,    80,    84,    86,    89,    92,
      95,    94,    96,     0,    31,    26,    28,     0,    25,    27,
      29,    11,     0,     0,     0,   108,     0,     0,    16,    13,
      15,    12,    14,    24,   104,     0,    97,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    33,     0,
       0,    30,    59,     9,    93,     0,   114,     0,   102,   103,
       0,     0,    17,    67,    64,     0,    69,    71,    72,    73,
      74,    75,    76,    78,    79,    83,    81,    82,    85,     0,
      32,     0,     0,   106,    63,    59,   113,    57,    61,    43,
      44,    45,    49,     0,    58,     0,   107,     0,     0,   100,
      99,     0,     0,    40,    37,    39,    41,    36,    38,    35,
      63,     0,     0,     0,   105,     0,    62,     0,   108,     0,
      60,    10,    56,     0,   101,    98,    65,     0,     0,     0,
       0,    50,    44,    55,    53,    54,    17,     0,    34,    63,
      46,     0,    42,     0,    47,    51,    63,     0,     0,    48,
      52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -172,  -172,    74,    71,  -172,   -30,  -172,   173,     0,    17,
      10,  -172,    36,  -172,  -161,  -171,  -172,    66,    61,  -155,
     -19,  -172,   120,   119,    87,    -9,    62,   -35,  -172,  -172,
    -172,    53,  -172,    56,  -172,  -172,   -98,  -172
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   137,     5,    17,    18,    27,    54,   100,
     159,   138,   139,   162,   140,   141,   142,   143,   144,   165,
     145,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    76,    51,   109,   110,   163,    66,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,   182,    73,    77,    78,   179,     1,   146,   172,    98,
      63,    64,    65,   131,    99,   132,    80,   133,   134,    81,
     195,    55,    56,     6,    58,    59,    60,   200,    92,    61,
     194,    62,    93,    94,   193,   164,    30,   199,   135,   105,
       7,   197,   136,    34,    35,    36,    37,    82,    74,   112,
      19,    38,    75,   -22,    39,   108,   111,   101,   -19,    30,
     128,    31,   114,   115,    32,    33,    34,    35,    36,    37,
     169,     4,    90,    91,    38,     4,     4,    39,     8,     9,
      74,   123,   124,    30,    75,    31,    65,   -21,   147,    33,
      34,    35,    36,    37,    20,    21,    22,    53,    38,   -18,
      23,    39,    24,    96,    97,    25,   -20,    26,    29,    28,
      10,    11,    12,    13,    65,   166,   168,    14,    79,    15,
      83,   103,    16,    95,   152,   153,   154,   155,   102,   108,
     104,   156,   176,   157,   105,   107,   158,    67,    68,    69,
      70,   166,   180,   186,   106,   129,    71,   130,   148,    72,
      10,    11,    12,    13,   125,   126,   127,   149,   -23,    15,
     151,   160,    16,    84,    85,    86,    87,    88,    89,   150,
     166,   117,   118,   119,   120,   121,   122,   166,   161,   171,
     172,   183,   173,   178,    75,   177,   184,   185,   187,   189,
     190,    99,   191,   196,   198,   188,    57,   192,   181,   170,
     113,   167,   116,   175,   174
};

static const yytype_uint8 yycheck[] =
{
      19,   162,    32,    38,    39,   160,    38,   105,    21,    33,
      29,    30,    31,     9,    38,    11,    20,    13,    14,    23,
     191,    21,    22,    22,    24,    25,    26,   198,    44,    21,
     191,    23,    48,    49,   189,   133,    32,   198,    34,    52,
       0,   196,    38,    39,    40,    41,    42,    51,    32,    79,
      36,    47,    36,    23,    50,    74,    75,    57,    23,    32,
      95,    34,    81,    82,    37,    38,    39,    40,    41,    42,
      22,     0,    46,    47,    47,     4,     5,    50,     4,     5,
      32,    90,    91,    32,    36,    34,   105,    23,   107,    38,
      39,    40,    41,    42,     4,     5,     6,    32,    47,    23,
      10,    50,    12,    30,    31,    15,    23,    17,    23,    21,
       3,     4,     5,     6,   133,   134,   135,    10,    37,    12,
      19,    21,    15,    45,     3,     4,     5,     6,    34,   148,
      33,    10,   151,    12,    52,    36,    15,     3,     4,     5,
       6,   160,   161,   173,    35,    22,    12,    33,    52,    15,
       3,     4,     5,     6,    92,    93,    94,    33,    23,    12,
      22,    32,    15,    24,    25,    26,    27,    28,    29,    37,
     189,    84,    85,    86,    87,    88,    89,   196,    32,    35,
      21,    21,    37,    52,    36,    36,    21,    35,    37,    21,
      33,    38,     7,    21,    33,   178,    23,   187,   162,   138,
      80,   135,    83,   150,   148
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    56,    57,    58,    59,    22,     0,    57,    57,
       3,     4,     5,     6,    10,    12,    15,    60,    61,    36,
       4,     5,     6,    10,    12,    15,    17,    62,    21,    23,
      32,    34,    37,    38,    39,    40,    41,    42,    47,    50,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    87,    92,    32,    63,    63,    63,    62,    63,    63,
      63,    21,    23,    75,    75,    75,    91,     3,     4,     5,
       6,    12,    15,    60,    32,    36,    86,    82,    82,    37,
      20,    23,    51,    19,    24,    25,    26,    27,    28,    29,
      46,    47,    44,    48,    49,    45,    30,    31,    33,    38,
      64,    63,    34,    21,    33,    52,    35,    36,    75,    88,
      89,    75,    60,    77,    75,    75,    78,    79,    79,    79,
      79,    79,    79,    80,    80,    81,    81,    81,    82,    22,
      33,     9,    11,    13,    14,    34,    38,    58,    66,    67,
      69,    70,    71,    72,    73,    75,    91,    75,    52,    33,
      37,    22,     3,     4,     5,     6,    10,    12,    15,    65,
      32,    32,    68,    90,    91,    74,    75,    72,    75,    22,
      73,    35,    21,    37,    88,    86,    75,    36,    52,    74,
      75,    67,    69,    21,    21,    35,    60,    37,    64,    21,
      33,     7,    65,    74,    69,    70,    21,    74,    33,    69,
      70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    57,    57,    58,    58,
      59,    59,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    66,    67,    67,    68,    69,    69,    69,
      70,    70,    70,    71,    71,    71,    71,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    75,    76,    76,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      79,    80,    80,    80,    80,    81,    81,    82,    82,    82,
      83,    83,    83,    84,    84,    84,    84,    85,    86,    86,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    92,    92,    92,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     1,     1,     4,     6,
       8,     5,     1,     1,     1,     1,     1,     5,     1,     1,
       1,     1,     1,     5,     4,     2,     2,     2,     2,     2,
       3,     2,     3,     2,     5,     3,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     3,     5,     9,     1,
       3,     5,     9,     3,     3,     3,     2,     1,     1,     0,
       2,     1,     1,     0,     3,     5,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     1,     2,     2,     1,
       2,     2,     1,     3,     1,     1,     1,     2,     4,     3,
       4,     3,     1,     1,     0,     1,     0,     3,     1,     1,
       1,     1,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 94 "parser.bison" /* yacc.c:1646  */
    {root = (yyvsp[0].decl); }
#line 1428 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 95 "parser.bison" /* yacc.c:1646  */
    { root = NULL; }
#line 1434 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 98 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create_list((yyvsp[-1].decl), (yyvsp[0].decl)); }
#line 1440 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 99 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create_list((yyvsp[-1].decl), (yyvsp[0].decl)); }
#line 1446 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 100 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); }
#line 1452 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].decl); }
#line 1458 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 104 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-3].str), (yyvsp[-1].type), NULL, NULL, NULL); }
#line 1464 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 106 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-5].str), (yyvsp[-3].type), (yyvsp[-1].expr), NULL, NULL); }
#line 1470 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 109 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create_func((yyvsp[-7].str), (yyvsp[-4].type), (yyvsp[-1].stmt)); }
#line 1476 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 110 "parser.bison" /* yacc.c:1646  */
    { (yyval.decl) = decl_create((yyvsp[-4].str), (yyvsp[-1].type), NULL, NULL, NULL); }
#line 1482 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 113 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_INTEGER, NULL, NULL); }
#line 1488 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 114 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_BOOLEAN, NULL, NULL); }
#line 1494 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 115 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_STRING, NULL, NULL); }
#line 1500 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 116 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_CHARACTER, NULL, NULL); }
#line 1506 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 117 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_AUTO, NULL, NULL); }
#line 1512 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 118 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_arr((yyvsp[-2].expr), (yyvsp[0].type)); }
#line 1518 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 122 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_INTEGER, NULL, NULL); }
#line 1524 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 123 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_BOOLEAN, NULL, NULL); }
#line 1530 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 124 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_STRING, NULL, NULL); }
#line 1536 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 125 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_CHARACTER, NULL, NULL); }
#line 1542 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 126 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_AUTO, NULL, NULL); }
#line 1548 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 127 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_arr((yyvsp[-2].expr), (yyvsp[0].type)); }
#line 1554 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 128 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_arr(NULL, (yyvsp[0].type)); }
#line 1560 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 131 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_func(TYPE_INTEGER, (yyvsp[0].param_list)); }
#line 1566 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 132 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_func(TYPE_BOOLEAN, (yyvsp[0].param_list)); }
#line 1572 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 133 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_func(TYPE_STRING, (yyvsp[0].param_list)); }
#line 1578 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 134 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_func(TYPE_CHARACTER, (yyvsp[0].param_list)); }
#line 1584 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 135 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_func(TYPE_VOID, (yyvsp[0].param_list)); }
#line 1590 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 136 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_FUNCTION, (yyvsp[-1].type), (yyvsp[0].param_list)); }
#line 1596 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 137 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create_func(TYPE_AUTO, (yyvsp[0].param_list)); }
#line 1602 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 140 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = (yyvsp[-1].param_list); }
#line 1608 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 141 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = NULL; }
#line 1614 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 144 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = param_list_create((yyvsp[-4].str), (yyvsp[-2].type), (yyvsp[0].param_list)); }
#line 1620 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 145 "parser.bison" /* yacc.c:1646  */
    { (yyval.param_list) = param_list_create((yyvsp[-2].str), (yyvsp[0].type), NULL); }
#line 1626 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 148 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_INTEGER, NULL, NULL); }
#line 1632 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 149 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_BOOLEAN, NULL, NULL); }
#line 1638 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 150 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_STRING, NULL, NULL); }
#line 1644 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 151 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_CHARACTER, NULL, NULL); }
#line 1650 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 152 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_AUTO, NULL, NULL); }
#line 1656 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 153 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_FUNCTION, NULL, NULL); }
#line 1662 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 155 "parser.bison" /* yacc.c:1646  */
    { (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[0].type), NULL); }
#line 1668 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 158 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1674 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 161 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1680 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 162 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1686 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 165 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1692 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 167 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, NULL, (yyvsp[-3].expr), NULL, (yyvsp[-2].stmt), (yyvsp[0].stmt), NULL); }
#line 1698 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 168 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_FOR, NULL, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, NULL); }
#line 1704 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 169 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1710 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 172 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, NULL, (yyvsp[-1].expr), NULL, (yyvsp[0].stmt), NULL, NULL); }
#line 1716 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 173 "parser.bison" /* yacc.c:1646  */
    {(yyval.stmt) = stmt_create(STMT_IF_ELSE, NULL, NULL, (yyvsp[-3].expr), NULL, (yyvsp[-2].stmt), (yyvsp[0].stmt), NULL); }
#line 1722 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 174 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_FOR, NULL, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt), NULL, NULL); }
#line 1728 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 177 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_RETURN, NULL, NULL, (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 1734 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 178 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_BLOCK, NULL, NULL, NULL, NULL, (yyvsp[-1].stmt), NULL, NULL); }
#line 1740 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 179 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create_print((yyvsp[-1].expr)); }
#line 1746 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 180 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_EXPR, NULL, NULL, (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 1752 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 181 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[0].decl), NULL, NULL, NULL, NULL, NULL, NULL); }
#line 1758 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 184 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1764 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 185 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = NULL; }
#line 1770 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 188 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = stmt_create_list((yyvsp[-1].stmt), (yyvsp[0].stmt)); }
#line 1776 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 189 "parser.bison" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1782 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 192 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1788 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 193 "parser.bison" /* yacc.c:1646  */
    {(yyval.expr) = NULL; }
#line 1794 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 196 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1800 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 197 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_tern((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1806 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 198 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1812 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 201 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_OR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1818 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 202 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1824 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 205 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1830 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 206 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1836 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 209 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_GT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1842 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 210 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_GE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1848 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 211 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_LT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1854 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 212 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_LE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1860 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 213 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1866 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 214 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1872 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 215 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1878 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 218 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1884 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 219 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1890 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 220 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1896 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 223 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1902 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 224 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1908 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 225 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_REM, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1914 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 226 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1920 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 229 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_EXP, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1926 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 230 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1932 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 233 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NEG, NULL, (yyvsp[0].expr)); }
#line 1938 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 234 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_NOT, NULL, (yyvsp[0].expr)); }
#line 1944 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 235 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1950 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 238 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_INC, (yyvsp[-1].expr), NULL); }
#line 1956 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 239 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create(EXPR_DEC, (yyvsp[-1].expr), NULL); }
#line 1962 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 240 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1968 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 243 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1974 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 244 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1980 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 245 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1986 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 246 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1992 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 249 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_arr_start((yyvsp[-1].str), (yyvsp[0].expr)); }
#line 1998 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 252 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_indeces((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2004 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 253 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_indeces((yyvsp[-1].expr), NULL); }
#line 2010 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 256 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_func((yyvsp[-3].str), (yyvsp[-1].expr)); }
#line 2016 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 259 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_args((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2022 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 260 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_args((yyvsp[0].expr), NULL); }
#line 2028 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 263 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2034 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 264 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = NULL; }
#line 2040 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 267 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2046 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 268 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = NULL; }
#line 2052 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 271 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_list((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2058 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 272 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_list((yyvsp[0].expr), NULL); }
#line 2064 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 275 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_integer_literal(atoi((yyvsp[0].str)) ); }
#line 2070 "parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 276 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_boolean_literal((yyvsp[0].str)); }
#line 2076 "parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 277 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_char_literal(parse_char((yyvsp[0].str)) ); }
#line 2082 "parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 278 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_string_literal(parse_string((yyvsp[0].str)) ); }
#line 2088 "parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 279 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_name((yyvsp[0].str)); }
#line 2094 "parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 280 "parser.bison" /* yacc.c:1646  */
    { (yyval.expr) = expr_create_arr_literal((yyvsp[-1].expr)); }
#line 2100 "parser.c" /* yacc.c:1646  */
    break;


#line 2104 "parser.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 283 "parser.bison" /* yacc.c:1906  */


int yyerror(char *str) {
    fprintf(stdout, "parse error: %s\n", str);
}
