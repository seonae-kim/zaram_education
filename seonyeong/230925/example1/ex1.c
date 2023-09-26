#include <stdio.h>

int main()
{
	int N = 0, M = 0;
	int num[1000] = {0};
	int sum[1000] = {0};
	int i = 0, j = 0, p = 0, q = 0;
	int count = 0;
	int max = 0;

	printf("input N, M:");
	scanf("%d %d", &N, &M);
	
	printf("input numbers:");

	for(i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}


	for(i = 0 ; i < N-2; i ++)
	{
		for(j = i + 1; j < N-1; j ++)
		{
			for (p = j + 1; p < N; p++)
			{
				sum[q] = num[i] + num[j] + num[p];
				q++;

			}
		}
	}

	printf("output: ");

	max = 0;
	for( i = 0; i < 1000; i++)
	{ 
		if(sum[i] == M)
		{
			count = 2;
			break;
		}

		else if( sum[i] < M )
		{
			if (sum[i] > max)
			{
				max = sum[i];
			}
		}
	}


	if(count != 2)
	{
		printf("%d\n", max);
	}
		
	
	return 0;

}
