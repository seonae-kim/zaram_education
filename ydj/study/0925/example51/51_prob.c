#include<stdio.h>
#include<string.h>
int main()
{
	char str[15] = {0};
	char alp = '0';
	int i = 0;
	printf("Please enter the string : ");
	scanf("%s", str);

	printf("Please enter the alphabet : ");
	scanf(" %c", &alp);

	for (i = 0; i < strlen(str); i++)
	{
		if (alp == str[i])
		{
			str[i] = str[i] - 32;
		}
	}

	printf("%s\n", str);
	return 0;
}
