#ifndef AST_classes_HH
#define AST_classes_HH

#include <string>
#include <vector>
#include <memory>
#include <iostream>

class NoAst {
    public:
    NoAst() {}
    ~NoAst() {}
};

class DeclaracaoAst : public NoAst {
    public:
    DeclaracaoAst() {}
};

class AcaoAst : public NoAst {
public:
    AcaoAst() {}
    AcaoAst(const AcaoAst &other);
    AcaoAst(AcaoAst* comando);
    AcaoAst(AcaoAst* comando, AcaoAst* tail);
    ~AcaoAst() {}
    
    std::vector<AcaoAst*> lista_comandos_;
};

// class ComandoAst : public AcaoAst {
// public:
//     ComandoAst();    
// };

class ProgramaAst : public NoAst {
public:
    ProgramaAst(DeclaracaoAst* dec, AcaoAst* acao);
    ~ProgramaAst() {}

    DeclaracaoAst* dec_;
    AcaoAst* acao_;
};

extern ProgramaAst* ast_root;

class ExpAst : public NoAst {
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
