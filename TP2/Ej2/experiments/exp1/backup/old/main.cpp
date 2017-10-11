#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Ej2.h"
#include "tiempo.h"

#define EXP
using namespace std;


int main(int argc, char **argv) {

	int n, m;

	cin >> n >> m;

	while ( n != 0 and m != 0){

		MatrizAdyacencias M(n+1, vector<int>(n+1, 0));
		
		int a, b;
		for(int i = 0; i < m; i++){
			cin >> a >> b;
			cin >> M[a][b];
			M[b][a] = M[a][b];

		}

		unsigned long long start, end, time_span;
        MEDIR_TIEMPO_START(start)

		// 2.1
		vector<int> padres = Prim(M);
		vector<Arista> aristas;
		// 'costoTotal' = costo mínimo utilizando los enlaces en 'aristas'
		int costoTotal = ConstruirSolucion(M, padres, aristas, 1); (void) costoTotal;
		

		// Construyendo lista de incidencias para aplicar BFS y DFS.
		vector< list<int> > incidentList(n+1);
		for(auto it = aristas.begin(); it != aristas.end(); it++){
			incidentList[it->first].push_back(it->second);
  			incidentList[it->second].push_back(it->first);
		}
		
		// 2.2
		int u =	NodoMasLejanoBFS(incidentList, 1); 
		int v = NodoMasLejanoBFS(incidentList, u);
		list<int> camino = CaminoEntreDFS(incidentList, u,v);

		// Calculo el medio de la raíz más larga para el master.
		int medio = camino.size() / 2;
		auto it = camino.begin();
		for(int i = 0; i < medio; i++) it++;
		int master = *it; (void) master;
		
		MEDIR_TIEMPO_STOP(end)
        time_span = end - start; (void) time_span;

		#ifdef EXP
            cout << time_span;
        #else
			//Imprimo solución.
			cout << costoTotal << " " << master << " " << aristas.size() << " ";
			for(unsigned int i = 0; i < aristas.size(); i++){
				cout << aristas[i].first << " " << aristas[i].second << " ";
				
			}
			cout << endl; 
        #endif

		cin >> n >> m;

	}


}