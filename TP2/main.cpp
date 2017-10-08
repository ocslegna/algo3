#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <functional>
#include <set>

#include "Ej1/Parser.h"
#include "Ej1/Solution.h"
#include "Ej2/Ej2.h"
#include "Ej3/HeavyTransportation.h"
#include "Ej3/Parser.h"
#include "Ej3/Solution.h"
#include "defines.h"

bool EXPERIMENTATION = false;

using namespace std;
using namespace std::chrono;

unsigned int ITERATIONS = 1, EXERCISE = 0;
long T_DURATION;
string FIRST, SECOND;

vector<EJ1Problem> ej1_problems;
vector<EJ3Problem> ej3_problems;

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
    if (argc != 3) {
        if(argc != 1) {
            cout << "You need to supply two arguments EXERCISE and ITERATIONS to this program." << endl;
            exit (EXIT_FAILURE);
        }
    } else {
        /* Los argumentos deberán ser -> Experimentacion: "E NumeroEjercicio" ó "NumeroEjercicio CantidadIteraciones" */
        FIRST = argv[1];
        SECOND = argv[2];
        if(FIRST == "e" || FIRST == "E"){
            EXPERIMENTATION = true;
            EXERCISE = static_cast<unsigned int>(strtol(argv[2], nullptr, 10));
        } else {
            EXERCISE = static_cast<unsigned int>(strtol(argv[1], nullptr, 10));
            ITERATIONS = static_cast<unsigned int>(strtol(argv[2], nullptr, 10));
        }

        if (EXERCISE >= 4 || EXERCISE <= 0) {
            cout << "Invalid exercise " << EXERCISE << ", please select 1, 2 or 3." << endl;
            exit (EXIT_FAILURE);
        }
    }

}

void parse() {
    // Parsear aca o en parser.cpp ej1 o ej2 o ej3.
    // TODO: Hacer parsers separados e invocar acá. (agregar list/vector de argumentos -corresponden a ejercicio-).

    switch ( EXERCISE ){
        case 1:
            Ej1::Parser ej1_parser;
            ej1_problems = ej1_parser.parse(std::cin);
            break;
        case 2:
            // Parse Ej2
            break;
        case 3:
            Ej3::Parser ej3_parser;
            ej3_problems = ej3_parser.parse(std::cin);
            break;
        default:
            cout << "Invalid exercise " << EXERCISE << ", please select 1, 2 or 3." << endl;
            exit(EXIT_FAILURE);
    }
}

/* General and container's actions */


/* Experiment */
void print_experiment_values (Experiment &experiment, unsigned int &global_value) {
    if(EXPERIMENTATION){
        cerr << "field1 " << experiment.field1 << endl;
        cerr << "field2 " << global_value << endl;
        cerr << "field3 " << 3 << endl;
        cerr << "field4 " << 4 << endl;
    }
}


/* Solve */
void run_experiment() {
    switch ( EXERCISE ){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            cout << "Invalid exercise " << EXERCISE << ", please select 1, 2 or 3." << endl;
            exit(EXIT_FAILURE);
    }
}

void run() {
    switch ( EXERCISE ){
        case 1:
            break;
        case 2:
            break;
        case 3:
            for (const auto &ej3_problem : ej3_problems) {
                Ej3::HeavyTransportation heavy_transportation(ej3_problem);
                Ej3::Solution ej3_solution;
                ej3_solution = heavy_transportation.solve();

                cout << ej3_solution;
            }
            break;
        default:
            cout << "Invalid exercise " << EXERCISE << ", please select 1, 2 or 3." << endl;
            exit(EXIT_FAILURE);
    }
}


int main(int argc, char *argv[]) {
    validate_argc (argc, argv);

    if(EXPERIMENTATION) {
        run_experiment();
        return 0;
    }

    srand (static_cast<unsigned int>(time (nullptr)));
    high_resolution_clock::time_point T_START, T_END;

    unsigned int GLOBAL_VALUE = 0;

    parse ();

    start_clock (T_START);
    run ();
    stop_clock (T_START, T_END);

    print_experiment_values (EXPERIMENT, GLOBAL_VALUE);
    return 0;
}