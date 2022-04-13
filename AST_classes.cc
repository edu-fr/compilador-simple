#include "AST_classes.hh"

/* ******************
 *      PROGRAMA    *
 * ****************** */

ProgramaAst* ast_root;

ProgramaAst::ProgramaAst(DeclaracoesAst* dec, BaseComandoAst *acao)
    : dec_(dec), acao_((ListaComandosAst*) acao)
{
    // TESTE GLOBAIS
//    for ( auto i : dec->globais_->lista_declaracoes_)
//    {
//        cout << "identificador: " << i->id_ << endl;
//        cout << "tipo: " << i->tipo_ << endl;
//        cout << "expressao: " << ((InteiroAst*) i->expressao_)->val_ << endl;
//    }
}

/* ******************
 *    DECLARACOES   *
 * ****************** */

/* declaracao de tipos */

TipoCampoAst::TipoCampoAst(const string &id, const string &tipo)
    : id_(id), tipo_(tipo) {}

TipoCamposAst::TipoCamposAst(BaseDecTiposAst* campo)
{
    lista_campos_.push_back((TipoCampoAst*) campo);
}

TipoCamposAst::TipoCamposAst(BaseDecTiposAst* tail, BaseDecTiposAst* campo)
{
    lista_campos_ = ((TipoCamposAst*) tail)->lista_campos_;
    lista_campos_.push_back((TipoCampoAst*) campo);
}

DescritorTipoIdAst::DescritorTipoIdAst(const string &id)
    : id_(id) {}

DescritorTipoCamposAst::DescritorTipoCamposAst(BaseDecTiposAst* campos)
    : tipo_campos_((TipoCamposAst*) campos) {}

TipoConstantesAst::TipoConstantesAst(int val)
{
    tipo_ctes_.push_back(val);
}

TipoConstantesAst::TipoConstantesAst(TipoConstantesAst* ctes, int val)
{
    tipo_ctes_ = ctes->tipo_ctes_;
    tipo_ctes_.push_back(val);
}

DescritorTipoCtesAst::DescritorTipoCtesAst(TipoConstantesAst* ctes, const string &tipo)
    : tipo_constantes_(ctes), tipo_(tipo) {}

DeclaracaoTipoAst::DeclaracaoTipoAst(const string &id, BaseDescritorTipoAst* descritor_tipo)
    : id_(id), descritor_tipo_(descritor_tipo) {}

DeclaracaoTiposAst::DeclaracaoTiposAst(BaseDecTiposAst* declaracao)
{
    lista_declaracoes_.push_back((DeclaracaoTipoAst*) declaracao);
}

DeclaracaoTiposAst::DeclaracaoTiposAst(BaseDecTiposAst* tail, BaseDecTiposAst* declaracao)
{
    lista_declaracoes_ = ((DeclaracaoTiposAst*) tail)->lista_declaracoes_;
    lista_declaracoes_.push_back((DeclaracaoTipoAst*) declaracao);
}

/* declaracao de variaveis */

DeclaracaoVariavelAst::DeclaracaoVariavelAst(const string &id, const string &tipo, ExprAst* expressao)
    : id_(id), tipo_(tipo), expressao_(expressao) {}

ListaDecVarAst::ListaDecVarAst(BaseDecVarAst *declaracao)
{
    lista_declaracoes_.push_back((DeclaracaoVariavelAst*)declaracao);
}

ListaDecVarAst::ListaDecVarAst(BaseDecVarAst *tail, BaseDecVarAst *declaracao)
{
    lista_declaracoes_ = ((ListaDecVarAst*) tail)->lista_declaracoes_;
    lista_declaracoes_.push_back((DeclaracaoVariavelAst*) declaracao);
}

/* declaracao funcoes */

ArgumentoAst::ArgumentoAst(Modificador mod, const string &id, const string &tipo)
    : mod_(mod), id_(id), tipo_(tipo) {
//    cout << "Modificador: " << mod_ << endl;
//    cout << "Id: " << id_ << endl;
//    cout << "Tipo: " << tipo_ << endl;
}

ListaArgsAst::ListaArgsAst(BaseArgsAst* arg)
{
    lista_argumentos_.push_back((ArgumentoAst*) arg);
}

ListaArgsAst::ListaArgsAst(BaseArgsAst* tail, BaseArgsAst* arg)
{
    lista_argumentos_ = ((ListaArgsAst*) tail)->lista_argumentos_;
    lista_argumentos_.push_back((ArgumentoAst*) arg);
}

CorpoAst::CorpoAst(BaseDecVarAst *var_locais, BaseComandoAst *lista_comandos)
    : variaveis_locais_((ListaDecVarAst*) var_locais), lista_comandos_((ListaComandosAst*) lista_comandos) {}

DeclaracaoFuncaoAst::DeclaracaoFuncaoAst(const string &id, BaseArgsAst *args, CorpoAst* corpo)
    : id_(id), args_((ListaArgsAst*)args), corpo_(corpo) {
//    cout << "nome do procedimento: " << id_ << endl;
}

DeclaracaoFuncaoAst::DeclaracaoFuncaoAst(const string &id, BaseArgsAst* args, const string &ret, CorpoAst* corpo)
    : id_(id), args_((ListaArgsAst*)args), retorno_(ret), corpo_(corpo) {
//    cout << "nome da funcao: " << id_ << endl;
}

DeclaracaoFuncoesAst::DeclaracaoFuncoesAst(BaseDecFuncAst* declaracao)
{
    lista_declaracoes_.push_back((DeclaracaoFuncaoAst*) declaracao);
}

DeclaracaoFuncoesAst::DeclaracaoFuncoesAst(BaseDecFuncAst* tail, BaseDecFuncAst* declaracao)
{
    lista_declaracoes_ = ((DeclaracaoFuncoesAst*) tail)->lista_declaracoes_;
    lista_declaracoes_.push_back((DeclaracaoFuncaoAst*) declaracao);
}

/* declaracoes */

DeclaracoesAst::DeclaracoesAst(BaseDecTiposAst *tipos, BaseDecVarAst *globais, BaseDecFuncAst *funcoes)
    : tipos_((DeclaracaoTiposAst*) tipos), globais_((ListaDecVarAst*) globais), funcoes_((DeclaracaoFuncoesAst*) funcoes) {}


/* ******************
 *        ACOES     *
 * ****************** */


ListaComandosAst::ListaComandosAst(BaseComandoAst* comando)
{
    lista_comandos_.push_back(comando);
}

ListaComandosAst::ListaComandosAst(BaseComandoAst *tail, BaseComandoAst *comando)
{
    lista_comandos_ = ((ListaComandosAst*) tail)->lista_comandos_;
    lista_comandos_.push_back(comando);

    // cout << "acao 1: " << ((LocalAst*)((AtribuicaoAst*) lista_comandos_[0])->esq_)->val_ << endl;
    // cout << "acao 1: " << ((InteiroAst*)((AtribuicaoAst*) lista_comandos_[0])->dir_)->val_ << endl;
}

AtribuicaoAst::AtribuicaoAst(LocalAst *esq, ExprAst *dir)
    : esq_(esq), dir_(dir) {}

SeAst::SeAst(ExprAst* expr, BaseComandoAst* comandos_v)
    : expr_(expr), comandos_verdadeiro_((ListaComandosAst*) comandos_v) {}

SeAst::SeAst(ExprAst* expr, BaseComandoAst* comandos_v, BaseComandoAst* comandos_f)
    : expr_(expr), comandos_verdadeiro_((ListaComandosAst*) comandos_v), comandos_falso_((ListaComandosAst*) comandos_f) {}

ParaAst::ParaAst(const string &it, ExprAst* inicio, ExprAst* fim, BaseComandoAst* comandos)
    : it_(it), expr_inicio_(inicio), expr_fim_(fim), comandos_((ListaComandosAst*) comandos) {}

EnquantoAst::EnquantoAst(ExprAst* expr, BaseComandoAst* comandos)
    : expr_(expr), comandos_((ListaComandosAst*) comandos) {}

RetorneAst::RetorneAst(ExprAst* expr)
    : expr_(expr) {}


/* ******************
 *    EXPRESSOES    *
 * ****************** */

AtribuicaoRegistroAst::AtribuicaoRegistroAst(const string &id, ExprAst* expr)
    : id_(id), expr_(expr) {}

CriacaoRegistroAst::CriacaoRegistroAst(ExprAst* atribuicao_registro)
{
    lista_.push_back((AtribuicaoRegistroAst*) atribuicao_registro);
}

CriacaoRegistroAst::CriacaoRegistroAst(ExprAst* tail, ExprAst* atribuicao_registro)
{
    lista_ = ((CriacaoRegistroAst*) tail)->lista_;
    lista_.push_back((AtribuicaoRegistroAst*) atribuicao_registro);
}

InteiroAst::InteiroAst(int val)
    : val_(val) {}

RealAst::RealAst(double val)
    : val_(val) {}

CadeiaAst::CadeiaAst(const std::string &val)
    : val_(val) {}

LocalAst::LocalAst(const std::string &val)
    : val_(val) {}

SomaAst::SomaAst(ExprAst* esq, ExprAst* dir)
    : esq_(esq), dir_(dir) {}

SubtracaoAst::SubtracaoAst(ExprAst* esq, ExprAst* dir)
    : esq_(esq), dir_(dir) {}

MaiorAst::MaiorAst(ExprAst* esq, ExprAst* dir)
    : esq_(esq), dir_(dir) {}

MenorAst::MenorAst(ExprAst* esq, ExprAst* dir)
    : esq_(esq), dir_(dir) {}

MaiorIgualAst::MaiorIgualAst(ExprAst* esq, ExprAst* dir)
    : esq_(esq), dir_(dir) {}

MenorIgualAst::MenorIgualAst(ExprAst* esq, ExprAst* dir)
    : esq_(esq), dir_(dir) {}

EquivalenteAst::EquivalenteAst(ExprAst* esq, ExprAst* dir)
    : esq_(esq), dir_(dir) {}

DiferenteAst::DiferenteAst(ExprAst* esq, ExprAst* dir)
    : esq_(esq), dir_(dir) {}

MultiplicacaoAst::MultiplicacaoAst(ExprAst* esq, ExprAst* dir)
    : esq_(esq), dir_(dir) {}

DivisaoAst::DivisaoAst(ExprAst* esq, ExprAst* dir)
    : esq_(esq), dir_(dir) {}

AndAst::AndAst(ExprAst* esq, ExprAst* dir)
    : esq_(esq), dir_(dir) {}

OrAst::OrAst(ExprAst* esq, ExprAst* dir)
    : esq_(esq), dir_(dir) {}

ListaArgsChamada::ListaArgsChamada(ExprAst* fator)
{
    args_.push_back(fator);
}

ListaArgsChamada::ListaArgsChamada(ExprAst* tail, ExprAst* fator)
{
    args_ = ((ListaArgsChamada*) tail)->args_;
    args_.push_back(fator);
}

ChamadaFuncaoAst::ChamadaFuncaoAst(const string &id, ListaArgsChamada* lista)
    : id_(id), lista_(lista) {}