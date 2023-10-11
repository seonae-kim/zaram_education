#include<stdio.h>

int main()
{
	int s= 0, e = 0;
	int i = 0;
	char str[30] = {0};
	char str_prt[30] = {0};
	printf("Please enter the string : ");
	scanf("%s", str);

	printf("Please enter the s : ");
	scanf("%d", &s);

	printf("Please enter the e : ");
	scanf("%d", &e);

	for (i = 0; i < e - s + 1; i++)
	{
		str_prt[s + i] = str[e - i];
	}

	for (i = 0; i < 30; i++)
	{
		if (i < s || i > e)
		{
			str_prt[i] = str[i];
		}
	}

	printf("%s\n", str_prt);

	return 0;
}

