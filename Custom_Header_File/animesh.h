/*This is how multiple values are returned in C/C++.
An illustration of how custom header files are used in C */

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
   int i,j;
   int *indices = (int *) malloc(*returnSize * sizeof(int));
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