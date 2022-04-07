#ifndef AST_classes_HH
#define AST_classes_HH

#include <string>
#include <vector>
#include <memory>
#include <iostream>

class ProgramaAst {
public:
    ProgramaAst() {}
    ~ProgramaAst() {}
};

extern ProgramaAst* ast_root;

class AcaoAst : public ProgramaAst {
public:
    AcaoAst(AcaoAst* comando);
    AcaoAst(AcaoAst* comando, AcaoAst* tail);
    ~AcaoAst() {}
    
    std::vector<AcaoAst*> lista_comandos;
};

class ExpAst : public ProgramaAst {
public:
    ExpAst() {}
    ~ExpAst() {}
};

class InteiroAst : public ExpAst {
public:
    InteiroAst(int val);

    int val_;
};

class RealAst : public ExpAst {
public:
    RealAst(double val);

    double val_;
};

class CadeiaAst : public ExpAst {
public:
    CadeiaAst(const std::string &val);
    std::string val_;
};

class LocalAst : public ExpAst {
public:
    LocalAst(const std::string &val);

    std::string val_;
};

class ExprAritAst : public ExpAst {
public:
    ExprAritAst(ExpAst* esq, ExpAst* dir);

    ExpAst* esq_;
    ExpAst* dir_;
};

class AtribuicaoAst : public AcaoAst {
public:
    AtribuicaoAst(LocalAst* esq, ExpAst* dir);

    LocalAst* esq_;
    ExpAst* dir_;
};

#endif
