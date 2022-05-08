#include <string>
#include <iostream>
#include <unistd.h>
#include "analise_semantica.hh"
#include "code_gen.hh"
#include "driver.hh"

int main(int argc, char **argv)
{
    if (argc < 2) {
        cout << "Erro: nenhum parametro especificado" << endl;
        exit(EXIT_FAILURE);
    }
    string nome_executavel = "a.out", nome_fonte = argv[argc - 1];
    if (nome_fonte.find(".s") == string::npos) {
        cout << "Erro: nome do arquivo fonte nao especificado" << endl;
        exit(EXIT_FAILURE);
    }
    bool imprime_intermediario = false, imprime_assembly = false;
    int opt;

    while ((opt = getopt(argc, argv, "iso:?")) != -1) {
        switch(opt) {
        case 'i':
            imprime_intermediario = true;
            break;

        case 's':
            imprime_assembly = true;
            break;
            
        case 'o':
            nome_executavel = optarg;
            break;
            
        default: /* '?' */
            fprintf(stderr, "Usage: %s [-i imprime_intermediario] [-s imprime_assembly] [-o nomeia_arquivo_saida] fonte.s\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    Simples::Driver driver;
    driver.parse_file(nome_fonte);

    if (!analise_semantica())
        exit(EXIT_FAILURE);

    code_generation(imprime_intermediario);
    
    if(system("clang++ -c utils.cc") == -1) {
        cout << "Erro: falha ao compilar o utils.cc" << endl;
        exit(EXIT_FAILURE);
    }
    
    if(system(("clang output.o utils.o -o " + nome_executavel).c_str()) == -1) {
        cout << "Erro: falha ao criar o executavel" << endl;
        exit(EXIT_FAILURE);
    }

    if(imprime_assembly) {
        if (system("clang -C output.o utils.o -o fonte.o") == -1) {
            cout << "Erro: falha ao criar arquivo .o" << endl;
            exit(EXIT_FAILURE);
        }

        if(system("objdump -D fonte.o > fonte.as") == -1) {
            cout << "Erro: falha ao criar arquivo assembly" << endl;
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
