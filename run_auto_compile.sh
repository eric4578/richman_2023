#!/bin/bash


git clone https://github.com/eric4578/richman_2023.git

cd richman_2023

sudo apt-get install cmake

cmake CMakeLists.txt

make

chmod +x ./bin/richman

chmod +x ./test/start_test.sh

