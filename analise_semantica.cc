#include "analise_semantica.hh"

map<string, Value*> named_values;

void declaracao_variavel(DeclaracaoVariavelAst* declaracao)
{

}

void declaracao_globais(ListaDecVarAst* lista_var)
{
    for (auto i : lista_var->lista_declaracoes_)
        declaracao_variavel(i);
}

void declaracao(DeclaracoesAst* declaracoes)
{
    declaracao_globais(declaracoes->globais_);
}

void acao(ListaComandosAst* lista_comandos)
{

}

void analise_semantica()
{
    declaracao(ast_root->dec_);
    acao(ast_root->acao_);
}

