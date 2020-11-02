#include "parseString.h"

void parse_string(parsed_t *p, char *str)
{
	
	char *mnemonic = strtok(str, ",");
	char *remainder = strtok(NULL, "\0");

	instr_t_pointer instr = (instr_t_pointer) malloc(sizeof(struct instr_t));

	validate_instruction(mnemonic, instr);

	if (strcmp(instr->mnemonic, "invalid")) {
        printf("ERROR - INVALID INSTRUCTION\n");
    }

	p->mnemonic = instr->mnemonic;
	p->etype = instr->etype;
	p->opcode = instr->opcode;
	p->func = instr->function;

	free(instr);

	bool failed = false;

	switch (instr->type) {
        case PARSE_RTYPE:
            failed = parseR(remainder, p);
            break;
        case PARSE_ITYPE:
            failed = parseI(remainder, p);
 	    break;
        case PARSE_JTYPE:
            failed = parseJ(remainder, p);
            break;
        case PARSE_JRTYPE:
            failed = parseJR(remainder, p);
            break;
        case MEMTYPE:
            failed = parseMem(remainder, p);
            break;
        case SHIFTY:
            failed = parseShifty(remainder, p);
    }

	if (failed) {
        printf("ERROR - INVALID REGISTER\n");
		p->mnemonic = "invalid";
    }

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
