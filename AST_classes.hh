#ifndef AST_classes_HH
#define AST_classes_HH

#include <string>

enum tipo_literal {
    INTEIRO,
    REAL,
    CADEIA
};

enum tipo_operador {
    SOMA,
    SUBTRACAO
};

/* FIX ME !! talvez aqui nao seja o melhor lugar pra colocar isso */
class expr_arit_ast;
extern expr_arit_ast* ast_root;

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

class expr_arit_ast {
    private:
        expr_arit_ast(tipo_operador operador, literal_ast* esq, literal_ast* dir);

    public:
        tipo_operador tipo_;
        literal_ast* esq_;   // exp
        literal_ast* dir_;   // exp

        static void set_esq(literal_ast *esq);
        static expr_arit_ast* get_ptr(tipo_operador tipo, literal_ast* esq, literal_ast* dir);

};

#endif