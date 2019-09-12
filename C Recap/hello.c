#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_static()
{       static int i = 0;
	i++;
	printf("%d\n",i);
}

int main()
{ 	int i;
	printf("Hello World\n");
	printf("sizeof(char): %ld\n", sizeof(char));
	printf("sizeof(short): %ld\n", sizeof(short));
	printf("sizeof(int): %ld\n", sizeof(int));
	printf("sizeof(long): %ld\n", sizeof(long));
	printf("sizeof(float): %ld\n", sizeof(float));
	printf("sizeof(double): %ld\n", sizeof(double));
	int a[3];
	a[0]=2;a[1]=4;a[2]=a[0]+a[1];
	int x = a[a[0]];
	printf("%d\n",x);
	char b[13] = "Hello, World!";
	char c[15];
	memset(c, '\0', sizeof(c));
	strncpy(c,b,14);
	printf("%s\n", c);
	for(i=0;i<3;i++)
		test_static();
	return (0);
}
