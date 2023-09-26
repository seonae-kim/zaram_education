#include<stdio.h>

int main()
{
	int num = 0, k = 0;
	int cal = 0;
	int result = 0;

	printf("Please enter the max number : ");
	scanf("%d", &num);
	
	printf("Please enter the number k : ");
	scanf("%d", &k);

	cal = 1 + (k - 1) * 2;
	result = cal % num;
	if (result == 0)
	{
		result = num;
	}

	printf("%d\n", result);
	return 0;
}
