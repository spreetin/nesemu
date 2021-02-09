#include "cartridgeloader.h"
#include "mappers/mapper_selecter.h"
#include <fstream>
#include <array>

CartridgeLoader::CartridgeLoader()
{

}

Cartridge *CartridgeLoader::loadFile(std::string filename)
{
    iNES_Header header;
    std::vector<Byte> prgROM;
    std::vector<Byte> chrROM;
    bool ines2 = true;
    std::ifstream file(filename, std::ios::binary);
    file.read(reinterpret_cast<char*>(header.full), 16);
    //file >> header.full;
    if (!(header.Flags7.b3 && !header.Flags7.b2)){
        ines2 = false;
    }
    std::vector<Byte> trainer;
    if (header.Flags6.b2){
        trainer.resize(512);
        file.read(reinterpret_cast<char*>(trainer.data()), 512);
    }
    Word prglen;
    if (ines2){
        if ((header.Flags9.byte & 0x0F) == 0xF){
            prglen = (1 << ((header.PRGROM_Size & 0xF0) >> 4)) * (((header.PRGROM_Size & 0x0F) * 2) + 1);
        } else {
            prglen = header.PRGROM_Size + ((Word)(header.Flags9.byte & 0x0F) << 8);
        }
    } else {
        prglen = header.PRGROM_Size;
    }
    prgROM.resize(prglen*(long long)(16*1024));
    file.read(reinterpret_cast<char*>(prgROM.data()), prglen*(long long)(16*1024));
    Word chrlen;
    if (ines2){
        if ((header.Flags9.byte & 0xF0) == 0xF0){
            chrlen = (1 << ((header.CHRROM_Size & 0xF0) >> 4)) * (((header.CHRROM_Size & 0x0F) * 2) + 1);
        } else {
            chrlen = header.CHRROM_Size + ((Word)(header.Flags9.byte & 0xF0) << 4);
        }
    } else {
        chrlen = header.CHRROM_Size;
    }
    chrROM.resize(chrlen*(long long)(16*1024));
    file.read(reinterpret_cast<char*>(chrROM.data()), chrlen*(long long)(16*1024));
    Word mapperID = ((header.Flags6.byte & 0xF0) >> 4) | (header.Flags7.byte & 0xF0);
    if (ines2){
        mapperID |= ((header.Flags8.byte & 0x0F) << 8);
    }
    Byte submapper = (header.Flags8.byte & 0xF0) >> 4;
    Word prgRAMsize = 0;
    Word prgNVRAMsize = 0;
    if (ines2){
        if (header.Flags10.byte & 0x0F){
            prgRAMsize = 64 << (header.Flags10.byte & 0x0F);
        }
        if (header.Flags10.byte & 0xF0){
            prgNVRAMsize = 64 << ((header.Flags10.byte & 0xF0) >> 4);
        }
    } else {
        if (header.Flags10.b4){
            prgRAMsize = header.Flags8.byte * (8*1024);
        } else {
            prgRAMsize = 0;
        }
    }
    Word chrRAMsize = 0;
    Word chrNVRAMsize = 0;
    if (header.Flags11.byte & 0x0F){
        chrRAMsize = 64 << (header.Flags11.byte & 0x0F);
    }
    if (header.Flags11.byte & 0xF0){
        chrNVRAMsize = 64 << ((header.Flags11.byte & 0xF0) >> 4);
    }
    TimingMode mode;
    switch (header.Flags12.byte & 0x03){
    case 0:
        mode = NTSC; break;
    case 1:
        mode = PAL; break;
    case 2:
        mode = Multi; break;
    default:
        mode = Dendy; break;
    }
    Cartridge *cart = getCorrectMapper(mapperID, header, prgROM, chrROM);
    cart->setPRGRAM(prgRAMsize, prgNVRAMsize);
    if (ines2){
        cart->setCHRRAM(chrRAMsize, chrNVRAMsize);
    }
    return cart;
}
