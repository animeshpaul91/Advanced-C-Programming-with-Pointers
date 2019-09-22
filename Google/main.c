#include <stdio.h>
#include <stdlib.h>

void hello(char *x)
{
	printf("%s\n", x);
}

int compare(const void* a, const void* b)
{
     int int_a = *((int*)a);
     int int_b = *((int*)b);

     if (int_a == int_b) return 0;
     else if (int_a < int_b) return -1;
     else return 1;
}

char* lin_search(int* arr, int n, int k)
{
  int i;
  for(i=0;i<n;i++)
   if(arr[i] == k)
    return((char *)"YES\n");
  return((char *)"NO\n");
}

int bin_search(int* arr, int p, int r, int x)
{
	if(p == r)
	{
		if(x == arr[p])
			return (p);
		else
			return (-1);
	}
	
	int mid = (p+r)/2;
	if (x == arr[mid])
		return mid;
	else if(x < arr[mid])
		return(bin_search(arr, p, mid-1, x));
	else
		return(bin_search(arr, mid+1, r, x));
}

int main()
{ int n,i,k,*arr;
  typedef void (*fp)(char *); // A function Pointer
  fp animesh = hello;
  animesh((char *)"Hello Animesh");
  printf("\nEnter the number of elements in the array\n");
  scanf("%d", &n);
  arr = (int *)malloc(n * sizeof(int));
  for(i=0;i<n;i++)
  { printf("\nEnter A[%d] = ", i+1);
    scanf("%d", arr+i);
  }
  printf("\nEnter the element to search\n");
  scanf("%d", &k);
  puts(lin_search(arr, n, k));
  printf("\nSorting Input Array to perform binary search\n");
  qsort(arr, n, sizeof(int), compare);
  printf("%d\n", bin_search(arr, 0, n-1, k));
  return (0);
}
