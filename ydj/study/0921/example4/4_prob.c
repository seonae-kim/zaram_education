#include<stdio.h>

int main()
{
	int N = 0;
	int i = 0;
	int num1 = 0, num2 = 0;
	printf("Please enter the # of array : ");
	scanf("%d", &N);

	int num[N];
	printf("Please enter the number : ");

	for (i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	printf("Enter num1 : ");
	scanf("%d", &num1);
	printf("Enter num2 : ");
	scanf("%d", &num2);

	printf("[");
	for (i = num1; i < num2 - num1 + 2; i++)
	{
		printf("%d ", num[i]);
	}
	printf("]\n");

	return  0;
}
