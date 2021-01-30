#ifndef CPU_H
#define CPU_H

#include "hw/units.h"

enum AddressingModes {
    Imm,
    ZeroP,
    ZeroPX,
    Abs,
    AbsX,
    AbsY,
    IndX,
    IndY
};

class CPU
{
public:
    CPU();

    void ADC(Pointer &addr, AddressingModes mode);
    void AND(Pointer &addr, AddressingModes mode);
    void ASL(Pointer &addr, AddressingModes mode);
    void BCC(Pointer &addr, AddressingModes mode);
    void BCS(Pointer &addr, AddressingModes mode);
    void BEQ(Pointer &addr, AddressingModes mode);
    void BIT(Pointer &addr, AddressingModes mode);
    void BMI(Pointer &addr, AddressingModes mode);
    void BNE(Pointer &addr, AddressingModes mode);
    void BPL(Pointer &addr, AddressingModes mode);
    void BRK(Pointer &addr, AddressingModes mode);
    void BVC(Pointer &addr, AddressingModes mode);
    void BVS(Pointer &addr, AddressingModes mode);
    void CLC(Pointer &addr, AddressingModes mode);
    void CLD(Pointer &addr, AddressingModes mode);
    void CLI(Pointer &addr, AddressingModes mode);
    void CLV(Pointer &addr, AddressingModes mode);
    void CMP(Pointer &addr, AddressingModes mode);
    void CPX(Pointer &addr, AddressingModes mode);
    void CPY(Pointer &addr, AddressingModes mode);
    void DEC(Pointer &addr, AddressingModes mode);
    void DEX(Pointer &addr, AddressingModes mode);
    void DEY(Pointer &addr, AddressingModes mode);
    void EOR(Pointer &addr, AddressingModes mode);
    void INC(Pointer &addr, AddressingModes mode);
    void INX(Pointer &addr, AddressingModes mode);
    void INY(Pointer &addr, AddressingModes mode);
    void JMP(Pointer &addr, AddressingModes mode);
    void JSR(Pointer &addr, AddressingModes mode);
    void LDA(Pointer &addr, AddressingModes mode);
    void LDX(Pointer &addr, AddressingModes mode);
    void LDY(Pointer &addr, AddressingModes mode);
    void LSR(Pointer &addr, AddressingModes mode);
    void NOP(Pointer &addr, AddressingModes mode);
    void ORA(Pointer &addr, AddressingModes mode);
    void PHA(Pointer &addr, AddressingModes mode);
    void PHP(Pointer &addr, AddressingModes mode);
    void PLA(Pointer &addr, AddressingModes mode);
    void PLP(Pointer &addr, AddressingModes mode);
    void ROL(Pointer &addr, AddressingModes mode);
    void ROR(Pointer &addr, AddressingModes mode);
    void RTI(Pointer &addr, AddressingModes mode);
    void RTS(Pointer &addr, AddressingModes mode);
    void SBC(Pointer &addr, AddressingModes mode);
    void SEC(Pointer &addr, AddressingModes mode);
    void SED(Pointer &addr, AddressingModes mode);
    void SEI(Pointer &addr, AddressingModes mode);
    void STA(Pointer &addr, AddressingModes mode);
    void STX(Pointer &addr, AddressingModes mode);
    void STY(Pointer &addr, AddressingModes mode);
    void TAX(Pointer &addr, AddressingModes mode);
    void TAY(Pointer &addr, AddressingModes mode);
    void TSX(Pointer &addr, AddressingModes mode);
    void TXA(Pointer &addr, AddressingModes mode);
    void TXS(Pointer &addr, AddressingModes mode);
    void TYA(Pointer &addr, AddressingModes mode);

private:
    bool negativeFlag() {return P & 128;}
    bool overflowFlag() {return P & 64;}
    bool breakFlag() {return P & 16;}
    bool decimalModeFlag() {return P & 8;}
    bool interruptFlag() {return P & 4;}
    bool zeroFlag() {return P & 2;}
    bool carryFlag() {return P & 1;}

    void setNegativeFlag(bool value) {if (value){P = P | 128;} else {P = P & (~128);}}

    Byte A;
    Byte X;
    Byte Y;
    Word PC;
    Byte S;
    Byte P;
};

#endif // CPU_H
