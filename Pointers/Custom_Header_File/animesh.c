#include "animesh.h"
#include <stdlib.h>

int len(char *str)
{
	int c;
	for(c=0;*str;c++)
		str++;
	return(c);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
   int i,j;
   int *indices = (int *) malloc(*returnSize * sizeof(int));
   indices[0] = 0;
   indices[1] = 0; //default values in case the target id not located
    for (i = 0; i<numsSize - 1; i++)
      for (j = i+1; j<numsSize; j++)
          if (nums[i] + nums[j] == target)
            {
                indices[0] = i;
                indices[1] = j;
                return (indices);
            }
 return (indices);
}

void multiple_return(int *arr, int n, int *sum, float *avg)
{ 
	int s = 0,i;
	for (i=0;i<n;i++)
		s+=arr[i];
	*sum = s;
	*avg = *sum/n;
}