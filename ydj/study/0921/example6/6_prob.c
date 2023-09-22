#include<stdio.h>
#include<stdlib.h>

int main()
{
	char n[10];
//	char temp[3] = {0};
	int i = 0, j = 0;
	int num = 0;
	int sum = 0;

	printf("Please enter the  number : ");
	scanf("%s", n);

	
	num = atoi(n);
	
	while ((num / 10) != 0)
	{
		sum = sum + (num % 10);
		num = num / 10;
	}

	sum = sum + num;
	printf("sum : %d \n", sum);

	return 0;
}
