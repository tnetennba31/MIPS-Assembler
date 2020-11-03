#include "format_instructions.h"

uint32_t format_rtype(parsed_t *parsed)
{
    int code = parsed->opcode;
    int rd = parsed->regs[0];
    int rs = parsed->regs[1];
    int rt = parsed->regs[2];
    int shamt = parsed->shamt;
    int func = parsed->func;

    return code << 26 | rs << 21 | rt << 16 | rd << 11 | shamt << 5 | func;
}

uint32_t format_itype(parsed_t *parsed)
{
    int code = parsed->opcode;
    int rt = parsed->regs[0];
    int rs = parsed->regs[1];
    int imm = parsed->immediate;

    return code << 26 | rs << 21 | rt << 16 | imm;
}

uint32_t format_jtype(parsed_t *parsed)
{
    int code = parsed->opcode;
    int addr = parsed->immediate;

    return code << 26 | addr;
}
