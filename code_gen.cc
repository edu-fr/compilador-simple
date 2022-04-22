#include "AST_classes.hh"

//===----------------------------------------------------------------------===//
// Code Generation Globals
//===----------------------------------------------------------------------===//

std::unique_ptr<LLVMContext> TheContext;
std::unique_ptr<Module> TheModule;
std::unique_ptr<IRBuilder<>> Builder;
std::map<std::string, Value *> NamedValues;
// static std::unique_ptr<KaleidoscopeJIT> TheJIT;
// static std::map<std::string, std::unique_ptr<PrototypeAST>> FunctionProtos;

void InitializeModule() {
  // Open a new context and module.
  TheContext = std::make_unique<LLVMContext>();
  TheModule = std::make_unique<Module>("my cool jit", *TheContext);

  // Create a new builder for the module.
  Builder = std::make_unique<IRBuilder<>>(*TheContext);
}


//===----------------------------------------------------------------------===//
// Code Generation CAP 8
//===----------------------------------------------------------------------===//

Value* TipoCampoAst::codegen()
{
    return nullptr;
}

Value* TipoCamposAst::codegen()
{
    return nullptr;
}

Value* DescritorTipoIdAst::codegen()
{
    return nullptr;
}

Value* DescritorTipoCamposAst::codegen()
{
    return nullptr;
}

Value* DescritorTipoCtesAst::codegen()
{
    return nullptr;
}

Value* DeclaracaoTipoAst::codegen()
{
    return nullptr;
}

Value* DeclaracaoTiposAst::codegen()
{
    return nullptr;
}

Value* DeclaracaoVariavelAst::codegen()
{
    return nullptr;
}

Value* ListaDecVarAst::codegen()
{
    return nullptr;
}

Value* ArgumentoAst::codegen()
{
    return nullptr;
}

Value* ListaArgsAst::codegen()
{
    return nullptr;
}

Value* CorpoAst::codegen()
{
    return nullptr;
}

Value* DeclaracaoFuncaoAst::codegen()
{
    return nullptr;
}

Value* DeclaracaoFuncoesAst::codegen()
{
    return nullptr;
}

Value* DeclaracoesAst::codegen()
{
    return nullptr;
}

Value* ListaComandosAst::codegen()
{
    return nullptr;
}

Value* AtribuicaoAst::codegen()
{
    return nullptr;
}

Value* SeAst::codegen()
{
    return nullptr;
}

Value* ParaAst::codegen()
{
    return nullptr;
}

Value* EnquantoAst::codegen()
{
    return nullptr;
}

Value* RetorneAst::codegen()
{
    cout << "print retorneAST codegen" << endl;
    return expr_->codegen();
}

Value* PareAst::codegen()
{
    return nullptr;
}

Value* ContinueAst::codegen()
{
    return nullptr;
}

Value* ChamadaProcedimentoAst::codegen()
{
    return nullptr;
}

Value* AtribuicaoRegistroAst::codegen()
{
    return nullptr;
}

Value* CriacaoRegistroAst::codegen()
{
    return nullptr;
}

Value* InteiroAst::codegen()
{
    return nullptr;
}

Value* RealAst::codegen()
{
    cout << "print realAST codegen" << endl;
    return ConstantFP::get(*TheContext, APFloat(val_));
}

Value* CadeiaAst::codegen()
{
    return nullptr;
}

Value* LocalAst::codegen()
{
    return nullptr;
}

Value* SomaAst::codegen()
{
    return nullptr;
}

Value* SubtracaoAst::codegen()
{
    return nullptr;
}

Value* MaiorAst::codegen()
{
    return nullptr;
}

Value* MenorAst::codegen()
{
    return nullptr;
}

Value* MaiorIgualAst::codegen()
{
    return nullptr;
}

Value* MenorIgualAst::codegen()
{
    return nullptr;
}

Value* EquivalenteAst::codegen()
{
    return nullptr;
}

Value* DiferenteAst::codegen()
{
    return nullptr;
}

Value* MultiplicacaoAst::codegen()
{
    return nullptr;
}

Value* DivisaoAst::codegen()
{
    return nullptr;
}

Value* AndAst::codegen()
{
    return nullptr;
}

Value* OrAst::codegen()
{
    return nullptr;
}

Value* NuloAst::codegen()
{
    return nullptr;
}

Value* ListaArgsChamada::codegen()
{
    return nullptr;
}

Value* ChamadaFuncaoAst::codegen()
{
    return nullptr;
}

// Value* InteiroAst::codegen()
// {
//    return ConstantFP::get(*TheContext, APSInt(val_));
// }

// Value* RealAst::codegen()
// {
//     return ConstantFP::get(*TheContext, APFloat(val_));
// }


void LogError(const char *Str) {
  fprintf(stderr, "LogError: %s\n", Str);
}

// Value *LogErrorV(const char *Str) {
//   LogError(Str);
//   return nullptr;
// }
