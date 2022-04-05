#include "AST_classes.hh"

#include <memory>

ProgramaAst* ast_root;

InteiroAst::InteiroAst(int val) : val_(val) {}

RealAst::RealAst(double val) : val_(val) {}

CadeiaAst::CadeiaAst(const std::string &val) : val_(val) {}

ExprAritAst::ExprAritAst(ExpAst *esq, ExpAst *dir) : esq_(esq), dir_(dir) {}
