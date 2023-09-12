#include<stdio.h>

int main()
{
	int i = 0, j = 0;
	char arr[5][6] = {0};

	printf("Please enter the word(5) : ");
	for (i = 0; i < 5; i++)
	{
		scanf("%s", arr[i]);
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (arr[j][i] != '\0' && arr[j][i] != ' ')
			{
				printf("%c", arr[j][i]);
			}
		}
	}
	printf("\n");
	return 0;
}
