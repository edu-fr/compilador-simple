#ifndef AST_classes_HH
#define AST_classes_HH

#include <memory>
#include <iostream>
using namespace std;

// enum Tipo {
//     inteiro,
//     real,  
// };
typedef struct FatorAST *FatorASTptr;

class FatorAST{
    public:
        int val;
        void print2() {
            cout << "ola\n" << endl;    
        }
};



// class FatorAST;

// class InteiroFatorAST : public FatorAST {
//     public:
//     int Val;
//     InteiroFatorAST(int Val);
//     static unique_ptr<FatorAST> ParseNumberExpr(int val);
// };

// static unique_ptr<FatorAST> ParseNumberExpr(int val);

#endif