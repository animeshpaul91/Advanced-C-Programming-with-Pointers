#include <stdio.h>
#include <stdlib.h>
char* lin_search(int* arr, int n, int k)
{
  int i;
  for(i=0;i<n;i++)
   if(arr[i] == k)
    return((char *)"YES\n");
  return((char *)"NO\n");
}

int main()
{ int n,i,k,*arr;
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
  return (0);
}
