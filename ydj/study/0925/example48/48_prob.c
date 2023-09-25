#include<stdio.h>

int main()
{
	char str[20] = {0};
	int n = 0;
	int i = 0;
	printf("Please enter the string : ");
	scanf("%s", str);

	printf("Please enter the # of element for index: ");
	scanf("%d", &n);

	printf("Please enter the arr : ");
	int arr[n];

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < n; i++)
	{
		printf("%c", str[arr[i]]);
	}
	
	printf("\n");
	return 0;
}
