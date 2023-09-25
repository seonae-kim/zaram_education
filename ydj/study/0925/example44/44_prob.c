#include<stdio.h>
#include<string.h>

int main()
{
	char str[10] = {0};
	char pat[10] = {0};
	int i = 0, j = 0, order = 0, flag = 0;

	printf("Please enter the string : ");
	scanf("%s", str);

	printf("Please enter the pat : ");
	scanf("%s", pat);
	
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == 'A')
		{
			str[i] = 'B';
		}
		else if (str[i] == 'B')
		{
			str[i] = 'A';
		}
	}

	for (i = 0; i < strlen(str); i++)
	{
		for (j = 0; j < strlen(pat); j++)
		{
			if (str[i + j] == pat[j])
			{
				order++;
			}
			if (order = strlen(pat))
			{
				flag = 1;
			}
		}
		order = 0;
	}


	if (flag == 1)
	{
		printf("1\n");
	}

	return 0;
}
