#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include "hw/units.h"

class Cartridge
{
public:
    Cartridge();

    virtual Byte getMemory(Pointer addr);
};

#endif // CARTRIDGE_H
