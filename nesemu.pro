TEMPLATE = app
CONFIG += console c++11 link_pkgconfig
CONFIG -= app_bundle
CONFIG -= qt
PKGCONFIG += sdl2

SOURCES += \
        cartridge/cartridge.cpp \
        cartridge/cartridgeloader.cpp \
        cartridge/mappers/mapper000.cpp \
        engine/graphics/screen.cpp \
        engine/sound/sound.cpp \
        hw/apu.cpp \
        hw/bus.cpp \
        hw/cpu.cpp \
        hw/ppu.cpp \
        main.cpp

HEADERS += \
    cartridge/cartridge.h \
    cartridge/cartridgeloader.h \
    cartridge/mappers/mapper000.h \
    cartridge/mappers/mapper_selecter.h \
    engine/graphics/screen.h \
    engine/sound/sound.h \
    hw/apu.h \
    hw/bus.h \
    hw/cpu.h \
    hw/ppu.h \
    units.h
