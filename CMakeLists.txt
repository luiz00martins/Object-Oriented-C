cmake_minimum_required(VERSION 3.14)
project(Test C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_COMPILER "/usr/bin/clang-6.0")

add_executable(Test Test.c Example.c Example.h "OOC Library/Object.c" "OOC Library/Object.h" "OOC Library/Wrappers/Wrapper.c" "OOC Library/Wrappers/Wrapper.h" "OOC Library/Wrappers/Int.c" "OOC Library/Wrappers/Int.h" "OOC Library/Wrappers/Char.c" "OOC Library/Wrappers/Char.h" "OOC Library/Wrappers/Float.c" "OOC Library/Wrappers/Float.h" "OOC Library/Wrappers/Double.c" "OOC Library/Wrappers/Double.h" "OOC Library/Wrappers/Short.c" "OOC Library/Wrappers/Short.h" "OOC Library/Wrappers/Long.c" "OOC Library/Wrappers/Long.h" "OOC Library/Wrappers/LongDouble.h" "OOC Library/Wrappers/LongDouble.c" "OOC Library/Wrappers/LongLong.c" "OOC Library/Wrappers/LongLong.h" "OOCLib.h" "OOC Library/Wrappers/Struct.c" "OOC Library/Wrappers/Struct.h" "OOC Library/Wrappers/Ptr.c" "OOC Library/Wrappers/Ptr.h" "OOC Library/Wrappers/PrimWrapper.c" "OOC Library/Wrappers/PrimWrapper.h")
