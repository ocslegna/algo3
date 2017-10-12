#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <cassert>
#include <cstdlib>      // atoi

using namespace std;

typedef struct ProblemInstance {
    int n_works;
    vector< vector<unsigned int> > cost_matrix;
    ProblemInstance(int n_works) : n_works(n_works), cost_matrix(n_works + 1) {}
} ProblemInstance;

typedef struct SolutionInstance {
    int cost;
    vector<unsigned int> M1;
    vector<unsigned int> M2;
    string format_solution() {
        string res = "" + to_string(this->cost) + " " + to_string(this->M1.size()) + " ";
        for(int i = 0; i < this->M1.size(); i++) {
            res += to_string(this->M1[i]) + " ";
        }
        return res;
    }
} SolutionInstance;

void parse(vector<ProblemInstance>& problems) {
    int n_works;
    cin >> n_works;
    while(n_works != 0) {
        ProblemInstance pi(n_works);
        for(unsigned int i = 1; i < pi.cost_matrix.size(); i++) {
            vector<unsigned int> j_vector;
            unsigned int cost;
            for(unsigned j = 0; j < i; j++) {
                cin >> cost;
                j_vector.push_back(cost);
            }
            pi.cost_matrix[i] = j_vector;
        }
        problems.push_back(pi);
        cin >> n_works;   
    }
}

void init_matrix(vector< vector<unsigned int> >& m, unsigned int v){
    for(unsigned int i = 0; i < m.size(); i++){
        for(unsigned int j = 0; j < m[i].size(); j++){
            m[i][j] = v;
        }
    }
}

void print_matrix(vector< vector<unsigned int> >& m) {
    for(unsigned int i = 1; i < m.size(); i++){
        for(unsigned int j = 0; j < m[i].size(); j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

unsigned int min(unsigned int a, unsigned int b){
    return (a < b) ? a : b;
}

void build_solution(vector< vector<unsigned int> >& cost, vector< vector<unsigned int> >& opt, 
    unsigned int n_works, vector<unsigned int>& M1, vector<unsigned int>& M2) {

    int last = 0;
    M1.push_back(0); M2.push_back(0);

    // 1 work always goes first
    M1.push_back(1); 

    // works 2 to n-1
    for(int i = 2; i < n_works; i++) {
        unsigned int c1 = cost[i][M1.back()];
        unsigned int c2 = cost[i][M2.back()];
        if(opt[i][last] - c1 == opt[i + 1][M2.back()]) {
            M1.push_back(i); last = M2.back();
        } else if(opt[i][last] - c2 == opt[i + 1][M1.back()]) {
            M2.push_back(i); last = M1.back();
        } else {
            assert(false);
        }
    }

    // nth work
    unsigned int c1 = cost[n_works][M1.back()];
    unsigned int c2 = cost[n_works][M2.back()];
    if(opt[n_works][last] - c1 == 0) {
        M1.push_back(n_works); last = M2.back();
    } else if(opt[n_works][last] - c2 == 0) {
        M2.push_back(n_works); last = M1.back();
    } else {
        assert(false);
    }

    M1.erase(M1.begin()); // erase 0
    M2.erase(M2.begin()); // erase 0
}

SolutionInstance dp_bottom_up(ProblemInstance& pi) {
    SolutionInstance sol;
    vector< vector<unsigned int> > opt = pi.cost_matrix;
    init_matrix(opt, 0);

    for(int i = 0; i < opt[pi.n_works].size(); i++) {
        opt[pi.n_works][i] = min(pi.cost_matrix[pi.n_works][i], pi.cost_matrix[pi.n_works][pi.n_works - 1]);
    }

    for(int i = pi.n_works - 1; i > 0; i--) {
        for(int j = 0; j < opt[i].size(); j++) {
            opt[i][j] = min(pi.cost_matrix[i][j] + opt[i + 1][i - 1], pi.cost_matrix[i][i - 1] + opt[i + 1][j]);
        }
    }

    sol.cost = opt[1][0];
    build_solution(pi.cost_matrix, opt, pi.n_works, sol.M1, sol.M2);

    return sol;
}

unsigned int dp_memo_recur(ProblemInstance& pi, vector< vector<unsigned int> >& dict, unsigned int k, unsigned int i) {
    if(dict[k][i] == 0) {
        if(k == pi.n_works) {
            dict[k][i] = min(pi.cost_matrix[k][i], pi.cost_matrix[k][k - 1]);
        } else {
            dict[k][i] = min(pi.cost_matrix[k][i] + dp_memo_recur(pi, dict, k + 1, k - 1), pi.cost_matrix[k][k - 1] + dp_memo_recur(pi, dict, k + 1, i));
        }
    }
    return dict[k][i];
}

SolutionInstance dp_memo(ProblemInstance& pi) {
    SolutionInstance sol;
    vector< vector<unsigned int> > dict = pi.cost_matrix;
    init_matrix(dict, 0); // los costos son todos positivos, podemos usar 0 como no inicializado

    sol.cost = dp_memo_recur(pi, dict, 1, 0);
    build_solution(pi.cost_matrix, dict, pi.n_works, sol.M1, sol.M2);

    return sol;
}

// $ ./ej1 [repetitions]
// Exp Mode:
//      stdout -> csv results
//      stderr -> shows advance
// Normal Mode:
//      stdout -> result
int main(int argc, char **argv) {
    vector<ProblemInstance> ps;
    parse(ps);
    SolutionInstance sol;

    if(argc > 1) {
        // Experiments
        unsigned int rep;
        // cout << "n_works,instance,repetition,algorithm,ticks,time,cost,res_length" << endl;
        rep = atoi(argv[1]);
        for(int i = 0; i < ps.size(); i++) {
            for(int r = 1; r <= rep; r++) {
                clock_t ck;
                double ticks;

                cerr << "N: " << ps[i].n_works << " -- Inst: " << i+1 << '/' << ps.size() << " -- " << "Rep: " << r << "/" << rep;

                ck = clock();
                sol = dp_bottom_up(ps[i]);
                ticks = (double)(clock() - ck);
                cout << ps[i].n_works << "," << i+1 << "," << r << "," << "bottom,";
                cout << ticks << "," << (ticks)/(CLOCKS_PER_SEC/1000) << "," << sol.cost << "," << sol.M1.size() << endl;

                cerr << " -- Bottom ";

                ck = clock();
                sol = dp_memo(ps[i]);
                ticks = (double)(clock() - ck);
                cout << ps[i].n_works << "," << i+1 << "," << r << "," << "memo,";
                cout << ticks << "," << (ticks)/(CLOCKS_PER_SEC/1000) << "," << sol.cost << "," << sol.M1.size() << endl;

                cerr << "Memo" << endl;
            }
        }
    } else {
        // Normal mode
        for(int i = 0; i < ps.size(); i++) {
            sol = dp_bottom_up(ps[i]);
            cout << sol.format_solution() << endl;
        }
    }

}