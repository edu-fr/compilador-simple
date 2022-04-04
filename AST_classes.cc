#include "AST_classes.hh"

#include <memory>

literal_ast* ast_root;

//inteiro_ast::inteiro_ast(int other) : val_(other) {}

//inteiro_ast *inteiro_ast::get_ptr(int val)
//{
//    static inteiro_ast o = inteiro_ast(val);
//    return std::move(&o);
//}

//real_ast::real_ast(double other) : val_(other) {}

//real_ast* real_ast::get_ptr(double val)
//{
//    static real_ast o = real_ast(val);
//    return std::move(&o);
//}

//cadeia_ast::cadeia_ast(const std::string &other) : val_(other) {}

//cadeia_ast* cadeia_ast::get_ptr(const std::string &val)
//{
//    static cadeia_ast o = cadeia_ast(val);
//    return std::move(&o);
//}


literal_ast::literal_ast(int other) : int_val_(other), tipo_(tipo_literal::INTEIRO) {}
literal_ast::literal_ast(double other) : real_val_(other), tipo_(tipo_literal::REAL) {}
literal_ast::literal_ast(std::string other) : cadeia_val_(other), tipo_(tipo_literal::CADEIA) {}

literal_ast::literal_ast(const literal_ast &other)
{
    switch (other.tipo_) {
    case tipo_literal::INTEIRO:
        int_val_ = other.int_val_;
        break;
    case tipo_literal::REAL:
        real_val_ = other.real_val_;
        break;
    case tipo_literal::CADEIA:
        cadeia_val_ = other.cadeia_val_;
        break;
    default:
        break;
    }
}

literal_ast* literal_ast::get_ptr(int valor)
{
    static literal_ast o = literal_ast(valor);
    return std::move(&o);
}

literal_ast* literal_ast::get_ptr(double valor)
{
    static literal_ast o = literal_ast(valor);
    return std::move(&o);
}

literal_ast* literal_ast::get_ptr(std::string valor)
{
    static literal_ast o = literal_ast(valor);
    return std::move(&o);
}