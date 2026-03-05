#!/bin/bash

mkdir -p build
cd build

cmake ..
make

sudo cp cshell /usr/local/bin/

echo "custom shell installed!"
