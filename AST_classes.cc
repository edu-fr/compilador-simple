#include "AST_classes.hh"

using namespace std;

ProgramaAst* ast_root;

ProgramaAst::ProgramaAst(DeclaracaoAst* dec, AcaoAst* acao) : dec_(dec), acao_(acao) {}

AcaoAst::AcaoAst(const AcaoAst &other) 
{
    this->lista_comandos_ = other.lista_comandos_;
}

AcaoAst::AcaoAst(AcaoAst* comando)
{

    cout << "seg fault " << endl;
    cout << "acao 1: " << ((LocalAst*)((AtribuicaoAst*) comando))->val_ << endl;
    cout << "acao 1: " << ((InteiroAst*)((AtribuicaoAst*) comando))->val_ << endl;

    lista_comandos_.push_back(comando);
}

AcaoAst::AcaoAst(AcaoAst* comando, AcaoAst* tail)
{
    lista_comandos_ = tail->lista_comandos_;
    lista_comandos_.push_back(comando);
}

InteiroAst::InteiroAst(int val) : val_(val) {}

RealAst::RealAst(double val) : val_(val) {}

CadeiaAst::CadeiaAst(const std::string &val) : val_(val) {}

LocalAst::LocalAst(const std::string &val) : val_(val) {}

ExprAritAst::ExprAritAst(ExpAst *esq, ExpAst *dir) : esq_(esq), dir_(dir) {}

AtribuicaoAst::AtribuicaoAst(LocalAst *esq, ExpAst *dir) : esq_(esq), dir_(dir) {}