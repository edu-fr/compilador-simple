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


#line 51 "/home/kari/git/compilador-simples/build/parser.cc"


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

#line 45 "parser.yy"
namespace Simples {
#line 148 "/home/kari/git/compilador-simples/build/parser.cc"


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
#line 149 "parser.yy"
                   { ast_root = new ProgramaAst((yystack_[1].value.declaracao_val), (yystack_[0].value.acao_val)); }
#line 644 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 3:
#line 155 "parser.yy"
                             { (yylhs.value.declaracao_val) = new DeclaracoesAst((yystack_[2].value.declaracao_tipos_val), (yystack_[1].value.declaracao_variavel_val), (yystack_[0].value.declaracao_funcoes_val)); }
#line 650 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 4:
#line 159 "parser.yy"
                          { (yylhs.value.acao_val) = (yystack_[0].value.acao_val); }
#line 656 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 5:
#line 163 "parser.yy"
                     { (yylhs.value.declaracao_tipos_val) = nullptr; }
#line 662 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 6:
#line 164 "parser.yy"
                                   { (yylhs.value.declaracao_tipos_val) = (yystack_[0].value.declaracao_tipos_val); }
#line 668 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 7:
#line 168 "parser.yy"
                  { (yylhs.value.declaracao_tipos_val) = new DeclaracaoTiposAst((yystack_[0].value.declaracao_tipos_val)); }
#line 674 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 8:
#line 169 "parser.yy"
                                        { (yylhs.value.declaracao_tipos_val) = new DeclaracaoTiposAst((yystack_[1].value.declaracao_tipos_val), (yystack_[0].value.declaracao_tipos_val)); }
#line 680 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 9:
#line 173 "parser.yy"
                     { (yylhs.value.declaracao_variavel_val) = nullptr; }
#line 686 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 10:
#line 174 "parser.yy"
                                       { (yylhs.value.declaracao_variavel_val) = (yystack_[0].value.declaracao_variavel_val); }
#line 692 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 11:
#line 178 "parser.yy"
                      { (yylhs.value.declaracao_variavel_val) = new ListaDecVarAst((yystack_[0].value.declaracao_variavel_val)); }
#line 698 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 12:
#line 179 "parser.yy"
                                                { (yylhs.value.declaracao_variavel_val) = new ListaDecVarAst((yystack_[1].value.declaracao_variavel_val), (yystack_[0].value.declaracao_variavel_val)); }
#line 704 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 13:
#line 183 "parser.yy"
                                            { (yylhs.value.declaracao_variavel_val) = new DeclaracaoVariavelAst(*(yystack_[4].value.stringVal), *(yystack_[2].value.stringVal), (yystack_[0].value.exp_val)); }
#line 710 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 14:
#line 187 "parser.yy"
                                   { (yylhs.value.declaracao_tipos_val) = new DeclaracaoTipoAst(*(yystack_[2].value.stringVal), (yystack_[0].value.descritor_tipo_val)); }
#line 716 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 15:
#line 191 "parser.yy"
                { (yylhs.value.descritor_tipo_val) = new DescritorTipoIdAst(*(yystack_[0].value.stringVal)); }
#line 722 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 16:
#line 192 "parser.yy"
                      { (yylhs.value.descritor_tipo_val) = new DescritorTipoCamposAst((yystack_[1].value.declaracao_tipos_val)); }
#line 728 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 17:
#line 193 "parser.yy"
                                           { (yylhs.value.descritor_tipo_val) = new DescritorTipoCtesAst((yystack_[3].value.tipo_ctes_val), *(yystack_[0].value.stringVal)); }
#line 734 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 18:
#line 197 "parser.yy"
             { (yylhs.value.declaracao_tipos_val) = new TipoCamposAst((yystack_[0].value.declaracao_tipos_val)); }
#line 740 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 19:
#line 198 "parser.yy"
                             { (yylhs.value.declaracao_tipos_val) = new TipoCamposAst((yystack_[2].value.declaracao_tipos_val), (yystack_[0].value.declaracao_tipos_val)); }
#line 746 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 20:
#line 202 "parser.yy"
                                  { (yylhs.value.declaracao_tipos_val) = new TipoCampoAst(*(yystack_[2].value.stringVal), *(yystack_[0].value.stringVal)); }
#line 752 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 21:
#line 206 "parser.yy"
          { (yylhs.value.tipo_ctes_val) = new TipoConstantesAst((yystack_[0].value.integerVal)); }
#line 758 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 22:
#line 207 "parser.yy"
                              { (yylhs.value.tipo_ctes_val) = new TipoConstantesAst((yystack_[2].value.tipo_ctes_val), (yystack_[0].value.integerVal)); }
#line 764 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 23:
#line 211 "parser.yy"
                     { (yylhs.value.declaracao_funcoes_val) = nullptr; }
#line 770 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 24:
#line 212 "parser.yy"
                                       { (yylhs.value.declaracao_funcoes_val) = (yystack_[0].value.declaracao_funcoes_val); }
#line 776 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 25:
#line 216 "parser.yy"
                    { (yylhs.value.declaracao_funcoes_val) = new DeclaracaoFuncoesAst((yystack_[0].value.declaracao_funcoes_val)); }
#line 782 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 26:
#line 217 "parser.yy"
                                            { (yylhs.value.declaracao_funcoes_val) = new DeclaracaoFuncoesAst((yystack_[1].value.declaracao_funcoes_val), (yystack_[0].value.declaracao_funcoes_val)); }
#line 788 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 27:
#line 221 "parser.yy"
                                                { (yylhs.value.declaracao_funcoes_val) = new DeclaracaoFuncaoAst(*(yystack_[5].value.stringVal), (yystack_[3].value.argumento_val), (yystack_[0].value.corpo_val)); }
#line 794 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 28:
#line 222 "parser.yy"
                                                                  { (yylhs.value.declaracao_funcoes_val) = new DeclaracaoFuncaoAst(*(yystack_[7].value.stringVal), (yystack_[5].value.argumento_val), *(yystack_[2].value.stringVal), (yystack_[0].value.corpo_val)); }
#line 800 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 29:
#line 226 "parser.yy"
                     { (yylhs.value.argumento_val) = nullptr; }
#line 806 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 30:
#line 227 "parser.yy"
    { (yylhs.value.argumento_val) = (yystack_[0].value.argumento_val); }
#line 812 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 31:
#line 231 "parser.yy"
       { (yylhs.value.argumento_val) = new ListaArgsAst((yystack_[0].value.argumento_val)); }
#line 818 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 32:
#line 232 "parser.yy"
                        { (yylhs.value.argumento_val) = new ListaArgsAst((yystack_[2].value.argumento_val), (yystack_[0].value.argumento_val)); }
#line 824 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 33:
#line 236 "parser.yy"
                                              { (yylhs.value.argumento_val) = new ArgumentoAst((yystack_[3].value.modificador_val), *(yystack_[2].value.stringVal), *(yystack_[0].value.stringVal)); }
#line 830 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 34:
#line 240 "parser.yy"
        { (yylhs.value.modificador_val) = Modificador::VALOR; }
#line 836 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 35:
#line 241 "parser.yy"
      { (yylhs.value.modificador_val) = Modificador::REFERENCIA; }
#line 842 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 36:
#line 246 "parser.yy"
                          { (yylhs.value.corpo_val) = new CorpoAst((yystack_[3].value.declaracao_variavel_val), (yystack_[0].value.acao_val)); }
#line 848 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 37:
#line 250 "parser.yy"
                     { (yylhs.value.declaracao_variavel_val) = nullptr; }
#line 854 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 38:
#line 251 "parser.yy"
                                        { (yylhs.value.declaracao_variavel_val) = (yystack_[0].value.declaracao_variavel_val); }
#line 860 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 39:
#line 255 "parser.yy"
          { (yylhs.value.acao_val) = new ListaComandosAst((yystack_[0].value.acao_val)); }
#line 866 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 40:
#line 256 "parser.yy"
                             { (yylhs.value.acao_val) = new ListaComandosAst((yystack_[2].value.acao_val), (yystack_[0].value.acao_val)); }
#line 872 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 41:
#line 260 "parser.yy"
                        { (yylhs.value.acao_val) = new AtribuicaoAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 878 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 42:
#line 261 "parser.yy"
  { (yylhs.value.acao_val) = (yystack_[0].value.acao_val); }
#line 884 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 43:
#line 262 "parser.yy"
                                        { (yylhs.value.acao_val) = new SeAst((yystack_[3].value.exp_val), (yystack_[1].value.acao_val)); }
#line 890 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 44:
#line 263 "parser.yy"
                                                             { (yylhs.value.acao_val) = new SeAst((yystack_[5].value.exp_val), (yystack_[3].value.acao_val), (yystack_[1].value.acao_val)); }
#line 896 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 45:
#line 264 "parser.yy"
                                                                   { (yylhs.value.acao_val) = new ParaAst(*(yystack_[7].value.stringVal), (yystack_[5].value.exp_val), (yystack_[3].value.exp_val), (yystack_[1].value.acao_val)); }
#line 902 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 46:
#line 265 "parser.yy"
                                              { (yylhs.value.acao_val) = new EnquantoAst((yystack_[3].value.exp_val), (yystack_[1].value.acao_val)); }
#line 908 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 47:
#line 266 "parser.yy"
       { (yylhs.value.acao_val) = new PareAst(); }
#line 914 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 48:
#line 267 "parser.yy"
           { (yylhs.value.acao_val) = new ContinueAst(); }
#line 920 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 49:
#line 268 "parser.yy"
               { (yylhs.value.acao_val) = new RetorneAst((yystack_[0].value.exp_val)); }
#line 926 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 50:
#line 272 "parser.yy"
                                           { (yylhs.value.acao_val) = new ChamadaProcedimentoAst(*(yystack_[3].value.stringVal), (yystack_[1].value.exp_val)); }
#line 932 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 51:
#line 276 "parser.yy"
                   { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 938 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 52:
#line 277 "parser.yy"
                              { (yylhs.value.exp_val) = (yystack_[1].value.exp_val); }
#line 944 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 53:
#line 281 "parser.yy"
                      { (yylhs.value.exp_val) = new CriacaoRegistroAst((yystack_[0].value.exp_val)); }
#line 950 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 54:
#line 282 "parser.yy"
                                              { (yylhs.value.exp_val) = new CriacaoRegistroAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 956 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 55:
#line 286 "parser.yy"
                         { (yylhs.value.exp_val) = new AtribuicaoRegistroAst(*(yystack_[2].value.stringVal), (yystack_[0].value.exp_val)); }
#line 962 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 56:
#line 290 "parser.yy"
                                            { (yylhs.value.exp_val) = new AndAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 968 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 57:
#line 291 "parser.yy"
                                            { (yylhs.value.exp_val) = new OrAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 974 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 58:
#line 292 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 980 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 59:
#line 296 "parser.yy"
                                                 { (yylhs.value.exp_val) = new MenorIgualAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 986 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 60:
#line 297 "parser.yy"
                                                 { (yylhs.value.exp_val) = new MaiorIgualAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 992 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 61:
#line 298 "parser.yy"
                                                { (yylhs.value.exp_val) = new MenorAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 998 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 62:
#line 299 "parser.yy"
                                                { (yylhs.value.exp_val) = new MaiorAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 1004 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 63:
#line 300 "parser.yy"
                                                 { (yylhs.value.exp_val) = new DiferenteAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 1010 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 64:
#line 301 "parser.yy"
                                                 { (yylhs.value.exp_val) = new EquivalenteAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 1016 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 65:
#line 302 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 1022 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 66:
#line 306 "parser.yy"
                                 { (yylhs.value.exp_val) = new SomaAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 1028 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 67:
#line 307 "parser.yy"
                                 { (yylhs.value.exp_val) = new SubtracaoAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 1034 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 68:
#line 308 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 1040 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 69:
#line 312 "parser.yy"
                  { (yylhs.value.exp_val) = new MultiplicacaoAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 1046 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 70:
#line 313 "parser.yy"
                  { (yylhs.value.exp_val) = new DivisaoAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 1052 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 71:
#line 314 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 1058 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 72:
#line 318 "parser.yy"
               { (yylhs.value.exp_val) = (yystack_[1].value.exp_val); }
#line 1064 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 73:
#line 319 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 1070 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 74:
#line 320 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 1076 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 75:
#line 321 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 1082 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 76:
#line 322 "parser.yy"
       { (yylhs.value.exp_val) = new NuloAst(); }
#line 1088 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 77:
#line 326 "parser.yy"
                                           { (yylhs.value.exp_val) = new ChamadaFuncaoAst(*(yystack_[3].value.stringVal), (yystack_[1].value.exp_val)); }
#line 1094 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 78:
#line 330 "parser.yy"
                     { (yylhs.value.exp_val) = nullptr; }
#line 1100 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 79:
#line 331 "parser.yy"
        { (yylhs.value.exp_val) = new ListaArgsChamada((yystack_[0].value.exp_val)); }
#line 1106 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 80:
#line 332 "parser.yy"
                               { (yylhs.value.exp_val) = new ListaArgsChamada((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 1112 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 81:
#line 336 "parser.yy"
          { (yylhs.value.exp_val) = new InteiroAst((yystack_[0].value.integerVal)); }
#line 1118 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 82:
#line 337 "parser.yy"
       { (yylhs.value.exp_val) = new RealAst((yystack_[0].value.doubleVal)); }
#line 1124 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 83:
#line 338 "parser.yy"
         { (yylhs.value.exp_val) = new CadeiaAst(*(yystack_[0].value.stringVal)); }
#line 1130 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 84:
#line 342 "parser.yy"
                { (yylhs.value.exp_val) = new LocalAst(*(yystack_[0].value.stringVal)); }
#line 1136 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 85:
#line 343 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[2].value.exp_val); }
#line 1142 "/home/kari/git/compilador-simples/build/parser.cc"
    break;

  case 86:
#line 344 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[3].value.exp_val); }
#line 1148 "/home/kari/git/compilador-simples/build/parser.cc"
    break;


#line 1152 "/home/kari/git/compilador-simples/build/parser.cc"

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


  const signed char Parser::yypact_ninf_ = -78;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
       3,   -19,    25,    73,    64,    35,   -78,    54,   -78,    70,
     101,    58,    35,   -78,    69,   103,    77,   -78,     6,   -78,
      76,   -78,   -78,   110,     7,     7,     7,    79,   -78,   -78,
      11,    81,   103,   -78,   113,   -78,    95,   115,   -78,    33,
     102,    85,   -78,   -78,   -78,   -78,     7,   119,   111,    -9,
      47,    21,    32,   -78,   -78,   -78,   -20,   109,   -78,    69,
      33,   122,     7,   123,   -78,    91,   113,   -78,   -78,   -12,
      94,   -22,   -78,   -78,    37,     7,    33,    92,    78,    27,
     -78,    69,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    69,   -78,    15,   -78,   -78,    80,
      40,   -78,   114,   117,   129,   115,   -78,    33,   -78,   118,
      48,   -78,     7,   119,   -78,     2,    47,    47,    21,    21,
      21,    21,    21,    21,    32,    32,   -78,   -78,    -2,   -78,
       7,   -78,   -78,    96,   105,   -78,   136,   -78,   137,   -78,
     -78,   -78,     7,   -78,   -78,   -78,   -78,   -78,    69,   -78,
     -18,    40,   107,   -78,   131,    -7,   141,   124,   -78,   144,
      69,   -78,    97,   116,   -78,   143,   -78,    -3,   124,   103,
     120,   -78,   -78,   103,    69,    79
  };

  const signed char
  Parser::yydefact_[] =
  {
       5,     0,     0,     0,     9,     0,     1,     0,     2,     0,
      23,     0,     6,     7,     0,     0,     0,     3,     0,     8,
      84,    47,    48,     0,     0,     0,     0,     4,    39,    42,
       0,     0,    10,    11,     0,    15,     0,     0,    14,    78,
       0,    84,    81,    82,    83,    76,     0,     0,     0,    51,
      58,    65,    68,    71,    75,    73,    74,     0,    49,     0,
      78,     0,     0,     0,    12,     0,    24,    25,    21,     0,
       0,     0,    18,    79,     0,     0,    78,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,     0,    85,    41,     0,
      29,    26,     0,     0,     0,     0,    16,     0,    50,     0,
       0,    72,     0,     0,    52,     0,    56,    57,    64,    63,
      61,    59,    62,    60,    66,    67,    70,    69,     0,    86,
       0,    34,    35,     0,    30,    31,     0,    22,     0,    20,
      19,    80,     0,    77,    55,    54,    46,    43,     0,    13,
       0,     0,     0,    17,     0,     0,     0,    37,    32,     0,
       0,    44,     0,     0,    27,     0,    33,     0,    37,     0,
       0,    45,    28,    38,     0,    36
  };

  const short
  Parser::yypgoto_[] =
  {
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -17,   -31,   139,
     -78,   -78,    50,   -78,   -78,   -78,    87,   -78,   -78,     5,
     -78,   -11,   -78,   -77,    99,   -78,   -23,   -78,    46,   -78,
       4,    14,    18,   -34,   -78,   -52,   -78,   -14
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,     8,     4,    12,    10,    32,    33,    13,
      38,    71,    72,    69,    17,    66,    67,   133,   134,   135,
     136,   164,   165,    27,    28,    29,    48,    79,    80,    49,
      50,    51,    52,    53,    54,    74,    55,    56
  };

  const unsigned char
  Parser::yytable_[] =
  {
      30,    64,    57,    58,   115,    73,   171,   161,    96,    35,
      41,   105,   147,   146,   148,     5,   156,   128,    60,   106,
       1,   102,    61,    77,   110,     6,    73,   103,    59,    42,
      43,    44,    59,    59,   157,    45,    41,    59,    11,    98,
      82,    83,    73,    46,    36,    30,    37,    47,   107,    60,
      90,    91,   109,    61,   129,    42,    43,    44,   126,   127,
     113,    45,    62,    92,    93,   131,   132,    30,   114,    46,
     107,   155,    20,   141,   108,    21,    22,    23,     7,    24,
      30,   107,    25,   167,     9,   143,   116,   117,    14,   144,
      84,    85,    86,    87,    88,    89,    26,   175,   118,   119,
     120,   121,   122,   123,    15,    16,    31,   149,   124,   125,
      18,    34,    39,    40,    59,    63,    65,    68,    70,   154,
      75,    76,    78,    81,    94,    97,    99,   100,   104,   111,
     112,   130,   139,   150,    30,   138,   137,   142,   151,   152,
     153,   159,    64,   160,   162,   163,    30,   166,   170,   168,
     169,    19,   173,   101,   174,   140,   158,   172,    95,   145,
      30
  };

  const unsigned char
  Parser::yycheck_[] =
  {
      14,    32,    25,    26,    81,    39,     9,    14,    60,     3,
       3,    33,    14,    11,    16,    34,    34,    94,    38,    41,
      17,    33,    42,    46,    76,     0,    60,    39,    35,    22,
      23,    24,    35,    35,    52,    28,     3,    35,     3,    62,
      49,    50,    76,    36,    38,    59,    40,    40,    33,    38,
      29,    30,    75,    42,    39,    22,    23,    24,    92,    93,
      33,    28,    51,    31,    32,    25,    26,    81,    41,    36,
      33,   148,     3,   107,    37,     6,     7,     8,     5,    10,
      94,    33,    13,   160,    20,    37,    82,    83,    34,   112,
      43,    44,    45,    46,    47,    48,    27,   174,    84,    85,
      86,    87,    88,    89,    34,     4,     3,   130,    90,    91,
      52,    34,    36,     3,    35,    34,     3,    22,     3,   142,
      18,    36,     3,    12,    15,     3,     3,    36,    34,    37,
      52,    51,     3,    37,   148,    18,    22,    19,    33,     3,
       3,    34,   173,    12,     3,    21,   160,     3,     5,    52,
      34,    12,   169,    66,    34,   105,   151,   168,    59,   113,
     174
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    17,    54,    55,    57,    34,     0,     5,    56,    20,
      59,     3,    58,    62,    34,    34,     4,    67,    52,    62,
       3,     6,     7,     8,    10,    13,    27,    76,    77,    78,
      90,     3,    60,    61,    34,     3,    38,    40,    63,    36,
       3,     3,    22,    23,    24,    28,    36,    40,    79,    82,
      83,    84,    85,    86,    87,    89,    90,    79,    79,    35,
      38,    42,    51,    34,    61,     3,    68,    69,    22,    66,
       3,    64,    65,    86,    88,    18,    36,    79,     3,    80,
      81,    12,    49,    50,    43,    44,    45,    46,    47,    48,
      29,    30,    31,    32,    15,    77,    88,     3,    79,     3,
      36,    69,    33,    39,    34,    33,    41,    33,    37,    79,
      88,    37,    52,    33,    41,    76,    83,    83,    84,    84,
      84,    84,    84,    84,    85,    85,    86,    86,    76,    39,
      51,    25,    26,    70,    71,    72,    73,    22,    18,     3,
      65,    86,    19,    37,    79,    81,    11,    14,    16,    79,
      37,    33,     3,     3,    79,    76,    34,    52,    72,    34,
      12,    14,     3,    21,    74,    75,     3,    76,    52,    34,
       5,     9,    74,    60,    34,    76
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    53,    54,    55,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    62,    63,    63,    63,    64,    64,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    72,    73,    73,    74,    75,    75,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      78,    79,    79,    80,    80,    81,    82,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    84,    84,    84,    85,
      85,    85,    86,    86,    86,    86,    86,    87,    88,    88,
      88,    89,    89,    89,    90,    90,    90
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     3,     3,     0,     3,     1,     2,     0,
       3,     1,     2,     5,     3,     1,     3,     5,     1,     3,
       3,     1,     3,     0,     3,     1,     2,     6,     8,     0,
       1,     1,     3,     4,     1,     1,     4,     0,     3,     1,
       3,     3,     1,     5,     7,     9,     5,     1,     1,     2,
       4,     1,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     1,     1,     1,     1,     4,     0,     1,
       3,     1,     1,     1,     1,     3,     4
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
  "lista_declaracao_variavel", "declaracao_variavel", "declaracao_tipo",
  "descritor_tipo", "tipo_campos", "tipo_campo", "tipo_constantes",
  "lista_declaracao_de_funcao", "lista_declaracao_funcao",
  "declaracao_funcao", "lista_de_args", "lista_args", "args",
  "modificador", "corpo", "lista_declaracao_de_variavel_local",
  "lista_comandos", "comando", "chamada_de_procedimento", "expr",
  "criacao_de_registro", "atribuicao_registro", "expressao_logica",
  "expressao_relacional", "expressao_aritmetica", "termo", "fator",
  "chamada_de_funcao", "lista_args_chamada", "literal", "local", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   149,   149,   153,   159,   163,   164,   168,   169,   173,
     174,   178,   179,   183,   187,   191,   192,   193,   197,   198,
     202,   206,   207,   211,   212,   216,   217,   221,   222,   226,
     227,   231,   232,   236,   240,   241,   245,   250,   251,   255,
     256,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     272,   276,   277,   281,   282,   286,   290,   291,   292,   296,
     297,   298,   299,   300,   301,   302,   306,   307,   308,   312,
     313,   314,   318,   319,   320,   321,   322,   326,   330,   331,
     332,   336,   337,   338,   342,   343,   344
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

#line 45 "parser.yy"
} // Simples
#line 1712 "/home/kari/git/compilador-simples/build/parser.cc"

#line 347 "parser.yy"


namespace Simples {
   void Parser::error(const location&, const string& m) {
        cerr << *driver.location_ << ": " << m << endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
