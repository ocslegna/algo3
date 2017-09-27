cmake_minimum_required(VERSION 3.6)
project(algo3)

set(CMAKE_CXX_STANDARD 11)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D _GLBCXX_DEBUG -g -Wall -Wextra")

set(SOURCE_FILES TP2/main.cpp TP2/Ej1/Ej1.cpp TP2/Ej1/Ej1.h TP2/Ej2/Ej2.cpp TP2/Ej2/Ej2.h TP2/Ej3/HeavyTransportation.cpp TP2/Ej3/HeavyTransportation.h TP2/Ej3/Parser.cpp TP2/Ej3/Parser.h TP2/defines.h TP2/parser.cpp TP2/Ej3/Solution.cpp TP2/Ej3/Solution.h)
add_executable(TP2 ${SOURCE_FILES})