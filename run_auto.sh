#!/bin/bash

# 检测发行版
if [ -x "$(command -v yum)" ]; then
    # Red Hat / CentOS / Fedora
    sudo yum install cmake -y
elif [ -x "$(command -v apt-get)" ]; then
    # Ubuntu / Debian
    sudo apt-get install cmake -y
elif [ -x "$(command -v pacman)" ]; then
    # Arch Linux
    sudo pacman -S cmake --noconfirm
else
    echo "无法检测到支持的Linux发行版"
    exit 1
fi

# 检查CMake是否成功安装
if [ -x "$(command -v cmake)" ]; then
    echo "CMake已成功安装"
else
    echo "CMake安装失败"
fi

cmake CMakeLists.txt

make

chmod +x ./bin/richman

chmod +x ./test/start_test.sh

if [ "$1" = 't' ]; then
  cd test
  sh ./start_test.sh
else
  ./bin/richman
fi