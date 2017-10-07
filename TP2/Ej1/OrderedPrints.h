#ifndef ALGO3_EJ1_H
#define ALGO3_EJ1_H

#include "../defines.h"
#include "Solution.h"

namespace Ej1 {
    class OrderedPrints {
    private:
        AdjacencyMatrix adjacency_matrix;
        void extend_adjacency_matrix();
        unsigned n, clients, factories;
    public:
        explicit OrderedPrints(EJ1Problem problem);
        Solution solve();
    };
}

#endif //ALGO3_EJ1_H

