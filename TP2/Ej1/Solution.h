#ifndef EJ1_SOLUTION_H
#define EJ1_SOLUTION_H


#include "../defines.h"

namespace Ej1 {
    class Solution {
    public:
        int total_cost;
        vector <Edge> routes;
        Solution(vector<Edge> routes);
        Solution();
        friend ostream& operator<<(ostream& os, const Solution& dt);
    };
}


#endif //EJ1_SOLUTION_H
