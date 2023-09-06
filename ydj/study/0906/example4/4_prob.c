#include<stdio.h>
#define N 10
int main()
{
	int arr[N];
	int temp;
	int i, j;
	int idx_max, idx_min; 
	int count = 0;
	printf("Please enter the num(10) : ");
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for(i = 0; i < N; i++)
	{
		for(j = i + 1; j < N; j++)
		{
			if(arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;	
			}
		}
	}

	for(i = 0; i < 5; i++)
	{
		printf("%d %d ", arr[i], arr[9-i]);
	}

	printf("\n");
	return 0;
}
