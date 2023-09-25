#include<stdio.h>
#include<string.h>

int main()
{
	char str[30] = {0};
	int n = 0;
	int i = 0;
	printf("Please enter the string : ");
	scanf("%s", str);

	printf("Please enter the number n :");
	scanf("%d", &n);
	
	for (i = strlen(str) - n; i < strlen(str); i++)
	{
		printf("%c", str[i]);
	}

	printf("\n");
	return 0;
}
