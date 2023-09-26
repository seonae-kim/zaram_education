#include<stdio.h>

int main()
{
	int price = 0, money = 0, count = 0, result = 0;
	int need = 0, sum = 0, i = 0;
	printf("Please enter the price : ");
	scanf("%d", &price);

	printf("Please enter the money : ");
	scanf("%d", &money);

	printf("Please enter the result : ");
	scanf("%d", &count);

	for (i = 0; i < count + 1; i++)
	{
		sum = sum + i;
	}

	need = sum * price;
	result = need - money;
	
	printf("%d\n", result);
	return 0;
}
