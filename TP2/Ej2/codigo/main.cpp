#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Ej2.h"
#include "tiempo.h"

//#define EXP
using namespace std;


int main(int argc, char **argv) {
	unsigned long long start, end, time_span;
	#ifdef EXP
		unsigned long long start_cp, end_cp, time_span_cp;
	#endif
	int n, m;

	cin >> n >> m;
	while ( n != 0 ){

		MatrizAdyacencias M = GenerarMatriz(n, m);
		
        start_time(start)
		// 2.1
		vector<int> padres = Prim(M);
		stop_time(end)
        time_span = end - start;
		
		// Calculo el costo mínimo y reconstruyo la solucion en 'aristas'
		vector<Arista> aristas;
		int costoTotal = ConstruirSolucion(M, padres, aristas, 1);
		
		// Construyendo lista de incidencias para aplicar BFS y DFS.
		ListaIncidencias incidentList = ConstruirListaIncidencias(n, aristas);

		// 2.2
		int u =	NodoMasLejanoBFS(incidentList, 1); 
		int v = NodoMasLejanoBFS(incidentList, u);
		list<int> camino = CaminoEntreDFS(incidentList, u,v);

		// Calculo el medio de la raíz más larga para el master.
		int master = CalcularRaiz(camino);
		
		// Imprimo solución.
		ImprimirSolucion(costoTotal, master, aristas);

	
		#ifdef EXP
			cout << time_span << endl;
			vector< list<ElemDist> > L = Matriz_A_Lista(M);
			start_time(start_cp);
			vector<int> padres_cp = Prim_Cola_Prioridad(L);
			stop_time(end_cp);
			time_span_cp = end_cp - start_cp;
			vector<Arista> aristas_cp;
			int costoTotal_cp = ConstruirSolucion(M, padres_cp, aristas_cp, 1);
			//ImprimirSolucion(costoTotal_cp, master, aristas_cp);
			cout << time_span_cp << endl;
		#endif



		cin >> n >> m;

	}
}
