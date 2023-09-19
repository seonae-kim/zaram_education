#include <stdio.h>

int main()
{
	int n;
	int i;
	int num[100] ={0,};
	int num1;
	int num2;

	printf("input N: \n");
	scanf("%d", &n);
	
	printf("input many number: \n");
	for(i =0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	printf("input num1 \n");
	scanf("%d", &num1);

	printf("input num2 \n");
	scanf("%d", &num2);

	if(num1 <=  n-1 && num1 <=num2 && num2 < n)		//4
	{
		for(i = num1; i <= num2; i++)
		{
			printf("%d ", num[i]);
		}	
	}
	else
	{
		printf("bad input");
	}
}
