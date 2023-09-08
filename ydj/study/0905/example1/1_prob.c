#include<stdio.h>

int main()
{
	int arr[10];
	int sum = 0;
	printf("Please enter num(10) : ");
	for(int i = 0; i <= 9; i++)
	{
		scanf("%d", &arr[i]);
	}	

	for (int j = 1; j <= 9; j++)
	{
		if(arr[j] == 0)
		{
			arr[j - 1] = 0;
		}
	}
	
	for (int k = 0; k <= 9; k++)
	{
		sum += arr[k];
	}

	printf("%d \n", sum);

	return 0;
}
