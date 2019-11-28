#include <string.h>
static void test(void);

static void token()
{
	char str[] = "String to tokenize. test. Vishal";
	char *saveptr;
	char *token;
	
	for (token = strtok_r(str, " ", &saveptr); token != NULL; token = strtok_r(NULL, " ", &saveptr))
	printf("%s\n", token);
}
