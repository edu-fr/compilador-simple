#include "AST_classes.hh"

using namespace std;

ProgramaAst* ast_root;

ProgramaAst::ProgramaAst(DeclaracaoAst* dec, AcaoAst* acao) : dec_(dec), acao_(acao) {}

AcaoAst::AcaoAst(AcaoAst* comando)
{
    lista_comandos_.push_back(comando);
}

AcaoAst::AcaoAst(AcaoAst* comando, AcaoAst* tail)
{
    lista_comandos_ = tail->lista_comandos_;
    lista_comandos_.push_back(comando);

    cout << "acao 1: " << ((LocalAst*)((AtribuicaoAst*) lista_comandos_[0])->esq_)->val_ << endl;
    cout << "acao 1: " << ((InteiroAst*)((AtribuicaoAst*) lista_comandos_[0])->dir_)->val_ << endl;
    cout << "acao 2: " << ((LocalAst*)((AtribuicaoAst*) lista_comandos_[1])->esq_)->val_ << endl;
    cout << "acao 2: " << ((InteiroAst*)((AtribuicaoAst*) lista_comandos_[1])->dir_)->val_ << endl;    
}

InteiroAst::InteiroAst(int val) : val_(val) {}

RealAst::RealAst(double val) : val_(val) {}

CadeiaAst::CadeiaAst(const std::string &val) : val_(val) {}

LocalAst::LocalAst(const std::string &val) : val_(val) {}

ExprAritAst::ExprAritAst(ExpAst *esq, ExpAst *dir) : esq_(esq), dir_(dir) {}

AtribuicaoAst::AtribuicaoAst(LocalAst *esq, ExpAst *dir) : esq_(esq), dir_(dir) {}