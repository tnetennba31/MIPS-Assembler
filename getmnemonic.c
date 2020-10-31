#include <string.h>

char parse_string(const char *str)
{
	char mnemonic;
	char* ptr = str;

	strcpy(mnemonic, strtok(ptr, ","));
	printf("%s", mnemonic);

	return mnemonic;
}