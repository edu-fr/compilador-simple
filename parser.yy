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

%type               expressao_aritmetica 
/* Tokens */
%token <stringVal> 	IDENTIFICADOR   "identificador"
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
%token              AND             '^'
%token              OR              '|'
%token              ATRIBUICAO      ":="
%token              IGUALFUNCAO     "="
 
%% 

programa: 
  declaracoes
;

declaracoes:
  /* empty */
  lista_declaracao_de_tipo
  lista_declaracao_de_variavel
| declaracao_variavel
;

lista_declaracao_de_tipo:
  /* empty */
  lista_declaracoes_tipo

lista_declaracoes_tipo:
   declaracao_tipo
|  declaracao_tipo PONTOEVIRGULA lista_declaracoes_tipo

lista_declaracao_de_variavel:
  /* empty */
  lista_declaracao_variavel

lista_declaracao_variavel:
  declaracao_variavel
| declaracao_variavel PONTOEVIRGULA lista_declaracao_de_variavel 

declaracao_variavel:
  IDENTIFICADOR DOISPONTOS IDENTIFICADOR ATRIBUICAO inicializacao
;

inicializacao:
  expr
| ABRECHAVES criacao_de_registro FECHACHAVES

declaracao_tipo:
  IDENTIFICADOR IGUALFUNCAO descritor_tipo

descritor_tipo:
  IDENTIFICADOR
| ABRECHAVES tipo_campos FECHACHAVES
| ABRECOLCHETES tipo_constantes FECHACOLCHETES DE IDENTIFICADOR

tipo_campos:
  tipo_campo
| tipo_campos VIRGULA tipo_campo

tipo_campo:
  IDENTIFICADOR DOISPONTOS IDENTIFICADOR

tipo_constantes:
  IDENTIFICADOR
| tipo_constantes VIRGULA IDENTIFICADOR


acao:
  lista_comandos
;

lista_comandos: 
  lista_comandos PONTOEVIRGULA comando  
| comando
| expr
;

comando:
  local ATRIBUICAO expr
| chamada_de_funcao
| SE expr VERDADEIRO lista_comandos FSE
| SE expr VERDADEIRO lista_comandos FALSO lista_comandos FSE
| PARA IDENTIFICADOR DE expr LIMITE expr FACA lista_comandos FPARA
| ENQUANTO expr FACA lista_comandos FENQUANTO
| PARE
| CONTINUE
| RETORNE expr
;

expr:
  expressao_logica
| expressao_relacional
| expressao_aritmetica
| criacao_de_registro
| NULO
| expressao_com_parenteses
| chamada_de_funcao
| local_de_armazenamento
| literal
;

local:
  IDENTIFICADOR
| local PONTO IDENTIFICADOR
| local [list_expr]


expressao_logica:

;

expressao_relacional:

;

expressao_aritmetica:
  id MAIS id { }
| id MENOS id {  }
| id ASTERISCO id {  }
| id BARRA id {  }
;

id:
  IDENTIFICADOR
| INTEIRO
| REAL

criacao_de_registro:

;

expressao_com_parenteses:

;

chamada_de_funcao:

;

local_de_armazenamento:

;

literal:
  INTEIRO
| REAL  
| CADEIA
;

%%

namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
