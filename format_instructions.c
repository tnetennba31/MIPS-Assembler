#include "format_instructions.h"

uint32_t format_rtype(parsed_t *parsed)
{
    int code = lookup_opcode(parsed->opcode);
    int rd = decode_register(parsed->regs[0]);
    int rs = decode_register(parsed->regs[1]);
    int rt = decode_register(parsed->regs[2]);
    int shamt = strtol(parsed->shamt, NULL, 0);
    int func = lookup_func(parsed->opcode);

    return code << 26 | rs << 21 | rt << 16 | rd << 11 | shamt << 5 | func;
}