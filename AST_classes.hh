#ifndef AST_classes_HH
#define AST_classes_HH

#include <string>
#include <vector>
#include <iostream>
// #include "llvm/ADT/APFloat.h"
// #include "llvm/ADT/APSInt.h"
// #include "llvm/ADT/STLExtras.h"
// #include "llvm/IR/BasicBlock.h"
// #include "llvm/IR/Constants.h"
// #include "llvm/IR/DerivedTypes.h"
// #include "llvm/IR/Function.h"
// #include "llvm/IR/IRBuilder.h"
// #include "llvm/IR/LLVMContext.h"
// #include "llvm/IR/Module.h"
// #include "llvm/IR/Type.h"
// #include "llvm/IR/Verifier.h"
// #include "../include/KaleidoscopeJIT.h"

using namespace std;
using namespace llvm;

class ExprAst;  
class LocalAst;
class ListaComandosAst;
class DeclaracoesAst;
class BaseComandoAst;
class ListaArgsChamada;

/* ******************
 *      PROGRAMA    *
 * ****************** */

class ProgramaAst {
public:
    ProgramaAst(DeclaracoesAst* dec, BaseComandoAst* acao);
    ~ProgramaAst() {}

    DeclaracoesAst* dec_;
    ListaComandosAst* acao_;
};

extern ProgramaAst* ast_root;


/* ******************
 *    DECLARACOES   *
 * ****************** */

/* declaracao de tipos */

class BaseDecTiposAst {
public:
    BaseDecTiposAst() {}
    ~BaseDecTiposAst() {}

    // virtual Value *codegen() = 0;
};

class TipoCampoAst : public BaseDecTiposAst {
public:
    TipoCampoAst(const string &id, const string &tipo);

    string id_;
    string tipo_;

    // Value *codegen() ove rride;
};

class TipoCamposAst : public BaseDecTiposAst {
public:
    TipoCamposAst(BaseDecTiposAst* campo);
    TipoCamposAst(BaseDecTiposAst* tail, BaseDecTiposAst* campo);

    vector<TipoCampoAst*> lista_campos_;

    // Value *codegen() ove rride;
};

class BaseDescritorTipoAst {
public:
    BaseDescritorTipoAst() {}
    ~BaseDescritorTipoAst() {}

    // virtual Value *codegen() = 0;
};

class DescritorTipoIdAst : public BaseDescritorTipoAst {
public:
    DescritorTipoIdAst(const string &id);

    string id_;

    // Value *codegen() ove rride;
};

class DescritorTipoCamposAst : public BaseDescritorTipoAst {
public:
    DescritorTipoCamposAst(BaseDecTiposAst* campos);

    TipoCamposAst* tipo_campos_;

    // Value *codegen() ove rride;
};

class TipoConstantesAst {
public:
    TipoConstantesAst(int val);
    TipoConstantesAst(TipoConstantesAst* ctes, int val);

    vector<int> tipo_ctes_;

    // Value *codegen();
};

class DescritorTipoCtesAst : public BaseDescritorTipoAst {
public:
    DescritorTipoCtesAst(TipoConstantesAst* ctes, const string &tipo);

    TipoConstantesAst* tipo_constantes_;
    string tipo_;

    // Value *codegen() ove rride;
};

class DeclaracaoTipoAst : public BaseDecTiposAst {
public:
    DeclaracaoTipoAst(const string &id, BaseDescritorTipoAst* descritor_tipo);
    
    string id_;
    BaseDescritorTipoAst* descritor_tipo_;

    // Value *codegen() ove rride;
};

class DeclaracaoTiposAst : public BaseDecTiposAst {
public:
    DeclaracaoTiposAst(BaseDecTiposAst* declaracao);
    DeclaracaoTiposAst(BaseDecTiposAst* tail, BaseDecTiposAst* declaracao);

    vector<DeclaracaoTipoAst*> lista_declaracoes_;

    // Value *codegen() ove rride;
};


/* declaracao de variaveis */

class BaseDecVarAst {
public:
    BaseDecVarAst() {}
    ~BaseDecVarAst() {}

    // virtual Value *codegen() = 0;
};

class DeclaracaoVariavelAst : public BaseDecVarAst {
public:
    DeclaracaoVariavelAst(const string &id, const string &tipo, ExprAst* expressao);
    ~DeclaracaoVariavelAst();

    string id_, tipo_;
    ExprAst* expressao_;

    // Value *codegen() ove rride;
};

class ListaDecVarAst : public BaseDecVarAst {
public:
    ListaDecVarAst(BaseDecVarAst* declaracao);
    ListaDecVarAst(BaseDecVarAst* tail, BaseDecVarAst* declaracao);

    vector<DeclaracaoVariavelAst*> lista_declaracoes_;

    // Value *codegen() ove rride;
};

/* declaracao de funcoes */

class BaseDecFuncAst {
public:
    BaseDecFuncAst() {}
    ~BaseDecFuncAst() {}

    // virtual Value *codegen() = 0;
};

enum Modificador {
    VALOR,
    REFERENCIA
};

class BaseArgsAst {
public:
    BaseArgsAst() {}
    ~BaseArgsAst() {}

    // virtual Value *codegen() = 0;
};

class ArgumentoAst : public BaseArgsAst {
public:
    ArgumentoAst(Modificador mod, const string &id, const string &tipo);

    Modificador mod_;
    string id_, tipo_;

    // Value *codegen() ove rride;
};

class ListaArgsAst : public BaseArgsAst {
public:
    ListaArgsAst(BaseArgsAst* arg);
    ListaArgsAst(BaseArgsAst* tail, BaseArgsAst* arg);

    vector<ArgumentoAst*> lista_argumentos_;

    // Value *codegen() ove rride;
};

class CorpoAst {
public:
    CorpoAst(BaseDecVarAst* var_locais, BaseComandoAst* lista_comandos);
    ~CorpoAst() {}

    ListaDecVarAst* variaveis_locais_;
    ListaComandosAst* lista_comandos_;

    // Value *codegen();
};

class DeclaracaoFuncaoAst : public BaseDecFuncAst {
public:
    DeclaracaoFuncaoAst(const string &id, BaseArgsAst* args, CorpoAst* corpo);
    DeclaracaoFuncaoAst(const string &id, BaseArgsAst* args, const string &ret, CorpoAst* corpo);

    string id_;
    ListaArgsAst* args_;
    string retorno_;
    CorpoAst* corpo_;

    // Value *codegen() ove rride;
};

class DeclaracaoFuncoesAst : public BaseDecFuncAst {
public:
    DeclaracaoFuncoesAst(BaseDecFuncAst* declaracao);
    DeclaracaoFuncoesAst(BaseDecFuncAst* tail, BaseDecFuncAst* declaracao);

    vector<DeclaracaoFuncaoAst*> lista_declaracoes_;

    // Value *codegen() ove rride;
};

/* declaracoes */

class DeclaracoesAst {
public:
    DeclaracoesAst(BaseDecTiposAst* tipos, BaseDecVarAst* globais, BaseDecFuncAst* funcoes);
    ~DeclaracoesAst() {}

    DeclaracaoTiposAst* tipos_;
    ListaDecVarAst* globais_;
    DeclaracaoFuncoesAst* funcoes_;

    // Value *codegen();
};


/* ******************
 *        ACOES     *
 * ****************** */


class BaseComandoAst {
public:
    BaseComandoAst() {}
    ~BaseComandoAst() {}

    // virtual Value *codegen() = 0;
};

class ListaComandosAst : public BaseComandoAst {
public:
    ListaComandosAst(BaseComandoAst* comando);
    ListaComandosAst(BaseComandoAst* tail, BaseComandoAst* comando);

    vector<BaseComandoAst*> lista_comandos_;

    // Value *codegen() ove rride;
};

class AtribuicaoAst : public BaseComandoAst {
public:
    AtribuicaoAst(ExprAst* esq, ExprAst* dir);

    LocalAst* esq_;
    ExprAst* dir_;

    // Value *codegen() ove rride;
};

class SeAst : public BaseComandoAst {
public:
    SeAst(ExprAst* expr, BaseComandoAst* comandos_v);
    SeAst(ExprAst* expr, BaseComandoAst* comandos_v, BaseComandoAst* comandos_f);

    ExprAst* expr_;
    ListaComandosAst* comandos_verdadeiro_;
    ListaComandosAst* comandos_falso_;

    // Value *codegen() ove rride;
};

class ParaAst : public BaseComandoAst {
public:
    ParaAst(const string &it, ExprAst* inicio, ExprAst* fim, BaseComandoAst* comandos);

    string it_;
    ExprAst* expr_inicio_;
    ExprAst* expr_fim_;
    ListaComandosAst* comandos_;

    // Value *codegen() ove rride;
};

class EnquantoAst : public BaseComandoAst {
public:
    EnquantoAst(ExprAst* expr, BaseComandoAst* comandos);

    ExprAst* expr_;
    ListaComandosAst* comandos_;

    // Value *codegen() ove rride;
};

class RetorneAst : public BaseComandoAst {
public:
    RetorneAst(ExprAst* expr);

    ExprAst* expr_;

    // Value *codegen() ove rride;
};

class PareAst : public BaseComandoAst {
public:
    PareAst() {}
    // Value *codegen() ove rride;
};

class ContinueAst : public BaseComandoAst {
public:
    ContinueAst() {}
    // Value *codegen() ove rride;
};

class ChamadaProcedimentoAst : public BaseComandoAst {
public:
    ChamadaProcedimentoAst(const string &id, ExprAst* lista);

    string id_;
    ListaArgsChamada* lista_;

    // Value *codegen() ove rride;
};

/* ******************
 *    EXPRESSOES    *
 * ****************** */


class ExprAst {
public:
    ExprAst() {}
    ~ExprAst() {}

    // virtual Value *codegen() = 0;
};

class AtribuicaoRegistroAst : public ExprAst {
public:
    AtribuicaoRegistroAst(const string &id, ExprAst* expr);

    string id_;
    ExprAst* expr_;

    // Value *codegen() ove rride;
};

class CriacaoRegistroAst : public ExprAst {
public:
    CriacaoRegistroAst(ExprAst* atribuicao_registro);
    CriacaoRegistroAst(ExprAst* tail, ExprAst* atribuicao_registro);

    vector<AtribuicaoRegistroAst*> lista_;

    // Value *codegen() ove rride;
};


class InteiroAst : public ExprAst {
public:
    InteiroAst(int val);

    int val_;

    // Value *codegen() ove rride;
};

class RealAst : public ExprAst {
public:
    RealAst(double val);

    double val_;

    // Value *codegen() ove rride;
};

class CadeiaAst : public ExprAst {
public:
    CadeiaAst(const string &val);

    string val_;

    // Value *codegen() ove rride;
};

class LocalAst : public ExprAst {
public:
    LocalAst(const string &val);

    string val_;

    // Value *codegen() ove rride;
};

class SomaAst : public ExprAst {
public:
    SomaAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;
    
    // Value *codegen() ove rride;
};

class SubtracaoAst : public ExprAst {
public:
    SubtracaoAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    // Value *codegen() ove rride;
};

class MaiorAst : public ExprAst {
public:
    MaiorAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    // Value *codegen() ove rride;
};

class MenorAst : public ExprAst {
public:
    MenorAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    // Value *codegen() ove rride;
};

class MaiorIgualAst : public ExprAst {
public:
    MaiorIgualAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    // Value *codegen() ove rride;
};

class MenorIgualAst : public ExprAst {
public:
    MenorIgualAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    // Value *codegen() ove rride;
};

class EquivalenteAst : public ExprAst {
public:
    EquivalenteAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    // Value *codegen() ove rride;
};

class DiferenteAst : public ExprAst {
public:
    DiferenteAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    // Value *codegen() ove rride;
};

class MultiplicacaoAst : public ExprAst {
public:
    MultiplicacaoAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    // Value *codegen() ove rride;
};

class DivisaoAst : public ExprAst {
public:
    DivisaoAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    // Value *codegen() ove rride;
};

class AndAst : public ExprAst {
public:
    AndAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    // Value *codegen() ove rride;
};

class OrAst : public ExprAst {
public:
    OrAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    // Value *codegen() ove rride;
};

class NuloAst : public ExprAst {
public:
    NuloAst() {}
    // Value *codegen() ove rride;
};

class ListaArgsChamada : public ExprAst {
public:
    ListaArgsChamada(ExprAst* fator);
    ListaArgsChamada(ExprAst* tail, ExprAst* fator);

    vector<ExprAst*> args_;

    // Value *codegen() ove rride;
};

class ChamadaFuncaoAst : public ExprAst {
public:
    ChamadaFuncaoAst(const string &id, ExprAst* lista);

    string id_;
    ListaArgsChamada* lista_;

    // Value *codegen() ove rride;
};

#endif
