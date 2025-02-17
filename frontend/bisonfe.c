/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "structfe.y"


#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "pile.h"
#include "generation_code.h"

#include "structfe.tab.h"


#include <assert.h> 


int yylex(void);
void yyerror(char*);
extern int yylineno;
table_t *table_sym;



#line 95 "bisonfe.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_BISONFE_H_INCLUDED
# define YY_YY_BISONFE_H_INCLUDED
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
    SIZEOF = 258,
    PTR_OP = 259,
    LE_OP = 260,
    GE_OP = 261,
    EQ_OP = 262,
    NE_OP = 263,
    AND_OP = 264,
    OR_OP = 265,
    EXTERN = 266,
    INT = 267,
    VOID = 268,
    STRUCT = 269,
    IF = 270,
    ELSE = 271,
    WHILE = 272,
    FOR = 273,
    RETURN = 274,
    IDENTIFIER = 275,
    CONSTANT = 276,
    MOINS = 277,
    THEN = 278
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "structfe.y"

	char *nom;
	all_types all;
	double nombre;

#line 177 "bisonfe.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISONFE_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

#define YYUNDEFTOK  2
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    22,     2,
      20,    21,    23,    33,    38,    24,    37,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
      31,    30,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    26,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    28,    29,    35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,   107,   111,   119,   123,   124,   125,   126,
     130,   133,   146,   150,   163,   175,   177,   179,   185,   189,
     209,   232,   236,   253,   272,   273,   274,   275,   276,   280,
     281,   282,   286,   287,   291,   292,   296,   297,   301,   302,
     306,   307,   311,   313,   315,   320,   321,   322,   325,   326,
     330,   334,   335,   339,   349,   350,   351,   355,   356,   360,
     364,   366,   368,   370,   372,   377,   378,   379,   380,   384,
     386,   393,   395,   402,   403,   407,   408,   412,   413,   417,
     418,   422,   423,   427,   428,   432
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SIZEOF", "PTR_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "EXTERN", "INT", "VOID", "STRUCT",
  "IF", "ELSE", "WHILE", "FOR", "RETURN", "'('", "')'", "'&'", "'*'",
  "'-'", "'{'", "'}'", "';'", "IDENTIFIER", "CONSTANT", "'='", "'<'",
  "'>'", "'+'", "'/'", "MOINS", "THEN", "'.'", "','", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "logical_and_expression", "logical_or_expression", "expression",
  "declaration", "declaration_specifiers", "type_specifier",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "declarator", "direct_declarator", "parameter_list",
  "parameter_declaration", "statement", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "program", "external_declaration", "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      40,    41,    38,    42,    45,   123,   125,    59,   275,   276,
      61,    60,    62,    43,    47,   277,   278,    46,    44
};
# endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     229,    22,   -76,   -76,   -14,   -76,   211,   -76,    15,   111,
     -76,   -76,   -76,   -76,    22,    -7,   211,    -1,   -76,    27,
      12,   -76,   -76,   -76,   211,   199,   -76,    22,    30,    12,
      90,   -76,   -76,   215,    41,   -76,   -76,   207,   -76,   194,
      62,    65,    69,    68,   194,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,    11,    76,   194,    60,   -11,    18,   119,
     112,    89,   106,   -76,   211,   -76,   -76,   117,   135,   -76,
     -76,   -76,   -76,   -76,   211,   -13,   -76,   -76,   -76,   -76,
     194,   194,   181,   -76,   122,   130,   139,    52,   141,   194,
     -76,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   -76,   156,   -76,   -76,   153,   -76,   -76,
     -76,   -76,   229,   164,   166,   181,   -76,   -76,   -76,   -76,
     -12,   -76,   -76,   -76,   -76,   -76,   -76,    60,    60,   -11,
     -11,   -11,   -11,    18,    18,   119,   112,   -76,   -76,   171,
     171,   194,   -76,   194,   176,   -76,   185,   -76,   171,   171,
     -76,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    43,    42,     0,    84,     0,    41,    44,     0,
      81,    83,    40,    44,     0,    47,     0,     0,    53,     0,
      52,    39,     1,    82,     0,     0,    48,     0,     0,    51,
       0,    38,    85,     0,     0,    46,    49,     0,    54,     0,
       0,     0,     0,     0,     0,    15,    16,    17,    65,    73,
       2,     3,     5,    12,    18,     0,    21,    24,    29,    32,
      34,    36,     0,    69,     0,    71,    60,     0,     0,    61,
      62,    63,    64,    56,     0,     0,    57,    50,    45,    14,
       0,     0,     0,    79,     0,     0,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,    67,    70,     0,    66,    72,
      59,    55,     0,     0,     0,     0,    80,     4,     9,     6,
       0,    10,     8,    37,    19,    20,    18,    23,    22,    27,
      28,    25,    26,    30,    31,    33,    35,    68,    58,     0,
       0,     0,     7,     0,    75,    77,     0,    11,     0,     0,
      76,    78
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   -76,   -35,   -76,    54,   149,    66,   101,
     105,   -76,   -43,   -20,   -28,    16,     3,   188,    -9,     5,
     213,   -76,   120,   -62,   205,   -76,   168,   -75,   -76,   -76,
     -76,   -76,   228,   -76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    52,    53,   120,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     5,     6,     7,    13,    25,    26,    19,
      20,    75,    76,    65,    66,    67,    68,    69,    70,    71,
      72,     9,    10,    11
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      84,    85,    64,     8,    79,    74,   109,   115,   111,   142,
      63,    14,     8,    93,    15,    86,    36,    12,    27,    16,
      90,    28,    94,    95,    96,   112,   143,    18,    36,    34,
      24,    87,    33,     8,     2,     3,     4,   113,   114,    64,
     141,    24,    21,    24,   121,   109,   123,   106,    88,    97,
      98,    38,    30,    24,    31,    39,   124,   125,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,    77,   104,
       8,    39,    44,   119,    45,    46,    47,   144,   145,   110,
      50,    51,    80,    91,    74,    81,   150,   151,    44,    82,
      45,    46,    47,    39,    92,    83,    50,    51,   146,   102,
     147,     1,     2,     3,     4,    40,    89,    41,    42,    43,
      44,    22,    45,    46,    47,    30,    48,    49,    50,    51,
      39,   101,     1,     2,     3,     4,    99,   100,     1,     2,
       3,     4,    40,   103,    41,    42,    43,    44,    39,    45,
      46,    47,    30,   105,    49,    50,    51,   127,   128,   116,
      40,   117,    41,    42,    43,    44,    39,    45,    46,    47,
      30,   108,    49,    50,    51,   133,   134,   118,    40,   122,
      41,    42,    43,    44,    39,    45,    46,    47,    30,   137,
      49,    50,    51,    31,    39,   139,    40,   140,    41,    42,
      43,    44,   148,    45,    46,    47,    30,    39,    49,    50,
      51,    44,   135,    45,    46,    47,   149,   136,    49,    50,
      51,     2,     3,     4,    44,    37,    45,    46,    47,     2,
       3,     4,    50,    51,    32,    35,     1,     2,     3,     4,
      29,    16,   138,    78,    17,   107,    73,    23,     0,    18,
       1,     2,     3,     4,   129,   130,   131,   132
};

static const yytype_int16 yycheck[] =
{
      43,    44,    30,     0,    39,    33,    68,    82,    21,    21,
      30,    25,     9,    24,    28,     4,    25,     1,    25,    20,
      55,    16,    33,     5,     6,    38,    38,    28,    37,    24,
      14,    20,    20,    30,    12,    13,    14,    80,    81,    67,
     115,    25,    27,    27,    87,   107,    89,    67,    37,    31,
      32,    21,    25,    37,    27,     3,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    27,    64,
      67,     3,    20,    21,    22,    23,    24,   139,   140,    74,
      28,    29,    20,    23,   112,    20,   148,   149,    20,    20,
      22,    23,    24,     3,    34,    27,    28,    29,   141,    10,
     143,    11,    12,    13,    14,    15,    30,    17,    18,    19,
      20,     0,    22,    23,    24,    25,    26,    27,    28,    29,
       3,     9,    11,    12,    13,    14,     7,     8,    11,    12,
      13,    14,    15,    27,    17,    18,    19,    20,     3,    22,
      23,    24,    25,    26,    27,    28,    29,    93,    94,    27,
      15,    21,    17,    18,    19,    20,     3,    22,    23,    24,
      25,    26,    27,    28,    29,    99,   100,    28,    15,    28,
      17,    18,    19,    20,     3,    22,    23,    24,    25,    26,
      27,    28,    29,    27,     3,    21,    15,    21,    17,    18,
      19,    20,    16,    22,    23,    24,    25,     3,    27,    28,
      29,    20,   101,    22,    23,    24,    21,   102,    27,    28,
      29,    12,    13,    14,    20,    27,    22,    23,    24,    12,
      13,    14,    28,    29,    19,    26,    11,    12,    13,    14,
      17,    20,   112,    26,    23,    67,    21,     9,    -1,    28,
      11,    12,    13,    14,    95,    96,    97,    98
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    12,    13,    14,    52,    53,    54,    55,    70,
      71,    72,    54,    55,    25,    28,    20,    23,    28,    58,
      59,    27,     0,    71,    54,    56,    57,    25,    58,    59,
      25,    27,    63,    20,    58,    26,    57,    56,    21,     3,
      15,    17,    18,    19,    20,    22,    23,    24,    26,    27,
      28,    29,    40,    41,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    62,    63,    64,    65,    66,
      67,    68,    69,    21,    53,    60,    61,    27,    26,    43,
      20,    20,    20,    27,    51,    51,     4,    20,    37,    30,
      43,    23,    34,    24,    33,     5,     6,    31,    32,     7,
       8,     9,    10,    27,    58,    26,    52,    65,    26,    62,
      58,    21,    38,    51,    51,    66,    27,    21,    28,    21,
      42,    51,    28,    51,    43,    43,    43,    45,    45,    46,
      46,    46,    46,    47,    47,    48,    49,    26,    61,    21,
      21,    66,    21,    38,    62,    62,    51,    51,    16,    21,
      62,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    40,    41,    41,    41,    41,    41,
      42,    42,    43,    43,    43,    44,    44,    44,    45,    45,
      45,    46,    46,    46,    47,    47,    47,    47,    47,    48,
      48,    48,    49,    49,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    55,    55,    55,    56,    56,
      57,    58,    58,    59,    59,    59,    59,    60,    60,    61,
      62,    62,    62,    62,    62,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     3,     4,     3,     3,
       1,     3,     1,     2,     2,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     3,     2,
       2,     1,     1,     1,     1,     5,     4,     2,     1,     2,
       3,     2,     1,     1,     3,     4,     3,     1,     3,     2,
       1,     1,     1,     1,     1,     2,     3,     3,     4,     1,
       2,     1,     2,     1,     2,     5,     7,     5,     7,     2,
       3,     1,     2,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 97 "structfe.y"
                        { (yyval.all).code = init_code();
                          (yyval.all).nom_res = strdup((yyvsp[0].nom));
                          inserer(table_sym, (yyvsp[0].nom));
                          //symbole_t *s = recherche(table_sym, $1);   //faire strdup pour le $1 dans recherche ??
                           //     if (s == NULL){
                          //              fprintf(stderr, "La variable %s a la ligne %d n'a jamais été déclaré.",$1, yylineno);
                          //      }
                          (yyval.all).s = s;
                          (yyval.all).type = s->type; }
#line 1489 "bisonfe.c"
    break;

  case 3:
#line 107 "structfe.y"
                   { (yyval.all).code = init_code(); 
                     (yyval.all).s = NULL;
                     (yyval.all).type = ENTIER;
                     (yyval.all).nom_res = strdup((yyvsp[0].nombre)) }
#line 1498 "bisonfe.c"
    break;

  case 4:
#line 111 "structfe.y"
                                { (yyval.all).code = init_code();
                                  (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[-1].all).code);
                                  (yyval.all).s = (yyvsp[-1].all).s;
                                  (yyval.all).type = (yyvsp[-1].all).type;
                                  (yyval.all).nom_res = strdup((yyvsp[-1].all).nom_res); }
#line 1508 "bisonfe.c"
    break;

  case 5:
#line 119 "structfe.y"
                             { (yyval.all).code = (yyvsp[0].all).code;
                               (yyval.all).s = (yyvsp[0].all).s;
                               (yyval.all).type = (yyvsp[0].all).type;
                               (yyval.all).nom_res = strdup((yyvsp[0].all).nom_res); }
#line 1517 "bisonfe.c"
    break;

  case 10:
#line 130 "structfe.y"
                     {  (yyval.all).code = (yyvsp[0].all).code;
                        (yyval.all).type = (yyvsp[0].all).type;
                        (yyval.all).nom_res = strdup((yyvsp[0].all).nom_res);}
#line 1525 "bisonfe.c"
    break;

  case 11:
#line 133 "structfe.y"
                                                   { (yyval.all).code = init_code();
                                                     (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[-2].all).code);
                                                     (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[0].all).code);
                                                     
                                                     // $$.type = 

                                                     (yyval.all).nom_res = init_code();
                                                     (yyval.all).nom_res = inserer_code((yyval.all).nom_res, (yyvsp[-2].all).nom_res);
                                                     (yyval.all).nom_res = inserer_code((yyval.all).nom_res, ",");
                                                     (yyval.all).nom_res = inserer_code((yyval.all).nom_res, (yyvsp[0].all).nom_res); }
#line 1540 "bisonfe.c"
    break;

  case 12:
#line 146 "structfe.y"
                              {(yyval.all).code = (yyvsp[0].all).code;
                               (yyval.all).s = (yyvsp[0].all).s;
                               (yyval.all).type = (yyvsp[0].all).type;
                               (yyval.all).nom_res = strdup((yyvsp[0].all).nom_res); }
#line 1549 "bisonfe.c"
    break;

  case 13:
#line 150 "structfe.y"
                                             {(yyval.all).code = init_code();
        					(yyval.all).code = inserer_code((yyval.all).code, (yyvsp[-1].all).code);
        					(yyval.all).code = inserer_code((yyval.all).code, (yyvsp[0].all).code);
        					if ((yyvsp[-1].all) == "&" && (yyvsp[0].all).type == ENTIER)
        						(yyval.all).type = ENTIER;
        					else if ((yyvsp[-1].all) == "*" && (yyvsp[0].all).type == POINTEUR)
        						(yyval.all).type = POINTEUR;
        					else if ((yyvsp[-1].all) == "-" && (yyvsp[0].all).type == ENTIER)
        						(yyval.all).type = ENTIER;
        					else
        						fprintf(stderr, "Incompatibilité entre le signe unaire et le type de l'expression qui suit, à la ligne %d\n", yylineno);}
#line 1565 "bisonfe.c"
    break;

  case 14:
#line 163 "structfe.y"
                                     { (yyval.all).code = init_code();
        				(yyval.all).code = inserer_code((yyval.all).code, "sizeof");
        				(yyval.all).code = inserer_code((yyval.all).code, (yyvsp[0].all).code); 
        				if ((yyvsp[0].all).type == ENTIER)
        					(yyval.all).type = ENTIER;
        				else
        					fprintf(stderr, "l'opérande n'est pas un entier, ligne %d, mais est de type %s\n.", yylineno, (yyvsp[0].all).type);  }
#line 1577 "bisonfe.c"
    break;

  case 15:
#line 175 "structfe.y"
               { (yyval.all).code = init_code(); 
                 (yyval.all).code = inserer_code((yyval.all).code, "&"); }
#line 1584 "bisonfe.c"
    break;

  case 16:
#line 177 "structfe.y"
               { (yyval.all).code = init_code(); 
                 (yyval.all).code = inserer_code((yyval.all).code, "*");}
#line 1591 "bisonfe.c"
    break;

  case 17:
#line 179 "structfe.y"
                          { (yyval.all).code = init_code(); 
                            (yyval.all).code = inserer_code((yyval.all).code, "-");}
#line 1598 "bisonfe.c"
    break;

  case 18:
#line 185 "structfe.y"
                           { (yyval.all).code = strdup((yyvsp[0].all).code);
                             (yyval.all).s = (yyvsp[0].all).s;
                             (yyval.all).type = (yyvsp[0].all).type;
                             (yyval.all).nom_res = strdup((yyvsp[0].all).nom_res); }
#line 1607 "bisonfe.c"
    break;

  case 19:
#line 189 "structfe.y"
                                                         { if ((yyvsp[-2].all).type == ENTIER) {
                                                                if ((yyvsp[0].all).type == ENTIER) {
                                                                        (yyval.all).type = ENTIER;
                                                                } else {
                                                                        fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s.", yylineno, (yyvsp[-2].all).type);
                                                                } else {
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.", yylineno, (yyvsp[0].all).type);
                                                                }
                                                        }
                                                        (yyval.all).s = NULL;
                                                        (yyval.all).code = init_code();
                                                        (yyval.all).nom_res = (yyval.all).nom_res;    // a revoir
                                                        (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[-2].all).code);
                                                        (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[0].all).code);
                                                        (yyval.all).code = inserer_code((yyval.all).code, (yyval.all).nom_res);
                                                        (yyval.all).code = inserer_code((yyval.all).code, "=");
                                                        (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[-2].all).nom_res);
                                                        (yyval.all).code = inserer_code((yyval.all).code, "*");
                                                        (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[0].all).nom_res);
                                                        (yyval.all).code = inserer_code((yyval.all).code, ";\n"); }
#line 1632 "bisonfe.c"
    break;

  case 20:
#line 209 "structfe.y"
                                                         { if ((yyvsp[-2].all).type == ENTIER) {
                                                                if ((yyvsp[0].all).type == ENTIER) {
                                                                        (yyval.all).type = ENTIER;
                                                                } else {
                                                                        fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s.", yylineno, (yyvsp[-2].all).type);
                                                                } else {
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.", yylineno, (yyvsp[0].all).type);
                                                                }
                                                        }
                                                        (yyval.all).s = NULL;
                                                        (yyval.all).code = init_code();
                                                        (yyval.all).nom_res = (yyval.all).nom_res;    // a revoir
                                                        (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[-2].all).code);
                                                        (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[0].all).code);
                                                        (yyval.all).code = inserer_code((yyval.all).code, (yyval.all).nom_res);
                                                        (yyval.all).code = inserer_code((yyval.all).code, "=");
                                                        (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[-2].all).nom_res);
                                                        (yyval.all).code = inserer_code((yyval.all).code, "/");
                                                        (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[0].all).nom_res);
                                                        (yyval.all).code = inserer_code((yyval.all).code, ";\n"); }
#line 1657 "bisonfe.c"
    break;

  case 21:
#line 232 "structfe.y"
                                    { (yyval.all).code = strdup((yyvsp[0].all).code);
                                      (yyval.all).s = (yyvsp[0].all).s;
                                      (yyval.all).type = (yyvsp[0].all).type;
                                      (yyval.all).nom_res = strdup((yyvsp[0].all).nom_res); }
#line 1666 "bisonfe.c"
    break;

  case 22:
#line 236 "structfe.y"
                                                               { (yyval.all).code = init.code();
        							    (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[-2].all).code);
        							    (yyval.all).code = inserer_code((yyval.all).code, '+');
        							    (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[0].all).code);
        							    (yyval.all).code = inserer_code((yyval.all).code, ";\n");
        
         							   if ((yyvsp[-2].all).type == ENTIER) {
                                                                	if ((yyvsp[0].all).type == ENTIER) {
                                                                        (yyval.all).type = ENTIER;
                                                                	} else {
                                                                        fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s.", yylineno, (yyvsp[-2].all).type);
                                                                }} else {
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.", yylineno, (yyvsp[0].all).type);
                                                                }}
#line 1685 "bisonfe.c"
    break;

  case 23:
#line 253 "structfe.y"
                                                                { (yyval.all).code = init.code();
        							    (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[-2].all).code);
        							    (yyval.all).code = inserer_code((yyval.all).code, '-');
        							    (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[0].all).code);
        							    (yyval.all).code = inserer_code((yyval.all).code, ";\n");
        
         							   if ((yyvsp[-2].all).type == ENTIER) {
                                                                	if ((yyvsp[0].all).type == ENTIER) {
                                                                        (yyval.all).type = ENTIER;
                                                                	} else {
                                                                        fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s.", yylineno, (yyvsp[-2].all).type);
                                                                }} else {
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.", yylineno, (yyvsp[0].all).type);
                                                                }}
#line 1704 "bisonfe.c"
    break;

  case 42:
#line 311 "structfe.y"
                 { (yyval.all).code = "void";
                   (yyval.all).type =  VIDE;  }
#line 1711 "bisonfe.c"
    break;

  case 43:
#line 313 "structfe.y"
                 { (yyval.all).code = "int";
                   (yyval.all).type = ENTIER; }
#line 1718 "bisonfe.c"
    break;

  case 44:
#line 315 "structfe.y"
                           { (yyval.all).code = (yyvsp[0].all).code;
                             (yyval.all).type = (yyvsp[0].all).type; }
#line 1725 "bisonfe.c"
    break;

  case 47:
#line 322 "structfe.y"
                               { inserer(table_sym, (yyvsp[-1].all));}
#line 1731 "bisonfe.c"
    break;

  case 53:
#line 339 "structfe.y"
                      {symbole_t *s; 
        		(yyval.all).nom_res = strdup((yyvsp[0].nom));   //voir avec arnaud
        		inserer(table_sym, (yyvsp[0].nom));
                      // s = recherche(table_sym, $1);   //strdup dans le recherche pour $1 ???
                      // if (s != NULL) {
                       //	inserer(table_sym, $1);
                       //} else {
                      // 	fprintf(stderr, "Variable %s a la ligne %d déja déclaré.",$1, yylineno);
                      // }
                      }
#line 1746 "bisonfe.c"
    break;

  case 60:
#line 364 "structfe.y"
                             { (yyval.all).code = (yyvsp[0].all).code;
                               (yyval.all).type = (yyvsp[0].all).type; }
#line 1753 "bisonfe.c"
    break;

  case 61:
#line 366 "structfe.y"
                                { (yyval.all).code = (yyvsp[0].all).code;
                                  (yyval.all).type = (yyvsp[0].all).type; }
#line 1760 "bisonfe.c"
    break;

  case 62:
#line 368 "structfe.y"
                               { (yyval.all).code = (yyvsp[0].all).code;
                                 (yyval.all).type = (yyvsp[0].all).type; }
#line 1767 "bisonfe.c"
    break;

  case 63:
#line 370 "structfe.y"
                              { (yyval.all).code = (yyvsp[0].all).code;
                                (yyval.all).type = (yyvsp[0].all).type; }
#line 1774 "bisonfe.c"
    break;

  case 64:
#line 372 "structfe.y"
                         { (yyval.all).code = (yyvsp[0].all).code;
                           (yyval.all).type = (yyvsp[0].all).type; }
#line 1781 "bisonfe.c"
    break;

  case 69:
#line 384 "structfe.y"
                      { (yyval.all).code = (yyvsp[0].all).code;
                        (yyval.all).type = (yyvsp[0].all).type; }
#line 1788 "bisonfe.c"
    break;

  case 70:
#line 386 "structfe.y"
                                        { (yyval.all).code = init_code();
                                          (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[-1].all).code);
                                          (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[0].all).code);
                                          (yyval.all).type = (yyvsp[0].all).type; }
#line 1797 "bisonfe.c"
    break;

  case 71:
#line 393 "structfe.y"
                      { (yyval.all).code = (yyvsp[0].all).code;
                        (yyval.all).type = (yyvsp[0].all).type; }
#line 1804 "bisonfe.c"
    break;

  case 72:
#line 395 "structfe.y"
                                   { (yyval.all).code = init_code();
                                     (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[-1].all).code);
                                     (yyval.all).code = inserer_code((yyval.all).code, (yyvsp[0].all).code);
                                     (yyval.all).type = (yyvsp[0].all).type; }
#line 1813 "bisonfe.c"
    break;


#line 1817 "bisonfe.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 435 "structfe.y"



void yyerror(char *s) {
        fprintf(stderr, "Erreur de syntaxe a la ligne %d: %s\n", yylineno, s );
}



int main(){
	table_t *table_sym = new_table();
  	yyparse();
  	printf("Analyse réussi\n");
  	return 0;
}








