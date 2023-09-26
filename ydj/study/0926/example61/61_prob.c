#include<stdio.h>

int main()
{
	int i = 0;
	char str[13] = {0};
	printf("Please enter the Phone Number : ");
	scanf("%s", str);
	
	for (i = 0; i < 13; i++)
	{
		if (i < 3 || (i > 3 && i < 8))
		{
			str[i] = '*';
		}
	}

	printf("%s\n", str);

	return 0;
}
