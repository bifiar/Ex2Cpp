cmake_minimum_required(VERSION 3.6)
project(Ex2Cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MemPool.cpp MemPool.h MemoryManager.cpp MemoryManager.h MyAllocator.cpp MyAllocator.h FreeNode.cpp FreeNode.h ConsolePrinter.cpp ConsolePrinter.h OperatorNewDelOver.cpp)
add_executable(Ex2Cpp ${SOURCE_FILES})