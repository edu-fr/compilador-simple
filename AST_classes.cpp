#include "AST_classes.hh"

// Base class
class ExprAST {
    Tipo tipo; 
    public: 
        virtual ~ExprAST() {}

};

// 
class InteiroExprAST : public ExprAST {
    int Val;

public:
    InteiroExprAST(int Val) : Val(Val) {}

    static unique_ptr<ExprAST> ParseNumberExpr(int val) {
        auto Result = make_unique<InteiroExprAST>(val);
        return move(Result);
    }
};
