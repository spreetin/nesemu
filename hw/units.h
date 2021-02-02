#ifndef UNITS_H
#define UNITS_H

#include <cstdint>

typedef uint8_t Byte;
typedef uint16_t Word;
typedef uint16_t Pointer;

union Bitfield {
    Byte byte;
    struct {
        unsigned b0 : 1;
        unsigned b1 : 1;
        unsigned b2 : 1;
        unsigned b3 : 1;
        unsigned b4 : 1;
        unsigned b5 : 1;
        unsigned b6 : 1;
        unsigned b7 : 1;
        unsigned b8 : 1;
    };
};

#endif
