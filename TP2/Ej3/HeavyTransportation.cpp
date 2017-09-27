#include "HeavyTransportation.h"

using namespace Ej3;

HeavyTransportation::HeavyTransportation(AdjacencyMatrix adjacency_matrix) {
    this -> adjacency_matrix = adjacency_matrix;
}

Solution HeavyTransportation::solve() {
    vector<Route> routes;
    Route r;
    r.weight = 5;
    r.origin = 1;
    r.target = 2;
    Route r2;
    r2.weight = 6;
    r2.origin = 1;
    r2.target = 3;
    routes.push_back(r);
    routes.push_back(r2);
    return Solution(routes);
}



