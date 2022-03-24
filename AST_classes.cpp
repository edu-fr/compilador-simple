#include "AST_classes.hh"

// // Base class
// class FatorAST {
//     // Tipo tipo; 
//     public: 
//         virtual ~FatorAST() {}

// };

// // 
// InteiroFatorAST::InteiroFatorAST(int Val) : Val(Val)
// { 
// }

// static unique_ptr<FatorAST> ParseNumberExpr(int val) {
//         auto Result = make_unique<InteiroFatorAST>(val);
//         return move(Result);
// }

// class FloatFatorAST : public FatorAST {
//     float Val;

// public:
//     FloatFatorAST(float Val) : Val(Val) {}

//     static unique_ptr<FatorAST> ParseNumberExpr(float val) {
//         auto Result = make_unique<FloatFatorAST>(val);
//         return move(Result);
//     }
// };