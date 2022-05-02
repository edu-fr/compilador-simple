#include "code_gen.hh"

#include <iostream>

#include "AST_classes.hh"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "KaleidoscopeJIT.hh"

using namespace llvm;
using namespace llvm::orc;

//===----------------------------------------------------------------------===//
// Code Generation Globals
//===----------------------------------------------------------------------===//

static std::unique_ptr<LLVMContext> TheContext;
static std::unique_ptr<Module> TheModule;
static std::unique_ptr<IRBuilder<>> Builder;
static std::map<std::string, Value *> NamedValues;

void InitializeModule() {
    // Open a new context and module.
    TheContext = std::make_unique<LLVMContext>();
    TheModule = std::make_unique<Module>("my cool jit", *TheContext);

    // Create a new builder for the module.
    Builder = std::make_unique<IRBuilder<>>(*TheContext);
}

//===----------------------------------------------------------------------===//
// Implementação das funções codegen() da AST
//===----------------------------------------------------------------------===//

Value* ProgramaAst::codegen()
{
    this->dec_->codegen();
    this->acao_->codegen();
}

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
    // Value *V = NamedValues[id_];
    // if (!V)
    //     return LogErrorV("Unknown variable name");

    // // Load the value.
    // return Builder.CreateLoad(V, Name.c_str());
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

Function* DeclaracaoFuncaoAst::codegen()
{
    // First, check for an existing function from a previous 'extern' declaration.
    Function *TheFunction = TheModule->getFunction(this->id_);

    if (!TheFunction) {
        vector<Type*> Doubles(this->args_->lista_argumentos_.size(),
                              Type::getDoubleTy(*TheContext));
        FunctionType* FT = FunctionType::get(Type::getDoubleTy(*TheContext), Doubles, false);
        Function* F = Function::Create(FT, Function::ExternalLinkage, this->id_, TheModule.get());

        // Set names for all arguments.
        unsigned Idx = 0;
        for (auto &Arg : F->args())
            Arg.setName(Args[Idx++]);
        TheFunction = F;
    }

    if (!TheFunction) return nullptr;

    // Create a new basic block to start insertion into.
    BasicBlock *BB = BasicBlock::Create(*TheContext, "entry", TheFunction);
    Builder->SetInsertPoint(BB);

    // Record the function arguments in the NamedValues map.
    NamedValues.clear();
    for (auto &Arg : TheFunction->args())
        NamedValues[string(Arg.getName())] = &Arg;

    if (Value* RetVal = this->corpo_->codegen()) {
        // Finish off the function.
        Builder->CreateRet(RetVal);

        // Validate the generated code, checking for consistency.
        verifyFunction(*TheFunction);

        return TheFunction;
    }

    // Error reading body, remove function.
    TheFunction->eraseFromParent();
    return nullptr;
}

Function* DeclaracaoFuncoesAst::codegen()
{
    for (auto funcao : this->lista_declaracoes_)
        funcao->codegen();

    return nullptr;
}

Value* DeclaracoesAst::codegen()
{
    this->tipos_->codegen();
    this->globais_->codegen();
    this->funcoes_->codegen();

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
    //    cout << "print retorneAST codegen" << endl;
    // expr_->codegen()->print(errs());
    //    return expr_->codegen();
    return nullptr;
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
    return ConstantFP::get(*TheContext, APFloat(this->val_));
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
    Value *E = esq_->codegen();
    Value *D = dir_->codegen();

    if (!E || !D)
        return nullptr;

    return Builder->CreateFAdd(E, D, "addtmp");
}

Value* SubtracaoAst::codegen()
{
    Value *E = esq_->codegen();
    Value *D = dir_->codegen();

    if (!E || !D)
        return nullptr;

    return Builder->CreateFSub(E, D, "subtmp");
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
    Value *E = esq_->codegen();
    Value *D = dir_->codegen();

    if (!E || !D)
        return nullptr;

    return Builder->CreateFMul(E, D, "multmp");
}

Value* DivisaoAst::codegen()
{
    Value *E = esq_->codegen();
    Value *D = dir_->codegen();

    if (!E || !D)
        return nullptr;

    return Builder->CreateFDiv(E, D, "divtmp");
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


//===----------------------------------------------------------------------===//
// Top-Level codegen
//===----------------------------------------------------------------------===//

void code_generation()
{
    InitializeModule();
    TheModule->print(errs(), nullptr);
}