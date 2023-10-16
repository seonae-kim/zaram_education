#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int *arr, int n);

int main()
{
	int arr[20] = {0, };
	int i = 0, re = 0, n = 0, num = 0;

	printf("num : ");
	scanf("%d",&num);

	printf("n: ");
	scanf("%d",&n);
	printf("arr: ");

	for(i = 0; i < num; i++)
	{
		scanf("%d",&arr[i]);
	}

	re = max(arr,n);

	printf("result : %d\n",re);

	return 0;
}

int max(int *arr, int n)
{
	int i = 0, count = 0;

	for(i = 0; i < sizeof(arr); i++)
	{
		if(*(arr + i) == '\n')
			break;

		if(*(arr + i) > n)
			count++;
	}

	return count;
}

	


