#include<stdio.h>
#include<stdlib.h>
int n; //Number of Array Elements
void print(int *a, int n)
{ int i;
  for (i=0;i<n;i++)
    printf("%d\t",a[i]);
}

void merge(int *a, int b, int m, int e)
{ int i=b, j=m+1, index = b, temp[e+1]; 
  while((i < m+1) && (j < e+1)){
  
  if (a[i] < a[j])
   temp[index++] = a[i++];
  
  else
   temp[index++] = a[j++];
 } //end of while loop

 if (i == m+1){
   while(j < e+1) 
      temp[index++] = a[j++];
  }

 else {
  while(i < m+1)
     temp[index++] = a[i++];
  }

 for (i=b; i<index; i++)
  a[i] = temp[i];
}


void merge_sort(int *a, int b, int e)
{ // b and e represent the beginning and end indices respectively
  int m; //mid index 
  if (b < e)
  { m = (b + e)/2;
    merge_sort(a,b,m);
    merge_sort(a,m+1,e);
    merge(a,b,m,e);
  }
}

int main()
{ int i,j;
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

  //Merge Sort Begins
  merge_sort(a,0,n-1);

printf("\nThe Array after sorting is\n\n");
print(a,n);
printf("\n");

return (0);
}
