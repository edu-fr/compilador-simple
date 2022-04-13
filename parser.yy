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
#include "driver.hh"
#include "location.hh"
#include "position.hh"
#include "AST_classes.hh"
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
    int                         integerVal;
    double 	                    doubleVal;
    std::string*                stringVal;
    ProgramaAst*                programa_val;
    ExprAst*                    exp_val;
    BaseComandoAst*             acao_val;
    LocalAst*                   local_val;
    DeclaracoesAst*             declaracao_val;
    BaseDecTiposAst*            declaracao_tipos_val;
    BaseDecFuncAst*             declaracao_funcoes_val;
    BaseDecVarAst*              declaracao_variavel_val;
    BaseArgsAst*                argumento_val;
    Modificador                 modificador_val;
    CorpoAst*                   corpo_val;
    TipoConstantesAst*          tipo_ctes_val;
    BaseDescritorTipoAst*       descritor_tipo_val;
}

/* Nao terminais */
%type <programa_val> programa 
%type <exp_val> termo fator literal expr expressao_logica expressao_relacional expressao_aritmetica inicializacao criacao_de_registro
%type <acao_val> lista_comandos acao comando
%type <local_val> local 
%type <declaracao_val> declaracoes
%type <declaracao_tipos_val> lista_declaracao_de_tipo lista_declaracao_tipo declaracao_tipo tipo_campo tipo_campos
%type <declaracao_funcoes_val> lista_declaracao_de_funcao lista_declaracao_funcao declaracao_funcao
%type <declaracao_variavel_val> declaracao_variavel lista_declaracao_de_variavel_global lista_declaracao_de_variavel_local lista_declaracao_variavel
%type <modificador_val> modificador
%type <argumento_val> args lista_args lista_de_args
%type <corpo_val> corpo
%type <tipo_ctes_val> tipo_constantes
%type <descritor_tipo_val> descritor_tipo

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
%token <exp_val>    NULO            "nulo"
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
  declaracoes acao { $$ = new ProgramaAst($1, $2); } 
;

declaracoes: 
  lista_declaracao_de_tipo 
  lista_declaracao_de_variavel_global
  lista_declaracao_de_funcao { $$ = new DeclaracoesAst($1, $2, $3); }
;

acao:
  ACAO ":" lista_comandos { $$ = $3; }
;

lista_declaracao_de_tipo:
  /* empty */ %empty { $$ = nullptr; }
  | TIPO ":" lista_declaracao_tipo { $$ = $3; }
;

lista_declaracao_tipo:
  declaracao_tipo { $$ = new DeclaracaoTiposAst($1); }
| lista_declaracao_tipo declaracao_tipo { $$ = new DeclaracaoTiposAst($1, $2); }
;

lista_declaracao_de_variavel_global:
  /* empty */ %empty { $$ = nullptr; }
| GLOBAL ":" lista_declaracao_variavel { $$ = $3; }
;

lista_declaracao_variavel:
  declaracao_variavel { $$ = new ListaDecVarAst($1); }
| lista_declaracao_variavel declaracao_variavel { $$ = new ListaDecVarAst($1, $2); }
;

declaracao_variavel:    
  IDENTIFICADOR ":" IDENTIFICADOR ":=" inicializacao { $$ = new DeclaracaoVariavelAst(*$1, *$3, $5); }
;

inicializacao:
  expr
;

declaracao_tipo:
  IDENTIFICADOR "=" descritor_tipo { $$ = new DeclaracaoTipoAst(*$1, $3); }
;

descritor_tipo:
  IDENTIFICADOR { $$ = new DescritorTipoIdAst(*$1); }
| "{" tipo_campos "}" { $$ = new DescritorTipoCamposAst($2); }
| "[" tipo_constantes "]" DE IDENTIFICADOR { $$ = new DescritorTipoCtesAst($2, *$5); }
;

tipo_campos:
  tipo_campo { $$ = new TipoCamposAst($1); }
| tipo_campos "," tipo_campo { $$ = new TipoCamposAst($1, $3); }
;

tipo_campo:
  IDENTIFICADOR ":" IDENTIFICADOR { $$ = new TipoCampoAst(*$1, *$3); }
;

tipo_constantes:
  INTEIRO { $$ = new TipoConstantesAst($1); }
| tipo_constantes "," INTEIRO { $$ = new TipoConstantesAst($1, $3); }
;

lista_declaracao_de_funcao:
  /* empty */ %empty { $$ = nullptr; }
  | FUNCAO ":" lista_declaracao_funcao { $$ = $3; }
;

lista_declaracao_funcao:
  declaracao_funcao { $$ = new DeclaracaoFuncoesAst($1); }
| lista_declaracao_funcao declaracao_funcao { $$ = new DeclaracaoFuncoesAst($1, $2); }
;

declaracao_funcao:
  IDENTIFICADOR "(" lista_de_args ")" "=" corpo { $$ = new DeclaracaoFuncaoAst(*$1, $3, $6); }
| IDENTIFICADOR "(" lista_de_args ")" ":" IDENTIFICADOR "=" corpo { $$ = new DeclaracaoFuncaoAst(*$1, $3, *$6, $8); }
;

lista_de_args: 
  /* empty */ %empty { $$ = nullptr; }
  | lista_args
;

lista_args:
  args { $$ = new ListaArgsAst($1); }
  | lista_args "," args { $$ = new ListaArgsAst($1, $3); }
;

args:
  modificador IDENTIFICADOR ":" IDENTIFICADOR { $$ = new ArgumentoAst($1, *$2, *$4); }
;

modificador:
  VALOR { $$ = Modificador::VALOR; }
| REF { $$ = Modificador::REFERENCIA; }
;

corpo:
  lista_declaracao_de_variavel_local
  ACAO ":" lista_comandos { $$ = new CorpoAst($1, $4); }
;

lista_declaracao_de_variavel_local:
  /* empty */ %empty { $$ = nullptr; }
  | LOCAL ":" lista_declaracao_variavel { $$ = $3; }
;

lista_comandos: 
  comando { $$ = new ListaComandosAst($1); }
| lista_comandos ";" comando { $$ = new ListaComandosAst($1, $3); }
;

comando:
  local ATRIBUICAO expr { $$ = new AtribuicaoAst($1, $3); }    
| chamada_de_funcao
| SE expr VERDADEIRO lista_comandos FSE { $$ = new SeAst($2, $4); }
| SE expr VERDADEIRO lista_comandos FALSO lista_comandos FSE { $$ = new SeAst($2, $4, $6); }
| PARA IDENTIFICADOR DE expr LIMITE expr FACA lista_comandos FPARA { $$ = new ParaAst(*$2, $4, $6, $8); }
| ENQUANTO expr FACA lista_comandos FENQUANTO { $$ = new EnquantoAst($2, $4); }
| PARE // O QUE FAZER AQUI ???
| CONTINUE 
| RETORNE expr { $$ = new RetorneAst($2); }
;

expr:
  expressao_logica { $$ = $1; }
| "{" criacao_de_registro "}" { $$ = $2; }
;

criacao_de_registro:
  atribuicao_registro
| criacao_de_registro "," atribuicao_registro
;

atribuicao_registro:
  IDENTIFICADOR "=" expr
;

expressao_logica:
  expressao_logica "&" expressao_relacional { $$ = new AndAst($1, $3); }
| expressao_logica "|" expressao_relacional { $$ = new OrAst($1, $3); }
| expressao_relacional
;

expressao_relacional:
  expressao_relacional "<=" expressao_aritmetica { $$ = new MenorIgualAst($1, $3); }
| expressao_relacional ">=" expressao_aritmetica { $$ = new MaiorIgualAst($1, $3); }
| expressao_relacional "<" expressao_aritmetica { $$ = new MenorAst($1, $3); }
| expressao_relacional ">" expressao_aritmetica { $$ = new MaiorAst($1, $3); }
| expressao_relacional "!=" expressao_aritmetica { $$ = new DiferenteAst($1, $3); }
| expressao_relacional "==" expressao_aritmetica { $$ = new EquivalenteAst($1, $3); }
| expressao_aritmetica
;

expressao_aritmetica:
  expressao_aritmetica "+" termo { $$ = new SomaAst($1, $3); }
| expressao_aritmetica "-" termo { $$ = new SubtracaoAst($1, $3); }
| termo 
;

termo:
  termo "*" fator { $$ = new MultiplicacaoAst($1, $3); }
| termo "/" fator { $$ = new DivisaoAst($1, $3); }
| fator
;

fator:
  "(" expr ")" { $$ = $2; }
| literal
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
  INTEIRO { $$ = new InteiroAst($1); }
| REAL { $$ = new RealAst($1); }
| CADEIA { $$ = new CadeiaAst(*$1); }
;

local:
  IDENTIFICADOR { $$ = new LocalAst(*$1); }
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
