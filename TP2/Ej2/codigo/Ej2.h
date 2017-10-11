#ifndef ALGO3_EJ2_H
#define ALGO3_EJ2_H

#include <vector>
#include <cstdio>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <climits>
#include <queue>

using namespace std;

typedef pair<int,int> Arista;

//typedef pair<int,int> ElemDist;

struct ElemDist{
	int elem;
	int dist;

	ElemDist(){
		elem = 0;
		dist = 0;
	}
	ElemDist(int e, int d): elem(e), dist(d) {};
	bool operator<(const ElemDist& e) const {
        if (dist < e.dist) {
           return false;
        }
        else {
            return true;
        }

    }
};

typedef vector <vector <int> > MatrizAdyacencias;

typedef vector< list<int> > ListaIncidencias;

vector<int> Prim(MatrizAdyacencias &M);

vector<int> Prim_Cola_Prioridad(vector< list<ElemDist> > &L);

vector< list<ElemDist> > Matriz_A_Lista(MatrizAdyacencias &M);

int ConstruirSolucion(MatrizAdyacencias &M, vector<int> &padre, vector<Arista> &aristas, int raiz);

list<int> CaminoEntreDFS(vector< list<int> > &graph, int u, int v);

int NodoMasLejanoBFS(vector< list<int> > &graph, int inicial);

void ImprimirSolucion(int costoTotal, int aster, vector<Arista> &aristas);

MatrizAdyacencias GenerarMatriz(int n, int m);

ListaIncidencias ConstruirListaIncidencias(int n, vector<Arista> &arista);

int CalcularRaiz(list<int> &camino);

#endif //ALGO3_EJ2_H
