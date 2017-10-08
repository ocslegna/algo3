#include "Parser.h"

using namespace Ej2;


vector<EJ2Problem> Parser::parse(std::istream &stream) {
    unsigned servidores, enlaces;
    vector<EJ2Problem> problems;

    stream >> servidores >> enlaces;

    while (servidores != 0 and enlaces != 0) {
        problems.push_back(parse_instance(servidores, enlaces, stream));
        stream >> servidores >> enlaces;
    }

    return problems;
}


EJ2Problem Parser::parse_instance(unsigned int servidores, unsigned int enlaces, std::istream &stream) {
    vector<vector<int>> adj_matrix(servidores+1, vector<int>(servidores+1, 0));

    unsigned int first_server, second_server;
    for (unsigned int i = 0; i < enlaces; i++) {
        stream >> first_server >> second_server;
        stream >> adj_matrix[first_server][second_server];
        adj_matrix[second_server][first_server] = adj_matrix[first_server][second_server];
    }

    EJ2Problem problem;
    problem.adj_matrix = adj_matrix;
    problem.servidores= servidores;
    problem.enlaces= enlaces;
    return problem;
}