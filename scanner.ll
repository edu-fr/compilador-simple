%{ /* -*- C++ -*- */

#include "parser.hh"
#include "scanner.hh"
#include "driver.hh"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

/*  Defines some macros to update locations */
#define STEP() do {driver.location_->step();} while (0)
#define COL(col) driver.location_->columns(col)
#define LINE(line) do {driver.location_->lines(line);} while (0)
#define YY_USER_ACTION COL(yyleng);
#define MAX_STR_CONST 1024

/* import the parser's token type into a local typedef */
typedef Simples::Parser::token token;
typedef Simples::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::TOK_EOF

char string_buf[MAX_STR_CONST];
char *string_buf_ptr;

%}

/*** Flex Declarations and Options ***/

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug
/* enable c++ scanner class generation */
%option c++
/* we don’t need yywrap */
%option noyywrap
/* you should not expect to be able to use the program interactively */
%option never-interactive
/* provide the global variable yylineno */
%option yylineno
/* do not fabricate input text to be scanned */
%option nounput
/* the manual says "somewhat more optimized" */
%option batch
/* change the name of the scanner class. results in "SimplesFlexLexer" */
%option prefix="Simples"
/* caseless */
%option caseless


/*
%option stack
*/

/* Abbreviations.  */

blank   [ ]+
tab     [\t]+
bl      [\n]+
eol     [\n\r]+
simbolo [,.-':;!@#$%&*()]

/* Start Conditions */

%x commentStartCond

%x stringStartCond


%%

 /* The following paragraph suffices to track locations accurately. Each time
 yylex is invoked, the begin position is moved onto the end position. */
%{
  STEP();
%}

 /*** BEGIN EXAMPLE - Change the example lexer rules below ***/

[A-Za-z][(A-Za-z)|(0-9)]* {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::IDENTIFICADOR;
}

"pare" {
  return token::PARE;
}

"continue" {
  return token::CONTINUE;
}

"para" {
  return token::PARA;
}

"fpara" {
  return token::FPARA;
}

"enquanto" {
  return token::ENQUANTO;
}

"fenquanto" {
  return token::ENQUANTO;
}

"faça" {
  return token::FACA;
}

"fa"(Ç|ç)"ça" {
  return token::FACA;
}


"se" {
  return token::SE;
}

"fse" {
  return token::FSE;
}

"verdadeiro" {
  return token::VERDADEIRO;
}

"falso" {
  return token::FALSO;
}

"tipo" {
  return token::TIPO;
}

"de" {
  return token::DE;
}

"limite" {
  return token::LIMITE;
}

"global" {
  return token::GLOBAL;
}

"local" {
  return token::LOCAL;
}

[0-9]+ {
     yylval->integerVal = atoi(yytext);
     return token::INTEIRO;
 }

[0-9]+[.][0-9]* {
  yylval->doubleVal = atof(yytext);
  return token::REAL;
}

<stringStartCond>\" {       /* Encontrou o fecha aspas - terminou */
  BEGIN(INITIAL);
  *string_buf_ptr = '\0';
  return token::CADEIA;
}

"valor" {
  return token::VALOR;
}

"ref" {
  return token::REF;
}

"retorne" {
  return token::RETORNE;
}

"nulo" {
  return token::NULO;
}

"in"(í|Í)"cio" {
  return token::INICIO;
}

"fim" {
  return token::FIM;
}

"+" { return token::MAIS; }
"-" { return token::MENOS; }
"/" { return token::BARRA; }
"*" { return token::ASTERISCO; }
":" { return token::DOISPONTOS; }
";" { return token::PONTOEVIRGULA; }
"(" { return token::ABREPARENTESES; }
")" { return token::FECHAPARENTESES; }
"[" { return token::ABRECOLCHETES; }
"]" { return token::FECHACOLCHETES; }
"{" { return token::ABRECHAVES; }
"}" { return token::FECHACHAVES; }
"." { return token::PONTO; }
"==" { return token::IGUAL; }
"!=" { return token::DIFERENTE; }
"<" { return token::MENOR; }
"<=" { return token::MENORIGUAL; }
">" { return token::MAIOR; }
">=" { return token::MAIORIGUAL; }
"&" { return token::AND; }
"|" { return token::OR; }
":=" { return token::ATRIBUICAO; }
"=" { return token::IGUALFUNCAO; }

"/*"  BEGIN(commentStartCond);

<commentStartCond>[^*\n]*         /* Tira tudo o que nao eh um '*'                   */ 
<commentStartCond>"*"+[^*/\n]*    /* Tira todos os '*' que nao sao seguidos por '/'s */
<commentStartCond>\n              /* Pula linha                                      */
<commentStartCond>"*"+"/" {       /* Fim do comentario                               */
  BEGIN(INITIAL);
  return token::COMENTARIO;
}

\" string_buf_ptr = string_buf; BEGIN(stringStartCond);

{blank} { STEP(); }
{tab}   { STEP(); }
{bl}    { STEP(); }
{eol}   { LINE(yyleng); }

.             {
                std::cerr << *driver.location_ << " Unexpected token : "
                                              << *yytext << std::endl;
                driver.error_ = (driver.error_ == 127 ? 127
                                : driver.error_ + 1);
                STEP ();
              }

%%

/* CUSTOM C++ CODE */

namespace Simples {

  Scanner::Scanner() : SimplesFlexLexer() {}

  Scanner::~Scanner() {}

  void Scanner::set_debug(bool b) {
    yy_flex_debug = b;
  }
}

#ifdef yylex
# undef yylex
#endif

int SimplesFlexLexer::yylex()
{
  std::cerr << "call parsepitFlexLexer::yylex()!" << std::endl;
  return 0;
}
