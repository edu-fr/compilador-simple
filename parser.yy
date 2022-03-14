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
%start programa

%union
{
 /* YYLTYPE */
  int  			      integerVal;
  double 			    doubleVal;
  std::string*		stringVal;
}

/* Tokens */
%token <stringVal> 	IDENTIFICADOR   "identificador"
%token              FUNCAO          "função"
%token              ACAO            "ação"
%token              PARE            "pare"
%token              CONTINUE        "continue"
%token              PARA            "para"
%token              FPARA           "fpara"
%token              ENQUANTO        "enquanto"
%token              FENQUANTO       "fenquanto"
%token              FACA            "faça"
%token              SE              "se"
%token              FSE             "fse"
%token              VERDADEIRO      "verdadeiro"
%token              FALSO           "falso" 
%token              TIPO            "tipo" 
%token              DE              "de"  
%token              LIMITE          "limite" 
%token              GLOBAL          "global"  
%token              LOCAL           "local"
%token <integerVal> INTEIRO		      "inteiro"
%token <doubleVal> 	REAL		        "real"
%token <stringVal>  CADEIA          "cadeia"
%token              VALOR           "valor"
%token              REF             "ref" 
%token              RETORNE         "retorne"  
%token              NULO            "nulo"   
%token              INICIO          "início" 
%token              FIM             "fim" 
%token              TOK_EOF 0       "end of file"
%token			        EOL		          "end of line"
%token              COMENTARIO      "comentário"
%token              SIMBOLO         "simbolo"
%token              MAIS            '+'
%token              MENOS           '-'
%token              BARRA           '/'
%token              ASTERISCO       '*'
%token              VIRGULA         ','
%token              DOISPONTOS      ':'
%token              PONTOEVIRGULA   ';'
%token              ABREPARENTESES  '('
%token              FECHAPARENTESES ')'
%token              ABRECOLCHETES   '['
%token              FECHACOLCHETES  ']'
%token              ABRECHAVES      '{'
%token              FECHACHAVES     '}'
%token              PONTO           '.'
%token              IGUAL           '='
%token              DIFERENTE       "!="
%token              MENOR           '<'
%token              MENORIGUAL      "<="
%token              MAIOR           '>'
%token              MAIORIGUAL      ">="
%token              AND             '&'
%token              OR              '|'
%token              ATRIBUICAO      ":="
%token              IGUALFUNCAO     "="
 
%% 

programa: 
  declaracoes
| acao
;

declaracoes: 
  lista_declaracao_de_tipo
  lista_declaracao_de_variavel_global
  lista_declaracao_de_funcao
;

acao:
  ACAO DOISPONTOS lista_comandos
;

lista_declaracao_de_tipo:
  /* empty */ %empty 
| TIPO DOISPONTOS lista_declaracao_tipo
;

lista_declaracao_tipo:
  declaracao_tipo
| lista_declaracao_tipo declaracao_tipo
;

lista_declaracao_de_variavel_global:
  /* empty */ %empty 
| GLOBAL DOISPONTOS lista_declaracao_variavel_global  { std::cout << "Global declarada! " << std::endl; }
;

lista_declaracao_variavel_global:
  declaracao_variavel
| lista_declaracao_variavel_global declaracao_variavel
;

declaracao_variavel:
  IDENTIFICADOR DOISPONTOS IDENTIFICADOR ATRIBUICAO inicializacao { std::cout << "Declaracao de variavel! " << std::endl; }
;

inicializacao:
  expr
| ABRECHAVES criacao_de_registro FECHACHAVES
;

criacao_de_registro:
  atribuicao_registro
| criacao_de_registro VIRGULA atribuicao_registro

atribuicao_registro:
  IDENTIFICADOR IGUALFUNCAO expr

declaracao_tipo:
  IDENTIFICADOR IGUALFUNCAO descritor_tipo
;

descritor_tipo:
  IDENTIFICADOR { std::cout << "Declaracao de tipo simples" << std::endl; }  /* (1.1) possível reduce reduce */
| ABRECHAVES tipo_campos FECHACHAVES { std::cout << "Declaracao de tipo: Tipo Campo " << std::endl; }
| ABRECOLCHETES tipo_constantes FECHACOLCHETES DE IDENTIFICADOR { std::cout << "Declaracao de tipo: Tipo constantes " << std::endl;  }
;

tipo_campos:
  tipo_campo
| tipo_campos VIRGULA tipo_campo
;

tipo_campo:
  IDENTIFICADOR DOISPONTOS IDENTIFICADOR
;

tipo_constantes:
  INTEIRO
| tipo_constantes VIRGULA INTEIRO
;

lista_declaracao_de_funcao:
  /* empty */ %empty 
| FUNCAO DOISPONTOS lista_declaracao_funcao 
;

lista_declaracao_funcao:
  declaracao_funcao
| lista_declaracao_funcao declaracao_funcao
;

declaracao_funcao:
  IDENTIFICADOR ABREPARENTESES lista_de_args FECHAPARENTESES IGUALFUNCAO corpo  { std::cout << "Declaracao de procedimento! " << std::endl; }  
| IDENTIFICADOR ABREPARENTESES lista_de_args FECHAPARENTESES DOISPONTOS IDENTIFICADOR IGUALFUNCAO corpo  { std::cout << "Declaracao de funcao! " << std::endl; }
;

lista_de_args: 
  /* empty */ %empty 
| lista_args
;

lista_args:
  args
| lista_args VIRGULA args
;

args:
  modificador IDENTIFICADOR DOISPONTOS IDENTIFICADOR   { std::cout << "Argumento! " << std::endl; }
;

modificador:
  VALOR
| REF
;

corpo:
  lista_declaracao_de_variavel_local
  ACAO DOISPONTOS lista_comandos
;

lista_declaracao_de_variavel_local:
  /* empty */ %empty 
| LOCAL DOISPONTOS lista_declaracao_variavel_local  { std::cout << "Local foi declarada! " << std::endl; }
;

lista_declaracao_variavel_local:
  declaracao_variavel
| lista_declaracao_variavel_local declaracao_variavel
;

lista_comandos: 
  comando
| lista_comandos PONTOEVIRGULA comando  
;

comando:
  local ATRIBUICAO expr
/* | chamada_de_funcao */
| SE expr VERDADEIRO lista_comandos FSE
| SE expr VERDADEIRO lista_comandos FALSO lista_comandos FSE
| PARA IDENTIFICADOR DE expr LIMITE expr FACA lista_comandos FPARA
| ENQUANTO expr FACA lista_comandos FENQUANTO
| PARE
| CONTINUE
| RETORNE expr
;

expr:
  NULO
| expressao_aritmetica
| expressao_logica
;

/* verificar */ 
expressao_logica:
  expressao_logica AND INTEIRO
| expressao_logica OR INTEIRO
| INTEIRO AND INTEIRO
| INTEIRO OR INTEIRO
| ABREPARENTESES expressao_logica FECHAPARENTESES
;


expressao_aritmetica:
  expressao_aritmetica MAIS termo
| expressao_aritmetica MENOS termo
| termo
;

termo:
  termo ASTERISCO fator
| termo BARRA fator
| fator
;

fator:
  ABREPARENTESES expressao_aritmetica FECHAPARENTESES
| numero
| IDENTIFICADOR
;

numero:
  INTEIRO
| REAL
;

local:
  IDENTIFICADOR
| local PONTO IDENTIFICADOR
| local ABRECOLCHETES expr /* lista_expr */ FECHACOLCHETES
;

%%

namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
