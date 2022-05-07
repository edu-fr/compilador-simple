#include "analise_semantica.hh"

#include <iostream>
#include <unordered_map>

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

namespace as {

unordered_map<string, DeclaracaoVariavelAst*> tabela_variaveis;
unordered_map<string, DeclaracaoFuncaoAst*> tabela_funcoes;
unordered_map<string, DeclaracaoTipoAst*> tabela_tipos;

string hash_(string id, string escopo)
{
    return id.append("$" + escopo); // '$' é um caracter especial que não é usado em identificadores
}

void erro(string message)
{
    cout << "ANALISE SEMANTICA: " << message << endl;
    // exit(EXIT_FAILURE);
}

enum tipos {
    INTEIRO,
    REAL,
    CADEIA,
    REGISTRO,
    VETOR
};

int stringType_to_enum (const string &tipo)
{
    if (tipo == "inteiro")
        return INTEIRO;
    else if (tipo == "real")
        return REAL;
    else if (tipo == "cadeia")
        return CADEIA;
    else if (tipo == "registro")
        return REGISTRO;
    else if (tipo == "vetor")
        return VETOR;

    return -1;
}

bool inserir_funcoes_padrao()
{
    vector<string> funcoes_padrao = {"main", "imprimei"};
    for(auto nome_funcao : funcoes_padrao) {
        tabela_funcoes.insert(pair<string, DeclaracaoFuncaoAst*>(nome_funcao, nullptr));
    }
    return true;
}

bool comando(BaseComandoAst* c)
{
//    cout << "comando" << endl;
    switch (c->get_type()) {
    case tipo_comando::LISTA_COMANDOS:
        break;
    case tipo_comando::ATRIBUICAO:
//        cout << "ATRIBUICAO" << endl;
        if (tabela_variaveis.find(((LocalAst*)((AtribuicaoAst*) c)->esq_)->val_)
                == tabela_variaveis.end()) {
            erro("Variavel nao declarada na atribuicao");
        }

        if (((AtribuicaoAst*) c)->esq_->get_type() // na verdade isso a analise sintatica ja pega
                != tipo_expressao::LOCAL) {
            erro("O lado esquerdo da atribuicao deve ser um local.");
        }
        return true;
        break;
    case tipo_comando::SE:
        break;
    case tipo_comando::PARA:
        break;
    case tipo_comando::ENQUANTO:
        break;
    case tipo_comando::RETORNE:
        break;
    case tipo_comando::PARE:
        break;
    case tipo_comando::CONTINUE:
        break;
    case tipo_comando::CHAMADA_PROCEDIMENTO:
        break;
    default:
        break;
    }
    return false;
}

bool acao(ListaComandosAst* lista_comandos)
{
//    cout << "acao" << endl;
    for (auto c : lista_comandos->lista_comandos_)
        comando(c);

    return true;
}

int verificacao_tipo_expr_aritmetica(string tipo)
{
    switch (stringType_to_enum(tipo))
    {
    case INTEIRO:

        break;

    default:
        erro("Tipo inválido");
        break;
    }
    return true;
}

bool declaracao_variavel(DeclaracaoVariavelAst* declaracao)
{
//    cout << "declaracao variavel" << endl;
//    string key = hash_(declaracao->id_, escopo);
    if (tabela_variaveis.find(declaracao->id_) != tabela_variaveis.end()) {
        erro("Variável já declarada neste escopo");
    } else {
        tabela_variaveis.insert(pair<string, DeclaracaoVariavelAst*>(declaracao->id_, declaracao));
    }
    //  switch (expressao_to_enum(declaracao->expressao_))
    //  {
    //  case SOMA: case SUBTRACAO: case MULTIPLICACAO: case DIVISAO:
    //    stringType_to_enum(declaracao->tipo) == verificacao_tipo();
    //    break;

    //  default:
    //    break;
    //  }
    return true;
}

bool declaracao_tipo(DeclaracaoTipoAst* declaracao)
{
return true;
}

bool add_tabela_variaveis(string arg)
{
    if (tabela_variaveis.find(declaracao->id_) != tabela_variaveis.end()) {
        erro("Variável já declarada neste escopo");
    } else {
        tabela_variaveis.insert(pair<string, DeclaracaoVariavelAst*>(declaracao->id_, declaracao));
    }
}

bool declaracao_funcao(DeclaracaoFuncaoAst* declaracao)
{
//    cout << "declaracao funcao" << endl;
    if (declaracao->corpo_->variaveis_locais_) {
        tabela_variaveis.clear();
        for (auto var : declaracao->args_->lista_argumentos_)
            declaracao_variavel(var);

        for (auto var : declaracao->corpo_->variaveis_locais_->lista_declaracoes_)
            declaracao_variavel(var);
    }

    acao(declaracao->corpo_->lista_comandos_);
    return true;
}

bool declaracao_funcoes(DeclaracaoFuncoesAst* lista_funcoes)
{
//    cout << "declaracao funcoes" << endl;
    for (auto funcao : lista_funcoes->lista_declaracoes_)
        declaracao_funcao(funcao);

    return true;
}

bool declaracao_tipos(DeclaracaoTiposAst* lista_tipos)
{
    for (auto i : lista_tipos->lista_declaracoes_)
        declaracao_tipo(i);

    return true;
}

bool declaracao_globais(ListaDecVarAst* lista_var)
{
    for (auto i : lista_var->lista_declaracoes_)
        declaracao_variavel(i, "global");

    return true;
}

bool declaracao(DeclaracoesAst* declaracoes)
{
//    cout << "declaracao" << endl;
    if (declaracoes->tipos_ != nullptr)
        declaracao_tipos(declaracoes->tipos_);
    if (declaracoes->globais_ != nullptr)
        declaracao_globais(declaracoes->globais_);
    if (declaracoes->funcoes_ != nullptr)
        declaracao_funcoes(declaracoes->funcoes_);

    return true;
}

bool insere_funcoes_tabela(const vector<DeclaracaoFuncaoAst*> &dec_funcoes)
{
    for (auto declaracao : dec_funcoes) {
        if (tabela_funcoes.find(declaracao->id_) != tabela_funcoes.end()) {
            erro("Função já declarada neste escopo: " + declaracao->id_);
        } else {
            tabela_funcoes.insert(pair<string, DeclaracaoFuncaoAst*>(declaracao->id_, declaracao));
        }
    }

    return true;
}

//===----------------------------------------------------------------------===//
// Analise semantica
//===----------------------------------------------------------------------===//

bool analise_semantica()
{
//    cout << "oir" << endl;
    inserir_funcoes_padrao();
    insere_funcoes_tabela(ast_root->dec_->funcoes_->lista_declaracoes_);
    declaracao(ast_root->dec_);
    acao(ast_root->acao_);

    return true;
}

} /* end namespace as */