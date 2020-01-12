#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b)
{
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

void randomize(int arr[], int n)
{
  int i, j;
  srand(time(NULL)); /* Sets a seed which eliminates similar occurrences on every call */
  for (i = n - 1; i > -1; i--)
  {
    j = rand() % (i + 1); /* Generates a Random Number between 0 and i */
    swap(&arr[i], &arr[j]);
  }
}

int main(int argc, char **argv) 
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int i, n = sizeof(arr)/sizeof(arr[0]);
  randomize(arr, n);
  for (i = 0; i < n; i++)
    printf("%d\t", arr[i]);
  printf("\n");
  return 0;
}