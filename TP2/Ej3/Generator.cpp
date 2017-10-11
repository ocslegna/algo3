#include "Generator.h"
#include "../defines.h"
#include <random>

using namespace Ej3;

EJ3Problem Generator::generate_random_instance(unsigned int factories, unsigned int clients, unsigned int routes, unsigned int max_weight) {
    EJ3Problem problem;

    int n = factories + clients;
    // Genero un grafo K
    vector<Edge> complete_routes = routes_for_complete_graph(n, max_weight);

    // Tomo el grafo generado anteriromento y me quedo con un árbol (de esta manera es conexo seguro)
    vector<Edge> tree_routes = create_tree_routes(complete_routes, n);

    // Le vuelvo a agregar tantas rutas como me piden
    int i = tree_routes.size();
    while (i < routes) {
        for (int j = 0; j < complete_routes.size(); j++) {
            Edge cr = complete_routes[j];
            bool exists = false;

            for (int k = 0; k < tree_routes.size(); k++) {
                Edge tr = tree_routes[k];
                if (tr.origin == cr.origin && tr.target == cr.target) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                tree_routes.push_back(cr);
                i++;
                break;
            }
        }
    }

    problem.routes = tree_routes;
    problem.factories = factories;
    problem.clients = clients;

    return problem;
}

EJ3Problem Generator::generate_complete_instance(unsigned int factories, unsigned int clients, unsigned int max_weight) {
    EJ3Problem problem;

    vector<Edge> complete_routes = routes_for_complete_graph(factories + clients, max_weight);

    problem.routes = complete_routes;
    problem.factories = factories;
    problem.clients = clients;

    return problem;
}

vector<Edge> Generator::routes_for_complete_graph(unsigned int k, unsigned int max_weight) {
    vector<Edge> routes;

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            Edge route;
            route.origin = i;
            route.target = j;
            route.weight = rand() % max_weight + 1;
            routes.push_back(route);
        }
    }

    return routes;
}

vector<Edge> Generator::create_tree_routes(vector<Edge> complete_edges, unsigned int n) {
    vector<Edge> solution_routes;
    vector<int> pertenece(n); // indica a que árbol pertenece el nodo

    for(int i = 0; i < n; i++){
        pertenece[i] = i;
    }

    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(complete_edges), std::end(complete_edges), rng);

    for (int i = 0; i < complete_edges.size(); i++){

        Edge r = complete_edges[i];

        if(pertenece[r.origin] != pertenece[r.target]){

            solution_routes.push_back(r);

            // Todos los nodos del árbol del nodoB ahora pertenecen al árbol del nodoA.
            int temp = pertenece[r.target];
            pertenece[r.target] = pertenece[r.origin];
            for(int k = 0; k < n; k++)
                if(pertenece[k] == temp)
                    pertenece[k] = pertenece[r.origin];

        }
    }

    return solution_routes;
}