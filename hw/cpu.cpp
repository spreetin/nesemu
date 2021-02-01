#include "cpu.h"
#include "bus.h"

CPU::CPU(Bus *bus)
    : bus(bus)
{
    A = 0;
    X = 0;
    Y = 0;
    P = 0x34;
    S = 0xFD;
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
        7, 6, 0, 0, 3, 3, 5, 0, 3, 2, 2, 0, 4, 4, 6, 0, // 0
        2, 5, 0, 0, 4, 4, 6, 0, 2, 4, 2, 0, 0, 4, 7, 0, // 1
        6, 6, 0, 0, 3, 3, 5, 0, 4, 2, 2, 0, 4, 4, 6, 0, // 2
        2, 5, 0, 0, 0, 4, 6, 0, 2, 4, 2, 0, 0, 4, 7, 0, // 3
        6, 6, 0, 0, 0, 3, 5, 0, 3, 2, 2, 0, 3, 4, 6, 0, // 4
        2, 5, 0, 0, 0, 4, 6, 0, 2, 4, 2, 0, 0, 4, 7, 0, // 5
        6, 6, 0, 0, 0, 3, 5, 0, 4, 2, 2, 0, 5, 4, 6, 0, // 6
        2, 5, 0, 0, 0, 4, 6, 0, 2, 4, 2, 0, 0, 4, 7, 0, // 7
        0, 6, 0, 0, 3, 3, 3, 0, 2, 0, 2, 0, 4, 4, 4, 4, // 8
        2, 6, 0, 0, 4, 4, 4, 0, 2, 5, 2, 0, 0, 5, 0, 0, // 9
        2, 6, 2, 0, 3, 3, 3, 0, 2, 2, 2, 0, 4, 4, 4, 0, // A
        2, 5, 0, 0, 4, 4, 4, 0, 0, 4, 2, 0, 4, 4, 4, 0, // B
        2, 6, 0, 0, 3, 3, 5, 0, 2, 2, 2, 0, 4, 4, 6, 0, // C
        2, 5, 0, 0, 0, 4, 6, 0, 2, 4, 2, 0, 0, 4, 7, 0, // D
        2, 6, 0, 0, 3, 3, 5, 0, 2, 2, 2, 0, 4, 4, 6, 0, // E
        2, 5, 0, 0, 0, 4, 6, 0, 2, 4, 2, 0, 0, 4, 7, 0  // F
    };
}

void CPU::cycle()
{
    if (opcounter){
        opcounter--;
    } else {
        Byte code = getPC();
        (this->*opcodes[code])();
        counter += cycleCount[code];
        opcounter = cycleCount[code]-1;
    }
}

void CPU::reset()
{
    S += 3;
    setInterruptFlag(true);
    setPC(0xFFFC);
    counter += 8;
}

void CPU::IRQ()
{
    P |= 52;
    setMemory(0x0100 + S, Byte((PC >> 8) & 0x00FF));
    setMemory(0x0100 + S - 1, Byte(PC & 0x00FF));
    setMemory(0x100 + S -2, P);
    S -= 3;
    setPC(0xFFFE);
    counter += 7;
}

void CPU::NMI()
{
    P |= 52;
    setMemory(0x0100 + S, Byte((PC >> 8) & 0x00FF));
    setMemory(0x0100 + S - 1, Byte(PC & 0x00FF));
    setMemory(0x100 + S -2, P);
    S -= 3;
    setPC(0xFFFA);
    counter += 8;
}

void CPU::i03()
{

}

void CPU::i07()
{

}

void CPU::i0B()
{

}

void CPU::i0F()
{

}

void CPU::i11()
{

}

void CPU::i13()
{

}

void CPU::i17()
{

}

void CPU::i19()
{

}

void CPU::i1B()
{

}

void CPU::i1C()
{

}

void CPU::i1D()
{

}

void CPU::i1F()
{

}

void CPU::i23()
{

}

void CPU::i27()
{

}

void CPU::i2B()
{

}

void CPU::i2F()
{

}

void CPU::i31()
{

}

void CPU::i33()
{

}

void CPU::i34()
{

}

void CPU::i37()
{

}

void CPU::i39()
{

}

void CPU::i3B()
{

}

void CPU::i3C()
{

}

void CPU::i3D()
{

}

void CPU::i3F()
{

}

void CPU::i43()
{

}

void CPU::i44()
{

}

void CPU::i47()
{

}

void CPU::i4B()
{

}

void CPU::i4F()
{

}

void CPU::i53()
{

}

void CPU::i54()
{

}

void CPU::i57()
{

}

void CPU::i59()
{

}

void CPU::i5B()
{

}

void CPU::i5C()
{

}

void CPU::i5D()
{

}

void CPU::i5F()
{

}

void CPU::i63()
{

}

void CPU::i64()
{

}

void CPU::i67()
{

}

void CPU::i6B()
{

}

void CPU::i6F()
{

}

void CPU::i71()
{

}

void CPU::i73()
{

}

void CPU::i74()
{

}

void CPU::i77()
{

}

void CPU::i79()
{

}

void CPU::i7B()
{

}

void CPU::i7C()
{

}

void CPU::i7D()
{

}

void CPU::i7F()
{

}

void CPU::i80()
{

}

void CPU::i82()
{

}

void CPU::i83()
{

}

void CPU::i87()
{

}

void CPU::i89()
{

}

void CPU::i8B()
{

}

void CPU::i93()
{

}

void CPU::i97()
{

}

void CPU::i9B()
{

}

void CPU::i9C()
{

}

void CPU::i9E()
{

}

void CPU::i9F()
{

}

void CPU::iA3()
{

}

void CPU::iA7()
{

}

void CPU::iAB()
{

}

void CPU::iAF()
{

}

void CPU::iB1()
{

}

void CPU::iB3()
{

}

void CPU::iB7()
{

}

void CPU::iB8()
{

}

void CPU::iB9()
{

}

void CPU::iBB()
{

}

void CPU::iBC()
{

}

void CPU::iBD()
{

}

void CPU::iBE()
{

}

void CPU::iBF()
{

}

void CPU::iC2()
{

}

void CPU::iC3()
{

}

void CPU::iC7()
{

}

void CPU::iCB()
{

}

void CPU::iCF()
{

}

void CPU::iD1()
{

}

void CPU::iD3()
{

}

void CPU::iD4()
{

}

void CPU::iD7()
{

}

void CPU::iDB()
{

}

void CPU::iDC()
{

}

void CPU::iDF()
{

}

void CPU::iE2()
{

}

void CPU::iE3()
{

}

void CPU::iE7()
{

}

void CPU::iEB()
{

}

void CPU::iEF()
{

}

void CPU::iF1()
{

}

void CPU::iF3()
{

}

void CPU::iF4()
{

}

void CPU::iF7()
{

}

void CPU::iF9()
{

}

void CPU::iFB()
{

}

void CPU::iFC()
{

}

void CPU::iFD()
{

}

void CPU::iFF()
{

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
    Byte addr = getPC();
    return getMemory((addr + X) & 0x00FF);
}

Byte CPU::ZPY()
{
    Byte addr = getPC();
    return getMemory((addr + Y) & 0x00FF);
}

Word CPU::ABS()
{
    Word addr = getPC() + ((Word)getPC() >> 8);
    return getMemory(addr);
}

Word CPU::ABSX()
{
    Word addr = getPC() + ((Word)getPC() >> 8);
    return getMemory(addr+X);
}

Word CPU::ABSY()
{
    Word addr = getPC() + ((Word)getPC() >> 8);
    return getMemory(addr+Y);
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

}

Word CPU::INDY()
{

}

Pointer CPU::INDX_Addr()
{

}

Pointer CPU::INDY_Addr()
{

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
            counter++;
        }
        counter++;
        PC += rel;
    }
}

void CPU::BCS()
{
    Byte rel = getPC();
    if (carryFlag()){
        if ((PC & 0x00FF) + rel > 0xFF){
            counter++;
        }
        counter++;
        PC += rel;
    }
}

void CPU::BEQ()
{
    Byte rel = getPC();
    if (zeroFlag()){
        if ((PC & 0x00FF) + rel > 0xFF){
            counter++;
        }
        counter++;
        PC += rel;
    }
}

void CPU::BIT(Byte data)
{
    setZeroFlag(data & A);
    data = data >> 6;
    setOverflowFlag(1 & data);
    setNegativeFlag(2 & data);
}

void CPU::BMI()
{
    Byte rel = getPC();
    if (negativeFlag()){
        if ((PC & 0x00FF) + rel > 0xFF){
            counter++;
        }
        counter++;
        PC += rel;
    }
}

void CPU::BNE()
{
    Byte rel = getPC();
    if (!zeroFlag()){
        if ((PC & 0x00FF) + rel > 0xFF){
            counter++;
        }
        counter++;
        PC += rel;
    }
}

void CPU::BPL()
{
    Byte rel = getPC();
    if (!negativeFlag()){
        if ((PC & 0x00FF) + rel > 0xFF){
            counter++;
        }
        counter++;
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
            counter++;
        }
        counter++;
        PC += rel;
    }
}

void CPU::BVS()
{
    Byte rel = getPC();
    if (overflowFlag()){
        if ((PC & 0x00FF) + rel > 0xFF){
            counter++;
        }
        counter++;
        PC += rel;
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
    push(PC);
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
    setMemory(0x100 + S, P);
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
        setMemory(addr, data);
    }
}

void CPU::RTI()
{
    S++;
    P = getMemory(0x0100 + S + 1);
    setPC(0x0100+S+2);
    S += 3;
}

void CPU::RTS()
{
    setPC(0x0100+S+1);
    S += 2;
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

}

void CPU::SAX(Pointer addr)
{
    setMemory(addr, A & X);
}

Byte CPU::getMemory(Pointer addr, bool *crossedBorder)
{
    Byte data = bus->getMemory(addr);
    return data;
}

void CPU::setMemory(Pointer addr, Byte data)
{
    bus->setMemory(addr, data);
}

void CPU::setPC(Word addr)
{
    Word pcl = getMemory(addr);
    Word pch = getMemory(addr+1);
    PC = (pch << 8) | pcl;
}

void CPU::push(Pointer addr)
{
    Byte pch = (addr << 8) & 0x00FF;
    Byte pcl = addr & 0x00FF;
    setMemory(0x0100+S, pch);
    S--;
    setMemory(0x0100+S, pcl);
    S--;
}

Pointer CPU::pop()
{

}
