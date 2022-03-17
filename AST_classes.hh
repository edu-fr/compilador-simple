#include <memory>
using namespace std;

enum Tipo {
    inteiro,
    real,  
};

class ExprAST;

class InteiroExprAST {
    public:
        static unique_ptr<ExprAST> ParseNumberExpr(int val);
};