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

    // TODO: volver a incorporar al azar algunos de los ejes removidos!

    problem.routes = tree_routes;
    problem.factories = factories;
    problem.clients = clients;

    return problem;
}

vector<Edge> Generator::routes_for_complete_graph(unsigned int k, unsigned int max_weight) {
    vector<Edge> routes;

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; i < k; i++) {
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

    int arcos = 1;

    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(complete_edges), std::end(complete_edges), rng);

    while(arcos < n){
        Edge r = complete_edges.back();
        complete_edges.pop_back();

        if(pertenece[r.origin] != pertenece[r.target]){

            solution_routes.push_back(r);

            // Todos los nodos del árbol del nodoB ahora pertenecen al árbol del nodoA.
            int temp = pertenece[r.target];
            pertenece[r.target] = pertenece[r.origin];
            for(int k = 0; k < n; k++)
                if(pertenece[k] == temp)
                    pertenece[k] = pertenece[r.origin];

            arcos++;
        }
    }
}