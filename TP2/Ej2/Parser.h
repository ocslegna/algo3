#ifndef ALGO3_PARSER_H
#define ALGO3_PARSER_H

#include <iostream>
#include <vector>
#include <list>
#include "../defines.h"


namespace Ej2 {
    class Parser {
    public:
        vector<EJ2Problem> parse(std::istream &stream);
        EJ2Problem parse_instance(unsigned int servidores, unsigned int enlaces, std::istream &stream);
    };
}

#endif //ALGO3_PARSER_H
