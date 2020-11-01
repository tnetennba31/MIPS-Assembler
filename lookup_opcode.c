#include "lookup_opcode.h"

int lookup_opcode(const char *str, struct instr_t *instr)
{
    int i;
    for (i = 0; i < NUM_INSTR; i++) {
        if (strcmp(instrs[i].mnemonic, str) == 0) {
            *instr = instrs[i];
            return 0;
        }
    }
}