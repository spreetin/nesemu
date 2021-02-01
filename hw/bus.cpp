#include "bus.h"

Bus::Bus()
{
    cpu = new CPU(this);
    ppu = new PPU();
    apu = new APU();
}

Bus::~Bus()
{
    delete ppu;
    delete apu;
    delete cpu;
}

Byte Bus::getMemory(Pointer addr)
{
    if (addr < 0x2000){
        return RAM.at(addr & 0x07ff);
    } else if (addr < 0x4000){ // PPU registers
        return ppu->getReg(addr & 0x0007);
    } else if (addr < 0x4018){ // APU & IO registers
        return apu->getReg(addr & 0x00FF);
    } else if (addr < 0x4020){
        return 0x00FF;
    } else { // Cartridge
        return  cartridge->getMemory(addr);
    }
}

void Bus::setMemory(Pointer addr, Byte value)
{
    if (addr < 0x2000){
        RAM.at(addr & 0x07ff) = value;
    }
}
