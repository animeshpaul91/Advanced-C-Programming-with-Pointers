#include <stdio.h>

void const_problem() {
	int i;
	int *pi;
	const int ci = 100;
	const int *cpi = &ci;
	i = 5;
	// ok
	pi = &i;
	// ok (normal)
	cpi = &i;
	// re-assign but no warning
	cpi = &ci;
	// ok - but no warning
	pi = cpi;
	// warning: "'=': different 'const' qualifiers"
	*pi = 30;
	// ok but ci is now 30!
	pi = (int*)cpi; // no warning: the cast tells the compiler to shut up
	//ci = 200;
	// error - compiler does not allow
	printf("ci = %d", ci);
}

int main(int argc, char **argv)
{
    int num;
    int* numPtr;
    int num2;
    num = 100;
    numPtr = &num; //numPtr points to the memory address containing num
    num2 = *numPtr; //indirection operator fetching the data that is found at that address
	printf("num=%d, numPtr=%d, address of num=%d, num2=%d\n", num, numPtr, &num, num2);
	const_problem();
	return 0;
}
