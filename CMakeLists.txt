cmake_minimum_required(VERSION 3.6)
project(algo3)

set(CMAKE_CXX_STANDARD 11)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D _GLBCXX_DEBUG -g -Wall -Wextra")

set(SOURCE_FILES TP2/Ej3/main.cpp TP2/Ej3/source/HeavyTransportation.cpp TP2/Ej3/source/HeavyTransportation.h TP2/Ej3/source/Parser.cpp TP2/Ej3/source/Parser.h TP2/Ej3/defines.h TP2/Ej3/source/Solution.cpp TP2/Ej3/source/Solution.h TP2/Ej3/source/Experimentation.cpp TP2/Ej3/source/Experimentation.h TP2/Ej3/source/Generator.cpp TP2/Ej3/source/Generator.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/TP2/build")

add_executable(TP2 ${SOURCE_FILES})