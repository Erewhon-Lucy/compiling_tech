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
    EOL = 258,
    NUMBER = 259,
    STRING = 260,
    ID = 261,
    INT = 262,
    STR = 263,
    VOID = 264,
    IF = 265,
    ELSE = 266,
    WHILE = 267,
    RETURN = 268,
    PRINT = 269,
    SCAN = 270,
    ASSIGN = 271,
    CMP = 272
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

#line 142 "lrparser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LRPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 159 "lrparser.tab.c" /* yacc.c:358  */

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
#define YYLAST   174

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
#define YYMAXUTOK   273

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
      15,    16,    17,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    44,    44,    45,    47,    48,    50,    52,    54,    55,
      57,    58,    59,    61,    62,    64,    65,    67,    69,    70,
      71,    72,    73,    76,    77,    79,    81,    82,    83,    85,
      86,    87,    88,    89,    90,    91,    92,    94,    95,    97,
      99,   101,   102,   104,   105,   107,   108,   110,   112,   113,
     115,   116,   118,   120,   122,   123,   124,   125,   127,   128,
     130,   131,   132,   134,   135,   136,   137,   138,   140,   141,
     142,   143,   144,   145,   147,   148,   150,   151
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EOL", "NUMBER", "STRING", "ID", "INT",
  "STR", "VOID", "IF", "ELSE", "WHILE", "RETURN", "PRINT", "SCAN",
  "ASSIGN", "CMP", "';'", "','", "'='", "'{'", "'}'", "'('", "')'", "'['",
  "']'", "'+'", "'-'", "'*'", "'/'", "'%'", "$accept", "program",
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
       0,   256,   273,   258,   259,   260,   261,   262,   263,   264,
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
      62,   -61,   -61,   -61,   145,   -61,   -61,   -61,    -3,   -61,
     -61,    30,     4,   -61,     6,    56,    98,   -61,    -3,   104,
     -61,   -61,    26,   139,   -61,   -61,   135,    14,   -61,    55,
     -61,   -12,   -61,    29,    23,    46,   -61,   -61,    61,    20,
      60,    23,    66,    71,   110,   113,    99,   -61,   -61,   -61,
      -3,   -61,   -61,   -61,    26,   -61,   -61,   -61,   -61,   -61,
     -61,    89,   -61,    -9,   -61,   114,    14,    14,   138,    14,
     105,   -61,   -61,   107,   107,   107,    55,    55,    55,    14,
      -6,   -61,    14,    14,   -61,   116,   -61,   -61,    79,   -61,
     121,   -61,   -61,   -61,    62,   -61,   -61,   -61,   -61,   -61,
      -7,   111,   -61,    23,    46,    46,   -61,   -61,   -61,   123,
      60,   -61,   126,   132,   -61,   -61,    14,   -61,   151,   -61,
     -61,   144,   -61,   -61,    78,    78,   -61,   -61,    14,   148,
     -61,   -61,    78,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    26,    27,    28,     0,     2,     4,     5,     0,     1,
       3,    18,     0,     8,    10,    17,     0,     7,     0,     0,
      39,     6,     0,     0,    15,    16,    71,     0,    22,     0,
      72,     0,    53,    54,    58,    60,    63,     9,    10,    71,
       0,    11,     0,     0,     0,     0,     0,    43,    40,    36,
       0,    41,    29,    37,     0,    30,    31,    32,    33,    34,
      35,     0,    20,     0,    23,     0,     0,     0,     0,     0,
       0,    67,    21,     0,     0,     0,     0,     0,     0,     0,
       0,    13,     0,     0,    48,     0,    50,    74,     0,    76,
       0,    42,    38,    44,     0,    19,    25,    55,    56,    69,
       0,     0,    70,    59,    61,    62,    64,    65,    66,     0,
       0,    12,     0,     0,    49,    51,     0,    52,     0,    24,
      68,    73,    73,    14,     0,     0,    75,    77,     0,    45,
      47,    57,     0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   161,   -61,    21,   -61,   149,   -61,   -36,   160,
     -61,   -61,    75,     1,   -52,   156,   -61,   117,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -16,   -60,   -61,   -11,    48,
     -20,   106,   -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    49,    12,    13,    80,    30,    38,
      15,    63,    64,    50,    51,    52,    22,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    32,    33,    34,    35,
      36,    88,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,     8,    91,    11,    81,     8,    97,    98,    41,    71,
      94,    70,   116,   110,    72,    95,   111,   120,    24,    25,
      26,     7,    17,    18,    65,     7,    19,    20,    85,    87,
      24,    25,    26,     1,     2,     3,    42,    27,    43,    44,
      45,    46,    29,    68,    47,    79,    73,    20,    48,    27,
      74,    75,    87,   101,    29,    16,   106,   107,   108,    24,
      25,    39,   103,   109,    24,    25,   112,   113,   131,     1,
       2,     3,   129,   130,   123,    76,    77,    78,    27,    23,
     133,    19,    24,    25,    26,     1,     2,     3,    42,    82,
      43,    44,    45,    46,    83,    65,    47,   115,   116,    20,
     126,    27,    24,    25,    26,    89,    29,    93,    24,    25,
      39,    24,    25,    39,    24,    25,    26,    24,    25,    26,
      96,    27,   104,   105,    28,    40,    29,    27,    84,   102,
      27,    86,    29,    27,   114,    29,    27,   121,    29,   117,
     118,    29,    24,    25,    26,     9,     1,     2,     3,   122,
     124,    66,     1,     2,     3,    67,   125,   127,    68,   132,
      69,    27,    99,    62,   128,    10,    29,    37,    14,   119,
      21,    92,     0,     0,   100
};

static const yytype_int16 yycheck[] =
{
      16,     0,    54,     6,    40,     4,    66,    67,    19,    29,
      19,    27,    19,    19,    26,    24,    22,    24,     4,     5,
       6,     0,    18,    19,    23,     4,    20,    21,    44,    45,
       4,     5,     6,     7,     8,     9,    10,    23,    12,    13,
      14,    15,    28,    23,    18,    25,    17,    21,    22,    23,
      27,    28,    68,    69,    28,    25,    76,    77,    78,     4,
       5,     6,    73,    79,     4,     5,    82,    83,   128,     7,
       8,     9,   124,   125,   110,    29,    30,    31,    23,    23,
     132,    20,     4,     5,     6,     7,     8,     9,    10,    23,
      12,    13,    14,    15,    23,    94,    18,    18,    19,    21,
     116,    23,     4,     5,     6,     6,    28,    18,     4,     5,
       6,     4,     5,     6,     4,     5,     6,     4,     5,     6,
       6,    23,    74,    75,    26,    21,    28,    23,    18,    24,
      23,    18,    28,    23,    18,    28,    23,    26,    28,    18,
      19,    28,     4,     5,     6,     0,     7,     8,     9,    26,
      24,    16,     7,     8,     9,    20,    24,     6,    23,    11,
      25,    23,    24,    24,    20,     4,    28,    18,     8,    94,
      14,    54,    -1,    -1,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    33,    34,    35,    36,    45,     0,
      34,     6,    37,    38,    41,    42,    25,    18,    19,    20,
      21,    47,    48,    23,     4,     5,     6,    23,    26,    28,
      40,    57,    58,    59,    60,    61,    62,    38,    41,     6,
      21,    60,    10,    12,    13,    14,    15,    18,    22,    36,
      45,    46,    47,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    24,    43,    44,    45,    16,    20,    23,    25,
      57,    62,    26,    17,    27,    28,    29,    30,    31,    25,
      39,    40,    23,    23,    18,    57,    18,    57,    63,     6,
      64,    46,    49,    18,    19,    24,     6,    58,    58,    24,
      63,    57,    24,    60,    61,    61,    62,    62,    62,    57,
      19,    22,    57,    57,    18,    18,    19,    18,    19,    44,
      24,    26,    26,    40,    24,    24,    57,     6,    20,    46,
      46,    58,    11,    46
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
#line 44 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=unite("program",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);showAst((yyvsp[0].pAst),0);}
#line 1339 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 45 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst)=unite("program",(yyvsp[-1].pAst),(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL);showAst((yyvsp[0].pAst),0);}
#line 1345 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 47 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("external_declaration",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1351 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 48 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("external_declaration",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1357 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 50 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("function_definition",(yyvsp[-2].pAst),(yyvsp[-1].pAst),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1363 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 52 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("declaration",(yyvsp[-2].pAst),(yyvsp[-1].pAst),newTerminal(";"),NULL,NULL,NULL,NULL);}
#line 1369 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 54 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("init_declarator_list",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1375 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 55 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("init_declarator_list",(yyvsp[-2].pAst),newTerminal(","),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1381 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 57 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("init_declarator",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1387 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 58 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("init_declarator",(yyvsp[-2].pAst),newTerminal("="),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1393 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 59 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("init_declarator",(yyvsp[-4].pAst),newTerminal("="),newTerminal("{"),(yyvsp[-1].pAst),newTerminal("}"),NULL,NULL);}
#line 1399 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 61 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("intstr_list",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1405 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 62 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("intstr_list",(yyvsp[-2].pAst),newTerminal(","),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1411 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 64 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("initializer",newTerminal("NUMBER"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1417 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 65 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("initializer",newTerminal("STRING"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1423 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 67 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("declarator",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1429 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 69 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("direct_declarator",newTerminal("ID"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1435 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 70 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("direct_declarator",(yyvsp[-3].pAst),newTerminal("("),(yyvsp[-1].pAst),newTerminal(")"),NULL,NULL,NULL);}
#line 1441 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 71 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("direct_declarator",(yyvsp[-2].pAst),newTerminal("("),newTerminal(")"),NULL,NULL,NULL,NULL);}
#line 1447 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 72 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("direct_declaratior",newTerminal("ID"),newTerminal("["),(yyvsp[-1].pAst),newTerminal("]"),NULL,NULL,NULL);}
#line 1453 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 73 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("direct_declaratior",newTerminal("ID"),newTerminal("["),newTerminal("]"),NULL,NULL,NULL,NULL);}
#line 1459 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 76 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("parameter_list",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1465 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 77 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("parameter_list",(yyvsp[-2].pAst),newTerminal(","),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1471 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 79 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("parameter",(yyvsp[-1].pAst),newTerminal("ID"),NULL,NULL,NULL,NULL,NULL);}
#line 1477 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 81 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("type",newTerminal("INT"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1483 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 82 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("type",newTerminal("STR"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1489 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 83 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("type",newTerminal("VOID"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1495 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 85 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1501 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 86 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1507 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 87 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1513 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 88 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1519 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 89 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1525 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 90 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1531 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 91 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1537 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 92 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("statement",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1543 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 94 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("compound_statement",(yyvsp[-1].pAst),(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL);}
#line 1549 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 95 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("compound_statement",(yyvsp[-2].pAst),(yyvsp[-1].pAst),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1555 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 97 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("begin_scope",newTerminal("{"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1561 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 99 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("end_scope",newTerminal("}"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1567 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 101 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("statement_list",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1573 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 102 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("statement_list",(yyvsp[-1].pAst),(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL);}
#line 1579 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 104 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("expression_statement",newTerminal(";"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1585 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 105 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("expression_statement",(yyvsp[-1].pAst),newTerminal(";"),NULL,NULL,NULL,NULL,NULL);}
#line 1591 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 107 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("selection_statement",newTerminal("IF"),newTerminal("("),(yyvsp[-2].pAst),newTerminal(")"),(yyvsp[0].pAst),NULL,NULL);}
#line 1597 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 108 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("selection_statement",newTerminal("IF"),newTerminal("("),(yyvsp[-4].pAst),newTerminal(")"),(yyvsp[-2].pAst),NULL,(yyvsp[0].pAst));}
#line 1603 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 110 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("iteration_statement",newTerminal("WHILE"),newTerminal("("),(yyvsp[-2].pAst),newTerminal(")"),(yyvsp[0].pAst),NULL,NULL);}
#line 1609 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 112 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("jump_statement",newTerminal("RETURN"),newTerminal(";"),NULL,NULL,NULL,NULL,NULL);}
#line 1615 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 113 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("jump_statement",newTerminal("RETURN"),(yyvsp[-1].pAst),newTerminal(";"),NULL,NULL,NULL,NULL);}
#line 1621 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 115 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("print_statement",newTerminal(PRINT),newTerminal(";"),NULL,NULL,NULL,NULL,NULL);}
#line 1627 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 116 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("print_statement",newTerminal(PRINT),(yyvsp[-1].pAst),newTerminal(";"),NULL,NULL,NULL,NULL);}
#line 1633 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 118 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("scan_statement",newTerminal("SCAN"),(yyvsp[-1].pAst),newTerminal(";"),NULL,NULL,NULL,NULL);}
#line 1639 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 120 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("expr",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1645 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 122 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("assign_expr",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1651 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 123 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("assign_expr",newTerminal("ID"),newTerminal("ASSIGN"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1657 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 124 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("assign_expr",newTerminal("ID"),newTerminal("="),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1663 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 125 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("assign_expr",newTerminal("ID"),newTerminal("["),(yyvsp[-3].pAst),newTerminal("]"),newTerminal("="),(yyvsp[0].pAst),NULL);}
#line 1669 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 127 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("cmp_expr",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1675 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 128 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("cmp_expr",(yyvsp[-2].pAst),newTerminal("CMP"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1681 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 130 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("add_expr",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1687 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 131 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("add_expr",(yyvsp[-2].pAst),newTerminal("+"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1693 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 132 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("add_expr",(yyvsp[-2].pAst),newTerminal("-"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1699 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 134 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("mul_expr",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1705 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 135 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("mul_expr",(yyvsp[-2].pAst),newTerminal("*"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1711 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 136 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("mul_expr",(yyvsp[-2].pAst),newTerminal("/"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1717 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 137 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("mul_expr",(yyvsp[-2].pAst),newTerminal("%"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1723 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 138 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("mul_expr",newTerminal("-"),(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL);}
#line 1729 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 140 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("primary_expr",newTerminal("ID"),newTerminal("("),(yyvsp[-1].pAst),newTerminal(")"),NULL,NULL,NULL);}
#line 1735 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 141 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("primary_expr",newTerminal("ID"),newTerminal("("),newTerminal(")"),NULL,NULL,NULL,NULL);}
#line 1741 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 142 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("primary_expr",newTerminal("("),(yyvsp[-1].pAst),newTerminal(")"),NULL,NULL,NULL,NULL);}
#line 1747 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 143 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("primary_expr",newTerminal("ID"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1753 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 144 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("primary_expr",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1759 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 145 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("primary_expr",newTerminal("ID"),newTerminal("["),(yyvsp[-1].pAst),newTerminal("]"),NULL,NULL,NULL);}
#line 1765 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 147 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("expr_list",(yyvsp[0].pAst),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1771 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 148 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("expr_list",(yyvsp[-2].pAst),newTerminal(","),(yyvsp[0].pAst),NULL,NULL,NULL,NULL);}
#line 1777 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 150 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("id_list",newTerminal("ID"),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 1783 "lrparser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 151 "lrparser.y" /* yacc.c:1646  */
    {(yyval.pAst) = unite("id_list",(yyvsp[-2].pAst),newTerminal(","),newTerminal("ID"),NULL,NULL,NULL,NULL);}
#line 1789 "lrparser.tab.c" /* yacc.c:1646  */
    break;


#line 1793 "lrparser.tab.c" /* yacc.c:1646  */
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
#line 153 "lrparser.y" /* yacc.c:1906  */


void yyerror(char *s) 
{
    fprintf(stderr, "%s\n", s);
}
