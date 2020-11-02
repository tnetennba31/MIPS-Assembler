#include "registers.h"

int decode_register(char reg_str[]) {
    int reg_num = -1;

    for (int i = 0; i < 32; i++) {
        if (strcmp(reg_str, regs[i]) == 0) {
            reg_num = i;
            i = 32;
        }
    }

    return reg_num;
}