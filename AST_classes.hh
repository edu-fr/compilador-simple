#ifndef AST_classes_HH
#define AST_classes_HH

#include <string>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class ExpAst;
class LocalAst;
class AcaoAst;
class DeclaracoesAst;


/* ******************
 *      PROGRAMA    *
 * ****************** */

class ProgramaAst {
public:
    ProgramaAst(DeclaracoesAst* dec, AcaoAst* acao);
    ~ProgramaAst() {}

    DeclaracoesAst* dec_;
    AcaoAst* acao_;
};

extern ProgramaAst* ast_root;


/* ******************
 *    DECLARACOES   *
 * ****************** */


class BaseDecVarAst {
public:
    BaseDecVarAst() {}
    ~BaseDecVarAst() {}
};

class DeclaracaoVariavelAst : public BaseDecVarAst {
public:
    DeclaracaoVariavelAst(const string &id, const string &tipo, ExpAst* expressao);
    ~DeclaracaoVariavelAst();

    string id_, tipo_;
    ExpAst* expressao_;
};

class DeclaracaoGlobaisAst : public BaseDecVarAst {
public:
    DeclaracaoGlobaisAst(BaseDecVarAst* declaracao);
    DeclaracaoGlobaisAst(BaseDecVarAst* declaracao, BaseDecVarAst* tail);
    ~DeclaracaoGlobaisAst() {}

    vector<DeclaracaoVariavelAst*> lista_declaracoes_;
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

class DeclaracoesAst {
public:
    DeclaracoesAst() {}
    DeclaracoesAst(DeclaracaoTiposAst* tipos, DeclaracaoGlobaisAst* globais, DeclaracaoFuncoesAst* funcoes);

    DeclaracaoGlobaisAst* globais_;
    DeclaracaoFuncoesAst* funcoes_;
    DeclaracaoTiposAst* tipos_;
};


/* ******************
 *        ACOES     *
 * ****************** */


class AcaoAst {
public:
    AcaoAst() {}
    AcaoAst(AcaoAst* comando);
    AcaoAst(AcaoAst* comando, AcaoAst* tail);
    ~AcaoAst() {}

    vector<AcaoAst*> lista_comandos_;
};

class AtribuicaoAst : public AcaoAst {
public:
    AtribuicaoAst(LocalAst* esq, ExpAst* dir);

    LocalAst* esq_;
    ExpAst* dir_;
};


/* ******************
 *    EXPRESSOES    *
 * ****************** */


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

#endif
