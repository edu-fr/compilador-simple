#include <string>
#include <iostream>
#include <unistd.h>

#include "driver.hh"
#include "AST_classes.hh"

using namespace std;

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

//    cout << ((InteiroAst*) ast_root)->val_ << endl;
      cout << ((CadeiaAst*) ast_root)->val_ << endl;

//  cout << "esquerdo: " << ((InteiroAst*) ((ExprAritAst*) ast_root)->esq_)->val_ << endl;
//  cout << "direito: "  << ((InteiroAst*) ((ExprAritAst*) ast_root)->dir_)->val_ << endl;

  return 0;
}
