/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./syntax.y"

    #include <stdio.h>
    #include "node.h"
    extern int syntax_errs;
    extern int yylineno;
    extern char* yytext;
    int yyerr_line=0;
    void yyerror(const char *msg);
    int yylex();
    #define YYDEBUG 1
    extern struct TN* root;

#line 84 "./syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_LP = 5,                         /* LP  */
  YYSYMBOL_RP = 6,                         /* RP  */
  YYSYMBOL_LB = 7,                         /* LB  */
  YYSYMBOL_RB = 8,                         /* RB  */
  YYSYMBOL_LC = 9,                         /* LC  */
  YYSYMBOL_RC = 10,                        /* RC  */
  YYSYMBOL_SEMI = 11,                      /* SEMI  */
  YYSYMBOL_COMMA = 12,                     /* COMMA  */
  YYSYMBOL_RELOP = 13,                     /* RELOP  */
  YYSYMBOL_ASSIGNOP = 14,                  /* ASSIGNOP  */
  YYSYMBOL_PLUS = 15,                      /* PLUS  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_STAR = 17,                      /* STAR  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_DOT = 21,                       /* DOT  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_STRUCT = 23,                    /* STRUCT  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_IF = 25,                        /* IF  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_WHILE = 27,                     /* WHILE  */
  YYSYMBOL_TYPE = 28,                      /* TYPE  */
  YYSYMBOL_ID = 29,                        /* ID  */
  YYSYMBOL_LOWER_THAN_ELSE = 30,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_Program = 32,                   /* Program  */
  YYSYMBOL_ExtDefList = 33,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 34,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 35,                /* ExtDecList  */
  YYSYMBOL_Specifier = 36,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 37,           /* StructSpecifier  */
  YYSYMBOL_OptTag = 38,                    /* OptTag  */
  YYSYMBOL_Tag = 39,                       /* Tag  */
  YYSYMBOL_VarDec = 40,                    /* VarDec  */
  YYSYMBOL_FunDec = 41,                    /* FunDec  */
  YYSYMBOL_VarList = 42,                   /* VarList  */
  YYSYMBOL_ParamDec = 43,                  /* ParamDec  */
  YYSYMBOL_CompSt = 44,                    /* CompSt  */
  YYSYMBOL_StmtList = 45,                  /* StmtList  */
  YYSYMBOL_Stmt = 46,                      /* Stmt  */
  YYSYMBOL_DefList = 47,                   /* DefList  */
  YYSYMBOL_Def = 48,                       /* Def  */
  YYSYMBOL_DecList = 49,                   /* DecList  */
  YYSYMBOL_Dec = 50,                       /* Dec  */
  YYSYMBOL_Exp = 51,                       /* Exp  */
  YYSYMBOL_Args = 52                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   455

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    44,    44,    46,    47,    49,    50,    51,    52,    53,
      54,    55,    56,    58,    59,    62,    63,    65,    66,    67,
      69,    70,    72,    75,    76,    78,    79,    81,    82,    84,
      87,    89,    90,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   106,   107,   109,   110,   111,
     113,   114,   116,   117,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   152,   153,   154
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "LP",
  "RP", "LB", "RB", "LC", "RC", "SEMI", "COMMA", "RELOP", "ASSIGNOP",
  "PLUS", "MINUS", "STAR", "DIV", "AND", "OR", "DOT", "NOT", "STRUCT",
  "RETURN", "IF", "ELSE", "WHILE", "TYPE", "ID", "LOWER_THAN_ELSE",
  "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-33)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,   257,   -28,   -42,    20,   -42,    29,     8,   -42,     5,
     -42,   -42,   -42,    23,    61,   -42,   -42,   -42,    98,   -42,
      75,    80,    74,    92,    10,    50,     5,     5,   -42,   -42,
      82,   -42,   110,    96,   -42,   111,   -42,    76,    15,   115,
      60,   -42,   -42,   113,   270,   129,   270,   126,   131,   132,
     -42,   128,    50,   287,   -42,    57,   -42,    96,   133,   137,
     135,   -42,   -42,   270,   130,   -42,    96,   -42,   -42,   134,
     308,     0,   -42,    85,   355,   143,   151,     9,   -42,   -42,
     -42,   159,   -42,   173,   181,   189,   203,   211,   219,   233,
     241,   121,   147,   -42,   146,   -42,     5,   -42,   400,   -42,
     -42,   -42,   -42,   -42,   -42,   155,   324,   160,   340,    56,
     -42,   370,   162,   161,   385,   -42,   434,   -42,   400,   -42,
       0,   -42,     0,   -42,    85,   -42,    85,   -42,   422,   -42,
     415,   -42,   -42,   -42,    99,    99,    99,    99,   -42,   270,
     249,   -42,   -42,   -42,   144,   145,   -42,   -42,   400,   167,
     -42,    99,    99,   -42,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    21,    15,     0,     2,     0,     0,    16,    46,
      10,     8,     9,    22,     0,    18,     1,     3,     0,     6,
      23,     0,    13,     0,     0,     0,    46,    46,    11,    12,
       0,     5,     0,     0,     7,     0,    23,    52,     0,    50,
       0,    70,    71,     0,     0,     0,     0,     0,     0,    69,
      34,     0,     0,     0,    45,     0,    26,     0,     0,    28,
       0,    14,    49,     0,     0,    47,     0,    39,    40,     0,
       0,    63,    82,    64,     0,     0,     0,     0,    30,    31,
      41,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    29,    25,     0,    24,    53,    48,
      51,    80,    81,    62,    35,     0,     0,     0,     0,     0,
      66,    86,     0,     0,     0,    75,    57,    72,    54,    76,
      58,    77,    59,    78,    60,    79,    61,    73,    55,    74,
      56,    68,    19,    27,     0,     0,     0,     0,    83,     0,
       0,    65,    84,    67,    42,    36,    44,    38,    87,     0,
      85,     0,     0,    43,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -42,   -42,   177,   186,   158,    -3,   -42,   -42,   -42,   -16,
     -42,   100,   -42,    55,   148,   -40,    93,   -42,   163,   -42,
     -41,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    21,     7,     8,    14,    15,    22,
      23,    58,    59,    50,    51,    52,    25,    26,    38,    39,
      53,   112
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    13,    70,    71,    73,    74,    24,    81,    37,    18,
     109,    35,    41,    42,    43,   110,    64,    87,    88,    19,
      16,    91,    98,    24,    24,    44,    65,    57,     2,    -4,
       1,    45,   -20,     3,   106,   108,   111,    20,    49,    36,
     114,    94,   116,   118,   120,   122,   124,   126,   128,   130,
      37,    40,     2,    41,    42,    43,    12,     3,    92,     9,
     -32,    40,   138,    41,    42,    43,    44,    93,   139,     9,
      27,    67,    45,    29,    46,    47,    44,    48,    34,    49,
      30,    32,    45,    32,    46,    47,    33,    48,    56,    49,
      63,    31,    81,    57,   144,   145,   146,   147,   148,   111,
      40,     9,    41,    42,    43,     2,    91,     9,     9,    28,
       3,   153,   154,    60,    69,    44,    41,    42,    43,    54,
      55,    45,    62,    46,    47,    36,    48,    66,    49,    44,
      72,    75,    41,    42,    43,    45,    76,    77,    78,    95,
     101,    99,    49,    97,   105,    44,    41,    42,    43,    96,
     131,    45,   107,    32,    41,    42,    43,   132,    49,    44,
     113,   134,    41,    42,    43,    45,   136,    44,   141,   142,
     151,   152,    49,    45,   115,    44,    41,    42,    43,   139,
      49,    45,   117,    17,    41,    42,    43,    11,    49,    44,
     119,    61,    41,    42,    43,    45,   133,    44,   150,     0,
      79,     0,    49,    45,   121,    44,    41,    42,    43,     0,
      49,    45,   123,     0,    41,    42,    43,     0,    49,    44,
     125,     0,    41,    42,    43,    45,     0,    44,     0,   100,
       0,     0,    49,    45,   127,    44,    41,    42,    43,     0,
      49,    45,   129,     0,    41,    42,    43,     0,    49,    44,
     149,     0,    41,    42,    43,    45,     0,    44,     1,     0,
       0,     0,    49,    45,     0,    44,     9,     0,    10,     0,
      49,    45,     0,    41,    42,    43,     0,     0,    49,     0,
       2,     0,     0,     0,     0,     3,    44,     0,    80,     0,
       0,     0,    45,     0,    81,     0,     0,     0,    82,    49,
      83,    84,    85,    86,    87,    88,    89,    90,    91,   102,
       0,     0,     0,     0,   103,    81,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     135,    81,     0,     0,     0,     0,     0,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   137,    81,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    81,     0,     0,     0,   104,     0,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    81,     0,     0,
       0,     0,   140,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    81,   143,     0,     0,     0,     0,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    81,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    81,     0,     0,     0,     0,     0,    83,    81,
      85,    86,    87,    88,    89,    83,    91,    85,    86,    87,
      88,    81,     0,    91,     0,     0,     0,     0,     0,    85,
      86,    87,    88,     0,     0,    91
};

static const yytype_int16 yycheck[] =
{
      40,    29,    43,    44,    45,    46,     9,     7,    24,     1,
       1,     1,     3,     4,     5,     6,     1,    17,    18,    11,
       0,    21,    63,    26,    27,    16,    11,    30,    23,     0,
       1,    22,     9,    28,    75,    76,    77,    29,    29,    29,
      81,    57,    83,    84,    85,    86,    87,    88,    89,    90,
      66,     1,    23,     3,     4,     5,     1,    28,     1,     9,
      10,     1,     6,     3,     4,     5,    16,    10,    12,     9,
       9,    11,    22,    18,    24,    25,    16,    27,    23,    29,
       5,     7,    22,     7,    24,    25,    12,    27,     6,    29,
      14,    11,     7,    96,   134,   135,   136,   137,   139,   140,
       1,     9,     3,     4,     5,    23,    21,     9,     9,    11,
      28,   151,   152,     3,     1,    16,     3,     4,     5,    26,
      27,    22,    11,    24,    25,    29,    27,    12,    29,    16,
       1,     5,     3,     4,     5,    22,     5,     5,    10,     6,
       6,    11,    29,     8,     1,    16,     3,     4,     5,    12,
      29,    22,     1,     7,     3,     4,     5,    10,    29,    16,
       1,     6,     3,     4,     5,    22,     6,    16,     6,     8,
      26,    26,    29,    22,     1,    16,     3,     4,     5,    12,
      29,    22,     1,     6,     3,     4,     5,     1,    29,    16,
       1,    33,     3,     4,     5,    22,    96,    16,   140,    -1,
      52,    -1,    29,    22,     1,    16,     3,     4,     5,    -1,
      29,    22,     1,    -1,     3,     4,     5,    -1,    29,    16,
       1,    -1,     3,     4,     5,    22,    -1,    16,    -1,    66,
      -1,    -1,    29,    22,     1,    16,     3,     4,     5,    -1,
      29,    22,     1,    -1,     3,     4,     5,    -1,    29,    16,
       1,    -1,     3,     4,     5,    22,    -1,    16,     1,    -1,
      -1,    -1,    29,    22,    -1,    16,     9,    -1,    11,    -1,
      29,    22,    -1,     3,     4,     5,    -1,    -1,    29,    -1,
      23,    -1,    -1,    -1,    -1,    28,    16,    -1,     1,    -1,
      -1,    -1,    22,    -1,     7,    -1,    -1,    -1,    11,    29,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     1,
      -1,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     7,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     7,     8,    -1,    -1,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     7,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     7,    -1,    -1,    -1,    -1,    -1,    13,     7,
      15,    16,    17,    18,    19,    13,    21,    15,    16,    17,
      18,     7,    -1,    21,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    23,    28,    32,    33,    34,    36,    37,     9,
      11,    34,    44,    29,    38,    39,     0,    33,     1,    11,
      29,    35,    40,    41,    36,    47,    48,     9,    11,    44,
       5,    11,     7,    12,    44,     1,    29,    40,    49,    50,
       1,     3,     4,     5,    16,    22,    24,    25,    27,    29,
      44,    45,    46,    51,    47,    47,     6,    36,    42,    43,
       3,    35,    11,    14,     1,    11,    12,    11,    46,     1,
      51,    51,     1,    51,    51,     5,     5,     5,    10,    45,
       1,     7,    11,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     1,    10,    40,     6,    12,     8,    51,    11,
      49,     6,     1,     6,    11,     1,    51,     1,    51,     1,
       6,    51,    52,     1,    51,     1,    51,     1,    51,     1,
      51,     1,    51,     1,    51,     1,    51,     1,    51,     1,
      51,    29,    10,    42,     6,     6,     6,     6,     6,    12,
      12,     6,     8,     8,    46,    46,    46,    46,    51,     1,
      52,    26,    26,    46,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    34,    34,    34,
      34,    34,    34,    35,    35,    36,    36,    37,    37,    37,
      38,    38,    39,    40,    40,    41,    41,    42,    42,    43,
      44,    45,    45,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    47,    47,    48,    48,    48,
      49,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    52
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     2,     2,
       2,     3,     3,     1,     3,     1,     1,     5,     2,     6,
       1,     0,     1,     1,     4,     4,     3,     3,     1,     2,
       4,     2,     0,     2,     1,     3,     5,     7,     5,     2,
       2,     2,     5,     7,     5,     2,     0,     3,     4,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     3,     4,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     4,     4,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: ExtDefList  */
#line 44 "./syntax.y"
                                                    { (yyval.node)=add_node("Program",(yyloc).first_line,1,(yyvsp[0].node));root=(yyval.node); }
#line 1668 "./syntax.tab.c"
    break;

  case 3: /* ExtDefList: ExtDef ExtDefList  */
#line 46 "./syntax.y"
                                                    { (yyval.node)=add_node("ExtDefList",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1674 "./syntax.tab.c"
    break;

  case 4: /* ExtDefList: %empty  */
#line 47 "./syntax.y"
                                                    { (yyval.node)=NULL; }
#line 1680 "./syntax.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 49 "./syntax.y"
                                                    { (yyval.node)=add_node("ExtDef",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1686 "./syntax.tab.c"
    break;

  case 6: /* ExtDef: Specifier SEMI  */
#line 50 "./syntax.y"
                                                    { (yyval.node)=add_node("ExtDef",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1692 "./syntax.tab.c"
    break;

  case 7: /* ExtDef: Specifier FunDec CompSt  */
#line 51 "./syntax.y"
                                                    { (yyval.node)=add_node("ExtDef",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1698 "./syntax.tab.c"
    break;

  case 8: /* ExtDef: error ExtDef  */
#line 52 "./syntax.y"
                                                    {}
#line 1704 "./syntax.tab.c"
    break;

  case 9: /* ExtDef: error CompSt  */
#line 53 "./syntax.y"
                                                    { yyerrok; }
#line 1710 "./syntax.tab.c"
    break;

  case 10: /* ExtDef: error SEMI  */
#line 54 "./syntax.y"
                                                    { yyerrok; }
#line 1716 "./syntax.tab.c"
    break;

  case 11: /* ExtDef: Specifier error SEMI  */
#line 55 "./syntax.y"
                                                    { yyerrok; }
#line 1722 "./syntax.tab.c"
    break;

  case 12: /* ExtDef: Specifier error CompSt  */
#line 56 "./syntax.y"
                                                    { yyerrok; }
#line 1728 "./syntax.tab.c"
    break;

  case 13: /* ExtDecList: VarDec  */
#line 58 "./syntax.y"
                                                    { (yyval.node)=add_node("ExtDecList",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1734 "./syntax.tab.c"
    break;

  case 14: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 59 "./syntax.y"
                                                    { (yyval.node)=add_node("ExtDecList",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1740 "./syntax.tab.c"
    break;

  case 15: /* Specifier: TYPE  */
#line 62 "./syntax.y"
                                                    { (yyval.node)=add_node("Specifier",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1746 "./syntax.tab.c"
    break;

  case 16: /* Specifier: StructSpecifier  */
#line 63 "./syntax.y"
                                                    { (yyval.node)=add_node("Specifier",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1752 "./syntax.tab.c"
    break;

  case 17: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 65 "./syntax.y"
                                                    { (yyval.node)=add_node("StructSpecifier",(yyloc).first_line,5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1758 "./syntax.tab.c"
    break;

  case 18: /* StructSpecifier: STRUCT Tag  */
#line 66 "./syntax.y"
                                                    { (yyval.node)=add_node("StructSpecifier",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1764 "./syntax.tab.c"
    break;

  case 19: /* StructSpecifier: STRUCT OptTag LC DefList error RC  */
#line 67 "./syntax.y"
                                                    { yyerrok; }
#line 1770 "./syntax.tab.c"
    break;

  case 20: /* OptTag: ID  */
#line 69 "./syntax.y"
                                                    { (yyval.node)=add_node("OptTag",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1776 "./syntax.tab.c"
    break;

  case 21: /* OptTag: %empty  */
#line 70 "./syntax.y"
                                                    { (yyval.node)=NULL; }
#line 1782 "./syntax.tab.c"
    break;

  case 22: /* Tag: ID  */
#line 72 "./syntax.y"
                                                    { (yyval.node)=add_node("Tag",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1788 "./syntax.tab.c"
    break;

  case 23: /* VarDec: ID  */
#line 75 "./syntax.y"
                                                    { (yyval.node)=add_node("VarDec",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1794 "./syntax.tab.c"
    break;

  case 24: /* VarDec: VarDec LB INT RB  */
#line 76 "./syntax.y"
                                                    { (yyval.node)=add_node("VarDec",(yyloc).first_line,4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1800 "./syntax.tab.c"
    break;

  case 25: /* FunDec: ID LP VarList RP  */
#line 78 "./syntax.y"
                                                    { (yyval.node)=add_node("FunDec",(yyloc).first_line,4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1806 "./syntax.tab.c"
    break;

  case 26: /* FunDec: ID LP RP  */
#line 79 "./syntax.y"
                                                    { (yyval.node)=add_node("FunDec",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1812 "./syntax.tab.c"
    break;

  case 27: /* VarList: ParamDec COMMA VarList  */
#line 81 "./syntax.y"
                                                    { (yyval.node)=add_node("VarList",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1818 "./syntax.tab.c"
    break;

  case 28: /* VarList: ParamDec  */
#line 82 "./syntax.y"
                                                    { (yyval.node)=add_node("VarList",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1824 "./syntax.tab.c"
    break;

  case 29: /* ParamDec: Specifier VarDec  */
#line 84 "./syntax.y"
                                                    { (yyval.node)=add_node("ParamDec",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1830 "./syntax.tab.c"
    break;

  case 30: /* CompSt: LC DefList StmtList RC  */
#line 87 "./syntax.y"
                                                    { (yyval.node)=add_node("CompSt",(yyloc).first_line,4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1836 "./syntax.tab.c"
    break;

  case 31: /* StmtList: Stmt StmtList  */
#line 89 "./syntax.y"
                                                    { (yyval.node)=add_node("StmtList",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1842 "./syntax.tab.c"
    break;

  case 32: /* StmtList: %empty  */
#line 90 "./syntax.y"
                                                    { (yyval.node)=NULL; }
#line 1848 "./syntax.tab.c"
    break;

  case 33: /* Stmt: Exp SEMI  */
#line 92 "./syntax.y"
                                                    { (yyval.node)=add_node("Stmt",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1854 "./syntax.tab.c"
    break;

  case 34: /* Stmt: CompSt  */
#line 93 "./syntax.y"
                                                    { (yyval.node)=add_node("Stmt",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1860 "./syntax.tab.c"
    break;

  case 35: /* Stmt: RETURN Exp SEMI  */
#line 94 "./syntax.y"
                                                    { (yyval.node)=add_node("Stmt",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1866 "./syntax.tab.c"
    break;

  case 36: /* Stmt: IF LP Exp RP Stmt  */
#line 95 "./syntax.y"
                                                    { (yyval.node)=add_node("Stmt",(yyloc).first_line,5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1872 "./syntax.tab.c"
    break;

  case 37: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 96 "./syntax.y"
                                                    { (yyval.node)=add_node("Stmt",(yyloc).first_line,7,(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1878 "./syntax.tab.c"
    break;

  case 38: /* Stmt: WHILE LP Exp RP Stmt  */
#line 97 "./syntax.y"
                                                    { (yyval.node)=add_node("Stmt",(yyloc).first_line,5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1884 "./syntax.tab.c"
    break;

  case 39: /* Stmt: error SEMI  */
#line 98 "./syntax.y"
                                                    { yyerrok; }
#line 1890 "./syntax.tab.c"
    break;

  case 40: /* Stmt: error Stmt  */
#line 99 "./syntax.y"
                                                    { yyerrok; }
#line 1896 "./syntax.tab.c"
    break;

  case 41: /* Stmt: Exp error  */
#line 100 "./syntax.y"
                                                    { yyerrok; }
#line 1902 "./syntax.tab.c"
    break;

  case 42: /* Stmt: IF LP error RP Stmt  */
#line 101 "./syntax.y"
                                                    { yyerrok; }
#line 1908 "./syntax.tab.c"
    break;

  case 43: /* Stmt: IF LP error RP Stmt ELSE Stmt  */
#line 102 "./syntax.y"
                                                    { yyerrok; }
#line 1914 "./syntax.tab.c"
    break;

  case 44: /* Stmt: WHILE LP error RP Stmt  */
#line 103 "./syntax.y"
                                                    { yyerrok; }
#line 1920 "./syntax.tab.c"
    break;

  case 45: /* DefList: Def DefList  */
#line 106 "./syntax.y"
                                                    { (yyval.node)=add_node("DefList",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1926 "./syntax.tab.c"
    break;

  case 46: /* DefList: %empty  */
#line 107 "./syntax.y"
                                                    { (yyval.node)=NULL; }
#line 1932 "./syntax.tab.c"
    break;

  case 47: /* Def: Specifier DecList SEMI  */
#line 109 "./syntax.y"
                                                    { (yyval.node)=add_node("Def",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1938 "./syntax.tab.c"
    break;

  case 48: /* Def: Specifier DecList error SEMI  */
#line 110 "./syntax.y"
                                                    { yyerrok; }
#line 1944 "./syntax.tab.c"
    break;

  case 49: /* Def: Specifier error SEMI  */
#line 111 "./syntax.y"
                                                    { yyerrok; }
#line 1950 "./syntax.tab.c"
    break;

  case 50: /* DecList: Dec  */
#line 113 "./syntax.y"
                                                    { (yyval.node)=add_node("DecList",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1956 "./syntax.tab.c"
    break;

  case 51: /* DecList: Dec COMMA DecList  */
#line 114 "./syntax.y"
                                                    { (yyval.node)=add_node("DecList",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1962 "./syntax.tab.c"
    break;

  case 52: /* Dec: VarDec  */
#line 116 "./syntax.y"
                                                    { (yyval.node)=add_node("Dec",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1968 "./syntax.tab.c"
    break;

  case 53: /* Dec: VarDec ASSIGNOP Exp  */
#line 117 "./syntax.y"
                                                    { (yyval.node)=add_node("Dec",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1974 "./syntax.tab.c"
    break;

  case 54: /* Exp: Exp ASSIGNOP Exp  */
#line 120 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1980 "./syntax.tab.c"
    break;

  case 55: /* Exp: Exp AND Exp  */
#line 121 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1986 "./syntax.tab.c"
    break;

  case 56: /* Exp: Exp OR Exp  */
#line 122 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1992 "./syntax.tab.c"
    break;

  case 57: /* Exp: Exp RELOP Exp  */
#line 123 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1998 "./syntax.tab.c"
    break;

  case 58: /* Exp: Exp PLUS Exp  */
#line 124 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2004 "./syntax.tab.c"
    break;

  case 59: /* Exp: Exp MINUS Exp  */
#line 125 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2010 "./syntax.tab.c"
    break;

  case 60: /* Exp: Exp STAR Exp  */
#line 126 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2016 "./syntax.tab.c"
    break;

  case 61: /* Exp: Exp DIV Exp  */
#line 127 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2022 "./syntax.tab.c"
    break;

  case 62: /* Exp: LP Exp RP  */
#line 128 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2028 "./syntax.tab.c"
    break;

  case 63: /* Exp: MINUS Exp  */
#line 129 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2034 "./syntax.tab.c"
    break;

  case 64: /* Exp: NOT Exp  */
#line 130 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2040 "./syntax.tab.c"
    break;

  case 65: /* Exp: ID LP Args RP  */
#line 131 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2046 "./syntax.tab.c"
    break;

  case 66: /* Exp: ID LP RP  */
#line 132 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2052 "./syntax.tab.c"
    break;

  case 67: /* Exp: Exp LB Exp RB  */
#line 133 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2058 "./syntax.tab.c"
    break;

  case 68: /* Exp: Exp DOT ID  */
#line 134 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2064 "./syntax.tab.c"
    break;

  case 69: /* Exp: ID  */
#line 135 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 2070 "./syntax.tab.c"
    break;

  case 70: /* Exp: INT  */
#line 136 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 2076 "./syntax.tab.c"
    break;

  case 71: /* Exp: FLOAT  */
#line 137 "./syntax.y"
                                                    { (yyval.node)=add_node("Exp",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 2082 "./syntax.tab.c"
    break;

  case 72: /* Exp: Exp ASSIGNOP error  */
#line 138 "./syntax.y"
                                                    { yyerrok; }
#line 2088 "./syntax.tab.c"
    break;

  case 73: /* Exp: Exp AND error  */
#line 139 "./syntax.y"
                                                    { yyerrok; }
#line 2094 "./syntax.tab.c"
    break;

  case 74: /* Exp: Exp OR error  */
#line 140 "./syntax.y"
                                                    { yyerrok; }
#line 2100 "./syntax.tab.c"
    break;

  case 75: /* Exp: Exp RELOP error  */
#line 141 "./syntax.y"
                                                    { yyerrok; }
#line 2106 "./syntax.tab.c"
    break;

  case 76: /* Exp: Exp PLUS error  */
#line 142 "./syntax.y"
                                                    { yyerrok; }
#line 2112 "./syntax.tab.c"
    break;

  case 77: /* Exp: Exp MINUS error  */
#line 143 "./syntax.y"
                                                    { yyerrok; }
#line 2118 "./syntax.tab.c"
    break;

  case 78: /* Exp: Exp STAR error  */
#line 144 "./syntax.y"
                                                    { yyerrok; }
#line 2124 "./syntax.tab.c"
    break;

  case 79: /* Exp: Exp DIV error  */
#line 145 "./syntax.y"
                                                    { yyerrok; }
#line 2130 "./syntax.tab.c"
    break;

  case 80: /* Exp: LP error RP  */
#line 146 "./syntax.y"
                                                    { yyerrok; }
#line 2136 "./syntax.tab.c"
    break;

  case 81: /* Exp: LP Exp error  */
#line 147 "./syntax.y"
                                                    { yyerrok; }
#line 2142 "./syntax.tab.c"
    break;

  case 82: /* Exp: NOT error  */
#line 148 "./syntax.y"
                                                    { yyerrok; }
#line 2148 "./syntax.tab.c"
    break;

  case 83: /* Exp: ID LP error RP  */
#line 149 "./syntax.y"
                                                    { yyerrok; }
#line 2154 "./syntax.tab.c"
    break;

  case 84: /* Exp: Exp LB error RB  */
#line 150 "./syntax.y"
                                                    { yyerrok; }
#line 2160 "./syntax.tab.c"
    break;

  case 85: /* Args: Exp COMMA Args  */
#line 152 "./syntax.y"
                                                    { (yyval.node)=add_node("Args",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2166 "./syntax.tab.c"
    break;

  case 86: /* Args: Exp  */
#line 153 "./syntax.y"
                                                    { (yyval.node)=add_node("Args",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 2172 "./syntax.tab.c"
    break;

  case 87: /* Args: error COMMA Exp  */
#line 154 "./syntax.y"
                                                    { yyerrok; }
#line 2178 "./syntax.tab.c"
    break;


#line 2182 "./syntax.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 156 "./syntax.y"


#include "lex.yy.c"
void yyerror(const char *msg) {
    if(yyerr_line==yylineno)return;
    yyerr_line=yylineno;
    syntax_errs++;
    printf("Error type B at Line %d :%s.\n",yylineno,msg);
}
