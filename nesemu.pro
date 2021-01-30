TEMPLATE = app
CONFIG += console c++11 link_pkgconfig
CONFIG -= app_bundle
CONFIG -= qt
PKGCONFIG += sdl2

SOURCES += \
        engine/graphics/screen.cpp \
        engine/sound/sound.cpp \
        hw/apu.cpp \
        hw/bus.cpp \
        hw/cpu.cpp \
        hw/memory.cpp \
        hw/ppu.cpp \
        main.cpp

HEADERS += \
    engine/graphics/screen.h \
    engine/sound/sound.h \
    hw/apu.h \
    hw/bus.h \
    hw/cpu.h \
    hw/memory.h \
    hw/ppu.h \
    hw/units.h
