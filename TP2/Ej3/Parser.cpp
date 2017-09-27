#include "Parser.h"

using namespace Ej3;

vector<AdjacencyMatrix> Parser::parse(std::istream &stream) {
    int factories;
    vector<AdjacencyMatrix> problems;

    stream >> factories;

    while (factories != 0) {
        problems.push_back(parse_instance(factories, stream));
        stream >> factories;
    }

    return problems;
}

AdjacencyMatrix Parser::parse_instance(int factories, std::istream &stream) {
    int clients, routes;
    stream >> clients >> routes;

    AdjacencyMatrix problem(factories + clients, vector<int>(factories + clients, 0));


    for (int i = 0; i < routes; i++) {
        int origin, target, weight;

        stream >> origin >> target >> weight;

        problem[origin - 1][target - 1] = weight;
        problem[target - 1][origin - 1] = weight;
    }

    return problem;
}