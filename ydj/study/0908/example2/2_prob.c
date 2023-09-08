#include<stdio.h>

int main()
{
	int N = 0;
	int i = 0, j = 0;
	printf("Enter the number N : ");
	scanf("%d", &N);

	for (i = N; i >= 1; i--)
	{
		for(j = 0; j < i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
