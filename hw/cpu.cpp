#include "cpu.h"
#include "bus.h"

CPU::CPU(Bus *bus)
    : bus(bus)
{
    A = 0;
    X = 0;
    Y = 0;
    P = 0x24;
    S = 0xFD;
    PC = 0xC000;
    opcodes = {
        &CPU::i00, &CPU::i01, &CPU::i02, &CPU::i03, &CPU::i04, &CPU::i05, &CPU::i06, &CPU::i07,
        &CPU::i08, &CPU::i09, &CPU::i0A, &CPU::i0B, &CPU::i0C, &CPU::i0D, &CPU::i0E, &CPU::i0F,
        &CPU::i10, &CPU::i11, &CPU::i12, &CPU::i13, &CPU::i14, &CPU::i15, &CPU::i16, &CPU::i17,
        &CPU::i18, &CPU::i19, &CPU::i1A, &CPU::i1B, &CPU::i1C, &CPU::i1D, &CPU::i1E, &CPU::i1F,
        &CPU::i20, &CPU::i21, &CPU::i22, &CPU::i23, &CPU::i24, &CPU::i25, &CPU::i26, &CPU::i27,
        &CPU::i28, &CPU::i29, &CPU::i2A, &CPU::i2B, &CPU::i2C, &CPU::i2D, &CPU::i2E, &CPU::i2F,
        &CPU::i30, &CPU::i31, &CPU::i32, &CPU::i33, &CPU::i34, &CPU::i35, &CPU::i36, &CPU::i37,
        &CPU::i38, &CPU::i39, &CPU::i3A, &CPU::i3B, &CPU::i3C, &CPU::i3D, &CPU::i3E, &CPU::i3F,
        &CPU::i40, &CPU::i41, &CPU::i42, &CPU::i43, &CPU::i44, &CPU::i45, &CPU::i46, &CPU::i47,
        &CPU::i48, &CPU::i49, &CPU::i4A, &CPU::i4B, &CPU::i4C, &CPU::i4D, &CPU::i4E, &CPU::i4F,
        &CPU::i50, &CPU::i51, &CPU::i52, &CPU::i53, &CPU::i54, &CPU::i55, &CPU::i56, &CPU::i57,
        &CPU::i58, &CPU::i59, &CPU::i5A, &CPU::i5B, &CPU::i5C, &CPU::i5D, &CPU::i5E, &CPU::i5F,
        &CPU::i60, &CPU::i61, &CPU::i62, &CPU::i63, &CPU::i64, &CPU::i65, &CPU::i66, &CPU::i67,
        &CPU::i68, &CPU::i69, &CPU::i6A, &CPU::i6B, &CPU::i6C, &CPU::i6D, &CPU::i6E, &CPU::i6F,
        &CPU::i70, &CPU::i71, &CPU::i72, &CPU::i73, &CPU::i74, &CPU::i75, &CPU::i76, &CPU::i77,
        &CPU::i78, &CPU::i79, &CPU::i7A, &CPU::i7B, &CPU::i7C, &CPU::i7D, &CPU::i7E, &CPU::i7F,
        &CPU::i80, &CPU::i81, &CPU::i82, &CPU::i83, &CPU::i84, &CPU::i85, &CPU::i86, &CPU::i87,
        &CPU::i88, &CPU::i89, &CPU::i8A, &CPU::i8B, &CPU::i8C, &CPU::i8D, &CPU::i8E, &CPU::i8F,
        &CPU::i90, &CPU::i91, &CPU::i92, &CPU::i93, &CPU::i94, &CPU::i95, &CPU::i96, &CPU::i97,
        &CPU::i98, &CPU::i99, &CPU::i9A, &CPU::i9B, &CPU::i9C, &CPU::i9D, &CPU::i9E, &CPU::i9F,
        &CPU::iA0, &CPU::iA1, &CPU::iA2, &CPU::iA3, &CPU::iA4, &CPU::iA5, &CPU::iA6, &CPU::iA7,
        &CPU::iA8, &CPU::iA9, &CPU::iAA, &CPU::iAB, &CPU::iAC, &CPU::iAD, &CPU::iAE, &CPU::iAF,
        &CPU::iB0, &CPU::iB1, &CPU::iB2, &CPU::iB3, &CPU::iB4, &CPU::iB5, &CPU::iB6, &CPU::iB7,
        &CPU::iB8, &CPU::iB9, &CPU::iBA, &CPU::iBB, &CPU::iBC, &CPU::iBD, &CPU::iBE, &CPU::iBF,
        &CPU::iC0, &CPU::iC1, &CPU::iC2, &CPU::iC3, &CPU::iC4, &CPU::iC5, &CPU::iC6, &CPU::iC7,
        &CPU::iC8, &CPU::iC9, &CPU::iCA, &CPU::iCB, &CPU::iCC, &CPU::iCD, &CPU::iCE, &CPU::iCF,
        &CPU::iD0, &CPU::iD1, &CPU::iD2, &CPU::iD3, &CPU::iD4, &CPU::iD5, &CPU::iD6, &CPU::iD7,
        &CPU::iD8, &CPU::iD9, &CPU::iDA, &CPU::iDB, &CPU::iDC, &CPU::iDD, &CPU::iDE, &CPU::iDF,
        &CPU::iE0, &CPU::iE1, &CPU::iE2, &CPU::iE3, &CPU::iE4, &CPU::iE5, &CPU::iE6, &CPU::iE7,
        &CPU::iE8, &CPU::iE9, &CPU::iEA, &CPU::iEB, &CPU::iEC, &CPU::iED, &CPU::iEE, &CPU::iEF,
        &CPU::iF0, &CPU::iF1, &CPU::iF2, &CPU::iF3, &CPU::iF4, &CPU::iF5, &CPU::iF6, &CPU::iF7,
        &CPU::iF8, &CPU::iF9, &CPU::iFA, &CPU::iFB, &CPU::iFC, &CPU::iFD, &CPU::iFE, &CPU::iFF
    };
    cycleCount = {
      //0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F
        7, 6, 0, 8, 3, 3, 5, 5, 3, 2, 2, 2, 4, 4, 6, 6, // 0
        2, 5, 0, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7, // 1
        6, 6, 0, 8, 3, 3, 5, 5, 4, 2, 2, 2, 4, 4, 6, 6, // 2
        2, 5, 0, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7, // 3
        6, 6, 0, 8, 3, 3, 5, 5, 3, 2, 2, 2, 3, 4, 6, 6, // 4
        2, 5, 0, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7, // 5
        6, 6, 0, 8, 3, 3, 5, 5, 4, 2, 2, 2, 5, 4, 6, 6, // 6
        2, 5, 0, 8, 4, 4, 6, 6, 2, 4, 2, 4, 4, 4, 7, 7, // 7
        2, 6, 2, 6, 3, 3, 3, 3, 2, 2, 2, 7, 4, 4, 4, 4, // 8
        2, 6, 0, 6, 4, 4, 4, 4, 2, 5, 2, 2, 5, 5, 5, 5, // 9
        2, 6, 2, 6, 3, 3, 3, 3, 2, 2, 2, 5, 4, 4, 4, 4, // A
        2, 5, 0, 5, 4, 4, 4, 4, 2, 4, 2, 4, 4, 4, 4, 4, // B
        2, 6, 2, 8, 3, 3, 5, 5, 2, 2, 2, 2, 4, 4, 6, 6, // C
        2, 5, 0, 8, 4, 4, 6, 6, 2, 4, 2, 7, 4, 4, 7, 7, // D
        2, 6, 2, 8, 3, 3, 5, 5, 2, 2, 2, 2, 4, 4, 6, 6, // E
        2, 5, 0, 8, 4, 4, 6, 6, 2, 4, 2, 4, 4, 4, 7, 7  // F
    };

    logger = std::ofstream("/tmp/nes.log", std::ios::trunc);
}

void CPU::cycle()
{
    if (opcounter > 0){
        cycleNum++;
        opcounter--;
    } else {
        Word oPC = PC;
        Byte A1 = getMemory(PC+1);
        Byte A2 = getMemory(PC+2);
        Byte code = getPC();
        char str[200];
        sprintf(str, "%-4X  %02X %02X %02X    A:%02X X:%02X Y:%02X P:%02X S:%02X  02:%02X 03:%02X CYC:%u\n",
                oPC, code, A1, A2, A, X, Y, P, S, getMemory(0x02), getMemory(0x03), cycleNum);
        opcounter = cycleCount[code];
        (this->*opcodes[code])();
        logger << str;
    }
}

void CPU::reset()
{
    S += 3;
    setInterruptFlag(true);
    setPC(0xFFFC);
    opcounter += 8;
}

void CPU::IRQ()
{
    P |= 52;
    setMemory(0x0100 + S, Byte((PC >> 8) & 0x00FF));
    setMemory(0x0100 + S - 1, Byte(PC & 0x00FF));
    setMemory(0x100 + S -2, P);
    S -= 3;
    setPC(0xFFFE);
    opcounter += 7;
}

void CPU::NMI()
{
    P |= 52;
    setMemory(0x0100 + S, Byte((PC >> 8) & 0x00FF));
    setMemory(0x0100 + S - 1, Byte(PC & 0x00FF));
    setMemory(0x100 + S -2, P);
    S -= 3;
    setPC(0xFFFA);
    opcounter += 8;
}

Byte CPU::IMM()
{
    return getPC();
}

Byte CPU::ZPI()
{
    Byte addr = getPC();
    return getMemory(addr);
}

Byte CPU::ZPX()
{
    return getMemory(ZPX_Addr());
}

Byte CPU::ZPY()
{
    return getMemory(ZPY_Addr());
}

Pointer CPU::ZPI_Addr()
{
    return getPC();
}

Pointer CPU::ZPX_Addr()
{
    return (getPC() + X) & 0x00FF;
}

Pointer CPU::ZPY_Addr()
{
    return (getPC() + Y) & 0x00FF;
}

Word CPU::ABS()
{
    Word addr = (Word)getPC() + ((Word)getPC() << 8);
    return getMemory(addr);
}

Word CPU::ABSX()
{
    return getMemory(ABSX_Addr());
}

Word CPU::ABSY()
{
    return getMemory(ABSY_Addr());
}

Pointer CPU::ABS_Addr()
{
    return (Word)getPC() + ((Word)getPC() << 8);
}

Pointer CPU::ABSX_Addr()
{
    Word low = getPC();
    Word high = getPC();
    Word addr = low + (high << 8) + X;
    if ((addr & 0xFF00) != (high << 8)){
        opcounter++;
    }
    return addr;
}

Pointer CPU::ABSY_Addr()
{
    Word low = getPC();
    Word high = getPC();
    Word addr = low + (high << 8) + Y;
    if ((addr & 0xFF00) != (high << 8)){
        opcounter++;
    }
    return addr;
}

Pointer CPU::IND()
{
    Word low = getPC();
    Word high = getPC();
    Pointer addr = low + (high >> 8);
    if (low == 0x00FF){
        return (getMemory(addr & 0xFF00) << 8) | getMemory(addr);
    } else {
        return (getMemory(addr + 1) << 8) | getMemory(addr);
    }
}

Word CPU::INDX()
{
    return getMemory(INDX_Addr());
}

Word CPU::INDY()
{
    return getMemory(INDY_Addr());
}

Pointer CPU::INDX_Addr()
{
    Word temp = getPC();
    Word low = getMemory((temp + (Word)X) & 0x00FF);
    Word high = getMemory((temp + (Word)X +1) & 0x00FF);

    return ((high << 8) | low);
}

Pointer CPU::INDY_Addr()
{
    Word temp = getPC();
    Word low = getMemory((temp + (Word)X) & 0x00FF);
    Word high = getMemory((temp + (Word)X +1) & 0x00FF);

    Pointer addr = (high << 8) | (low + Y);
    if ((addr & 0xFF00) != (high << 8)){
        opcounter++;
    }
    return addr;
}

void CPU::ADC(Word data)
{
    Word result = data + Word(A) + Word(carryFlag());
    setCarryFlag(result > 0xFF);
    setNegativeFlag(A & 0x80);
    setZeroFlag(!(result & 0x00FF));
    setOverflowFlag((~((Word)A ^ (Word)data) & ((Word)A ^ (Word)result)) & 0x0080);
    A = result & 0x00FF;
}

void CPU::AND(Byte data)
{
    setZeroFlag(!(A & data));
    setNegativeFlag((A & data) & 0x80);
}

void CPU::ASL(Pointer addr, bool useA)
{
    if (useA){
        setCarryFlag(A & 0x80);
        A <<= 1;
        A &= 0xFE;
    } else {
        Byte data = getMemory(addr);
        setCarryFlag(data & 0x80);
        data <<= 1;
        data &= 0xFE;
        setMemory(addr, data);
    }
}

void CPU::BCC()
{
    Byte rel = getPC();
    if (!carryFlag()){
        if ((PC & 0x00FF) + rel > 0xFF){
            opcounter++;
        }
        opcounter++;
        PC += rel;
    }
}

void CPU::BCS()
{
    Byte rel = getPC();
    if (carryFlag()){
        if ((PC & 0x00FF) + rel > 0xFF){
            opcounter++;
        }
        opcounter++;
        PC += rel;
    }
}

void CPU::BEQ()
{
    Byte rel = getPC();
    if (zeroFlag()){
        if ((PC & 0x00FF) + rel > 0xFF){
            opcounter++;
        }
        opcounter++;
        PC += rel;
    }
}

void CPU::BIT(Byte data)
{
    setZeroFlag(!(data & A));
    setOverflowFlag(0x40 & data);
    setNegativeFlag(0x80 & data);
}

void CPU::BMI()
{
    Byte rel = getPC();
    if (negativeFlag()){
        if ((PC & 0x00FF) + rel > 0xFF){
            opcounter++;
        }
        opcounter++;
        PC += rel;
    }
}

void CPU::BNE()
{
    Byte rel = getPC();
    if (!zeroFlag()){
        if ((PC & 0x00FF) + rel > 0xFF){
            opcounter++;
        }
        opcounter++;
        PC += rel;
    }
}

void CPU::BPL()
{
    Byte rel = getPC();
    if (!negativeFlag()){
        if ((PC & 0x00FF) + rel > 0xFF){
            opcounter++;
        }
        opcounter++;
        PC += rel;
    }
}

void CPU::BRK()
{
    setBreakFlag(true);
    setMemory(0x0100 + S, Byte((PC >> 8) & 0x00FF));
    setMemory(0x0100 + S - 1, Byte(PC & 0x00FF));
    setMemory(0x100 + S -2, P);
    S -= 3;
    setPC(0xFFFE);
}

void CPU::BVC()
{
    Byte rel = getPC();
    if (!overflowFlag()){
        if ((PC & 0x00FF) + rel > 0xFF){
            opcounter++;
        }
        opcounter++;
        PC = (((PC & 0x00FF) + rel) & 0x00FF) + (PC & 0xFF00);
    }
}

void CPU::BVS()
{
    Byte rel = getPC();
    if (overflowFlag()){
        if ((PC & 0x00FF) + rel > 0xFF){
            opcounter++;
        }
        opcounter++;
        PC = (((PC & 0x00FF) + rel) & 0x00FF) + (PC & 0xFF00);
    }
}

void CPU::CLC()
{
    setCarryFlag(false);
}

void CPU::CLD()
{
    setDecimalModeFlag(false);
}

void CPU::CLI()
{
    setInterruptFlag(false);
}

void CPU::CLV()
{
    setOverflowFlag(false);
}

void CPU::CMP(Byte data)
{
    setZeroFlag(A == data);
    setCarryFlag(A >= data);
    setNegativeFlag((A-data) & 0x0080);
}

void CPU::CPX(Byte data)
{
    setZeroFlag(X == data);
    setCarryFlag(X >= data);
    setNegativeFlag(data & 0x80);
}

void CPU::CPY(Byte data)
{
    setZeroFlag(Y == data);
    setCarryFlag(Y >= data);
    setNegativeFlag(data & 0x80);
}

void CPU::DEC(Pointer addr)
{
    Byte data = getMemory(addr);
    data--;
    setZeroFlag(!data);
    setNegativeFlag(data & 0x80);
    setMemory(addr, data);
}

void CPU::DEX()
{
    X--;
    setZeroFlag(!X);
    setNegativeFlag(X & 0x80);
}

void CPU::DEY()
{
    Y--;
    setZeroFlag(!Y);
    setNegativeFlag(Y & 0x80);
}

void CPU::EOR(Byte data)
{
    A ^= data;
    setZeroFlag(!A);
    setNegativeFlag(A & 0x80);
}

void CPU::INC(Pointer addr)
{
    Byte data = getMemory(addr);
    data++;
    setZeroFlag(!data);
    setNegativeFlag(data & 0x80);
    setMemory(addr, data);
}

void CPU::INX()
{
    X++;
    setZeroFlag(!X);
    setNegativeFlag(X & 0x80);
}

void CPU::INY()
{
    Y++;
    setZeroFlag(!Y);
    setNegativeFlag(Y & 0x80);
}

void CPU::JMP(Pointer addr)
{
    PC = addr;
}

void CPU::JSR(Pointer addr)
{
    push(PC-1);
    PC = addr;
}

void CPU::LDA(Byte data)
{
    A = data;
    setZeroFlag(!A);
    setNegativeFlag(A & 0x80);
}

void CPU::LDX(Byte data)
{
    X = data;
    setZeroFlag(!X);
    setNegativeFlag(X & 0x80);
}

void CPU::LDY(Byte data)
{
    Y = data;
    setZeroFlag(!Y);
    setNegativeFlag(Y & 0x80);
}

void CPU::LSR(Pointer addr, bool useA)
{
    if (useA){
        setCarryFlag(A & 0x01);
        A >>= 1;
    } else {
        Byte data = getMemory(addr);
        setCarryFlag(data & 0x01);
        data >>= 1;
        setMemory(addr, data);
    }
}

void CPU::ORA(Byte data)
{
    A |= data;
    setZeroFlag(!A);
    setNegativeFlag(A & 0x80);
}

void CPU::PHA()
{
    setMemory(0x0100 + S, A);
    S--;
}

void CPU::PHP()
{
    setMemory(0x0100 + S, P);
    S--;
}

void CPU::PLA()
{
    S++;
    A = getMemory(0x0100 + S);
    setZeroFlag(A == 0);
    setNegativeFlag(A & 0x80);
}

void CPU::PLP()
{
    S++;
    P = getMemory(0x0100 + S);
}

void CPU::ROL(Pointer addr, bool useA)
{
    if (useA){
        bool cb = A & 0x80;
        A = A << 1;
        if (carryFlag()){
            A |= 0x01;
        } else {
            A &= ~0x01;
        }
        setCarryFlag(cb);
    } else {
        Byte data = getMemory(addr);
        bool cb = data & 0x80;
        data = data << 1;
        if (carryFlag()){
            data |= 0x01;
        } else {
            data &= ~0x01;
        }
        setCarryFlag(cb);
        setMemory(addr, data);
    }
}

void CPU::ROR(Pointer addr, bool useA)
{
    if (useA){
        bool cb = A & 0x01;
        A = A >> 1;
        if (carryFlag()){
            A |= 0x80;
        } else {
            A &= ~0x80;
        }
        setCarryFlag(cb);
        setZeroFlag(!A);
        setNegativeFlag(A & 0x80);
    } else {
        Byte data = getMemory(addr);
        bool cb = data & 0x01;
        data = data >> 1;
        if (carryFlag()){
            data |= 0x80;
        } else {
            data &= ~0x80;
        }
        setCarryFlag(cb);
        setZeroFlag(!data);
        setNegativeFlag(data & 0x80);
        setMemory(addr, data);
    }
}

void CPU::RTI()
{
    S++;
    P = getMemory(0x0100 + S);
    S++;
    Word pcl = getMemory(0x0100+S);
    S++;
    Word pch = getMemory(0x0100+S) << 8;
    PC = pcl|pch;
}

void CPU::RTS()
{
    S++;
    Word pcl = getMemory(0x0100+S);
    S++;
    Word pch = ((Word)getMemory(0x0100+S)) << 8;
    PC = pcl|pch;
    PC++;
}

void CPU::SBC(Word data)
{
    Word temp = data ^ 0x00FF;
    Word result = temp + Word(A) + Word(carryFlag());
    setCarryFlag(result > 0xFF);
    setNegativeFlag(A & 0x80);
    setZeroFlag(!(result & 0x00FF));
    setOverflowFlag(((Word)A ^ result) & (temp ^ result) & 0x0080);
    A = result & 0x00FF;
}

void CPU::SEC()
{
    setCarryFlag(true);
}

void CPU::SED()
{
    setDecimalModeFlag(true);
}

void CPU::SEI()
{
    setInterruptFlag(true);
}

void CPU::STA(Pointer addr)
{
    setMemory(addr, A);
}

void CPU::STX(Pointer addr)
{
    setMemory(addr, X);
}

void CPU::STY(Pointer addr)
{
    setMemory(addr, Y);
}

void CPU::TAX()
{
    X = A;
    setZeroFlag(!X);
    setNegativeFlag(X & 0x80);
}

void CPU::TAY()
{
    Y = A;
    setZeroFlag(!Y);
    setNegativeFlag(Y & 0x80);
}

void CPU::TSX()
{
    X = S;
    setZeroFlag(!X);
    setNegativeFlag(X & 0x80);
}

void CPU::TXA()
{
    A = X;
    setZeroFlag(!A);
    setNegativeFlag(A & 0x80);
}

void CPU::TXS()
{
    X = S;
}

void CPU::TYA()
{
    A = Y;
    setZeroFlag(!A);
    setNegativeFlag(A & 0x80);
}

void CPU::KILL()
{
    reset();
}

void CPU::SAX(Pointer addr)
{
    setMemory(addr, A & X);
}

void CPU::DCP(Pointer addr)
{
    DEC(addr);
    CMP(getMemory(addr));
}

void CPU::ISC(Pointer addr)
{
    INC(addr);
    SBC(getMemory(addr));
}

void CPU::RLA(Pointer addr)
{
    ROL(addr);
    AND(getMemory(addr));
}

void CPU::RRA(Pointer addr)
{
    ROR(addr);
    ADC(getMemory(addr));
}

void CPU::SLO(Pointer addr)
{
    ASL(addr);
    ORA(getMemory(addr));
}

void CPU::SRE(Pointer addr)
{
    LSR(addr);
    EOR(getMemory(addr));
}

void CPU::ARR(Byte data)
{
    Byte temp = A & data;
    if (decimalModeFlag()){
        Byte A_high = temp >> 4;
        Byte A_low = temp & 15;
        setNegativeFlag(carryFlag());
        setZeroFlag(!(A = (temp >> 1) | (carryFlag() << 7)));
        setOverflowFlag((temp ^ A) & 64);
        if (A_low + (A_low & 1) > 5){
            A = (A & 0xF0) | ((A + 6) & 0xF);
        }
        Byte c = A_high + (A_high & 1);
        setCarryFlag(c);
        if (c > 5){
            A = (A + 0x60) & 0xFF;
        }
    } else {
        temp >>= 1;
        temp &= 0x8F & (carryFlag() << 7);
        setZeroFlag(!temp);
        setNegativeFlag(temp & 0x80);
        setCarryFlag(temp & 0x40);
        setOverflowFlag(((temp >> 4) ^ (temp >> 5)) & 0x01);
    }
    A = temp;
}

void CPU::XAA(Byte data)
{
    A = (A | getMemory(0xEE)) & X & data;
}

void CPU::SHA(Pointer addr)
{
    setMemory(addr, A & X & (Byte)((addr >> 8) + 1));
}

void CPU::SHX(Pointer addr)
{
    setMemory(addr, X & (Byte)((addr >> 8) + 1));
}

void CPU::SHY(Pointer addr)
{
    setMemory(addr, Y & (Byte)((addr >> 8) + 1));
}

void CPU::TAS(Pointer addr)
{
    S = A & X;
    setMemory(addr, S & ((addr >> 8)+1));
}

void CPU::LAX(Byte data)
{
    X = data;
    A = X;
    setZeroFlag(!A);
    setNegativeFlag(A & 0x80);
}

void CPU::LAS(Byte data)
{
    S = data & S;
    X = S;
    A = S;
}

void CPU::AXS(Byte data)
{
    X = (A & X) - data;
    // Carry flag
}

Byte CPU::getMemory(Pointer addr)
{
    Byte data = bus->getCPUMemory(addr);
    return data;
}

void CPU::setMemory(Pointer addr, Byte data)
{
    bus->setCPUMemory(addr, data);
}

void CPU::setPC(Word addr)
{
    Word pcl = getMemory(addr);
    Word pch = getMemory(addr+1);
    PC = (pch << 8) | pcl;
}

void CPU::push(Pointer addr)
{
    Byte pch = (addr >> 8) & 0x00FF;
    Byte pcl = addr & 0x00FF;
    setMemory(0x0100+S, pch);
    S--;
    setMemory(0x0100+S, pcl);
    S--;
}

Pointer CPU::pop()
{
    S++;
    Byte pcl = getMemory(0x0100+S);
    S++;
    Byte pch = getMemory(0x0100+S);
    return (pch << 8) + pcl;
}
