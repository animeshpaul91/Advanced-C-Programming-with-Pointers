#include <stdio.h>

int main(int argc, char **argv)
{
	int a,b,c;
	int *p;
	printf("\nEnter any two numbers\n");
	scanf("%d\%d",&a,&b);
	c = a+b;
	p = &c;
	printf("\nThe Sum is = %d\n", *p);
	printf("\nThe Memory Address of the variable that stores the sum is = %u\n", p);
	return 0;
}
