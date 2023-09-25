#include<stdio.h>
#include<string.h>

int main()
{
	int sum = 0;
	int i = 0;
	char str[20] = {0};
	printf("Please enter the string : ");
	scanf("%s", str);

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == 'w')
		{
			sum = sum + 1;
		}
		else if (str[i] == 's')
		{
			sum = sum - 1;
		}
		else if (str[i] == 'd')
		{
			sum = sum + 10;
		}
		else if (str[i] == 'a')
		{
			sum = sum - 10;
		}
	}

	printf("%d\n", sum);

	return 0;
}
