cmake_minimum_required(VERSION 3.14)
project(OOC C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_COMPILER "/usr/bin/clang-6.0")

add_executable(OOC main.c Object.c Point.c Example.c Example.h)