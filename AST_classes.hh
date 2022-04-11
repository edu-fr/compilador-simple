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

/* declaracao de tipos */

class BaseDecTiposAst {
public:
    BaseDecTiposAst() {}
    ~BaseDecTiposAst() {}
};

class TipoCampoAst : public BaseDecTiposAst {
public:
    TipoCampoAst(const string &id, const string &tipo);

    string id_;
    string tipo_;
};

class TipoCamposAst : public BaseDecTiposAst {
public:
    TipoCamposAst(BaseDecTiposAst* campo);
    TipoCamposAst(BaseDecTiposAst* tail, BaseDecTiposAst* campo);

    vector<TipoCampoAst*> lista_campos_;
};

class DescritorTipoAst {
public:
    DescritorTipoAst() {}
    ~DescritorTipoAst() {}
};

class DescritorTipoIdAst : public DescritorTipoAst {
public:
    DescritorTipoIdAst(const string &id);

    string id_;
};

class DescritorTipoCamposAst : public DescritorTipoAst {
public:
    DescritorTipoCamposAst(BaseDecTiposAst* campos);

    TipoCamposAst* tipo_campos_;
};

class TipoConstantesAst {
public:
    TipoConstantesAst(int val);
    TipoConstantesAst(TipoConstantesAst* ctes, int val);

    vector<int> tipo_ctes_;
};

class DescritorTipoCtesAst : public DescritorTipoAst {
public:
    DescritorTipoCtesAst(TipoConstantesAst* ctes, const string &tipo);

    TipoConstantesAst* tipo_constantes_;
    string tipo_;
};

class DeclaracaoTipoAst : public BaseDecTiposAst {
public:
    DeclaracaoTipoAst(const string &id, DescritorTipoAst* descritor_tipo);

    string id_;
    DescritorTipoAst* descritor_tipo_;
};

class DeclaracaoTiposAst : public BaseDecTiposAst {
public:
    DeclaracaoTiposAst(BaseDecTiposAst* declaracao);
    DeclaracaoTiposAst(BaseDecTiposAst* tail, BaseDecTiposAst* declaracao);

    vector<DeclaracaoTipoAst*> lista_declaracoes_;
};


/* declaracao de variaveis */

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

// FIX ME! ESSAS DUAS CLASSES FAZEM A MESMA COISA
class DeclaracaoGlobaisAst : public BaseDecVarAst {
public:
    DeclaracaoGlobaisAst(BaseDecVarAst* declaracao);
    DeclaracaoGlobaisAst(BaseDecVarAst* tail, BaseDecVarAst* declaracao);
    ~DeclaracaoGlobaisAst() {}

    vector<DeclaracaoVariavelAst*> lista_declaracoes_;
};
// FIX ME! ESSAS DUAS CLASSES FAZEM A MESMA COISA
class DeclaracaoVarLocaisAst : public BaseDecVarAst {
public:
    DeclaracaoVarLocaisAst(BaseDecVarAst* declaracao);
    DeclaracaoVarLocaisAst(BaseDecVarAst* tail, BaseDecVarAst* declaracao);
    ~DeclaracaoVarLocaisAst() {}

    vector<DeclaracaoVariavelAst*> lista_declaracoes_;
};

/* declaracao de funcoes */

class BaseDecFuncAst {
public:
    BaseDecFuncAst() {}
    ~BaseDecFuncAst() {}
};

enum Modificador {
    VALOR,
    REFERENCIA
};

class BaseArgsAst {
public:
    BaseArgsAst() {}
    ~BaseArgsAst() {}
};

class ArgumentoAst : public BaseArgsAst {
public:
    ArgumentoAst();
    ArgumentoAst(Modificador mod, const string &id, const string &tipo);
    ~ArgumentoAst();

    Modificador mod_;
    string id_, tipo_;
};

class ListaArgsAst : public BaseArgsAst {
public:
    ListaArgsAst(BaseArgsAst* arg);
    ListaArgsAst(BaseArgsAst* tail, BaseArgsAst* arg);

    vector<ArgumentoAst*> lista_argumentos_;
};

class CorpoAst {
public:
    CorpoAst() {}
    CorpoAst(BaseDecVarAst* var_locais, AcaoAst* lista_comandos);
    ~CorpoAst() {}

    DeclaracaoVarLocaisAst* variaveis_locais_;
    AcaoAst* lista_comandos_;
};

// ??? - MELHOR SEPARAR FUNCAO E PROCEDIMENTO???
class DeclaracaoFuncaoAst : public BaseDecFuncAst {
public:
    DeclaracaoFuncaoAst(const string &id, BaseArgsAst* args, CorpoAst* corpo);
    DeclaracaoFuncaoAst(const string &id, BaseArgsAst* args, const string &ret, CorpoAst* corpo);

    string id_, retorno_;
    ListaArgsAst* args_;
    CorpoAst* corpo_;
};

class DeclaracaoFuncoesAst : public BaseDecFuncAst {
public:
    DeclaracaoFuncoesAst() {}
    DeclaracaoFuncoesAst(BaseDecFuncAst* declaracao);
    DeclaracaoFuncoesAst(BaseDecFuncAst* tail, BaseDecFuncAst* declaracao);
    ~DeclaracaoFuncoesAst() {}

    vector<DeclaracaoFuncaoAst*> lista_declaracoes_;
};

/* declaracoes */

class DeclaracoesAst {
public:
    DeclaracoesAst(BaseDecTiposAst* tipos, BaseDecVarAst* globais, BaseDecFuncAst* funcoes);
    ~DeclaracoesAst() {}

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
    AcaoAst(AcaoAst* tail, AcaoAst* comando);
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
