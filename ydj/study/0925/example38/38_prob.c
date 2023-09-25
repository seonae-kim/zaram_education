#include<stdio.h>

int  main()
{
	int num = 0;
	int n = 0, m = 0;
	int flag_n = 0, flag_m = 0;
	int result = 0;

	printf("Please enter the num : ");
	scanf("%d", &num);

	printf("Please enter the n : ");
	scanf("%d", &n);

	printf("Please enter the m : ");
	scanf("%d", &m);

	if (num % n == 0)
	{
		flag_n++;
	}

	if(num % m == 0)
	{
		flag_m++;
	}

	if (flag_n == 1 && flag_m == 1)
	{
		result = 1;	
	}
	else
	{
		result = 0;
	}

	printf("%d \n", result);
	return 0;
}
