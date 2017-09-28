#ifndef ALGO3_EJ3_H
#define ALGO3_EJ3_H

#include "../defines.h"
#include "Solution.h"

namespace Ej3 {
    class HeavyTransportation {
    private:
        AdjacencyMatrix adjacency_matrix;
        unsigned int n;
    public:
        explicit HeavyTransportation(AdjacencyMatrix adjacency_matrix);
        Solution solve();
    };
}

#endif //ALGO3_EJ3_H

