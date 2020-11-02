#ifndef _NORMALIZE_H
#define _NORMALIZE_H

#include "main.h"
#include "registers.h"

parsed_t *parse_string(const char* str);

bool parseR(char *str, parsed_t *result);
bool parseI(char *str, parsed_t *result);
bool parseJ(char *str, parsed_t *result);
bool parseJR(char *str, parsed_t *result);
bool parseMem(char *str, parsed_t *result);
bool parseShifty(char *str, parsed_t *result);

#endif