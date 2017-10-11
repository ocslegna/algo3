#include "Ej2.h"

vector<int> Prim(MatrizAdyacencias &M){
	unsigned long n = M.size();

	vector<int> distancia(n, INT_MAX);
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
	padre[v] = 0;
	visitado[v] = true;

	unsigned int cant_visitados = 1;
	int min;
	while (cant_visitados < n){

		for(unsigned int i = 2; i < n; i++){
			if(not visitado[i]){
				min = i;
				break;
			}
		}
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
		if(cant_visitados < n-1){
			for(unsigned int w = 1; w < n; w++){
				if(not visitado[w]){
					if( M[min][w] > 0 ){
						if( distancia[w] > M[min][w] ){
							distancia[w] = M[min][w];
							padre[w] = min;
						}
					}
				}
			}
		}
	}
	return padre;
}


vector<int> Prim_Cola_Prioridad(vector< list<ElemDist> > &L){
	unsigned long n = L.size();

	vector<int> distancia(n, INT_MAX);
	vector<int> padre(n, -1);
	vector<bool> visitado(n, false);


	int v = 1;
	distancia[v] = 0;
	padre[v] = 0;

	priority_queue< ElemDist > cola;
	ElemDist e(v, distancia[v]);
	cola.push(e);

	ElemDist u;
	while (not cola.empty()){

		u = cola.top();
		cola.pop();
		if (visitado[u.elem]) continue;

		visitado[u.elem] = true;

		for(auto it = L[u.elem].begin(); it != L[u.elem].end(); it++){
			int v = (*it).elem;
			int peso_uv = (*it).dist;
			if (not visitado[v] and distancia[v] > peso_uv){
				distancia[v] = peso_uv;
				padre[v] = u.elem;
				cola.push(ElemDist(v,distancia[v]));
			}
		}

	}
	return padre;
}

// Devuelve el costo total
int ConstruirSolucion(MatrizAdyacencias &M, vector<int> &padre, vector<Arista> &aristas, int raiz){

	auto n = static_cast<int>(padre.size());
	
	int costo = 0;
	
	int w;
	// Arranco desde 2 porque Prim arranca siempre desde 1 (no tiene padre).
	for(int i = 2; i < n; i++){
		w = padre[i];
		Arista e = make_pair(w, i);
		aristas.push_back(e);
		costo += M[w][i];
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

	vector<bool> visitado(graph.size(), false);
	vector<int> distancia(graph.size(), -1);
	vector<int> padre(graph.size(), -1);


	visitado[inicial] = true;
	distancia[inicial] = 0;
	padre[inicial] = 0;

	int u;

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


vector< list<ElemDist> > Matriz_A_Lista(MatrizAdyacencias &M){
	int n = M.size();
	vector< list<ElemDist> > L(n);
	for(unsigned int i = 1; i < M.size(); i++){
		for(unsigned int j = 1; j < M.size(); j++){
			if (M[i][j] > 0){
				ElemDist e(j, M[i][j]);
				L[i].push_back(e);
			}
		}
	}
	return L;
}


void ImprimirSolucion(int costoTotal, int master, vector<Arista> &aristas){
	cout << costoTotal << " " << master << " " << aristas.size() << " ";
	for(unsigned int i = 0; i < aristas.size(); i++){
		cout << aristas[i].first << " " << aristas[i].second << " ";
		
	}
	cout << endl; 
}

MatrizAdyacencias GenerarMatriz(int n, int m){
	MatrizAdyacencias M(n+1, vector<int>(n+1, 0));
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		cin >> M[a][b];
		M[b][a] = M[a][b];
	}
	return M;
}

ListaIncidencias ConstruirListaIncidencias(int n, vector<Arista> &aristas){
	ListaIncidencias incidentList(n+1);
	for(auto it = aristas.begin(); it != aristas.end(); it++){
		incidentList[it->first].push_back(it->second);
  		incidentList[it->second].push_back(it->first);
	}
	return incidentList;
}

int CalcularRaiz(list<int> &camino){
	int medio = camino.size() / 2;
	auto it = camino.begin();
	for(int i = 0; i < medio; i++) it++;
	int master = *it;

	return master;
}