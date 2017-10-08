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
    unsigned int clients, routesAmount;
    stream >> clients >> routesAmount;

    vector<Edge> routes;

    for (int i = 0; i < routesAmount; i++) {
        unsigned int origin, target, weight;

        stream >> origin >> target >> weight;

        Edge route{};
        route.origin = origin;
        route.target = target;
        route.weight = weight;

        routes.push_back(route);
    }

    EJ3Problem problem;
    problem.Edges = routes;
    problem.clients = clients;
    problem.factories = factories;
    return problem;
}