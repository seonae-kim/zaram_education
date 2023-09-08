#include <stdio.h>
#include <math.h>	    //pow

int main(void) 
{
    short a, b;
    unsigned short c;

	a = pow(2, 15) -1;	// 2^15 - 1
	b = pow(2, 15);
	c = pow(2, 15);

	printf("a is %d.\n", a);

	return 0;
}
