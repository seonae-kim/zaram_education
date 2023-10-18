#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int n1 = 0, mod, i = 0, n2 = 0;
	int a = 0, b = 0, sum = 0,  index = 0;
	int arr[20];

	printf("n1: ");
	scanf("%d",&n1);

	printf("n2: ");
	scanf("%d",&n2);

	while(n1 != 0)
	{
		mod = n1 % 10;
		n1 = n1 / 10;
		a += mod* pow(2, i++);
	}

	i = 0;
	while(n2 != 0)
	{
		mod = n2 % 10;
		n2 = n2 / 10;
		b += mod * pow(2, i++);
	}

	sum = a + b;

	printf("sum: %d\n",sum);

	while(sum != 0)
	{
		a = sum % 2;
		arr[index++] = a;
		sum /= 2;
	}

	for(i = index - 1; i >= 0; i--)
	{
		printf("%d",arr[i]);
	}

	printf("\n");


	return 0;

}











	


	
