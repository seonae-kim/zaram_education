#include<stdio.h>
#include<string.h>
#define ROW 5
#define COL 10

int main()
{
	int i = 0, j = 0;
	int temp = 0;
	char temp_c[COL] = {0};
	char str[ROW][COL] = {0};
	int num[ROW];
	for (i = 0; i < ROW; i++)
	{
		scanf("%s", str[i]);
	}

	for (i = 0; i < ROW; i++)
	{
		for (j = i + 1; j < ROW; j++)
		{	
			if (strlen(str[i]) > strlen(str[j]))
			{
				strcpy(temp_c, str[j]);
				strcpy(str[j], str[i]);
				strcpy(str[i], temp_c);
			}
		}
	}

	memset (temp_c, 0, sizeof(char) * 10);
	for (i = 0; i < ROW; i++)
	{
		for (j = i + 1; j < ROW; j++)
		{
			if (strlen(str[i]) == strlen(str[j]))
			{
				if (strcmp(str[i], str[j]) > 0)
				{
					strcpy(temp_c, str[j]);
					strcpy(str[j], str[i]);
					strcpy(str[i], temp_c);
				}
			}
		}
	}
	
	for (i = 0; i < ROW; i++)
	{
		printf("%s ", str[i]);
	}
	printf("\n");

	return 0;
}
