#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n = 0, num = 0;
	int i = 0, x = 0;
	int min = 0;
	printf("Please enter the # of element : ");
	scanf("%d", &num);

	int arr[n];
	int dif[n];
	printf("Pleae enter the array element : ");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Please enter the n : ");
	scanf("%d", &n);
	
	for (i = 0; i < num; i++)
	{
		dif[i] = abs(arr[i] - n);
	}

	min = dif[0];
	for (i = 0; i < num; i++)
	{
		if (min > dif[i])
		{
			min = dif[i];
			x = i;
		}
	}

	printf("%d\n", arr[x]);
	return 0;
}
