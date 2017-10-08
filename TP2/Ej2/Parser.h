#ifndef EJ2_PARSER_H
#define EJ2_PARSER_H

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

#endif //EJ2_PARSER_H
