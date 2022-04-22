#include "analise_semantica.hh"

// map<string, Value*> named_values;

void declaracao_variavel(DeclaracaoVariavelAst* declaracao)
{
    NamedValues[declaracao->id_] = declaracao->expressao_->codegen();
}

void declaracao_tipo(DeclaracaoTipoAst* declaracao)
{

}

void declaracao_funcao(DeclaracaoFuncaoAst* declaracao) 
{

}

void declaracao_funcoes(DeclaracaoFuncoesAst* lista_funcoes)
{
    for (auto i : lista_funcoes->lista_declaracoes_)
        declaracao_funcao(i);
}

void declaracao_tipos(DeclaracaoTiposAst* lista_tipos)
{
    for (auto i : lista_tipos->lista_declaracoes_)
        declaracao_tipo(i);
}

void declaracao_globais(ListaDecVarAst* lista_var)
{
    for (auto i : lista_var->lista_declaracoes_)
        declaracao_variavel(i);
}

void declaracao(DeclaracoesAst* declaracoes)
{
    if(declaracoes->tipos_ != nullptr) 
        declaracao_tipos(declaracoes->tipos_);
    if(declaracoes->globais_ != nullptr)
        declaracao_globais(declaracoes->globais_);
    if(declaracoes->funcoes_ != nullptr)
        declaracao_funcoes(declaracoes->funcoes_);
}

void acao(ListaComandosAst* lista_comandos)
{
    for (auto i : lista_comandos->lista_comandos_)
        i->codegen()->print(errs());
}

void analise_semantica()
{
    declaracao(ast_root->dec_);
    acao(ast_root->acao_);
}

