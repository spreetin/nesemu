#ifndef APU_H
#define APU_H

#include "../units.h"

class APU
{
public:
    APU();

    Byte getReg(Byte addr);
};

#endif // APU_H
