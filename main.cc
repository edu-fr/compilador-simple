#include <string>
#include <iostream>
#include <unistd.h>
#include "analise_semantica.hh"
#include "code_gen.hh"
#include "driver.hh"

// int main(int argc, char **argv)
// {
//     std::string filename;
//     int opt;

//     while ((opt = getopt(argc, argv, "i:?")) != EOF)
//         switch(opt) {
//         case 'i': filename = optarg; break;
//         case '?': std::cerr << "Usuage: tc -i <filename>" << std::endl; break;
//         default: std::cerr << std::endl; abort();
//         }

//     Simples::Driver driver;
//     driver.parse_file(filename);

//     // analise_semantica();
//     code_generation();
//     system("clang++ -c utils.cc");
//     system("clang output.o utils.o -o execucao_teste");
//     return 0;
// }

// cout << (typeid(t) == typeid(oie::teste)) << endl;


class base {
    public:
    base() {}
    virtual int numero() {return 2;}
};

class filho1 : public base {
    public:
    filho1()  {}
    int numero() override {return 3;} 
};

class classe2 {
    public:
    classe2(base *b) : b(b) {}
    base *b;
};

int main(int argc, char **argv)
{
    classe2 c = classe2(new filho1());
    cout << c.b->numero() << endl;
    return 0;
}