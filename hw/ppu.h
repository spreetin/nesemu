#ifndef PPU_H
#define PPU_H

class Bus;

#include "../units.h"
#include <array>

class PPU
{
public:
    explicit PPU(Bus *bus);

    void clockCycle();

    void reset();

    Byte getReg(Pointer addr);
    void writeReg(Pointer addr, Byte data);

    Byte getMem(Pointer addr);
    void writeMem(Pointer addr, Byte data);

private:
    Bus *bus;

    union {
        Byte byte;
        struct {
            Byte NametableX : 1;
            Byte NametableY : 1;
            Byte IncrementMode : 1;
            Byte PatternSprite : 1;
            Byte PatternBackground : 1;
            Byte SpriteSize : 1;
            Byte SlaveMode : 1;
            Byte EnableNMI : 1;
        };
    } PPUCTRL;
    union {
        Byte byte;
        struct {
            Byte Grayscale : 1;
            Byte RenderBackgroundLeft : 1;
            Byte RenderSPritesLeft : 1;
            Byte RenderBackground : 1;
            Byte RenderSprites : 1;
            Byte EnhanceRed : 1;
            Byte EnhanceGreen : 1;
            Byte EnhanceBlue : 1;
        };
    } PPUMASK;
    union {
        Byte byte;
        struct {
            Byte na : 5;
            Byte SpriteOverflow : 1;
            Byte SpriteZeroHit : 1;
            Byte VerticalBlank : 1;
        };
    } PPUSTATUS;
    Byte OAMADDR;
    Byte OAMDATA;
    Byte PPUSCROLL;
    Byte PPUADDR;
    Byte PPUDATA;
    Byte OAMDMA;

    Byte buffer;

    union LoppyReg {
        Word byte = 0x0000;
        struct {
            Word CoarseX : 5;
            Word CoarseY : 5;
            Word NametableX : 1;
            Word NametableY : 1;
            Word FineY : 3;
            Word na : 1;
        };
    };

    LoppyReg VRAM_Addr;
    LoppyReg TRAM_Addr;

    Word shift16_1;
    Word shift16_2;
    Byte shift8_1;
    Byte shift8_2;

    struct SpriteReg {
        Byte shift;
        Byte latch;
        Byte counter;
    };

    std::array<SpriteReg, 8> sprites;

    bool oddFrame = false;
    int16_t scanline = 0;
    int16_t cycle = 0;

    std::array<Byte, 256> OAM_MEM;
};

#endif // PPU_H
