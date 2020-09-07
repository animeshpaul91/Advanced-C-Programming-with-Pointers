#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef void(*PFI)(char *);

void print(char *str)
{
	printf("%s", str);
}

void sum(int *a)
{
	int s = *a + *(a+1);
	printf("The sum is %d\n", s);
}

int main(int argc, char **argv)
{
	PFI test = print; //test is a pointer to function print
	pthread_t thread1, thread2, thread3;
	int a[] = {1,2};
	pthread_create(&thread1, NULL, (void *)test, (char *)"Hello ");
	pthread_create(&thread2, NULL, (void *)test, (char *)"World!\n");
	pthread_create(&thread3, NULL, (void *)&sum, a);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	exit(0);
}