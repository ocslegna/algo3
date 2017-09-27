#include "Solution.h"
#include "../defines.h"

namespace Ej3 {
    Solution::Solution(vector<Route> routes) {
        this -> routes = routes;
        this -> total_cost = 0;

        for(int i = 0; i < routes.size(); i++) {
            total_cost += routes[i].weight;
        }
    }

    Solution::Solution() {}


    std::ostream & operator<<(std::ostream & Str, Solution const & sol) {
        Str << sol.total_cost << " " << sol.routes.size();

        for (int i = 0; i < sol.routes.size(); i++) {
            Str << " " << sol.routes[i].origin << " " << sol.routes[i].target;
        }

        Str << endl;

        return Str;
    }

}
