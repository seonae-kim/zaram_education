#include <stdio.h>

int main()
{
	int N = 0;
	int i = 0, j = 0, num = 1;
	int arr[20][20] = {0};

	printf(" input N:");
	scanf("%d", &N);

	
	while(1)
	{
		for( j = 0; j < N; j++)
		{
			arr[0][j] = a;
			a++;
		}
	
		for( i = 1; i < N; i++)
		{
			arr[i][N-1] = a;
			a++;
		}

	}








		for(i = 0; i < N; i++)
		{
			for(j = 0; j < N; j++)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	
	
	return 0;
}
