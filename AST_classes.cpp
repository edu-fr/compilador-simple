#include <memory>
using namespace std;

enum Tipo {
    inteiro,
    real,
    fodase
}

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

    static unique_ptr<ExprAST> ParseNumberExpr() {
        auto Result = make_unique<InteiroExprAST>();

    }
};
