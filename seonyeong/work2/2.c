#include <stdio.h>

int main()
{
	int num[100];
	int i;
	int p = 0;

	printf("15 numbers : ");

	for (i = 0; i < 15; i++)
	{
		scanf("%d", &num[i]);
	}

	printf("output:");

	int max;
	max = num[0];
	int number = 0;
	
	for (i = 0; i < 15; i++)
	{
		if (num[i] == 0)
		{
			for (p = 0; p < i; p++)
			{
				if (num[p] >= max)
				{
					max = num[p];
					number = p;
				}
			}
			printf("%d ", max);
			max = 0;
			num[number] = 0;
		}

	}

	printf("\n");
	return 0;
	
}

