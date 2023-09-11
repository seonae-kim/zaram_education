#include<stdio.h>
#define X 4

int main()
{
	int i = 0, j = 0, N = 0, flag = 0, max = 0;
	int temp = 0;
	int arr[X];

	printf("Please enter the num(4) : ");
	for (i = 0; i < X; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Please enter the N : ");
	scanf("%d", &N);

	for (i = 0; i < X; i++)
	{
		if(arr[i] % N == 0)
		{
			flag++;
		}
		else
		{
			arr[i] = 0;
		}
	}

	for (i = 0; i < X; i++)
	{
		for (j = i + 1; j < X; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	if (flag == 0)
	{
		printf("-1 -1 -1 -1");
	}
	else
	{
		for (i = 0; i < X; i++)
		{
			if (arr[i] == 0)
			{
				continue;
			}
			else
			{
				printf("%d ", arr[i]);
			}
		}
	}
	printf("\n");
	return 0;
}
