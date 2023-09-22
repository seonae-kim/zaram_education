#include<stdio.h>

int main()
{
	int N = 0;
	int i = 0, j = 0;
	int temp = 0;
	int cent = 0;
	printf("You should enter the odd number N!\n");
	printf("Please enter the #of element : ");
	scanf("%d", &N);
	
	int arr[N];

	printf("Please enter the array element : ");
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	cent = N / 2;
	printf("%d\n", arr[cent]);
	return 0;
}
