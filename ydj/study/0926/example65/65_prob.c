#include<stdio.h>
#include<string.h>

int main()
{
	char pat[5] = {0};
	char myString[20] = {0};
	char result[20] = {0};
	char temp[5] = {0};

	int i = 0, j = 0;
	int max = 0;
	int num = 0;

	printf("Please enter the pat string : ");
	scanf("%s", pat);

	printf("Please enter the myString : ");
	scanf("%s", myString);

	num = strlen(myString) -strlen(pat) + 1;

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < strlen(pat); j++)
		{
			temp[j] = myString[i + j];
		}
		if (strcmp(temp, pat) == 0)
		{
			if (max < i)
			{
				max = i;
			}
		}
	}

	for (i = 0;  i < max + strlen(pat); i++)
	{
		printf("%c", myString[i]);
	}
	printf("\n");
	return 0;
}
