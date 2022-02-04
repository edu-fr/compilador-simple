/*
 * PARSER
 */

%{

/*** C++ Declarations ***/
#include "parser.hh"
#include "scanner.hh"

#define yylex driver.scanner_->yylex

%}

%code requires {
  #include <iostream>
  #include "driver.hh"
  #include "location.hh"
  #include "position.hh"
}

%code provides {
  namespace Simples  {
    // Forward declaration of the Driver class
    class Driver;

    inline void yyerror (const char* msg) {
      std::cerr << msg << std::endl;
    }
  }
}

/* Require bison 2.3 or later */
%require "2.4"
/* enable c++ generation */
%language "C++"
%locations
/* write out a header file containing the token defines */
%defines
/* add debug output code to generated parser. disable this for release
 * versions. */
%debug
/* namespace to enclose parser in */
%define api.namespace {Simples}
/* set the parser's class identifier */
%define api.parser.class {Parser}
/* set the parser */
%parse-param {Driver &driver}
/* set the lexer */
%lex-param {Driver &driver}
/* verbose error messages */
%define parse.error verbose
/* use newer C++ skeleton file */
%skeleton "lalr1.cc"
/* Entry point of grammar */
%start program

%union
{
 /* YYLTYPE */
  int  			      integerVal;
  double 			    doubleVal;
  std::string*		stringVal;
}

/* Tokens */
%token              TOK_EOF 0     "end of file"
%token			        EOL		        "end of line"
%token <integerVal> INTEGER		    "integer"
%token <doubleVal> 	REAL		      "real"
%token <stringVal> 	IDENTIFIER    "identifier"
%token <stringVal>  CADEIA        "cadeia"
%token              COMMENT       "comment"
%token              PARE          "pare"
%token              CONTINUE      "continue"
%token              PARA          "para"
%token              ENQUANTO      "enquanto"
%token              FACA          "faça" 
%token              FUN           "fun"
%token              SE            "se"
%token              VERDADEIRO    "verdadeiro"
%token              FALSO         "falso" 
%token              TIPO          "tipo" 
%token              DE            "de"  
%token              LIMITE        "limite" 
%token              VAR           "var" 
%token              REF           "ref" 
%token              RETORNE       "retorne"  
%token              NULO          "nulo"   
%token              INICIO        "inicio" 
%token              FIM           "fim" 

%%

program:  /* empty */
        | constant
        | variable
        | cadeia
        | comment
        | reserved

constant : INTEGER { std::cout << "Inteiro: " << $1 << std::endl; }
         | REAL  { std::cout << "Real: " << $1 << std::endl; }

variable : IDENTIFIER {  std::cout << "Identificador: " << *$1 << std::endl; }

cadeia : CADEIA { std::cout << "Cadeia: " << *$1 << std::endl; }

comment : COMMENT { std::cout << "Comentario! " << std::endl; }

reserved : PARE { std::cout << "Pare!" << std::endl; }
         | CONTINUE { std::cout << "Continue!" << std::endl; }
         | PARA { std::cout << "Para!" << std::endl; }
         | ENQUANTO { std::cout << "Enquanto!" << std::endl; }
         | FACA { std::cout << "Faça!" << std::endl; }
         | FUN { std::cout << "Fun!" << std::endl; }
         | SE { std::cout << "Se!" << std::endl; }
         | VERDADEIRO { std::cout << "Verdadeiro!" << std::endl; }
         | FALSO { std::cout << "Falso!" << std::endl; }
         | TIPO { std::cout << "Tipo!" << std::endl; }
         | DE { std::cout << "De!" << std::endl; }  
         | LIMITE { std::cout << "Limite!" << std::endl; }  
         | VAR { std::cout << "Var!" << std::endl; }  
         | REF { std::cout << "Ref!" << std::endl; }  
         | RETORNE { std::cout << "Retorne!" << std::endl; }  
         | NULO { std::cout << "Nulo!" << std::endl; }  
         | INICIO { std::cout << "Inicio!" << std::endl; }  
         | FIM { std::cout << "Fim!" << std::endl; }  

%%

namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
