#include<stdio.h>

int main()
{
	int N;
	int i, j;
	printf("Enter the number N : ");
	scanf("%d", &N);

	for(i = 0; i < N; i++)
	{
		for(j = 0; j <= i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
