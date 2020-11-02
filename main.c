#include "main.h"

int main() {

    char input[160];
    fgets(input, 160, stdin);

    char *instruction = normalize(input);

    parsed_t *parsed_ptr = malloc(sizeof(parsed_t));
    
    parse_string(parsed_ptr, instruction);

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

    char *string = NULL;

    hexreturn(formatted_instr, string);
    printf("%s\n", string);

done:
    free(parsed_ptr);
    return 0;
}
