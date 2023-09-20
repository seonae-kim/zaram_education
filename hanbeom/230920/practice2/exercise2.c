#include <stdio.h>

int main()
{
	int number;
	int n;
	int m;

	printf("input number: \n");
	scanf("%d", &number);

	printf("input n: \n");
	scanf("%d", &n);

	printf("input m: \n");
	scanf("%d", &m);

	if(number % n == 0 && number % m ==0)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
}
