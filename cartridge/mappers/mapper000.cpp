#include "mapper000.h"


Byte Mapper000::readCPU(Pointer addr)
{
    if (addr < 0x8000){
        return 0x00;
    } else if (addr > 0xBFFF && header.PRGROM_Size == 1){
        return PRG_ROM[addr-0xC000];
    } else {
        return PRG_ROM[addr-0x8000];
    }
}

void Mapper000::writeCPU(Pointer addr, Byte data)
{
    return;
}

Byte Mapper000::readPPU(Pointer addr)
{
    return Cartridge::readPPU(addr);
}

void Mapper000::writePPU(Pointer addr, Byte data)
{
    return;
}
