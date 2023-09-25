#include<stdio.h>

int main()
{
	int i = 0;
	int num_arr1 = 0, num_arr2 = 0;
	int sum1 = 0, sum2 = 0;
	printf("Please enter the # of elememt for arr1 : ");
	scanf("%d",& num_arr1);
	printf("Please enter the # of elememt for arr1 : ");
	scanf("%d", &num_arr2);
	int arr1[num_arr1];
	int arr2[num_arr2];
	
	printf("Please enter the arr1 : ");
	for (i = 0; i < num_arr1; i++)
	{
		scanf("%d", &arr1[i]);
	}
	
	printf("Please enter the arr2 : ");
	for (i = 0; i < num_arr2; i++)
	{
		scanf("%d", &arr2[i]);
	}

	if (num_arr1 > num_arr2)
	{
		printf("1\n");
	}
	else if (num_arr1 < num_arr2)
	{
		printf("-1\n");
	}
	else if (num_arr1 == num_arr2)
	{
		for (i = 0; i < num_arr1; i++)
		{
			sum1 = sum1 + arr1[i];
		}

		for (i = 0; i < num_arr2; i++)
		{
			sum2 = sum2 + arr2[i];
		}

		if (sum1 > sum2)
		{
			printf("1\n");
		}
		else if (sum1 < sum2)
		{
			printf("-1\n");
		}
		else if (sum1 == sum2)
		{
			printf("0\n");
		}
	}


	return 0;
}
