TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        engine/graphics/screen.cpp \
        engine/sound/sound.cpp \
        hw/bus.cpp \
        hw/cpu.cpp \
        hw/memory.cpp \
        main.cpp

HEADERS += \
    engine/graphics/screen.h \
    engine/sound/sound.h \
    hw/bus.h \
    hw/cpu.h \
    hw/memory.h
