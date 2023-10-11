#include <stdio.h>

void main()
{
	int i = 1;
	int j = 0;
	int N = 0;
	int size = 0;
	int num = 0;
	int count = 0;
	int flag = 0;
	
	printf("N*N input N:");
	scanf("%d", &N);
	size = N;
	int arr[N][N];
	
	while(N > 0)
	{
		for(i = 0; i < 4; i++)
		{
			if((count % 4) == 0)
			{
				if(N == 1) arr[flag][flag] = ++num;
				else
				{
					for(j = 0; j < N-1; j++)
					{
						arr[flag][j+flag] = ++num;
					}
				}
			}
			else if((count % 4) == 1)
			{
				
				for(j = flag; j < N-1+flag; j++)
				{
					arr[j][N-1+flag] = ++num;
				}
			}
			else if((count % 4) == 2)
			{
				for(j = N+flag-1; j >= flag+1; j--)
				{
					arr[N+flag-1][j] = ++num;
				}
			}
			else if((count % 4) == 3)
			{
				for(j = N+flag-1; j > flag; j--)
				{
					arr[j][flag] = ++num;
				}
			}
			count++;
			if(num > size*size) break;
		}
		if(num > size*size) break;
		flag++;
		N-=2;
	}
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}
