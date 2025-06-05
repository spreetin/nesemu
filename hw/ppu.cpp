#include "ppu.h"
#include "bus.h"

PPU::PPU(Bus *bus)
    : bus(bus)
{
    PPUCTRL.byte = 0;
    PPUMASK.byte = 0;
    PPUSTATUS.byte = 0xA0;
    OAMADDR = 0;
    PPUSCROLL = 0;
    PPUADDR = 0;
    PPUDATA = 0;
}

void PPU::clockCycle()
{
        
}

void PPU::reset()
{
    PPUCTRL.byte = 0;
    PPUMASK.byte = 0;
    PPUSCROLL = 0;
    PPUDATA = 0;
    oddFrame = false;
}

Byte PPU::getReg(Pointer addr)
{
    switch (addr){
    case 0x2002:
    {
        Byte data = (PPUSTATUS.byte & 0xE0) | (buffer & 0x1F);
        PPUSTATUS.VerticalBlank = 0;
        // Reset address latch flag;
        return data;
    }
    case 0x2003: return OAMADDR;
    case 0x2004: return OAMDATA;
    case 0x2007: return PPUDATA;
    {
        Byte data = buffer;
        buffer = getMem(VRAM_Addr.byte);
        if (VRAM_Addr.byte >= 0x3F00){
            data = buffer;
        }
        VRAM_Addr.byte += PPUCTRL.IncrementMode ? 32 : 1;
        return data;
    }
    case 0x4014: return OAMDMA;
    }
    return 0x0;
}

void PPU::writeReg(Pointer addr, Byte data)
{
    switch (addr){
    case 0x2000:
        PPUCTRL.byte = data;
        TRAM_Addr.NametableX = PPUCTRL.NametableX;
        TRAM_Addr.NametableY = PPUCTRL.NametableY;
        break;
    case 0x2001: PPUMASK.byte = data; break;
    case 0x2005:{
        // Need work
        PPUSCROLL = data;
        break;
    }
    case 0x2006: PPUADDR = data; break; // Need work
    case 0x2007:
        writeMem(VRAM_Addr.byte, data);
        VRAM_Addr.byte += (PPUCTRL.IncrementMode ? 32 : 1);
    }
}

Byte PPU::getMem(Pointer addr)
{
    return bus->getPPUMemory(addr);
}

void PPU::writeMem(Pointer addr, Byte data)
{
    bus->setPPUMemory(addr, data);
}
