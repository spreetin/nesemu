#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <vector>
#include "units.h"

union iNES_Header {
    char full[16];
    struct {
    char name[4];
    Byte PRGROM_Size;
    Byte CHRROM_Size;
    Bitfield Flags6;
    Bitfield Flags7;
    Bitfield Flags8;
    Bitfield Flags9;
    Bitfield Flags10;
    Bitfield Flags11;
    Bitfield Flags12;
    Bitfield Flags13;
    Bitfield Flags14;
    Bitfield Flags15;
    };
};

enum TimingMode {
    NTSC = 0,
    PAL = 1,
    Multi = 2,
    Dendy = 3
};

enum Mirroring {
    Vertical,
    Horizontal
};

class Cartridge
{
public:
    Cartridge(iNES_Header header, std::vector<Byte> PRG_ROM, std::vector<Byte> CHR_ROM);

    void setTrainerData(std::vector<Byte> data) {
        trainingData = data;
    }
    void setPRGRAM(Word PRGRAM, Word PRGNVRAM){
        PRG_RAM.resize(PRGRAM);
        PRG_NVRAM.resize(PRGNVRAM);
    }
    void setCHRRAM(Word CHRRAM, Word CHRNVRAM){
        CHR_RAM.resize(CHRRAM);
        CHR_NVRAM.resize(CHRNVRAM);
    }

    virtual Byte readCPU(Pointer addr) = 0;
    virtual void writeCPU(Pointer addr, Byte data) = 0;

    virtual Byte readPPU(Pointer addr);
    virtual void writePPU(Pointer addr, Byte data) = 0;

protected:
    iNES_Header header;
    std::vector<Byte> PRG_ROM;
    std::vector<Byte> CHR_ROM;
    std::vector<Byte> PRG_RAM;
    std::vector<Byte> PRG_NVRAM;
    std::vector<Byte> CHR_RAM;
    std::vector<Byte> CHR_NVRAM;
    std::vector<Byte> trainingData;

    Mirroring mirr;
};

#endif // CARTRIDGE_H
