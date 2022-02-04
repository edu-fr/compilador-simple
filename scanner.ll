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
#define MAX_DOUBLE_CONST 1024

/* import the parser's token type into a local typedef */
typedef Simples::Parser::token token;
typedef Simples::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::TOK_EOF

char string_buf[MAX_STR_CONST];
char *string_buf_ptr;
std::string* double_buf_ptr;
std::string double_buf;
char double_char_array[MAX_DOUBLE_CONST];

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

/*
%option stack
*/

/* Abbreviations.  */

blank   [ \t]+
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

[0-9]+ {
     yylval->integerVal = atoi(yytext);
     return token::INTEGER;
 }

[0-9]+[,][0-9]* {
  double_buf_ptr = new std::string(yytext, yyleng);
  double_buf = *double_buf_ptr;
  std::replace(double_buf.begin(), double_buf.end(), ',', '.');
  strcpy(double_char_array, double_buf.c_str());
  yylval->doubleVal = atof(double_char_array);
  return token::REAL;
}

[A-Za-z][A-Za-z[0-9],.-]* {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::IDENTIFIER;
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

"enquanto" {
  return token::ENQUANTO;
}

"faca" {
  return token::FACA;
}

"fun" {
  return token::FUN;
}

"se" {
  return token::SE;
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

"var" {
  return token::VAR;
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

"inicio" {
  return token::INICIO;
}

"fim" {
  return token::FIM;
}

"/*"  BEGIN(commentStartCond);

<commentStartCond>[^*\n]*         /* Tira tudo o que nao eh um '*'                   */ 
<commentStartCond>"*"+[^*/\n]*    /* Tira todos os '*' que nao sao seguidos por '/'s */
<commentStartCond>\n              /* Pula linha                                      */
<commentStartCond>"*"+"/" {       /* Fim do comentario                               */
  BEGIN(INITIAL);
  return token::COMMENT;
}


\" string_buf_ptr = string_buf; BEGIN(stringStartCond);

<stringStartCond>\" {             /* Encontrou o fecha aspas - terminou */
  BEGIN(INITIAL);
  *string_buf_ptr = '\0';
  return token::CADEIA;
}

{blank} { STEP(); }

{eol}  { LINE(yyleng); }

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
