#include <stdio.h>
#include <stdlib.h>

int* sort(int *arr, int n);
int main()
{
	int n = 0, i = 0, p = 0;
	int arr[20] = {0, };
	int *re;

	printf("n: ");
	scanf("%d",&n);

	for(i = 0; i <= n; i++)
	{
		if(p % 2 == 1)
			arr[i] = p;
		p++;
	}

	re=sort(arr,n);

	printf("return: ");
	for(i = 0; i <= n; i++)
	{
		if(*(re + i) == 0)
			continue;
		printf("%d",*(re + i));
	}
	printf("\n");
	
	return 0;
}

int* sort(int *arr, int n)
{
	int min = 1000, index = 0;
	int i = 0, j = 0;
	int *sarr;

	sarr = (int*)malloc(sizeof(int) * n);

	for(j = 0; j <= n; j++)
	{
		for(i = 0; i <= n; i++)
		{
			if(*(arr + i) < min)
			{
				min = *(arr + i);
				index = i;
			}
		}
		*(sarr + j) = min;
		*(arr + index) = 1000;
		min = 1000;
	}

	return sarr;
}
	



	

