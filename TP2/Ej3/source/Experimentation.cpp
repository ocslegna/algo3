#include "Experimentation.h"
#include "Generator.h"
#include <fstream>

using namespace Ej3;

// Dejo fija la cantidad de clientes y fabricas y crezo la cantidad de ejes
void Experimentation::first_experiment() {
    std::ofstream csv;
    csv.open ("./Resultados/EJ3/first_experiment.csv");
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
    csv.open ("./Resultados/EJ3/second_experiment.csv");
    csv << "vertices,nanoseconds_sorted,nanoseconds_random,nanoseconds_inverted\n";

    Generator generator;

    for (int n = 3; n < 200; n++) {

        std::cout << n << endl;
        int reps = 100 ;
        while(reps > 0) {
            reps--;

            EJ3Problem problem = generator.generate_complete_instance(n, n - 1, 10000000);
            HeavyTransportation ht(problem);
            double random = measureHT(ht);

            EJ3Problem problem2 = generator.generate_complete_instance(n, n - 1, 10000000);
            sort(problem2.routes.begin(), problem2.routes.end());
            HeavyTransportation ht2(problem2);
            double sorted = measureHT(ht2);

            EJ3Problem problem3 = generator.generate_complete_instance(n, n - 1, 10000000);
            vector<Edge> inverted_routes(problem3.routes.size());
            for (int i = 0; i < problem3.routes.size(); i++) {
                inverted_routes[problem3.routes.size() - 1 - i] = problem3.routes[i];
            }
            problem3.routes = inverted_routes;
            HeavyTransportation ht3(problem3);
            double inverted = measureHT(ht3);

            csv << n + n - 1 << "," << sorted << "," << random << "," << inverted << "\n";
        }
    }

    csv.close();
}


// Genero grafos K cada vez mas grandes, y comparo los tiempos dandole al algoritmo los ejes ya ordenados/random/orden invertido
void Experimentation::third_experiment() {
    std::ofstream csv;
    csv.open ("./Resultados/EJ3/third_experiment.csv");
    csv << "factories,nanoseconds\n";

    Generator generator;


    for (int factories = 100; factories < 450; factories++) {

        std::cout << factories << endl;
        int reps = 50;
        while(reps > 0) {
            reps--;

            EJ3Problem problem = generator.generate_complete_instance(factories, 1000 - factories, 10000000);
            HeavyTransportation ht(problem);

            csv << factories << "," << measureHT(ht) << "\n";
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
//    experimentation.second_experiment();
    experimentation.third_experiment();
}

