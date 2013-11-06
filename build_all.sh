#!/bin/sh

DIR = '~/dev/engines/zengine'
cd $DIR

clear
mkdir build
cd build
echo "BUILDING ZENGINE"
pwd
cmake ..
make

cd ..

echo "BUILDING TESTS"
pwd
cd tests
mkdir build
cd build
cmake ..
make
