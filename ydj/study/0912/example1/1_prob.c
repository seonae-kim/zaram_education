#include<stdio.h>
#define ROW 5
#define COL 10
int main()
{
	int i = 0
	char arr[ROW][COL];
	int num[ROW];
	for (i = 0; i < ROW; i++)
	{
		scanf("%s", arr[i]);
	}

	int count = 0;

	for (i = 0; i < ROW; i++)
	{
		while(arr[i][j] != '\0')
		{
			count++;
			j++;
		}
		num[i] = count;
		count = 0;
		j = 0;
	}

	for (i = 0; i < ROW; i++)
	{
		for (j = i + 1; j < ROW; j++)
		{
			if (num[i] == num[j])
			{
				
			}
			else 
			{
				
			}
		}
	}
	return 0;
}
