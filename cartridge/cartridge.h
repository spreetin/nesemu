#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <vector>
#include "units.h"

struct iNES_Header {
    char name[4];
    Byte PRGROM_Size;
    Byte CHRROM_Size;
    Bitfield Flags6;
    Bitfield Flags7;
    Bitfield Flags8;
    Bitfield Flags9;
    Bitfield Flags10;
};

class Cartridge
{
public:
    Cartridge(iNES_Header header, std::vector<Byte> PRG_ROM, std::vector<Byte> CHR_ROM);

    virtual Byte readCPU(Pointer addr) = 0;
    virtual void writeCPU(Pointer addr, Byte data) = 0;

    virtual Byte readPPU(Pointer addr) = 0;
    virtual void writePPU(Pointer addr, Byte data) = 0;

protected:
    iNES_Header header;
    std::vector<Byte> PRG_ROM;
    std::vector<Byte> CHR_ROM;
    std::vector<Byte> PRG_RAM;
};

#endif // CARTRIDGE_H
