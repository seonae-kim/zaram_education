#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	int num[2][4] = { 0 };

	printf("8 numbers: ");

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j ++)
		{
			scanf("%d",&num[i][j]);

		}
	}

	for(i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("(%d %d)",num[0][i], num[1][j]);
			
		}
	}
		
	printf("\n");


}




