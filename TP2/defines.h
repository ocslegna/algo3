#ifndef ALGO3_DEFINES_H
#define ALGO3_DEFINES_H

#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <functional>
#include <set>

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
void parsear();


/* Experiment */
void print_experiment_values (Experiment &experiment, unsigned int &global_value);

/* Solve */
void run(unsigned int &global_count, Experiment &init_experiment, Experiment &experiment);
unsigned int solve(unsigned int &global_count, Experiment &experiment);


#endif //ALGO3_DEFINES_H
