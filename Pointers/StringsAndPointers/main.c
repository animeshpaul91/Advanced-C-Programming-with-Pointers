#include <stdio.h>
#include <string.h>
#include "tokenize.h"

int main(int argc, char **argv) {
	char str1[] = "Hello world";	
	int i;
	printf("%s %c %p %p %p\n", str1, str1[0], &str1, &str1[0], str1);
	printf("\nSequential Addresses of each element goes as follows\n\n");
	for(i=0;i<strlen(str1);i++)
		{
			printf("\nAddress at index = %d is = %p", i, &str1[i]);
		}
	printf("\n");
	token();
	test();
	return 0;
}

static void test(void)
{
	printf("Testing static import\n");
}

/* The address of an Array is the same as the address of the first item in an array because that's where the array begins. The name
   of the array variable is also the address of the array. Array name is the address of the first item in the array. This address is
   also known as the base address of the array */
