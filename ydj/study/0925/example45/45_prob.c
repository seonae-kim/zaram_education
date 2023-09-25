#include<stdio.h>
#include<string.h>

int main()
{
	int i = 0;
	char str[30] = {0};
	printf("Please enter the string : ");
	scanf("%s", str);
	
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
	}

	printf("%s\n", str);

	return 0;
}
