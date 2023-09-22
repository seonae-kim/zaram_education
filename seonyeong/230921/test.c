#include <stdio.h>


void A(int *x)
{
	*x = 3;
}

int main(void)
{
	int x = 0;
	int c = 0;
	int *y = &c;


	A(&x);
	A(y);

	printf("%d %d\n",x, *y);

	return 0;
}
