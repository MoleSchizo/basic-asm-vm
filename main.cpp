#include "VM.h"
#include "Assembler.h"
#include <iostream>

int main() {
    Assembler assembler;

    std::string code = "load 5\n"
                       "add 3\n"
                       "mul 2\n"
                       "halt\n";

    auto program = assembler.assemble(code);

    VirtualMachine vm;
    vm.run(program);

    std::cout << vm.getAccumulator() << '\n';

    return 0;
}
