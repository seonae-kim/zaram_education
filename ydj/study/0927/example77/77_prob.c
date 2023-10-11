#include<stdio.h>
#include<string.h>

int main()
{
    char str[15] = {0};
    int i = 0;
    int num = 0;
    printf("Please enter the string : ");
    scanf("%s", str);

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == '1')
		{
			num++;
		}
		else
		{
			if (num % 2 == 0)
			{
				if (i % 2 == 0)
				{
					printf("%c", str[i]);
				}
			}
			else if (num % 2 == 1)
			{
				if (i % 2 == 1)
				{
					printf("%c", str[i]);
				}
			}
		}
	}
	printf("\n");

    return 0;
}
