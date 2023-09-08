#include <stdio.h>

int main(void)
{
	int a = 20;
	float b = 5.05F, c = 12000.149F;   //F= change to Float(default = double)

	printf("1)%d\n\n", a);
	printf("2)6d\n\n", a);		    //arange to right (set width)
	printf("3)%+6d\n\n", a);	    //arange to right (set width)
	printf("4)%-6d\n\n", a);	    //arange to left  (set width)

	printf("1)%\n\n", b);
	printf("2)%6.1f\n\n", b);	    //arrange to right (set width)
	printf("3)%+6.1f\n\n", b);	    //arange to right  (set width) ,   .1
	printf("4)%6f\n\n", c);		    //arrange to right (set width)

	return 0;
}
