#include<stdio.h>

int main()
{
	int n = 0;
	int i = 0;
	printf("Please enter the num : ");
	scanf("%d", &n);
	
	for (i = 1; i < n + 1; i++)
	{
		if (i % 2 == 1)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}
