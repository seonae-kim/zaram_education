#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	int num[4][4] = { 0 };
	int a = 0, b = 0;
	int sum = 0, max = 0;
	int c,d,e,f;

	printf("test code");
	printf("hello test code\n");
	printf("8 numbers: ");

	printf("test :");
	for (i = 2; i < 4; i++)
	{
		printf("test");
		for (j = 2; j < 4; j ++)
		{
			scanf("%d",&num[i][j]);

		}
	}
	printf("exit\n");
	printf("hello");
	
	printf("%d\n", num[0][0]);
	printf("Test Code \n");

	for(i = 0; i < 4; i++)
	{
		printf("hello");
		for (j = 0; j < 4; j++)
		{
			printf("hello");
			printf("###\n");
			for (a = 0; a < 4; a++)
			{
				printf("hello");
				for (b = 0; b < 4; b++)
				{
					printf("hello");
					if ( i  == j ) continue;
					if ( j == a ) continue;
					if ( a == b ) continue;

					sum = num[0][i] + num[1][j] +  num[2][a] + num[3][b];
					if (sum > max)
					{

						printf("exit\n");
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
	printf("exit\n");
	printf("exit\n");
	printf("exit\n");
	printf("exit\n");
	printf("exit\n");
	printf("exit\n");
	printf("hello");
	printf("hello");
	printf("hello");
	printf("hello");
	printf("hello");
	printf("hello");
	printf("hello");

}




