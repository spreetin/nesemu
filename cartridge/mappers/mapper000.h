#ifndef MAPPER000_H
#define MAPPER000_H

#include <array>
#include "cartridge/cartridge.h"
#include "hw/units.h"

class mapper000 : public Cartridge
{
public:
    mapper000();

public:
    Byte getMemory(Pointer addr);

private:
    std::array<Byte, 16*1024> low;
    std::array<Byte, 16*1024> high;
    bool hasHigh;
};

#endif // MAPPER000_H
