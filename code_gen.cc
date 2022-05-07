#include "code_gen.hh"

#include <iostream>
#include <fstream>
#include <sstream>

#include "AST_classes.hh"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/Optional.h"
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
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Utils.h"
#include "KaleidoscopeJIT.hh"

using namespace llvm;
using namespace llvm::orc;
using namespace llvm::sys;

//===----------------------------------------------------------------------===//
// Code Generation Globals
//===----------------------------------------------------------------------===//

static unique_ptr<LLVMContext> TheContext; 
static unique_ptr<Module> TheModule;
static unique_ptr<IRBuilder<>> Builder;
static map<string, AllocaInst *> NamedValues;
static unique_ptr<legacy::FunctionPassManager> TheFPM;

void insert_std_print()
{
    vector<Type *> Doubles(1, Type::getDoubleTy(*TheContext));
    FunctionType *FT = FunctionType::get(Type::getInt32Ty(*TheContext), Doubles, false);
    Function *F = Function::Create(FT, Function::ExternalLinkage, "imprimei", TheModule.get());

    // Set names for all arguments.
    for (auto &Arg : F->args())
        Arg.setName("i");
}

void InitializeModule() {
    // Open a new context and module.
    TheContext = make_unique<LLVMContext>();
    TheModule = make_unique<Module>("my cool jit", *TheContext);

    // Create a new builder for the module.
    Builder = make_unique<IRBuilder<>>(*TheContext);

    insert_std_print();

    // Create a new pass manager attached to it.
    TheFPM = make_unique<legacy::FunctionPassManager>(TheModule.get());
    // Promote allocas to registers.
    TheFPM->add(createPromoteMemoryToRegisterPass());
    // Do simple "peephole" optimizations and bit-twiddling optzns.
    TheFPM->add(createInstructionCombiningPass());
    // Reassociate expressions.
    TheFPM->add(createReassociatePass());
    // Eliminate Common SubExpressions.
    TheFPM->add(createGVNPass());
    // Simplify the control flow graph (deleting unreachable blocks, etc).
    TheFPM->add(createCFGSimplificationPass());

    TheFPM->doInitialization();
}

void insert_functions() {
    for(auto funcao : ast_root->dec_->funcoes_->lista_declaracoes_) {
        vector<Type*> Argumentos(funcao->args_ == nullptr ? 0 : funcao->args_->lista_argumentos_.size(), Type::getInt32Ty(*TheContext));
        FunctionType *FT = FunctionType::get(Type::getInt32Ty(*TheContext), Argumentos, false);
        Function *F = Function::Create(FT, Function::ExternalLinkage, funcao->id_, TheModule.get());

        // Set names for all arguments.
        unsigned Idx = 0;
        for (auto &Arg : F->args())
            Arg.setName(funcao->args_->lista_argumentos_[Idx++]->id_);
    }
}

// Precisa receber o tipo caso seja diferente de inteiro
static AllocaInst *CreateEntryBlockAlloca(Function *TheFunction,
                                          const string &VarName) {
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(),
                     TheFunction->getEntryBlock().begin());
    return TmpB.CreateAlloca(Type::getInt32Ty(*TheContext), 0,
                             VarName.c_str());
}

//===----------------------------------------------------------------------===//
// Implementação das funções codegen() da AST
//===----------------------------------------------------------------------===//

Value *LogErrorV(const char *Str) {
    fprintf(stderr, "Error: %s\n", Str);
    return nullptr;
}

Value* ProgramaAst::codegen()
{
    this->dec_->codegen();

    FunctionType* FT = FunctionType::get(Type::getInt32Ty(*TheContext), {}, false);
    Function* F = Function::Create(FT, Function::ExternalLinkage, "main", TheModule.get());
    BasicBlock *BB = BasicBlock::Create(*TheContext, "entry", F);
    Builder->SetInsertPoint(BB);
    Value* body = this->acao_->codegen();
    Builder->CreateRet(body);
    verifyFunction(*F);

    return F;
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

Value* DeclaracaoVariavelAst::codegen(vector<AllocaInst *> OldBindings, Function *TheFunction)
{
    AllocaInst *Alloca = CreateEntryBlockAlloca(TheFunction, this->id_);
    Builder->CreateStore(this->expressao_->codegen(), Alloca);
    OldBindings.push_back(NamedValues[this->id_]);
    // Remember this binding.
    NamedValues[this->id_] = Alloca;
    return nullptr;
}

Value* ListaDecVarAst::codegen(vector<AllocaInst *> OldBindings, Function *TheFunction)
{
    if (this->lista_declaracoes_.empty())
        return nullptr;

    for (auto dec : this->lista_declaracoes_) {
        dec->codegen(OldBindings, TheFunction);
    }

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
    // cout << "corpo" << endl;

    vector<AllocaInst *> OldBindings;
    Function *TheFunction = Builder->GetInsertBlock()->getParent();

    if(variaveis_locais_ != nullptr) {
        variaveis_locais_->codegen(OldBindings, TheFunction);
    }
    return lista_comandos_->codegen();

}

Function* DeclaracaoFuncaoAst::codegen()
{
    Function *F = TheModule->getFunction(this->id_);
    if (!F) cout << "funcao nao encontrada IR" << endl;
    
    // Create a new basic block to start insertion into.
    BasicBlock *BB = BasicBlock::Create(*TheContext, "entry", F);
    Builder->SetInsertPoint(BB);

    // Record the function arguments in the NamedValues map.
    NamedValues.clear();
    for (auto &Arg : F->args()) {
        AllocaInst *Alloca = CreateEntryBlockAlloca(F, string(Arg.getName()));
        Builder->CreateStore(&Arg, Alloca);

        NamedValues[string(Arg.getName())] = Alloca;
    }
    
    Value* RetVal = this->corpo_->codegen();
    if (RetVal) {
        // Finish off the function.
        Builder->CreateRet(RetVal);

        // Validate the generated code, checking for consistency.
        verifyFunction(*F);
        return F;
    }
    
    // Error reading body, remove function.
    F->eraseFromParent();
    return nullptr;
}

Function* DeclaracaoFuncoesAst::codegen()
{
    for (auto funcao : this->lista_declaracoes_) {
        funcao->codegen();
    }

    return nullptr;
}

Value* DeclaracoesAst::codegen()
{
    
    if (this->tipos_ != nullptr) {
        this->tipos_->codegen();
    }

    if (this->globais_ != nullptr) {
        // vector<AllocaInst *> OldBindings;
        // Function *TheFunction = Builder->GetInsertBlock()->getParent();

        // this->globais_->codegen();
    }

    if (this->funcoes_ != nullptr) {
        this->funcoes_->codegen();
    }
    
    return nullptr;
}

Value* ListaComandosAst::codegen()
{
    // cout << "lista comandos" << endl;
    Value* return_value = nullptr;
    for (auto comando : lista_comandos_) {
        return_value = comando->codegen();
    }
    return return_value;
}

Value* AtribuicaoAst::codegen()
{
    Value *Val = this->dir_->codegen();
    Value *Variable = NamedValues[esq_->val_];
    Builder->CreateStore(Val, Variable);

    return Val;
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
    // << "retorne" << endl;
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
    Function *call_proc = TheModule->getFunction(this->id_);
    if (!call_proc)
        return LogErrorV("Unknown procedure referenced");

    if (call_proc->arg_size() != lista_->args_.size())
        return LogErrorV("Incorrect # arguments passed to procedure");

    vector<Value *> ArgsV;
    for (unsigned i = 0, e = this->lista_ == nullptr ? 0 : this->lista_->args_.size(); i != e; ++i) {
        ArgsV.push_back(lista_->args_[i]->codegen());
        if (!ArgsV.back())
            return nullptr;
    }

    return Builder->CreateCall(call_proc, ArgsV, "calltmp");
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
    return ConstantInt::get(*TheContext, APInt(32, this->val_));
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
    // Look this variable up in the function.
    Value *V = NamedValues[this->val_];
    if (!V)
        LogErrorV("Unknown variable name");

    // Load the value.
    return Builder->CreateLoad(Type::getInt32Ty(*TheContext), V, this->val_.c_str());
}

Value* SomaAst::codegen()
{
    Value *E = esq_->codegen();
    Value *D = dir_->codegen();

    if (!E || !D)
        return nullptr;

    return Builder->CreateAdd(E, D, "addtmp");
}

Value* SubtracaoAst::codegen()
{
    Value *E = esq_->codegen();
    Value *D = dir_->codegen();

    if (!E || !D)
        return nullptr;

    return Builder->CreateSub(E, D, "subtmp");
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

    return Builder->CreateMul(E, D, "multmp");
}

Value* DivisaoAst::codegen()
{
    Value *E = esq_->codegen();
    Value *D = dir_->codegen();

    if (!E || !D)
        return nullptr;

    return Builder->CreateFDiv( E, D, "divtmp");
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
    Function *CalleeF = TheModule->getFunction(this->id_);
    // // ANALISE SEMANTICA
    // if (!CalleeF)
    //     return LogErrorV("Unknown function referenced");

    // // If argument mismatch error.
    // // ANALISE SEMANTICA
    // if (CalleeF->arg_size() != this->lista_->args_.size())
    //     return LogErrorV("Incorrect # arguments passed to function");
    vector<Value *> ArgsV;
    for (unsigned i = 0, e = this->lista_ == nullptr ? 0 : this->lista_->args_.size(); i != e; ++i) {
        ArgsV.push_back(this->lista_->args_[i]->codegen());
        if (!ArgsV.back())
            return nullptr;
    }
   
    return Builder->CreateCall(CalleeF, ArgsV, "calltmp");

}


//===----------------------------------------------------------------------===//
// Top-Level codegen
//===----------------------------------------------------------------------===//

int generate_bin()
{
    // Initialize the target registry etc.
    InitializeAllTargetInfos();
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmParsers();
    InitializeAllAsmPrinters();

    auto TargetTriple = getDefaultTargetTriple();
    TheModule->setTargetTriple(TargetTriple);

    string Error;
    auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);

    // Print an error and exit if we couldn't find the requested target.
    // This generally occurs if we've forgotten to initialise the
    // TargetRegistry or we have a bogus target triple.
    if (!Target) {
        errs() << Error;
        return 1;
    }

    auto CPU = "generic";
    auto Features = "";

    TargetOptions opt;
    auto RM = Optional<Reloc::Model>();
    auto TheTargetMachine =
            Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

    TheModule->setDataLayout(TheTargetMachine->createDataLayout());

    auto Filename = "output.o";
    error_code EC;
    raw_fd_ostream dest(Filename, EC, sys::fs::OF_None);

    if (EC) {
        errs() << "Could not open file: " << EC.message();
        return 1;
    }

    legacy::PassManager pass;
    auto FileType = CGFT_ObjectFile;

    if (TheTargetMachine->addPassesToEmitFile(pass, dest, nullptr, FileType)) {
        errs() << "TheTargetMachine can't emit a file of this type";
        return 1;
    }

    pass.run(*TheModule);
    dest.flush();

    return 0;
}

void code_generation(bool dump_IR)
{
    InitializeModule();
    insert_functions();

    ast_root->codegen();
    if (dump_IR) {
        string IR_dump_str;
        raw_string_ostream OS(IR_dump_str);
        OS << *TheModule;
        OS.flush();
        ofstream out("fonte.ll", ofstream::out);
        out << IR_dump_str;
        out.close();
    }

    generate_bin();
}