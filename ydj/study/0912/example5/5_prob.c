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
		for (j = i + 1; j < N; j++)
		{
			if (arr[i] == 0)
			{
				flag++;
				break;
			}
			else if(arr[i] == arr[j])
			{
				arr[j] = 0;
			}
		}
		if (flag == 0)
		{	
			prt[k] = arr[i];
			k++;
		}
		flag = 0;
	}

	for (i = 0; i < k - 1; i++)
	{
		for (j = i + 1; j < k - 1; j++)
		{
			printf("(%d %d) ", prt[i], prt[j]);
		}
	}
	printf("\n");
	return 0;
}
