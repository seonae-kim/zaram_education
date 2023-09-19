#include <stdio.h>

int main()
{
	int a[2][2] = { {3, 2}, {1, 3} };
	int b[2][2] = { {1, 4}, {0, -1} };
	int result_add[2][2] = {0,};
	int result_sub[2][2] = {0,};
	
	int i, j;

	
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			result_add[i][j] = a[i][j]+ b[i][j];
		}
	}

	
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			result_sub[i][j] = a[i][j] - b[i][j];
		}
	}

	for(i = 0; i < 2 ; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("%d ", result_add[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	for(i = 0; i < 2 ; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("%d ", result_sub[i][j]);
		}
		printf("\n");
	}
	
}
		
	
