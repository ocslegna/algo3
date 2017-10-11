#include "Experimentation.h"
#include "Generator.h"
#include "../defines.h"
#include <fstream>

using namespace Ej3;

// Dejo fija la cantidad de clientes y fabricas y crezo la cantidad de ejes
void Experimentation::first_experiment() {
    std::ofstream csv;
    csv.open ("../Experimentacion/Resultados/EJ3/first_experiment.csv");
    csv << "clients,factories,routes,nanoseconds\n";

    Generator generator;

    unsigned int clients = 51, factories = 49;
    unsigned int min_amount_of_edges = 100;
    unsigned int max_amount_of_edges = 4950;

    for (int n = min_amount_of_edges; n < max_amount_of_edges; n++) {

        std::cout << n << endl;
        int reps = 50;
        while(reps > 0) {
            reps--;
            // Creo instancia random con cantidad de clientes y fabricas constante y cada vez mas ejes.
            EJ3Problem problem = generator.generate_random_instance(clients, factories, n, n);

            HeavyTransportation ht(problem);

            csv << clients << "," << factories << "," << problem.routes.size() << "," << measureHT(ht) << "\n";
        }
    }

    csv.close();
}

// Dejo fija la cantidad de clientes y fabricas y crezo la cantidad de ejes
void Experimentation::second_experiment() {
    std::ofstream csv;
    csv.open ("../Experimentacion/Resultados/EJ3/first_experiment.csv");
    csv << "clients,factories,routes,nanoseconds\n";

    Generator generator;

    unsigned int clients = 51, factories = 49;
    unsigned int min_amount_of_edges = 100;
    unsigned int max_amount_of_edges = 4950;

    for (int n = min_amount_of_edges; n < max_amount_of_edges; n++) {

        std::cout << n << endl;
        int reps = 50;
        while(reps > 0) {
            reps--;
            // Creo instancia random con cantidad de clientes y fabricas constante y cada vez mas ejes.
            EJ3Problem problem = generator.generate_random_instance(clients, factories, n, n);

            HeavyTransportation ht(problem);

            csv << clients << "," << factories << "," << problem.routes.size() << "," << measureHT(ht) << "\n";
        }
    }

    csv.close();
}

double Experimentation::measureHT(HeavyTransportation ht) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    ht.solve();

    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
}

void Experimentation::run() {
    Experimentation experimentation;
    experimentation.first_experiment();
}
