#include<stdio.h>

int main()
{
	int i = 0;
	char str[4];
	printf("Enter the string : ");
	scanf("%s",str);
//	printf(" %c", str[2]);

	if(str[0] == 'y')
	{
		if (str[1] == 'e')
		{
			if(str[2] == 's')
			{
//				printf("%c", str[3]);
				if(str[3] == '\0')
				{
					printf("pass\n");
				}
				else
				{
					printf("fail\n");
				}
			}
			else
			{
				printf("fail\n");
			}
		}
		else 
		{
			printf("fail\n");
		}	
	}
	else
	{
		printf("fail\n");
	}
	return 0;
}
