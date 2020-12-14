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
#line 1 "lrparser.y" /* yacc.c:339  */


#include <stdio.h>
#include "ast.h"
extern char* yytext;
int yylex(void);
struct AST* root;
extern char value[50];

#line 76 "lrparser.tab.c" /* yacc.c:339  */

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
   by #include "lrparser.tab.h".  */
#ifndef YY_YY_LRPARSER_TAB_H_INCLUDED
# define YY_YY_LRPARSER_TAB_H_INCLUDED
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
    NUMBER = 258,
    ID = 259,
    STRING = 260,
    INT = 261,
    VOID = 262,
    STR = 263,
    ASSIGN = 264,
    CMP = 265,
    WHILE = 266,
    IF = 267,
    ELSE = 268,
    PRINT = 269,
    SCAN = 270,
    RETURN = 271,
    END = 272
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "lrparser.y" /* yacc.c:355  */

	int		num;//储存数字类
	char		str[50];//储存非数字类
	struct AST*	Ast;

#line 140 "lrparser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LRPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 157 "lrparser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   272

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    31,     2,     2,
      23,    24,    29,    27,    19,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    18,
       2,    20,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    25,     2,    26,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    21,     2,    22,     2,     2,     2,     2,
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
      15,    16,    17
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    25,    25,    26,    29,    30,    32,    34,    37,    38,
      40,    41,    42,    45,    46,    49,    50,    52,    55,    56,
      57,    58,    59,    61,    62,    64,    66,    67,    68,    70,
      71,    72,    73,    74,    75,    76,    77,    79,    80,    82,
      85,    88,    89,    91,    92,    94,    95,    97,    99,   100,
     102,   103,   105,   107,   109,   110,   111,   112,   114,   115,
     117,   118,   119,   121,   122,   123,   124,   125,   127,   128,
     129,   130,   131,   132,   134,   135,   137,   138
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "STRING", "INT", "VOID",
  "STR", "ASSIGN", "CMP", "WHILE", "IF", "ELSE", "PRINT", "SCAN", "RETURN",
  "END", "';'", "','", "'='", "'{'", "'}'", "'('", "')'", "'['", "']'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "$accept", "program",
  "external_declaration", "function_definition", "declaration",
  "init_declarator_list", "init_declarator", "intstr_list", "initializer",
  "declarator", "direct_declarator", "parameter_list", "parameter", "type",
  "statement", "compound_statement", "begin_scope", "end_scope",
  "statement_list", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "print_statement",
  "scan_statement", "expr", "assign_expr", "cmp_expr", "add_expr",
  "mul_expr", "primary_expr", "expr_list", "id_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    59,    44,
      61,   123,   125,    40,    41,    91,    93,    43,    45,    42,
      47,    37
};
# endif

#define YYPACT_NINF -61

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-61)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      70,   -61,   -61,   -61,    42,   -61,   -61,   -61,    -1,   -61,
     -61,   -13,     2,   -61,    20,     8,    56,   -61,    -1,   103,
     -61,   -61,    11,   141,   -61,   119,   -61,   115,   -61,    32,
     -61,    28,   -61,    61,    64,   121,   -61,   -61,    81,    58,
      99,    64,    86,    88,   109,   125,   112,   -61,   -61,   -61,
      -1,   -61,   -61,   -61,    11,   -61,   -61,   -61,   -61,   -61,
     -61,   107,   -61,    19,   -61,   132,   115,   115,    41,   115,
     133,   -61,   -61,   118,   118,   118,    32,    32,    32,   115,
      -9,   -61,   115,   115,   -61,   -61,   135,   -61,   137,   -61,
     127,   -61,   -61,   -61,    70,   -61,   -61,   -61,   -61,   -61,
      51,   134,   -61,    64,   121,   121,   -61,   -61,   -61,   136,
      99,   -61,   139,   140,   -61,   115,   -61,   154,   -61,   -61,
     -61,   146,   -61,   -61,    82,    82,   -61,   -61,   115,   -61,
     148,   -61,    82,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    26,    28,    27,     0,     2,     4,     5,     0,     1,
       3,    18,     0,     8,    10,    17,     0,     7,     0,     0,
      39,     6,     0,     0,    15,    71,    16,     0,    22,     0,
      72,     0,    53,    54,    58,    60,    63,     9,    10,    71,
       0,    11,     0,     0,     0,     0,     0,    43,    40,    36,
       0,    41,    29,    37,     0,    30,    31,    32,    33,    34,
      35,     0,    20,     0,    23,     0,     0,     0,     0,     0,
       0,    67,    21,     0,     0,     0,     0,     0,     0,     0,
       0,    13,     0,     0,    50,    74,     0,    76,     0,    48,
       0,    42,    38,    44,     0,    19,    25,    55,    56,    69,
       0,     0,    70,    59,    61,    62,    64,    65,    66,     0,
       0,    12,     0,     0,    51,     0,    52,     0,    49,    24,
      68,    73,    73,    14,     0,     0,    75,    77,     0,    47,
      45,    57,     0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   155,   -61,    47,   -61,   149,   -61,   -36,   160,
     -61,   -61,    75,     1,   -52,   156,   -61,   117,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -16,   -60,   -61,   -11,    59,
     -20,   104,   -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    49,    12,    13,    80,    30,    38,
      15,    63,    64,    50,    51,    52,    22,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    32,    33,    34,    35,
      36,    86,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,     8,    91,    11,    81,     8,    97,    98,    41,    71,
     110,    70,    16,   111,    24,    25,    26,     1,     2,     3,
      17,    18,    42,    43,    65,    44,    45,    46,    85,    47,
      90,    23,    20,    48,    27,    24,    39,    26,    94,    29,
      19,    20,     9,    95,    24,    25,    26,     7,     1,     2,
       3,     7,    85,   101,    72,    27,   106,   107,   108,    24,
      25,    26,   103,   109,    27,    99,   112,   113,   131,    29,
     115,    73,   129,   130,   123,   120,     1,     2,     3,    27,
     133,    68,    28,    79,    29,    24,    25,    26,     1,     2,
       3,    74,    75,    42,    43,    65,    44,    45,    46,   126,
      47,    19,    24,    20,    26,    27,    24,    39,    26,    82,
      29,    83,    24,    25,    26,    24,    25,    26,    24,    25,
      26,    24,    39,    26,    40,    93,    27,    84,    66,    87,
      89,    29,    27,   104,   105,    27,    96,    29,    27,    67,
      29,    27,    68,    29,    69,   118,    29,     1,     2,     3,
      76,    77,    78,   114,   115,   116,   117,   102,   127,    10,
     121,   132,   122,   124,   125,    62,   128,    37,    14,   119,
      21,    92,   100
};

static const yytype_uint8 yycheck[] =
{
      16,     0,    54,     4,    40,     4,    66,    67,    19,    29,
      19,    27,    25,    22,     3,     4,     5,     6,     7,     8,
      18,    19,    11,    12,    23,    14,    15,    16,    44,    18,
      46,    23,    21,    22,    23,     3,     4,     5,    19,    28,
      20,    21,     0,    24,     3,     4,     5,     0,     6,     7,
       8,     4,    68,    69,    26,    23,    76,    77,    78,     3,
       4,     5,    73,    79,    23,    24,    82,    83,   128,    28,
      19,    10,   124,   125,   110,    24,     6,     7,     8,    23,
     132,    23,    26,    25,    28,     3,     4,     5,     6,     7,
       8,    27,    28,    11,    12,    94,    14,    15,    16,   115,
      18,    20,     3,    21,     5,    23,     3,     4,     5,    23,
      28,    23,     3,     4,     5,     3,     4,     5,     3,     4,
       5,     3,     4,     5,    21,    18,    23,    18,     9,     4,
      18,    28,    23,    74,    75,    23,     4,    28,    23,    20,
      28,    23,    23,    28,    25,    18,    28,     6,     7,     8,
      29,    30,    31,    18,    19,    18,    19,    24,     4,     4,
      26,    13,    26,    24,    24,    24,    20,    18,     8,    94,
      14,    54,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,    33,    34,    35,    36,    45,     0,
      34,     4,    37,    38,    41,    42,    25,    18,    19,    20,
      21,    47,    48,    23,     3,     4,     5,    23,    26,    28,
      40,    57,    58,    59,    60,    61,    62,    38,    41,     4,
      21,    60,    11,    12,    14,    15,    16,    18,    22,    36,
      45,    46,    47,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    24,    43,    44,    45,     9,    20,    23,    25,
      57,    62,    26,    10,    27,    28,    29,    30,    31,    25,
      39,    40,    23,    23,    18,    57,    63,     4,    64,    18,
      57,    46,    49,    18,    19,    24,     4,    58,    58,    24,
      63,    57,    24,    60,    61,    61,    62,    62,    62,    57,
      19,    22,    57,    57,    18,    19,    18,    19,    18,    44,
      24,    26,    26,    40,    24,    24,    57,     4,    20,    46,
      46,    58,    13,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    35,    36,    37,    37,
      38,    38,    38,    39,    39,    40,    40,    41,    42,    42,
      42,    42,    42,    43,    43,    44,    45,    45,    45,    46,
      46,    46,    46,    46,    46,    46,    46,    47,    47,    48,
      49,    50,    50,    51,    51,    52,    52,    53,    54,    54,
      55,    55,    56,    57,    58,    58,    58,    58,    59,    59,
      60,    60,    60,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    63,    63,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     3,     1,     3,
       1,     3,     5,     1,     3,     1,     1,     1,     1,     4,
       3,     4,     3,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       1,     1,     2,     1,     2,     5,     7,     5,     2,     3,
       2,     3,     3,     1,     1,     3,     3,     6,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     2,     4,     3,
       3,     1,     1,     4,     1,     3,     1,     3
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
#line 25 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("program",NULL,1,(yyvsp[0].Ast));}
#line 1337 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 26 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("program",NULL,2,(yyvsp[-1].Ast),(yyvsp[0].Ast));root = (yyval.Ast);}
#line 1343 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 29 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("external_declaration",NULL,1,(yyvsp[0].Ast));}
#line 1349 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 30 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("external_declaration",NULL,1,(yyvsp[0].Ast));}
#line 1355 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 32 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("function_definition",NULL,3,(yyvsp[-2].Ast),(yyvsp[-1].Ast),(yyvsp[0].Ast));}
#line 1361 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 34 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("declaration",NULL,2,(yyvsp[-2].Ast),(yyvsp[-1].Ast));}
#line 1367 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 37 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("init_declarator_list",NULL,1,(yyvsp[0].Ast));}
#line 1373 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 38 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("init_declarator_list",NULL,2,(yyvsp[-2].Ast),(yyvsp[0].Ast));}
#line 1379 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 41 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("init_declarator",NULL,2,(yyvsp[-2].Ast),(yyvsp[0].Ast));}
#line 1385 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 42 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("init_declarator",NULL,2,(yyvsp[-4].Ast),(yyvsp[-1].Ast));}
#line 1391 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 45 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("intstr_list",NULL,1,(yyvsp[0].Ast));}
#line 1397 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 46 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("intstr_list",NULL,2,(yyvsp[-2].Ast),(yyvsp[0].Ast));}
#line 1403 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 49 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("initializer",NULL,1,newnode("NUMBER",value,1,NULL));}
#line 1409 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 50 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("initializer",NULL,1,newnode("STRING",value,1,NULL));}
#line 1415 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 52 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("declarator",NULL,1,(yyvsp[0].Ast));}
#line 1421 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 55 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("direct_declarator",NULL,1,newnode("ID",value,1,NULL));}
#line 1427 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 56 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("direct_declarator",NULL,2,(yyvsp[-3].Ast),(yyvsp[-1].Ast));}
#line 1433 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 57 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("direct_declarator",NULL,1,(yyvsp[-2].Ast));}
#line 1439 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 58 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("direct_declarator",NULL,2,newnode("ID",value,1,NULL),(yyvsp[-1].Ast));}
#line 1445 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 59 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("direct_declarator",NULL,1,newnode("ID",value,1,NULL));}
#line 1451 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 61 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("parameter_list",NULL,1,(yyvsp[0].Ast));}
#line 1457 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 62 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("parameter_list",NULL,2,(yyvsp[-2].Ast),(yyvsp[0].Ast));}
#line 1463 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 64 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("parameter",NULL,2,(yyvsp[-1].Ast),newnode("ID",value,1,NULL));}
#line 1469 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 66 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("type",NULL,1,newnode("INT",NULL,1,NULL));}
#line 1475 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 67 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("type",NULL,1,newnode("STR",NULL,1,NULL));}
#line 1481 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 68 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("type",NULL,1,newnode("VOID",NULL,1,NULL));}
#line 1487 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 70 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("statement",NULL,1,(yyvsp[0].Ast));}
#line 1493 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 71 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("statement",NULL,1,(yyvsp[0].Ast));}
#line 1499 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 72 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("statement",NULL,1,(yyvsp[0].Ast));}
#line 1505 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 73 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("statement",NULL,1,(yyvsp[0].Ast));}
#line 1511 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 74 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("statement",NULL,1,(yyvsp[0].Ast));}
#line 1517 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 75 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("statement",NULL,1,(yyvsp[0].Ast));}
#line 1523 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 76 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("statement",NULL,1,(yyvsp[0].Ast));}
#line 1529 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 77 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("statement",NULL,1,(yyvsp[0].Ast));}
#line 1535 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 79 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("compound_statement",NULL,2,(yyvsp[-1].Ast),(yyvsp[0].Ast));}
#line 1541 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 80 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("compound_statement",NULL,2,(yyvsp[-2].Ast),(yyvsp[-1].Ast));}
#line 1547 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 82 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("begin_scope",NULL,1,NULL);}
#line 1553 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 85 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("end_scope",NULL,1,NULL);}
#line 1559 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 88 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("statement_list",NULL,1,(yyvsp[0].Ast));}
#line 1565 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 89 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("statement_list",NULL,2,(yyvsp[-1].Ast),(yyvsp[0].Ast));}
#line 1571 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 91 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("expression_statement",NULL,1,NULL);}
#line 1577 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 92 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("expression_statement",NULL,1,(yyvsp[-1].Ast));}
#line 1583 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 94 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("selection_statement",NULL,3,newnode("IF",NULL,1,NULL),(yyvsp[-2].Ast),(yyvsp[0].Ast));}
#line 1589 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 95 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("selection_statement",NULL,5,newnode("IF",NULL,1,NULL),(yyvsp[-4].Ast),(yyvsp[-2].Ast),newnode("ELSE",NULL,1,NULL),(yyvsp[0].Ast));}
#line 1595 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 97 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("iteration_statement",NULL,3,newnode("WHILE",NULL,1,NULL),(yyvsp[-2].Ast),(yyvsp[0].Ast));}
#line 1601 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 99 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("jump_statement",NULL,1,newnode("RETURN",NULL,1,NULL));}
#line 1607 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 100 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("jump_statement",NULL,2,newnode("RETURN",NULL,1,NULL),(yyvsp[-1].Ast));}
#line 1613 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 102 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("print_statement",NULL,1,newnode("PRINT",NULL,1,NULL));}
#line 1619 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 103 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("print_statement",NULL,2,newnode("PRINT",NULL,1,NULL),(yyvsp[-1].Ast));}
#line 1625 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 105 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("scan_statement",NULL,2,newnode("SCAN",NULL,1,NULL),(yyvsp[-1].Ast));}
#line 1631 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 107 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("expr",NULL,1,(yyvsp[0].Ast));}
#line 1637 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 109 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("assign_expr",NULL,1,(yyvsp[0].Ast));}
#line 1643 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 110 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("assign_expr",NULL,3,newnode("ID",value,1,NULL),newnode("ASSING",NULL,1,NULL),(yyvsp[0].Ast));}
#line 1649 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 111 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("assign_expr",NULL,2,newnode("ID",value,1,NULL),(yyvsp[0].Ast));}
#line 1655 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 112 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("assign_expr",NULL,3,newnode("ID",value,1,NULL),(yyvsp[-3].Ast),(yyvsp[0].Ast));}
#line 1661 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 114 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("cmp_expr",NULL,1,(yyvsp[0].Ast));}
#line 1667 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 115 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("cmp_expr",NULL,3,(yyvsp[-2].Ast),newnode("CMP",NULL,1,NULL),(yyvsp[0].Ast));}
#line 1673 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 117 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("add_expr",NULL,1,(yyvsp[0].Ast));}
#line 1679 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 118 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("add_expr",NULL,2,(yyvsp[-2].Ast),(yyvsp[0].Ast));}
#line 1685 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 119 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("add_expr",NULL,2,(yyvsp[-2].Ast),(yyvsp[0].Ast));}
#line 1691 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 121 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("mul_expr",NULL,1,(yyvsp[0].Ast));}
#line 1697 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 122 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("mul_expr",NULL,2,(yyvsp[-2].Ast),(yyvsp[0].Ast));}
#line 1703 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 123 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("mul_expr",NULL,2,(yyvsp[-2].Ast),(yyvsp[0].Ast));}
#line 1709 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 124 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("mul_expr",NULL,2,(yyvsp[-2].Ast),(yyvsp[0].Ast));}
#line 1715 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 125 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("mul_expr",NULL,1,(yyvsp[0].Ast));}
#line 1721 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 127 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("primary_expr",NULL,2,newnode("ID",value,1,NULL),(yyvsp[-1].Ast));}
#line 1727 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 128 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("primary_expr",NULL,1,newnode("ID",value,1,NULL));}
#line 1733 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 129 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("primary_expr",NULL,1,(yyvsp[-1].Ast));}
#line 1739 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 130 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("primary_expr",NULL,1,newnode("ID",value,1,NULL));}
#line 1745 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 131 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("primary_expr",NULL,1,(yyvsp[0].Ast));}
#line 1751 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 132 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("primary_expr",NULL,2,newnode("ID",value,1,NULL),(yyvsp[-1].Ast));}
#line 1757 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 134 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("expr_list",NULL,1,(yyvsp[0].Ast));}
#line 1763 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 135 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("expr_list",NULL,2,(yyvsp[-2].Ast),(yyvsp[0].Ast));}
#line 1769 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 137 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("id_list",NULL,1,newnode("ID",value,1,NULL));}
#line 1775 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 138 "lrparser.y" /* yacc.c:1646  */
    {(yyval.Ast) = newnode("id_list",NULL,2,(yyvsp[-2].Ast),newnode("ID",value,1,NULL));}
#line 1781 "lrparser.tab.c" /* yacc.c:1646  */
    break;


#line 1785 "lrparser.tab.c" /* yacc.c:1646  */
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
#line 142 "lrparser.y" /* yacc.c:1906  */

