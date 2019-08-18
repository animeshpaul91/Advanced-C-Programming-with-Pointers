#include <stdio.h>
#include <malloc.h>
int main(int argc, char **argv)
{
	int i,n;
	int *p;
	printf("Enter the Number of integers\n");
	scanf("%d",&n);
	p = (int*)malloc(n * sizeof(int)); //Dynamically allocate an Array
	for (i = 0; i<n;i++)
	{
		p[i] = i;
	}
	
	printf("The array is\n");
	for (i=0;i<n;i++)
		printf("%d\t", p[i]);
	printf("\n");
	return 0;
}
