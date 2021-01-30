#ifndef PPU_H
#define PPU_H

#include "hw/units.h"

class PPU
{
public:
    PPU();

    Byte getReg(Byte addr);
};

#endif // PPU_H
