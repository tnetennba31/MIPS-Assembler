#include <stdbool.h>
#include "parseString.h"

parsed_t *parse_string(char *str)
{
	parsed_t result;
	
	char *mnemonic = strtok(str, ",");
	char *remainder = strtok(NULL, "\0");

	instr_t_pointer instr = validate_instruction(mnemonic);

	if (strcmp(instr->mnemonic, "invalid")) {
        printf("ERROR - INVALID INSTRUCTION\n");
    }

	result.mnemonic = instr->mnemonic;
	result.etype = instr->etype;
	result.opcode = instr->opcode;
	result.func = instr->function;

	bool failed = false;

	switch (instr->type) {
        case PARSE_RTYPE:
            failed = parseR(remainder, &result);
            break;
        case PARSE_ITYPE:
            failed = parseI(remainder, &result);
            break;
        case PARSE_JTYPE:
            failed = parseJ(remainder, &result);
            break;
        case PARSE_JRTYPE:
            failed = parseJR(remainder, &result);
            break;
        case MEMTYPE:
            failed = parseMem(remainder, &result);
            break;
        case SHIFTY:
            failed = parseShifty(remainder, &result);
    }

	if (failed) {
        printf("ERROR - INVALID REGISTER\n");
		result.mnemonic = "invalid";
    }

	return &result;
}

bool parseR(char *str, parsed_t *result) {
	result->regs[0] = decode_register(strtok(str, ","));
	result->regs[1] = decode_register(strtok(NULL, ","));
	result->regs[2] = decode_register(strtok(NULL, ","));

	result->shamt = 0;

	if(result->regs[0] == -1 || result->regs[1] == -1 || result->regs[2] == -1) return true;
	else return false;
}

bool parseI(char *str, parsed_t *result) {
	result->regs[0] = decode_register(strtok(str, ","));
	result->regs[1] = decode_register(strtok(NULL, ","));
	result->immediate = atoi(strtok(NULL, ","));

	if(result->regs[0] == -1 || result->regs[1] == -1) return true;
	else return false;
}

bool parseJ(char *str, parsed_t *result) {
	result->immediate = atoi(str);

	return false;
}

bool parseJR(char *str, parsed_t *result) {
	result->regs[0] = decode_register(strtok(str, ","));

	result->shamt = 0;

	if(result->regs[0] == -1) return true;
	else return false;
}

bool parseMem(char *str, parsed_t *result) {
	result->regs[0] = decode_register(strtok(str, ","));
	result->immediate = atoi(strtok(NULL, ","));
	result->regs[1] = decode_register(strtok(NULL, ","));

	if(result->regs[0] == -1 || result->regs[1] == -1) return true;
	else return false;
}

bool parseShifty(char *str, parsed_t *result) {
	result->regs[0] = decode_register(strtok(str, ","));
	result->regs[1] = decode_register(strtok(NULL, ","));
	result->shamt = atoi(strtok(NULL, ","));

	if(result->regs[0] == -1 || result->regs[1] == -1) return true;
	else return false;
}
