#include<stdio.h>
#define N 4
int main()
{
	int arr[N][N] = {0};
	int i = 0, j = 0;

	printf("Please enter the 2D array num(16) : ");

	for (i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%d ", arr[i][j]);
		}
	}
	printf("\n");
	return 0;
}
