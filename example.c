#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum{
	RTYPE, ITYPE, JTYPE, JALTYPE, MEMTYPE
} instr_type_t;

typedef struct{
	char *mnemonic;
	instr_type_t type;
	int opcode
	int function;
} instr_t;

instr_t instrs[] = {
	{ .mnemonic = "ADD", .type = RTYPE, .opcode = 0, .function = 0x20},
	{ .mnemonic = "ADDI", .type = ITYPE, .opcode = 0x20, .function = 0}
};

#define NUM_INSTR ( sizeof(instrs) / sizeof(instr_t))

int find_opcode(const char *str, instr_t *instr)
{
	int i;
	for(i = 0; i < NUM_INSTR; i++){
		if(strcmp(instr[i].mnemonic, str) == 0){
			*instr = instr[i];
			return 0;
		}
	}
	return -1;
}

int num_regs(instr_type_t t)
{
	switch(t) {
		case RTYPE: return 3;
		case ITYPE: return 2;
		case JTYPE: return 0;
		case JALTYPEL: return 1;
		case MEMTYPE: return 2;
		default: return -1;
	}
}


void parse_string(const char *str)
{
	int i = 0;
	int state = 0;
	int start = 0;
	char *opcode = NULL;
	
	while ((str[i] != 0) && (state >= 0)){
		char ch = str[i];
		switch(state){
			case 0:
			if(str[i] == ' ') state = 0;
			else if (str[i] == '\t') state = 0;
			else if ((str[i] >= 'A') && (str[i] <= 'Z')){
				state = 1;
				start = i;
			}
			else start = -1;
			break;
			
			//beginning of instruction
			case 1;
			if((str[i] >= 'A') && (str[i] <= 'Z'))
				state = 1;
			else if((str[i] == ' ') || (str[i] == '\t')) {
				state = 2;
				opcode = malloc(i - start + 1);
				strncpy(opcode, &str[start], (i - start));
			}
			else{
				state = -1;
			}
			break;
		}
		i++;
	}
}