#include "Parser.h"

using namespace Ej1;

vector<EJ1Problem> Parser::parse(std::istream &stream) {
    unsigned works;
    vector<EJ1Problem> problems;

    stream >> works;

    while (works != 0) {
        problems.push_back(parse_instance(works, stream));
        stream >> works;
    }

    return problems;
}

EJ1Problem Parser::parse_instance(unsigned works, std::istream &stream) {
    vector<vector<unsigned>> costMatrix(works);

    for (unsigned i = 0; i < works; i++) {
        vector<unsigned> j_vector;
        for (unsigned j = 0; j <= i; j++) {
            unsigned cost;
            stream >> cost;
            j_vector.push_back (cost);
        }
        costMatrix.push_back (j_vector);
    }

    EJ1Problem problem;
    problem.cost_matrix = costMatrix;
    problem.works = works;
    return problem;
}