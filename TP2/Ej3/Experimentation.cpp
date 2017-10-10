#include "Experimentation.h"
#include "Generator.h"
#include "../defines.h"
#include <fstream>

using namespace Ej3;

// Genero grafos completos, clientes y fabricas crecen a la par
void Experimentation::first_experiment() {
    std::ofstream csv;
    csv.open ("../Experimentacion/Resultados/EJ3/first_experiment.csv");
    csv << "clients,factories,routes,nanoseconds\n";

    Generator generator;

    for (int n = 5; n < 100; n++) {

        std::cout << n << endl;
        int reps = 100;
        while(reps > 0) {
            reps--;
            EJ3Problem problem = generator.generate_complete_instance(n, n-1, 1000);

            HeavyTransportation ht(problem);

            csv << n << "," << n-1 << "," << problem.routes.size() << "," << measureHT(ht) << "\n";
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
