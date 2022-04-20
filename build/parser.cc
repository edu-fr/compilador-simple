// A Bison parser, made by GNU Bison 3.7.6.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 5 "parser.yy"


/*** C++ Declarations ***/
#include "parser.hh"
#include "scanner.hh"
#include "AST_classes.hh"

#define yylex driver.scanner_->yylex


#line 52 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"


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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
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
#line 150 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"

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
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
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
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
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

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
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
    that.kind_ = symbol_kind::S_YYEMPTY;
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
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
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
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
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
    YY_STACK_PRINT ();

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
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, driver));
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
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
  case 2: // programa: declaracoes acao
#line 149 "parser.yy"
                   { (yylhs.value.programa_val) = new ProgramaAst((yystack_[1].value.declaracao_val), (yystack_[0].value.acao_val)); }
#line 617 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 3: // declaracoes: lista_declaracao_de_tipo lista_declaracao_de_variavel_global lista_declaracao_de_funcao
#line 155 "parser.yy"
                             { (yylhs.value.declaracao_val) = new DeclaracoesAst((yystack_[2].value.declaracao_tipos_val), (yystack_[1].value.declaracao_variavel_val), (yystack_[0].value.declaracao_funcoes_val)); }
#line 623 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 4: // acao: "ação" ":" lista_comandos
#line 159 "parser.yy"
                          { (yylhs.value.acao_val) = (yystack_[0].value.acao_val); }
#line 629 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 5: // lista_declaracao_de_tipo: %empty
#line 163 "parser.yy"
                     { (yylhs.value.declaracao_tipos_val) = nullptr; }
#line 635 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 6: // lista_declaracao_de_tipo: "tipo" ":" lista_declaracao_tipo
#line 164 "parser.yy"
                                   { (yylhs.value.declaracao_tipos_val) = (yystack_[0].value.declaracao_tipos_val); }
#line 641 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 7: // lista_declaracao_tipo: declaracao_tipo
#line 168 "parser.yy"
                  { (yylhs.value.declaracao_tipos_val) = new DeclaracaoTiposAst((yystack_[0].value.declaracao_tipos_val)); }
#line 647 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 8: // lista_declaracao_tipo: lista_declaracao_tipo declaracao_tipo
#line 169 "parser.yy"
                                        { (yylhs.value.declaracao_tipos_val) = new DeclaracaoTiposAst((yystack_[1].value.declaracao_tipos_val), (yystack_[0].value.declaracao_tipos_val)); }
#line 653 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 9: // lista_declaracao_de_variavel_global: %empty
#line 173 "parser.yy"
                     { (yylhs.value.declaracao_variavel_val) = nullptr; }
#line 659 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 10: // lista_declaracao_de_variavel_global: "global" ":" lista_declaracao_variavel
#line 174 "parser.yy"
                                       { (yylhs.value.declaracao_variavel_val) = (yystack_[0].value.declaracao_variavel_val); }
#line 665 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 11: // lista_declaracao_variavel: declaracao_variavel
#line 178 "parser.yy"
                      { (yylhs.value.declaracao_variavel_val) = new ListaDecVarAst((yystack_[0].value.declaracao_variavel_val)); }
#line 671 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 12: // lista_declaracao_variavel: lista_declaracao_variavel declaracao_variavel
#line 179 "parser.yy"
                                                { (yylhs.value.declaracao_variavel_val) = new ListaDecVarAst((yystack_[1].value.declaracao_variavel_val), (yystack_[0].value.declaracao_variavel_val)); }
#line 677 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 13: // declaracao_variavel: "identificador" ":" "identificador" ":=" inicializacao
#line 183 "parser.yy"
                                                     { (yylhs.value.declaracao_variavel_val) = new DeclaracaoVariavelAst(*(yystack_[4].value.stringVal), *(yystack_[2].value.stringVal), (yystack_[0].value.exp_val)); }
#line 683 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 14: // inicializacao: expr
#line 187 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 689 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 15: // declaracao_tipo: "identificador" "=" descritor_tipo
#line 191 "parser.yy"
                                   { (yylhs.value.declaracao_tipos_val) = new DeclaracaoTipoAst(*(yystack_[2].value.stringVal), (yystack_[0].value.descritor_tipo_val)); }
#line 695 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 16: // descritor_tipo: "identificador"
#line 195 "parser.yy"
                { (yylhs.value.descritor_tipo_val) = new DescritorTipoIdAst(*(yystack_[0].value.stringVal)); }
#line 701 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 17: // descritor_tipo: "{" tipo_campos "}"
#line 196 "parser.yy"
                      { (yylhs.value.descritor_tipo_val) = new DescritorTipoCamposAst((yystack_[1].value.declaracao_tipos_val)); }
#line 707 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 18: // descritor_tipo: "[" tipo_constantes "]" "de" "identificador"
#line 197 "parser.yy"
                                           { (yylhs.value.descritor_tipo_val) = new DescritorTipoCtesAst((yystack_[3].value.tipo_ctes_val), *(yystack_[0].value.stringVal)); }
#line 713 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 19: // tipo_campos: tipo_campo
#line 201 "parser.yy"
             { (yylhs.value.declaracao_tipos_val) = new TipoCamposAst((yystack_[0].value.declaracao_tipos_val)); }
#line 719 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 20: // tipo_campos: tipo_campos "," tipo_campo
#line 202 "parser.yy"
                             { (yylhs.value.declaracao_tipos_val) = new TipoCamposAst((yystack_[2].value.declaracao_tipos_val), (yystack_[0].value.declaracao_tipos_val)); }
#line 725 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 21: // tipo_campo: "identificador" ":" "identificador"
#line 206 "parser.yy"
                                  { (yylhs.value.declaracao_tipos_val) = new TipoCampoAst(*(yystack_[2].value.stringVal), *(yystack_[0].value.stringVal)); }
#line 731 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 22: // tipo_constantes: "inteiro"
#line 210 "parser.yy"
          { (yylhs.value.tipo_ctes_val) = new TipoConstantesAst((yystack_[0].value.integerVal)); }
#line 737 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 23: // tipo_constantes: tipo_constantes "," "inteiro"
#line 211 "parser.yy"
                              { (yylhs.value.tipo_ctes_val) = new TipoConstantesAst((yystack_[2].value.tipo_ctes_val), (yystack_[0].value.integerVal)); }
#line 743 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 24: // lista_declaracao_de_funcao: %empty
#line 215 "parser.yy"
                     { (yylhs.value.declaracao_funcoes_val) = nullptr; }
#line 749 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 25: // lista_declaracao_de_funcao: "função" ":" lista_declaracao_funcao
#line 216 "parser.yy"
                                       { (yylhs.value.declaracao_funcoes_val) = (yystack_[0].value.declaracao_funcoes_val); }
#line 755 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 26: // lista_declaracao_funcao: declaracao_funcao
#line 220 "parser.yy"
                    { (yylhs.value.declaracao_funcoes_val) = new DeclaracaoFuncoesAst((yystack_[0].value.declaracao_funcoes_val)); }
#line 761 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 27: // lista_declaracao_funcao: lista_declaracao_funcao declaracao_funcao
#line 221 "parser.yy"
                                            { (yylhs.value.declaracao_funcoes_val) = new DeclaracaoFuncoesAst((yystack_[1].value.declaracao_funcoes_val), (yystack_[0].value.declaracao_funcoes_val)); }
#line 767 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 28: // declaracao_funcao: "identificador" "(" lista_de_args ")" "=" corpo
#line 225 "parser.yy"
                                                { (yylhs.value.declaracao_funcoes_val) = new DeclaracaoFuncaoAst(*(yystack_[5].value.stringVal), (yystack_[3].value.argumento_val), (yystack_[0].value.corpo_val)); }
#line 773 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 29: // declaracao_funcao: "identificador" "(" lista_de_args ")" ":" "identificador" "=" corpo
#line 226 "parser.yy"
                                                                  { (yylhs.value.declaracao_funcoes_val) = new DeclaracaoFuncaoAst(*(yystack_[7].value.stringVal), (yystack_[5].value.argumento_val), *(yystack_[2].value.stringVal), (yystack_[0].value.corpo_val)); }
#line 779 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 30: // lista_de_args: %empty
#line 230 "parser.yy"
                     { (yylhs.value.argumento_val) = nullptr; }
#line 785 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 31: // lista_de_args: lista_args
#line 231 "parser.yy"
    { (yylhs.value.argumento_val) = (yystack_[0].value.argumento_val); }
#line 791 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 32: // lista_args: args
#line 235 "parser.yy"
       { (yylhs.value.argumento_val) = new ListaArgsAst((yystack_[0].value.argumento_val)); }
#line 797 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 33: // lista_args: lista_args "," args
#line 236 "parser.yy"
                        { (yylhs.value.argumento_val) = new ListaArgsAst((yystack_[2].value.argumento_val), (yystack_[0].value.argumento_val)); }
#line 803 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 34: // args: modificador "identificador" ":" "identificador"
#line 240 "parser.yy"
                                              { (yylhs.value.argumento_val) = new ArgumentoAst((yystack_[3].value.modificador_val), *(yystack_[2].value.stringVal), *(yystack_[0].value.stringVal)); }
#line 809 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 35: // modificador: "valor"
#line 244 "parser.yy"
        { (yylhs.value.modificador_val) = Modificador::VALOR; }
#line 815 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 36: // modificador: "ref"
#line 245 "parser.yy"
      { (yylhs.value.modificador_val) = Modificador::REFERENCIA; }
#line 821 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 37: // corpo: lista_declaracao_de_variavel_local "ação" ":" lista_comandos
#line 250 "parser.yy"
                          { (yylhs.value.corpo_val) = new CorpoAst((yystack_[3].value.declaracao_variavel_val), (yystack_[0].value.acao_val)); }
#line 827 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 38: // lista_declaracao_de_variavel_local: %empty
#line 254 "parser.yy"
                     { (yylhs.value.declaracao_variavel_val) = nullptr; }
#line 833 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 39: // lista_declaracao_de_variavel_local: "local" ":" lista_declaracao_variavel
#line 255 "parser.yy"
                                        { (yylhs.value.declaracao_variavel_val) = (yystack_[0].value.declaracao_variavel_val); }
#line 839 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 40: // lista_comandos: comando
#line 259 "parser.yy"
          { (yylhs.value.acao_val) = new ListaComandosAst((yystack_[0].value.acao_val)); }
#line 845 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 41: // lista_comandos: lista_comandos ";" comando
#line 260 "parser.yy"
                             { (yylhs.value.acao_val) = new ListaComandosAst((yystack_[2].value.acao_val), (yystack_[0].value.acao_val)); }
#line 851 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 42: // comando: local ":=" expr
#line 264 "parser.yy"
                        { (yylhs.value.acao_val) = new AtribuicaoAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 857 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 43: // comando: chamada_de_procedimento
#line 265 "parser.yy"
  { (yylhs.value.acao_val) = (yystack_[0].value.acao_val); }
#line 863 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 44: // comando: "se" expr "verdadeiro" lista_comandos "fse"
#line 266 "parser.yy"
                                        { (yylhs.value.acao_val) = new SeAst((yystack_[3].value.exp_val), (yystack_[1].value.acao_val)); }
#line 869 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 45: // comando: "se" expr "verdadeiro" lista_comandos "falso" lista_comandos "fse"
#line 267 "parser.yy"
                                                             { (yylhs.value.acao_val) = new SeAst((yystack_[5].value.exp_val), (yystack_[3].value.acao_val), (yystack_[1].value.acao_val)); }
#line 875 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 46: // comando: "para" "identificador" "de" expr "limite" expr "faça" lista_comandos "fpara"
#line 268 "parser.yy"
                                                                   { (yylhs.value.acao_val) = new ParaAst(*(yystack_[7].value.stringVal), (yystack_[5].value.exp_val), (yystack_[3].value.exp_val), (yystack_[1].value.acao_val)); }
#line 881 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 47: // comando: "enquanto" expr "faça" lista_comandos "fenquanto"
#line 269 "parser.yy"
                                              { (yylhs.value.acao_val) = new EnquantoAst((yystack_[3].value.exp_val), (yystack_[1].value.acao_val)); }
#line 887 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 48: // comando: "pare"
#line 270 "parser.yy"
       { (yylhs.value.acao_val) = new PareAst(); }
#line 893 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 49: // comando: "continue"
#line 271 "parser.yy"
           { (yylhs.value.acao_val) = new ContinueAst(); }
#line 899 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 50: // comando: "retorne" expr
#line 272 "parser.yy"
               { (yylhs.value.acao_val) = new RetorneAst((yystack_[0].value.exp_val)); }
#line 905 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 51: // chamada_de_procedimento: "identificador" "(" lista_args_chamada ")"
#line 276 "parser.yy"
                                           { (yylhs.value.acao_val) = new ChamadaProcedimentoAst(*(yystack_[3].value.stringVal), (yystack_[1].value.exp_val)); }
#line 911 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 52: // expr: expressao_logica
#line 281 "parser.yy"
                   { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 917 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 53: // expr: "{" criacao_de_registro "}"
#line 282 "parser.yy"
                              { (yylhs.value.exp_val) = (yystack_[1].value.exp_val); }
#line 923 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 54: // criacao_de_registro: atribuicao_registro
#line 286 "parser.yy"
                      { (yylhs.value.exp_val) = new CriacaoRegistroAst((yystack_[0].value.exp_val)); }
#line 929 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 55: // criacao_de_registro: criacao_de_registro "," atribuicao_registro
#line 287 "parser.yy"
                                              { (yylhs.value.exp_val) = new CriacaoRegistroAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 935 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 56: // atribuicao_registro: "identificador" "=" expr
#line 291 "parser.yy"
                         { (yylhs.value.exp_val) = new AtribuicaoRegistroAst(*(yystack_[2].value.stringVal), (yystack_[0].value.exp_val)); }
#line 941 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 57: // expressao_logica: expressao_logica "&" expressao_relacional
#line 295 "parser.yy"
                                            { (yylhs.value.exp_val) = new AndAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 947 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 58: // expressao_logica: expressao_logica "|" expressao_relacional
#line 296 "parser.yy"
                                            { (yylhs.value.exp_val) = new OrAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 953 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 59: // expressao_logica: expressao_relacional
#line 297 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 959 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 60: // expressao_relacional: expressao_relacional "<=" expressao_aritmetica
#line 301 "parser.yy"
                                                 { (yylhs.value.exp_val) = new MenorIgualAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 965 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 61: // expressao_relacional: expressao_relacional ">=" expressao_aritmetica
#line 302 "parser.yy"
                                                 { (yylhs.value.exp_val) = new MaiorIgualAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 971 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 62: // expressao_relacional: expressao_relacional "<" expressao_aritmetica
#line 303 "parser.yy"
                                                { (yylhs.value.exp_val) = new MenorAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 977 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 63: // expressao_relacional: expressao_relacional ">" expressao_aritmetica
#line 304 "parser.yy"
                                                { (yylhs.value.exp_val) = new MaiorAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 983 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 64: // expressao_relacional: expressao_relacional "!=" expressao_aritmetica
#line 305 "parser.yy"
                                                 { (yylhs.value.exp_val) = new DiferenteAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 989 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 65: // expressao_relacional: expressao_relacional "==" expressao_aritmetica
#line 306 "parser.yy"
                                                 { (yylhs.value.exp_val) = new EquivalenteAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 995 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 66: // expressao_relacional: expressao_aritmetica
#line 307 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 1001 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 67: // expressao_aritmetica: expressao_aritmetica "+" termo
#line 311 "parser.yy"
                                 { (yylhs.value.exp_val) = new SomaAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 1007 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 68: // expressao_aritmetica: expressao_aritmetica "-" termo
#line 312 "parser.yy"
                                 { (yylhs.value.exp_val) = new SubtracaoAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 1013 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 69: // expressao_aritmetica: termo
#line 313 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 1019 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 70: // termo: termo "*" fator
#line 317 "parser.yy"
                  { (yylhs.value.exp_val) = new MultiplicacaoAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 1025 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 71: // termo: termo "/" fator
#line 318 "parser.yy"
                  { (yylhs.value.exp_val) = new DivisaoAst((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 1031 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 72: // termo: fator
#line 319 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 1037 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 73: // fator: "(" expr ")"
#line 323 "parser.yy"
               { (yylhs.value.exp_val) = (yystack_[1].value.exp_val); }
#line 1043 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 74: // fator: literal
#line 324 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 1049 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 75: // fator: local
#line 325 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 1055 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 76: // fator: chamada_de_funcao
#line 326 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[0].value.exp_val); }
#line 1061 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 77: // fator: "nulo"
#line 327 "parser.yy"
       { (yylhs.value.exp_val) = new NuloAst(); }
#line 1067 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 78: // chamada_de_funcao: "identificador" "(" lista_args_chamada ")"
#line 331 "parser.yy"
                                           { (yylhs.value.exp_val) = new ChamadaFuncaoAst(*(yystack_[3].value.stringVal), (yystack_[1].value.exp_val)); }
#line 1073 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 79: // lista_args_chamada: %empty
#line 335 "parser.yy"
                     { (yylhs.value.exp_val) = nullptr; }
#line 1079 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 80: // lista_args_chamada: fator
#line 336 "parser.yy"
        { (yylhs.value.exp_val) = new ListaArgsChamada((yystack_[0].value.exp_val)); }
#line 1085 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 81: // lista_args_chamada: lista_args_chamada "," fator
#line 337 "parser.yy"
                               { (yylhs.value.exp_val) = new ListaArgsChamada((yystack_[2].value.exp_val), (yystack_[0].value.exp_val)); }
#line 1091 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 82: // literal: "inteiro"
#line 341 "parser.yy"
          { (yylhs.value.exp_val) = new InteiroAst((yystack_[0].value.integerVal)); }
#line 1097 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 83: // literal: "real"
#line 342 "parser.yy"
       { (yylhs.value.exp_val) = new RealAst((yystack_[0].value.doubleVal)); }
#line 1103 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 84: // literal: "cadeia"
#line 343 "parser.yy"
         { (yylhs.value.exp_val) = new CadeiaAst(*(yystack_[0].value.stringVal)); }
#line 1109 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 85: // local: "identificador"
#line 347 "parser.yy"
                { (yylhs.value.exp_val) = new LocalAst(*(yystack_[0].value.stringVal)); }
#line 1115 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 86: // local: local "." "identificador"
#line 348 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[2].value.exp_val); }
#line 1121 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 87: // local: local "[" lista_args_chamada "]"
#line 349 "parser.yy"
  { (yylhs.value.exp_val) = (yystack_[3].value.exp_val); }
#line 1127 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"
    break;


#line 1131 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;

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
    YY_STACK_PRINT ();
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

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
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

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

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
          yyres += symbol_name (yyarg[yyi++]);
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
       3,   -19,    25,    73,    63,    35,   -78,    54,   -78,    65,
      93,    58,    35,   -78,    69,   103,    77,   -78,     6,   -78,
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
     -78,   -18,    40,   107,   -78,   130,    -7,   141,   124,   -78,
     143,    69,   -78,    97,   116,   -78,   146,   -78,    -3,   124,
     103,   120,   -78,   -78,   103,    69,    79
  };

  const signed char
  Parser::yydefact_[] =
  {
       5,     0,     0,     0,     9,     0,     1,     0,     2,     0,
      24,     0,     6,     7,     0,     0,     0,     3,     0,     8,
      85,    48,    49,     0,     0,     0,     0,     4,    40,    43,
       0,     0,    10,    11,     0,    16,     0,     0,    15,    79,
       0,    85,    82,    83,    84,    77,     0,     0,     0,    52,
      59,    66,    69,    72,    76,    74,    75,     0,    50,     0,
      79,     0,     0,     0,    12,     0,    25,    26,    22,     0,
       0,     0,    19,    80,     0,     0,    79,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,    86,    42,     0,
      30,    27,     0,     0,     0,     0,    17,     0,    51,     0,
       0,    73,     0,     0,    53,     0,    57,    58,    65,    64,
      62,    60,    63,    61,    67,    68,    71,    70,     0,    87,
       0,    35,    36,     0,    31,    32,     0,    23,     0,    21,
      20,    81,     0,    78,    56,    55,    47,    44,     0,    13,
      14,     0,     0,     0,    18,     0,     0,     0,    38,    33,
       0,     0,    45,     0,     0,    28,     0,    34,     0,    38,
       0,     0,    46,    29,    39,     0,    37
  };

  const short
  Parser::yypgoto_[] =
  {
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -17,   -31,   -78,
     140,   -78,   -78,    43,   -78,   -78,   -78,    89,   -78,   -78,
       5,   -78,   -13,   -78,   -77,    99,   -78,   -23,   -78,    46,
     -78,     4,    16,    18,   -34,   -78,   -52,   -78,   -14
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     2,     3,     8,     4,    12,    10,    32,    33,   149,
      13,    38,    71,    72,    69,    17,    66,    67,   133,   134,
     135,   136,   165,   166,    27,    28,    29,    48,    79,    80,
      49,    50,    51,    52,    53,    54,    74,    55,    56
  };

  const unsigned char
  Parser::yytable_[] =
  {
      30,    64,    57,    58,   115,    73,   172,   162,    96,    35,
      41,   105,   147,   146,   148,     5,   157,   128,    60,   106,
       1,   102,    61,    77,   110,     6,    73,   103,    59,    42,
      43,    44,    59,    59,   158,    45,    41,    59,    11,    98,
      82,    83,    73,    46,    36,    30,    37,    47,   107,    60,
      90,    91,   109,    61,   129,    42,    43,    44,   126,   127,
     113,    45,    62,    92,    93,   131,   132,    30,   114,    46,
     107,   156,    20,   141,   108,    21,    22,    23,     7,    24,
      30,   107,    25,     9,   168,   143,   116,   117,    14,   144,
      84,    85,    86,    87,    88,    89,    26,    16,   176,    15,
     118,   119,   120,   121,   122,   123,    31,   150,   124,   125,
      18,    34,    39,    40,    59,    63,    65,    68,    70,   155,
      75,    76,    78,    81,    94,    97,    99,   100,   104,   111,
     112,   130,   139,   151,    30,   138,   137,   142,   152,   153,
     154,   160,   161,    64,   163,   164,   167,    30,   140,   169,
     170,   171,    19,   174,   175,   101,   173,   159,    95,   145,
       0,    30
  };

  const short
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
      94,    33,    13,    20,   161,    37,    82,    83,    34,   112,
      43,    44,    45,    46,    47,    48,    27,     4,   175,    34,
      84,    85,    86,    87,    88,    89,     3,   130,    90,    91,
      52,    34,    36,     3,    35,    34,     3,    22,     3,   142,
      18,    36,     3,    12,    15,     3,     3,    36,    34,    37,
      52,    51,     3,    37,   148,    18,    22,    19,    33,     3,
       3,    34,    12,   174,     3,    21,     3,   161,   105,    52,
      34,     5,    12,   170,    34,    66,   169,   152,    59,   113,
      -1,   175
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    17,    54,    55,    57,    34,     0,     5,    56,    20,
      59,     3,    58,    63,    34,    34,     4,    68,    52,    63,
       3,     6,     7,     8,    10,    13,    27,    77,    78,    79,
      91,     3,    60,    61,    34,     3,    38,    40,    64,    36,
       3,     3,    22,    23,    24,    28,    36,    40,    80,    83,
      84,    85,    86,    87,    88,    90,    91,    80,    80,    35,
      38,    42,    51,    34,    61,     3,    69,    70,    22,    67,
       3,    65,    66,    87,    89,    18,    36,    80,     3,    81,
      82,    12,    49,    50,    43,    44,    45,    46,    47,    48,
      29,    30,    31,    32,    15,    78,    89,     3,    80,     3,
      36,    70,    33,    39,    34,    33,    41,    33,    37,    80,
      89,    37,    52,    33,    41,    77,    84,    84,    85,    85,
      85,    85,    85,    85,    86,    86,    87,    87,    77,    39,
      51,    25,    26,    71,    72,    73,    74,    22,    18,     3,
      66,    87,    19,    37,    80,    82,    11,    14,    16,    62,
      80,    37,    33,     3,     3,    80,    77,    34,    52,    73,
      34,    12,    14,     3,    21,    75,    76,     3,    77,    52,
      34,     5,     9,    75,    60,    34,    77
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    53,    54,    55,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    62,    63,    64,    64,    64,    65,
      65,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    74,    74,    75,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    80,    80,    81,    81,    82,    83,    83,    83,
      84,    84,    84,    84,    84,    84,    84,    85,    85,    85,
      86,    86,    86,    87,    87,    87,    87,    87,    88,    89,
      89,    89,    90,    90,    90,    91,    91,    91
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     2,     3,     3,     0,     3,     1,     2,     0,
       3,     1,     2,     5,     1,     3,     1,     3,     5,     1,
       3,     3,     1,     3,     0,     3,     1,     2,     6,     8,
       0,     1,     1,     3,     4,     1,     1,     4,     0,     3,
       1,     3,     3,     1,     5,     7,     9,     5,     1,     1,
       2,     4,     1,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     1,     1,     1,     1,     4,     0,
       1,     3,     1,     1,     1,     1,     3,     4
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"identificador\"",
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
  "lista_declaracao_variavel", "declaracao_variavel", "inicializacao",
  "declaracao_tipo", "descritor_tipo", "tipo_campos", "tipo_campo",
  "tipo_constantes", "lista_declaracao_de_funcao",
  "lista_declaracao_funcao", "declaracao_funcao", "lista_de_args",
  "lista_args", "args", "modificador", "corpo",
  "lista_declaracao_de_variavel_local", "lista_comandos", "comando",
  "chamada_de_procedimento", "expr", "criacao_de_registro",
  "atribuicao_registro", "expressao_logica", "expressao_relacional",
  "expressao_aritmetica", "termo", "fator", "chamada_de_funcao",
  "lista_args_chamada", "literal", "local", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   149,   149,   153,   159,   163,   164,   168,   169,   173,
     174,   178,   179,   183,   187,   191,   195,   196,   197,   201,
     202,   206,   210,   211,   215,   216,   220,   221,   225,   226,
     230,   231,   235,   236,   240,   244,   245,   249,   254,   255,
     259,   260,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   276,   281,   282,   286,   287,   291,   295,   296,   297,
     301,   302,   303,   304,   305,   306,   307,   311,   312,   313,
     317,   318,   319,   323,   324,   325,   326,   327,   331,   335,
     336,   337,   341,   342,   343,   347,   348,   349
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
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

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
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
    // Last valid token kind.
    const int code_max = 307;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 45 "parser.yy"
} // Simples
#line 1771 "/home/dudu/compiladores/projeto/compilador-simples/build/parser.cc"

#line 352 "parser.yy"


namespace Simples {
   void Parser::error(const location&, const string& m) {
        cerr << *driver.location_ << ": " << m << endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
