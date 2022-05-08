#include "analise_semantica.hh"

#include <iostream>
#include <unordered_map>

//===----------------------------------------------------------------------===//
// Implementacoes AST get_type
//===----------------------------------------------------------------------===//

tipo_comando ListaComandosAst::get_type() { return tipo_comando::LISTA_COMANDOS; }
tipo_comando AtribuicaoAst::get_type() { return tipo_comando::ATRIBUICAO; }
tipo_comando SeAst::get_type() { return tipo_comando::SE; }
tipo_comando ParaAst::get_type() { return tipo_comando::PARA; }
tipo_comando EnquantoAst::get_type() { return tipo_comando::ENQUANTO; }
tipo_comando RetorneAst::get_type() { return tipo_comando::RETORNE; }
tipo_comando PareAst::get_type() { return tipo_comando::PARE; }
tipo_comando ContinueAst::get_type() { return tipo_comando::CONTINUE; }
tipo_comando ChamadaProcedimentoAst::get_type() { return tipo_comando::CHAMADA_PROCEDIMENTO; }

tipo_expressao AtribuicaoRegistroAst::get_type() { return tipo_expressao::ATRIBUICAO_REG; }
tipo_expressao CriacaoRegistroAst::get_type() { return tipo_expressao::CRIACAO_REG; }
tipo_expressao InteiroAst::get_type() { return tipo_expressao::INTEIRO; }
tipo_expressao RealAst::get_type() { return tipo_expressao::REAL; }
tipo_expressao CadeiaAst::get_type() { return tipo_expressao::CADEIA; }
tipo_expressao LocalAst::get_type() { return tipo_expressao::LOCAL; }
tipo_expressao SomaAst::get_type() { return tipo_expressao::SOMA; }
tipo_expressao SubtracaoAst::get_type() { return tipo_expressao::SUBTRACAO; }
tipo_expressao MaiorAst::get_type() { return tipo_expressao::MAIOR; }
tipo_expressao MenorAst::get_type() { return tipo_expressao::MENOR; }
tipo_expressao MaiorIgualAst::get_type() { return tipo_expressao::MAIOR_IGUAL; }
tipo_expressao MenorIgualAst::get_type() { return tipo_expressao::MENOR_IGUAL; }
tipo_expressao EquivalenteAst::get_type() { return tipo_expressao::EQUIVALENTE; }
tipo_expressao DiferenteAst::get_type() { return tipo_expressao::DIFERENTE; }
tipo_expressao MultiplicacaoAst::get_type() { return tipo_expressao::MULTIPLICACAO; }
tipo_expressao DivisaoAst::get_type() { return tipo_expressao::DIVISAO; }
tipo_expressao AndAst::get_type() { return tipo_expressao::AND; }
tipo_expressao OrAst::get_type() { return tipo_expressao::OR; }
tipo_expressao NuloAst::get_type() { return tipo_expressao::NULO; }
tipo_expressao ListaArgsChamada::get_type() { return tipo_expressao::LISTA_ARGS_CHAMADA; }
tipo_expressao ChamadaFuncaoAst::get_type() { return tipo_expressao::CHAMADA_FUNCAO; }

//===----------------------------------------------------------------------===//
// Analise semantica globais
//===----------------------------------------------------------------------===//

typedef struct variavel { 
    string id_;
    tipo_expressao tipo_;
    ExprAst* expressao_;

    variavel(string id, tipo_expressao tipo, ExprAst* expr) : id_(id), tipo_(tipo), expressao_(expr) {}
} variavel;

unordered_map<string, variavel> tabela_variaveis;
unordered_map<string, DeclaracaoFuncaoAst*> tabela_funcoes;
unordered_map<string, DeclaracaoTipoAst*> tabela_tipos;

bool analise_semantica_return = true;

//===----------------------------------------------------------------------===//
// Analise semantica funcoes
//===----------------------------------------------------------------------===//

string hash_(string id, string escopo)
{
    return id.append("$" + escopo); // '$' é um caracter especial que não é usado em identificadores
}

void erro(string message)
{
    cout << "ANALISE SEMANTICA: " << message << endl;
    analise_semantica_return = false;
}

tipo_expressao stringType_to_enum (const string &tipo)
{
    if (tipo == "inteiro")
        return tipo_expressao::INTEIRO;
    else if (tipo == "real")
        return tipo_expressao::REAL;
    else if (tipo == "cadeia")
        return tipo_expressao::CADEIA;
    return tipo_expressao::OR;
}

void inserir_funcoes_padrao()
{
    DeclaracaoFuncaoAst* imprimei = new DeclaracaoFuncaoAst{string{"imprimei"}, new ListaArgsAst{new ArgumentoAst{Modificador::VALOR, "i", "inteiro"}}, {}, nullptr};
    
    tabela_funcoes.insert(pair<string, DeclaracaoFuncaoAst*>("main", nullptr));
    tabela_funcoes.insert(pair<string, DeclaracaoFuncaoAst*>("imprimei", imprimei));
}

string tipo_expressao_to_str(tipo_expressao tipo)
{
    switch (tipo)
    {
    case tipo_expressao::INTEIRO:
        return "inteiro";
        break;

    case tipo_expressao::REAL:
        return "real";
        break;

    case tipo_expressao::CADEIA:
        return "cadeia";
        break;

    case tipo_expressao::LOCAL:
        return "local";
        break;

    default:
        return "tipo invalido";
        break;
    }
}

tipo_expressao get_expr_type(ExprAst* expr) 
{
    switch (expr->get_type())
    {
    case tipo_expressao::INTEIRO:
        return tipo_expressao::INTEIRO;

    case tipo_expressao::REAL:
        return tipo_expressao::REAL;

    case tipo_expressao::LOCAL:
        return (*tabela_variaveis.find(((LocalAst*)expr)->val_)).second.tipo_;

    case tipo_expressao::SOMA: {
        auto soma = (SomaAst*) expr;
        tipo_expressao tipo_esq = get_expr_type(soma->esq_), tipo_dir = get_expr_type(soma->dir_);
        if (tipo_dir == tipo_expressao::INTEIRO || tipo_dir == tipo_expressao::REAL) {
            if (tipo_esq == tipo_dir) {
                return tipo_dir;
            } else {
                erro("Soma com tipos distintos");
            }
        }
        break;
    }

    case tipo_expressao::SUBTRACAO: {
        auto sub = (SubtracaoAst*) expr;
        tipo_expressao tipo_esq = get_expr_type(sub->esq_), tipo_dir = get_expr_type(sub->dir_);
        if (tipo_dir == tipo_expressao::INTEIRO || tipo_dir == tipo_expressao::REAL) {
            if (tipo_esq == tipo_dir) {
                return tipo_dir;
            } else {
                erro("Subtracao com tipos distintos");
            }
        }
        break;
    }

    case tipo_expressao::MULTIPLICACAO: {
        auto mul = (MultiplicacaoAst*) expr;
        tipo_expressao tipo_esq = get_expr_type(mul->esq_), tipo_dir = get_expr_type(mul->dir_);
        if (tipo_dir == tipo_expressao::INTEIRO || tipo_dir == tipo_expressao::REAL) {
            if (tipo_esq == tipo_dir) {
                return tipo_dir;
            } else {
                erro("Multiplicacao com tipos distintos");
            }
        }
        break;
    }

    case tipo_expressao::CHAMADA_FUNCAO: {
        auto funcao_tabela = tabela_funcoes.find(((ChamadaFuncaoAst*) expr)->id_);

        if ((*funcao_tabela).second->retorno_.empty())
            erro("O procedimento " + (*funcao_tabela).second->id_ + " nao retorna valor.");

        if (funcao_tabela == tabela_funcoes.end()) {
            erro("Funcao " + ((ChamadaFuncaoAst*) expr)->id_ + "não declarada");
        }

        auto argumentos_chamada = ((ChamadaFuncaoAst*) expr)->lista_;
        if ((*funcao_tabela).second->args_ == nullptr && argumentos_chamada != nullptr) {
            erro("A funcao " + (*funcao_tabela).second->id_ + " nao aceita argumentos");
        }

        if ((*funcao_tabela).second->args_ != nullptr && argumentos_chamada == nullptr) {
            erro("A funcao " + (*funcao_tabela).second->id_ + " requer argumentos");
        }

        if ((*funcao_tabela).second->args_->lista_argumentos_.size() != argumentos_chamada->args_.size()) {
            erro ("numero de argumentos diferente");
        }

        for (unsigned i = 0; i < (*funcao_tabela).second->args_->lista_argumentos_.size(); i++) {
            if (stringType_to_enum((*funcao_tabela).second->args_->lista_argumentos_[i]->tipo_) != get_expr_type(argumentos_chamada->args_[i]))
                erro("Argumento: " + (*funcao_tabela).second->args_->lista_argumentos_[i]->id_
                     + " precisa ser do tipo " + (*funcao_tabela).second->args_->lista_argumentos_[i]->tipo_ + ". Tipo recebido: " +
                     tipo_expressao_to_str(get_expr_type(argumentos_chamada->args_[i])));
        }

        return stringType_to_enum((*funcao_tabela).second->retorno_);
    }
        break;
    case tipo_expressao::INVALIDO: break;
    case tipo_expressao::ATRIBUICAO_REG: break;
    case tipo_expressao::CRIACAO_REG: break;
    case tipo_expressao::CADEIA: break;
    case tipo_expressao::MAIOR: break;
    case tipo_expressao::MENOR: break;
    case tipo_expressao::MAIOR_IGUAL: break;
    case tipo_expressao::MENOR_IGUAL: break;
    case tipo_expressao::EQUIVALENTE: break;
    case tipo_expressao::DIFERENTE: break;
    case tipo_expressao::DIVISAO: break;
    case tipo_expressao::AND: break;
    case tipo_expressao::OR: break;
    case tipo_expressao::NULO: break;
    case tipo_expressao::LISTA_ARGS_CHAMADA: break;
    }

    return tipo_expressao::INVALIDO;
}

void comando(BaseComandoAst* c)
{
    switch (c->get_type())
    {
    case tipo_comando::LISTA_COMANDOS: break;

    case tipo_comando::ATRIBUICAO: {
        auto atribuicao = (AtribuicaoAst*) c;
        if (tabela_variaveis.find(((LocalAst*)atribuicao->esq_)->val_)
                == tabela_variaveis.end()) {
            erro("Variavel nao declarada na atribuicao");
        }

        if (get_expr_type(atribuicao->esq_) != get_expr_type(atribuicao->dir_)) {
            erro("Atribuicao: os tipos nao coincidem.\n Local: "+ tipo_expressao_to_str(get_expr_type(atribuicao->esq_)) +
                 "\nExpressao: " + tipo_expressao_to_str(get_expr_type(atribuicao->dir_)));
        }
        break;
    }

    case tipo_comando::SE: break;
    case tipo_comando::PARA: break;
    case tipo_comando::ENQUANTO: break;
    case tipo_comando::RETORNE: break;
    case tipo_comando::PARE: break;
    case tipo_comando::CONTINUE: break;

    case tipo_comando::CHAMADA_PROCEDIMENTO: {
        auto procedimento_tabela = tabela_funcoes.find(((ChamadaProcedimentoAst*) c)->id_);

        if (!(*procedimento_tabela).second->retorno_.empty()) {
            erro("O valor de retorno da funcao " + (*procedimento_tabela).second->id_ + " deve ser utilizado.");
        }

        if (procedimento_tabela == tabela_funcoes.end()) {
            erro("procedimento " + ((ChamadaProcedimentoAst*) c)->id_ + "não encontrado");
        }

        auto argumentos_chamada = ((ChamadaProcedimentoAst*) c)->lista_;

        if ((*procedimento_tabela).second->args_ == nullptr && argumentos_chamada != nullptr) {
            erro("O procedimento " + (*procedimento_tabela).second->id_ + " nao aceita argumentos");
        }

        if ((*procedimento_tabela).second->args_ != nullptr && argumentos_chamada == nullptr) {
            erro("O procedimento " + (*procedimento_tabela).second->id_ + " requer argumentos");
        }

        if ((*procedimento_tabela).second->args_->lista_argumentos_.size() != argumentos_chamada->args_.size()) {
            erro ("numero de argumentos diferente");
        }

        for (unsigned i = 0; i < (*procedimento_tabela).second->args_->lista_argumentos_.size(); i++) {
            if (stringType_to_enum((*procedimento_tabela).second->args_->lista_argumentos_[i]->tipo_) != get_expr_type(argumentos_chamada->args_[i]))
                return erro("Argumento: " + (*procedimento_tabela).second->args_->lista_argumentos_[i]->id_
                            + " precisa ser do tipo " + (*procedimento_tabela).second->args_->lista_argumentos_[i]->tipo_ + ". Tipo recebido: " +
                            tipo_expressao_to_str(get_expr_type(argumentos_chamada->args_[i])));
        }
        break;
    }
        
    default: break;
    }
}

void acao(ListaComandosAst* lista_comandos)
{
    for (auto c : lista_comandos->lista_comandos_)
        comando(c);
}

void declaracao_variavel(DeclaracaoVariavelAst* declaracao)
{
    if (tabela_variaveis.find(declaracao->id_) != tabela_variaveis.end()) {
        erro("Variável já declarada neste escopo");
    } else {
        tabela_variaveis.insert(pair<string, variavel>(declaracao->id_,
                                                       variavel(declaracao->id_,
                                                                stringType_to_enum(declaracao->tipo_),
                                                                declaracao->expressao_)));
    }
}

void declaracao_funcao(DeclaracaoFuncaoAst* declaracao)
{
    if (declaracao->retorno_.empty()) {
        for (auto comando : declaracao->corpo_->lista_comandos_->lista_comandos_) {
            if (comando->get_type() == tipo_comando::RETORNE)
                erro("Declaracao de procedimento nao retorna valor");
        }
    } else {
        if (declaracao->corpo_->lista_comandos_->lista_comandos_.back()->get_type()
                != tipo_comando::RETORNE)
            erro("A funcao nao esta retornando valor");
    }

    if (declaracao->corpo_->variaveis_locais_) {
        tabela_variaveis.clear();
        for (auto var : declaracao->args_->lista_argumentos_) {
            tabela_variaveis.insert(pair<string, variavel>(var->id_, variavel(var->id_, stringType_to_enum(var->tipo_), nullptr)));
        }

        for (auto var : declaracao->corpo_->variaveis_locais_->lista_declaracoes_) {
            declaracao_variavel(var);
        }
    }
    acao(declaracao->corpo_->lista_comandos_);
}

void declaracao_funcoes(DeclaracaoFuncoesAst* lista_funcoes)
{
    for (auto funcao : lista_funcoes->lista_declaracoes_) {
        declaracao_funcao(funcao);
    }
}

void declaracao_globais(ListaDecVarAst* lista_var)
{
    for (auto declaracao : lista_var->lista_declaracoes_)
        declaracao_variavel(declaracao);
}

void declaracao(DeclaracoesAst* declaracoes)
{
    //    if (declaracoes->tipos_ != nullptr)
    //        declaracao_tipos(declaracoes->tipos_);
    if (declaracoes->globais_ != nullptr)
        declaracao_globais(declaracoes->globais_);
    if (declaracoes->funcoes_ != nullptr)
        declaracao_funcoes(declaracoes->funcoes_);
}

void insere_funcoes_tabela(const vector<DeclaracaoFuncaoAst*> &dec_funcoes)
{
    for (auto declaracao : dec_funcoes) {
        if (tabela_funcoes.find(declaracao->id_) != tabela_funcoes.end()) {
            erro("Função já declarada neste escopo: " + declaracao->id_);
        } else {
            tabela_funcoes.insert(pair<string, DeclaracaoFuncaoAst*>(declaracao->id_, declaracao));
        }
    }
}

//===----------------------------------------------------------------------===//
// Debug
//===----------------------------------------------------------------------===//

void print_tabela_var()
{
    for (auto i : tabela_variaveis) {
        cout << i.first << " -> " << i.second.id_ << ", " << i.second.tipo_ << endl;
    }
}

//===----------------------------------------------------------------------===//
// Analise semantica
//===----------------------------------------------------------------------===//

bool analise_semantica()
{
    inserir_funcoes_padrao();
    insere_funcoes_tabela(ast_root->dec_->funcoes_->lista_declaracoes_);
    declaracao(ast_root->dec_);
    acao(ast_root->acao_);

    // print_tabela_var();
    return analise_semantica_return;
}
