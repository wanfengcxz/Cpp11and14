cmake_minimum_required(VERSION 3.19)
project(Cpp11and14)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib)
include_directories(googletest/include googletest)

add_executable(Cpp11and14 main.cpp)

# 参数数量不定的模板
add_executable(chapter01 ./chapter01/main.cpp)
target_link_libraries(chapter01 gtest gtest_main)

# 模板表达式中的空格
add_executable(chapter02 ./chapter02/main.cpp)
target_link_libraries(chapter02 gtest gtest_main)

add_executable(chapter03 ./chapter03/main.cpp)
target_link_libraries(chapter03 gtest gtest_main)

add_executable(chapter04 ./chapter04/main.cpp)
target_link_libraries(chapter04 gtest gtest_main)
