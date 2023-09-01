#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "Instruction.h"
#include <vector>
#include <map>
#include <string>

class Assembler {
public:
    std::vector<Instruction> assemble(const std::string& code) {
        std::vector<Instruction> program;

        std::map<std::string, OpCode> opcodes{
            {"halt", OpCode::HALT},
            {"load", OpCode::LOAD},
            {"add", OpCode::ADD},
            {"sub", OpCode::SUB},
            {"mul", OpCode::MUL},
            {"div", OpCode::DIV}
        };

        size_t pos = 0;
        while (pos < code.size()) {
            size_t end = code.find('\n', pos);
            if (end == std::string::npos) {
                end = code.size();
            }

            std::string line = code.substr(pos, end - pos);
            size_t space = line.find(' ');
            std::string mnemonic = line.substr(0, space);

            Instruction instruction{opcodes[mnemonic], 0};
            if (space != std::string::npos) {
                instruction.operand = std::stoi(line.substr(space + 1));
            }

            program.push_back(instruction);

            pos = end + 1;
        }

        return program;
    }
};

#endif
