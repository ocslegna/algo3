#ifndef EJ1_PARSER_H
#define EJ1_PARSER_H

#include <iostream>
#include <vector>
#include <list>
#include "../defines.h"


namespace Ej1 {
    class Parser {
    public:
        vector<EJ1Problem> parse(std::istream &stream);
        EJ1Problem parse_instance(unsigned int factories, std::istream &stream);
    };
}


#endif //EJ1_PARSER_H
