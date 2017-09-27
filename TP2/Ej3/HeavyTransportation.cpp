#include "HeavyTransportation.h"

using namespace Ej3;

HeavyTransportation::HeavyTransportation(AdjacencyMatrix adjacency_matrix) {
    this -> adjacency_matrix = adjacency_matrix;
}

Solution HeavyTransportation::solve() {
    vector<Route> routes(1);
    Route r;
    r.weight = 5;
    r.origin = 1;
    r.target = 2;
    routes[0] = r;
    return Solution(routes);
}



