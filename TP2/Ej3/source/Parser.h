#ifndef EJ3_PARSER_H
#define EJ3_PARSER_H

#include <iostream>
#include <vector>
#include <list>
#include "../defines.h"


namespace Ej3 {
    class Parser {
    public:
        vector<EJ3Problem> parse(std::istream &stream);
        EJ3Problem parse_instance(unsigned int factories, std::istream &stream);
    };
}


#endif //EJ3_PARSER_H
