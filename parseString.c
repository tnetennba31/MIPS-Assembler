#include "parseString.h"
#include <math.h>

int get_num(char *number);

void parse_string(parsed_t *p, char *str)
{
	
	char *mnemonic = strtok(str, ",");
	char *remainder = strtok(NULL, "\n");

	instr_t_pointer instr = malloc(sizeof(struct instr_t));

	validate_instruction(mnemonic, instr);

	if (strcmp(instr->mnemonic, "invalid") == 0) {
        printf("ERROR - INVALID INSTRUCTION\n");
    }

	p->mnemonic = instr->mnemonic;
	p->etype = instr->etype;
	p->opcode = instr->opcode;
	p->func = instr->function;

	 printf("P is %d instr is %d ", p->func, instr->function);

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

	free(instr);

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
	char *ptr = strtok(NULL, ",");
	char *ptr2 = malloc(sizeof(char *));
	strcpy(ptr2, ptr);
	result->immediate = get_num(ptr2);
	printf("return is %d %x\n", result->immediate, result->immediate);
	if(result->regs[0] == -1 || result->regs[1] == -1) return true;
	else return false;
}

bool parseJ(char *str, parsed_t *result) {	
	char *ptr = malloc(sizeof(char *));
	strcpy(ptr, str);
	result->immediate = get_num(ptr);
	printf("return is %d %x\n", result->immediate, result->immediate);
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


int get_num(char *number)
{
    int sum = 0;
    int dig, base, offset;

    if (strncmp(number, "0x", 2) == 0) {
	char *cpy = malloc(sizeof(char *));
	strcpy(cpy, number);
	strtok(cpy, "x");
	number = strtok(NULL, "x");
	base = 16;
    }
    else {
	base = 10;
    }

    int len = strlen(number);

    for (int i = len - 1; i >= 0; i--) {
	if (number[i] <= 102 && number[i] >= 97) {	// if current char is A_F
	   offset = 87; }
	else if (number[i] <= 70 && number[i] >= 65) {  // if current char is a-f
	    offset = 55; }
	else if (number[i] <= 57 && number[i] >= 48) {  // if current char is 0-9
	    offset = 48; }
	else return -1;

	dig = number[i] - offset;
	//printf("char is %c int is %d\n", number[i], dig);
        sum = sum + dig * pow(base, (len - i - 1));
	}

	int max_bits = (int) (pow(2,26) - 1);

	//printf("max is %d bin is %x\n", max_bits, max_bits);
	return sum & max_bits;			// return 26 bits
}
