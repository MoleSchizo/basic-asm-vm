#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include "Instruction.h"
#include <vector>

class VirtualMachine {
public:
    VirtualMachine() : m_ip(0), m_acc(0), m_flag(false) {}

    void run(const std::vector<Instruction>& program) {
        while (m_ip < program.size()) {
            const auto& instruction = program[m_ip];
            switch (instruction.opcode) {
                case OpCode::HALT:
                    return;
                case OpCode::LOAD:
                    m_acc = instruction.operand;
                    break;
                case OpCode::ADD:
                    m_acc += instruction.operand;
                    break;
                case OpCode::SUB:
                    m_acc -= instruction.operand;
                    break;
                case OpCode::MUL:
                    m_acc *= instruction.operand;
                    break;
                case OpCode::DIV:
                    m_acc /= instruction.operand;
                    break;
            }
            ++m_ip;
        }
    }

    int getAccumulator() const { return m_acc; }

private:
    int m_ip;
    int m_acc;
    bool m_flag;
};

#endif
