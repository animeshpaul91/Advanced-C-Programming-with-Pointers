#include<stdio.h>
#include<stdlib.h>
void print(int *a, int n)
{ int i;
  for (i=0;i<n;i++)
    printf("%d\t",a[i]);
}

void swap(int *x, int *y)
{ int t;
  t = *x;
  *x = *y;
  *y = t;
}


int main()
{ int n,i,j;
  printf("\nEnter the number of terms in the array\n");
  scanf("%d",&n);
  int *a = (int *) malloc(n * sizeof(int)); // Dynamically Allocated Array in C
  printf("\nStart Entering the Array Elements\n");
  for (i=0;i<n;i++)
   { printf("\nEnter A[%d] = ",i+1);
     scanf("%d",&a[i]);
   }

  printf("\nThe Array before sorting is\n\n");
  print(a,n);

  //Selection Sorting Begins
  for (i = 0; i< (n-1); i++)
    for (j = i+1; j < n; j++)
	if (a[i] > a[j])
	  swap(&a[i], &a[j]);


printf("\nThe Array after sorting is\n\n");
print(a,n);
printf("\n");

return (0);
}
