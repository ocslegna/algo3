#include "HeavyTransportation.h"

using namespace Ej3;

HeavyTransportation::HeavyTransportation(EJ3Problem problem) {
    this -> routes = problem.routes;
    this -> factories = problem.factories;
    this -> clients = problem.clients;
    this -> n = clients + factories;
}

void HeavyTransportation::init() {
    this -> altura.reserve(this -> n);
    this -> padre.reserve(this -> n);
    for(int i = 0; i < this -> n; i++){
        this -> padre[i] = i;
        this -> altura[i] = 1;
    }
}

int HeavyTransportation::find(int x) {
    if(this -> padre[x] != x){
        this -> padre[x] = find(this -> padre[x]);
    }
    return this -> padre[x];
}

void HeavyTransportation::uni(int x, int y) {
    // union es una palabra reservada en C++, por eso usamos "uni"
    x = find(x);
    y = find(y);
    if(this -> altura[x] < this -> altura[y]){
        this -> padre[x] = y;
    } else {
        this -> padre[y] = x;
        if(this -> altura[x] == this -> altura[y]){
            this -> altura[y]++;
        }
    }
}

void HeavyTransportation::extend_routes() {
    int new_vertex = clients + factories;
    for (int i = 0; i < this -> factories; i++) {
        Edge r{};
        r.origin = new_vertex;
        r.target = clients + i;
        r.weight = 0;
        this -> routes.push_back(r);
    }
    this -> n ++;
}

Solution HeavyTransportation::solve() {

    extend_routes();

    init();
    vector<Edge> res;

    sort(this -> routes.begin(), this -> routes.end()); // ordenamos las aristas por peso de menor a mayor

    for(int i = 0; i < this -> routes.size(); i++){
        Edge a = this -> routes[i];
        if(find(a.origin) != find(a.target)){
            uni(a.origin, a.target);
            res.push_back(a);
        }
    }

    return Solution(res);
}



