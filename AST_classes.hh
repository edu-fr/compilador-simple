#ifndef AST_classes_HH
#define AST_classes_HH

#include <string>

enum tipo_literal {
    INTEIRO,
    REAL,
    CADEIA
};

/* FIX ME !! talvez aqui nao seja o melhor lugar pra colocar isso */
class literal_ast;
extern literal_ast* ast_root;

//class inteiro_ast {
//public:
//    int val_;
//    inteiro_ast(int other);
//    static inteiro_ast* get_ptr(int val);
//};

//class real_ast {
//public:
//    double val_;
//    real_ast(double other);
//    static real_ast* get_ptr(double val);
//};

//class cadeia_ast {
//public:
//    std::string val_;
//    cadeia_ast(const std::string &other);
//    static cadeia_ast* get_ptr(const std::string &val);
//};

class literal_ast {
private:
    literal_ast(int other);
    literal_ast(double other);
    literal_ast(std::string other);
    literal_ast(const literal_ast &other);
    ~literal_ast() {}

public:
    union {
        int int_val_;
        double real_val_;
        std::string cadeia_val_;
    };
    tipo_literal tipo_;

    static literal_ast* get_ptr(int valor);
    static literal_ast* get_ptr(double valor);
    static literal_ast* get_ptr(std::string valor);
};

#endif