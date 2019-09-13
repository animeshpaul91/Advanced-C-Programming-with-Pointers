/*This is how multiple values are returned in C/C++.
An illustration of how custom header files are used in C */

void multiple_return(int *arr, int n, int *sum, float *avg)
{ 
	int s = 0,i;
	for (i=0;i<n;i++)
		s+=arr[i];
	*sum = s;
	*avg = *sum/n;
}