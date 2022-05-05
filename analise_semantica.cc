//#include "analise_semantica.hh"

//#include <iostream>
//#include <unordered_map>

//unordered_map<string, DeclaracaoVariavelAst*> tabela_variaveis;
//unordered_map<string, DeclaracaoFuncaoAst*> tabela_funcoes;
//unordered_map<string, DeclaracaoTipoAst*> tabela_tipos;

//void erro(string message)
//{
//  cout << "ANALISE SEMANTICA" << message << endl;
//  exit(1);
//}

//enum comando_tipo {
//    ATRIBUICAO,
//    SE,
//    PARA,
//    ENQUANTO,
//    RETORNE,
//    PARE,
//    CONTINUE,
//    CHAMADA_PROCEDIMENTO
//};

//enum tipos {
//    INTEIRO,
//    REAL,
//    CADEIA,
//    REGISTRO,
//    VETOR
//};

//enum expressao_tipo {
//    ATRIBUICAO_REG,
//    CRIACAO_REG,
//    SOMA,
//    SUBTRACAO,
//    MAIOR,
//    MENOR,
//    MAIOR_IGUAL,
//    MENOR_IGUAL,
//    EQUIVALENTE,
//    DIFERENTE,
//    MULTIPLICACAO,
//    DIVISAO,
//    AND,
//    OR,
//    NULO,
//    CHAMADA_FUNCAO
//};

//int comando_to_enum(BaseComandoAst* comando)
//{
//    if (typeid(*comando) == typeid(AtribuicaoAst))
//        return comando_tipo::ATRIBUICAO;
//    else if (typeid(*comando) == typeid(SeAst))
//      return comando_tipo::SE;
//    else if (typeid(*comando) == typeid(ParaAst))
//      return comando_tipo::PARA;
//    else if (typeid(*comando) == typeid(EnquantoAst))
//      return comando_tipo::ENQUANTO;
//    else if (typeid(*comando) == typeid(RetorneAst))
//      return comando_tipo::RETORNE;
//    else if (typeid(*comando) == typeid(PareAst))
//      return comando_tipo::PARE;
//    else if (typeid(*comando) == typeid(ContinueAst))
//      return comando_tipo::CONTINUE;
//    else if (typeid(*comando) == typeid(ChamadaProcedimentoAst))
//      return comando_tipo::CHAMADA_PROCEDIMENTO;

//    return -1;
//}

//int expressao_to_enum(ExprAst* expressao)
//{
//    if (typeid(*expressao) == typeid(AtribuicaoRegistroAst))
//        return expressao_tipo::ATRIBUICAO_REG;
//    else if (typeid(*expressao) == typeid(CriacaoRegistroAst))
//      return expressao_tipo::CRIACAO_REG;
//    else if (typeid(*expressao) == typeid(SomaAst))
//      return expressao_tipo::SOMA;
//    else if (typeid(*expressao) == typeid(SubtracaoAst))
//      return expressao_tipo::SUBTRACAO;
//    else if (typeid(*expressao) == typeid(MaiorAst))
//      return expressao_tipo::MAIOR;
//    else if (typeid(*expressao) == typeid(MenorAst))
//      return expressao_tipo::MENOR;
//    else if (typeid(*expressao) == typeid(MaiorIgualAst))
//      return expressao_tipo::MAIOR_IGUAL;
//    else if (typeid(*expressao) == typeid(EquivalenteAst))
//      return expressao_tipo::EQUIVALENTE;
//    else if (typeid(*expressao) == typeid(DiferenteAst))
//      return expressao_tipo::DIFERENTE;
//    else if (typeid(*expressao) == typeid(MultiplicacaoAst))
//      return expressao_tipo::MULTIPLICACAO;
//    else if (typeid(*expressao) == typeid(DivisaoAst))
//      return expressao_tipo::DIVISAO;
//    else if (typeid(*expressao) == typeid(AndAst))
//      return expressao_tipo::AND;
//    else if (typeid(*expressao) == typeid(OrAst))
//      return expressao_tipo::OR;
//    else if (typeid(*expressao) == typeid(NuloAst))
//      return expressao_tipo::NULO;
//    else if (typeid(*expressao) == typeid(ChamadaFuncaoAst))
//      return expressao_tipo::CHAMADA_FUNCAO;

//    return -1;
//}

//int stringType_to_enum (const string &tipo) {
//  if (tipo == "inteiro")
//    return INTEIRO;
//  else if (tipo == "real")
//    return REAL;
//  else if (tipo == "cadeia")
//    return CADEIA;
//  else if (tipo == "registro")
//    return REGISTRO;
//  else if (tipo == "vetor")
//    return VETOR;

//   return -1;
//}

//void comando(BaseComandoAst* comando)
//{
//    switch (comando_to_enum(comando))
//    {
//    case comando_tipo::ATRIBUICAO:
//        // tabela_variaveis.find((AtribuicaoAst*) comando)->esq_->val_);
//        // Caso encontrou na tabela
//            // Checa o tipo
//        // Caso contrário

//        break;

//    case comando_tipo::SE:
//        /* code */
//        break;

//    case comando_tipo::PARA:
//        /* code */
//        break;
//    case comando_tipo::ENQUANTO:
//        /* code */
//        break;
//    case comando_tipo::RETORNE:
//        /* code */
//        break;
//    case comando_tipo::PARE:
//        /* code */
//        break;
//    case comando_tipo::CONTINUE:
//        /* code */
//        break;
//    case comando_tipo::CHAMADA_PROCEDIMENTO:
//        /* code */
//        break;

//    default:
//        cout << "ERRO" << endl;
//        break;
//    }
//}

//string hash_(string id, string escopo)
//{
//    return id.append("$" + escopo); // '$' é um caracter especial que não é usado em identificadores
//}

//void acao(ListaComandosAst* lista_comandos)
//{
//    for (auto comando : lista_comandos->lista_comandos_) {
//        //
//        comando->codegen();
//    }
//}

//int verificacao_tipo_expr_aritmetica(string tipo) {
//  switch (stringType_to_enum(tipo))
//  {
//  case INTEIRO:

//    break;

//  default:
//      erro("Tipo inválido");
//    break;
//  }
//}

//void declaracao_variavel(DeclaracaoVariavelAst* declaracao, string escopo)
//{
//  string key = hash_(declaracao->id_, escopo);
//  if (tabela_variaveis.find(key) != tabela_variaveis.end()) {
//    erro("Variável já declarada neste escopo.");
//  }
//  tabela_variaveis.insert(pair<string, DeclaracaoVariavelAst*>(key, declaracao));

//  switch (expressao_to_enum(declaracao->expressao_))
//  {
//  case SOMA: case SUBTRACAO: case MULTIPLICACAO: case DIVISAO:
//    stringType_to_enum(declaracao->tipo) == verificacao_tipo();
//    break;

//  default:
//    break;
//  }
//}

//void declaracao_tipo(DeclaracaoTipoAst* declaracao)
//{

//}

//void declaracao_funcao(DeclaracaoFuncaoAst* declaracao)
//{
//    for (auto var : declaracao->corpo_->variaveis_locais_->lista_declaracoes_)
//      declaracao_variavel(var, declaracao->id_);
//    acao(declaracao->corpo_->lista_comandos_);
//}

//void declaracao_funcoes(DeclaracaoFuncoesAst* lista_funcoes)
//{
//    for (auto funcao : lista_funcoes->lista_declaracoes_) {
//        if (!tabela_funcoes.insert(make_pair(funcao->id_, funcao)).second) {
//            cout << "Erro ao declarar a funcao " << funcao->id_ << "." << endl;
//            exit(1);
//        }
//        // pilha_escopos.push_back(vector<string>());
//        declaracao_funcao(funcao);
//    }
//}

//void declaracao_tipos(DeclaracaoTiposAst* lista_tipos)
//{
//    for (auto i : lista_tipos->lista_declaracoes_)
//        declaracao_tipo(i);
//}

//void declaracao_globais(ListaDecVarAst* lista_var)
//{
//    for (auto i : lista_var->lista_declaracoes_)
//        declaracao_variavel(i);
//}

//void declaracao(DeclaracoesAst* declaracoes)
//{
//    if (declaracoes->tipos_ != nullptr)
//        declaracao_tipos(declaracoes->tipos_);
//    if (declaracoes->globais_ != nullptr)
//        declaracao_globais(declaracoes->globais_);
//    if (declaracoes->funcoes_ != nullptr)
//        declaracao_funcoes(declaracoes->funcoes_);
//}

//void analise_semantica()
//{
//    declaracao(ast_root->dec_);
//    acao(ast_root->acao_);
//}

