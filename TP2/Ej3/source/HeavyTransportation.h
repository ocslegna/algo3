#ifndef ALGO3_EJ3_H
#define ALGO3_EJ3_H

#include "../defines.h"
#include "Solution.h"

namespace Ej3 {
    class HeavyTransportation {
    private:
        vector<Edge> routes;
        void extend_routes();
        int find(int x);
        void uni(int x, int y);
        unsigned n, clients, factories;
        vector<int> altura, padre;
        void init();
    public:
        explicit HeavyTransportation(EJ3Problem problem);
        Solution solve();
    };
}

#endif //ALGO3_EJ3_H

