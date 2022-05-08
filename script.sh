#! /bin/sh

cd build
make
cd ..
./sc -i -s -o execucao_teste fonte.s
./execucao_teste
#cat fonte.ll
# echo $?