#ifndef ALGO3_EJ3_H
#define ALGO3_EJ3_H

#include "../defines.h"
#include "Solution.h"

namespace Ej3 {
    class HeavyTransportation {
    private:
        vector<Route> routes;
        void extend_routes();
        unsigned n, clients, factories;
    public:
        explicit HeavyTransportation(EJ3Problem problem);
        Solution solve();
    };
}

#endif //ALGO3_EJ3_H

