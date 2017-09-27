#ifndef ALGO3_SOLUTION_H
#define ALGO3_SOLUTION_H


#include "../defines.h"

namespace Ej3 {
    class Solution {
    public:
        int total_cost;
        vector <Route> routes;
        Solution(vector<Route> routes);
        Solution();
        friend ostream& operator<<(ostream& os, const Solution& dt);
    };
}


#endif //ALGO3_SOLUTION_H
