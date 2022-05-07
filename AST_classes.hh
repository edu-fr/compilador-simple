#ifndef AST_classes_HH
#define AST_classes_HH

#include <vector>
#include "llvm/IR/Value.h"
#include "llvm/IR/Instructions.h"

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

    Value* codegen();
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

    virtual Value *codegen() = 0;
};

class TipoCampoAst : public BaseDecTiposAst {
public:
    TipoCampoAst(const string &id, const string &tipo);

    string id_;
    string tipo_;

    Value *codegen() override;
};

class TipoCamposAst : public BaseDecTiposAst {
public:
    TipoCamposAst(BaseDecTiposAst* campo);
    TipoCamposAst(BaseDecTiposAst* tail, BaseDecTiposAst* campo);

    vector<TipoCampoAst*> lista_campos_;

    Value *codegen() override;
};

class BaseDescritorTipoAst {
public:
    BaseDescritorTipoAst() {}
    ~BaseDescritorTipoAst() {}

    virtual Value *codegen() = 0;
};

class DescritorTipoIdAst : public BaseDescritorTipoAst {
public:
    DescritorTipoIdAst(const string &id);

    string id_;

    Value *codegen() override;
};

class DescritorTipoCamposAst : public BaseDescritorTipoAst {
public:
    DescritorTipoCamposAst(BaseDecTiposAst* campos);

    TipoCamposAst* tipo_campos_;

    Value *codegen() override;
};

class TipoConstantesAst {
public:
    TipoConstantesAst(int val);
    TipoConstantesAst(TipoConstantesAst* ctes, int val);

    vector<int> tipo_ctes_;

    Value *codegen();
};

class DescritorTipoCtesAst : public BaseDescritorTipoAst {
public:
    DescritorTipoCtesAst(TipoConstantesAst* ctes, const string &tipo);

    TipoConstantesAst* tipo_constantes_;
    string tipo_;

    Value *codegen() override;
};

class DeclaracaoTipoAst : public BaseDecTiposAst {
public:
    DeclaracaoTipoAst(const string &id, BaseDescritorTipoAst* descritor_tipo);
    
    string id_;
    BaseDescritorTipoAst* descritor_tipo_;

    Value *codegen() override;
};

class DeclaracaoTiposAst : public BaseDecTiposAst {
public:
    DeclaracaoTiposAst(BaseDecTiposAst* declaracao);
    DeclaracaoTiposAst(BaseDecTiposAst* tail, BaseDecTiposAst* declaracao);

    vector<DeclaracaoTipoAst*> lista_declaracoes_;

    Value *codegen() override;
};


/* declaracao de variaveis */

class BaseDecVarAst {
public:
    BaseDecVarAst() {}
    ~BaseDecVarAst() {}

    virtual Value *codegen(std::vector<AllocaInst *> OldBindings, Function *TheFunction) = 0;
};

class DeclaracaoVariavelAst : public BaseDecVarAst {
public:
    DeclaracaoVariavelAst(const string &id, const string &tipo, ExprAst* expressao);
    ~DeclaracaoVariavelAst();

    string id_, tipo_;
    ExprAst* expressao_;

    Value *codegen(std::vector<AllocaInst *> OldBindings, Function *TheFunction) override;
};

class ListaDecVarAst : public BaseDecVarAst {
public:
    ListaDecVarAst(BaseDecVarAst* declaracao);
    ListaDecVarAst(BaseDecVarAst* tail, BaseDecVarAst* declaracao);

    vector<DeclaracaoVariavelAst*> lista_declaracoes_;

    Value *codegen(std::vector<AllocaInst *> OldBindings, Function *TheFunction) override;
};

/* declaracao de funcoes */

class BaseDecFuncAst {
public:
    BaseDecFuncAst() {}
    ~BaseDecFuncAst() {}

    virtual Function *codegen() = 0;
};

enum Modificador {
    VALOR,
    REFERENCIA
};

class BaseArgsAst {
public:
    BaseArgsAst() {}
    ~BaseArgsAst() {}

    virtual Value *codegen() = 0;
};

class ArgumentoAst : public BaseArgsAst {
public:
    ArgumentoAst(Modificador mod, const string &id, const string &tipo);

    Modificador mod_;
    string id_, tipo_;

    Value *codegen() override;
};

class ListaArgsAst : public BaseArgsAst {
public:
    ListaArgsAst(BaseArgsAst* arg);
    ListaArgsAst(BaseArgsAst* tail, BaseArgsAst* arg);

    vector<ArgumentoAst*> lista_argumentos_;

    Value *codegen() override;
};

class CorpoAst {
public:
    CorpoAst(BaseDecVarAst* var_locais, BaseComandoAst* lista_comandos);
    ~CorpoAst() {}

    ListaDecVarAst* variaveis_locais_;
    ListaComandosAst* lista_comandos_;

    Value *codegen();
};

class DeclaracaoFuncaoAst : public BaseDecFuncAst {
public:
    DeclaracaoFuncaoAst(const string &id, BaseArgsAst* args, CorpoAst* corpo);
    DeclaracaoFuncaoAst(const string &id, BaseArgsAst* args, const string &ret, CorpoAst* corpo);

    string id_;
    ListaArgsAst* args_;
    string retorno_;
    CorpoAst* corpo_;

    Function *codegen() override;
};

class DeclaracaoFuncoesAst : public BaseDecFuncAst {
public:
    DeclaracaoFuncoesAst(BaseDecFuncAst* declaracao);
    DeclaracaoFuncoesAst(BaseDecFuncAst* tail, BaseDecFuncAst* declaracao);

    vector<DeclaracaoFuncaoAst*> lista_declaracoes_;

    Function *codegen() override;
};

/* declaracoes */

class DeclaracoesAst {
public:
    DeclaracoesAst(BaseDecTiposAst* tipos, BaseDecVarAst* globais, BaseDecFuncAst* funcoes);
    ~DeclaracoesAst() {}

    DeclaracaoTiposAst* tipos_;
    ListaDecVarAst* globais_;
    DeclaracaoFuncoesAst* funcoes_;

    Value *codegen();
};


/* ******************
 *        ACOES     *
 * ****************** */

enum tipo_comando {
    LISTA_COMANDOS,
    ATRIBUICAO,
    SE,
    PARA,
    ENQUANTO,
    RETORNE,
    PARE,
    CONTINUE,
    CHAMADA_PROCEDIMENTO
};

class BaseComandoAst {
public:
    BaseComandoAst() {}
    ~BaseComandoAst() {}

    virtual Value *codegen() = 0;
    virtual tipo_comando get_type() = 0;
};

class ListaComandosAst : public BaseComandoAst {
public:
    ListaComandosAst(BaseComandoAst* comando);
    ListaComandosAst(BaseComandoAst* tail, BaseComandoAst* comando);

    vector<BaseComandoAst*> lista_comandos_;

    Value *codegen() override;
    tipo_comando get_type() override;
};

class AtribuicaoAst : public BaseComandoAst {
public:
    AtribuicaoAst(ExprAst* esq, ExprAst* dir);

    LocalAst* esq_;
    ExprAst* dir_;

    Value *codegen() override;
    tipo_comando get_type() override;
};

class SeAst : public BaseComandoAst {
public:
    SeAst(ExprAst* expr, BaseComandoAst* comandos_v);
    SeAst(ExprAst* expr, BaseComandoAst* comandos_v, BaseComandoAst* comandos_f);

    ExprAst* expr_;
    ListaComandosAst* comandos_verdadeiro_;
    ListaComandosAst* comandos_falso_;

    Value *codegen() override;
    tipo_comando get_type() override;
};

class ParaAst : public BaseComandoAst {
public:
    ParaAst(const string &it, ExprAst* inicio, ExprAst* fim, BaseComandoAst* comandos);

    string it_;
    ExprAst* expr_inicio_;
    ExprAst* expr_fim_;
    ListaComandosAst* comandos_;

    Value *codegen() override;
    tipo_comando get_type() override;
};

class EnquantoAst : public BaseComandoAst {
public:
    EnquantoAst(ExprAst* expr, BaseComandoAst* comandos);

    ExprAst* expr_;
    ListaComandosAst* comandos_;

    Value *codegen() override;
    tipo_comando get_type() override;
};

class RetorneAst : public BaseComandoAst {
public:
    RetorneAst(ExprAst* expr);

    ExprAst* expr_;

    Value *codegen() override;
    tipo_comando get_type() override;
};

class PareAst : public BaseComandoAst {
public:
    PareAst() {}
    Value *codegen() override;
    tipo_comando get_type() override;
};

class ContinueAst : public BaseComandoAst {
public:
    ContinueAst() {}
    Value *codegen() override;
    tipo_comando get_type() override;
};

class ChamadaProcedimentoAst : public BaseComandoAst {
public:
    ChamadaProcedimentoAst(const string &id, ExprAst* lista);

    string id_;
    ListaArgsChamada* lista_;

    Value *codegen() override;
    tipo_comando get_type() override;
};


/* ******************
 *    EXPRESSOES    *
 * ****************** */

enum tipo_expressao {
    INVALIDO,
    ATRIBUICAO_REG,
    CRIACAO_REG,
    INTEIRO,
    REAL,
    CADEIA,
    LOCAL,
    SOMA,
    SUBTRACAO,
    MAIOR,
    MENOR,
    MAIOR_IGUAL,
    MENOR_IGUAL,
    EQUIVALENTE,
    DIFERENTE,
    MULTIPLICACAO,
    DIVISAO,
    AND,
    OR,
    NULO,
    LISTA_ARGS_CHAMADA,
    CHAMADA_FUNCAO
};

class ExprAst {
public:
    ExprAst() {}
    ~ExprAst() {}

    virtual Value *codegen() = 0;
    virtual tipo_expressao get_type() = 0;
};

class AtribuicaoRegistroAst : public ExprAst {
public:
    AtribuicaoRegistroAst(const string &id, ExprAst* expr);

    string id_;
    ExprAst* expr_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class CriacaoRegistroAst : public ExprAst {
public:
    CriacaoRegistroAst(ExprAst* atribuicao_registro);
    CriacaoRegistroAst(ExprAst* tail, ExprAst* atribuicao_registro);

    vector<AtribuicaoRegistroAst*> lista_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};


class InteiroAst : public ExprAst {
public:
    InteiroAst(long val);

    long val_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class RealAst : public ExprAst {
public:
    RealAst(double val);

    double val_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class CadeiaAst : public ExprAst {
public:
    CadeiaAst(const string &val);

    string val_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class LocalAst : public ExprAst {
public:
    LocalAst(const string &val);

    string val_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class SomaAst : public ExprAst {
public:
    SomaAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;
    
    Value *codegen() override;
    tipo_expressao get_type() override;
};

class SubtracaoAst : public ExprAst {
public:
    SubtracaoAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class MaiorAst : public ExprAst {
public:
    MaiorAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class MenorAst : public ExprAst {
public:
    MenorAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class MaiorIgualAst : public ExprAst {
public:
    MaiorIgualAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class MenorIgualAst : public ExprAst {
public:
    MenorIgualAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class EquivalenteAst : public ExprAst {
public:
    EquivalenteAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class DiferenteAst : public ExprAst {
public:
    DiferenteAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class MultiplicacaoAst : public ExprAst {
public:
    MultiplicacaoAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class DivisaoAst : public ExprAst {
public:
    DivisaoAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class AndAst : public ExprAst {
public:
    AndAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class OrAst : public ExprAst {
public:
    OrAst(ExprAst* esq, ExprAst* dir);

    ExprAst* esq_;
    ExprAst* dir_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class NuloAst : public ExprAst {
public:
    NuloAst() {}

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class ListaArgsChamada : public ExprAst {
public:
    ListaArgsChamada(ExprAst* fator);
    ListaArgsChamada(ExprAst* tail, ExprAst* fator);

    vector<ExprAst*> args_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

class ChamadaFuncaoAst : public ExprAst {
public:
    ChamadaFuncaoAst(const string &id, ExprAst* lista);

    string id_;
    ListaArgsChamada* lista_;

    Value *codegen() override;
    tipo_expressao get_type() override;
};

#endif
