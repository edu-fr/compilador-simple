// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 5 "parser.yy"


/*** C++ Declarations ***/
#include "parser.hh"
#include "scanner.hh"
#include "AST_classes.hh"

#define yylex driver.scanner_->yylex


#line 51 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"


#include "parser.hh"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 46 "parser.yy"
namespace Simples {
#line 148 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
    , location (std::move (that.location))
  {}
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location, driver));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 12:
#line 156 "parser.yy"
                                                      { cout << "Global declarada! " << endl; }
#line 644 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 15:
#line 165 "parser.yy"
                                                                  { cout << "Declaracao de variavel! " << endl; }
#line 650 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 21:
#line 184 "parser.yy"
                { cout << "Declaracao de tipo simples" << endl; }
#line 656 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 22:
#line 185 "parser.yy"
                                     { cout << "Declaracao de tipo: Tipo Campo " << endl; }
#line 662 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 23:
#line 186 "parser.yy"
                                                                { cout << "Declaracao de tipo: Tipo constantes " << endl;  }
#line 668 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 33:
#line 214 "parser.yy"
                                                                          { cout << "Declaracao de procedimento! " << endl; }
#line 674 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 34:
#line 215 "parser.yy"
                                                                                                   { cout << "Declaracao de funcao! " << endl; }
#line 680 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 39:
#line 229 "parser.yy"
                                                       { cout << "Argumento! " << endl; }
#line 686 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 44:
#line 244 "parser.yy"
                                                    { cout << "Local foi declarada! " << endl; }
#line 692 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 49:
#line 258 "parser.yy"
                        { cout << "atribuição simples" << endl; }
#line 698 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 51:
#line 260 "parser.yy"
                                        { cout << "SE simples" << endl; }
#line 704 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 52:
#line 261 "parser.yy"
                                                             { cout << "SE com FALSO" << endl; }
#line 710 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 53:
#line 262 "parser.yy"
                                                                   { cout << "PARA" << endl; }
#line 716 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 54:
#line 263 "parser.yy"
                                              { cout << "ENQUANTO" << endl; }
#line 722 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 55:
#line 264 "parser.yy"
        { cout << "PARE" << endl; }
#line 728 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 56:
#line 265 "parser.yy"
           { cout << "CONTINUE" << endl; }
#line 734 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 57:
#line 266 "parser.yy"
                { cout << "RETORNE" << endl; }
#line 740 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 60:
#line 275 "parser.yy"
                                            { cout << " AND " << endl; }
#line 746 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 61:
#line 276 "parser.yy"
                                           { cout << " OR " << endl; }
#line 752 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 63:
#line 281 "parser.yy"
                                                       { cout << "Maior igual" << endl; }
#line 758 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 64:
#line 282 "parser.yy"
                                                       { cout << "Menor igual " << endl; }
#line 764 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 65:
#line 283 "parser.yy"
                                                  { cout << " Menor " << endl; }
#line 770 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 66:
#line 284 "parser.yy"
                                                  { cout << " Maior " << endl; }
#line 776 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 67:
#line 285 "parser.yy"
                                                      { cout << " Diferente " << endl; }
#line 782 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 68:
#line 286 "parser.yy"
                                                        { cout << " Equivalente " << endl; }
#line 788 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 70:
#line 290 "parser.yy"
                                  { cout << "SOMA " << endl; }
#line 794 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 71:
#line 291 "parser.yy"
                                   { cout << " Sutracao " << endl; }
#line 800 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 73:
#line 296 "parser.yy"
                        { cout << " Multiplicacao " << endl; }
#line 806 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 74:
#line 297 "parser.yy"
                    { cout << " Divisao " << endl; }
#line 812 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 76:
#line 302 "parser.yy"
                                      { cout << "Expressao com parenteses " << endl; }
#line 818 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 85:
#line 320 "parser.yy"
           { cout << "int: " << (yystack_[0].value.integerVal) << endl; }
#line 824 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;


#line 828 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -65;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      56,   -16,    49,   -65,   -65,   -65,    42,   -65,   -65,    11,
     -65,    64,    81,   -65,    51,   104,    69,   -65,   -65,   108,
       5,     5,     5,    73,   -65,   -65,   -26,    57,    81,   -65,
     112,    78,   -65,    13,   103,   -65,     5,   119,   113,    21,
      44,    10,    45,   -65,   -65,   -65,    17,   109,   -65,    64,
      13,   123,     5,     8,   -65,    88,   112,   -65,   125,   -65,
      24,     5,    87,    74,   -24,   -65,    64,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    64,
     -65,   -25,   -65,   -65,   -65,   110,   127,   -65,   130,   -65,
      93,   125,   -65,    13,   -65,   116,   -65,     5,   119,   -65,
      -6,    44,    44,    10,    10,    10,    10,    10,    10,    45,
      45,   -65,   -65,    43,   -65,   -65,    14,    97,   -20,   -65,
      82,    61,   -65,   -65,     5,   -65,   -65,   -65,   -65,    64,
     115,   121,   137,   127,   -65,     5,   -65,   -65,    99,   106,
     -65,   142,   134,    -8,   -65,   144,   -65,   -65,   -65,   -65,
     -32,    61,   111,    64,   -65,   -65,   145,   128,   -65,   148,
       3,    95,   114,   -65,   149,   -65,   -65,   128,   112,   117,
     -65,   -65,   112,    64,   -65,    73
  };

  const signed char
  Parser::yydefact_[] =
  {
       7,     0,     0,    85,    86,    87,     0,     2,     3,    11,
       4,     0,     0,     1,     0,    29,    88,    55,    56,     0,
       0,     0,     0,     6,    47,    50,     0,     0,     8,     9,
       0,     0,     5,    82,     0,    80,     0,     0,     0,    58,
      62,    69,    72,    75,    79,    77,    78,     0,    57,     0,
      82,     0,     0,     0,    10,     0,    12,    13,     0,    83,
       0,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,    89,    49,    21,     0,     0,    20,     0,    14,
       0,    30,    31,     0,    81,     0,    76,     0,     0,    59,
       0,    60,    61,    68,    67,    65,    63,    66,    64,    70,
      71,    74,    73,     0,    90,    27,     0,     0,     0,    24,
       0,    35,    32,    84,     0,    19,    18,    54,    51,     0,
       0,     0,     0,     0,    22,     0,    40,    41,     0,    36,
      37,     0,     0,     0,    28,     0,    26,    25,    15,    16,
       0,     0,     0,     0,    52,    23,     0,    43,    38,     0,
       0,     0,     0,    33,     0,    39,    53,    43,     0,     0,
      34,    45,    44,     0,    46,    42
  };

  const short
  Parser::yypgoto_[] =
  {
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -52,   -65,
     -65,    59,   131,   -65,   -65,    22,   -65,   -65,   -65,    67,
     -65,   -65,     9,   -65,    -3,   -65,   -65,   -64,   118,   -12,
     -65,    37,    29,    31,   -30,   -11,   120,   161,   -10
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     6,     7,     8,     9,    28,    15,    56,    57,   148,
      64,    65,    29,    87,   118,   119,   116,    32,    91,    92,
     138,   139,   140,   141,   163,   164,   172,    23,    24,    38,
      39,    40,    41,    42,    43,    44,    60,    45,    46
  };

  const unsigned char
  Parser::yytable_[] =
  {
      25,    26,   100,    59,    89,   127,   154,   156,    16,    47,
      48,    84,   166,    93,    98,   113,    16,    50,   133,   114,
      59,    51,    99,    11,    62,   157,   134,     3,     4,     5,
      52,    14,    49,    35,    49,     3,     4,     5,    25,    26,
      83,    35,    13,    49,    75,    76,    36,   111,   112,    95,
      37,    85,   130,    86,    36,    25,    26,   128,   131,   129,
      50,     1,    93,   123,    51,   143,    94,    16,    25,    26,
      17,    18,    19,     2,    20,    67,    68,    21,     3,     4,
       5,    77,    78,    49,    27,   125,   136,   137,    12,   160,
      30,    22,    69,    70,    71,    72,    73,    74,   103,   104,
     105,   106,   107,   108,   101,   102,   109,   110,    31,   175,
      33,    34,   142,    49,    53,    55,   171,    58,    25,    26,
     174,    61,    63,   149,    79,    66,    82,    88,    90,    96,
     117,    97,   115,   120,   121,   124,   132,   144,   135,   145,
     146,   150,    25,    26,   151,   152,   153,   155,   161,   162,
     159,   165,   167,   168,   169,   147,   173,   126,   122,    54,
     158,    10,    25,    26,   170,     0,     0,    80,     0,     0,
      81
  };

  const short
  Parser::yycheck_[] =
  {
      11,    11,    66,    33,    56,    11,    14,    39,     3,    21,
      22,     3,     9,    38,    38,    79,     3,    43,    38,    44,
      50,    47,    46,    39,    36,    57,    46,    22,    23,    24,
      56,    20,    40,    28,    40,    22,    23,    24,    49,    49,
      52,    28,     0,    40,    34,    35,    41,    77,    78,    61,
      45,    43,    38,    45,    41,    66,    66,    14,    44,    16,
      43,     5,    38,    93,    47,   129,    42,     3,    79,    79,
       6,     7,     8,    17,    10,    54,    55,    13,    22,    23,
      24,    36,    37,    40,     3,    97,    25,    26,    39,   153,
      39,    27,    48,    49,    50,    51,    52,    53,    69,    70,
      71,    72,    73,    74,    67,    68,    75,    76,     4,   173,
      41,     3,   124,    40,    57,     3,   168,    39,   129,   129,
     172,    18,     3,   135,    15,    12,     3,    39,     3,    42,
       3,    57,    22,     3,    41,    19,    39,    22,    56,    18,
       3,    42,   153,   153,    38,     3,    12,     3,     3,    21,
      39,     3,    57,    39,     5,   133,    39,    98,    91,    28,
     151,     0,   173,   173,   167,    -1,    -1,    49,    -1,    -1,
      50
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     5,    17,    22,    23,    24,    59,    60,    61,    62,
      95,    39,    39,     0,    20,    64,     3,     6,     7,     8,
      10,    13,    27,    85,    86,    93,    96,     3,    63,    70,
      39,     4,    75,    41,     3,    28,    41,    45,    87,    88,
      89,    90,    91,    92,    93,    95,    96,    87,    87,    40,
      43,    47,    56,    57,    70,     3,    65,    66,    39,    92,
      94,    18,    87,     3,    68,    69,    12,    54,    55,    48,
      49,    50,    51,    52,    53,    34,    35,    36,    37,    15,
      86,    94,     3,    87,     3,    43,    45,    71,    39,    66,
       3,    76,    77,    38,    42,    87,    42,    57,    38,    46,
      85,    89,    89,    90,    90,    90,    90,    90,    90,    91,
      91,    92,    92,    85,    44,    22,    74,     3,    72,    73,
       3,    41,    77,    92,    19,    87,    69,    11,    14,    16,
      38,    44,    39,    38,    46,    56,    25,    26,    78,    79,
      80,    81,    87,    85,    22,    18,     3,    73,    67,    87,
      42,    38,     3,    12,    14,     3,    39,    57,    80,    39,
      85,     3,    21,    82,    83,     3,     9,    57,    39,     5,
      82,    66,    84,    39,    66,    85
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    58,    59,    59,    59,    60,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    67,    68,    68,    69,
      70,    71,    71,    71,    72,    72,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      81,    81,    82,    83,    83,    84,    84,    85,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    87,    87,
      88,    88,    88,    89,    89,    89,    89,    89,    89,    89,
      90,    90,    90,    91,    91,    91,    92,    92,    92,    92,
      92,    93,    94,    94,    94,    95,    95,    95,    96,    96,
      96
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     3,     3,     0,     3,     1,
       2,     0,     3,     1,     2,     5,     1,     1,     3,     3,
       3,     1,     3,     5,     1,     3,     3,     1,     3,     0,
       3,     1,     2,     6,     8,     0,     1,     1,     3,     4,
       1,     1,     4,     0,     3,     1,     2,     1,     3,     3,
       1,     5,     7,     9,     5,     1,     1,     2,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     1,     1,     1,
       1,     4,     0,     1,     3,     1,     1,     1,     1,     3,
       4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"identificador\"",
  "\"função\"", "\"ação\"", "\"pare\"", "\"continue\"", "\"para\"",
  "\"fpara\"", "\"enquanto\"", "\"fenquanto\"", "\"faça\"", "\"se\"",
  "\"fse\"", "\"verdadeiro\"", "\"falso\"", "\"tipo\"", "\"de\"",
  "\"limite\"", "\"global\"", "\"local\"", "\"inteiro\"", "\"real\"",
  "\"cadeia\"", "\"valor\"", "\"ref\"", "\"retorne\"", "\"nulo\"",
  "\"início\"", "\"fim\"", "\"end of line\"", "\"comentário\"",
  "\"simbolo\"", "\"+\"", "\"-\"", "\"/\"", "\"*\"", "\",\"", "\":\"",
  "\";\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\".\"",
  "\"==\"", "\"!=\"", "\"<\"", "\"<=\"", "\">\"", "\">=\"", "\"&\"",
  "\"|\"", "\":=\"", "\"=\"", "$accept", "programa", "declaracoes", "acao",
  "lista_declaracao_de_tipo", "lista_declaracao_tipo",
  "lista_declaracao_de_variavel_global",
  "lista_declaracao_variavel_global", "declaracao_variavel",
  "inicializacao", "criacao_de_registro", "atribuicao_registro",
  "declaracao_tipo", "descritor_tipo", "tipo_campos", "tipo_campo",
  "tipo_constantes", "lista_declaracao_de_funcao",
  "lista_declaracao_funcao", "declaracao_funcao", "lista_de_args",
  "lista_args", "args", "modificador", "corpo",
  "lista_declaracao_de_variavel_local", "lista_declaracao_variavel_local",
  "lista_comandos", "comando", "expr", "expressao_logica",
  "expressao_relacional", "expressao_aritmetica", "termo", "fator",
  "chamada_de_funcao", "lista_args_chamada", "literal", "local", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   129,   129,   130,   131,   135,   141,   145,   146,   150,
     151,   155,   156,   160,   161,   165,   169,   173,   174,   177,
     180,   184,   185,   186,   190,   191,   195,   199,   200,   204,
     205,   209,   210,   214,   215,   219,   220,   224,   225,   229,
     233,   234,   238,   243,   244,   248,   249,   253,   254,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   270,   271,
     275,   276,   277,   281,   282,   283,   284,   285,   286,   287,
     290,   291,   292,   296,   297,   298,   302,   303,   304,   305,
     306,   310,   314,   315,   316,   320,   321,   322,   326,   327,
     328
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
    };
    const int user_token_number_max_ = 312;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 46 "parser.yy"
} // Simples
#line 1397 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"

#line 331 "parser.yy"


namespace Simples {
   void Parser::error(const location&, const string& m) {
        cerr << *driver.location_ << ": " << m << endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
