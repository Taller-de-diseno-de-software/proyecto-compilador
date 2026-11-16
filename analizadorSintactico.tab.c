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
#line 13 "analizadorSintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "analizadorSemantico.h"

int yylex(void);
void yyerror(const char *s);
extern int yylineno;

nodoAST *raiz;

#line 84 "analizadorSintactico.tab.c"

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

#include "analizadorSintactico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BOOLEAN = 3,                    /* BOOLEAN  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_EXTERN = 5,                     /* EXTERN  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_DO = 11,                        /* DO  */
  YYSYMBOL_FLOAT = 12,                     /* FLOAT  */
  YYSYMBOL_CTE_LOGICA = 13,                /* CTE_LOGICA  */
  YYSYMBOL_CTE_ENTERA = 14,                /* CTE_ENTERA  */
  YYSYMBOL_CTE_FLOAT = 15,                 /* CTE_FLOAT  */
  YYSYMBOL_ID = 16,                        /* ID  */
  YYSYMBOL_OP_SUMA = 17,                   /* OP_SUMA  */
  YYSYMBOL_OP_PROD = 18,                   /* OP_PROD  */
  YYSYMBOL_OP_RESTA = 19,                  /* OP_RESTA  */
  YYSYMBOL_OP_DIV = 20,                    /* OP_DIV  */
  YYSYMBOL_OP_DIVENT = 21,                 /* OP_DIVENT  */
  YYSYMBOL_OP_MENOR = 22,                  /* OP_MENOR  */
  YYSYMBOL_OP_MAYOREQ = 23,                /* OP_MAYOREQ  */
  YYSYMBOL_OP_MAYOR = 24,                  /* OP_MAYOR  */
  YYSYMBOL_OP_EQ = 25,                     /* OP_EQ  */
  YYSYMBOL_OP_AND = 26,                    /* OP_AND  */
  YYSYMBOL_OP_OR = 27,                     /* OP_OR  */
  YYSYMBOL_OP_NEG = 28,                    /* OP_NEG  */
  YYSYMBOL_OP_ASIG = 29,                   /* OP_ASIG  */
  YYSYMBOL_PUNTO_COMA = 30,                /* PUNTO_COMA  */
  YYSYMBOL_PAR_IZQ = 31,                   /* PAR_IZQ  */
  YYSYMBOL_PAR_DER = 32,                   /* PAR_DER  */
  YYSYMBOL_LLAVE_IZQ = 33,                 /* LLAVE_IZQ  */
  YYSYMBOL_LLAVE_DER = 34,                 /* LLAVE_DER  */
  YYSYMBOL_COMA = 35,                      /* COMA  */
  YYSYMBOL_SIGNO_MENOS = 36,               /* SIGNO_MENOS  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_P = 38,                         /* P  */
  YYSYMBOL_DECLS = 39,                     /* DECLS  */
  YYSYMBOL_DECL = 40,                      /* DECL  */
  YYSYMBOL_VAR = 41,                       /* VAR  */
  YYSYMBOL_IDS = 42,                       /* IDS  */
  YYSYMBOL_ID_PRIMA = 43,                  /* ID_PRIMA  */
  YYSYMBOL_METHOD = 44,                    /* METHOD  */
  YYSYMBOL_EXTERN_DECL = 45,               /* EXTERN_DECL  */
  YYSYMBOL_PARAMS = 46,                    /* PARAMS  */
  YYSYMBOL_PARAMS_PRIMA = 47,              /* PARAMS_PRIMA  */
  YYSYMBOL_PARAM = 48,                     /* PARAM  */
  YYSYMBOL_BLOQUE = 49,                    /* BLOQUE  */
  YYSYMBOL_VAR_DECL = 50,                  /* VAR_DECL  */
  YYSYMBOL_STATEMENTS = 51,                /* STATEMENTS  */
  YYSYMBOL_TYPE = 52,                      /* TYPE  */
  YYSYMBOL_STATEMENT = 53,                 /* STATEMENT  */
  YYSYMBOL_OPTIONAL_ELSE = 54,             /* OPTIONAL_ELSE  */
  YYSYMBOL_OPTIONAL_EXPR = 55,             /* OPTIONAL_EXPR  */
  YYSYMBOL_METHOD_CALL = 56,               /* METHOD_CALL  */
  YYSYMBOL_ARGS = 57,                      /* ARGS  */
  YYSYMBOL_ARGS_PRIMA = 58,                /* ARGS_PRIMA  */
  YYSYMBOL_ARG = 59,                       /* ARG  */
  YYSYMBOL_EXPR = 60,                      /* EXPR  */
  YYSYMBOL_LITERAL = 61                    /* LITERAL  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    56,    57,    61,    62,    63,    67,    71,
      75,    76,    80,    81,    82,    83,    88,    89,    90,    91,
      95,    99,   100,   104,   108,   112,   113,   117,   118,   122,
     123,   124,   128,   129,   130,   131,   132,   133,   134,   135,
     139,   140,   144,   145,   149,   150,   154,   158,   159,   163,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     179,   180,   181,   182,   183,   184,   185,   190,   191,   192
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BOOLEAN", "ELSE",
  "EXTERN", "IF", "INT", "RETURN", "VOID", "WHILE", "DO", "FLOAT",
  "CTE_LOGICA", "CTE_ENTERA", "CTE_FLOAT", "ID", "OP_SUMA", "OP_PROD",
  "OP_RESTA", "OP_DIV", "OP_DIVENT", "OP_MENOR", "OP_MAYOREQ", "OP_MAYOR",
  "OP_EQ", "OP_AND", "OP_OR", "OP_NEG", "OP_ASIG", "PUNTO_COMA", "PAR_IZQ",
  "PAR_DER", "LLAVE_IZQ", "LLAVE_DER", "COMA", "SIGNO_MENOS", "$accept",
  "P", "DECLS", "DECL", "VAR", "IDS", "ID_PRIMA", "METHOD", "EXTERN_DECL",
  "PARAMS", "PARAMS_PRIMA", "PARAM", "BLOQUE", "VAR_DECL", "STATEMENTS",
  "TYPE", "STATEMENT", "OPTIONAL_ELSE", "OPTIONAL_EXPR", "METHOD_CALL",
  "ARGS", "ARGS_PRIMA", "ARG", "EXPR", "LITERAL", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     104,   -58,   103,   -58,    -8,   -58,    16,   -58,   104,   -58,
     -58,   -58,     7,    10,    15,    23,   -58,   -58,     3,    28,
      35,    41,    -2,     0,    66,   -58,   -58,    21,    48,    51,
      55,    54,    72,    51,    59,    57,   -58,    65,    64,    73,
      97,    67,   -58,    51,    67,   -58,   -58,   -58,    51,   -58,
      74,   -58,   100,    67,    53,    66,   -58,   -58,   -58,   -58,
     -58,   -58,   114,    86,   115,    51,     6,   -58,   -58,    63,
      53,   102,    86,   -58,   -58,   -58,   116,    86,    86,    86,
     118,   -58,   179,   -58,    86,   121,    86,    62,   -58,   -58,
     -58,   101,   -58,   -58,   117,   -58,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,   133,   130,   165,
     -58,   131,   127,   179,    51,   -58,    47,   -58,    47,   -58,
     -58,   200,   200,   200,   200,   209,   190,    51,    86,   -58,
     -58,    86,   -58,   160,   -58,   149,   -58,    51,   -58,   -58,
     -58
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    31,     0,    29,     0,    30,     0,     2,     4,     5,
       6,     7,     0,     0,     0,     0,     1,     3,    11,     0,
       0,     0,     0,     0,     0,     9,     8,     0,     0,     0,
       0,    22,     0,     0,     0,    11,    10,     0,     0,     0,
       0,    26,    15,     0,     0,    20,    23,    14,     0,    19,
       0,    18,     0,    26,    28,     0,    13,    21,    12,    17,
      16,    25,     0,    43,     0,     0,     0,    38,    39,     0,
      28,     0,     0,    68,    67,    69,    50,     0,     0,     0,
       0,    51,    42,    52,     0,     0,     0,     0,    24,    27,
      33,     0,    64,    65,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,     0,    48,    49,     0,    66,    53,    55,    54,    56,
      57,    58,    59,    60,    61,    62,    63,     0,     0,    32,
      44,     0,    46,    41,    36,     0,    47,     0,    34,    35,
      40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   169,   -58,   -28,   154,   -58,   -58,   -58,    29,
     -58,   -58,   -29,   126,   110,     9,   -58,   -58,   -58,   -52,
     105,   -58,   -58,   -57,   -58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,    19,    25,    10,    11,    30,
      45,    31,    68,    54,    69,    32,    70,   138,    80,    81,
     111,   132,   112,   113,    83
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,     1,    71,     1,    47,     3,    82,     3,    15,    12,
       5,    14,     5,    53,    56,    91,    16,    12,    71,    58,
      92,    93,    94,    18,     1,    53,    20,   107,     3,   109,
      29,    21,    33,     5,    23,    86,    85,    87,    24,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      55,     1,    34,    37,    22,     3,    38,    40,    26,    62,
       5,    63,    55,    64,    65,    97,    27,    99,   100,    66,
       1,   135,    28,    57,     3,    73,    74,    75,    76,     5,
      39,    77,    35,    67,    41,   133,    41,    43,    46,    44,
      78,    48,    24,    79,   110,    49,    50,    88,   134,    73,
      74,    75,    76,    51,    59,    77,     1,     1,   140,     2,
       3,     3,    13,     4,    78,     5,     5,    79,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    52,
      60,   108,    90,   114,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    72,    84,    87,    95,   115,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   128,   131,   130,   137,   127,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    17,    36,    61,
      89,   139,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,   129,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,   136
};

static const yytype_int16 yycheck[] =
{
      29,     3,    54,     3,    33,     7,    63,     7,    16,     0,
      12,     2,    12,    41,    43,    72,     0,     8,    70,    48,
      77,    78,    79,    16,     3,    53,    16,    84,     7,    86,
      32,    16,    32,    12,    31,    29,    65,    31,    35,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      41,     3,    23,    32,    31,     7,    27,    28,    30,     6,
      12,     8,    53,    10,    11,    18,    31,    20,    21,    16,
       3,   128,    31,    44,     7,    13,    14,    15,    16,    12,
      32,    19,    16,    30,    33,   114,    33,    32,    16,    35,
      28,    32,    35,    31,    32,    30,    32,    34,   127,    13,
      14,    15,    16,    30,    30,    19,     3,     3,   137,     5,
       7,     7,     9,     9,    28,    12,    12,    31,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    32,
      30,    10,    30,    32,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    31,    31,    31,    30,    32,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    31,    35,    32,     4,    32,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     8,    24,    53,
      70,    32,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    30,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,   131
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     7,     9,    12,    38,    39,    40,    41,
      44,    45,    52,     9,    52,    16,     0,    39,    16,    42,
      16,    16,    31,    31,    35,    43,    30,    31,    31,    32,
      46,    48,    52,    32,    46,    16,    42,    32,    46,    32,
      46,    33,    49,    32,    35,    47,    16,    49,    32,    30,
      32,    30,    32,    41,    50,    52,    49,    46,    49,    30,
      30,    50,     6,     8,    10,    11,    16,    30,    49,    51,
      53,    56,    31,    13,    14,    15,    16,    19,    28,    31,
      55,    56,    60,    61,    31,    49,    29,    31,    34,    51,
      30,    60,    60,    60,    60,    30,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    60,    10,    60,
      32,    57,    59,    60,    32,    32,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    32,    31,    30,
      32,    35,    58,    49,    49,    60,    57,     4,    54,    32,
      49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    41,    42,
      43,    43,    44,    44,    44,    44,    45,    45,    45,    45,
      46,    47,    47,    48,    49,    50,    50,    51,    51,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    54,    55,    55,    56,    56,    57,    58,    58,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    61,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     3,     2,
       2,     0,     6,     6,     5,     5,     7,     7,     6,     6,
       2,     2,     0,     2,     4,     2,     0,     2,     0,     1,
       1,     1,     4,     2,     6,     6,     5,     3,     1,     1,
       2,     0,     1,     0,     4,     3,     2,     2,     0,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     1,     1,     1
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
#  undef YYSTACK_RELOCATE
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
  case 2: /* P: DECLS  */
#line 52 "analizadorSintactico.y"
            {(yyval.nodo) = crearNodo(NODO_DECLS, NULL, (yyvsp[0].nodo), NULL, NULL, NULL); raiz = (yyval.nodo);}
#line 1240 "analizadorSintactico.tab.c"
    break;

  case 3: /* DECLS: DECL DECLS  */
#line 56 "analizadorSintactico.y"
                 {(yyval.nodo) = crearNodo(NODO_DECLS, NULL, (yyvsp[-1].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1246 "analizadorSintactico.tab.c"
    break;

  case 4: /* DECLS: %empty  */
#line 57 "analizadorSintactico.y"
      {(yyval.nodo) = NULL;}
#line 1252 "analizadorSintactico.tab.c"
    break;

  case 5: /* DECL: VAR  */
#line 61 "analizadorSintactico.y"
          {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1258 "analizadorSintactico.tab.c"
    break;

  case 6: /* DECL: METHOD  */
#line 62 "analizadorSintactico.y"
             {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1264 "analizadorSintactico.tab.c"
    break;

  case 7: /* DECL: EXTERN_DECL  */
#line 63 "analizadorSintactico.y"
                  {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1270 "analizadorSintactico.tab.c"
    break;

  case 8: /* VAR: TYPE IDS PUNTO_COMA  */
#line 67 "analizadorSintactico.y"
                          {(yyval.nodo) = crearNodo(NODO_VAR, NULL, (yyvsp[-2].nodo), (yyvsp[-1].nodo), NULL, NULL);}
#line 1276 "analizadorSintactico.tab.c"
    break;

  case 9: /* IDS: ID ID_PRIMA  */
#line 71 "analizadorSintactico.y"
                  {(yyval.nodo) = crearNodo(NODO_IDS, (yyvsp[-1].str), (yyvsp[0].nodo), NULL, NULL, NULL);}
#line 1282 "analizadorSintactico.tab.c"
    break;

  case 10: /* ID_PRIMA: COMA IDS  */
#line 75 "analizadorSintactico.y"
               {(yyval.nodo) = crearNodo(NODO_IDS, NULL, (yyvsp[0].nodo), NULL, NULL, NULL);}
#line 1288 "analizadorSintactico.tab.c"
    break;

  case 11: /* ID_PRIMA: %empty  */
#line 76 "analizadorSintactico.y"
      {(yyval.nodo) = NULL;}
#line 1294 "analizadorSintactico.tab.c"
    break;

  case 12: /* METHOD: TYPE ID PAR_IZQ PARAMS PAR_DER BLOQUE  */
#line 80 "analizadorSintactico.y"
                                            {(yyval.nodo) = crearNodo(NODO_METHOD, (yyvsp[-4].str), (yyvsp[-5].nodo), (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL);}
#line 1300 "analizadorSintactico.tab.c"
    break;

  case 13: /* METHOD: VOID ID PAR_IZQ PARAMS PAR_DER BLOQUE  */
#line 81 "analizadorSintactico.y"
                                            {(yyval.nodo) = crearNodo(NODO_METHOD, (yyvsp[-4].str), NULL, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL);}
#line 1306 "analizadorSintactico.tab.c"
    break;

  case 14: /* METHOD: TYPE ID PAR_IZQ PAR_DER BLOQUE  */
#line 82 "analizadorSintactico.y"
                                     {(yyval.nodo) = crearNodo(NODO_METHOD, (yyvsp[-3].str), (yyvsp[-4].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1312 "analizadorSintactico.tab.c"
    break;

  case 15: /* METHOD: VOID ID PAR_IZQ PAR_DER BLOQUE  */
#line 83 "analizadorSintactico.y"
                                     {(yyval.nodo) = crearNodo(NODO_METHOD, (yyvsp[-3].str), NULL, (yyvsp[0].nodo), NULL, NULL);}
#line 1318 "analizadorSintactico.tab.c"
    break;

  case 16: /* EXTERN_DECL: EXTERN TYPE ID PAR_IZQ PARAMS PAR_DER PUNTO_COMA  */
#line 88 "analizadorSintactico.y"
                                                       {(yyval.nodo) = crearNodo(NODO_EXTERN, (yyvsp[-4].str), (yyvsp[-5].nodo), (yyvsp[-2].nodo), NULL, NULL);}
#line 1324 "analizadorSintactico.tab.c"
    break;

  case 17: /* EXTERN_DECL: EXTERN VOID ID PAR_IZQ PARAMS PAR_DER PUNTO_COMA  */
#line 89 "analizadorSintactico.y"
                                                       {(yyval.nodo) = crearNodo(NODO_EXTERN, (yyvsp[-4].str), NULL, (yyvsp[-2].nodo), NULL, NULL);}
#line 1330 "analizadorSintactico.tab.c"
    break;

  case 18: /* EXTERN_DECL: EXTERN TYPE ID PAR_IZQ PAR_DER PUNTO_COMA  */
#line 90 "analizadorSintactico.y"
                                                {(yyval.nodo) = crearNodo(NODO_EXTERN, (yyvsp[-3].str), (yyvsp[-4].nodo), NULL, NULL, NULL);}
#line 1336 "analizadorSintactico.tab.c"
    break;

  case 19: /* EXTERN_DECL: EXTERN VOID ID PAR_IZQ PAR_DER PUNTO_COMA  */
#line 91 "analizadorSintactico.y"
                                                {(yyval.nodo) = crearNodo(NODO_EXTERN, (yyvsp[-3].str), NULL, NULL, NULL, NULL);}
#line 1342 "analizadorSintactico.tab.c"
    break;

  case 20: /* PARAMS: PARAM PARAMS_PRIMA  */
#line 95 "analizadorSintactico.y"
                         {(yyval.nodo) = crearNodo(NODO_PARAMS, NULL, (yyvsp[-1].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1348 "analizadorSintactico.tab.c"
    break;

  case 21: /* PARAMS_PRIMA: COMA PARAMS  */
#line 99 "analizadorSintactico.y"
                  {(yyval.nodo) = crearNodo(NODO_PARAMS, NULL, (yyvsp[0].nodo), NULL, NULL, NULL);}
#line 1354 "analizadorSintactico.tab.c"
    break;

  case 22: /* PARAMS_PRIMA: %empty  */
#line 100 "analizadorSintactico.y"
      {(yyval.nodo) = NULL;}
#line 1360 "analizadorSintactico.tab.c"
    break;

  case 23: /* PARAM: TYPE ID  */
#line 104 "analizadorSintactico.y"
              {(yyval.nodo) = crearNodo(NODO_PARAM, (yyvsp[0].str), (yyvsp[-1].nodo), NULL, NULL, NULL);}
#line 1366 "analizadorSintactico.tab.c"
    break;

  case 24: /* BLOQUE: LLAVE_IZQ VAR_DECL STATEMENTS LLAVE_DER  */
#line 108 "analizadorSintactico.y"
                                              {(yyval.nodo) = crearNodo(NODO_LLAVE, NULL, (yyvsp[-2].nodo), (yyvsp[-1].nodo), NULL, NULL);}
#line 1372 "analizadorSintactico.tab.c"
    break;

  case 25: /* VAR_DECL: VAR VAR_DECL  */
#line 112 "analizadorSintactico.y"
                   {(yyval.nodo) = crearNodo(NODO_VAR_DECL, NULL, (yyvsp[-1].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1378 "analizadorSintactico.tab.c"
    break;

  case 26: /* VAR_DECL: %empty  */
#line 113 "analizadorSintactico.y"
      {(yyval.nodo) = NULL;}
#line 1384 "analizadorSintactico.tab.c"
    break;

  case 27: /* STATEMENTS: STATEMENT STATEMENTS  */
#line 117 "analizadorSintactico.y"
                           {(yyval.nodo) = crearNodo(NODO_STATEMENT, NULL, (yyvsp[-1].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1390 "analizadorSintactico.tab.c"
    break;

  case 28: /* STATEMENTS: %empty  */
#line 118 "analizadorSintactico.y"
      {(yyval.nodo) = NULL;}
#line 1396 "analizadorSintactico.tab.c"
    break;

  case 29: /* TYPE: INT  */
#line 122 "analizadorSintactico.y"
          {(yyval.nodo) = crearNodo(NODO_TYPE, "int", NULL, NULL, NULL, NULL);}
#line 1402 "analizadorSintactico.tab.c"
    break;

  case 30: /* TYPE: FLOAT  */
#line 123 "analizadorSintactico.y"
            {(yyval.nodo) = crearNodo(NODO_TYPE, "float", NULL, NULL, NULL, NULL);}
#line 1408 "analizadorSintactico.tab.c"
    break;

  case 31: /* TYPE: BOOLEAN  */
#line 124 "analizadorSintactico.y"
              {(yyval.nodo) = crearNodo(NODO_TYPE, "boolean", NULL, NULL, NULL, NULL);}
#line 1414 "analizadorSintactico.tab.c"
    break;

  case 32: /* STATEMENT: ID OP_ASIG EXPR PUNTO_COMA  */
#line 128 "analizadorSintactico.y"
                                 {(yyval.nodo) = crearNodo(NODO_OP_ASIG, (yyvsp[-3].str), (yyvsp[-1].nodo), NULL, NULL, NULL);}
#line 1420 "analizadorSintactico.tab.c"
    break;

  case 33: /* STATEMENT: METHOD_CALL PUNTO_COMA  */
#line 129 "analizadorSintactico.y"
                             {(yyval.nodo) = crearNodo(NODO_METHOD_CALL, NULL, (yyvsp[-1].nodo), NULL, NULL, NULL);}
#line 1426 "analizadorSintactico.tab.c"
    break;

  case 34: /* STATEMENT: IF PAR_IZQ EXPR PAR_DER BLOQUE OPTIONAL_ELSE  */
#line 130 "analizadorSintactico.y"
                                                   {(yyval.nodo) = crearNodo(NODO_IF, NULL, (yyvsp[-3].nodo), (yyvsp[-1].nodo), (yyvsp[0].nodo), NULL);}
#line 1432 "analizadorSintactico.tab.c"
    break;

  case 35: /* STATEMENT: DO BLOQUE WHILE PAR_IZQ EXPR PAR_DER  */
#line 131 "analizadorSintactico.y"
                                           {(yyval.nodo) = crearNodo(NODO_DO, NULL, (yyvsp[-4].nodo), (yyvsp[-1].nodo), NULL, NULL);}
#line 1438 "analizadorSintactico.tab.c"
    break;

  case 36: /* STATEMENT: WHILE PAR_IZQ EXPR PAR_DER BLOQUE  */
#line 132 "analizadorSintactico.y"
                                        {(yyval.nodo) = crearNodo(NODO_WHILE, NULL, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1444 "analizadorSintactico.tab.c"
    break;

  case 37: /* STATEMENT: RETURN OPTIONAL_EXPR PUNTO_COMA  */
#line 133 "analizadorSintactico.y"
                                      {(yyval.nodo) = crearNodo(NODO_RETURN, NULL, (yyvsp[-1].nodo), NULL, NULL, NULL);}
#line 1450 "analizadorSintactico.tab.c"
    break;

  case 38: /* STATEMENT: PUNTO_COMA  */
#line 134 "analizadorSintactico.y"
                 {(yyval.nodo) = NULL;}
#line 1456 "analizadorSintactico.tab.c"
    break;

  case 39: /* STATEMENT: BLOQUE  */
#line 135 "analizadorSintactico.y"
             {(yyval.nodo) = crearNodo(NODO_BLOQUE, NULL, (yyvsp[0].nodo), NULL, NULL, NULL);}
#line 1462 "analizadorSintactico.tab.c"
    break;

  case 40: /* OPTIONAL_ELSE: ELSE BLOQUE  */
#line 139 "analizadorSintactico.y"
                  {(yyval.nodo) = crearNodo(NODO_ELSE, NULL, (yyvsp[0].nodo), NULL, NULL, NULL);}
#line 1468 "analizadorSintactico.tab.c"
    break;

  case 41: /* OPTIONAL_ELSE: %empty  */
#line 140 "analizadorSintactico.y"
      {(yyval.nodo) = NULL;}
#line 1474 "analizadorSintactico.tab.c"
    break;

  case 42: /* OPTIONAL_EXPR: EXPR  */
#line 144 "analizadorSintactico.y"
           {(yyval.nodo) = crearNodo(NODO_EXPR, NULL, (yyvsp[0].nodo), NULL, NULL, NULL);}
#line 1480 "analizadorSintactico.tab.c"
    break;

  case 43: /* OPTIONAL_EXPR: %empty  */
#line 145 "analizadorSintactico.y"
      {(yyval.nodo) = NULL;}
#line 1486 "analizadorSintactico.tab.c"
    break;

  case 44: /* METHOD_CALL: ID PAR_IZQ ARGS PAR_DER  */
#line 149 "analizadorSintactico.y"
                              {(yyval.nodo) = crearNodo(NODO_ARGUMENTS_CALL, (yyvsp[-3].str), (yyvsp[-1].nodo), NULL, NULL, NULL);}
#line 1492 "analizadorSintactico.tab.c"
    break;

  case 45: /* METHOD_CALL: ID PAR_IZQ PAR_DER  */
#line 150 "analizadorSintactico.y"
                         {(yyval.nodo) = crearNodo(NODO_NO_ARGUMENTS_CALL, (yyvsp[-2].str), NULL, NULL, NULL, NULL);}
#line 1498 "analizadorSintactico.tab.c"
    break;

  case 46: /* ARGS: ARG ARGS_PRIMA  */
#line 154 "analizadorSintactico.y"
                     {(yyval.nodo) = crearNodo(NODO_ARG, NULL, (yyvsp[-1].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1504 "analizadorSintactico.tab.c"
    break;

  case 47: /* ARGS_PRIMA: COMA ARGS  */
#line 158 "analizadorSintactico.y"
                {(yyval.nodo) = crearNodo(NODO_ARGS, NULL, (yyvsp[0].nodo), NULL, NULL, NULL);}
#line 1510 "analizadorSintactico.tab.c"
    break;

  case 48: /* ARGS_PRIMA: %empty  */
#line 159 "analizadorSintactico.y"
      {(yyval.nodo) = NULL;}
#line 1516 "analizadorSintactico.tab.c"
    break;

  case 49: /* ARG: EXPR  */
#line 163 "analizadorSintactico.y"
           {(yyval.nodo) = crearNodo(NODO_EXPR, NULL, (yyvsp[0].nodo), NULL, NULL, NULL);}
#line 1522 "analizadorSintactico.tab.c"
    break;

  case 50: /* EXPR: ID  */
#line 167 "analizadorSintactico.y"
         {(yyval.nodo) = crearNodo(NODO_ID, (yyvsp[0].str), NULL, NULL, NULL, NULL);}
#line 1528 "analizadorSintactico.tab.c"
    break;

  case 51: /* EXPR: METHOD_CALL  */
#line 168 "analizadorSintactico.y"
                  {(yyval.nodo) = crearNodo(NODO_METHOD_CALL, NULL, (yyvsp[0].nodo), NULL, NULL, NULL);}
#line 1534 "analizadorSintactico.tab.c"
    break;

  case 52: /* EXPR: LITERAL  */
#line 169 "analizadorSintactico.y"
              {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1540 "analizadorSintactico.tab.c"
    break;

  case 53: /* EXPR: EXPR OP_SUMA EXPR  */
#line 170 "analizadorSintactico.y"
                        {(yyval.nodo) = crearNodo(NODO_SUMA, NULL, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1546 "analizadorSintactico.tab.c"
    break;

  case 54: /* EXPR: EXPR OP_RESTA EXPR  */
#line 171 "analizadorSintactico.y"
                         {(yyval.nodo) = crearNodo(NODO_RESTA, NULL, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1552 "analizadorSintactico.tab.c"
    break;

  case 55: /* EXPR: EXPR OP_PROD EXPR  */
#line 172 "analizadorSintactico.y"
                        {(yyval.nodo) = crearNodo(NODO_PROD, NULL, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1558 "analizadorSintactico.tab.c"
    break;

  case 56: /* EXPR: EXPR OP_DIV EXPR  */
#line 173 "analizadorSintactico.y"
                       {(yyval.nodo) = crearNodo(NODO_DIV, NULL, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1564 "analizadorSintactico.tab.c"
    break;

  case 57: /* EXPR: EXPR OP_DIVENT EXPR  */
#line 174 "analizadorSintactico.y"
                          {(yyval.nodo) = crearNodo(NODO_DIVENT, NULL, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1570 "analizadorSintactico.tab.c"
    break;

  case 58: /* EXPR: EXPR OP_MENOR EXPR  */
#line 175 "analizadorSintactico.y"
                         {(yyval.nodo) = crearNodo(NODO_MENOR, NULL, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1576 "analizadorSintactico.tab.c"
    break;

  case 59: /* EXPR: EXPR OP_MAYOREQ EXPR  */
#line 176 "analizadorSintactico.y"
                           {
        nodoAST *menor = crearNodo(NODO_MENOR, NULL, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL, NULL);
        (yyval.nodo) = crearNodo(NODO_NEG, NULL, menor, NULL, NULL, NULL);}
#line 1584 "analizadorSintactico.tab.c"
    break;

  case 60: /* EXPR: EXPR OP_MAYOR EXPR  */
#line 179 "analizadorSintactico.y"
                         {(yyval.nodo) = crearNodo(NODO_MAYOR, NULL, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1590 "analizadorSintactico.tab.c"
    break;

  case 61: /* EXPR: EXPR OP_EQ EXPR  */
#line 180 "analizadorSintactico.y"
                      {(yyval.nodo) = crearNodo(NODO_EQ, NULL, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1596 "analizadorSintactico.tab.c"
    break;

  case 62: /* EXPR: EXPR OP_AND EXPR  */
#line 181 "analizadorSintactico.y"
                       {(yyval.nodo) = crearNodo(NODO_AND, NULL, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1602 "analizadorSintactico.tab.c"
    break;

  case 63: /* EXPR: EXPR OP_OR EXPR  */
#line 182 "analizadorSintactico.y"
                      {(yyval.nodo) = crearNodo(NODO_OR, NULL, (yyvsp[-2].nodo), (yyvsp[0].nodo), NULL, NULL);}
#line 1608 "analizadorSintactico.tab.c"
    break;

  case 64: /* EXPR: OP_RESTA EXPR  */
#line 183 "analizadorSintactico.y"
                                      { (yyval.nodo) = crearNodo(NODO_SIGNO_MENOS, NULL, (yyvsp[0].nodo), NULL, NULL, NULL);}
#line 1614 "analizadorSintactico.tab.c"
    break;

  case 65: /* EXPR: OP_NEG EXPR  */
#line 184 "analizadorSintactico.y"
                  {(yyval.nodo) = crearNodo(NODO_NEG, NULL, (yyvsp[0].nodo), NULL, NULL, NULL);}
#line 1620 "analizadorSintactico.tab.c"
    break;

  case 66: /* EXPR: PAR_IZQ EXPR PAR_DER  */
#line 185 "analizadorSintactico.y"
                           {(yyval.nodo) = (yyvsp[-1].nodo);}
#line 1626 "analizadorSintactico.tab.c"
    break;

  case 67: /* LITERAL: CTE_ENTERA  */
#line 190 "analizadorSintactico.y"
                 {(yyval.nodo) = crearNodo(NODO_LITERAL, (yyvsp[0].str), NULL, NULL, NULL, NULL);}
#line 1632 "analizadorSintactico.tab.c"
    break;

  case 68: /* LITERAL: CTE_LOGICA  */
#line 191 "analizadorSintactico.y"
                 {(yyval.nodo) = crearNodo(NODO_LITERAL, (yyvsp[0].str), NULL, NULL, NULL, NULL);}
#line 1638 "analizadorSintactico.tab.c"
    break;

  case 69: /* LITERAL: CTE_FLOAT  */
#line 192 "analizadorSintactico.y"
                {(yyval.nodo) = crearNodo(NODO_LITERAL, (yyvsp[0].str), NULL, NULL, NULL, NULL);}
#line 1644 "analizadorSintactico.tab.c"
    break;


#line 1648 "analizadorSintactico.tab.c"

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
      yyerror (YY_("syntax error"));
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 195 "analizadorSintactico.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error sintáctico en la línea %d: %s\n", yylineno, s);
}

/* El programa principal (linea de comandos y orden de las etapas) esta en main.c */
