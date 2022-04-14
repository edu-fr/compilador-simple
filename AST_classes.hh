#ifndef AST_classes_HH
#define AST_classes_HH

#include <string>
#include <vector>
#include <iostream>
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

using namespace std;
using namespace llvm;

class ExprAst;
class LocalAst;
class ListaComandosAst;
class DeclaracoesAst;
class BaseComandoAst;


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
};

class TipoCampoAst : public BaseDecTiposAst {
public:
    TipoCampoAst(const string &id, const string &tipo);

    string id_;
    string tipo_;
};

class TipoCamposAst : public BaseDecTiposAst {
public:
    TipoCamposAst(BaseDecTiposAst* campo);
    TipoCamposAst(BaseDecTiposAst* tail, BaseDecTiposAst* campo);

    vector<TipoCampoAst*> lista_campos_;
};

class BaseDescritorTipoAst {
public:
    BaseDescritorTipoAst() {}
    ~BaseDescritorTipoAst() {}
};

class DescritorTipoIdAst : public BaseDescritorTipoAst {
public:
    DescritorTipoIdAst(const string &id);

    string id_;
};

class DescritorTipoCamposAst : public BaseDescritorTipoAst {
public:
    DescritorTipoCamposAst(BaseDecTiposAst* campos);

    TipoCamposAst* tipo_campos_;
};

class TipoConstantesAst {
public:
    TipoConstantesAst(int val);
    TipoConstantesAst(TipoConstantesAst* ctes, int val);

    vector<int> tipo_ctes_;
};

class DescritorTipoCtesAst : public BaseDescritorTipoAst {
public:
    DescritorTipoCtesAst(TipoConstantesAst* ctes, const string &tipo);

    TipoConstantesAst* tipo_constantes_;
    string tipo_;
};

class DeclaracaoTipoAst : public BaseDecTiposAst {
public:
    DeclaracaoTipoAst(const string &id, BaseDescritorTipoAst* descritor_tipo);
    
    string id_;
    BaseDescritorTipoAst* descritor_tipo_;
};

class DeclaracaoTiposAst : public BaseDecTiposAst {
public:
    DeclaracaoTiposAst(BaseDecTiposAst* declaracao);
    DeclaracaoTiposAst(BaseDecTiposAst* tail, BaseDecTiposAst* declaracao);

    vector<DeclaracaoTipoAst*> lista_declaracoes_;
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
};

class ListaDecVarAst : public BaseDecVarAst {
public:
    ListaDecVarAst(BaseDecVarAst* declaracao);
    ListaDecVarAst(BaseDecVarAst* tail, BaseDecVarAst* declaracao);

    vector<DeclaracaoVariavelAst*> lista_declaracoes_;
};

/* declaracao de funcoes */

class BaseDecFuncAst {
public:
    BaseDecFuncAst() {}
    ~BaseDecFuncAst() {}
};

enum Modificador {
    VALOR,
    REFERENCIA
};

class BaseArgsAst {
public:
    BaseArgsAst() {}
    ~BaseArgsAst() {}
};

class ArgumentoAst : public BaseArgsAst {
public:
    ArgumentoAst(Modificador mod, const string &id, const string &tipo);

    Modificador mod_;
    string id_, tipo_;
};

class ListaArgsAst : public BaseArgsAst {
public:
    ListaArgsAst(BaseArgsAst* arg);
    ListaArgsAst(BaseArgsAst* tail, BaseArgsAst* arg);

    vector<ArgumentoAst*> lista_argumentos_;
};

class CorpoAst {
public:
    CorpoAst(BaseDecVarAst* var_locais, BaseComandoAst* lista_comandos);
    ~CorpoAst() {}

    ListaDecVarAst* variaveis_locais_;
    ListaComandosAst* lista_comandos_;
};

// ??? - MELHOR SEPARAR FUNCAO E PROCEDIMENTO???
class DeclaracaoFuncaoAst : public BaseDecFuncAst {
public:
    DeclaracaoFuncaoAst(const string &id, BaseArgsAst* args, CorpoAst* corpo);
    DeclaracaoFuncaoAst(const string &id, BaseArgsAst* args, const string &ret, CorpoAst* corpo);

    string id_;
    ListaArgsAst* args_;
    string retorno_;
    CorpoAst* corpo_;
};

class DeclaracaoFuncoesAst : public BaseDecFuncAst {
public:
    DeclaracaoFuncoesAst(BaseDecFuncAst* declaracao);
    DeclaracaoFuncoesAst(BaseDecFuncAst* tail, BaseDecFuncAst* declaracao);

    vector<DeclaracaoFuncaoAst*> lista_declaracoes_;
};

/* declaracoes */

class DeclaracoesAst {
public:
    DeclaracoesAst(BaseDecTiposAst* tipos, BaseDecVarAst* globais, BaseDecFuncAst* funcoes);
    ~DeclaracoesAst() {}

    DeclaracaoTiposAst* tipos_;
    ListaDecVarAst* globais_;
    DeclaracaoFuncoesAst* funcoes_;
};


/* ******************
 *        ACOES     *
 * ****************** */


class BaseComandoAst {
public:
    BaseComandoAst() {}
    ~BaseComandoAst() {}
};

class ListaComandosAst : public BaseComandoAst {
public:
    ListaComandosAst(BaseComandoAst* comando);
    ListaComandosAst(BaseComandoAst* tail, BaseComandoAst* comando);

    vector<BaseComandoAst*> lista_comandos_;
};

class AtribuicaoAst : public BaseComandoAst {
public:
    AtribuicaoAst(ExprAst* esq, ExprAst* dir);

    LocalAst* esq_;
    ExprAst* dir_;
};

class SeAst : public BaseComandoAst {
public:
    SeAst(ExprAst* expr, BaseComandoAst* comandos_v);
    SeAst(ExprAst* expr, BaseComandoAst* comandos_v, BaseComandoAst* comandos_f);

    ExprAst* expr_;
    ListaComandosAst* comandos_verdadeiro_;
    ListaComandosAst* comandos_falso_;
};

class ParaAst : public BaseComandoAst {
public:
    ParaAst(const string &it, ExprAst* inicio, ExprAst* fim, BaseComandoAst* comandos);

    string it_;
    ExprAst* expr_inicio_;
    ExprAst* expr_fim_;
    ListaComandosAst* comandos_;
};

class EnquantoAst : public BaseComandoAst {
public:
    EnquantoAst(ExprAst* expr, BaseComandoAst* comandos);

    ExprAst* expr_;
    ListaComandosAst* comandos_;
};

class RetorneAst : public BaseComandoAst {
public:
    RetorneAst(ExprAst* expr);

    ExprAst* expr_;
};

class PareAst : public BaseComandoAst {
public:
    PareAst() {}
};

class ContinueAst : public BaseComandoAst {
public:
    ContinueAst() {}
};


/* ******************
 *    EXPRESSOES    *
 * ****************** */


class ExprAst {
public:
    ExprAst() {}
    ~ExprAst() {}
};

class AtribuicaoRegistroAst : public ExprAst {
public:
    AtribuicaoRegistroAst(const string &id, ExprAst* expr);

    string id_;
    ExprAst* expr_;
};

class CriacaoRegistroAst : public ExprAst {
public:
    CriacaoRegistroAst(ExprAst* atribuicao_registro);
    CriacaoRegistroAst(ExprAst* tail, ExprAst* atribuicao_registro);

    vector<AtribuicaoRegistroAst*> lista_;
};


class InteiroAst : public ExprAst {
public:
    InteiroAst(int val);

    int val_;
};

class RealAst : public ExprAst {
public:
    RealAst(double val);

    double val_;
};

class CadeiaAst : public ExprAst {
public:
    CadeiaAst(const string &val);

    string val_;
};

class LocalAst : public ExprAst {
public:
    LocalAst(const string &val);

    string val_;
};

class SomaAst : public ExprAst {
public:
    SomaAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;
};

class SubtracaoAst : public ExprAst {
public:
    SubtracaoAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;
};

class MaiorAst : public ExprAst {
public:
    MaiorAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;
};

class MenorAst : public ExprAst {
public:
    MenorAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;
};

class MaiorIgualAst : public ExprAst {
public:
    MaiorIgualAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;
};

class MenorIgualAst : public ExprAst {
public:
    MenorIgualAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;
};

class EquivalenteAst : public ExprAst {
public:
    EquivalenteAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;
};

class DiferenteAst : public ExprAst {
public:
    DiferenteAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;
};

class MultiplicacaoAst : public ExprAst {
public:
    MultiplicacaoAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;
};

class DivisaoAst : public ExprAst {
public:
    DivisaoAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;
};

class AndAst : public ExprAst {
public:
    AndAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;
};

class OrAst : public ExprAst {
public:
    OrAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;
};

class NuloAst : public ExprAst {
public:
    NuloAst() {}
};

class ListaArgsChamada : public ExprAst {
public:
    ListaArgsChamada(ExprAst* fator);
    ListaArgsChamada(ExprAst* tail, ExprAst* fator);

    vector<ExprAst*> args_;
};

class ChamadaFuncaoAst : public ExprAst {
public:
    ChamadaFuncaoAst(const string &id, ExprAst* lista);

    string id_;
    ListaArgsChamada* lista_;
};

class ChamadaProcedimentoAst : public BaseComandoAst {
public:
    ChamadaProcedimentoAst(const string &id, ExprAst* lista);

    string id_;
    ListaArgsChamada* lista_;
};


#endif
