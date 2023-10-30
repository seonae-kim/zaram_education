#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	int num[4][4] = { 0 };
	int a = 0, b = 0;
	int sum = 0, max = 0;
	int c,d,e,f;

	printf("hello test code\n");
	printf("8 numbers: ");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j ++)
		{
			scanf("%d",&num[i][j]);

		}
	}
	printf("%d\n", num[0][0]);
	printf("Test Code \n");

	for(i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
		  printf("###\n");
			for (a = 0; a < 4; a++)
			{
				for (b = 0; b < 4; b++)
				{
					if ( i  == j ) continue;
					if ( j == a ) continue;
					if ( a == b ) continue;

						sum = num[0][i] + num[1][j] +  num[2][a] + num[3][b];
						if (sum > max)
						{

							max = sum;
						}
						//printf("(%d %d %d %d)",num[0][i], num[1][j], num[2][a], num[3][b]);
				}
			}
			
		}
	}
	printf("%d", max);
		
	printf("\n");

	printf("exit\n");

}




