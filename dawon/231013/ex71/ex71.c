#include <stdio.h>
#include <stdlib.h>

int main()
{
	int price, money, count, result, sum = 0, i;

	printf("price: ");
	scanf("%d",&price);

	printf("money: ");
	scanf("%d",&money);

	printf("count: ");
	scanf("%d",&count);

	for(i = 1; i <= count; i++)
	{
		sum += price * i;
	}

	result = sum - money;

	printf("result: %d\n",result);

	return 0;

}
	
