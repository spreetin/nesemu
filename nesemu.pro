TEMPLATE = app
CONFIG += console c++11 link_pkgconfig
CONFIG -= app_bundle
CONFIG -= qt
PKGCONFIG += sdl2

SOURCES += \
        cartridge/cartridge.cpp \
        engine/graphics/screen.cpp \
        engine/sound/sound.cpp \
        hw/apu.cpp \
        hw/bus.cpp \
        hw/cpu.cpp \
        hw/ppu.cpp \
        main.cpp

HEADERS += \
    cartridge/cartridge.h \
    engine/graphics/screen.h \
    engine/sound/sound.h \
    hw/apu.h \
    hw/bus.h \
    hw/cpu.h \
    hw/ppu.h \
    hw/units.h
