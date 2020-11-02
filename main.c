#include "main.h"

int main() {

    char* input;
    fgets(input, 160, stdin);

    char *instruction = normalize(input);

    char *mnemonic = strtok(instruction, ",");

    parsed_t *parsed_ptr = parse_string(instruction);

    if (strcmp(parsed_ptr->mnemonic, "invalid")) {
        goto done;
    }

    uint32_t formatted_instr;
    
    switch (parsed_ptr->etype) {
        case FMT_RTYPE:
            formatted_instr = format_rtype(parsed_ptr);
            break;
        case FMT_ITYPE:
            formatted_instr = format_itype(parsed_ptr);
            break;
        case FMT_JTYPE:
            formatted_instr = format_jtype(parsed_ptr);
    }

    printf("%d", hexreturn(formatted_instr));

done:
    return 0;
}
