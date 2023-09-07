#include <stdio.h>

int main()
{
	int arry[2][4];
	
	printf("input: ");
	for(int i = 0 ; i < 2 ; i++)
	{
		for(int j = 0 ; j < 4 ; j++)
		{
			scanf("%d ",&arry[i][j]);
		}
	}
	
	printf("output: ");
	for(int i = 0 ; i < 4 ; i++)
	{
		for(int j = 0 ; j < 4 ; j++)
		{
			printf("(%d, %d) ",arry[0][i], arry[1][j] );
		}
	}
	
	printf("\n");
	return 0;
}
