#include <string.h>
#include "validateInstruction.h"

instr_t_pointer validate_instruction(char str[]) {
    struct instr_t result;
    instr_t_pointer ptr = &result;
    int len = sizeof(instrs)/sizeof(instrs[0]);
    
    for (int i = 0; i < len; i++) {
        if (strcasecmp(instrs[i].mnemonic, str) == 0) {
            result = instrs[i];
            break;
        }
        
        // If loop doesn't break by this point and reaches
        // this if statement, the mnemonic will be set to
        //"invalid" to indicate that the instruction is invalid.
        if (i == len - 1) {
            result.mnemonic = "invalid";
        }
    }
    
    return ptr;
}