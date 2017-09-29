#ifndef ALGO3_EJ3_H
#define ALGO3_EJ3_H

#include "../defines.h"
#include "Solution.h"

namespace Ej3 {
    class HeavyTransportation {
    private:
        AdjacencyMatrix adjacency_matrix;
        void extend_adjacency_matrix();
        unsigned n, clients, factories;
    public:
        explicit HeavyTransportation(EJ3Problem problem);
        Solution solve();
    };
}

#endif //ALGO3_EJ3_H

