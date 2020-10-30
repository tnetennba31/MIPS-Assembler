#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    PARSE_RTYPE, PARSE_ITYPE, PARSE_JTYPE, PARSE_JRTYPE, MEMTYPE, SHIFTY
} instr_type_t;

typedef enum {
    FMT_RTYPE, FMT_ITYPE, FMT_JTYPE
} encode_type_t;

typedef struct {
    char *mnemonic;
    instr_type_t type;
    encode_type_t etype;
    int opcode;
    int function;
} instr_t;

instr_t instrs[] = {
    { .mnemonic = "ADD", .type = PARSE_RTYPE, .etype = FMT_RTYPE,
        .opcode = 0, .function = 0x20},
    { .mnemonic = "ADDI", .type = PARSE_ITYPE, .etype = FMT_ITYPE,
        .opcode = 0x20, .function = 0},
};

#define NUM_INSTR ( sizeof(instrs) / sizeof(instr_t))


int find_opcode(const char *str, instr_t *instr)
{
    int i;
    for (i = 0; i < NUM_INSTR; i++) {
        if (strcmp(instrs[i].mnemonic, str) == 0) {
            *instr = instrs[i];
            return 0;
        }
    }
}

typedef struct {
    int last_state;
    instr_t instr;
    char *opcode;
    char *regs[3];
    char *immediate;
    char *shamt;
} parsed_t;

uint32_t format_rtype(parsed_t *parsed)
{
    int code = lookup_opcode(parsed->opcode);
    int rd = lookup_reg(parsed->regs[0]);
    int rs = lookup_reg(parsed->regs[1]);
    int rt = lookup_reg(parsed->regs[2]);
    int shamt = strtol(parsed->shamt, NULL, 0);
    int func = lookup_func(parsed->opcode);

    return code << 26 | rs << 21 | rt << 16 | rd << 11 | shamt << 5 | func;
}

void parse_string(const char *str, parsed_t *result)
{
    int i = 0;
    int state = 0;
    int start = 0;
    char *opcode = NULL;


    while ((str[i] != 0) && (state >= 0)) {

        char ch = str[i];
        switch(state) {
            case 0:
                if (str[i] == ' ') state = 0;
                else if (str[i] == '\t') state = 0;
                else if ((str[i] >= 'A') && (str[i] <= 'Z')) {
                    state = 1;
                    start = i;
                }
                else state = -1;
                break;

            // beginning of instruction
            case 1:
                if ((str[i] >= 'A') && (str[i] <= 'Z'))
                    state = 1;
                else if ((str[i] == ' ') || (str[i] == '\t')) {
                    state = 2;
                    result->opcode = malloc(i - start + 1);
                    strncpy(opcode, &str[start], (i - start));
                }
                else {
                    state = -1;
                }
                break;
            }

            i++;
        }

        if (state < 0) {
            printf("ERROR - Invalid instruction");
        }
        else {
            printf("OPCODE: %s \n", opcode);
        }
    }

    int main(int argc, char **argv)
    {
    }
}