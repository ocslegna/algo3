#ifndef ALGO3_PARSER_H
#define ALGO3_PARSER_H

#include <iostream>
#include <vector>
#include <list>
#include "../defines.h"


namespace Ej3 {
    class Parser {
    public:
        vector<AdjacencyMatrix> parse(std::istream &stream);
        AdjacencyMatrix parse_instance(unsigned int factories, std::istream &stream);
    };
}


#endif //ALGO3_PARSER_H
