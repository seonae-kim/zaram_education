#include<stdio.h>

int main()
{
	int N = 0;
	int i = 0, j = 0, k = 0;
	int flag = 0;
	printf("Please enter the N : ");
	scanf("%d", &N);

	printf("Please enter the num : ");

	int arr[N];
	int prt[N];

	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < N; i++)
	{
		flag = 0;
		for (j = i + 1; j < N; j++)
		{
			if (arr[i] == arr[j])
			{
				flag++;
				break;
			}
		}
		if (flag == 0)
		{	
			prt[k] = arr[i];
			k++;
		}
	}

	for (i = 0; i < k; i++)
	{
		for (j = i + 1; j < k; j++)
		{
			printf("(%d %d)", prt[i], prt[j]);
		}
	}
	printf("\n");
	return 0;
}
