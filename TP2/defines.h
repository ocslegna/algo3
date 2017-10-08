#ifndef ALGO3_DEFINES_H
#define ALGO3_DEFINES_H

#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <functional>
#include <set>
#include <stdlib.h>

using namespace std;
using namespace std::chrono;

/* Structures */
struct Experiment;


/* Timing */
void start_clock(high_resolution_clock::time_point &T_START);
void stop_clock(high_resolution_clock::time_point &T_START, high_resolution_clock::time_point &T_END);


/* General and container's actions */


/* Validation */
void validate_argc(const int &argc, char *argv[]);
void parse(); // Sino, implementar parser.cpp con el parseo de todos los ejercicios.


/* Experiment */
void print_experiment_values (Experiment &experiment, unsigned int &global_value);


/* Solve */
void run();

typedef vector <vector <int> > AdjacencyMatrix;
typedef vector <vector <unsigned> > costMatrix;

typedef struct {
    unsigned int origin;
    unsigned int target;
    unsigned int weight;
} Edge;

typedef struct {
    costMatrix cost_matrix;
    unsigned works;
} EJ1Problem;

typedef struct {
    AdjacencyMatrix adj_matrix;
    unsigned servidores;
    unsigned enlaces;
} EJ2Problem;

typedef struct {
    vector<Edge> Edges;
    int factories;
    int clients;
} EJ3Problem;

#endif //ALGO3_DEFINES_H
