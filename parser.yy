/*
 * PARSER
 */

%{

/*** C++ Declarations ***/
#include "parser.hh"
#include "scanner.hh"
#include "AST_classes.hh"

#define yylex driver.scanner_->yylex

%}

%code requires {
  #include <iostream>
  #include "driver.hh"
  #include "location.hh"
  #include "position.hh"
  #include "AST_classes.hh"
  using namespace std;
}

%code provides {
  namespace Simples  {
    // Forward declaration of the Driver class
    class Driver;

    inline void yyerror (const char* msg) {
      cerr << msg << endl;
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
  int  			  integerVal;
  double 		  doubleVal;
  string*		  stringVal;
  FatorASTptr     fatorVal;
  /* union tipos_literal {
    int inteiro;
    double pontofloat;
  } tipos_literal; */
}

/* Nao terminais */
//%type <fatorVal>    fator
//%type <fatorVal>    literal

/* Tokens */
%token <stringVal>  IDENTIFICADOR   "identificador"
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
%token <integerVal> INTEIRO	        "inteiro"
%token <doubleVal>  REAL	        "real"
%token <stringVal>  CADEIA          "cadeia"
%token              VALOR           "valor"
%token              REF             "ref" 
%token              RETORNE         "retorne"  
%token              NULO            "nulo"   
%token              TOK_EOF 0       "end of file"
%token              MAIS            "+"
%token              MENOS           "-"
%token              BARRA           "/"
%token              ASTERISCO       "*"
%token              VIRGULA         ","
%token              DOISPONTOS      ":"
%token              PONTOEVIRGULA   ";"
%token              ABREPARENTESES  "("
%token              FECHAPARENTESES ")"
%token              ABRECOLCHETES   "["
%token              FECHACOLCHETES  "]"
%token              ABRECHAVES      "{"
%token              FECHACHAVES     "}"
%token              PONTO           "."
%token              EQUIVALENTE     "=="
%token              DIFERENTE       "!="
%token              MENOR           "<"
%token              MENORIGUAL      "<="
%token              MAIOR           ">"
%token              MAIORIGUAL      ">="
%token              AND             "&"
%token              OR              "|"
%token              ATRIBUICAO      ":="
%token              IGUAL           "="

%% 

programa:  
  declaracoes
| acao
| literal { }
;

declaracoes: 
  lista_declaracao_de_tipo
  lista_declaracao_de_variavel_global
  lista_declaracao_de_funcao
;

acao:
  ACAO ":" lista_comandos
;

lista_declaracao_de_tipo:
  /* empty */ %empty 
| TIPO ":" lista_declaracao_tipo
;

lista_declaracao_tipo:
  declaracao_tipo
| lista_declaracao_tipo declaracao_tipo
;

lista_declaracao_de_variavel_global:
  /* empty */ %empty 
| GLOBAL ":" lista_declaracao_variavel_global  { cout << "Global declarada! " << endl; }
;

lista_declaracao_variavel_global:
  declaracao_variavel
| lista_declaracao_variavel_global declaracao_variavel
;

declaracao_variavel:
  IDENTIFICADOR ":" IDENTIFICADOR ATRIBUICAO inicializacao { cout << "Declaracao de variavel! " << endl; }
;

inicializacao:
  expr
;

criacao_de_registro:
  atribuicao_registro
| criacao_de_registro "," atribuicao_registro
;

atribuicao_registro:
  IDENTIFICADOR IGUAL expr
;

declaracao_tipo:
  IDENTIFICADOR IGUAL descritor_tipo
;

descritor_tipo:
  IDENTIFICADOR { cout << "Declaracao de tipo simples" << endl; }
| "{" tipo_campos "}" { cout << "Declaracao de tipo: Tipo Campo " << endl; }
| "[" tipo_constantes "]" DE IDENTIFICADOR { cout << "Declaracao de tipo: Tipo constantes " << endl;  }
;

tipo_campos:
  tipo_campo
| tipo_campos "," tipo_campo
;

tipo_campo:
  IDENTIFICADOR ":" IDENTIFICADOR
;

tipo_constantes:
  INTEIRO
| tipo_constantes "," INTEIRO
;

lista_declaracao_de_funcao:
  /* empty */ %empty 
| FUNCAO ":" lista_declaracao_funcao
;

lista_declaracao_funcao:
  declaracao_funcao
| lista_declaracao_funcao declaracao_funcao
;

declaracao_funcao:
  IDENTIFICADOR "(" lista_de_args ")" IGUAL corpo  { cout << "Declaracao de procedimento! " << endl; }
| IDENTIFICADOR "(" lista_de_args ")" ":" IDENTIFICADOR IGUAL corpo  { cout << "Declaracao de funcao! " << endl; }
;

lista_de_args: 
  /* empty */ %empty 
| lista_args
;

lista_args:
  args
| lista_args "," args
;

args:
  modificador IDENTIFICADOR ":" IDENTIFICADOR   { cout << "Argumento! " << endl; }
;

modificador:
  VALOR
| REF
;

corpo:
  lista_declaracao_de_variavel_local
  ACAO ":" lista_comandos
;

lista_declaracao_de_variavel_local:
  /* empty */ %empty 
| LOCAL ":" lista_declaracao_variavel_local  { cout << "Local foi declarada! " << endl; }
;

lista_declaracao_variavel_local:
  declaracao_variavel
| lista_declaracao_variavel_local declaracao_variavel
;

lista_comandos: 
  comando
| lista_comandos ";" comando
;

comando:
  local ATRIBUICAO expr { cout << "atribuição simples" << endl; }
| chamada_de_funcao
| SE expr VERDADEIRO lista_comandos FSE { cout << "SE simples" << endl; }
| SE expr VERDADEIRO lista_comandos FALSO lista_comandos FSE { cout << "SE com FALSO" << endl; }
| PARA IDENTIFICADOR DE expr LIMITE expr FACA lista_comandos FPARA { cout << "PARA" << endl; }
| ENQUANTO expr FACA lista_comandos FENQUANTO { cout << "ENQUANTO" << endl; }
| PARE { cout << "PARE" << endl; }
| CONTINUE { cout << "CONTINUE" << endl; }
| RETORNE expr { cout << "RETORNE" << endl; }
;

expr:
  expressao_logica
| "{" criacao_de_registro "}"
;

expressao_logica:
  expressao_logica "&" expressao_relacional { cout << " AND " << endl; }
| expressao_logica "|" expressao_relacional { cout << " OR " << endl; }
| expressao_relacional
;

expressao_relacional:
  expressao_relacional "<=" expressao_aritmetica { cout << " Maior igual" << endl; }
| expressao_relacional ">=" expressao_aritmetica { cout << " Maior igual " << endl; }
| expressao_relacional "<" expressao_aritmetica { cout << " Menor " << endl; }
| expressao_relacional ">" expressao_aritmetica { cout << " Maior " << endl; }
| expressao_relacional "!=" expressao_aritmetica { cout << " Diferente " << endl; }
| expressao_relacional "==" expressao_aritmetica { cout << " Equivalente " << endl; }
| expressao_aritmetica
;

expressao_aritmetica:
  expressao_aritmetica "+" termo  { cout << "SOMA " << endl; }
| expressao_aritmetica "-" termo { cout << " Sutracao " << endl; }
| termo
;

termo:
  termo "*" fator { cout << " Multiplicacao " << endl; }
| termo "/" fator { cout << " Divisao " << endl; }
| fator
;

fator:
  "(" expr ")" { cout << "Expressao com parenteses " << endl; }
| literal {  }
| local
| chamada_de_funcao
| NULO
;

chamada_de_funcao:
  IDENTIFICADOR "(" lista_args_chamada ")"
;

lista_args_chamada: 
  /* empty */ %empty
| fator
| lista_args_chamada "," fator
;

literal:
  INTEIRO { }
| REAL
| CADEIA
;

local:
  IDENTIFICADOR
| local "." IDENTIFICADOR
| local "[" lista_args_chamada "]"
;

%%

namespace Simples {
   void Parser::error(const location&, const string& m) {
        cerr << *driver.location_ << ": " << m << endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
