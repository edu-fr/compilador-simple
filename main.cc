#include <string>
#include <iostream>
#include <unistd.h>
#include "analise_semantica.hh"
#include "code_gen.hh"
#include "driver.hh"

int main(int argc, char **argv)
{
    std::string filename;
    int opt;

    while ((opt = getopt(argc, argv, "i:?")) != EOF)
        switch(opt) {
        case 'i': filename = optarg; break;
        case '?': std::cerr << "Usuage: tc -i <filename>" << std::endl; break;
        default: std::cerr << std::endl; abort();
        }

    Simples::Driver driver;
    driver.parse_file(filename);

//    analise_semantica();
    code_generation();

    return 0;
}

    // cout << (typeid(t) == typeid(oie::teste)) << endl;
