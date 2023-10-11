#include<stdio.h>
#include<string.h>

int main()
{
	char str[100] = {0};
	int i = 0;
	int x = 0;

	printf("Please enter the string : ");

	while (1)
	{
		scanf("%s", str);

		if (strcmp (str, "q") == 0)
		{
			break;
		}
	}

	printf("Bye ~! \n");
	return 0;
}
