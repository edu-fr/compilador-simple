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
  acao
;

declaracoes:
  /* empty */

acao:
  lista_comandos
;

lista_comandos: 
  lista_comandos PONTOEVIRGULA comando  
| comando
;

comando:
| SE expr VERDADEIRO lista_comandos FSE
| SE expr VERDADEIRO lista_comandos FALSO lista_comandos FSE
| PARA id DE expr LIMITE expr FACA lista_comandos FPARA
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

expressao_logica:

;

expressao_relacional:

;

expressao_aritmetica:

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

;

id:

;

constante_inteiro: INTEIRO { std::cout << "Inteiro: " << $1 << std::endl; }
;

constante_real : REAL { std::cout << "Real: " << $1 << std::endl; }
;

variavel : IDENTIFICADOR {  std::cout << "Identificador: " << *$1 << std::endl; }
;

cadeia : CADEIA { std::cout << "Cadeia: " << *$1 << std::endl; }
;

comentario : COMENTARIO { std::cout << "Comentário! " << std::endl; }
;

reservado : PARE { std::cout << "Pare!" << std::endl; }
         | CONTINUE { std::cout << "Continue!" << std::endl; }
         | PARA { std::cout << "Para!" << std::endl; }
         | FPARA { std::cout << "Fpara!" << std::endl; }
         | ENQUANTO { std::cout << "Enquanto!" << std::endl; }
         | FENQUANTO { std::cout << "Fenquanto!" << std::endl; }
         | FACA { std::cout << "Faça!" << std::endl; }
         | SE { std::cout << "Se!" << std::endl; }
         | FSE { std::cout << "Fse!" << std::endl; }
         | VERDADEIRO { std::cout << "Verdadeiro!" << std::endl; }
         | FALSO { std::cout << "Falso!" << std::endl; }
         | TIPO { std::cout << "Tipo!" << std::endl; }
         | DE { std::cout << "De!" << std::endl; }  
         | LIMITE { std::cout << "Limite!" << std::endl; }  
         | GLOBAL { std::cout << "Global!" << std::endl; }  
         | LOCAL { std::cout << "Local!" << std::endl; }  
         | REF { std::cout << "Ref!" << std::endl; }  
         | RETORNE { std::cout << "Retorne!" << std::endl; }  
         | NULO { std::cout << "Nulo!" << std::endl; }  
         | INICIO { std::cout << "Início!" << std::endl; }  
         | FIM { std::cout << "Fim!" << std::endl; }  
;

%%

namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}
