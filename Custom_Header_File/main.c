#include <stdio.h>
#include <stdlib.h>
#include "animesh.h"

int main(int argc, char **argv)
{
	int n,i,*arr,sum;
	int *ret, t=2, target;
	float avg;
	printf("\nEnter the number of elements in the array\n");
	scanf("%d", &n);
	arr = (int *)malloc(n * sizeof(int));
	for(i=0;i<n;i++)
	{	printf("\nEnter A[%d] = ", i);
	 	scanf("%d", arr+i);
	}
	multiple_return(arr, n, &sum, &avg);
	printf("\nThe Sum is = %d and the average is = %f\n", sum, avg);
	printf("\nStarting Leetcode Problem No. 1\n");
	printf("Enter the Sum Target\n");
	scanf("%d", &target);
	ret = twoSum(arr, n, target, &t);
	printf("%d\t%d\n", *ret, *(ret+1));
	return (0);
}
