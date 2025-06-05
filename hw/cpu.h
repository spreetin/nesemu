#ifndef CPU_H
#define CPU_H

class Bus;

#include "../units.h"
#include <vector>
#include <fstream>
#include <string>

class CPU
{
public:
    CPU(Bus *bus);

    char current_code[10];
    char current_mnemonic[10];
    char current_P[10];
    char current_A[10];
    char current_X[10];
    char current_Y[10];
    char current_SP[10];
    char current_PC[10];

    void cycle();
    void reset();
    void IRQ();
    void NMI();

    inline void i00() {BRK();}
    inline void i01() {ORA(INDX());}
    inline void i02() {KILL();}
    inline void i03() {SLO(INDX_Addr());}
    inline void i04() {NOP(); getPC();}
    inline void i05() {ORA(ZPI());}
    inline void i06() {ASL(getPC());}
    inline void i07() {SLO(getPC());}
    inline void i08() {PHP();}
    inline void i09() {ORA(IMM());}
    inline void i0A() {ASL(0x0, true);}
    inline void i0B() {AND(IMM()); setCarryFlag(negativeFlag());}
    inline void i0C() {NOP(); getPC(); getPC();}
    inline void i0D() {ORA(ABS());}
    inline void i0E() {ASL(ABS_Addr());}
    inline void i0F() {SLO(ABS_Addr());}
    inline void i10() {BPL();}
    inline void i11() {ORA(INDY());}
    inline void i12() {KILL();}
    inline void i13() {SLO(INDY_Addr());}
    inline void i14() {NOP(); getPC();}
    inline void i15() {ORA(ZPX());}
    inline void i16() {ASL(ZPX_Addr());}
    inline void i17() {SLO(ZPX_Addr());}
    inline void i18() {CLC();}
    inline void i19() {ORA(ABSY());}
    inline void i1A() {NOP();}
    inline void i1B() {SLO(ABSY_Addr());}
    inline void i1C() {getMemory(ABSX_Addr());}
    inline void i1D() {ORA(ABSX());}
    inline void i1E() {ASL(ABSX_Addr());}
    inline void i1F() {SLO(ABSX_Addr());}
    inline void i20() {JSR(ABS_Addr());}
    inline void i21() {AND(INDX());}
    inline void i22() {KILL();}
    inline void i23() {RLA(INDX_Addr());}
    inline void i24() {BIT(ZPI());}
    inline void i25() {AND(ZPI());}
    inline void i26() {ROL(ZPI_Addr());}
    inline void i27() {RLA(getPC());}
    inline void i28() {PLP();}
    inline void i29() {AND(IMM());}
    inline void i2A() {ROL(0x0, true);}
    inline void i2B() {AND(IMM()); setCarryFlag(negativeFlag());}
    inline void i2C() {BIT(ABS());}
    inline void i2D() {AND(ABS());}
    inline void i2E() {ROL(ABS_Addr());}
    inline void i2F() {RLA(ABS_Addr());}
    inline void i30() {BMI();}
    inline void i31() {AND(INDY());}
    inline void i32() {KILL();}
    inline void i33() {RLA(INDY_Addr());}
    inline void i34() {NOP(); getPC();}
    inline void i35() {AND(ZPX());}
    inline void i36() {ROL(ZPX_Addr());}
    inline void i37() {RLA(ZPX_Addr());}
    inline void i38() {SEC();}
    inline void i39() {AND(ABSY());}
    inline void i3A() {NOP();}
    inline void i3B() {RLA(ABSY_Addr());}
    inline void i3C() {getMemory(ABSX_Addr());}
    inline void i3D() {AND(ABSX());}
    inline void i3E() {ROL(ABSX_Addr());}
    inline void i3F() {RLA(ABSX_Addr());}
    inline void i40() {RTI();}
    inline void i41() {EOR(INDX());}
    inline void i42() {KILL();}
    inline void i43() {SRE(INDX_Addr());}
    inline void i44() {NOP(); getPC();}
    inline void i45() {EOR(ZPI());}
    inline void i46() {LSR(ZPI_Addr());}
    inline void i47() {SRE(getPC());}
    inline void i48() {PHA();}
    inline void i49() {EOR(IMM());}
    inline void i4A() {LSR(0x0, true);}
    inline void i4B() {AND(IMM()); LSR(0x0, true);}
    inline void i4C() {JMP(ABS_Addr());}
    inline void i4D() {EOR(ABS());}
    inline void i4E() {LSR(ABS_Addr());}
    inline void i4F() {SRE(ABS_Addr());}
    inline void i50() {BVC();}
    inline void i51() {EOR(INDY());}
    inline void i52() {KILL();}
    inline void i53() {SRE(INDY_Addr());}
    inline void i54() {NOP(); getPC();}
    inline void i55() {EOR(ZPX());}
    inline void i56() {LSR(ZPX_Addr());}
    inline void i57() {SRE(ZPX_Addr());}
    inline void i58() {CLI();}
    inline void i59() {EOR(ABSY());}
    inline void i5A() {NOP();}
    inline void i5B() {SRE(ABSY_Addr());}
    inline void i5C() {getMemory(ABSX_Addr());}
    inline void i5D() {EOR(ABSX());}
    inline void i5E() {LSR(ABSX_Addr());}
    inline void i5F() {SRE(ABSX_Addr());}
    inline void i60() {RTS();}
    inline void i61() {ADC(INDX());}
    inline void i62() {KILL();}
    inline void i63() {RRA(INDX_Addr());}
    inline void i64() {NOP(); getPC();}
    inline void i65() {ADC(ZPI());}
    inline void i66() {ROR(ZPI_Addr());}
    inline void i67() {RRA(getPC());}
    inline void i68() {PLA();}
    inline void i69() {ADC(IMM());}
    inline void i6A() {ROR(0x0, true);}
    inline void i6B() {ARR(IMM());}
    inline void i6C() {JMP(IND());}
    inline void i6D() {ADC(ABS());}
    inline void i6E() {ROR(ABS_Addr());}
    inline void i6F() {RRA(ABS_Addr());}
    inline void i70() {BVS();}
    inline void i71() {ADC(INDY());}
    inline void i72() {KILL();}
    inline void i73() {RRA(INDY_Addr());}
    inline void i74() {NOP(); getPC();}
    inline void i75() {ADC(ZPX());}
    inline void i76() {ROR(ZPX_Addr());}
    inline void i77() {RRA(ZPX_Addr());}
    inline void i78() {SEI();}
    inline void i79() {ADC(ABSY());}
    inline void i7A() {NOP();}
    inline void i7B() {RRA(ABSY_Addr());}
    inline void i7C() {getMemory(ABSX_Addr());}
    inline void i7D() {ADC(ABSX());}
    inline void i7E() {ROR(ABSX_Addr());}
    inline void i7F() {RRA(ABSX_Addr());}
    inline void i80() {IMM(); NOP();}
    inline void i81() {STA(INDX_Addr());}
    inline void i82() {IMM(); NOP();}
    inline void i83() {SAX(INDX_Addr());}
    inline void i84() {STY(getPC());}
    inline void i85() {STA(getPC());}
    inline void i86() {STX(getPC());}
    inline void i87() {SAX(getPC());}
    inline void i88() {DEY();}
    inline void i89() {IMM(); NOP();}
    inline void i8A() {TXA();}
    inline void i8B() {XAA(IMM());}
    inline void i8C() {STY(ABS_Addr());}
    inline void i8D() {STA(ABS_Addr());}
    inline void i8E() {STX(ABS_Addr());}
    inline void i8F() {SAX(ABS_Addr());}
    inline void i90() {BCC();}
    inline void i91() {STA(INDY_Addr());}
    inline void i92() {KILL();}
    inline void i93() {SHA(INDY_Addr());}
    inline void i94() {STY(ZPX_Addr());}
    inline void i95() {STA(ZPX_Addr());}
    inline void i96() {STX(ZPY_Addr());}
    inline void i97() {SAX(ZPY_Addr());}
    inline void i98() {TYA();}
    inline void i99() {STA(ABSY_Addr());}
    inline void i9A() {TXS();}
    inline void i9B() {TAS(ABSY_Addr());}
    inline void i9C() {SHY(ABSX_Addr());}
    inline void i9D() {STA(ABSX_Addr());}
    inline void i9E() {SHX(ABSY_Addr());}
    inline void i9F() {SHA(ABSY_Addr());}
    inline void iA0() {LDY(IMM());}
    inline void iA1() {LDA(INDX());}
    inline void iA2() {LDX(IMM());}
    inline void iA3() {LDA(INDX()); TAX();}
    inline void iA4() {LDY(ZPI());}
    inline void iA5() {LDA(ZPI());}
    inline void iA6() {LDX(ZPI());}
    inline void iA7() {LDA(ZPI()); TAX();}
    inline void iA8() {TAY();}
    inline void iA9() {LDA(IMM());}
    inline void iAA() {TAX();}
    inline void iAB() {LAX(IMM());}
    inline void iAC() {LDY(ABS());}
    inline void iAD() {LDA(ABS());}
    inline void iAE() {LDX(ABS());}
    inline void iAF() {LDA(ABS()); TAX();}
    inline void iB0() {BCS();}
    inline void iB1() {LDA(INDY());}
    inline void iB2() {KILL();}
    inline void iB3() {LDA(INDY()); TAX();}
    inline void iB4() {LDY(ZPX());}
    inline void iB5() {LDA(ZPX());}
    inline void iB6() {LDX(ZPX());}
    inline void iB7() {LDA(ZPY()); TAX();}
    inline void iB8() {CLV();}
    inline void iB9() {LDA(ABSY());}
    inline void iBA() {TSX();}
    inline void iBB() {LAS(ABSY());}
    inline void iBC() {LDY(ABSX());}
    inline void iBD() {LDA(ABSX());}
    inline void iBE() {LDX(ABSY());}
    inline void iBF() {LDA(ABSY()); TAX();}
    inline void iC0() {CPY(IMM());}
    inline void iC1() {CMP(INDX());}
    inline void iC2() {IMM(); NOP();}
    inline void iC3() {DCP(INDX_Addr());}
    inline void iC4() {CPY(ZPI());}
    inline void iC5() {CMP(ZPI());}
    inline void iC6() {DEC((Pointer)getPC());}
    inline void iC7() {DCP(getPC());}
    inline void iC8() {INY();}
    inline void iC9() {CMP(IMM());}
    inline void iCA() {DEX();}
    inline void iCB() {AXS(IMM());}
    inline void iCC() {CPY(ABS());}
    inline void iCD() {CMP(ABS());}
    inline void iCE() {DEC(ABS_Addr());}
    inline void iCF() {DCP(ABS_Addr());}
    inline void iD0() {BNE();}
    inline void iD1() {CMP(INDY());}
    inline void iD2() {KILL();}
    inline void iD3() {DCP(INDY_Addr());}
    inline void iD4() {NOP(); getPC();}
    inline void iD5() {CMP(ZPX());}
    inline void iD6() {DEC(ZPX_Addr());}
    inline void iD7() {DCP(ZPX_Addr());}
    inline void iD8() {CLD();}
    inline void iD9() {CMP(ABSY());}
    inline void iDA() {NOP();}
    inline void iDB() {DCP(ABSY_Addr());}
    inline void iDC() {getMemory(ABSX_Addr());}
    inline void iDD() {CMP(ABSX());}
    inline void iDE() {DEC(ABSX_Addr());}
    inline void iDF() {DCP(ABSX_Addr());}
    inline void iE0() {CPX(IMM());}
    inline void iE1() {SBC(INDX());};
    inline void iE2() {IMM(); NOP();}
    inline void iE3() {ISC(ZPX_Addr());}
    inline void iE4() {CPX(ZPI());}
    inline void iE5() {SBC(ZPI());}
    inline void iE6() {INC(ZPI_Addr());}
    inline void iE7() {ISC(getPC());}
    inline void iE8() {INX();}
    inline void iE9() {SBC(IMM());}
    inline void iEA() {NOP();}
    inline void iEB() {SBC(IMM());}
    inline void iEC() {CPX(ABS());}
    inline void iED() {SBC(ABS());}
    inline void iEE() {INC(ABS_Addr());}
    inline void iEF() {ISC(ABS_Addr());}
    inline void iF0() {BEQ();}
    inline void iF1() {SBC(INDY());}
    inline void iF2() {KILL();}
    inline void iF3() {ISC(INDY_Addr());}
    inline void iF4() {NOP(); getPC();}
    inline void iF5() {SBC(ZPX());}
    inline void iF6() {INC(ZPX_Addr());}
    inline void iF7() {ISC(ZPX_Addr());}
    inline void iF8() {SED();}
    inline void iF9() {SBC(ABSY());}
    inline void iFA() {NOP();}
    inline void iFB() {ISC(ABSY_Addr());}
    inline void iFC() {getMemory(ABSX_Addr());}
    inline void iFD() {SBC(ABSX());}
    inline void iFE() {INC(ABSX_Addr());}
    inline void iFF() {ISC(ABSX_Addr());}

    Byte IMM();
    Byte ZPI();
    Byte ZPX();
    Byte ZPY();
    Pointer ZPI_Addr();
    Pointer ZPX_Addr();
    Pointer ZPY_Addr();
    Word ABS();
    Word ABSX();
    Word ABSY();
    Pointer ABS_Addr();
    Pointer ABSX_Addr();
    Pointer ABSY_Addr();
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
    void DCP(Pointer addr);
    void ISC(Pointer addr);
    void RLA(Pointer addr);
    void RRA(Pointer addr);
    void SLO(Pointer addr);
    void SRE(Pointer addr);
    void ARR(Byte data);
    void XAA(Byte data);
    void SHA(Pointer addr);
    void SHX(Pointer addr);
    void SHY(Pointer addr);
    void TAS(Pointer addr);
    void LAX(Byte data);
    void LAS(Byte data);
    void AXS(Byte data);

private:
    Byte getMemory(Pointer addr);
    void setMemory(Pointer addr, Byte data);

    bool negativeFlag() const {return P & 128;}
    bool overflowFlag() const {return P & 64;}
    bool breakFlag() const {return P & 16;}
    bool decimalModeFlag() const {return P & 8;}
    bool interruptFlag() const {return P & 4;}
    bool zeroFlag() const {return P & 2;}
    bool carryFlag() const {return P & 1;}

    void setNegativeFlag(bool value) {if (value){P = P | 128;} else {P = P & (~128);}}
    void setOverflowFlag(bool value) {if (value){P = P | 64;} else {P = P & (~64);}}
    void setBreakFlag(bool value) {if (value){P = P | 16;} else {P = P & (~16);}}
    void setDecimalModeFlag(bool value) {if (value){P = P | 8;} else {P = P & (~8);}}
    void setInterruptFlag(bool value) {if (value){P = P | 4;} else {P = P & (~4);}}
    void setZeroFlag(bool value) {if (value){P = P | 2;} else {P = P & (~2);}}
    void setCarryFlag(bool value) {if (value){P = P | 1;} else {P = P & (~1);}}

    Byte getPC() {
        Byte byte = getMemory(PC);
        PC++;
        return byte;
    }

    void setPC(Word addr);

    void push(Pointer addr);
    Pointer pop();

    std::string getRepr(Byte code, Byte A1, Byte A2) const;

    Byte A;
    Byte X;
    Byte Y;
    Word PC;
    Byte S;
    Byte P;

    std::vector<uint8_t> readCount;
    std::vector<void(CPU::*)()> opcodes;
    std::vector<std::string> opnames;
    std::vector<uint8_t> cycleCount;

    uint64_t cycleNum = 7;

    uint8_t opcounter = 0;

    Bus *bus;

    std::ofstream logger;
};

#endif // CPU_H
