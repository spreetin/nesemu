#ifndef CPU_H
#define CPU_H

#include "hw/units.h"

class CPU
{
public:
    CPU();

private:
    Byte A;
    Byte X;
    Byte Y;
    Word PC;
    Byte S;
    Byte P;
};

#endif // CPU_H
