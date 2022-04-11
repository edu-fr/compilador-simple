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


#line 51 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"


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

#line 47 "parser.yy"
namespace Simples {
#line 148 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"


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
  case 2:
#line 137 "parser.yy"
                   { (yylhs.value.programa_val) = new ProgramaAst(nullptr, (yystack_[0].value.acao_val)); }
#line 644 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 4:
#line 147 "parser.yy"
                          { (yylhs.value.acao_val) = (yystack_[0].value.acao_val); }
#line 650 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 45:
#line 261 "parser.yy"
          { (yylhs.value.acao_val) = new AcaoAst((yystack_[0].value.acao_val));  }
#line 656 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 46:
#line 262 "parser.yy"
                             { (yylhs.value.acao_val) = new AcaoAst((yystack_[0].value.acao_val), (yystack_[2].value.acao_val)); }
#line 662 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 47:
#line 266 "parser.yy"
                        { (yylhs.value.acao_val) = new AtribuicaoAst((yystack_[2].value.local_val), (yystack_[0].value.exp_val)); }
#line 668 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 56:
#line 278 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 674 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 58:
#line 283 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[2].value.exp_val); }
#line 680 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 59:
#line 284 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[2].value.exp_val); }
#line 686 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 60:
#line 285 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 692 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 61:
#line 289 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[2].value.exp_val); }
#line 698 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 62:
#line 290 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[2].value.exp_val); }
#line 704 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 63:
#line 291 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[2].value.exp_val); }
#line 710 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 64:
#line 292 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[2].value.exp_val); }
#line 716 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 65:
#line 293 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[2].value.exp_val); }
#line 722 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 66:
#line 294 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[2].value.exp_val); }
#line 728 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 67:
#line 295 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 734 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 68:
#line 299 "parser.yy"
                                  { (yylhs.value.exp_val) = new ExprAritAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 740 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 69:
#line 300 "parser.yy"
                                  { (yylhs.value.exp_val) = new ExprAritAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 746 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 70:
#line 301 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 752 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 71:
#line 305 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[2].value.exp_val); }
#line 758 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 72:
#line 306 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[2].value.exp_val); }
#line 764 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 73:
#line 307 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 770 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 75:
#line 312 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 776 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 83:
#line 329 "parser.yy"
          { (yylhs.value.exp_val) = new InteiroAst((yystack_[0].value.integerVal)); }
#line 782 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 84:
#line 330 "parser.yy"
       { (yylhs.value.exp_val) = new RealAst((yystack_[0].value.doubleVal)); }
#line 788 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 85:
#line 331 "parser.yy"
         { (yylhs.value.exp_val) = new CadeiaAst(*(yystack_[0].value.stringVal)); }
#line 794 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 86:
#line 335 "parser.yy"
                { (yylhs.value.local_val) = new LocalAst(*(yystack_[0].value.stringVal)); }
#line 800 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 87:
#line 336 "parser.yy"
  { (yylhs.value.local_val) = (yystack_[2].value.local_val); }
#line 806 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 88:
#line 337 "parser.yy"
  { (yylhs.value.local_val) = (yystack_[3].value.local_val); }
#line 812 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;


#line 816 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"

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


  const signed char Parser::yypact_ninf_ = -75;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      -1,    -9,    48,    31,    30,    59,   -75,    63,   -75,    74,
      90,    12,    59,   -75,    14,   106,    76,   -75,     9,   -75,
      75,   -75,   -75,   109,     6,     6,     6,    78,   -75,   -75,
      25,    80,   106,   -75,   112,   -75,    94,   115,   -75,    32,
     101,   -75,   -75,   -75,   -75,     6,   117,   110,   -36,    45,
      44,    50,   -75,   -75,   -75,   -27,   108,   -75,    14,    32,
     118,     6,   121,   -75,    89,   112,   -75,   -75,    36,    92,
      10,   -75,   -75,    47,     6,    91,    77,    20,   -75,    14,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    14,   -75,    38,   -75,   -75,    81,    60,   -75,
     105,   116,   130,   115,   -75,    32,   -75,   119,   -75,     6,
     117,   -75,    -3,    45,    45,    44,    44,    44,    44,    44,
      44,    50,    50,   -75,   -75,    24,   -75,     6,   -75,   -75,
      98,   104,   -75,   136,   -75,   137,   -75,   -75,   -75,     6,
     -75,   -75,   -75,   -75,    14,   -75,   -75,   -15,    60,   111,
     -75,   134,    -4,   139,   126,   -75,   145,    14,   -75,    97,
     120,   -75,   146,   -75,    -2,   126,   106,   122,   -75,   -75,
     -75,   106,    14,   -75,    78
  };

  const signed char
  Parser::yydefact_[] =
  {
       5,     0,     0,     0,     9,     0,     1,     0,     2,     0,
      27,     0,     6,     7,     0,     0,     0,     3,     0,     8,
      86,    53,    54,     0,     0,     0,     0,     4,    45,    48,
       0,     0,    10,    11,     0,    19,     0,     0,    18,    80,
       0,    83,    84,    85,    78,     0,     0,     0,    56,    60,
      67,    70,    73,    77,    75,    76,     0,    55,     0,    80,
       0,     0,     0,    12,     0,    28,    29,    25,     0,     0,
       0,    22,    81,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,    87,    47,     0,    33,    30,
       0,     0,     0,     0,    20,     0,    79,     0,    74,     0,
       0,    57,     0,    58,    59,    66,    65,    63,    61,    64,
      62,    68,    69,    72,    71,     0,    88,     0,    38,    39,
       0,    34,    35,     0,    26,     0,    24,    23,    82,     0,
      17,    16,    52,    49,     0,    13,    14,     0,     0,     0,
      21,     0,     0,     0,    41,    36,     0,     0,    50,     0,
       0,    31,     0,    37,     0,    41,     0,     0,    51,    32,
      43,    42,     0,    44,    40
  };

  const short
  Parser::yypgoto_[] =
  {
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -30,   -75,
     -75,    40,   140,   -75,   -75,    52,   -75,   -75,   -75,    88,
     -75,   -75,    13,   -75,    -8,   -75,   -75,   -74,   102,   -22,
     -75,    15,    17,    18,   -33,   -14,   103,   -75,   -13
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,     8,     4,    12,    10,    32,    33,   145,
      77,    78,    13,    38,    70,    71,    68,    17,    65,    66,
     130,   131,   132,   133,   161,   162,   171,    27,    28,    47,
      48,    49,    50,    51,    52,    53,    73,    54,    55
  };

  const unsigned char
  Parser::yytable_[] =
  {
      29,    30,    63,    56,    57,   112,    72,   168,   142,    20,
     158,    59,    35,    80,    81,    60,     1,    20,   125,   153,
      21,    22,    23,    75,    24,     5,    72,    25,    41,    42,
      43,    58,    58,    58,    44,    20,     7,   154,   143,    96,
     144,    26,    45,   103,    29,    30,    46,    36,     6,    37,
       9,   104,   107,   110,    41,    42,    43,   123,   124,    58,
      44,   111,    11,    59,    18,    29,    30,    60,    45,   100,
     152,   105,   138,    88,    89,   101,    61,   126,    29,    30,
     105,    90,    91,   164,   106,   128,   129,   140,    82,    83,
      84,    85,    86,    87,    16,   113,   114,    14,   174,   115,
     116,   117,   118,   119,   120,   146,   121,   122,    15,    31,
      34,    39,    40,    58,    62,    64,    67,   151,    69,    74,
      76,    95,    79,    92,    97,    98,   102,   134,   108,   109,
      29,    30,   127,   136,   135,   147,   170,   148,   139,   149,
     150,   173,   159,    29,    30,   156,   157,   160,   163,   165,
     141,   167,    19,    99,   166,   137,   172,   169,    29,    30,
      93,   155,    94
  };

  const unsigned char
  Parser::yycheck_[] =
  {
      14,    14,    32,    25,    26,    79,    39,     9,    11,     3,
      14,    38,     3,    49,    50,    42,    17,     3,    92,    34,
       6,     7,     8,    45,    10,    34,    59,    13,    22,    23,
      24,    35,    35,    35,    28,     3,     5,    52,    14,    61,
      16,    27,    36,    33,    58,    58,    40,    38,     0,    40,
      20,    41,    74,    33,    22,    23,    24,    90,    91,    35,
      28,    41,     3,    38,    52,    79,    79,    42,    36,    33,
     144,    33,   105,    29,    30,    39,    51,    39,    92,    92,
      33,    31,    32,   157,    37,    25,    26,   109,    43,    44,
      45,    46,    47,    48,     4,    80,    81,    34,   172,    82,
      83,    84,    85,    86,    87,   127,    88,    89,    34,     3,
      34,    36,     3,    35,    34,     3,    22,   139,     3,    18,
       3,     3,    12,    15,     3,    36,    34,    22,    37,    52,
     144,   144,    51,     3,    18,    37,   166,    33,    19,     3,
       3,   171,     3,   157,   157,    34,    12,    21,     3,    52,
     110,     5,    12,    65,    34,   103,    34,   165,   172,   172,
      58,   148,    59
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    17,    54,    55,    57,    34,     0,     5,    56,    20,
      59,     3,    58,    65,    34,    34,     4,    70,    52,    65,
       3,     6,     7,     8,    10,    13,    27,    80,    81,    88,
      91,     3,    60,    61,    34,     3,    38,    40,    66,    36,
       3,    22,    23,    24,    28,    36,    40,    82,    83,    84,
      85,    86,    87,    88,    90,    91,    82,    82,    35,    38,
      42,    51,    34,    61,     3,    71,    72,    22,    69,     3,
      67,    68,    87,    89,    18,    82,     3,    63,    64,    12,
      49,    50,    43,    44,    45,    46,    47,    48,    29,    30,
      31,    32,    15,    81,    89,     3,    82,     3,    36,    72,
      33,    39,    34,    33,    41,    33,    37,    82,    37,    52,
      33,    41,    80,    84,    84,    85,    85,    85,    85,    85,
      85,    86,    86,    87,    87,    80,    39,    51,    25,    26,
      73,    74,    75,    76,    22,    18,     3,    68,    87,    19,
      82,    64,    11,    14,    16,    62,    82,    37,    33,     3,
       3,    82,    80,    34,    52,    75,    34,    12,    14,     3,
      21,    77,    78,     3,    80,    52,    34,     5,     9,    77,
      61,    79,    34,    61,    80
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    53,    54,    55,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    62,    63,    63,    64,    65,    66,
      66,    66,    67,    67,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    74,    74,    75,    76,    76,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    82,    82,    83,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    85,    85,
      85,    86,    86,    86,    87,    87,    87,    87,    87,    88,
      89,    89,    89,    90,    90,    90,    91,    91,    91
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     3,     3,     0,     3,     1,     2,     0,
       3,     1,     2,     5,     1,     1,     3,     3,     3,     1,
       3,     5,     1,     3,     3,     1,     3,     0,     3,     1,
       2,     6,     8,     0,     1,     1,     3,     4,     1,     1,
       4,     0,     3,     1,     2,     1,     3,     3,     1,     5,
       7,     9,     5,     1,     1,     2,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     1,     1,     1,     4,
       0,     1,     3,     1,     1,     1,     1,     3,     4
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
  "\"cadeia\"", "\"valor\"", "\"ref\"", "\"retorne\"", "\"nulo\"", "\"+\"",
  "\"-\"", "\"/\"", "\"*\"", "\",\"", "\":\"", "\";\"", "\"(\"", "\")\"",
  "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\".\"", "\"==\"", "\"!=\"", "\"<\"",
  "\"<=\"", "\">\"", "\">=\"", "\"&\"", "\"|\"", "\":=\"", "\"=\"",
  "$accept", "programa", "declaracoes", "acao", "lista_declaracao_de_tipo",
  "lista_declaracao_tipo", "lista_declaracao_de_variavel_global",
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
       0,   137,   137,   141,   147,   151,   152,   156,   157,   161,
     162,   166,   167,   171,   175,   179,   180,   184,   188,   192,
     193,   194,   198,   199,   203,   207,   208,   212,   213,   217,
     218,   222,   223,   227,   228,   232,   233,   237,   241,   242,
     246,   251,   252,   256,   257,   261,   262,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   278,   279,   283,   284,
     285,   289,   290,   291,   292,   293,   294,   295,   299,   300,
     301,   305,   306,   307,   311,   312,   313,   314,   315,   319,
     323,   324,   325,   329,   330,   331,   335,   336,   337
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
      45,    46,    47,    48,    49,    50,    51,    52
    };
    const int user_token_number_max_ = 307;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 47 "parser.yy"
} // Simples
#line 1377 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"

#line 340 "parser.yy"


namespace Simples {
   void Parser::error(const location&, const string& m) {
        cerr << *driver.location_ << ": " << m << endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
