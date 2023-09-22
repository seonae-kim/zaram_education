#include<stdio.h>
#include<string.h>
int main()
{
	int i = 0;
	char str[30] = {0};
	printf("Please enter string : ");
	fgets(str, 30, stdin);
//	scanf("%s", str);

	for (i = 0; i < strlen(str); i++)
	{
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
		{
			str[i] = '0';	
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
