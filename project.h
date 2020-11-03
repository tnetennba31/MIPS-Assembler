#ifndef _PROJECT_H
#define _PROJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <strings.h>

#define NUM_INSTR ( sizeof(instrs) / sizeof(struct instr_t))

typedef enum {
    FMT_RTYPE, FMT_ITYPE, FMT_JTYPE
} encode_type_t;

typedef enum {
    PARSE_RTYPE, PARSE_ITYPE, PARSE_JTYPE, PARSE_JRTYPE, MEMTYPE, SHIFTY
} instr_type_t;

typedef struct instr_t {
    char *mnemonic;
    instr_type_t type;
    encode_type_t etype;
    int opcode;
    int function;
} *instr_t_pointer;

typedef struct {
    char *mnemonic;
    encode_type_t etype;
    int opcode;
    int regs[3];
    int immediate;
    int shamt;
    int func;
} parsed_t;

#endif
