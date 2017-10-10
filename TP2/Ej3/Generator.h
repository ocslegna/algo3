//
// Created by Nicolás Risso on 10/7/17.
//

#ifndef ALGO3_GENERATOR_H
#define ALGO3_GENERATOR_H

#include "../defines.h"

namespace Ej3 {
    class Generator {
    public:
        EJ3Problem generate_random_instance(unsigned int factories, unsigned int clients, unsigned int max_weight);
        EJ3Problem generate_complete_instance(unsigned int factories, unsigned int clients, unsigned int max_weight);
        vector<Edge> routes_for_complete_graph(unsigned int k, unsigned int max_weight);
        vector<Edge> create_tree_routes(vector<Edge> complete_edges, unsigned int n);
    };
}

#endif //ALGO3_GENERATOR_H
