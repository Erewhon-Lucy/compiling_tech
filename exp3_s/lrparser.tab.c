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
#include <stdlib.h>
#include "ast.h"

int yylex(void);
void yyerror(char *);
struct _ast* root;


#line 77 "lrparser.tab.c" /* yacc.c:339  */

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
    RETURN = 278
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "lrparser.y" /* yacc.c:355  */

    int	iValue;
	struct _ast*	pAst;
    char *String;
    char * id;

#line 141 "lrparser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LRPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 158 "lrparser.tab.c" /* yacc.c:358  */

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
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    30,     2,     2,
      22,    23,    28,    26,    18,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    17,
       2,    19,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,    25,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    20,     2,    21,     2,     2,     2,     2,
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
      14,    15,     2,     6,     7,     8,     9,    10,    16
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    43,    43,    44,    46,    47,    49,    51,    53,    54,
      56,    57,    58,    60,    61,    63,    64,    66,    68,    69,
      70,    71,    72,    75,    76,    78,    80,    81,    82,    84,
      85,    86,    87,    88,    89,    90,    91,    93,    94,    96,
      98,   100,   101,   103,   104,   106,   107,   109,   111,   112,
     114,   115,   117,   119,   121,   122,   123,   124,   126,   127,
     129,   130,   131,   133,   134,   135,   136,   137,   139,   140,
     141,   142,   143,   144,   146,   147,   149,   150
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "STR", "STRING", "INT", "ID",
  "ASSIGN", "NUMBER", "CMP", "IF", "WHILE", "ELSE", "PRINT", "SCAN",
  "RETURN", "';'", "','", "'='", "'{'", "'}'", "'('", "')'", "'['", "']'",
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
       0,   256,   272,   264,   263,   260,   273,   274,   275,   276,
     277,   266,   267,   268,   270,   271,   278,    59,    44,    61,
     123,   125,    40,    41,    91,    93,    43,    45,    42,    47,
      37
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
      83,   -61,   -61,   -61,    10,   -61,   -61,   -61,    -4,   -61,
     -61,    30,    42,   -61,    74,     3,   111,   -61,    -4,    70,
     -61,   -61,    28,    23,   -61,   107,   -61,    14,   -61,    76,
     -61,    40,   -61,    72,    95,    41,   -61,   -61,    19,    54,
      13,    95,    62,    66,   118,    84,   125,   -61,   -61,   -61,
      -4,   -61,   -61,   -61,    28,   -61,   -61,   -61,   -61,   -61,
     -61,    79,   -61,    -6,   -61,    98,    14,    14,   132,    14,
      87,   -61,   -61,   139,   139,   139,    76,    76,    76,    14,
      43,   -61,    14,    14,   -61,   -61,   133,   -61,   140,   -61,
      90,   -61,   -61,   -61,    83,   -61,   -61,   -61,   -61,   -61,
      -3,   103,   -61,    95,    41,    41,   -61,   -61,   -61,   124,
      13,   -61,   120,   130,   -61,    14,   -61,   149,   -61,   -61,
     -61,   141,   -61,   -61,    97,    97,   -61,   -61,    14,   151,
     -61,   -61,    97,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    28,    27,    26,     0,     2,     4,     5,     0,     1,
       3,    18,     0,     8,    10,    17,     0,     7,     0,     0,
      39,     6,     0,     0,    16,    71,    15,     0,    22,     0,
      72,     0,    53,    54,    58,    60,    63,     9,    10,    71,
       0,    11,     0,     0,     0,     0,     0,    43,    40,    36,
       0,    41,    29,    37,     0,    30,    31,    32,    33,    34,
      35,     0,    20,     0,    23,     0,     0,     0,     0,     0,
       0,    67,    21,     0,     0,     0,     0,     0,     0,     0,
       0,    13,     0,     0,    50,    74,     0,    76,     0,    48,
       0,    42,    38,    44,     0,    19,    25,    55,    56,    69,
       0,     0,    70,    59,    61,    62,    64,    65,    66,     0,
       0,    12,     0,     0,    51,     0,    52,     0,    49,    24,
      68,    73,    73,    14,     0,     0,    75,    77,     0,    45,
      47,    57,     0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   161,   -61,    47,   -61,   150,   -61,   -36,   159,
     -61,   -61,    75,     1,   -52,   156,   -61,   117,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -16,   -60,   -61,   -11,    88,
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
       9,    70,    94,     1,     2,   115,     3,    95,    24,    24,
     120,    25,    26,    26,    65,    23,     1,     2,    85,     3,
      90,     1,     2,    24,     3,    25,    27,    26,    19,    42,
      43,    29,    44,    45,    46,    47,    62,     7,    20,    48,
      27,     7,    85,   101,    16,    29,   106,   107,   108,    17,
      18,   110,   103,   109,   111,    72,   112,   113,   131,    76,
      77,    78,   129,   130,   123,    24,    68,    39,    79,    26,
     133,    24,    73,    39,    82,    26,     1,     2,    83,     3,
      40,    87,    27,    19,    20,    65,    93,    29,    27,   126,
       1,     2,    24,     3,    25,    96,    26,   118,    42,    43,
     102,    44,    45,    46,    47,    66,    24,    20,    25,    27,
      26,    74,    75,    24,    29,    25,    67,    26,   121,    68,
      24,    69,    25,    27,    26,    84,    28,    24,    29,    25,
      27,    26,    89,   124,    24,    29,    39,    27,    26,   122,
     114,   115,    29,   125,    27,    99,   127,   116,   117,    29,
     128,    27,   104,   105,   132,    10,    29,    14,    37,   119,
      21,    92,   100
};

static const yytype_uint8 yycheck[] =
{
      16,     0,    54,     7,    40,     4,    66,    67,    19,    29,
       0,    27,    18,     3,     4,    18,     6,    23,     5,     5,
      23,     7,     9,     9,    23,    22,     3,     4,    44,     6,
      46,     3,     4,     5,     6,     7,    22,     9,    19,    11,
      12,    27,    14,    15,    16,    17,    23,     0,    20,    21,
      22,     4,    68,    69,    24,    27,    76,    77,    78,    17,
      18,    18,    73,    79,    21,    25,    82,    83,   128,    28,
      29,    30,   124,   125,   110,     5,    22,     7,    24,     9,
     132,     5,    10,     7,    22,     9,     3,     4,    22,     6,
      20,     7,    22,    19,    20,    94,    17,    27,    22,   115,
       3,     4,     5,     6,     7,     7,     9,    17,    11,    12,
      23,    14,    15,    16,    17,     8,     5,    20,     7,    22,
       9,    26,    27,     5,    27,     7,    19,     9,    25,    22,
       5,    24,     7,    22,     9,    17,    25,     5,    27,     7,
      22,     9,    17,    23,     5,    27,     7,    22,     9,    25,
      17,    18,    27,    23,    22,    23,     7,    17,    18,    27,
      19,    22,    74,    75,    13,     4,    27,     8,    18,    94,
      14,    54,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,    32,    33,    34,    35,    44,     0,
      33,     7,    36,    37,    40,    41,    24,    17,    18,    19,
      20,    46,    47,    22,     5,     7,     9,    22,    25,    27,
      39,    56,    57,    58,    59,    60,    61,    37,    40,     7,
      20,    59,    11,    12,    14,    15,    16,    17,    21,    35,
      44,    45,    46,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    23,    42,    43,    44,     8,    19,    22,    24,
      56,    61,    25,    10,    26,    27,    28,    29,    30,    24,
      38,    39,    22,    22,    17,    56,    62,     7,    63,    17,
      56,    45,    48,    17,    18,    23,     7,    57,    57,    23,
      62,    56,    23,    59,    60,    60,    61,    61,    61,    56,
      18,    21,    56,    56,    17,    18,    17,    18,    17,    43,
      23,    25,    25,    39,    23,    23,    56,     7,    19,    45,
      45,    57,    13,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    32,    33,    33,    34,    35,    36,    36,
      37,    37,    37,    38,    38,    39,    39,    40,    41,    41,
      41,    41,    41,    42,    42,    43,    44,    44,    44,    45,
      45,    45,    45,    45,    45,    45,    45,    46,    46,    47,
      48,    49,    49,    50,    50,    51,    51,    52,    53,    53,
      54,    54,    55,    56,    57,    57,    57,    57,    58,    58,
      59,    59,    59,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    62,    62,    63,    63
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
#line 43 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=connect("program",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);showAst((yyvsp[0].pAst),0);}
#line 1338 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 44 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=connect("program",(yyvsp[-1].pAst),(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL);showAst((yyvsp[0].pAst),0);}
#line 1344 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 46 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("external_declaration",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1350 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 47 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("external_declaration",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1356 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 49 "lrparser.y" /* yacc.c:1646  */
    {printf("***()");(yyval.pAst) = connect("function_definition",(yyvsp[-2].pAst),(yyvsp[-1].pAst),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1362 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 51 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("declaration",(yyvsp[-2].pAst),(yyvsp[-1].pAst),newTerminal(";"),NULL,NULL,NULL,NULL);}
#line 1368 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 53 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("init_declarator",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1374 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 54 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("init_declarator_list",(yyvsp[-2].pAst),newTerminal(","),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1380 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 56 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("init_declarator",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1386 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 57 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("init_declarator",(yyvsp[-2].pAst),newTerminal("="),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1392 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 58 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("init_declarator",(yyvsp[-4].pAst),newTerminal("="),newTerminal("{"),(yyvsp[-1].pAst),newTerminal("}"),NULL,NULL);}
#line 1398 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 60 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("intstr_list",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1404 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 61 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("intstr_list",(yyvsp[-2].pAst),newTerminal(","),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1410 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 63 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect(newTerminal("NUMBER"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1416 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 64 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect(newTerminal("STRING"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1422 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 66 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("declarator",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1428 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 68 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect(newTerminal("ID"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1434 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 69 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("direct_declarator",(yyvsp[-3].pAst),newTerminal("("),(yyvsp[-1].pAst),newTerminal(")"),NULL,NULL,NULL);}
#line 1440 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 70 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("direct_declarator",(yyvsp[-2].pAst),newTerminal("("),newTerminal(")"),NULL,NULL,NULL,NULL);}
#line 1446 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 71 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("direct_declaration",newTerminal("ID"),newTerminal("["),(yyvsp[-1].pAst),newTerminal("]"),NULL,NULL,NULL);}
#line 1452 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 72 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("direct_declaration",newTerminal("ID"),newTerminal("["),newTerminal("]"),NULL,NULL,NULL,NULL);}
#line 1458 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 75 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("parameter_list",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1464 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 76 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("parameter_list",(yyvsp[-2].pAst),newTerminal(","),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1470 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 78 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("parameter",(yyvsp[-1].pAst),newTerminal("ID"),NULL,NULL,NULL,NULL,NULL);}
#line 1476 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 80 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("type",newTerminal("INT"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1482 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 81 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("type",newTerminal("STR"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1488 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 82 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("type",newTerminal("VOID"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1494 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 84 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1500 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 85 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1506 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 86 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1512 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 87 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1518 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 88 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1524 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 89 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1530 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 90 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1536 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 91 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1542 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 93 "lrparser.y" /* yacc.c:1646  */
    {printf("***begin_scope end_scope");(yyval.pAst) = connect("compound_statement",(yyvsp[-1].pAst),(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL);}
#line 1548 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 94 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("compound_statement",(yyvsp[-2].pAst),(yyvsp[-1].pAst),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1554 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 96 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("begin_scope",newTerminal("{"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1560 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 98 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("end_scope",newTerminal("}"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1566 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 100 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("statement_list",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1572 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 101 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("statement_list",(yyvsp[-1].pAst),(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL);}
#line 1578 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 103 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("expression_statement",newTerminal(";"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1584 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 104 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("expression_statement",(yyvsp[-1].pAst),newTerminal(";"),NULL,NULL,NULL,NULL,NULL);}
#line 1590 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 106 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("selection_statement",newTerminal("IF"),newTerminal("("),(yyvsp[-2].pAst),newTerminal(")"),(yyvsp[0].pAst),NULL,NULL);}
#line 1596 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 107 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("selection_statement",newTerminal("IF"),newTerminal("("),(yyvsp[-4].pAst),newTerminal(")"),(yyvsp[-2].pAst),NULL,(yyvsp[0].pAst));}
#line 1602 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 109 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("iteration_statement",newTerminal("WHILE"),newTerminal("("),(yyvsp[-2].pAst),newTerminal(")"),(yyvsp[0].pAst),NULL,NULL);}
#line 1608 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 111 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("jump_statement",newTerminal("RETURN"),newTerminal(";"),NULL,NULL,NULL,NULL,NULL);}
#line 1614 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 112 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("jump_statement",newTerminal("RETURN"),(yyvsp[-1].pAst),newTerminal(";"),NULL,NULL,NULL,NULL);}
#line 1620 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 114 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("print_statement",newTerminal(PRINT),newTerminal(";"),NULL,NULL,NULL,NULL,NULL);}
#line 1626 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 115 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("print_statement",newTerminal(PRINT),(yyvsp[-1].pAst),newTerminal(";"),NULL,NULL,NULL,NULL);}
#line 1632 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 117 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("statement",newTerminal("SCAN"),(yyvsp[-1].pAst),newTerminal(";"),NULL,NULL,NULL,NULL);}
#line 1638 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 119 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("expr",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1644 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 121 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("assign_expr",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1650 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 122 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("assign_expr",newTerminal("ID"),newTerminal("ASSIGN"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1656 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 123 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("assign_expr",newTerminal("ID"),newTerminal("="),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1662 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 124 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("assign_expr",newTerminal("ID"),newTerminal("["),(yyvsp[-3].pAst),newTerminal("]"),newTerminal("="),(yyvsp[0].pAst),NULL);}
#line 1668 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 126 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("cmp_expr",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1674 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 127 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("cmp_expr",(yyvsp[-2].pAst),newTerminal("CMP"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1680 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 129 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("add_expr",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1686 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 130 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("add_expr",(yyvsp[-2].pAst),newTerminal("+"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1692 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 131 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("add_expr",(yyvsp[-2].pAst),newTerminal("-"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1698 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 133 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("mul_expr",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1704 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 134 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("mul_expr",(yyvsp[-2].pAst),newTerminal("*"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1710 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 135 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("mul_expr",(yyvsp[-2].pAst),newTerminal("/"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1716 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 136 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("mul_expr",(yyvsp[-2].pAst),newTerminal("%"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1722 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 137 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("mul_expr",newTerminal("-"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL);}
#line 1728 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 139 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("primary_expr",newTerminal("ID"),newTerminal("("),(yyvsp[-1].pAst),newTerminal(")"),NULL,NULL,NULL);}
#line 1734 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 140 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("primary_expr",newTerminal("ID"),newTerminal("("),newTerminal(")"),NULL,NULL,NULL,NULL);}
#line 1740 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 141 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("primary_expr",newTerminal("("),(yyvsp[-1].pAst),newTerminal(")"),NULL,NULL,NULL,NULL);}
#line 1746 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 142 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("primary_expr",newTerminal("ID"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1752 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 143 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("primary_expr",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1758 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 144 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("primary_expr",newTerminal("ID"),newTerminal("["),(yyvsp[-1].pAst),newTerminal("]"),NULL,NULL,NULL);}
#line 1764 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 146 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("expr_list",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1770 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 147 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("expr_list",(yyvsp[-2].pAst),newTerminal(","),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1776 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 149 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("id_list",newTerminal("ID"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1782 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 150 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = connect("id_list",(yyvsp[-2].pAst),newTerminal(","),newTerminal("ID"),NULL,NULL,NULL,NULL);}
#line 1788 "lrparser.tab.c" /* yacc.c:1646  */
    break;


#line 1792 "lrparser.tab.c" /* yacc.c:1646  */
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
#line 152 "lrparser.y" /* yacc.c:1906  */


void yyerror(char *s) 
{
    fprintf(stderr, "%s\n", s);
}
