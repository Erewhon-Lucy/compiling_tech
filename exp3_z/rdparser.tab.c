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
#line 1 "rdparser.y" /* yacc.c:339  */

#include <stdio.h>
#include "ast.h"
int yylex(void);
void yyerror(char *c);


#line 74 "rdparser.tab.c" /* yacc.c:339  */

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
   by #include "rdparser.tab.h".  */
#ifndef YY_YY_RDPARSER_TAB_H_INCLUDED
# define YY_YY_RDPARSER_TAB_H_INCLUDED
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
    VOID = 264,
    STR = 263,
    STRING = 260,
    INT = 273,
    ID = 274,
    ASSIGN = 275,
    NUMBER = 276,
    CMP = 277,
    IF = 266,
    WHILE = 267,
    ELSE = 268,
    PRINT = 270,
    SCAN = 271,
    RETURN = 278,
    F = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 9 "rdparser.y" /* yacc.c:355  */

    int iValue;
    past pAst;
    char *String;
    char * id;
 //   char bracket;
    char c;

#line 141 "rdparser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_RDPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 158 "rdparser.tab.c" /* yacc.c:358  */

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
#define YYLAST   203

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      26,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    21,     2,     2,
      22,    23,    19,    17,    30,    18,     2,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    31,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    33,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       5,     2,     2,     4,     3,     2,    11,    12,    13,     2,
      14,    15,     2,     6,     7,     8,     9,    10,    16,    24,
      25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    56,    59,    60,    62,    65,    66,    68,
      69,    70,    71,    72,    73,    74,    75,    77,    78,    80,
      81,    82,    83,    85,    87,    89,    91,    92,    94,    95,
      97,    99,   100,   102,   103,   104,   106,   107,   109,   111,
     113,   114,   115,   116,   117,   119,   120,   121,   123,   125,
     126,   127,   129,   130,   133,   134,   135,   137,   138,   139,
     140,   141,   143,   144,   145,   146,   147,   150,   151,   153,
     154,   157,   158,   161,   163,   165
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "STR", "STRING", "INT", "ID",
  "ASSIGN", "NUMBER", "CMP", "IF", "WHILE", "ELSE", "PRINT", "SCAN",
  "RETURN", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'", "\"ELSE\"",
  "F", "'\\n'", "'{'", "'}'", "';'", "','", "'='", "'['", "']'", "$accept",
  "program", "extr_decl", "function_definition", "statement_list",
  "statement", "compound_statement", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "print_statement", "scan_statement", "declaration",
  "init_declarator_list", "init_declarator", "parameter_list", "parameter",
  "declarator", "direct_declarator", "type", "expr", "assign_expr",
  "cmp_expr", "add_expr", "mul_expr", "primary_expr", "expr_list",
  "initializer", "intstr_list", "id", "cmp", "assign", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   272,   264,   263,   260,   273,   274,   275,   276,
     277,   266,   267,   268,   270,   271,   278,    43,    45,    42,
      47,    37,    40,    41,   279,   280,    10,   123,   125,    59,
      44,    61,    91,    93
};
# endif

#define YYPACT_NINF -85

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-85)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     131,   -85,   -85,   -85,    69,    -7,   -85,   -85,    21,   -85,
      17,   -85,   -85,    31,   -85,    43,    16,    23,   -85,   -85,
      21,    87,   167,   -85,   104,     8,   -85,    40,   -85,   -85,
      75,   100,    11,    30,   153,    44,   181,   -85,   -85,   114,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,    21,
      71,   -85,   116,    59,    92,   -85,   -85,    12,    22,    59,
     111,   -85,     2,   -85,    21,   -85,    98,   181,   181,   -85,
     -85,   109,   -85,   135,   -85,   120,   -85,   117,   -85,   -85,
     -85,   -85,   181,   181,   181,    44,    44,    44,   -85,   174,
     181,   181,   -85,    76,   -85,   131,   -85,   -85,   128,   138,
     -85,   181,   -85,   -85,   -85,    59,    92,    92,   -85,   -85,
     -85,   -85,    24,   121,   -85,   -85,    22,   -85,   141,   141,
     -85,   -85,   142,   -85,   156,   -85,   181,   141,   -85,   -85
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    47,    46,    45,     0,     0,     5,     4,     0,     1,
       0,     2,    73,     0,    31,    33,    39,    40,     3,    30,
       0,     0,     0,     6,     0,     0,    32,    33,    70,    69,
       0,     0,     0,     0,     0,     0,     0,    17,    19,     0,
       7,     9,    10,    12,    11,    15,    13,    14,    16,     0,
       0,    48,    49,    52,    54,    57,    66,    65,     0,    34,
      65,    42,     0,    36,     0,    44,     0,     0,     0,    26,
      67,     0,    28,     0,    24,     0,    61,     0,    18,     8,
      20,    75,     0,     0,     0,     0,     0,     0,    74,     0,
       0,     0,    71,     0,    41,     0,    38,    43,     0,     0,
      27,     0,    29,    25,    64,    53,    55,    56,    58,    59,
      60,    63,     0,     0,    50,    35,     0,    37,     0,     0,
      68,    62,     0,    72,    21,    23,     0,     0,    51,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,   173,   -85,   -85,   -38,   163,   -85,   -85,   -85,
     -85,   -85,   -85,    78,   -85,   160,   -85,    89,   179,   -85,
       0,   -22,   -84,   -85,   -20,    83,   -29,   -25,   -53,   -85,
       1,   -85,   -85
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    13,    14,    62,    63,    27,    16,
      49,    50,    51,    52,    53,    54,    55,    71,    56,    93,
      57,    91,    82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       8,    79,    59,    66,     8,    92,    76,   114,    73,    17,
      70,    70,    75,    28,    77,    12,    28,    29,    12,    11,
      29,    17,    88,    60,    64,    94,    35,    28,    12,    35,
      36,    29,    95,    36,    89,    28,    60,    12,    24,    29,
      69,    65,   128,    18,    90,    98,    99,   121,    35,    28,
      17,    12,    36,    29,   101,    25,   108,   109,   110,    72,
      19,    20,   105,   123,   112,    96,    36,    70,   113,     9,
      21,    22,     1,     2,    22,     3,    83,    84,     7,   120,
     124,   125,     7,    60,    60,    60,    60,    60,    60,   129,
       1,     2,    28,     3,    12,    64,    29,    67,    30,    31,
      80,    32,    33,    34,   115,    35,   116,     1,     2,    36,
       3,    85,    86,    87,    21,    37,    38,     1,     2,    28,
       3,    12,    68,    29,    81,    30,    31,    61,    32,    33,
      34,    97,    35,    89,     1,     2,    36,     3,   100,   101,
     104,    21,    78,    38,     1,     2,    28,     3,    12,   103,
      29,   118,    30,    31,   122,    32,    33,    34,    28,    35,
      12,   119,    29,    36,   102,   101,   106,   107,    21,   127,
      38,    35,    28,   126,    12,    36,    29,    10,    23,    28,
      26,    12,    74,    29,   117,    35,    28,    15,    12,    36,
      29,     0,    35,     0,    58,     0,    36,   111,     0,    35,
       0,     0,     0,    36
};

static const yytype_int8 yycheck[] =
{
       0,    39,    22,    25,     4,    58,    35,    91,    33,     8,
      32,    33,    34,     5,    36,     7,     5,     9,     7,    26,
       9,    20,    10,    22,    24,    23,    18,     5,     7,    18,
      22,     9,    30,    22,    22,     5,    35,     7,    22,     9,
      29,    33,   126,    26,    32,    67,    68,    23,    18,     5,
      49,     7,    22,     9,    30,    32,    85,    86,    87,    29,
      29,    30,    82,   116,    89,    64,    22,    89,    90,     0,
      27,    31,     3,     4,    31,     6,    17,    18,     0,   101,
     118,   119,     4,    82,    83,    84,    85,    86,    87,   127,
       3,     4,     5,     6,     7,    95,     9,    22,    11,    12,
      29,    14,    15,    16,    28,    18,    30,     3,     4,    22,
       6,    19,    20,    21,    27,    28,    29,     3,     4,     5,
       6,     7,    22,     9,     8,    11,    12,    23,    14,    15,
      16,    33,    18,    22,     3,     4,    22,     6,    29,    30,
      23,    27,    28,    29,     3,     4,     5,     6,     7,    29,
       9,    23,    11,    12,    33,    14,    15,    16,     5,    18,
       7,    23,     9,    22,    29,    30,    83,    84,    27,    13,
      29,    18,     5,    31,     7,    22,     9,     4,    15,     5,
      20,     7,    29,     9,    95,    18,     5,     8,     7,    22,
       9,    -1,    18,    -1,    27,    -1,    22,    23,    -1,    18,
      -1,    -1,    -1,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,    35,    36,    37,    47,    54,     0,
      36,    26,     7,    48,    49,    52,    53,    64,    26,    29,
      30,    27,    31,    40,    22,    32,    49,    52,     5,     9,
      11,    12,    14,    15,    16,    18,    22,    28,    29,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    54,
      55,    56,    57,    58,    59,    60,    62,    64,    27,    58,
      64,    23,    50,    51,    54,    33,    55,    22,    22,    29,
      55,    61,    29,    61,    29,    55,    60,    55,    28,    39,
      29,     8,    66,    17,    18,    19,    20,    21,    10,    22,
      32,    65,    62,    63,    23,    30,    64,    33,    55,    55,
      29,    30,    29,    29,    23,    58,    59,    59,    60,    60,
      60,    23,    61,    55,    56,    28,    30,    51,    23,    23,
      55,    23,    33,    62,    39,    39,    31,    13,    56,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    35,    36,    36,    37,    38,    38,    39,
      39,    39,    39,    39,    39,    39,    39,    40,    40,    41,
      41,    42,    42,    43,    44,    44,    45,    45,    46,    46,
      47,    48,    48,    49,    49,    49,    50,    50,    51,    52,
      53,    53,    53,    53,    53,    54,    54,    54,    55,    56,
      56,    56,    57,    57,    58,    58,    58,    59,    59,    59,
      59,    59,    60,    60,    60,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    65,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       2,     5,     7,     5,     2,     3,     2,     3,     2,     3,
       3,     1,     3,     1,     3,     5,     1,     3,     2,     1,
       1,     4,     3,     4,     3,     1,     1,     1,     1,     1,
       3,     6,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     2,     4,     3,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1
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
#line 55 "rdparser.y" /* yacc.c:1646  */
    {showAst((yyvsp[-1].pAst), 0);}
#line 1342 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 56 "rdparser.y" /* yacc.c:1646  */
    { showAst((yyvsp[-1].pAst), 0); }
#line 1348 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 60 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1354 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 62 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newFunc((yyvsp[-2].pAst), (yyvsp[-1].pAst), (yyvsp[0].pAst));}
#line 1360 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 66 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newStat_list((yyvsp[-1].pAst), (yyvsp[0].pAst));}
#line 1366 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 77 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newEmptyComp("{", "}");}
#line 1372 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 78 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newComp("{", (yyvsp[-1].pAst), "}");}
#line 1378 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 80 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = 0;}
#line 1384 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 82 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newIf_stmt((yyvsp[-4].String), (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1390 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 83 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newIf_Else((yyvsp[-6].String), (yyvsp[-4].pAst), (yyvsp[-2].pAst), (yyvsp[-1].String), (yyvsp[0].pAst));}
#line 1396 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 85 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newWhile((yyvsp[-4].String), (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1402 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 87 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newRET((yyvsp[-1].String), 0);}
#line 1408 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 89 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newRET((yyvsp[-2].String), (yyvsp[-1].pAst));}
#line 1414 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 91 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newPrint((yyvsp[-1].String), 0);}
#line 1420 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 92 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newPrint((yyvsp[-2].String), (yyvsp[-1].pAst));}
#line 1426 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 94 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newScan((yyvsp[-1].String), 0);}
#line 1432 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 95 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newScan((yyvsp[-2].String), (yyvsp[-1].pAst));}
#line 1438 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 97 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newDecl((yyvsp[-2].pAst), (yyvsp[-1].pAst));}
#line 1444 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 100 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newDecl_list((yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1450 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 103 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newDeclarator('=', (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1456 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 104 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newDeclarator('=', (yyvsp[-4].pAst), (yyvsp[-1].pAst));}
#line 1462 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 107 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newPara_list((yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1468 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 109 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newPara((yyvsp[-1].pAst), (yyvsp[0].pAst));}
#line 1474 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 114 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newDir_dec((yyvsp[-3].pAst), (yyvsp[-1].pAst));}
#line 1480 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 116 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newDir_dec((yyvsp[-3].pAst), (yyvsp[-1].pAst));}
#line 1486 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 119 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newInt((yyvsp[0].String));}
#line 1492 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 120 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newSTR((yyvsp[0].String));}
#line 1498 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 121 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newVOID((yyvsp[0].String));}
#line 1504 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 126 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=new_Expr((yyvsp[-1].pAst), (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1510 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 127 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newAss_expr_1('=', (yyvsp[-5].pAst),(yyvsp[-3].pAst),(yyvsp[0].pAst));}
#line 1516 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 130 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newCmp((yyvsp[-2].pAst),(yyvsp[-1].pAst),(yyvsp[0].pAst));}
#line 1522 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 134 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newExpr('+', (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1528 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 135 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newExpr('-', (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1534 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 138 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newExpr('*', (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1540 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 139 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newExpr('/', (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1546 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 140 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newExpr('%', (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1552 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 141 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newMul('-',(yyvsp[0].pAst));}
#line 1558 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 143 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newPrim((yyvsp[-3].pAst), (yyvsp[-1].pAst));}
#line 1564 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 144 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newPrim((yyvsp[-2].pAst), 0);}
#line 1570 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 145 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newPrim(0, (yyvsp[-1].pAst));}
#line 1576 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 151 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=newExpr_list((yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1582 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 153 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newNum((yyvsp[0].iValue));}
#line 1588 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 154 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newSTRING((yyvsp[0].String));}
#line 1594 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 158 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newIntstr((yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1600 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 161 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newID((yyvsp[0].id));}
#line 1606 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 163 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newCMP((yyvsp[0].String));}
#line 1612 "rdparser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 165 "rdparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = newASSIGN((yyvsp[0].String));}
#line 1618 "rdparser.tab.c" /* yacc.c:1646  */
    break;


#line 1622 "rdparser.tab.c" /* yacc.c:1646  */
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
#line 167 "rdparser.y" /* yacc.c:1906  */
