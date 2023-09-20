#include <stdio.h>
#include <string.h>

int main()
{
	int arr1[50] = {0,};
	int arr2[50] = {0,};
	int size1;
	int size2;
	int i;

	printf("input arr1's size\n");
	scanf("%d", &size1);

	printf("input arr1:\n");
	for(i = 0; i < size1; i++)
	{
		scanf("%d", &arr1[i]);
	}

	printf("input arr2's size\n");
	scanf("%d", &size2);


	printf("input arr2:\n");
	for(i = 0; i < size2; i++)
	{
		scanf("%d", &arr2[i]);
	}

	int sum1=0;
	int sum2=0;
	for(i=0; i <size1; i++)
	{
		sum1 += arr1[i];
	}

	for(i = 0; i < size2; i++)
	{
		sum2 += arr2[i];
	}

	if(size1 == size2)
	{
		if(sum1 > sum2)
		{
			printf("1");
		}
		else if(sum1 < sum2)
		{
			printf("-1");
		}
		else
		{
			printf("0");
		}
	}

	else 
	{
		if(size1 > size2)
		{
			printf("1");
		}
		else
		{
			printf("-1");
		}
	}

}
