#include "cartridge.h"

Cartridge::Cartridge(iNES_Header header, std::vector<Byte> PRG_ROM, std::vector<Byte> CHR_ROM)
    : header(header), PRG_ROM(PRG_ROM), CHR_ROM(CHR_ROM)
{
    PRG_RAM.resize(2*1024);
    if (header.Flags6.b1){
        mirr = Vertical;
    } else {
        mirr = Horizontal;
    }
}

Byte Cartridge::readPPU(Pointer addr)
{
    if (addr <= 0x1FFF){
        return CHR_ROM[addr];
    } else if (addr <= 0x2FFF){
        if (mirr == Vertical){
            if (addr >= 2800){
                return PRG_RAM[addr-0x2800];
            }
            return PRG_RAM[addr-0x2000];
        } else {
            if (addr <= 0x2C00 || (addr >= 2400 && addr < 2800)){
                return PRG_RAM[addr-0x2400];
            }
            return PRG_RAM[addr-0x2000];
        }
    } else if (addr <= 0x3EFF){
        return readPPU(addr-0x1000);
    }
    return 0x0;
}

