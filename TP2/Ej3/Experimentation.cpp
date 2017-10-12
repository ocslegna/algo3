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

// Genero grafos K cada vez mas grandes, y comparo los tiempos dandole al algoritmo los ejes ya ordenados/random/orden invertido
void Experimentation::second_experiment() {
    std::ofstream csv;
    csv.open ("../Experimentacion/Resultados/EJ3/second_experiment.csv");
    csv << "vertices,routes,nanoseconds_sorted,nanoseconds_random,nanoseconds_inverted\n";

    Generator generator;

    for (int n = 3; n < 100; n++) {

        std::cout << n << endl;
        int reps = 50;
        while(reps > 0) {
            reps--;
            // Creo instancia random con cantidad de clientes y fabricas constante y cada vez mas ejes.
            EJ3Problem problem = generator.generate_complete_instance(n, n - 1, n);

            //random
            HeavyTransportation ht(problem);
            double random = measureHT(ht);

            vector<Edge> routes = problem.routes;
            sort(routes.begin(), routes.end());
            problem.routes = routes;

            HeavyTransportation ht2(problem);
            double sorted = measureHT(ht2);

            vector<Edge> inverted_routes(routes.size());

            for (int i = 0; i < routes.size(); i++) {
                inverted_routes[routes.size() - 1 - i] = routes[i];
            }

            problem.routes = inverted_routes;
            HeavyTransportation ht3(problem);
            double inverted = measureHT(ht3);

            csv << n + n - 1 << "," << problem.routes.size() << "," << sorted << "," << random << "," << inverted << "\n";
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
//    experimentation.first_experiment();
    experimentation.second_experiment();
}

