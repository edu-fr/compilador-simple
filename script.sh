#! /bin/sh

cd build
make
cd ..
./sc -o execucao_teste teste46.s
#./execucao_teste
#cat fonte.ll
# echo $?