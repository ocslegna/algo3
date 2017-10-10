#ifndef ALGO3_EXPERIMENTATION_H
#define ALGO3_EXPERIMENTATION_H

#include "HeavyTransportation.h"

namespace Ej3 {
    class Experimentation {
    public:
        void run();
        double measureHT(HeavyTransportation ht);
        void first_experiment();
    };
}

#endif //ALGO3_EXPERIMENTATION_H
