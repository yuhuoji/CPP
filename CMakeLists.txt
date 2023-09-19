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

add_executable(Leetcode_1_two-sum src/leetcode/editor/cn/Leetcode_1_two-sum.cpp)
set_target_properties(Leetcode_1_two-sum PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_2_add-two-numbers src/leetcode/editor/cn/Leetcode_2_add-two-numbers.cpp)
set_target_properties(Leetcode_2_add-two-numbers PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_49_group-anagrams src/leetcode/editor/cn/Leetcode_49_group-anagrams.cpp)
set_target_properties(Leetcode_49_group-anagrams PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_128_longest-consecutive-sequence src/leetcode/editor/cn/Leetcode_128_longest-consecutive-sequence.cpp)
set_target_properties(Leetcode_128_longest-consecutive-sequence PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_35_search-insert-position src/leetcode/editor/cn/Leetcode_35_search-insert-position.cpp)
set_target_properties(Leetcode_35_search-insert-position PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_69_sqrtx src/leetcode/editor/cn/Leetcode_69_sqrtx.cpp)
set_target_properties(Leetcode_69_sqrtx PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_226_invert-binary-tree src/leetcode/editor/cn/Leetcode_226_invert-binary-tree.cpp)
set_target_properties(Leetcode_226_invert-binary-tree PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_104_maximum-depth-of-binary-tree src/leetcode/editor/cn/Leetcode_104_maximum-depth-of-binary-tree.cpp)
set_target_properties(Leetcode_104_maximum-depth-of-binary-tree PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_101_symmetric-tree src/leetcode/editor/cn/Leetcode_101_symmetric-tree.cpp)
set_target_properties(Leetcode_101_symmetric-tree PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_74_search-a-2d-matrix src/leetcode/editor/cn/Leetcode_74_search-a-2d-matrix.cpp)
set_target_properties(Leetcode_74_search-a-2d-matrix PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_13_roman-to-integer src/leetcode/editor/cn/Leetcode_13_roman-to-integer.cpp)
set_target_properties(Leetcode_13_roman-to-integer PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_JianZhiOffer10-II_qing-wa-tiao-tai-jie-wen-ti-lcof  "src/leetcode/editor/cn/Leetcode_JianZhiOffer10-II_qing-wa-tiao-tai-jie-wen-ti-lcof .cpp")
set_target_properties(Leetcode_JianZhiOffer10-II_qing-wa-tiao-tai-jie-wen-ti-lcof  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_JianZhiOffer10-I_fei-bo-na-qi-shu-lie-lcof  "src/leetcode/editor/cn/Leetcode_JianZhiOffer10-I_fei-bo-na-qi-shu-lie-lcof .cpp")
set_target_properties(Leetcode_JianZhiOffer10-I_fei-bo-na-qi-shu-lie-lcof  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_70_climbing-stairs  "src/leetcode/editor/cn/Leetcode_70_climbing-stairs .cpp")
set_target_properties(Leetcode_70_climbing-stairs  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_118_pascals-triangle  "src/leetcode/editor/cn/Leetcode_118_pascals-triangle .cpp")
set_target_properties(Leetcode_118_pascals-triangle  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_120_triangle  "src/leetcode/editor/cn/Leetcode_120_triangle .cpp")
set_target_properties(Leetcode_120_triangle  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_169_majority-element  "src/leetcode/editor/cn/Leetcode_169_majority-element .cpp")
set_target_properties(Leetcode_169_majority-element  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_279_perfect-squares  "src/leetcode/editor/cn/Leetcode_279_perfect-squares .cpp")
set_target_properties(Leetcode_279_perfect-squares  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_198_house-robber  "src/leetcode/editor/cn/Leetcode_198_house-robber .cpp")
set_target_properties(Leetcode_198_house-robber  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_LCP50_WHnhjV  "src/leetcode/editor/cn/Leetcode_LCP50_WHnhjV .cpp")
set_target_properties(Leetcode_LCP50_WHnhjV  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_121_best-time-to-buy-and-sell-stock  "src/leetcode/editor/cn/Leetcode_121_best-time-to-buy-and-sell-stock .cpp")
set_target_properties(Leetcode_121_best-time-to-buy-and-sell-stock  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(Leetcode_34_find-first-and-last-position-of-element-in-sorted-array  "src/leetcode/editor/cn/Leetcode_34_find-first-and-last-position-of-element-in-sorted-array .cpp")
set_target_properties(Leetcode_34_find-first-and-last-position-of-element-in-sorted-array  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")
add_executable(BinarySearch src/leetcode/BinarySearch.cpp)
set_target_properties(BinarySearch PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build")