#include <stdio.h>

int main()
{
	int N = 0;
	int a = 0, temp = 0;
	int i = 0, j = 0, num = 1;
	int idx = 1;
	int arr[20][20] = {0};

	printf(" input N:");
	scanf("%d", &N);

	temp = N;
	for( idx = 0; idx < N ; idx++ )
	{
		if( num == N * N + 1)
			break;

		if(idx >= 1)
		{
			a = a + 1;
			temp = temp - 1;
		}
		
		
		for( j = a; j < temp; j++)
		{
			i = a;
			arr[i][j] = num++;
		}
	
		num--;
		for(i = a; i < temp; i++)
		{
			j = temp-1;
			arr[i][j] = num++;
		}
		
		num--;
		for(j = temp-1; j >= a; j--)
		{
			i = temp-1;
			arr[i][j] = num++;
		}
		num--;

		for( i = temp-1; i > a; i--)
		{
			j = a;
			arr[i][j] = num++;
		}
	}

















	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
