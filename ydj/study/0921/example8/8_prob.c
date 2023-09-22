#include<stdio.h>
#include<string.h>

int main()
{
	char str[20] = {0};
	int n = 0;
	int i = 0, j = 0;

	printf("Please enter the string : ");
	scanf("%s", str);

	printf("\nPlease enter the repeat number : ");
	scanf("%d", &n);

	for (i = 0; i < strlen(str); i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%c", str[i]);
		}
	}	
	printf("\n");
	return 0;
}
