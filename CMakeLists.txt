cmake_minimum_required(VERSION 3.8)
project(algo3)

set(CMAKE_CXX_STANDARD 11)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D _GLBCXX_DEBUG -g -Wall -Wextra")

set(SOURCE_FILES TP2/main.cpp TP2/Ej1/Ej1.cpp TP2/Ej1/Ej1.h TP2/Ej2/Ej2.cpp TP2/Ej2/Ej2.h TP2/Ej3/Ej3.cpp TP2/Ej3/Ej3.h TP2/defines.h TP2/parser.cpp)
add_executable(TP2 ${SOURCE_FILES})