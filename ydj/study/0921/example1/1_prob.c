#include<stdio.h>

int main()
{
	int arr[10] = {0};
	int comb[4] = {0};
	int i = 0, j = 0;
	int count = 0;
	int flag = 0;
	printf("Please enter the number : ");
	
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("\nPlease enter the series of number you want to search : ");
	for (i = 0; i < 4; i++)
	{
		scanf("%d", &comb[i]);
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (comb[j] == arr[i + j])
			{
				flag++;
			}
			if (flag == 4)
			{
				count++;
			}
		}
		flag = 0;
	}

	printf("\nThe # of the series is %d\n\n", count);
	return 0;
}
