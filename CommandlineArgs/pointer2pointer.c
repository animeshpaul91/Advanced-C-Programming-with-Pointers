#include <stdio.h>
void pointer2pointer()
{
	char *a, **argv;
	a = "one";
	argv = &a;
	/*
	 * a points to a string, but argv points to a pointer(i.e a) which points to a string
	 */
	printf("\nAddress of a is %p Address pointed by a is %p and content of a is %s\n", &a, a, a);
	printf("Address pointed by argv is %p, address and content of *argv is %p and %s which is the same as %s\n", argv, *argv, *argv, argv[0]);
}