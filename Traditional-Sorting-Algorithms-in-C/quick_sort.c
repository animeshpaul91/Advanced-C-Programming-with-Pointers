#include<stdio.h>
#include<stdlib.h>
void print(int *a, size_t n)
{ size_t i;
  for (i=0;i<n;i++)
    printf("%d\t",a[i]);
}

void swap(int *x, int *y)
{ int t;
  t = *x;
  *x = *y;
  *y = t;
}

void shuffle(int *a, size_t n)
{ size_t i;
  if (n > 1) 
    { for (i = 0; i < n - 1; i++) 
        { size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
	  swap(&a[i], &a[j]);
        }
    }
}

int partition(int *a, int b, int e)
{ int left, right, loc, flag=0;
  left = loc = b;
  right = e;
  while (flag != 1)
  { while((a[loc] <= a[right]) && (loc != right))
      right--; //Moving right leftwards
    if (loc==right)
      flag=1;
    else
    {
      swap(&a[loc], &a[right]);
      loc = right;
    }

    if (flag!=1) //We have to move left rightwards now
    { while((a[left] <= a[loc]) && (left != loc))
       left++; // Moving left rightwards
      if (loc == left)
       flag=1;
      else
      { swap(&a[loc], &a[left]);
	loc = left;
      }
    }
  }
return (loc);
}


void quick_sort(int *a, int b, int e)
{ int l;
  if (b < e)
  {
    l = partition(a,b,e); // After this step l will be at its correct position
    quick_sort(a,b,l-1);
    quick_sort(a,l+1,e);
  }	  
}

int main()
{ int i,j;
  size_t n;
  printf("\nEnter the number of terms in the array\n");
  scanf("%ld",&n);
  int *a = (int *) malloc(n * sizeof(int)); // Dynamically Allocated Array in C
  printf("\nStart Entering the Array Elements\n");
  for (i=0;i<n;i++)
   { printf("\nEnter A[%d] = ",i+1);
     scanf("%d",&a[i]);
   }

  printf("\nThe Array before sorting is\n\n");
  print(a,n);
  
  printf("\nShuffling Array-----------\n");
  shuffle(a,n); //Randomize ordering of elements for optimized Quick Sort Performance.This is done to avoid the worst case running time at every recursive call
  printf("\nThe Randomized shuffled Array is \n\n");
  print(a,n);

  quick_sort(a,0,n-1);
  printf("\nThe Array after sorting is\n\n");
  print(a,n);
  printf("\n");

  return (0);
}
