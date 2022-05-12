#! /bin/sh

cd build
make
cd ..
./sc -o execucao_teste teste47.s
#./execucao_teste
#cat fonte.ll
# echo $?