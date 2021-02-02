#ifndef CPU_H
#define CPU_H

class Bus;

#include "hw/units.h"
#include <vector>

class CPU
{
public:
    CPU(Bus *bus);

    void cycle();
    void reset();
    void IRQ();
    void NMI();

    inline void i00() {BRK();}
    inline void i01() {ORA(INDX());}
    inline void i02() {KILL();}
    void i03();
    inline void i04() {NOP(); getPC();}
    inline void i05() {ORA(ZPI());}
    inline void i06() {ASL(getPC());}
    void i07();
    inline void i08() {PHP();}
    inline void i09() {ORA(IMM());}
    inline void i0A() {ASL(0x0000, true);}
    void i0B();
    inline void i0C() {NOP(); getPC(); getPC();}
    inline void i0D() {ORA(ABS());}
    inline void i0E() {ASL((Word)getPC()+((Word)getPC() << 8));}
    void i0F();
    inline void i10() {BPL();}
    inline void i11() {ORA(INDY());}
    inline void i12() {KILL();}
    void i13();
    inline void i14() {NOP(); getPC();}
    inline void i15() {ORA(ZPX());}
    inline void i16() {ASL(getPC()+X);}
    void i17();
    inline void i18() {CLC();}
    inline void i19() {ORA(ABSY());}
    inline void i1A() {NOP();}
    void i1B();
    void i1C();
    inline void i1D() {ORA(ABSX());}
    inline void i1E() {ASL((Word)getPC()+((Word)getPC() << 8)+X);}
    void i1F();
    inline void i20() {JSR(ABS());}
    inline void i21() {AND(INDX());}
    inline void i22() {KILL();}
    void i23();
    inline void i24() {BIT(ZPI());}
    inline void i25() {AND(ZPI());}
    inline void i26() {ROL(ZPI());}
    void i27();
    inline void i28() {PLP();}
    inline void i29() {AND(IMM());}
    inline void i2A() {ROL(0x00, true);}
    void i2B();
    inline void i2C() {BIT(ABS());}
    inline void i2D() {AND(ABS());}
    inline void i2E() {ROL(ABS());}
    void i2F();
    inline void i30() {BMI();}
    inline void i31() {AND(INDY());}
    inline void i32() {KILL();}
    void i33();
    void i34();
    inline void i35() {AND(ZPX());}
    inline void i36() {ROL(ZPX());}
    void i37();
    inline void i38() {SEC();}
    inline void i39() {AND(ABSY());}
    inline void i3A() {NOP();}
    void i3B();
    void i3C();
    inline void i3D() {AND(ABSX());}
    inline void i3E() {ROL(ABSX());}
    void i3F();
    inline void i40() {RTI();}
    inline void i41() {EOR(INDX());}
    inline void i42() {KILL();}
    void i43();
    void i44();
    inline void i45() {EOR(ZPI());}
    inline void i46() {LSR(ZPI());}
    void i47();
    inline void i48() {PHA();}
    inline void i49() {EOR(IMM());}
    inline void i4A() {LSR(0x00, true);}
    void i4B();
    inline void i4C() {JMP((Word)getPC()+((Word)getPC() << 8));}
    inline void i4D() {EOR(ABS());}
    inline void i4E() {LSR(ABS());}
    void i4F();
    inline void i50() {BVC();}
    inline void i51() {EOR(INDY());}
    inline void i52() {KILL();}
    void i53();
    void i54();
    inline void i55() {EOR(ZPX());}
    inline void i56() {LSR(ZPX());}
    void i57();
    inline void i58() {CLI();}
    inline void i59() {EOR(ABSY());}
    inline void i5A() {NOP();}
    void i5B();
    void i5C();
    inline void i5D() {EOR(ABSX());}
    inline void i5E() {LSR(ABSX());}
    void i5F();
    inline void i60() {RTS();}
    inline void i61() {ADC(INDX());}
    inline void i62() {KILL();}
    void i63();
    void i64();
    inline void i65() {ADC(ZPI());}
    inline void i66() {ROR(ZPI());}
    void i67();
    inline void i68() {PLA();}
    inline void i69() {ADC(IMM());}
    inline void i6A() {ROR(0x00, true);}
    void i6B();
    inline void i6C() {JMP(IND());}
    inline void i6D() {ADC(ABS());}
    inline void i6E() {ROR(ABS());}
    void i6F();
    inline void i70() {BVS();}
    inline void i71() {ADC(INDY());}
    inline void i72() {KILL();}
    void i73();
    void i74();
    inline void i75() {ADC(ZPX());}
    inline void i76() {ROR(ZPX());}
    void i77();
    inline void i78() {SEI();}
    inline void i79() {ADC(ABSY());}
    inline void i7A() {NOP();}
    void i7B();
    void i7C();
    inline void i7D() {ADC(ABSX());}
    inline void i7E() {ROR(ABSX());}
    void i7F();
    void i80();
    inline void i81() {STA(INDX_Addr());}
    void i82();
    void i83();
    inline void i84() {STY(getPC());}
    inline void i85() {STA(getPC());}
    inline void i86() {STX(getPC());}
    void i87();
    inline void i88() {DEY();}
    void i89();
    inline void i8A() {TXA();}
    void i8B();
    inline void i8C() {STY((Word)getPC()+((Word)getPC() << 8));}
    inline void i8D() {STA((Word)getPC()+((Word)getPC() << 8));}
    inline void i8E() {STX((Word)getPC()+((Word)getPC() << 8));}
    inline void i8F() {SAX((Word)getPC()+((Word)getPC() << 8));}
    inline void i90() {BCC();}
    inline void i91() {STA(INDY_Addr());}
    inline void i92() {KILL();}
    void i93();
    inline void i94() {STY(getPC()+X);}
    inline void i95() {STA(getPC()+X);}
    inline void i96() {STX(getPC()+Y);}
    void i97();
    inline void i98() {TYA();}
    inline void i99() {STA((Word)getPC()+((Word)getPC() << 8)+Y);}
    inline void i9A() {TXS();}
    void i9B();
    void i9C();
    inline void i9D() {STA((Word)getPC()+((Word)getPC() << 8)+X);}
    void i9E();
    void i9F();
    inline void iA0() {LDY(IMM());}
    inline void iA1() {LDA(INDX());}
    inline void iA2() {LDX(IMM());}
    void iA3();
    inline void iA4() {LDY(ZPI());}
    inline void iA5() {LDA(ZPI());}
    inline void iA6() {LDX(ZPI());}
    void iA7();
    inline void iA8() {TAY();}
    inline void iA9() {LDA(IMM());}
    inline void iAA() {TAX();}
    void iAB();
    inline void iAC() {LDY(ABS());}
    inline void iAD() {LDA(ABS());}
    inline void iAE() {LDX(ABS());}
    void iAF();
    inline void iB0() {BCS();}
    inline void iB1() {LDA(INDY());}
    inline void iB2() {KILL();}
    void iB3();
    inline void iB4() {LDY(ZPX());}
    inline void iB5() {LDA(ZPX());}
    inline void iB6() {LDX(ZPX());}
    void iB7();
    inline void iB8() {CLV();}
    inline void iB9() {LDA(ABSY());}
    inline void iBA() {TSX();}
    void iBB();
    inline void iBC() {LDY(ABSX());}
    inline void iBD() {LDA(ABSX());}
    inline void iBE() {LDX(ABSY());}
    void iBF();
    inline void iC0() {CPY(IMM());}
    inline void iC1() {CMP(INDX());}
    void iC2();
    void iC3();
    inline void iC4() {CPY(ZPI());}
    inline void iC5() {CMP(ZPI());}
    inline void iC6() {DEC((Pointer)getPC());}
    void iC7();
    inline void iC8() {INY();}
    inline void iC9() {CMP(IMM());}
    inline void iCA() {DEX();}
    void iCB();
    inline void iCC() {CPY(ABS());}
    inline void iCD() {CMP(ABS());}
    inline void iCE() {DEC((Word)getPC()+((Word)getPC() << 8));}
    void iCF();
    inline void iD0() {BNE();}
    inline void iD1() {CMP(INDY());}
    inline void iD2() {KILL();}
    void iD3();
    void iD4();
    inline void iD5() {CMP(ZPX());}
    inline void iD6() {DEC((Pointer)getPC()+X);}
    void iD7();
    inline void iD8() {CLD();}
    inline void iD9() {CMP(ABSY());}
    inline void iDA() {NOP();}
    void iDB();
    void iDC();
    inline void iDD() {CMP(ABSX());}
    inline void iDE() {DEC((Word)getPC()+((Word)getPC() << 8)+X);}
    void iDF();
    inline void iE0() {CPX(IMM());}
    inline void iE1() {SBC(INDX());};
    void iE2();
    void iE3();
    inline void iE4() {CPX(ZPI());}
    inline void iE5() {SBC(ZPI());}
    inline void iE6() {INC(ZPI());}
    void iE7();
    inline void iE8() {INX();}
    inline void iE9() {SBC(IMM());}
    inline void iEA() {NOP();}
    void iEB();
    inline void iEC() {CPX(ABS());}
    inline void iED() {SBC(ABS());}
    inline void iEE() {INC(ABS());}
    void iEF();
    inline void iF0() {BEQ();}
    inline void iF1() {SBC(INDY());}
    inline void iF2() {KILL();}
    void iF3();
    void iF4();
    inline void iF5() {SBC(ZPX());}
    inline void iF6() {INC(ZPX());}
    void iF7();
    inline void iF8() {SED();}
    inline void iF9() {SBC(ABSY());}
    inline void iFA() {NOP();}
    void iFB();
    void iFC();
    inline void iFD() {SBC(ABSX());}
    inline void iFE() {INC(ABSX());}
    void iFF();

    Byte IMM();
    Byte ZPI();
    Byte ZPX();
    Byte ZPY();
    Word ABS();
    Word ABSX();
    Word ABSY();
    Pointer IND();
    Word INDX();
    Word INDY();
    Pointer INDX_Addr();
    Pointer INDY_Addr();

    void ADC(Word data);
    void AND(Byte data);
    void ASL(Pointer addr, bool useA = false);
    void BCC();
    void BCS();
    void BEQ();
    void BIT(Byte data);
    void BMI();
    void BNE();
    void BPL();
    void BRK();
    void BVC();
    void BVS();
    void CLC();
    void CLD();
    void CLI();
    void CLV();
    void CMP(Byte data);
    void CPX(Byte data);
    void CPY(Byte data);
    void DEC(Pointer addr);
    void DEX();
    void DEY();
    void EOR(Byte data);
    void INC(Pointer addr);
    void INX();
    void INY();
    void JMP(Pointer addr);
    void JSR(Pointer addr);
    void LDA(Byte data);
    void LDX(Byte data);
    void LDY(Byte data);
    void LSR(Pointer addr, bool useA = false);
    void NOP() {return;}
    void ORA(Byte data);
    void PHA();
    void PHP();
    void PLA();
    void PLP();
    void ROL(Pointer addr, bool useA = false);
    void ROR(Pointer addr, bool useA = false);
    void RTI();
    void RTS();
    void SBC(Word data);
    void SEC();
    void SED();
    void SEI();
    void STA(Pointer addr);
    void STX(Pointer addr);
    void STY(Pointer addr);
    void TAX();
    void TAY();
    void TSX();
    void TXA();
    void TXS();
    void TYA();

    // Illegal opcodes
    void KILL();
    void SAX(Pointer addr);

private:
    Byte getMemory(Pointer addr, bool * crossedBorder = nullptr);
    void setMemory(Pointer addr, Byte data);

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

    Byte getPC() {
        PC++;
        return getMemory(PC-1);
    }

    void setPC(Word addr);

    void push(Pointer addr);
    Pointer pop();

    Byte A;
    Byte X;
    Byte Y;
    Word PC;
    Byte S;
    Byte P;

    std::vector<void(CPU::*)()> opcodes;
    std::vector<uint8_t> cycleCount;

    uint32_t counter = 0;
    uint8_t opcounter = 0;

    Bus *bus;
};

#endif // CPU_H
