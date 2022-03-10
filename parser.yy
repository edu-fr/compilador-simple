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
  lista_declaracao_de_variavel_global
  lista_declaracao_de_funcao
;

lista_declaracao_de_tipo:
  /* empty */
| TIPO DOISPONTOS lista_declaracao_tipo

lista_declaracao_tipo:
   declaracao_tipo
|  declaracao_tipo PONTOEVIRGULA lista_declaracao_de_tipo 

lista_declaracao_de_variavel_global:
  /* empty */
| GLOBAL DOISPONTOS lista_declaracao_variavel_global  { std::cout << "Global declarada! " << std::endl; }

lista_declaracao_variavel_global:
  declaracao_variavel
| declaracao_variavel PONTOEVIRGULA lista_declaracao_de_variavel_global 

declaracao_variavel:
  IDENTIFICADOR DOISPONTOS IDENTIFICADOR ATRIBUICAO inicializacao { std::cout << "Declaracao de variavel! " << std::endl; }
;

inicializacao:
  expr
| ABRECHAVES criacao_de_registro FECHACHAVES

declaracao_tipo:
  IDENTIFICADOR IGUALFUNCAO descritor_tipo

descritor_tipo:
  IDENTIFICADOR { std::cout << "Declaracao de tipo simples" << std::endl; }  /* (1.1) possível reduce reduce */
| ABRECHAVES tipo_campos FECHACHAVES { std::cout << "Declaracao de tipo: Tipo Campo " << std::endl; }
| ABRECOLCHETES tipo_constantes FECHACOLCHETES DE IDENTIFICADOR { std::cout << "Declaracao de tipo: Tipo constantes " << std::endl;  }

tipo_campos:
  tipo_campo
| tipo_campos VIRGULA tipo_campo

tipo_campo:
  IDENTIFICADOR DOISPONTOS IDENTIFICADOR

tipo_constantes:
  INTEIRO
| tipo_constantes VIRGULA INTEIRO

lista_declaracao_de_funcao:
  /* empty */
| FUNCAO DOISPONTOS lista_declaracao_funcao 

lista_declaracao_funcao:
  declaracao_funcao
| declaracao_funcao PONTOEVIRGULA lista_declaracao_de_funcao

declaracao_funcao:
  IDENTIFICADOR ABREPARENTESES lista_de_args FECHAPARENTESES IGUALFUNCAO corpo  { std::cout << "Declaracao de procedimento! " << std::endl; }  
| IDENTIFICADOR ABREPARENTESES lista_de_args FECHAPARENTESES DOISPONTOS IDENTIFICADOR IGUALFUNCAO corpo  { std::cout << "Declaracao de funcao! " << std::endl; }

lista_de_args: 
  /* empty */ 
| lista_args

lista_args:
  args
| args VIRGULA lista_de_args

args:
  modificador IDENTIFICADOR DOISPONTOS IDENTIFICADOR   { std::cout << "Argumento! " << std::endl; }


modificador:
  VALOR
| REF

corpo:
  lista_declaracao_de_variavel_local
  ACAO DOISPONTOS lista_comandos

lista_declaracao_de_variavel_local:
  /* empty */
| LOCAL DOISPONTOS lista_declaracao_variavel_local  { std::cout << "Local foi declarada! " << std::endl; }

lista_declaracao_variavel_local:
  declaracao_variavel
| declaracao_variavel PONTOEVIRGULA lista_declaracao_de_variavel_local


lista_comandos: 
  comando
| lista_comandos PONTOEVIRGULA comando  
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
  IDENTIFICADOR /* (1.2) possível reduce reduce */
| local PONTO IDENTIFICADOR
/* | local ABRECOLCHETES lista_expr FECHACOLCHETES */


expressao_logica:

;

expressao_relacional:

;

expressao_aritmetica:   /* No lugar de literal deve ser IDENTFICADOR */
  literal MAIS literal { std:: cout << "Operacao de soma realizada! " << std::endl; }
| literal MENOS literal { std:: cout << "Operacao de subtracao realizada! " << std::endl; }
| literal ASTERISCO literal { std:: cout << "Operacao de multiplicacao realizada! " << std::endl; }
| literal BARRA literal { std:: cout << "Operacao de divisao realizada! " << std::endl; }
;

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
