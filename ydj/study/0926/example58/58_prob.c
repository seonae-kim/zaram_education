#include<stdio.h>

int main()
{
	int date1[3] = {0};
	int date2[3] = {0};
	int i = 0;

	printf("Please enter the date 1 (YYYY MM DD format) : ");
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &date1[i]);
	}

	printf("Please enter the date 2( YYYY MM DD format) : ");
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &date2[i]);
	}

	if (date1[0] > date2[0])
	{
		printf("0\n");
	}
	else if (date1[0] < date2[0])
	{
		printf("1\n");
	}
	else if (date1[0] == date2[0])
	{
		if (date1[1] > date2[1])
		{
			printf("0\n");
		}
		else if (date1[1] < date2[1])
		{
			printf("1\n");
		}
		else if (date1[1] == date2[1])
		{
			if (date1[2] > date2[2])
			{
				printf("0\n");
			}
			else if (date1[2] < date2[2])
			{
				printf("1\n");
			}
			else if (date1[2] == date2[2])
			{
				printf("0\n");
			}
		}
	}

	return 0;
}
