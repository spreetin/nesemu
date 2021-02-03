#ifndef BUS_H
#define BUS_H

class PPU;
class APU;
class CPU;
class Cartridge;
class Screen;

#include "units.h"
#include <array>
#include <chrono>

class Bus
{
public:
    Bus();
    ~Bus();

    void run();
    void cycle();

    Byte getCPUMemory(Pointer addr);
    void setCPUMemory(Pointer addr, Byte value);

    Byte getPPUMemory(Pointer addr);
    void setPPUMemory(Pointer addr, Byte value);

private:
    std::array<Byte, 0x800> RAM;
    std::array<Byte, 0x1000> VRAM;
    std::array<Byte, 0x100> Palette;

    PPU *ppu = nullptr;
    APU *apu = nullptr;
    CPU *cpu = nullptr;
    Cartridge *cartridge = nullptr;
    Screen *screen = nullptr;
    bool quit = false;
    std::chrono::high_resolution_clock::duration elapsedTime;
    std::chrono::nanoseconds cpuCycleTime = std::chrono::nanoseconds(559);
    std::chrono::high_resolution_clock::time_point cycleTimer;

};

#endif // BUS_H
