#include <SDL2/SDL.h>
#include "bus.h"
#include "hw/cpu.h"
#include "hw/ppu.h"
#include "hw/apu.h"
#include "cartridge/cartridge.h"
#include "cartridge/cartridgeloader.h"
#include "engine/graphics/screen.h"
#include <ctime>

Bus::Bus()
{
    cpu = new CPU(this);
    ppu = new PPU(this);
    apu = new APU();
    screen = new Screen();
    CartridgeLoader loader;
    cartridge = loader.loadFile("/home/david/nestest.nes");
}

Bus::~Bus()
{
    delete ppu;
    delete apu;
    delete cpu;
    delete screen;
}

void Bus::run()
{
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_GAMECONTROLLER|SDL_INIT_EVENTS);
    screen->show();
    SDL_Event event;
    cycleTimer = std::chrono::high_resolution_clock::now();
    cycle();
    struct timespec w = {0, 200};
    while (!(event.type == SDL_QUIT)){
        elapsedTime += std::chrono::high_resolution_clock::now() - cycleTimer;
        cycleTimer = std::chrono::high_resolution_clock::now();
        if (elapsedTime > cpuCycleTime){
            cycle();
            elapsedTime -= cpuCycleTime;
        } else {
            nanosleep(&w, (struct timespec *)nullptr);
        }
        SDL_PollEvent(&event);
    }
    SDL_Quit();
}

void Bus::cycle()
{
    ppu->cycle();
    ppu->cycle();
    ppu->cycle();
    cpu->cycle();
}

Byte Bus::getCPUMemory(Pointer addr)
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
        return  cartridge->readCPU(addr);
    }
}

void Bus::setCPUMemory(Pointer addr, Byte value)
{
    if (addr < 0x2000){
        RAM.at(addr & 0x07ff) = value;
    }
}

Byte Bus::getPPUMemory(Pointer addr)
{
    if (addr <= 0x1FFF){
        return cartridge->readPPU(addr);
    } else if (addr <= 0x2FFF){
        return VRAM[addr & 0x0FFF];
    } else if (addr <= 0x3EFF){
        return VRAM[addr & 0x0FFF];
    } else if (addr <= 0x3FFF){
        return Palette[addr & 0x001F];
    }
    return 0x0;
}

void Bus::setPPUMemory(Pointer addr, Byte value)
{
    cartridge->writePPU(addr, value);
}
