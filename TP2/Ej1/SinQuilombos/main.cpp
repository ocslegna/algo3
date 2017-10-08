#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Ej1.h"


using namespace std;


int main(int argc, char **argv) {
	int N; 
	cin >> N;
	while (N != 0){
		vector<vector<unsigned>> costMatrix(N+1);
    	for (unsigned i = 1; i < costMatrix.size(); i++) {
    	    vector<unsigned> j_vector;
    	    unsigned int cost;
    	    for (unsigned j = 0; j < i; j++) {
    	        cin >> cost;
    	        j_vector.push_back(cost);
    	    }
    	    costMatrix[i] = j_vector;
    	}


    	for(unsigned int i = 1; i < costMatrix.size(); i++){
    		for(unsigned int j = 0; j < costMatrix[i].size(); j++){
    			cout << costMatrix[i][j] << " ";
    		}
    		cout << endl;
    	}



    	cin >> N;
		
	}

}