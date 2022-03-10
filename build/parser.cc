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


#line 50 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"


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
#line 147 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"


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
  case 9:
#line 148 "parser.yy"
                                                      { std::cout << "Global declarada! " << std::endl; }
#line 643 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 12:
#line 155 "parser.yy"
                                                                  { std::cout << "Declaracao de variavel! " << std::endl; }
#line 649 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 16:
#line 166 "parser.yy"
                { std::cout << "Declaracao de tipo simples" << std::endl; }
#line 655 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 17:
#line 167 "parser.yy"
                                     { std::cout << "Declaracao de tipo: Tipo Campos " << std::endl; }
#line 661 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 18:
#line 168 "parser.yy"
                                                                { std::cout << "Declaracao de tipo: Tipo constantes " << std::endl;  }
#line 667 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 28:
#line 190 "parser.yy"
                                                                     { std::cout << "Declaracao de procedimento! " << std::endl; }
#line 673 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 29:
#line 191 "parser.yy"
                                                                                              { std::cout << "Declaracao de funcao! " << std::endl; }
#line 679 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 34:
#line 202 "parser.yy"
                                                       { std::cout << "Argumento! " << std::endl; }
#line 685 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 39:
#line 215 "parser.yy"
                                                    { std::cout << "Local foi declarada! " << std::endl; }
#line 691 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 68:
#line 267 "parser.yy"
             { std:: cout << "Operacao de soma realizada! " << std::endl; }
#line 697 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 69:
#line 268 "parser.yy"
              { std:: cout << "Operacao de subtracao realizada! " << std::endl; }
#line 703 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 70:
#line 269 "parser.yy"
                  { std:: cout << "Operacao de multiplicacao realizada! " << std::endl; }
#line 709 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;

  case 71:
#line 270 "parser.yy"
              { std:: cout << "Operacao de divisao realizada! " << std::endl; }
#line 715 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"
    break;


#line 719 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"

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


  const signed char Parser::yypact_ninf_ = -102;

  const signed char Parser::yytable_ninf_ = -75;

  const short
  Parser::yypact_[] =
  {
       2,   -31,    25,  -102,     9,    38,  -102,     4,    45,   -20,
    -102,     7,    56,    14,  -102,    -1,     2,    17,  -102,    16,
      11,  -102,    49,    70,  -102,  -102,    72,     9,  -102,  -102,
    -102,  -102,    37,    40,  -102,   -36,    41,   -34,  -102,    19,
    -102,    45,    -9,    64,    81,    89,    70,  -102,    -2,  -102,
    -102,  -102,    58,  -102,    76,   103,  -102,   109,  -102,  -102,
      36,    55,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
      75,  -102,  -102,  -102,  -102,  -102,   -37,    -9,    73,  -102,
      61,    11,    11,    11,    11,   111,    95,  -102,   117,  -102,
    -102,  -102,  -102,  -102,    46,    77,  -102,   118,  -102,    95,
      56,    82,  -102,    79,  -102,    74,    95,   -25,  -102,  -102,
     124,     8,     8,     8,    83,  -102,  -102,   -23,  -102,  -102,
     110,   119,   115,  -102,    97,   129,     8,     8,    74,    74,
    -102,  -102,  -102,  -102,  -102,   114,    -8,    -4,     8,  -102,
    -102,    74,   122,     1,    74,  -102,     0,  -102
  };

  const signed char
  Parser::yydefact_[] =
  {
       4,     0,     0,     2,     8,     0,     1,     0,    24,     0,
       5,     6,     0,     0,     3,     0,     4,     0,     9,    10,
       0,    16,     0,     0,    15,     7,     0,     8,    72,    73,
      74,    25,    26,     0,    22,     0,     0,     0,    19,     0,
      11,    24,    30,     0,     0,     0,     0,    17,    66,    27,
      35,    36,     0,    31,    32,     0,    23,     0,    21,    20,
      79,    80,    81,    58,    75,    12,    13,    54,    55,    56,
       0,    57,    59,    60,    61,    62,     0,    30,     0,    18,
       0,     0,     0,     0,     0,     0,    38,    33,     0,    14,
      68,    69,    71,    70,     0,     0,    28,     0,    34,    38,
       0,     0,    29,    40,    39,    66,    38,    72,    51,    52,
       0,    66,    66,    66,    37,    43,    44,     0,    46,    41,
       0,     0,     0,    53,    77,     0,    66,    66,    66,    66,
      63,    42,    46,    64,    45,     0,     0,     0,    66,    50,
      47,    66,     0,     0,    66,    48,     0,    49
  };

  const signed char
  Parser::yypgoto_[] =
  {
    -102,  -102,  -102,   120,  -102,   108,  -102,    39,  -102,  -102,
    -102,  -102,    91,  -102,    99,  -102,  -102,    65,  -102,  -102,
    -102,    42,    32,  -102,   -84,    20,   -48,  -102,  -102,  -102,
    -102,   -15,    84,  -102,  -101,  -102,  -102
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,    10,     8,    18,    19,    65,    11,
      24,    37,    38,    35,    14,    31,    32,    52,    53,    54,
      55,    96,    97,   104,   114,   115,   116,   117,    67,    68,
      69,    70,    71,    72,    73,    74,    75
  };

  const short
  Parser::yytable_[] =
  {
      66,    28,    21,   139,   118,    33,    43,    85,    46,   147,
     140,    28,   141,     5,    28,   145,    50,    51,    44,     1,
      60,    61,    62,   132,    47,     6,    63,   118,   118,     7,
      60,    61,    62,    29,    30,   -63,    63,   125,   124,    86,
     118,     9,   124,   118,   136,   137,   124,   124,    12,    13,
     -63,    22,   126,    16,    64,    23,    15,   143,    20,    17,
     146,    26,    27,   121,   122,   123,    90,    91,    92,    93,
     -73,    34,   -73,    36,   -73,    39,   -73,   107,   134,   135,
     108,   109,   110,    41,   111,    45,    56,   112,    42,   -74,
     142,   -74,    58,   -74,    48,   -74,    60,    61,    62,    57,
     130,   113,    63,   108,   109,   110,    78,   111,    76,    81,
     112,    82,    79,    83,    94,    84,    95,    88,    77,    89,
      98,   100,    99,   101,   113,   106,   105,   120,   127,   124,
     129,   128,   133,   138,   144,    40,    25,    59,   119,   103,
      49,   102,    87,     0,   131,     0,     0,     0,    80
  };

  const short
  Parser::yycheck_[] =
  {
      48,     3,     3,    11,   105,    20,    42,    44,    42,     9,
      14,     3,    16,    44,     3,    14,    25,    26,    54,    17,
      22,    23,    24,   124,    58,     0,    28,   128,   129,    20,
      22,    23,    24,    22,    23,    60,    28,    60,    46,    76,
     141,     3,    46,   144,   128,   129,    46,    46,    44,     4,
      75,    52,    75,    46,    56,    56,    76,   141,    44,     3,
     144,    44,    46,   111,   112,   113,    81,    82,    83,    84,
      34,    22,    36,     3,    38,     3,    40,     3,   126,   127,
       6,     7,     8,    46,    10,    44,    22,    13,    48,    34,
     138,    36,     3,    38,    75,    40,    22,    23,    24,    18,
       3,    27,    28,     6,     7,     8,     3,    10,    50,    34,
      13,    36,     3,    38,     3,    40,    21,    44,    42,    58,
       3,    44,    76,     5,    27,    46,    44,     3,    18,    46,
      15,    12,     3,    19,    12,    27,    16,    46,   106,   100,
      41,    99,    77,    -1,   124,    -1,    -1,    -1,    64
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    17,    78,    79,    80,    44,     0,    20,    82,     3,
      81,    86,    44,     4,    91,    76,    46,     3,    83,    84,
      44,     3,    52,    56,    87,    80,    44,    46,     3,    22,
      23,    92,    93,   108,    22,    90,     3,    88,    89,     3,
      82,    46,    48,    42,    54,    44,    42,    58,    75,    91,
      25,    26,    94,    95,    96,    97,    22,    18,     3,    89,
      22,    23,    24,    28,    56,    85,   103,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    50,    42,     3,     3,
     109,    34,    36,    38,    40,    44,    76,    94,    44,    58,
     108,   108,   108,   108,     3,    21,    98,    99,     3,    76,
      44,     5,    98,    84,   100,    44,    46,     3,     6,     7,
       8,    10,    13,    27,   101,   102,   103,   104,   111,    99,
       3,   103,   103,   103,    46,    60,    75,    18,    12,    15,
       3,   102,   111,     3,   103,   103,   101,   101,    19,    11,
      14,    16,   103,   101,    12,    14,   101,     9
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    77,    78,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    85,    85,    86,    87,    87,    87,    88,
      88,    89,    90,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    97,    97,    98,    99,    99,
     100,   100,   101,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   104,   104,   104,   105,   106,   107,   107,
     107,   107,   108,   108,   108,   109,   110,   111,   112,   113,
     113,   113
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     3,     0,     3,     1,     3,     0,     3,
       1,     3,     5,     1,     3,     3,     1,     3,     5,     1,
       3,     3,     1,     3,     0,     3,     1,     3,     6,     8,
       0,     1,     1,     3,     4,     1,     1,     4,     0,     3,
       1,     3,     3,     1,     1,     3,     1,     5,     7,     9,
       5,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     0,     0,     3,     3,
       3,     3,     1,     1,     1,     0,     0,     0,     0,     1,
       1,     1
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
  "MENOR", "'<'", "\"<=\"", "MAIOR", "'>'", "\">=\"", "AND", "'^'", "OR",
  "'|'", "\":=\"", "\"=\"", "$accept", "programa", "declaracoes",
  "lista_declaracao_de_tipo", "lista_declaracao_tipo",
  "lista_declaracao_de_variavel_global",
  "lista_declaracao_variavel_global", "declaracao_variavel",
  "inicializacao", "declaracao_tipo", "descritor_tipo", "tipo_campos",
  "tipo_campo", "tipo_constantes", "lista_declaracao_de_funcao",
  "lista_declaracao_funcao", "declaracao_funcao", "lista_de_args",
  "lista_args", "args", "modificador", "corpo",
  "lista_declaracao_de_variavel_local", "lista_declaracao_variavel_local",
  "lista_comandos", "comando", "expr", "local", "expressao_logica",
  "expressao_relacional", "expressao_aritmetica", "id",
  "criacao_de_registro", "expressao_com_parenteses", "chamada_de_funcao",
  "local_de_armazenamento", "literal", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   128,   128,   133,   138,   140,   143,   144,   146,   148,
     151,   152,   155,   159,   160,   163,   166,   167,   168,   171,
     172,   175,   178,   179,   181,   183,   186,   187,   190,   191,
     193,   195,   198,   199,   202,   206,   207,   210,   213,   215,
     218,   219,   223,   224,   225,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   253,   254,   255,   258,   262,   267,   268,
     269,   270,   274,   275,   276,   278,   282,   286,   290,   295,
     296,   297
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
      49,    51,    41,    35,    43,    37,    61,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    47,
      66,    63,    69,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    55,    72,     2,     2,     2,     2,     2,
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
#line 1273 "/home/dudu/Documentos/Facul/compiladores/projeto/compilador-simples/build/parser.cc"

#line 300 "parser.yy"


namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
