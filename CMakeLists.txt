cmake_minimum_required(VERSION 3.22)
project(richman_2023 C)

set(CMAKE_C_STANDARD 11)
include_directories(./include)#添加头文件路径

#设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#设置编译的.c文件
<<<<<<< HEAD
aux_source_directory(src/ test)
#aux_source_directory(./ main)
add_executable(richman_2023  main.c ${test}  )
=======
aux_source_directory(./src/ test)
#aux_source_directory(./ main)
add_executable(richman_2023  main.c ${test} ./src/Player.c )
>>>>>>> aed0620babbca38c9c04f0cdceb275b2ae2fab08

