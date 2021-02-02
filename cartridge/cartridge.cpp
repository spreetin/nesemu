#include "cartridge.h"

Cartridge::Cartridge(iNES_Header header, std::vector<Byte> PRG_ROM, std::vector<Byte> CHR_ROM)
    : header(header), PRG_ROM(PRG_ROM), CHR_ROM(CHR_ROM)
{

}
