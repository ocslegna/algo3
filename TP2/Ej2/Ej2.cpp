#include "Ej2.h"

vector<int> Prim(MatrizAdyacencias &M){
	unsigned long n = M.size();

	vector<int> distancia(n, -1);
	vector<int> padre(n, -1);
	vector<bool> visitado(n, false);

	int v = 1;
	for (unsigned int w = 2; w < n; w++){
		if( M[v][w] > 0 ){
			distancia[w] = M[v][w];
			padre[w] = v;
		}
	}

	distancia[v] = 0;
	visitado[v] = true;

	unsigned int cant_visitados = 1;
	int min;
	while (cant_visitados < n){

		min = 2;
		for(unsigned int i = 2; i < n; i++){
			// Busco el de menor distancia
			if(not visitado[i] and distancia[i] > 0 and distancia[i] < distancia[min] ){
				min = i;
			}
		}

		// Actualizo visitados
		visitado[min] = true;
		cant_visitados++;

		// Actualizo distancias.
		if(cant_visitados != n-1){
			for(unsigned int w = 1; w < n; w++){
				if( M[min][w] > 0 ){
					if( distancia[w] > M[min][w] ){
						distancia[w] = M[min][w];
						padre[w] = min;
					}
				}
			}
		}
	}
	return padre;
}

// Devuelve el costo total
int ConstruirSolucion(MatrizAdyacencias &M, vector<int> &padre, vector<Arista> &aristas, int raiz){

	auto n = static_cast<int>(padre.size());
	
	int costo = 0;
	
	for(int i = 1; i < n; i++){
		if(i != raiz and padre[i] == raiz){
			Arista e = make_pair(raiz, i);
			aristas.push_back(e);
			costo += M[raiz][i];
			raiz = i;
		}
	}

	return costo;
}





list<int> CaminoEntreDFS(vector< list<int> > &graph, int u, int v){
	
	vector<bool> visitado(graph.size(), false);
	vector<int> padre(graph.size(), -1);
	stack<int> Pila;
	Pila.push(u);

	while(not Pila.empty()){
		int w = Pila.top();
		if (w == v) break;
		Pila.pop();
		visitado[w] = true;
		
		for(auto it = graph[w].begin(); it != graph[w].end(); it++){
				int k = *it;
				if(visitado[k] == false){
					Pila.push(k);
					padre[k] = w;
				}
		}
	}

	int inicial = v;
	list<int> camino;
	while(inicial != -1){
		camino.push_back(inicial);
		inicial = padre[inicial];
	}

	return camino;
}

int NodoMasLejanoBFS(vector< list<int> > &graph, int inicial){

	vector<bool> visitado(graph.size()-1, false);
	vector<int> distancia(graph.size()-1, -1);
	vector<int> padre(graph.size()-1, -1);


	visitado[inicial] = true;
	distancia[inicial] = 0;
	padre[inicial] = 0;

	int u = 0;

	queue<int> Cola;
	Cola.push(inicial);

	while(not Cola.empty()){
		u = Cola.front();
		Cola.pop();

		for(auto it = graph[u].begin(); it != graph[u].end(); it++){
			int v = *it;
			if( not visitado[v] ){
				visitado[v] = true;
				padre[v] = u;
				distancia[v] = distancia[u] + 1;
				Cola.push(v);
			} 
		}
	}
	return u;

}


