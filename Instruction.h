#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>

enum class OpCode {
    HALT,
    LOAD,
    ADD,
    SUB,
    MUL,
    DIV
};

struct Instruction {
    OpCode opcode;
    int operand;
};

#endif
