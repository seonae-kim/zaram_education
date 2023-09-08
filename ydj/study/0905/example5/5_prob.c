#include<stdio.h>
#define N 4

int main()
{
	int i, j, k, l;
	int arr[N][N] = {0};
	int sum = 0;
	int max = 0;

	printf("Please enter the num (4 x 4 2D array) : ");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			for(k = 0; k < N; k++)
			{
				for(l = 0; l < N; l++)
				{
					if(i == j || j == k || k == l)
					{
						continue;
					}

					sum = arr[0][i] + arr[1][j] + arr[2][k] + arr[3][l];

					if(max < sum)
					{
						max = sum;	
					}
					sum = 0;			
				}
			}
		}
	}
	printf("%d \n", max);
		



	//1.
	/*
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			sum = 0;
			for(k = 0; k < N; k++)
			{
				if(k != j)
				{
					
				}
			}		
		}
	}
	*/
	return 0;
}
