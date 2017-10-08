#include "Experimentation.h"
#include <iostream>
#include <fstream>

using namespace Ej3;

// Dejo fija la cantidad de fabricas, y crezco en la cantidad de clientes
void Experimentation::first_experiment() {
    int factories = 10;
    std::ofstream csv;
    csv.open ("../Experimentacion/Resultados/EJ3/first_experiment.csv");
    csv << "clients,factories,milliseconds\n";

    for (int clients = 5; clients < 100; clients++) {
        int reps = 200;
        while(reps > 0) {
            reps--;
            csv << "4,3,4\n";
        }
    }

    csv.close();
}

void Experimentation::run() {
    Experimentation experimentation;
    experimentation.first_experiment();
}
