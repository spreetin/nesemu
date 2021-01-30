#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include "hw/units.h"

class Cartridge
{
public:
    Cartridge();

    Byte getMemory(Pointer addr);
};

#endif // CARTRIDGE_H
