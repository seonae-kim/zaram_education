#include<stdio.h>
#define N 3

int main()
{
	int i = 0;
	int max = 0, min = 0;
	int arr[N] = {0};
	int apply = 1;

	printf("Enter the number(3) : ");

	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	max = arr[0];
	min = arr[0];
	
	for (i = 0; i < N; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
		else if(arr[i] < min)
		{
			min = arr[i];
		}
	}

	for(i = min; i <= max; i++)
	{
		if(i % 2 == 0)
		{
			apply *= i;
		}
	}

	printf("%d \n", apply);
	return 0;
}
