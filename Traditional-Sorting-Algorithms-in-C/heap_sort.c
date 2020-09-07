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


void restoreHeapUp(int *a, int i)
{ int val = a[i];
  while ((i>0) && (a[i/2] > val))
  { a[i] = a[i/2];
    i/=2;
  }
  a[i] = val;

}

void restoreHeapDown(int *a, int i, int n)
{ int ptr=i, l=1,r=2;
  while ((l <= n) && (a[ptr]>=a[l] || a[ptr]>=a[r]))
  { if (a[l] <= a[r])
     { swap(&a[ptr], &a[l]);
       ptr = l;
     } 
    else
     { swap(&a[ptr], &a[r]);
	ptr = r;
     }
   l= 2*ptr;
   r = l + 1;
  }
}

int main()
{ int n,i,j,*s;
  printf("\nEnter the number of terms in the array\n");
  scanf("%d",&n);
  int *a = (int *) malloc(n * sizeof(int)); // Dynamically Allocated Array in C
  s = (int *) malloc(n * sizeof(int)); // Will store Sorted Sequence
  printf("\nStart Entering the Array Elements\n");
  for (i=0;i<n;i++)
   { printf("\nEnter A[%d] = ",i+1);
     scanf("%d",&a[i]);
     restoreHeapUp(a,i);
   }

  printf("\nThe Heap is\n\n");
  print(a,n);
  printf("\nSorting------------");
  i = 0;
  while (n!=0)
  { s[i++] = a[0];
   // printf("%d\t",s[i]);
    a[0] = a[n-1];
    n--;
    restoreHeapDown(a,0,n);
  }

 printf("\n The Array Sorted using Heap Sort is \n\n");
 print(s,i); 

printf("\n");

return (0);
}
