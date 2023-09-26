#include<stdio.h>

int main()
{
	int n = 0;
	int i = 0, cnt = 0;
	printf("Please enter the length of num_string : ");
	scanf("%d",&n);
	char str[n];

	printf("Please enter the number : ");
	scanf("%s", str);

	for(i = 0; i < n; i++)
	{
		printf("%c", str[i] + 49);
	}
	printf("\n");

	return 0;
}
