#! /bin/sh -e
cmake ${CMAKE_ARGS} -B cmake-build -S .
cd cmake-build

make
make install
