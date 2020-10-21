typedef struct r_type {
    unsigned int opcode = 0b000000;
    unsigned int rs:5;
    unsigned int rt:5;
    unsigned int rd:5;
    unsigned int shamt:5;
    unsigned int funct:6;
} r_type_instruction;

typedef struct i_type {
    unsigned int opcode:6;
    unsigned int rs:6;
    unsigned int rt:6;
    unsigned int imm:16;
} i_type_instruction;

typedef struct j_type {
    unsigned int opcode:6;
    unsigned int address:26;
} j_type_instruction;