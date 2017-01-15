cmake_minimum_required(VERSION 3.6)
project(Ex2Cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MemPool.cpp MemPool.h MemoryManager.cpp MemoryManager.h FreeNode.cpp FreeNode.h ConsolePrinter.cpp ConsolePrinter.h OperatorNewDelOver.cpp sharedTypeDeffs.h FitAlgo.h BestFIt.cpp BestFIt.h FirstFit.cpp FirstFit.h)
add_executable(Ex2Cpp ${SOURCE_FILES})