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

#define yylex driver.scanner_->yylex


#line 50 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"


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

#line 44 "parser.yy"
namespace Simples {
#line 147 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"


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
  case 11:
#line 153 "parser.yy"
                                                      { std::cout << "Global declarada! " << std::endl; }
#line 643 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 14:
#line 162 "parser.yy"
                                                                  { std::cout << "Declaracao de variavel! " << std::endl; }
#line 649 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 20:
#line 181 "parser.yy"
                { std::cout << "Declaracao de tipo simples" << std::endl; }
#line 655 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 21:
#line 182 "parser.yy"
                                     { std::cout << "Declaracao de tipo: Tipo Campo " << std::endl; }
#line 661 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 22:
#line 183 "parser.yy"
                                                                { std::cout << "Declaracao de tipo: Tipo constantes " << std::endl;  }
#line 667 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 32:
#line 211 "parser.yy"
                                                                                { std::cout << "Declaracao de procedimento! " << std::endl; }
#line 673 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 33:
#line 212 "parser.yy"
                                                                                                         { std::cout << "Declaracao de funcao! " << std::endl; }
#line 679 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 38:
#line 226 "parser.yy"
                                                       { std::cout << "Argumento! " << std::endl; }
#line 685 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 43:
#line 241 "parser.yy"
                                                    { std::cout << "Local foi declarada! " << std::endl; }
#line 691 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 58:
#line 272 "parser.yy"
                                            { std::cout << " AND " << std::endl; }
#line 697 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 59:
#line 273 "parser.yy"
                                           { std::cout << " OR " << std::endl; }
#line 703 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 61:
#line 278 "parser.yy"
                                                       { std::cout << "Maior igual" << std::endl; }
#line 709 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 62:
#line 279 "parser.yy"
                                                       { std::cout << "Menor igual " << std::endl; }
#line 715 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 63:
#line 280 "parser.yy"
                                                  { std::cout << " Menor " << std::endl; }
#line 721 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 64:
#line 281 "parser.yy"
                                                  { std::cout << " Maior " << std::endl; }
#line 727 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 65:
#line 282 "parser.yy"
                                                      { std::cout << " Diferente " << std::endl; }
#line 733 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 66:
#line 283 "parser.yy"
                                                  { std::cout << " Igual " << std::endl; }
#line 739 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 68:
#line 287 "parser.yy"
                                  { std::cout << " Soma " << std::endl; }
#line 745 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 69:
#line 288 "parser.yy"
                                   { std::cout << " Sutracao " << std::endl; }
#line 751 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 71:
#line 293 "parser.yy"
                        { std::cout << " Multiplicacao " << std::endl; }
#line 757 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 72:
#line 294 "parser.yy"
                    { std::cout << " Divisao " << std::endl; }
#line 763 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;

  case 74:
#line 299 "parser.yy"
                                      { std::cout << "Expressao com parenteses " << std::endl; }
#line 769 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"
    break;


#line 773 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"

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


  const signed char Parser::yypact_ninf_ = -52;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
       4,   -24,    -5,    42,   -52,   -52,    44,    65,    48,   -52,
      25,    72,   -52,   -52,   -52,    78,     2,     2,     2,    38,
     -52,   -48,    17,    48,   -52,    96,    57,   -52,    84,   -52,
     -52,   -52,   -52,     2,   100,    92,   -19,    15,    26,    27,
     -52,   -52,   -41,    90,   -52,    65,     2,   103,     2,     3,
     -52,    63,    96,   -52,   106,     2,    60,    39,   -10,   -52,
      65,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    65,   -52,    62,   -52,   -52,   -52,    95,
     115,   -52,   116,   -52,    73,   106,   -52,   101,   -52,     2,
     100,   -52,    -3,    15,    15,    26,    26,    26,    26,    26,
      26,    27,    27,   -52,   -52,    -1,   -52,   -52,   -20,    79,
       5,   -52,    47,    31,   -52,     2,   -52,   -52,   -52,   -52,
      65,   102,   107,   123,   115,   -52,     2,   -52,   -52,    77,
      86,   -52,   126,   118,     0,   -52,   128,   -52,   -52,   -52,
     -52,   -27,    31,    88,    65,   -52,   -52,   130,   113,   -52,
     132,    -2,    64,    94,   -52,   131,   -52,   -52,   113,    96,
      97,   -52,   -52,    96,    65,   -52,    38
  };

  const signed char
  Parser::yydefact_[] =
  {
       6,     0,     0,     0,     2,     3,    10,     0,     0,     1,
       0,    28,    81,    53,    54,     0,     0,     0,     0,     5,
      46,     0,     0,     7,     8,     0,     0,     4,     0,    78,
      79,    80,    77,     0,     0,     0,    56,    60,    67,    70,
      73,    75,    76,     0,    55,     0,     0,     0,     0,     0,
       9,     0,    11,    12,     0,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,    82,    48,    20,     0,
       0,    19,     0,    13,     0,    29,    30,     0,    74,     0,
       0,    57,     0,    58,    59,    66,    65,    63,    61,    64,
      62,    68,    69,    72,    71,     0,    83,    26,     0,     0,
       0,    23,     0,    34,    31,     0,    18,    17,    52,    49,
       0,     0,     0,     0,     0,    21,     0,    39,    40,     0,
      35,    36,     0,     0,     0,    27,     0,    25,    24,    14,
      15,     0,     0,     0,     0,    50,    22,     0,    42,    37,
       0,     0,     0,     0,    32,     0,    38,    51,    42,     0,
       0,    33,    44,    43,     0,    45,    41
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -51,   -52,
     -52,    49,   119,   -52,   -52,    19,   -52,   -52,   -52,    59,
     -52,   -52,     6,   -52,   -13,   -52,   -52,   -50,   104,   -15,
     -52,   -33,    23,    28,    24,   -52,    -7
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     3,     4,     5,     6,    23,    11,    52,    53,   139,
      58,    59,    24,    81,   110,   111,   108,    27,    85,    86,
     129,   130,   131,   132,   154,   155,   163,    19,    20,    35,
      36,    37,    38,    39,    40,    41,    42
  };

  const unsigned char
  Parser::yytable_[] =
  {
      21,    83,    43,    44,    46,    12,    78,   157,   118,     1,
      92,    46,    47,   119,   145,   120,    12,   147,    56,    47,
       7,     2,   121,   105,    29,    30,    31,    48,    93,    94,
      32,    75,    90,    77,   122,    29,    30,    31,    21,     8,
      87,    32,     9,    45,    45,    45,    45,   124,    91,   148,
      33,    22,    61,    21,    62,    79,   127,   128,    34,    80,
      69,    33,    70,   125,    10,    71,    21,    72,    12,    25,
     134,    13,    14,    15,   116,    16,    26,    63,    17,    64,
      65,    28,    66,    67,    45,    68,    95,    96,    97,    98,
      99,   100,    18,    49,   151,   103,   104,   101,   102,    51,
     133,    54,    55,    57,    60,    73,    76,    82,   162,    84,
      88,   140,   165,    21,   166,    89,   106,   107,   109,   112,
     115,   113,   126,   123,   135,   136,   137,   141,   142,   143,
     144,   146,   150,   152,   153,   156,   160,    21,   159,   117,
     158,   164,    50,   138,   114,   161,     0,     0,   149,    74,
       0,     0,     0,     0,     0,     0,     0,    21
  };

  const short
  Parser::yycheck_[] =
  {
       7,    52,    17,    18,    52,     3,     3,     9,    11,     5,
      60,    52,    60,    14,    14,    16,     3,    44,    33,    60,
      44,    17,    42,    73,    22,    23,    24,    75,    61,    62,
      28,    46,    42,    48,    54,    22,    23,    24,    45,    44,
      55,    28,     0,    46,    46,    46,    46,    42,    58,    76,
      48,     3,    71,    60,    73,    52,    25,    26,    56,    56,
      34,    48,    36,    58,    20,    38,    73,    40,     3,    44,
     120,     6,     7,     8,    89,    10,     4,    62,    13,    64,
      65,     3,    67,    68,    46,    70,    63,    64,    65,    66,
      67,    68,    27,    76,   144,    71,    72,    69,    70,     3,
     115,    44,    18,     3,    12,    15,     3,    44,   159,     3,
      50,   126,   163,   120,   164,    76,    54,    22,     3,     3,
      19,    48,    75,    44,    22,    18,     3,    50,    42,     3,
      12,     3,    44,     3,    21,     3,     5,   144,    44,    90,
      76,    44,    23,   124,    85,   158,    -1,    -1,   142,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   164
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     5,    17,    78,    79,    80,    81,    44,    44,     0,
      20,    83,     3,     6,     7,     8,    10,    13,    27,   104,
     105,   113,     3,    82,    89,    44,     4,    94,     3,    22,
      23,    24,    28,    48,    56,   106,   107,   108,   109,   110,
     111,   112,   113,   106,   106,    46,    52,    60,    75,    76,
      89,     3,    84,    85,    44,    18,   106,     3,    87,    88,
      12,    71,    73,    62,    64,    65,    67,    68,    70,    34,
      36,    38,    40,    15,   105,   106,     3,   106,     3,    52,
      56,    90,    44,    85,     3,    95,    96,   106,    50,    76,
      42,    58,   104,   108,   108,   109,   109,   109,   109,   109,
     109,   110,   110,   111,   111,   104,    54,    22,    93,     3,
      91,    92,     3,    48,    96,    19,   106,    88,    11,    14,
      16,    42,    54,    44,    42,    58,    75,    25,    26,    97,
      98,    99,   100,   106,   104,    22,    18,     3,    92,    86,
     106,    50,    42,     3,    12,    14,     3,    44,    76,    99,
      44,   104,     3,    21,   101,   102,     3,     9,    76,    44,
       5,   101,    85,   103,    44,    85,   104
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    77,    78,    78,    79,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    86,    87,    87,    88,    89,
      90,    90,    90,    91,    91,    92,    93,    93,    94,    94,
      95,    95,    96,    96,    97,    97,    98,    98,    99,   100,
     100,   101,   102,   102,   103,   103,   104,   104,   105,   105,
     105,   105,   105,   105,   105,   105,   106,   106,   107,   107,
     107,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     109,   110,   110,   110,   111,   111,   111,   111,   112,   112,
     112,   113,   113,   113
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     3,     3,     0,     3,     1,     2,
       0,     3,     1,     2,     5,     1,     1,     3,     3,     3,
       1,     3,     5,     1,     3,     3,     1,     3,     0,     3,
       1,     2,     6,     8,     0,     1,     1,     3,     4,     1,
       1,     4,     0,     3,     1,     2,     1,     3,     3,     5,
       7,     9,     5,     1,     1,     2,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     4
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
  "\"simbolo\"", "MAIS", "'+'", "MENOS", "'-'", "BARRA", "'/'",
  "ASTERISCO", "'*'", "VIRGULA", "','", "DOISPONTOS", "':'",
  "PONTOEVIRGULA", "';'", "ABREPARENTESES", "'('", "FECHAPARENTESES",
  "')'", "ABRECOLCHETES", "'['", "FECHACOLCHETES", "']'", "ABRECHAVES",
  "'{'", "FECHACHAVES", "'}'", "PONTO", "'.'", "IGUAL", "'='", "\"!=\"",
  "MENOR", "'<'", "\"<=\"", "MAIOR", "'>'", "\">=\"", "AND", "'&'", "OR",
  "'|'", "\":=\"", "\"=\"", "$accept", "programa", "declaracoes", "acao",
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
  "literal", "local", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   127,   127,   128,   132,   138,   142,   143,   147,   148,
     152,   153,   157,   158,   162,   166,   170,   171,   174,   177,
     181,   182,   183,   187,   188,   192,   196,   197,   201,   202,
     206,   207,   211,   212,   216,   217,   221,   222,   226,   230,
     231,   235,   240,   241,   245,   246,   250,   251,   255,   257,
     258,   259,   260,   261,   262,   263,   267,   268,   272,   273,
     274,   278,   279,   280,   281,   282,   283,   284,   287,   288,
     289,   293,   294,   295,   299,   300,   301,   302,   306,   307,
     308,   312,   313,   314
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
       2,     2,     2,     2,     2,     2,     2,     2,    72,     2,
      49,    51,    41,    35,    43,    37,    61,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    47,
      66,    63,    69,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,    74,    59,     2,     2,     2,     2,
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
      36,    38,    40,    42,    44,    46,    48,    50,    52,    54,
      56,    58,    60,    62,    64,    65,    67,    68,    70,    71,
      73,    75,    76
    };
    const int user_token_number_max_ = 312;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 44 "parser.yy"
} // Simples
#line 1335 "/home/lipe/Documentos/Compiladores/compilador-simples/make2/parser.cc"

#line 317 "parser.yy"


namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
