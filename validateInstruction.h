#include "project.h"

instr_t_pointer validate_instruction(char str[]);

struct instr_t instrs[] = {
    {.mnemonic = "ADD", .type = PARSE_RTYPE, .etype = FMT_RTYPE, .opcode = 0, .function = 0x20},
    {.mnemonic = "ADDI", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x08},
    {.mnemonic = "ADDIU", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x09},
    {.mnemonic = "ADDU", .type = PARSE_RTYPE, .etype = FMT_RTYPE, .opcode = 0, .function = 0x21},
    {.mnemonic = "AND", .type = PARSE_RTYPE, .etype = FMT_RTYPE, .opcode = 0, .function = 0x24},
    {.mnemonic = "ANDI", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x0C},
    {.mnemonic = "BEQ", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x04},
    {.mnemonic = "BNE", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x05},
    {.mnemonic = "J", .type = PARSE_JTYPE, .etype = FMT_JTYPE, .opcode = 0x02},
    {.mnemonic = "JAL", .type = PARSE_JTYPE, .etype = FMT_JTYPE, .opcode = 0x03},
    {.mnemonic = "JR", .type = PARSE_JRTYPE, .etype = FMT_RTYPE, .opcode = 0, .function = 0x08},
    {.mnemonic = "LBU", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x24},
    {.mnemonic = "LHU", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x25},
    {.mnemonic = "LL", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x30},
    {.mnemonic = "LUI", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x0F},
    {.mnemonic = "LW", .type = MEMTYPE, .etype = FMT_ITYPE, .opcode = 0x23},
    {.mnemonic = "NOR", .type = PARSE_RTYPE, .etype = FMT_RTYPE, .opcode = 0, .function = 0x27},
    {.mnemonic = "OR", .type = PARSE_RTYPE, .etype = FMT_RTYPE, .opcode = 0, .function = 0x25},
    {.mnemonic = "ORI", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x0D},
    {.mnemonic = "SLT", .type = PARSE_RTYPE, .etype = FMT_RTYPE, .opcode = 0, .function = 0x2A},
    {.mnemonic = "SLTI", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x0A},
    {.mnemonic = "SLTIU", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x0B},
    {.mnemonic = "SLTU", .type = PARSE_RTYPE, .etype = FMT_RTYPE, .opcode = 0, .function = 0x2B},
    {.mnemonic = "SLL", .type = SHIFTY, .etype = FMT_RTYPE, .opcode = 0, .function = 0x00},
    {.mnemonic = "SRL", .type = SHIFTY, .etype = FMT_RTYPE, .opcode = 0, .function = 0x02},
    {.mnemonic = "SB", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x28},
    {.mnemonic = "SC", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x38},
    {.mnemonic = "SH", .type = PARSE_ITYPE, .etype = FMT_ITYPE, .opcode = 0x29},
    {.mnemonic = "SW", .type = MEMTYPE, .etype = FMT_ITYPE, .opcode = 0x2B},
    {.mnemonic = "SUB", .type = PARSE_RTYPE, .etype = FMT_RTYPE, .opcode = 0, .function = 0x22},
    {.mnemonic = "SUBU", .type = PARSE_RTYPE, .etype = FMT_RTYPE, .opcode = 0, .function = 0x23}
};
