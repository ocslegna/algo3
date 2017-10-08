#ifndef ALGO3_GENERATOR_H
#define ALGO3_GENERATOR_H

#include "../defines.h"

namespace Ej2 {
    class Generator {
    public:
        EJ2Problem generate_random_instance();
        vector<Edge> routes_for_complete_graph(unsigned int k, unsigned int max_weight);
        vector<Edge> create_tree_routes(vector<Edge> complete_edges, unsigned int n);
    };
}

#endif //ALGO3_GENERATOR_H
