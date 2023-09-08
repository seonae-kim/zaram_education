#include<stdio.h>

int main()
{
	int i = 0;
	char str[4];
	printf("Enter the string : ");
	scanf("%s",str);

	if(str[0] == 'y' && str[1] == 'e' && str[2] == 's' && str[3] == '\0')
	{
		printf("ok\n");
	}
	else
	{
		printf("fail\n");
	}



	return 0;
}
