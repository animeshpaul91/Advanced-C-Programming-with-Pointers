#include<stdio.h>
#include<stdlib.h>
void print(int *a, int n)
{ int i;
  for (i=0;i<n;i++)
    printf("%d\t",a[i]);
}

int* insertion_sort(int *a, int n)
{ int i,j,temp;
  for (i=1;i<n;i++)
  { j = i-1; 
    temp = a[i];
    while (temp < a[j]){
    a[j+1] = a[j];
    j--;
    }
    a[j+1] = temp;
  }
 return (a);
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

  //Insertion Sort
  a = insertion_sort(a,n);

  printf("\nThe Array after sorting is\n\n");
  print(a,n);
  printf("\n");

return (0);
}
