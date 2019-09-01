#include <stdio.h>
#include <stdlib.h>
int stringlen(char *s)
{
	int c;
	for(c=0;*s;s++)
		c++;
	return(c);
}

int stringcmp(char *a, char *b)
{
	while(*a++ == *b++)
		if (!*a && !*b)
			return(0);
	return (*a - *b);
}

void stringcopy(char *t, char *s)
{
	while((*t++ = *s++)); //s gets assigned into t and while condition only fires on the content of t
}

int main(int argc, char **argv)
{
	int a[] = {1,2,3,4,5};
	int *p = a;
	char *s = "Animesh";
	char *t = (char *)malloc(sizeof(s));
	printf("The Address of p is %p and the value pointed by p is %d\n",p,*p);
	printf("The length of Animesh is: %d\n", stringlen(s));
	printf("The Length including null is: %ld\n", sizeof(s));
	stringcopy(t,s);
	printf("%s\n",t);
	free(t);
	char *t1="Animesh";
	printf("%d\n", stringcmp(s, t1));
	return 0;
}