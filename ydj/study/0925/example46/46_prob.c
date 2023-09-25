#include<stdio.h>

int main()
{
	int num = 0;
	int i = 0, n = 0;
	printf("Please enter the # of element : ");
	scanf("%d", &num);

	int arr[n];
	printf("Please enter the element : ");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Please enter the number n : ");
	scanf("%d", &n);


	if (num % 2 == 0)
	{
		for (i = 0; i < num; i++)
		{
			if (i % 2 == 1)
			{
				arr[i] = arr[i] + n;
			}
		}
	}
	
	else if (num % 2 == 1)
	{
		for (i = 0; i < num; i++)
		{
			if (i % 2 == 0)
			{
				arr[i] = arr[i] + n;
			}
		}
	}

	for (i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
