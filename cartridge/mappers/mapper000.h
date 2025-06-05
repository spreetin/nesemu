#ifndef MAPPER000_H
#define MAPPER000_H

#include "../cartridge.h"

class Mapper000 : public Cartridge
{
public:
    Mapper000(iNES_Header header, std::vector<Byte> PRG_ROM, std::vector<Byte> CHR_ROM) : Cartridge(header, PRG_ROM, CHR_ROM) {}


    // Cartridge interface
public:
    Byte readCPU(Pointer addr);
    void writeCPU(Pointer addr, Byte data);
    Byte readPPU(Pointer addr);
    void writePPU(Pointer addr, Byte data);
};

#endif // MAPPER000_H
