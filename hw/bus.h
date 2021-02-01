#ifndef BUS_H
#define BUS_H

#include "hw/units.h"
#include "hw/cpu.h"
#include "hw/ppu.h"
#include "hw/apu.h"
#include "cartridge/cartridge.h"
#include <array>

class Bus
{
public:
    Bus();
    ~Bus();

    Byte getMemory(Pointer addr);
    void setMemory(Pointer addr, Byte value);

private:
    std::array<Byte, 0x800> RAM;
    PPU *ppu = nullptr;
    APU *apu = nullptr;
    CPU *cpu = nullptr;
    Cartridge *cartridge = nullptr;
};

#endif // BUS_H
