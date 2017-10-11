#ifndef ALGO3_EJ2_H
#define ALGO3_EJ2_H

#include <vector>
#include <cstdio>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int,int> Arista;

typedef vector <vector <int> > MatrizAdyacencias;

vector<int> Prim(MatrizAdyacencias &M);

int ConstruirSolucion(MatrizAdyacencias &M, vector<int> &padre, vector<Arista> &aristas, int raiz);

list<int> CaminoEntreDFS(vector< list<int> > &graph, int u, int v);

int NodoMasLejanoBFS(vector< list<int> > &graph, int inicial);

#endif //ALGO3_EJ2_H
