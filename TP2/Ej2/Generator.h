#ifndef ALGO3_GENERATOR_H
#define ALGO3_GENERATOR_H

namespace Ej2 {
    class Generator {
    public:
        EJ2Problem generate_random_instance();
        vector<Route> routes_for_complete_graph(unsigned int k, unsigned int max_weight);
        vector<Route> create_tree_routes(vector<Route> complete_edges, unsigned int n);
    };
}

#endif //ALGO3_GENERATOR_H
