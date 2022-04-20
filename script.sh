#! /bin/sh

cd build
rm -r *
cmake ..
make
cd ..
./sc -i test.s 