#include <stdio.h> 
  
// returns true if there is triplet with sum equal 
// to 'sum' present in A[]. Also, prints the triplet 
int find3Numbers(int A[], int arr_size, int sum) 
{ 
    int l, r,i,j,k; 
  
    // Fix the first element as A[i] 
    for (i = 0; i < arr_size - 2; i++) { 
  
        // Fix the second element as A[j] 
        for (j = i + 1; j < arr_size - 1; j++) { 
  
            // Now look for the third number 
            for (k = j + 1; k < arr_size; k++) { 
                if (A[i] + A[j] + A[k] == sum) { 
                    printf("Triplet is %d, %d, %d", 
                           A[i], A[j], A[k]); 
                    return 1; 
                } 
            } 
        } 
    } 
  
    // If we reach here, then no triplet was found 
    return 0; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    int A[] = { 1, 4, 45, 6, 10, 8 }; 
    int sum = 22,bool; 
    int arr_size = sizeof(A) / sizeof(A[0]); 
    bool=find3Numbers(A, arr_size, sum); 
    return 0; 
}
