#include<stdio.h>
#include<string.h>

int main()
{
	char str[20] = {0};
	char prefix[10];
	int i = 0, flag = 0;
	printf("Please enter the string : ");
	scanf("%s", str);

	printf("Please enter the prefix : ");
	scanf("%s", prefix);

	while(str[i] == prefix[i])
	{
		if (i == strlen(str))
		{
			break;	
		}
		flag++;
		i++;
	}


	if (flag == strlen(prefix))
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}

	return 0;
}
