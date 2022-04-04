#include "AST_classes.hh"

#include <memory>

expr_arit_ast* ast_root;

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

void expr_arit_ast::set_esq(literal_ast *esq) {
    esq_ = esq;
}

expr_arit_ast::expr_arit_ast(tipo_operador operador, literal_ast* esq, literal_ast* dir) : tipo_(operador), esq_(esq), dir_(dir) {}

expr_arit_ast* expr_arit_ast::get_ptr(tipo_operador tipo, literal_ast* esq, literal_ast* dir) {
    static expr_arit_ast o = expr_arit_ast(tipo, esq, dir);
    return std::move(&o);
}
