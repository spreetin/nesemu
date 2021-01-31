#include "cpu.h"

CPU::CPU()
{

}

void CPU::cycle()
{
    Byte code = getMemory(PC);
    PC++;
}

void CPU::i00()
{

}

void CPU::ADC(Pointer &addr, AddressingModes mode)
{

}

void CPU::AND(Pointer &addr, AddressingModes mode)
{

}

void CPU::ASL(Pointer &addr, AddressingModes mode)
{

}

void CPU::BCC(Pointer &addr, AddressingModes mode)
{

}

void CPU::BCS(Pointer &addr, AddressingModes mode)
{

}

void CPU::BEQ(Pointer &addr, AddressingModes mode)
{

}

void CPU::BIT(Pointer &addr, AddressingModes mode)
{
    Byte data = getMemory(addr);
    setZeroFlag(data & A);
    data = data >> 6;
    setOverflowFlag(1 & data);
    setNegativeFlag(2 & data);
    if (mode == ZeroPage){
        counter += 3;
    } else if (mode == Absolute){
        counter += 4;
    }
}

void CPU::BMI(Pointer &addr, AddressingModes mode)
{

}

void CPU::BNE(Pointer &addr, AddressingModes mode)
{

}

void CPU::BPL(Pointer &addr, AddressingModes mode)
{

}

void CPU::BRK(Pointer &addr, AddressingModes mode)
{

}

void CPU::BVC(Pointer &addr, AddressingModes mode)
{

}

void CPU::BVS(Pointer &addr, AddressingModes mode)
{

}

void CPU::CLC(Pointer &addr, AddressingModes mode)
{
    setCarryFlag(false);
    counter += 2;
}

void CPU::CLD(Pointer &addr, AddressingModes mode)
{
    setDecimalModeFlag(false);
    counter += 2;
}

void CPU::CLI(Pointer &addr, AddressingModes mode)
{
    setInterruptFlag(false);
    counter += 2;
}

void CPU::CLV(Pointer &addr, AddressingModes mode)
{
    setOverflowFlag(false);
    counter += 2;
}

void CPU::CMP(Pointer &addr, AddressingModes mode)
{

}

void CPU::CPX(Pointer &addr, AddressingModes mode)
{

}

void CPU::CPY(Pointer &addr, AddressingModes mode)
{

}

void CPU::DEC(Pointer &addr, AddressingModes mode)
{

}

void CPU::DEX(Pointer &addr, AddressingModes mode)
{

}

void CPU::DEY(Pointer &addr, AddressingModes mode)
{

}

void CPU::EOR(Pointer &addr, AddressingModes mode)
{

}

void CPU::INC(Pointer &addr, AddressingModes mode)
{

}

void CPU::INX(Pointer &addr, AddressingModes mode)
{

}

void CPU::INY(Pointer &addr, AddressingModes mode)
{

}

void CPU::JMP(Pointer &addr, AddressingModes mode)
{

}

void CPU::JSR(Pointer &addr, AddressingModes mode)
{

}

void CPU::LDA(Pointer &addr, AddressingModes mode)
{

}

void CPU::LDX(Pointer &addr, AddressingModes mode)
{

}

void CPU::LDY(Pointer &addr, AddressingModes mode)
{

}

void CPU::LSR(Pointer &addr, AddressingModes mode)
{

}

void CPU::NOP(Pointer &addr, AddressingModes mode)
{

}

void CPU::ORA(Pointer &addr, AddressingModes mode)
{

}

void CPU::PHA(Pointer &addr, AddressingModes mode)
{

}

void CPU::PHP(Pointer &addr, AddressingModes mode)
{

}

void CPU::PLA(Pointer &addr, AddressingModes mode)
{

}

void CPU::PLP(Pointer &addr, AddressingModes mode)
{

}

void CPU::ROL(Pointer &addr, AddressingModes mode)
{

}

void CPU::ROR(Pointer &addr, AddressingModes mode)
{

}

void CPU::RTI(Pointer &addr, AddressingModes mode)
{

}

void CPU::RTS(Pointer &addr, AddressingModes mode)
{

}

void CPU::SBC(Pointer &addr, AddressingModes mode)
{

}

void CPU::SEC(Pointer &addr, AddressingModes mode)
{

}

void CPU::SED(Pointer &addr, AddressingModes mode)
{

}

void CPU::SEI(Pointer &addr, AddressingModes mode)
{

}

void CPU::STA(Pointer &addr, AddressingModes mode)
{

}

void CPU::STX(Pointer &addr, AddressingModes mode)
{

}

void CPU::STY(Pointer &addr, AddressingModes mode)
{

}

void CPU::TAX(Pointer &addr, AddressingModes mode)
{

}

void CPU::TAY(Pointer &addr, AddressingModes mode)
{

}

void CPU::TSX(Pointer &addr, AddressingModes mode)
{

}

void CPU::TXA(Pointer &addr, AddressingModes mode)
{

}

void CPU::TXS(Pointer &addr, AddressingModes mode)
{

}

void CPU::TYA(Pointer &addr, AddressingModes mode)
{

}

Byte CPU::getMemory(Pointer &addr, bool *crossedBorder)
{

}

void CPU::setMemory(Pointer &addr, Byte &data)
{

}
