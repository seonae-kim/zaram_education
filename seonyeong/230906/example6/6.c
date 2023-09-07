#include <stdio.h>

int main()
{
	int i=0;
	int j = 0;
	int num[4][4] = {0};

	printf("16 numbers:");
	
	for (i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			scanf("%d", &num[i][j]);
		}

	}

	printf("output: ");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", num[i][j]);
		}
	}
	
	printf("\n");
	return 0;

}
