#include "registers.h"

char *registers[] = {"$zero", "$at", "$v0", "$v1", "$a0", "$a1", 
    "$a2", "$a3", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", 
    "$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", 
    "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$fp", "$ra"};

int decode_register(char reg_str[]) {
    int reg_num = -1;

    for (int i = 0; i < 32; i++) {
        if (strcmp(reg_str, registers[i]) == 0) {
            reg_num = i;
            i = 32;
        }
    }

    return reg_num;
}
