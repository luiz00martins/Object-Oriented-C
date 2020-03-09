cmake_minimum_required(VERSION 3.14)
project(Test C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_COMPILER "/usr/bin/clang-6.0")

add_executable(Test Test.c Person.c Particle.c Example.c "OOC Library/Utilities/ArrayList.c" "OOC Library/Utilities/ArrayQueue.c" "OOC Library/Utilities/ArrayStack.c" "OOC Library/Utilities/LinkedList.c" "OOC Library/Utilities/LinkedQueue.c" "OOC Library/Utilities/LinkedStack.c" "OOC Library/Utilities/List.c" "OOC Library/Utilities/Queue.c" "OOC Library/Utilities/Stack.c" "OOC Library/Utilities/String.c" "OOC Library/Object.c" "OOC Library/Wrappers/Wrapper.c" "OOC Library/Wrappers/Int.c" "OOC Library/Wrappers/Char.c" "OOC Library/Wrappers/Float.c" "OOC Library/Wrappers/Double.c" "OOC Library/Wrappers/Short.c" "OOC Library/Wrappers/Long.c" "OOC Library/Wrappers/LongDouble.c" "OOC Library/Wrappers/LongLong.c" "OOC Library/Wrappers/Struct.c" "OOC Library/Wrappers/Ptr.c" "OOC Library/Wrappers/PrimWrapper.c")
