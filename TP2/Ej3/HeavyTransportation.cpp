#include "HeavyTransportation.h"

using namespace Ej3;

HeavyTransportation::HeavyTransportation(AdjacencyMatrix adjacency_matrix) {
    this -> adjacency_matrix = adjacency_matrix;
    this -> n = static_cast<unsigned int>(adjacency_matrix.size());
}

Solution HeavyTransportation::solve() {
    vector< vector<int> > adyacencia = this->adjacency_matrix;
    vector< vector<int> > arbol(n);
    vector<Route> solution_routes;
    vector<int> pertenece(n); // indica a que árbol pertenece el nodo

    for(int i = 0; i < n; i++){
        arbol[i] = vector<int> (n, 0);
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
                if((min > adyacencia[i][j] || min == -1) && adyacencia[i][j]!=0 && pertenece[i] != pertenece[j]){
                    min = adyacencia[i][j];
                    nodoA = i;
                    nodoB = j;
                }

        // Si los nodos no pertenecen al mismo árbol agrego el arco al árbol mínimo.
        if(pertenece[nodoA] != pertenece[nodoB]){
            arbol[nodoA][nodoB] = min;
            arbol[nodoB][nodoA] = min;

            Route r{};
            r.origin = nodoA + 1;
            r.target = nodoB + 1;
            r.weight = min;
            solution_routes.push_back(r);

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



