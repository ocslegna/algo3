#include "OrderedPrints.h"

using namespace Ej1;

OrderedPrints::OrderedPrints(EJ1Problem problem) {

    this -> adjacency_matrix = problem.adjacency_matrix;
    this -> factories = problem.factories;
    this -> clients = problem.clients;
    this -> n = clients + factories;
}

void OrderedPrints::extend_adjacency_matrix() {
    vector<int> new_row(n, -1);

    for (int i = 0; i < n; i++) {
        if (i < factories) {
            this -> adjacency_matrix[i].push_back(
                0); // Esto es conectar la fábrica con un eje de peso 0 a un nuevo vértice
            new_row[i] = 0;
        } else {
            this -> adjacency_matrix[i].push_back(-1);
        }
    }

    this -> adjacency_matrix.push_back(new_row);
    this -> n ++;
}

Solution OrderedPrints::solve() {
    extend_adjacency_matrix();

    vector< vector<int> > adyacencia = this->adjacency_matrix;
    vector<Route> solution_routes;
    vector<int> pertenece(n); // indica a que árbol pertenece el nodo

    for(int i = 0; i < n; i++){
        pertenece[i] = i;
    }

    int nodoA = 0;
    int nodoB = 0;
    int arcos = 1;
    while(arcos < n){
        // Encontrar  el arco mínimo que no forma ciclo y guardar los nodos y la distancia.
        int min = -1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if((min > adyacencia[i][j] || min == -1) && adyacencia[i][j]!=-1 && pertenece[i] != pertenece[j]){
                    min = adyacencia[i][j];
                    nodoA = i;
                    nodoB = j;
                }

        // Si los nodos no pertenecen al mismo árbol agrego el arco al árbol mínimo.
        if(pertenece[nodoA] != pertenece[nodoB]){


            if (min != 0) {
                Route r{};
                r.origin = nodoA + 1;
                r.target = nodoB + 1;
                r.weight = min;
                solution_routes.push_back(r);
            }

            // Todos los nodos del árbol del nodoB ahora pertenecen al árbol del nodoA.
            int temp = pertenece[nodoB];
            pertenece[nodoB] = pertenece[nodoA];
            for(int k = 0; k < n; k++)
                if(pertenece[k] == temp)
                    pertenece[k] = pertenece[nodoA];

            arcos++;
        }
    }


    return Solution(solution_routes);
}



