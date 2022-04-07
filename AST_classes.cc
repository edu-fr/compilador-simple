#include "AST_classes.hh"

using namespace std;

ProgramaAst* ast_root;

AcaoAst::AcaoAst(AcaoAst* comando)
{
    lista_comandos.push_back(comando);
}

AcaoAst::AcaoAst(AcaoAst* comando, AcaoAst* tail)
{
    lista_comandos = tail->lista_comandos;
    lista_comandos.push_back(comando);
}

InteiroAst::InteiroAst(int val) : val_(val) {}

RealAst::RealAst(double val) : val_(val) {}

CadeiaAst::CadeiaAst(const std::string &val) : val_(val) {}

LocalAst::LocalAst(const std::string &val) : val_(val) {}

ExprAritAst::ExprAritAst(ExpAst *esq, ExpAst *dir) : esq_(esq), dir_(dir) {}

AtribuicaoAst::AtribuicaoAst(LocalAst *esq, ExpAst *dir) : esq_(esq), dir_(dir) {}