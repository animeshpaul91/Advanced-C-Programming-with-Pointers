#include <stdio.h>
#include <stdlib.h>
#include "animesh.h"

int main(int argc, char **argv)
{
	int n,i,*arr,sum;
	float avg;
	printf("\nEnter the number of elements in the array\n");
	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));
	for(i=0;i<n;i++)
	{	printf("\nEnter A[%d] = ", i+1);
	 	scanf("%d", arr+i);
	}
	multiple_return(arr, n, &sum, &avg);
	printf("\nThe Sum is = %d and the average is = %f\n", sum, avg);
	return (0);
}
