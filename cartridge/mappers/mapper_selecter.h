#ifndef MAPPER_SELECTER_H
#define MAPPER_SELECTER_H

#include "../cartridge.h"
#include "mapper000.h"

Cartridge * getCorrectMapper(int num, iNES_Header header, std::vector<Byte> PRG_ROM, std::vector<Byte> CHR_ROM){
    switch (num) {
    default: return new Mapper000(header, PRG_ROM, CHR_ROM);
    }
}

#endif // MAPPER_SELECTER_H
