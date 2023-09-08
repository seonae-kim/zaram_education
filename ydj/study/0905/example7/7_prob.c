#include<stdio.h>
#define ROW 2
#define COL 4

int main()
{
	int i = 0, j = 0;
	int arr[ROW][COL] = {0};
	printf("Please enter the num(8) : ");

	for (i = 0; i < ROW; i++)
	{
		for(j = 0; j < COL; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 0; i < COL; i++)
	{
		for(j = 0; j < COL; j++)
		{
			printf("(%d %d)", arr[0][i], arr[1][j]);
		}
	}

	printf("\n");
	return 0;
}
