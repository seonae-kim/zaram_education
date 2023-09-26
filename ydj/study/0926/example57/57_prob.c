#include<stdio.h>
#include<string.h>

int main()
{
	char str[20] = {0};
	int i = 0, j = 0;
	printf("Please enter the string : ");
	fgets(str, 20, stdin);
//	scanf("%s", str);
	
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == '0')
		{
			continue;
		}
		for (j = i + 1; j < strlen(str); j++)
		{
			if (str[i] == str[j])
			{
				str[j] = '0';
			}
		}
	}

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == '0')
		{
			continue;
		}
		printf("%c", str[i]);
	}

	printf("\n");
	return 0;
}
