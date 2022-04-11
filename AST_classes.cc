#include "AST_classes.hh"

/* ******************
 *      PROGRAMA    *
 * ****************** */

ProgramaAst* ast_root;

ProgramaAst::ProgramaAst(DeclaracoesAst* dec, AcaoAst* acao) : dec_(dec), acao_(acao)
{
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

DeclaracaoGlobaisAst::DeclaracaoGlobaisAst(BaseDecVarAst *declaracao)
{
    lista_declaracoes_.push_back((DeclaracaoVariavelAst*)declaracao);
}

DeclaracaoGlobaisAst::DeclaracaoGlobaisAst(BaseDecVarAst *declaracao, BaseDecVarAst *tail)
{
    lista_declaracoes_ = ((DeclaracaoGlobaisAst*) tail)->lista_declaracoes_;
    lista_declaracoes_.push_back((DeclaracaoVariavelAst*) declaracao);
}

DeclaracoesAst::DeclaracoesAst(DeclaracaoTiposAst* tipos, DeclaracaoGlobaisAst* globais, DeclaracaoFuncoesAst* funcoes) : tipos_(tipos), globais_(globais), funcoes_(funcoes) {}

DeclaracaoVariavelAst::DeclaracaoVariavelAst(const string &id, const string &tipo, ExpAst* expressao) : id_(id), tipo_(tipo), expressao_(expressao) {}

/* ******************
 *        ACOES     *
 * ****************** */

AcaoAst::AcaoAst(AcaoAst* comando)
{
    lista_comandos_.push_back(comando);
}

AcaoAst::AcaoAst(AcaoAst* comando, AcaoAst* tail)
{
    lista_comandos_ = tail->lista_comandos_;
    lista_comandos_.push_back(comando);

    // cout << "acao 1: " << ((LocalAst*)((AtribuicaoAst*) lista_comandos_[0])->esq_)->val_ << endl;
    // cout << "acao 1: " << ((InteiroAst*)((AtribuicaoAst*) lista_comandos_[0])->dir_)->val_ << endl;
}

AtribuicaoAst::AtribuicaoAst(LocalAst *esq, ExpAst *dir) : esq_(esq), dir_(dir) {}


/* ******************
 *    EXPRESSOES    *
 * ****************** */

InteiroAst::InteiroAst(int val) : val_(val) {}

RealAst::RealAst(double val) : val_(val) {}

CadeiaAst::CadeiaAst(const std::string &val) : val_(val) {}

LocalAst::LocalAst(const std::string &val) : val_(val) {}

ExprAritAst::ExprAritAst(ExpAst *esq, ExpAst *dir) : esq_(esq), dir_(dir) {}

