cmake_minimum_required(VERSION 3.23)
project(nesemu)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories("/usr/include/SDL2")

add_executable(nesemu main.cpp units.h hw/apu.cpp hw/apu.h hw/bus.cpp hw/bus.h hw/cpu.cpp hw/cpu.h hw/ppu.cpp hw/ppu.h
        engine/graphics/screen.cpp engine/graphics/screen.h engine/sound/sound.cpp engine/sound/sound.h
        cartridge/cartridge.cpp cartridge/cartridge.h cartridge/cartridgeloader.cpp cartridge/cartridgeloader.h
        cartridge/mappers/mapper000.cpp cartridge/mappers/mapper000.h cartridge/mappers/mapper_selecter.h)

target_link_libraries(nesemu "/usr/lib/libSDL2.so" "/usr/lib/libSDL2_ttf.so")
