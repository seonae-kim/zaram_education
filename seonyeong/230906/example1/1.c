#include <stdio.h>

int main()
{
	int num[10];
	int i;
	int sum = 0;

	printf("10 numbers : ");
	
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);
	}
	
	for (i = 0; i < 10; i++)
	{
		if (num[i] == 0)
		{
			num[i - 1] = 0;
		}
			
	}
	
	for (i = 0; i < 10; i++)
	{
		sum = sum + num[i];	
	}
	printf("output: %d\n ", sum);
	
	return 0;
}

