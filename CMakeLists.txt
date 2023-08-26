#最低要求
cmake_minimum_required(VERSION 3.21)
#项目名称
project(Algorithm)

#设置CMake变量
set(CMAKE_CXX_STANDARD 17)

#将main.cpp生成可执行程序Demo
add_executable(Algorithm main.cpp
        dependencies/include/bits/stdc++.h
        dependencies/include/leetcode.h)

#添加bits/stdc++的路径
include_directories(BEFORE dependencies/include)


#SingleFileExecutionPlugin
add_executable(test_1 test/test_1.cpp)
set_target_properties(test_1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(test test/test.cpp)
set_target_properties(test PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(SwordOffer_58_Reverse-Left-Words leetcode/SwordOffer_58_Reverse-Left-Words.cpp)
set_target_properties(SwordOffer_58_Reverse-Left-Words PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")