#include "Solution.h"

namespace Ej1 {
    Solution::Solution(vector<Edge> routes) {
        this -> routes = routes;
        this -> total_cost = 0;

        for (auto &route : routes) {
            total_cost += route.weight;
        }
    }

    Solution::Solution() = default;


    std::ostream & operator<<(std::ostream & Str, Solution const & sol) {
        Str << sol.total_cost << " " << sol.routes.size();

        for (auto route : sol.routes) {
            Str << " " << route.origin << " " << route.target;
        }

        Str << endl;

        return Str;
    }

}
