#include <stdio.h>

int main(int argc, char **argv) {
	int i;
	char str1[] = "Hello"; //str1 is an Array
	char *str2 = "Goodbye"; //str2 is a Pointer
	// str2 = &str1;
	// str2 = str1;
	printf("%d %d %s\n", &str1, str1, str1); //Array name refers to base address/address of the array/address of the first element of the array.
	printf("%d %d %s\n", &str2, str2, str2); 
	/* str2 returns the address(base address) of "Goodbye" whereas &str2 returns the address of the str2 pointer. The former and 
	latter are completely different */
	// &str2 is of no interest to us. 
	for(i=0;i<7;i++)
	{
		printf("\nCharacter stored at Address = %d is = %c\n", str2, *str2);
		str2++;
	}
	printf("\n");
	return 0;
}
