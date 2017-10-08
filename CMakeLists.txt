cmake_minimum_required(VERSION 3.6)
project(algo3)

set(CMAKE_CXX_STANDARD 11)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D _GLBCXX_DEBUG -g -Wall -Wextra")

set(SOURCE_FILES TP2/main.cpp TP2/Ej1/Parser.cpp TP2/Ej1/Parser.h TP2/Ej1/OrderedPrints.cpp TP2/Ej1/OrderedPrints.h TP2/Ej1/Solution.cpp TP2/Ej1/Solution.h TP2/Ej2/Ej2.cpp TP2/Ej2/Ej2.h TP2/Ej3/HeavyTransportation.cpp TP2/Ej3/HeavyTransportation.h TP2/Ej3/Parser.cpp TP2/Ej3/Parser.h TP2/defines.h TP2/Ej3/Solution.cpp TP2/Ej3/Solution.h  TP2/Ej3/Experimentation.cpp TP2/Ej3/Experimentation.h TP2/Ej3/Generator.cpp TP2/Ej3/Generator.h TP2/Ej2/Experimentation.cpp TP2/Ej2/Experimentation.h TP2/Ej2/Generator.cpp TP2/Ej2/Generator.h TP2/Ej2/Parser.cpp TP2/Ej2/Parser.h TP2/Ej2/Solution.cpp TP2/Ej2/Solution.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/TP2/build")

add_executable(TP2 ${SOURCE_FILES})