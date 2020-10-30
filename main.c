#include "main.h"

int main() {

    // read in a line of stuff -> input

    char *instruction = normalize(input);

    char *mnemonic = parse_string(instruction); // TODO - Yong returns the mnemonic (up til first comma)

    instr_t instr = validate_instruction(mnemonic);    // TODO - Nicholas returns the instruction as an instr_t struct

    if (instr == null) {
        printf("ERROR - INVALID INSTRUCTION\n");
        goto done;
    }

    typedef enum {
        PARSE_RTYPE, PARSE_ITYPE, PARSE_JTYPE, PARSE_JRTYPE, MEMTYPE, SHIFTY
    } instr_type_t;

    uint32_t formatted_instr;
    
    switch (instr.type) {
        case PARSE_RTYPE:
            formatted_instr = format_rtype();
            break;
        case PARSE_ITYPE:
            formatted_instr = format_itype();
            break;
        case PARSE_JTYPE:
            formatted_instr = format_jtype();
            break;
        case PARSE_JRTYPE:
            formatted_instr = format_jrtype();
            break;
        case MEMTYPE:
            formatted_instr = format_memtype();
            break;
        case SHIFTY:
            formatted_instr = format_shifty();
    }

    if (formatted_instr == null) {
        printf("ERROR - INVALID REGISTER\n");
        goto done;
    }

    printf("%d", converttohex(formatted_instr));

done:
    return 0;
}