#include <string>
#include <iostream>
#include <unistd.h>

#include "driver.hh"
#include "AST_classes.hh"

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

  switch (ast_root->tipo_) {
  case tipo_literal::INTEIRO:
      std::cout << ast_root->int_val_ << std::endl;
      break;
  case tipo_literal::REAL:
      std::cout << ast_root->real_val_ << std::endl;
      break;
  case tipo_literal::CADEIA:
      std::cout << ast_root->cadeia_val_ << std::endl; // FIX ME -- STRING TA DANDO ERRO DE SEG
      break;
  default:
      break;
  }

  return 0;
}
