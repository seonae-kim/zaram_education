#include<stdio.h>
#include<string.h>

int main()
{
	int player = 0, call = 0;
	int i = 0, j = 0;
	char temp[10] = {0};
	printf("Please enter the # of players : ");
	scanf("%d", &player);

	char ranking[player][10];
	printf("Please enter the current ranking : ");
	for (i = 0; i < player; i++)
	{
		scanf("%s", ranking[i]);
	}

	printf("Please enter the # of call : ");
	scanf("%d", &call);

	char calling[call][10];
	printf("Please enter the calling array : ");
	for (i = 0; i < call; i++)
	{
		scanf("%s", calling[i]);
	}

	for (i = 0; i < call; i++)
	{
		for (j = 0; j < player; j++)
		{
			if (strcmp(calling[i], ranking[j]) == 0)
			{
				strcpy(temp, ranking[j - 1]);
				strcpy(ranking[j - 1], ranking[j]);
				strcpy(ranking[j], temp);
			}
		}
	}

	for (i = 0; i < player; i++)
	{
		printf("%s ", ranking[i]);
	}
	
	printf("\n");
	return 0;
}
