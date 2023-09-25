#include <stdio.h>

int main()
{
	int price;
	int money;
	int count;
	int i;
	int sum = 0;

	printf("input price:\n");
	scanf("%d", &price);				

	printf("input money:\n");
	scanf("%d", &money);				

	printf("input count:\n");
	scanf("%d", &count);						

	int price_fix = price;
								
	for(i = 0; i < count; i++)
	{
		price = price_fix * (i+1);
		sum += price;
	}

	printf("%d", sum - money);

}
