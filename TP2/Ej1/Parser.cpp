#include "Parser.h"

using namespace Ej3;


vector<EJ3Problem> Parser::parse(std::istream &stream) {
    unsigned factories;
    vector<EJ3Problem> problems;

    stream >> factories;

    while (factories != 0) {
        problems.push_back(parse_instance(factories, stream));
        stream >> factories;
    }

    return problems;
}


EJ3Problem Parser::parse_instance(unsigned factories, std::istream &stream) {
    unsigned int clients, routes;
    stream >> clients >> routes;

    AdjacencyMatrix adjM(factories + clients, vector<int>(factories + clients, -1));


    for (int i = 0; i < routes; i++) {
        int origin, target, weight;

        stream >> origin >> target >> weight;

        adjM[origin - 1][target - 1] = weight;
        adjM[target - 1][origin - 1] = weight;
    }

    EJ3Problem problem;
    problem.adjacency_matrix = adjM;
    problem.clients = clients;
    problem.factories = factories;
    return problem;
}