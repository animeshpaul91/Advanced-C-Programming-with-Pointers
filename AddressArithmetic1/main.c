#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 4

// basic address arithmetic

int main() {
	int *p;
	int a[COUNT];

	// first let's look at the size of a basic integer
	printf("size of an 'int' is %d\n", sizeof(int));

	// initialize our array
	for (int i = 0; i < COUNT; i++) a[i] = i;

	// let's do some pointer arithmetic
	p = a;						// set the pointer to the array to the start of the array
	printf("address of a is %p; value of p is %p [%d]; value pointed to by p is %d\n", a, p, p, *p);
	
	// increment p by 1
	// NOTE: the address of 'a'a remains the same (because we haven't done anything to it)  ...
	// ... but the value of 'p' has been increased by 4 - the size of an integer - and so ...
	// the value pointed to by 'p' is now a[1]
	p++;
	printf("address of a is %p; value of p is %p [%d]; value pointed to by p is %d\n", a, p, p, *p);

	// increment p by another 2 the value pointed to by 'p' is now a[3]
	p++;
	printf("address of a is %p; value of p is %p [%d]; value pointed to by p is %d\n", a, p, p, *p);

	// what happens if we go beyond the array end? there's nothing to stop you or warn you ...
	// ... so, increment p by another 1 the value pointed to by 'p' is now a[4]
	// ... but we will get junk
	p++;
	printf("address of a is %p; value of p is %p [%d]; value pointed to by p is %d\n", a, p, p, *p);
	return 0;
}

/* C knows that p is a pointer to an integer datatype and therefore every p++ statement causes the pointer to increment 4 bytes (i.e
point to the next integer) in the array */