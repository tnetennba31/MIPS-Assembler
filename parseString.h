#ifndef _PARSESTRING_H
#define _PARSESTRING_H

#include "project.h"
#include "registers.h"
#include "validateInstruction.h"
#include <stdbool.h>

void parse_string(parsed_t *p, char* str);

bool parseR(char *str, parsed_t *result);
bool parseI(char *str, parsed_t *result);
bool parseJ(char *str, parsed_t *result);
bool parseJR(char *str, parsed_t *result);
bool parseMem(char *str, parsed_t *result);
bool parseShifty(char *str, parsed_t *result);

#endif
