#include "Solution.h"

namespace Ej3 {
    Solution::Solution(vector<Edge> routes) {
        this -> total_cost = 0;

        vector<Edge> aux;

        for (auto &route : routes) {
            total_cost += route.weight;
            if(route.weight != 0)
                aux.push_back(route);
        }

        this -> routes = aux;
    }

    Solution::Solution() = default;


    std::ostream & operator<<(std::ostream & Str, Solution const & sol) {
        Str << sol.total_cost << " " << sol.routes.size();

        for (auto route : sol.routes) {
            Str << " " << route.origin + 1 << " " << route.target + 1;
        }

        Str << endl;

        return Str;
    }

}
