#! /bin/sh

cd build
make
cd ..
./sc -i test.s 