#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <functional>
#include <set>
#include <cassert>

#include "Ej1/Ej1.h"
#include "Ej2/Ej2.h"
#include "Ej3/Ej3.h"
#include "defines.h"

#define EXPERIMENTATION

using namespace std;
using namespace std::chrono;

unsigned int ITERATIONS = 1, EXERCISE = 0;
long T_DURATION;


/* Structures */
struct Experiment { // Ejemplo estructura a experimentar para luego redireccionar por cerr.
    unsigned int field1{};
    unsigned int field2{};
    unsigned int field3{};
    vector< tuple<unsigned int, unsigned int, unsigned int, unsigned int> > field4;
    vector< pair<unsigned int, unsigned int> > field5;

    Experiment(unsigned int &f1,
               unsigned int &f2,
               unsigned int &f3,
               vector< tuple<unsigned int, unsigned int, unsigned int, unsigned int> > &f4,
               vector< pair<unsigned int, unsigned int> > &f5) {
        field1= f1;
        field2 = f2;
        field3 = f3;
        field4 = f4;
        field5 = f5;
    }

    Experiment() = default;

    Experiment &operator=(const Experiment &e)= default;

    ~Experiment() = default;

    Experiment(const Experiment &e) {
        field1 = e.field1;
        field2 = e.field2;
        field3 = e.field3;
        field4 = e.field4;
        field5 = e.field5;
    }
};
Experiment EXPERIMENT, INIT_EXPERIMENT;


/* Timing */
void start_clock (high_resolution_clock::time_point &T_START) {
    T_START = high_resolution_clock::now ();
}

void stop_clock (high_resolution_clock::time_point &T_START, high_resolution_clock::time_point &T_END) {
    T_END = high_resolution_clock::now ();
    T_DURATION = (duration_cast<microseconds> (T_END - T_START).count ()) / ITERATIONS;
    cerr << "time " << T_DURATION << endl;
}


/* Validation */
void validate_argc (const int &argc, char *argv[]) {
    // Ejercicios a correr y otros argumentos.

    if (argc != 3) {
        if(argc != 1) {
            cout << "You need to supply two arguments EXERCISE and ITERATIONS to this program." << endl;
            exit (EXIT_FAILURE);
        }
    } else {
        EXERCISE = static_cast<unsigned int>(strtol(argv[1], nullptr, 10));
        ITERATIONS = static_cast<unsigned int>(strtol(argv[2], nullptr, 10));
    }

}

void parse() {
    // Parsear aca o en parser.cpp ej1 o ej2 o ej3.
}

/* General and container's actions */


/* Experiment */
void print_experiment_values (Experiment &experiment, unsigned int &global_value) {
#ifdef EXPERIMENTATION
    cerr << "field1 " << global_value << endl;
    cerr << "field2 " << 2 << endl;
    cerr << "field3 " << 3 << endl;
#endif
}


/* Solve */
void run(unsigned int &global_count, Experiment &init_experiment, Experiment &experiment) {
    // Corre ej1 o ej2 o ej3 con sus respectivos parametros a definir.

    for (unsigned int i = 0; i < ITERATIONS; ++i) {
        experiment = init_experiment;
        global_count = 0;
        solve(global_count, experiment);
    }
}

unsigned int solve(unsigned int &global_count, Experiment &experiment) {
    return 1;
}


int main(int argc, char *argv[]) {
    validate_argc (argc, argv);

    srand (static_cast<unsigned int>(time (nullptr)));
    high_resolution_clock::time_point T_START, T_END;

    unsigned int GLOBAL_VALUE = 0, COUNT_AFFIRMATIONS = 0;
    vector<pair<unsigned int, int> > AFFIRMATIONS;

    parse ();

    start_clock (T_START);
    run (GLOBAL_VALUE, INIT_EXPERIMENT, EXPERIMENT);
    stop_clock (T_START, T_END);

#ifdef EXPERIMENTATION
    print_experiment_values (EXPERIMENT, GLOBAL_VALUE);
#endif
    return 0;
}