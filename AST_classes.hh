#ifndef AST_classes_HH
#define AST_classes_HH

#include <string>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class DeclaracaoGlobaisAst {
public:
    DeclaracaoGlobaisAst() {}
    DeclaracaoGlobaisAst(DeclaracaoGlobaisAst* declaracao);
    DeclaracaoGlobaisAst(DeclaracaoGlobaisAst* declaracao, DeclaracaoGlobaisAst* tail);
    ~DeclaracaoGlobaisAst() {}
    vector<DeclaracaoGlobaisAst*> lista_declaracoes_;    
};

class DeclaracaoFuncoesAst {
public:
    DeclaracaoFuncoesAst() {}
    DeclaracaoFuncoesAst(DeclaracaoFuncoesAst* declaracao);
    DeclaracaoFuncoesAst(DeclaracaoFuncoesAst* declaracao, DeclaracaoFuncoesAst* tail);
    ~DeclaracaoFuncoesAst() {}
    vector<DeclaracaoFuncoesAst*> lista_declaracoes_;    
};

class DeclaracaoTiposAst {
public:
    DeclaracaoTiposAst() {}
    DeclaracaoTiposAst(DeclaracaoTiposAst* declaracao);
    DeclaracaoTiposAst(DeclaracaoTiposAst* declaracao, DeclaracaoTiposAst* tail);
    ~DeclaracaoTiposAst() {}
    vector<DeclaracaoTiposAst*> lista_declaracoes_;    
};

class DeclaracaoAst {
    public:
    DeclaracaoAst() {}
    DeclaracaoAst(DeclaracaoTiposAst* tipos, DeclaracaoGlobaisAst* globais, DeclaracaoFuncoesAst* funcoes);

    DeclaracaoGlobaisAst* globais_;
    DeclaracaoFuncoesAst* funcoes_;
    DeclaracaoTiposAst* tipos_;
};


class AcaoAst {
public:
    AcaoAst() {}
    // AcaoAst(const AcaoAst &other);
    AcaoAst(AcaoAst* comando);
    AcaoAst(AcaoAst* comando, AcaoAst* tail);
    ~AcaoAst() {}
    
    vector<AcaoAst*> lista_comandos_;
};

// class ComandoAst : public AcaoAst {
// public:
//     ComandoAst();    
// };

class ProgramaAst {
public:
    ProgramaAst(DeclaracaoAst* dec, AcaoAst* acao);
    ~ProgramaAst() {}

    DeclaracaoAst* dec_;
    AcaoAst* acao_;
};

extern ProgramaAst* ast_root;

class ExpAst {
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
    CadeiaAst(const string &val);
    string val_;
};

class LocalAst : public ExpAst {
public:
    LocalAst(const string &val);

    string val_;
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

class DeclaracaoVarAst : public DeclaracaoAst {
public:
    DeclaracaoVarAst(string id, string tipo, ExpAst* expressao); 
    ~DeclaracaoVarAst();

    string id_, tipo_; 
    ExpAst* expressao_;
};

#endif
