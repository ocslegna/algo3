#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <functional>
#include <set>

#include "Ej3/HeavyTransportation.h"
#include "Ej3/Parser.h"
#include "Ej3/Solution.h"
#include "defines.h"
#include "Ej3/Experimentation.h"

bool EXPERIMENTATION = false;

using namespace std;
using namespace std::chrono;

unsigned int ITERATIONS = 1, EXERCISE = 0;
long T_DURATION;
string FIRST;

vector<EJ3Problem> ej3_problems;

/* Timing */
void start_clock (high_resolution_clock::time_point &T_START) {
    T_START = high_resolution_clock::now ();
}

void stop_clock (high_resolution_clock::time_point &T_START, high_resolution_clock::time_point &T_END) {
    T_END = high_resolution_clock::now ();
    T_DURATION = (duration_cast<microseconds> (T_END - T_START).count ()) / ITERATIONS;
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
    switch ( EXERCISE ){
        case 1:
//            Ej1::Parser ej1_parser;
//            ej1_problems = ej1_parser.parse(std::cin);
            break;
        case 2:
//            Ej2::Parser ej2_parser;
//            ej2_problems = ej2_parser.parse (std::cin);
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

/* Solve */
void run_experiment() {
    switch ( EXERCISE ){
        case 1:
            break;
        case 2:
            break;
        case 3:
            Ej3::Experimentation experimentation;
            experimentation.run();
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

    parse ();

    start_clock (T_START);
    run ();
    stop_clock (T_START, T_END);
    return 0;
}