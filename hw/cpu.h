#ifndef CPU_H
#define CPU_H

#include "hw/units.h"

enum AddressingModes {
    Immidiate,
    ZeroPage,
    ZeroPageX,
    Absolute,
    AbsoluteX,
    AbsoluteY,
    IndirectX,
    IndirectY
};

class CPU
{
public:
    CPU();

    void cycle();

    void i00(); // BRK, IMP
    void i01();
    void i02();
    void i03();
    void i04();
    void i05();
    void i06(); // ASL, ZP
    void i07();
    void i08();
    void i09();
    void i0A(); // ASL, ACC
    void i0B();
    void i0C();
    void i0D();
    void i0E(); // ASL, ABS
    void i0F();
    void i10(); // BPL, REL
    void i11();
    void i12();
    void i13();
    void i14();
    void i15();
    void i16(); // ASL, ZPX
    void i17();
    void i18(); // CLC, IMP
    void i19();
    void i1A();
    void i1B();
    void i1C();
    void i1D();
    void i1E(); // ASL, ABSX
    void i1F();
    void i20();
    void i21(); // AND, INDX
    void i22();
    void i23();
    void i24(); // BIT, ZP
    void i25(); // AND, ZP
    void i26();
    void i27();
    void i28();
    void i29(); // AND, IMM
    void i2A();
    void i2B();
    void i2C(); // BIT, ABS
    void i2D(); // AND, ABS
    void i2E();
    void i2F();
    void i30(); // BMI, REL
    void i31(); // AND, INDY
    void i32();
    void i33();
    void i34();
    void i35(); // AND, ZPX
    void i36();
    void i37();
    void i38();
    void i39(); // AND, ABSY
    void i3A();
    void i3B();
    void i3C();
    void i3D(); // AND, ABSX
    void i3E();
    void i3F();
    void i40();
    void i41();
    void i42();
    void i43();
    void i44();
    void i45(); // EOR, ZP
    void i46();
    void i47();
    void i48();
    void i49(); // EOR, IMM
    void i4A();
    void i4B();
    void i4C();
    void i4D(); // EOR, ABS
    void i4E();
    void i4F();
    void i50(); // BVC, REL
    void i51();
    void i52();
    void i53();
    void i54();
    void i55(); // EOR, ZPX
    void i56();
    void i57();
    void i58(); // CLI, IMP
    void i59(); // EOR, ABSY
    void i5A();
    void i5B();
    void i5C();
    void i5D(); // EOR, ABSX
    void i5E();
    void i5F();
    void i60();
    void i61(); // ADC, INDX
    void i62();
    void i63();
    void i64();
    void i65(); // ADC, ZP
    void i66();
    void i67();
    void i68();
    void i69(); // ADC, IMM
    void i6A();
    void i6B();
    void i6C();
    void i6D(); // ADC, ABS
    void i6E();
    void i6F();
    void i70(); // BVS, REL
    void i71(); // ADC, INDY
    void i72();
    void i73();
    void i74();
    void i75(); // ADC, ZPX
    void i76();
    void i77();
    void i78();
    void i79(); // ADC, ABSY
    void i7A();
    void i7B();
    void i7C();
    void i7D(); // ADC, ABSX
    void i7E();
    void i7F();
    void i80();
    void i81();
    void i82();
    void i83();
    void i84();
    void i85();
    void i86();
    void i87();
    void i88(); // DEY, IMP
    void i89();
    void i8A();
    void i8B();
    void i8C();
    void i8D();
    void i8E();
    void i8F();
    void i90(); // BCC, REL
    void i91();
    void i92();
    void i93();
    void i94();
    void i95();
    void i96();
    void i97();
    void i98();
    void i99();
    void i9A();
    void i9B();
    void i9C();
    void i9D();
    void i9E();
    void i9F();
    void iA0();
    void iA1();
    void iA2();
    void iA3();
    void iA4();
    void iA5();
    void iA6();
    void iA7();
    void iA8();
    void iA9();
    void iAA();
    void iAB();
    void iAC();
    void iAD();
    void iAE();
    void iAF();
    void iB0(); // BCS, REL
    void iB1();
    void iB2();
    void iB3();
    void iB4();
    void iB5();
    void iB6();
    void iB7();
    void iB8(); // CLV, IMP
    void iB9();
    void iBA();
    void iBB();
    void iBC();
    void iBD();
    void iBE();
    void iBF();
    void iC0(); // CPY, IMM
    void iC1(); // CMP, INDX
    void iC2();
    void iC3();
    void iC4(); // CPY, ZP
    void iC5(); // CMP, ZP
    void iC6(); // DEC, ZP
    void iC7();
    void iC8();
    void iC9(); // CMP, IMM
    void iCA(); // DEX, IMP
    void iCB();
    void iCC(); // CPY, ABS
    void iCD(); // CMP, ABS
    void iCE(); // DEC, ABS
    void iCF();
    void iD0(); // BNE, REL
    void iD1(); // CMP, INDY
    void iD2();
    void iD3();
    void iD4();
    void iD5(); // CMP, ZPX
    void iD6(); // DEC, ZPX
    void iD7();
    void iD8(); // CLD, IMP
    void iD9(); // CMP, ABSY
    void iDA();
    void iDB();
    void iDC();
    void iDD(); // CMP, ABSX
    void iDE(); // DEC, ABSX
    void iDF();
    void iE0(); // CPX, IMM
    void iE1();
    void iE2();
    void iE3();
    void iE4(); // CPX, ZP
    void iE5();
    void iE6();
    void iE7();
    void iE8();
    void iE9();
    void iEA();
    void iEB();
    void iEC(); // CPX, ABS
    void iED();
    void iEE();
    void iEF();
    void iF0(); // BEQ, REL
    void iF1();
    void iF2();
    void iF3();
    void iF4();
    void iF5();
    void iF6();
    void iF7();
    void iF8();
    void iF9();
    void iFA();
    void iFB();
    void iFC();
    void iFD();
    void iFE();
    void iFF();


    void ADC(Pointer &addr, AddressingModes mode);
    void AND(Pointer &addr, AddressingModes mode);
    void ASL(Pointer &addr, AddressingModes mode);
    void BCC(Pointer &addr, AddressingModes mode);
    void BCS(Pointer &addr, AddressingModes mode);
    void BEQ(Pointer &addr, AddressingModes mode);
    void BIT(Pointer &addr, AddressingModes mode); // Klar
    void BMI(Pointer &addr, AddressingModes mode);
    void BNE(Pointer &addr, AddressingModes mode);
    void BPL(Pointer &addr, AddressingModes mode);
    void BRK(Pointer &addr, AddressingModes mode);
    void BVC(Pointer &addr, AddressingModes mode);
    void BVS(Pointer &addr, AddressingModes mode);
    void CLC(Pointer &addr, AddressingModes mode); // Klar
    void CLD(Pointer &addr, AddressingModes mode); // Klar
    void CLI(Pointer &addr, AddressingModes mode); // Klar
    void CLV(Pointer &addr, AddressingModes mode); // Klar
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
    Byte getMemory(Pointer &addr, bool * crossedBorder = nullptr);
    void setMemory(Pointer &addr, Byte &data);

    bool negativeFlag() {return P & 128;}
    bool overflowFlag() {return P & 64;}
    bool breakFlag() {return P & 16;}
    bool decimalModeFlag() {return P & 8;}
    bool interruptFlag() {return P & 4;}
    bool zeroFlag() {return P & 2;}
    bool carryFlag() {return P & 1;}

    void setNegativeFlag(bool value) {if (value){P = P | 128;} else {P = P & (~128);}}
    void setOverflowFlag(bool value) {if (value){P = P | 64;} else {P = P & (~64);}}
    void setBreakFlag(bool value) {if (value){P = P | 16;} else {P = P & (~16);}}
    void setDecimalModeFlag(bool value) {if (value){P = P | 8;} else {P = P & (~8);}}
    void setInterruptFlag(bool value) {if (value){P = P | 4;} else {P = P & (~4);}}
    void setZeroFlag(bool value) {if (value){P = P | 2;} else {P = P & (~2);}}
    void setCarryFlag(bool value) {if (value){P = P | 1;} else {P = P & (~1);}}

    Byte A;
    Byte X;
    Byte Y;
    Word PC;
    Byte S;
    Byte P;

    uint32_t counter = 0;
};

#endif // CPU_H
