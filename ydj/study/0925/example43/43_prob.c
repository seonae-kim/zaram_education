#include<stdio.h>
#include<string.h>
int main()
{
	char str[30] = {0};
	int i = 0;
	printf("Please enter the string : ");
	fgets(str, 30, stdin);
//	scanf("%s", str);
	
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] != ' ')
		{
			printf("%c", str[i]);
		}
	}
	printf("\n");
	return 0;
}
